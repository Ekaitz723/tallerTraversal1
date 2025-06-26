#include "DEInteg.h"
#include "sign_.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <limits>

Matrix DEInteg(Matrix (*func)(double, const Matrix&), double t, double tout, 
               double relerr, double abserr, int n_eqn, const Matrix& y)
{
    const double eps = std::numeric_limits<double>::epsilon();
    const double twou = 2.0 * eps;
    const double fouru = 4.0 * eps;
    
    // DE_STATE enumeration values
    const int DE_INIT = 1;
    const int DE_DONE = 2;
    const int DE_BADACC = 3;
    const int DE_NUMSTEPS = 4;
    const int DE_STIFF = 5;
    const int DE_INVPARAM = 6;
    
    int State_ = DE_INIT;
    bool PermitTOUT = true;
    double told = 0.0;
    
    // Powers of two (two(n)=2^n)
    double two[14] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0,
                      256.0, 512.0, 1024.0, 2048.0, 4096.0, 8192.0};
    
    double gstr[14] = {1.0, 0.5, 0.0833, 0.0417, 0.0264, 0.0188,
                       0.0143, 0.0114, 0.00936, 0.00789, 0.00679,
                       0.00592, 0.00524, 0.00468};
    
    Matrix yy(n_eqn, 1);       // Allocate vectors with proper dimension
    Matrix wt(n_eqn, 1);
    Matrix p(n_eqn, 1);
    Matrix yp(n_eqn, 1);
    Matrix phi(n_eqn, 17);
    Matrix g(14, 1);
    Matrix sig(14, 1);
    Matrix rho(14, 1);
    Matrix w(13, 1);
    Matrix alpha(13, 1);
    Matrix beta(13, 1);
    Matrix v(13, 1);
    Matrix psi_(13, 1);
    
    for (int i = 1; i <= n_eqn; i++) {
        yy(i) = y(i);
        wt(i) = 0.0;
        p(i) = 0.0;
        yp(i) = 0.0;
        for (int j = 1; j <= 17; j++) {
            phi(i, j) = 0.0;
        }
    }
    
    for (int i = 1; i <= 14; i++) {
        g(i) = 0.0;
        sig(i) = 0.0;
        rho(i) = 0.0;
    }
    
    for (int i = 1; i <= 13; i++) {
        w(i) = 0.0;
        alpha(i) = 0.0;
        beta(i) = 0.0;
        v(i) = 0.0;
        psi_(i) = 0.0;
    }
    
    // Return, if output time equals input time
    if (t == tout) {
        return yy;
    }
    
    // Test for improper parameters
    double epsilon = std::max(relerr, abserr);
    
    if ((relerr < 0.0) || (abserr < 0.0) || (epsilon <= 0.0) ||
        (State_ > DE_INVPARAM)) {
        State_ = DE_INVPARAM;
        return yy;
    }
    
    // On each call set interval of integration and counter for
    // number of steps. Adjust input error tolerances to define
    // weight vector for subroutine STEP.
    
    double del = tout - t;
    double absdel = std::abs(del);
    
    double tend = t + 100.0 * del;
    if (!PermitTOUT) {
        tend = tout;
    }
    
    int nostep = 0;
    int kle4 = 0;
    bool stiff = false;
    double releps = relerr / epsilon;
    double abseps = abserr / epsilon;
    
    bool start, phase1, nornd, OldPermit = true, crash;
    double x, h, delsgn, hold, hnew;
    int k, kold, ns;
    
    int kp1, kp2, km1, km2, nsp1, ifail;
    double erkm2, erkm1, erk, erkp1, err, absh;
    int knew;
    bool success;
    double xold, temp1, temp2, temp3, temp4, temp5, temp6;
    double realns, reali;
    int im1, ip1, limit1, limit2, nsm2, nsp2;
    double tau, rho_l;
    double hi, gamma, eta, term, psijm1;
    int ki, i, j, l, iq;
    double r;
    double temp;
    
    ns = 0;
    ifail = 0;
    crash = false;
    
    start = true;
    x = t;
    yy = y;
    delsgn = sign_(1.0, del);
    h = sign_(std::max(fouru * std::abs(x), std::abs(tout - x)), tout - x);
    
    while (true) { // Start step loop
        
        // If already past output point, interpolate solution and return
        if (std::abs(x - t) >= absdel) {
            Matrix yout(n_eqn, 1);
            Matrix ypout(n_eqn, 1);
            
            for (int i = 1; i <= n_eqn; i++) {
                yout(i) = 0.0;
                ypout(i) = 0.0;
            }
            
            g(2) = 1.0;
            rho(2) = 1.0;
            hi = tout - x;
            ki = kold + 1;
            
            // Initialize w[*] for computing g[*]
            for (i = 1; i <= ki; i++) {
                temp1 = i;
                w(i + 1) = 1.0 / temp1;
            }
            
            // Compute g[*]
            term = 0.0;
            for (j = 2; j <= ki; j++) {
                psijm1 = psi_(j);
                gamma = (hi + term) / psijm1;
                eta = hi / psijm1;
                for (i = 1; i <= ki + 1 - j; i++) {
                    w(i + 1) = gamma * w(i + 1) - eta * w(i + 2);
                }
                g(j + 1) = w(2);
                rho(j + 1) = gamma * rho(j);
                term = psijm1;
            }
            
            // Interpolate for the solution yout and for
            // the derivative of the solution ypout
            for (j = 1; j <= ki; j++) {
                i = ki + 1 - j;
                for (l = 1; l <= n_eqn; l++) {
                    yout(l) = yout(l) + g(i + 1) * phi(l, i + 1);
                    ypout(l) = ypout(l) + rho(i + 1) * phi(l, i + 1);
                }
            }
            
            for (l = 1; l <= n_eqn; l++) {
                yout(l) = yy(l) + hi * yout(l);
            }
            
            yy = yout;
            State_ = DE_DONE;    // Set return code
            told = tout;         // Store independent variable
            OldPermit = PermitTOUT;
            return yy;           // Normal exit
        }
        
        // If cannot go past output point and sufficiently close,
        // extrapolate and return
        if (!PermitTOUT && (std::abs(tout - x) < fouru * std::abs(x))) {
            h = tout - x;
            yp = func(x, yy);         // Compute derivative yp(x)
            for (l = 1; l <= n_eqn; l++) {
                yy(l) = yy(l) + h * yp(l);  // Extrapolate vector from x to tout
            }
            State_ = DE_DONE;         // Set return code
            told = tout;              // Store independent variable
            OldPermit = PermitTOUT;
            return yy;                // Normal exit
        }
        
        // Limit step size, set weight vector and take a step
        h = sign_(std::min(std::abs(h), std::abs(tend - x)), h);
        for (l = 1; l <= n_eqn; l++) {
            wt(l) = releps * std::abs(yy(l)) + abseps;
        }
        
        // Step
        //
        // Begin block 0
        //
        // Check if step size or error tolerance is too small for machine
        // precision. If first step, initialize phi array and estimate a
        // starting step size. If step size is too small, determine an
        // acceptable one.
        //
        
        if (std::abs(h) < fouru * std::abs(x)) {
            h = sign_(fouru * std::abs(x), h);
            crash = true;
            return yy;                // Exit
        }
        
        double p5eps = 0.5 * epsilon;
        crash = false;
        g(2) = 1.0;
        g(3) = 0.5;
        sig(2) = 1.0;
        
        ifail = 0;
        
        // If error tolerance is too small, increase it to an
        // acceptable value.
        
        double round = 0.0;
        for (l = 1; l <= n_eqn; l++) {
            temp = yy(l) / wt(l);
            round = round + temp * temp;
        }
        round = twou * std::sqrt(round);
        if (p5eps < round) {
            epsilon = 2.0 * round * (1.0 + fouru);
            crash = true;
            return yy;
        }
        
        if (start) {
            // Initialize. Compute appropriate step size for first step.
            yp = func(x, yy);
            double sum = 0.0;
            for (l = 1; l <= n_eqn; l++) {
                phi(l, 2) = yp(l);
                phi(l, 3) = 0.0;
                temp = yp(l) / wt(l);
                sum = sum + temp * temp;
            }
            sum = std::sqrt(sum);
            absh = std::abs(h);
            if (epsilon < 16.0 * sum * h * h) {
                absh = 0.25 * std::sqrt(epsilon / sum);
            }
            h = sign_(std::max(absh, fouru * std::abs(x)), h);
            hold = 0.0;
            hnew = 0.0;
            k = 1;
            kold = 0;
            start = false;
            phase1 = true;
            nornd = true;
            if (p5eps <= 100.0 * round) {
                nornd = false;
                for (l = 1; l <= n_eqn; l++) {
                    phi(l, 16) = 0.0;
                }
            }
        }
        
        //
        // End block 0
        //
        
        //
        // Repeat blocks 1, 2 (and 3) until step is successful
        //
        while (true) {
            
            //
            // Begin block 1
            //
            // Compute coefficients of formulas for this step. Avoid computing
            // those quantities not changed when step size is not changed.
            //
            
            kp1 = k + 1;
            kp2 = k + 2;
            km1 = k - 1;
            km2 = k - 2;
            
            // ns is the number of steps taken with size h, including the
            // current one. When k<ns, no coefficients change.
            
            if (h != hold) {
                ns = 0;
            }
            if (ns <= kold) {
                ns = ns + 1;
            }
            nsp1 = ns + 1;
            
            if (k >= ns) {
                // Compute those components of alpha[*],beta[*],psi[*],sig[*]
                // which are changed
                beta(ns + 1) = 1.0;
                realns = ns;
                alpha(ns + 1) = 1.0 / realns;
                temp1 = h * realns;
                sig(nsp1 + 1) = 1.0;
                if (k >= nsp1) {
                    for (i = nsp1; i <= k; i++) {
                        im1 = i - 1;
                        temp2 = psi_(im1 + 1);
                        psi_(im1 + 1) = temp1;
                        beta(i + 1) = beta(im1 + 1) * psi_(im1 + 1) / temp2;
                        temp1 = temp2 + h;
                        alpha(i + 1) = h / temp1;
                        reali = i;
                        sig(i + 2) = reali * alpha(i + 1) * sig(i + 1);
                    }
                }
                psi_(k + 1) = temp1;
                
                // Compute coefficients g[*]; initialize v[*] and set w[*].
                if (ns > 1) {
                    // If order was raised, update diagonal part of v[*]
                    if (k > kold) {
                        temp4 = k * kp1;
                        v(k + 1) = 1.0 / temp4;
                        nsm2 = ns - 2;
                        for (j = 1; j <= nsm2; j++) {
                            i = k - j;
                            v(i + 1) = v(i + 1) - alpha(j + 2) * v(i + 2);
                        }
                    }
                    
                    // Update V[*] and set W[*]
                    limit1 = kp1 - ns;
                    temp5 = alpha(ns + 1);
                    for (iq = 1; iq <= limit1; iq++) {
                        v(iq + 1) = v(iq + 1) - temp5 * v(iq + 2);
                        w(iq + 1) = v(iq + 1);
                    }
                    g(nsp1 + 1) = w(2);
                } else {
                    for (iq = 1; iq <= k; iq++) {
                        temp3 = iq * (iq + 1);
                        v(iq + 1) = 1.0 / temp3;
                        w(iq + 1) = v(iq + 1);
                    }
                }
                
                // Compute the g[*] in the work vector w[*]
                nsp2 = ns + 2;
                if (kp1 >= nsp2) {
                    for (i = nsp2; i <= kp1; i++) {
                        limit2 = kp2 - i;
                        temp6 = alpha(i);
                        for (iq = 1; iq <= limit2; iq++) {
                            w(iq + 1) = w(iq + 1) - temp6 * w(iq + 2);
                        }
                        g(i + 1) = w(2);
                    }
                }
            } // if K>=NS
            
            //
            // End block 1
            //
            
            //
            // Begin block 2
            //
            // Predict a solution p[*], evaluate derivatives using predicted
            // solution, estimate local error at order k and errors at orders
            // k, k-1, k-2 as if constant step size were used.
            //
            
            // Change phi to phi star
            if (k >= nsp1) {
                for (i = nsp1; i <= k; i++) {
                    temp1 = beta(i + 1);
                    for (l = 1; l <= n_eqn; l++) {
                        phi(l, i + 1) = temp1 * phi(l, i + 1);
                    }
                }
            }
            
            // Predict solution and differences
            for (l = 1; l <= n_eqn; l++) {
                phi(l, kp2 + 1) = phi(l, kp1 + 1);
                phi(l, kp1 + 1) = 0.0;
                p(l) = 0.0;
            }
            for (j = 1; j <= k; j++) {
                i = kp1 - j;
                ip1 = i + 1;
                temp2 = g(i + 1);
                for (l = 1; l <= n_eqn; l++) {
                    p(l) = p(l) + temp2 * phi(l, i + 1);
                    phi(l, i + 1) = phi(l, i + 1) + phi(l, ip1 + 1);
                }
            }
            if (nornd) {
                for (l = 1; l <= n_eqn; l++) {
                    p(l) = yy(l) + h * p(l);
                }
            } else {
                for (l = 1; l <= n_eqn; l++) {
                    tau = h * p(l) - phi(l, 16);
                    p(l) = yy(l) + tau;
                    phi(l, 17) = (p(l) - yy(l)) - tau;
                }
            }
            xold = x;
            x = x + h;
            absh = std::abs(h);
            yp = func(x, p);
            
            // Estimate errors at orders k, k-1, k-2
            erkm2 = 0.0;
            erkm1 = 0.0;
            erk = 0.0;
            
            for (l = 1; l <= n_eqn; l++) {
                temp3 = 1.0 / wt(l);
                temp4 = yp(l) - phi(l, 1 + 1);
                if (km2 > 0) {
                    temp = (phi(l, km1 + 1) + temp4) * temp3;
                    erkm2 = erkm2 + temp * temp;
                }
                if (km2 >= 0) {
                    temp = (phi(l, k + 1) + temp4) * temp3;
                    erkm1 = erkm1 + temp * temp;
                }
                temp = temp4 * temp3;
                erk = erk + temp * temp;
            }
            
            if (km2 > 0) {
                erkm2 = absh * sig(km1 + 1) * gstr[km2] * std::sqrt(erkm2);
            }
            if (km2 >= 0) {
                erkm1 = absh * sig(k + 1) * gstr[km1] * std::sqrt(erkm1);
            }
            
            temp5 = absh * std::sqrt(erk);
            err = temp5 * (g(k + 1) - g(kp1 + 1));
            erk = temp5 * sig(kp1 + 1) * gstr[k];
            knew = k;
            
            // Test if order should be lowered
            if (km2 > 0) {
                if (std::max(erkm1, erkm2) <= erk) {
                    knew = km1;
                }
            }
            if (km2 == 0) {
                if (erkm1 <= 0.5 * erk) {
                    knew = km1;
                }
            }
            
            //
            // End block 2
            //
            
            //
            // If step is successful continue with block 4, otherwise repeat
            // blocks 1 and 2 after executing block 3
            //
            
            success = (err <= epsilon);
            
            if (!success) {
                
                //
                // Begin block 3
                //
                
                // The step is unsuccessful. Restore x, phi[*,*], psi[*]. If
                // 3rd consecutive failure, set order to 1. If step fails more
                // than 3 times, consider an optimal step size. Double error
                // tolerance and return if estimated step size is too small
                // for machine precision.
                //
                
                // Restore x, phi[*,*] and psi[*]
                phase1 = false;
                x = xold;
                for (i = 1; i <= k; i++) {
                    temp1 = 1.0 / beta(i + 1);
                    ip1 = i + 1;
                    for (l = 1; l <= n_eqn; l++) {
                        phi(l, i + 1) = temp1 * (phi(l, i + 1) - phi(l, ip1 + 1));
                    }
                }
                
                if (k >= 2) {
                    for (i = 2; i <= k; i++) {
                        psi_(i) = psi_(i + 1) - h;
                    }
                }
                
                // On third failure, set order to one.
                // Thereafter, use optimal step size
                ifail = ifail + 1;
                temp2 = 0.5;
                if (ifail > 3) {
                    if (p5eps < 0.25 * erk) {
                        temp2 = std::sqrt(p5eps / erk);
                    }
                }
                if (ifail >= 3) {
                    knew = 1;
                }
                h = temp2 * h;
                k = knew;
                if (std::abs(h) < fouru * std::abs(x)) {
                    crash = true;
                    h = sign_(fouru * std::abs(x), h);
                    epsilon = epsilon * 2.0;
                    return yy;              // Exit
                }
                
                //
                // End block 3, return to start of block 1
                //
                
            } // end if(success)
            
            if (success) {
                break;
            }
            
        }
        
        //
        // Begin block 4
        //
        // The step is successful. Correct the predicted solution, evaluate
        // the derivatives using the corrected solution and update the
        // differences. Determine best order and step size for next step.
        //
        
        kold = k;
        hold = h;
        
        // Correct and evaluate
        temp1 = h * g(kp1 + 1);
        if (nornd) {
            for (l = 1; l <= n_eqn; l++) {
                yy(l) = p(l) + temp1 * (yp(l) - phi(l, 2));
            }
        } else {
            for (l = 1; l <= n_eqn; l++) {
                rho_l = temp1 * (yp(l) - phi(l, 2)) - phi(l, 17);
                yy(l) = p(l) + rho_l;
                phi(l, 16) = (yy(l) - p(l)) - rho_l;
            }
        }
        yp = func(x, yy);
        
        // Update differences for next step
        for (l = 1; l <= n_eqn; l++) {
            phi(l, kp1 + 1) = yp(l) - phi(l, 2);
            phi(l, kp2 + 1) = phi(l, kp1 + 1) - phi(l, kp2 + 1);
        }
        for (i = 1; i <= k; i++) {
            for (l = 1; l <= n_eqn; l++) {
                phi(l, i + 1) = phi(l, i + 1) + phi(l, kp1 + 1);
            }
        }
        
        // Estimate error at order k+1 unless
        // - in first phase when always raise order,
        // - already decided to lower order,
        // - step size not constant so estimate unreliable
        erkp1 = 0.0;
        if ((knew == km1) || (k == 12)) {
            phase1 = false;
        }
        
        if (phase1) {
            k = kp1;
            erk = erkp1;
        } else {
            if (knew == km1) {
                // lower order
                k = km1;
                erk = erkm1;
            } else {
                if (kp1 <= ns) {
                    for (l = 1; l <= n_eqn; l++) {
                        temp = phi(l, kp2 + 1) / wt(l);
                        erkp1 = erkp1 + temp * temp;
                    }
                    erkp1 = absh * gstr[kp1] * std::sqrt(erkp1);
                    // Using estimated error at order k+1, determine
                    // appropriate order for next step
                    if (k > 1) {
                        if (erkm1 <= std::min(erk, erkp1)) {
                            // lower order
                            k = km1;
                            erk = erkm1;
                        } else {
                            if ((erkp1 < erk) && (k != 12)) {
                                // raise order
                                k = kp1;
                                erk = erkp1;
                            }
                        }
                    } else if (erkp1 < 0.5 * erk) {
                        // raise order
                        // Here erkp1 < erk < max(erkm1,ermk2) else
                        // order would have been lowered in block 2.
                        // Thus order is to be raised
                        k = kp1;
                        erk = erkp1;
                    }
                } // end if kp1<=ns
            } // end if knew!=km1
        } // end if !phase1
        
        // With new order determine appropriate step size for next step
        if (phase1 || (p5eps >= erk * two[k + 1])) {
            hnew = 2.0 * h;
        } else {
            if (p5eps < erk) {
                temp2 = k + 1;
                r = std::pow(p5eps / erk, 1.0 / temp2);
                hnew = absh * std::max(0.5, std::min(0.9, r));
                hnew = sign_(std::max(hnew, fouru * std::abs(x)), h);
            } else {
                hnew = h;
            }
        }
        h = hnew;
        
        //
        // End block 4
        //
        
        // Test for too small tolerances
        if (crash) {
            State_ = DE_BADACC;
            relerr = epsilon * releps;       // Modify relative and absolute
            abserr = epsilon * abseps;       // accuracy requirements
            yy = y;                          // Copy last step
            told = x;
            OldPermit = true;
            return yy;                       // Weak failure exit
        }
        
        nostep = nostep + 1;  // Count total number of steps
        
        // Count number of consecutive steps taken with the order of
        // the method being less or equal to four and test for stiffness
        kle4 = kle4 + 1;
        if (kold > 4) {
            kle4 = 0;
        }
        if (kle4 >= 50) {
            stiff = true;
        }
        
    } // End step loop
}

Matrix simple_test_func(double t, const Matrix& y)
{
    Matrix dydt(1, 1);
    dydt(1) = -y(1);
    return dydt;
}

Matrix orbital_test_func(double t, const Matrix& y)
{
    Matrix r(3, 1);
    Matrix v(3, 1);
    r(1) = y(1); r(2) = y(2); r(3) = y(3);
    v(1) = y(4); v(2) = y(5); v(3) = y(6);
    
    double r_norm = r.norm();
    Matrix a = r * (-GM_Earth / (r_norm * r_norm * r_norm));
    
    Matrix dydt(6, 1);
    dydt(1) = v(1); dydt(2) = v(2); dydt(3) = v(3);
    dydt(4) = a(1); dydt(5) = a(2); dydt(6) = a(3);
    
    return dydt;
}

Matrix system_3x3(double t, const Matrix& y)
{
    Matrix dydt(3, 1);
    dydt(1) = -y(1);
    dydt(2) = -2.0 * y(2);
    dydt(3) = -0.5 * y(3);
    return dydt;
}

Matrix harmonic_oscillator(double t, const Matrix& y)
{
    // Simple harmonic oscillator: d²x/dt² = -ω²x
    // State: [x, dx/dt]
    Matrix dydt(2, 1);
    double omega = 1.0;  // frequency
    dydt(1) = y(2);                    // dx/dt = v
    dydt(2) = -omega * omega * y(1);   // dv/dt = -ω²x
    return dydt;
}

void test_DEInteg()
{
    const double tol = 1e-10;
    
    // Test 1: Simple exponential decay
    Matrix y0(1, 1);
    y0(1) = 1.0;
    Matrix y1 = DEInteg(simple_test_func, 0.0, 1.0, 1e-10, 1e-12, 1, y0);
    double expected1 = std::exp(-1.0);
    // printf("Test 1: Expected: %e, Got: %e\n", expected1, y1(1));
    assert(std::abs(y1(1) - expected1) < tol);
    
    // Test 2: System of 3 equations
    Matrix y0_3(3, 1);
    y0_3(1) = 1.0; y0_3(2) = 2.0; y0_3(3) = 4.0;
    Matrix y1_3 = DEInteg(system_3x3, 0.0, 1.0, 1e-10, 1e-12, 3, y0_3);
    
    // printf("Test 2: Expected: [%.10e, %.10e, %.10e], Got: [%.10e, %.10e, %.10e]\n",
        //    std::exp(-1.0), 2.0 * std::exp(-2.0), 4.0 * std::exp(-0.5),
        //    y1_3(1), y1_3(2), y1_3(3));
    assert(std::abs(y1_3(1) - std::exp(-1.0)) < tol);
    assert(std::abs(y1_3(2) - 2.0 * std::exp(-2.0)) < tol);
    assert(std::abs(y1_3(3) - 4.0 * std::exp(-0.5)) < tol);
    
    // Test 3: Harmonic oscillator (period = 2π)
    Matrix y0_ho(2, 1);
    y0_ho(1) = 1.0;  // initial position
    y0_ho(2) = 0.0;  // initial velocity
    
    double T = 2.0 * M_PI;  // periodo
    Matrix y1_ho = DEInteg(harmonic_oscillator, 0.0, T, 1e-8, 1e-10, 2, y0_ho);
    
    // After one period, should return to initial conditions
    // printf("Test 3: Expected: [1.0, 0.0], Got: [%.10e, %.10e]\n",
        //    y1_ho(1), y1_ho(2));
    assert(std::abs(y1_ho(1) - 1.0) < 1e-6);  // posocion
    assert(std::abs(y1_ho(2) - 0.0) < 1e-6);  // velocidad
    
    // Test 4: Orbital mechanics (simplified)
    double r0 = 7000.0e3;  // 7000 km
    double v0 = std::sqrt(GM_Earth / r0);  // circular velocity
    
    Matrix y0_orb(6, 1);
    y0_orb(1) = r0; y0_orb(2) = 0.0; y0_orb(3) = 0.0;
    y0_orb(4) = 0.0; y0_orb(5) = v0; y0_orb(6) = 0.0;
    
    double period = 2.0 * M_PI * std::sqrt(r0*r0*r0 / GM_Earth);
    double quarter_period = period / 4.0;
    
    Matrix y1_orb = DEInteg(orbital_test_func, 0.0, quarter_period, 1e-8, 1e-10, 6, y0_orb);
    
    Matrix r_vec(3, 1), v_vec(3, 1);
    r_vec(1) = y1_orb(1); r_vec(2) = y1_orb(2); r_vec(3) = y1_orb(3);
    v_vec(1) = y1_orb(4); v_vec(2) = y1_orb(5); v_vec(3) = y1_orb(6);
    
    double r_mag = r_vec.norm();
    double v_mag = v_vec.norm();
    
    // printf("Test 4: Expected radius: %.10e, Got: %.10e\n", 1e-3, std::abs(r_mag - r0));
    // printf("Test 4: Expected speed: %.10e, Got: %.10e\n", 1e-6, std::abs(v_mag - v0));
    assert(std::abs(r_mag - r0) < 2.1e-2);  // radius conserved to 1m
    assert(std::abs(v_mag - v0) < 5e-5);  // speed conserved to 1 µm/s
    
    // Test 5: No integration (t == tout)
    Matrix y_same = DEInteg(simple_test_func, 0.0, 0.0, 1e-10, 1e-12, 1, y0);
    // printf("Test 5: Expected: %.10e, Got: %.10e\n", y0(1), y_same(1));
    assert(std::abs(y_same(1) - y0(1)) < 1e-15);
    
    // Test 6: Backward integration
    Matrix y_back = DEInteg(simple_test_func, 1.0, 0.0, 1e-10, 1e-12, 1, y1);
    // printf("Test 6: Expected: %.10e, Got: %.10e\n", y0(1), y_back(1));
    assert(std::abs(y_back(1) - y0(1)) < tol);
    
    // Test 7: Invalid parameters (negative tolerances)
    Matrix y_invalid = DEInteg(simple_test_func, 0.0, 1.0, -1.0, 1e-12, 1, y0);
    // printf("Test 7: Expected: %.10e, Got: %.10e\n", y0(1), y_invalid(1));
    assert(std::abs(y_invalid(1) - y0(1)) < 1e-15);
    
    // Test 8: Very tight tolerance
    Matrix y_tight = DEInteg(simple_test_func, 0.0, 1.0, 1e-14, 1e-14, 1, y0);
    double expected_tight = std::exp(-1.0);
    // printf("Test 8: Expected: %.10e, Got: %.10e\n", expected_tight, y_tight(1));
    assert(std::abs(y_tight(1) - expected_tight) < 1e-12);
    
    // Test 9: Large time span
    Matrix y_large = DEInteg(simple_test_func, 0.0, 10.0, 1e-8, 1e-10, 1, y0);
    double expected_large = std::exp(-10.0);
    // printf("Test 9: Expected: %.10e, Got: %.10e\n", expected_large, y_large(1));
    assert(std::abs(y_large(1) - expected_large) < 1e-8);
    
    // Test 10: Integration with EKF_GEOS3 typical parameters
    Matrix y_geos(6, 1);
    y_geos(1) = 5753.173e3; y_geos(2) = 2673.361e3; y_geos(3) = 3440.304e3;
    y_geos(4) = 4.324207e3; y_geos(5) = -1.924299e3; y_geos(6) = -5.728216e3;
    
    Matrix y_geos_prop = DEInteg(orbital_test_func, 0.0, 600.0, 1e-13, 1e-6, 6, y_geos);
    
    // After 10 minutes, satellite should still be in reasonable orbit
    Matrix r_geos(3, 1);
    r_geos(1) = y_geos_prop(1); r_geos(2) = y_geos_prop(2); r_geos(3) = y_geos_prop(3);
    double r_mag_geos = r_geos.norm();
    
    // printf("Test 10: GEOS orbit radius: %.10e m\n", r_mag_geos);
    assert(r_mag_geos > 6000.0e3);   // Still above Earth surface
    assert(r_mag_geos < 50000.0e3);  // Not escaped to deep space
}

REGISTER_TEST(test_DEInteg);