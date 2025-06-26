#include "anglesg.h"
#include "Geodetic.h"
#include "LTC.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "gibbs.h"
#include "hgibbs.h"
#include "elements.h"
#include "angl.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <complex>
#include <string>
#include <cstring>

// root en matlab
double find_largest_real_root(double poly[9])
{
    double r_start = 1.0;
    double r_max = 1e8;
    
    double prev_val = poly[8];
    double best_r = 0;
    bool found_sign_change = false;
    
    // Busqueda exponencial para encontrar rango con cambio de signo
    for (double r = r_start; r <= r_max; r *= 1.1) {
        double r2 = r * r; double r3 = r2 * r; double r4 = r3 * r; 
        double r5 = r4 * r; double r6 = r5 * r; double r7 = r6 * r; double r8 = r7 * r;
        
        double val = poly[0]*r8 + poly[1]*r7 + poly[2]*r6 + poly[3]*r5 + 
                     poly[4]*r4 + poly[5]*r3 + poly[6]*r2 + poly[7]*r + poly[8];
        
        // Buscar cambio de signo (indica raiz)
        if (prev_val * val < 0) {
            double r_left = r / 1.1;
            double r_right = r;
            
            // Bisección para refinar
            for (int i = 0; i < 50; i++) {
                double r_mid = (r_left + r_right) / 2.0;
                
                double r_mid2 = r_mid * r_mid; double r_mid3 = r_mid2 * r_mid; 
                double r_mid4 = r_mid3 * r_mid; double r_mid5 = r_mid4 * r_mid; 
                double r_mid6 = r_mid5 * r_mid; double r_mid7 = r_mid6 * r_mid; 
                double r_mid8 = r_mid7 * r_mid;
                
                double val_mid = poly[0]*r_mid8 + poly[1]*r_mid7 + poly[2]*r_mid6 + 
                                poly[3]*r_mid5 + poly[4]*r_mid4 + poly[5]*r_mid3 + 
                                poly[6]*r_mid2 + poly[7]*r_mid + poly[8];
                
                if (std::abs(val_mid) < 1e-10 || (r_right - r_left) < 1e-6) {
                    best_r = r_mid;
                    found_sign_change = true;
                    break;
                }
                
                if (prev_val * val_mid < 0) {
                    r_right = r_mid;
                } else {
                    r_left = r_mid;
                    prev_val = val_mid;
                }
            }
            break;
        }
        prev_val = val;
    }
    
    // Si no encontramos cambio de signo, buscar el minimo absoluto
    if (!found_sign_change) {
        double min_abs_val = 1e50;
        for (double r = r_start; r <= r_max; r *= 1.01) {
            double r2 = r * r; double r3 = r2 * r; double r4 = r3 * r; 
            double r5 = r4 * r; double r6 = r5 * r; double r7 = r6 * r; double r8 = r7 * r;
            
            double val = poly[0]*r8 + poly[1]*r7 + poly[2]*r6 + poly[3]*r5 + 
                         poly[4]*r4 + poly[5]*r3 + poly[6]*r2 + poly[7]*r + poly[8];
            
            double abs_val = std::abs(val);
            if (abs_val < min_abs_val) {
                min_abs_val = abs_val;
                best_r = r;
            }
        }
    }
    
    return best_r;
}

void anglesg(double az1, double az2, double az3, double el1, double el2, double el3,
             double Mjd1, double Mjd2, double Mjd3, 
             const Matrix& Rs1, const Matrix& Rs2, const Matrix& Rs3,
             const Matrix& eopdata, Matrix*& r2, Matrix*& v2)
{
    Matrix L1(3, 1);
    L1(1) = std::cos(el1)*std::sin(az1);
    L1(2) = std::cos(el1)*std::cos(az1);
    L1(3) = std::sin(el1);
    
    Matrix L2(3, 1);
    L2(1) = std::cos(el2)*std::sin(az2);
    L2(2) = std::cos(el2)*std::cos(az2);
    L2(3) = std::sin(el2);
    
    Matrix L3(3, 1);
    L3(1) = std::cos(el3)*std::sin(az3);
    L3(2) = std::cos(el3)*std::cos(az3);
    L3(3) = std::sin(el3);
    
    double lon1, lat1, h1, lon2, lat2, h2, lon3, lat3, h3;
    Geodetic(Rs1, lon1, lat1, h1);
    Geodetic(Rs2, lon2, lat2, h2);
    Geodetic(Rs3, lon3, lat3, h3);
    
    Matrix M1 = LTC(lon1, lat1);
    Matrix M2 = LTC(lon2, lat2);
    Matrix M3 = LTC(lon3, lat3);
    
    // Sistema body-fixed - MATLAB usa M1 para todos :/
    Matrix Lb1 = M1.transpose() * L1;
    Matrix Lb2 = M1.transpose() * L2;  
    Matrix Lb3 = M1.transpose() * L3;  
    
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS(eopdata, Mjd1, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    
    double Mjd_TT = Mjd1 + TT_UTC/86400.0;
    double Mjd_UT1 = Mjd_TT + (UT1_UTC-TT_UTC)/86400.0;
    
    Matrix P = PrecMatrix(MJD_J2000, Mjd_TT);
    Matrix N = NutMatrix(Mjd_TT);
    Matrix T = N * P;
    Matrix E = PoleMatrix(x_pole, y_pole) * GHAMatrix(Mjd_UT1) * T;
    
    Matrix Lm1 = E.transpose() * Lb1;
    Matrix Rs1_inertial = E.transpose() * Rs1;
    
    IERS(eopdata, Mjd2, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    
    Mjd_TT = Mjd2 + TT_UTC/86400.0;
    Mjd_UT1 = Mjd_TT + (UT1_UTC-TT_UTC)/86400.0;
    
    P = PrecMatrix(MJD_J2000, Mjd_TT);
    N = NutMatrix(Mjd_TT);
    T = N * P;
    E = PoleMatrix(x_pole, y_pole) * GHAMatrix(Mjd_UT1) * T;
    
    Matrix Lm2 = E.transpose() * Lb2;
    Matrix Rs2_inertial = E.transpose() * Rs2;
    
    IERS(eopdata, Mjd3, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    
    Mjd_TT = Mjd3 + TT_UTC/86400.0;
    Mjd_UT1 = Mjd_TT + (UT1_UTC-TT_UTC)/86400.0;
    
    P = PrecMatrix(MJD_J2000, Mjd_TT);
    N = NutMatrix(Mjd_TT);
    T = N * P;
    E = PoleMatrix(x_pole, y_pole) * GHAMatrix(Mjd_UT1) * T;
    
    Matrix Lm3 = E.transpose() * Lb3;
    Matrix Rs3_inertial = E.transpose() * Rs3;
    
    // % geocentric inertial position
    double tau1 = (Mjd1-Mjd2)*86400.0;
    double tau3 = (Mjd3-Mjd2)*86400.0;
    
    double a1 = tau3/(tau3-tau1);
    double a3 = -tau1/(tau3-tau1);
    
    double b1 = tau3/(6.0*(tau3-tau1))*((tau3-tau1)*(tau3-tau1)-tau3*tau3);
    double b3 = -tau1/(6.0*(tau3-tau1))*((tau3-tau1)*(tau3-tau1)-tau1*tau1);
    
    // Matriz D = inv([Lm1,Lm2,Lm3])*[Rs1,Rs2,Rs2]
    Matrix LM(3, 3);
    LM.assign_column(1, Lm1);
    LM.assign_column(2, Lm2);
    LM.assign_column(3, Lm3);
    
    Matrix RS(3, 3);
    RS.assign_column(1, Rs1_inertial);
    RS.assign_column(2, Rs2_inertial);
    RS.assign_column(3, Rs2_inertial);  // Rs2 dos veces como en MATLAB
    
    Matrix D = LM.inverse() * RS;
    
    double d1s = D(2,1)*a1 - D(2,2) + D(2,3)*a3;
    double d2s = D(2,1)*b1 + D(2,3)*b3;
    
    double Ccye = 2.0*Matrix::dot(Lm2, Rs2_inertial);
    
    // Polinomio de grado 8 para R2
    double poly[9];
    poly[0] = 1.0;  // R2^8
    poly[1] = 0.0;
    poly[2] = -(d1s*d1s + d1s*Ccye + Rs2_inertial.norm()*Rs2_inertial.norm());
    poly[3] = 0.0;
    poly[4] = 0.0;
    poly[5] = -GM_Earth*(d2s*Ccye + 2.0*d1s*d2s);
    poly[6] = 0.0;
    poly[7] = 0.0;
    poly[8] = -GM_Earth*GM_Earth*d2s*d2s;
    
    double bigr2 = find_largest_real_root(poly);
    
    double u = GM_Earth/(bigr2*bigr2*bigr2);
    
    double C1 = a1 + b1*u;
    double C2 = -1.0;
    double C3 = a3 + b3*u;
    
    Matrix C_vec(3, 1);
    C_vec(1) = C1; C_vec(2) = C2; C_vec(3) = C3;
    Matrix temp = D * C_vec * (-1.0);
    
    double rho1 = temp(1)/(a1+b1*u);
    double rho2 = -temp(2);
    double rho3 = temp(3)/(a3+b3*u);
    
    double rhoold1 = rho1;
    double rhoold2 = rho2;
    double rhoold3 = rho3;
    
    rho2 = 99999999.9;
    int ll = 0;
    
    Matrix *v2_result = nullptr;
    

    // printf("DEBUG PRE-WHILE: bigr2=%.1f, rho1=%.1f, rho2=%.1f, rho3=%.1f\n", 
    //     bigr2, rho1, rho2, rho3);

    while ((std::abs(rhoold2-rho2) > 1e-12) && (ll <= 0)) {
        ll = ll + 1;
        rho2 = rhoold2;
        
        Matrix r1_calc = Rs1_inertial + Lm1 * rho1;
        Matrix r2_calc = Rs2_inertial + Lm2 * rho2;
        Matrix r3_calc = Rs3_inertial + Lm3 * rho3;
        
        double magr1 = r1_calc.norm();
        double magr2 = r2_calc.norm();
        double magr3 = r3_calc.norm();
        
        Matrix *v2_temp = new Matrix(3, 1);
        double theta, theta1, copa;
        std::string error;
        
        gibbs(r1_calc, r2_calc, r3_calc, v2_temp, theta, theta1, copa, error);

//         printf("DEBUG DESPUES GIBBS: error='%s', copa=%.6f\n", error.c_str(), copa);
// printf("DEBUG DESPUES GIBBS: v2_gibbs=[%.3f, %.3f, %.3f]\n", 
//        (*v2_temp)(1), (*v2_temp)(2), (*v2_temp)(3));
// printf("DEBUG CONDICION: (error != ok)=%s, (copa < limit)=%s, copa y pi/180: %f, %f\n",
//        (error != "          ok") ? "true" : "false",
//        (copa < M_PI/180.0) ? "true" : "false", copa, M_PI/180.0);

//        printf("DEBUG C++: error = '%s'\n", error.c_str());
// printf("DEBUG C++: error.length() = %zu\n", error.length());
// printf("DEBUG C++: error != '          ok' = %s\n", (error != "          ok") ? "true" : "false");
// printf("DEBUG C++: copa < pi/180 = %s\n", (copa < M_PI/180.0) ? "true" : "false");
// printf("DEBUG C++: condicion completa = %s\n", ((error != "          ok") && (copa < M_PI/180.0)) ? "true" : "false");
        
        if ((std::strcmp(error.c_str(), "          ok") != 0) && (copa < M_PI/180.0)) {
            delete v2_temp;
            v2_temp = new Matrix(3, 1);
            hgibbs(r1_calc, r2_calc, r3_calc, Mjd1, Mjd2, Mjd3, v2_temp, theta, theta1, copa, error);
        }
        
        v2_result = new Matrix(*v2_temp);
        
        Matrix state(6, 1);
        state(1) = r2_calc(1); state(2) = r2_calc(2); state(3) = r2_calc(3);
        state(4) = (*v2_temp)(1); state(5) = (*v2_temp)(2); state(6) = (*v2_temp)(3);
        
        double p, a, e, i, Omega, omega, M;
        elements(state, p, a, e, i, Omega, omega, M);
        
        if (ll <= 8) {
            u = GM_Earth/(magr2*magr2*magr2);
            double rdot = Matrix::dot(r2_calc, *v2_temp)/magr2;
            double udot = (-3.0*GM_Earth*rdot)/(magr2*magr2*magr2*magr2);
            
            double tausqr = tau1*tau1;
            double f1 = 1.0 - 0.5*u*tausqr - (1.0/6.0)*udot*tausqr*tau1
                      - (1.0/24.0)*u*u*tausqr*tausqr
                      - (1.0/30.0)*u*udot*tausqr*tausqr*tau1;
            double g1 = tau1 - (1.0/6.0)*u*tau1*tausqr - (1.0/12.0)*udot*tausqr*tausqr
                      - (1.0/120.0)*u*u*tausqr*tausqr*tau1
                      - (1.0/120.0)*u*udot*tausqr*tausqr*tausqr;
            
            tausqr = tau3*tau3;
            double f3 = 1.0 - 0.5*u*tausqr - (1.0/6.0)*udot*tausqr*tau3
                      - (1.0/24.0)*u*u*tausqr*tausqr
                      - (1.0/30.0)*u*udot*tausqr*tausqr*tau3;
            double g3 = tau3 - (1.0/6.0)*u*tau3*tausqr - (1.0/12.0)*udot*tausqr*tausqr
                      - (1.0/120.0)*u*u*tausqr*tausqr*tau3
                      - (1.0/120.0)*u*udot*tausqr*tausqr*tausqr;
            
            C1 = g3/(f1*g3-f3*g1);
            C2 = -1.0;
            C3 = -g1/(f1*g3-f3*g1);
        } else {
            theta = angl(r1_calc, r2_calc);
            theta1 = angl(r2_calc, r3_calc);
            
            double f1 = 1.0 - (magr1*(1.0 - std::cos(theta))/p);
            double g1 = (magr1*magr2*std::sin(-theta))/std::sqrt(p);
            double f3 = 1.0 - (magr3*(1.0 - std::cos(theta1))/p);
            double g3 = (magr3*magr2*std::sin(theta1))/std::sqrt(p);
            
            C1 = g3/(f1*g3-f3*g1);
            C2 = -1.0;
            C3 = -g1/(f1*g3-f3*g1);
        }
        
        double H1 = GM_Earth*tau3/12.0;
        double H3 = -GM_Earth*tau1/12.0;
        double H2 = H1 - H3;
        
        double G1 = -tau3/(tau1*(tau3-tau1));
        double G3 = -tau1/(tau3*(tau3-tau1));
        double G2 = G1 - G3;
        
        double D1 = G1 + H1/(magr1*magr1*magr1);
        double D2 = G2 + H2/(magr2*magr2*magr2);
        double D3 = G3 + H3/(magr3*magr3*magr3);
        
        Matrix D_vec(3, 1);
        D_vec(1) = D1; D_vec(2) = D2; D_vec(3) = D3;
        C_vec(1) = C1; C_vec(2) = C2; C_vec(3) = C3;
        double temp_scalar = -Matrix::dot(D_vec, C_vec);
        
        rhoold1 = temp_scalar/(a1+b1*u);
        rhoold2 = -temp_scalar;
        rhoold3 = temp_scalar/(a3+b3*u);
        
        r1_calc = Rs1_inertial + Lm1 * rhoold1;
        r2_calc = Rs2_inertial + Lm2 * rhoold2;
        r3_calc = Rs3_inertial + Lm3 * rhoold3;
        
        delete v2_temp;
    }

//     printf("DEBUG POST-WHILE: rho1=%.1f, rho2=%.1f, rho3=%.1f\n", 
//         rho1, rho2, rho3);
//  printf("DEBUG v2_result norm: %.1f\n", 
//         v2_result ? v2_result->norm() : -999.0);
    
    Matrix r1_final = Rs1_inertial + Lm1 * rho1;
    Matrix r2_final = Rs2_inertial + Lm2 * rho2;
    Matrix r3_final = Rs3_inertial + Lm3 * rho3;
    
    r2 = new Matrix(r2_final);
    v2 = v2_result;
}

void debug_anglesg_complete()
{
    printf("=== ANGLESG DEBUG COMPLETO C++ ===\n");
    
    // Inputs para test de 2 horas
    double az1 = 1.2, az2 = 1.25, az3 = 1.3;
    double el1 = 0.5, el2 = 0.55, el3 = 0.6;
    double Mjd1 = 58849.0;
    double Mjd2 = Mjd1 + 2.0/24.0;  // +2 horas
    double Mjd3 = Mjd2 + 2.0/24.0;  // +2 horas
    
    Matrix Rs(3, 1);
    Rs(1) = -5466082.0; Rs(2) = -2404436.0; Rs(3) = 2242887.0;
    
    Matrix eopdata(13, 3);
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 3; j++) {
            eopdata(i, j) = 0.0;
        }
    }
    eopdata(4, 1) = std::floor(Mjd1);
    eopdata(4, 2) = std::floor(Mjd2);  
    eopdata(4, 3) = std::floor(Mjd3);
    
    printf("INPUTS:\n");
    printf("az1=%.6f, az2=%.6f, az3=%.6f [rad]\n", az1, az2, az3);
    printf("el1=%.6f, el2=%.6f, el3=%.6f [rad]\n", el1, el2, el3);
    printf("Mjd1=%.6f, Mjd2=%.6f, Mjd3=%.6f\n", Mjd1, Mjd2, Mjd3);
    printf("Rs = [%.1f, %.1f, %.1f] m\n", Rs(1), Rs(2), Rs(3));
    
    Matrix *r2_result = nullptr;
    Matrix *v2_result = nullptr;
    
    anglesg(az1, az2, az3, el1, el2, el3, Mjd1, Mjd2, Mjd3, 
            Rs, Rs, Rs, eopdata, r2_result, v2_result);
    
    printf("\nRESULTADOS C++:\n");
    printf("r2 = [%.6f, %.6f, %.6f] m\n", (*r2_result)(1), (*r2_result)(2), (*r2_result)(3));
    printf("||r2|| = %.6f km\n", r2_result->norm()/1000.0);
    printf("v2 = [%.6f, %.6f, %.6f] m/s\n", (*v2_result)(1), (*v2_result)(2), (*v2_result)(3));
    printf("||v2|| = %.6f m/s\n", v2_result->norm());
    
    delete r2_result;
    delete v2_result;
    
    printf("=== FIN DEBUG C++ ===\n");
}

void test_anglesg()
{
    // Ejecutar debug completo primero
    // debug_anglesg_complete();
    
    // Test principal: 1 hora de separacion
    double az1 = 1.2, az2 = 1.25, az3 = 1.3;
    double el1 = 0.5, el2 = 0.55, el3 = 0.6;
    double Mjd1 = 58849.0;
    double Mjd2 = Mjd1 + 1.0/24.0;
    double Mjd3 = Mjd2 + 1.0/24.0;
    
    Matrix Rs(3, 1);
    Rs(1) = -5466082.0; Rs(2) = -2404436.0; Rs(3) = 2242887.0;
    
    Matrix eopdata(13, 3);
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 3; j++) {
            eopdata(i, j) = 0.0;
        }
    }
    eopdata(4, 1) = std::floor(Mjd1);
    eopdata(4, 2) = std::floor(Mjd2);  
    eopdata(4, 3) = std::floor(Mjd3);
    
    Matrix *r2_result = nullptr;
    Matrix *v2_result = nullptr;
    
    anglesg(az1, az2, az3, el1, el2, el3, Mjd1, Mjd2, Mjd3, 
            Rs, Rs, Rs, eopdata, r2_result, v2_result);
    
    assert(r2_result != nullptr && v2_result != nullptr);
    
    double r_mag = r2_result->norm();
    double v_mag = v2_result->norm();
    
    // printf("Test 1h REAL: ||r2|| = %.1f km, ||v2|| = %.1f m/s\n", r_mag/1000.0, v_mag);
    
    // Basado en MATLAB: 29177.6 km, 1895.655 m/s
    assert(r_mag > 28000.0e3 && r_mag < 30000.0e3);  // 28-30 mil km
    assert(v_mag > 1800.0 && v_mag < 2000.0);        // 1.8-2.0 km/s
    
    for (int i = 1; i <= 3; i++) {
        assert(!std::isnan((*r2_result)(i)) && !std::isinf((*r2_result)(i)));
        assert(!std::isnan((*v2_result)(i)) && !std::isinf((*v2_result)(i)));
    }
    
    // printf("Test 1h: ||r2|| = %.1f km, ||v2|| = %.1f m/s PASSED\n", r_mag/1000.0, v_mag);
    delete r2_result; delete v2_result;
    
    // Test 2: separacion de 2 horas
    double Mjd2_test2 = Mjd1 + 2.0/24.0;
    double Mjd3_test2 = Mjd2_test2 + 2.0/24.0;
    
    Matrix *r2_test2 = nullptr, *v2_test2 = nullptr;
    anglesg(az1, az2, az3, el1, el2, el3, Mjd1, Mjd2_test2, Mjd3_test2,
            Rs, Rs, Rs, eopdata, r2_test2, v2_test2);
    
    double r_mag2 = r2_test2->norm();
    double v_mag2 = v2_test2->norm();
    
    // printf("Test 2h REAL: ||r2|| = %.1f km, ||v2|| = %.1f m/s\n", r_mag2/1000.0, v_mag2);
    
    // Basado en MATLAB: 25570.2 km, 2678.199 m/s  
    assert(r_mag2 > 24000.0e3 && r_mag2 < 27000.0e3);
    assert(v_mag2 > 2600.0 && v_mag2 < 2800.0);
    
    // printf("Test 2h: ||r2|| = %.1f km, ||v2|| = %.1f m/s PASSED\n", r_mag2/1000.0, v_mag2);
    delete r2_test2; delete v2_test2;
}

void debug_azimuts_diferentes() {
    printf("=== DEBUG AZIMUTS DIFERENTES C++ ===\n");
    
    double az1 = 1.1, az2 = 1.15, az3 = 1.2;  // Los problemáticos
    double el1 = 0.5, el2 = 0.55, el3 = 0.6;
    double Mjd1 = 58849.0;
    double Mjd2 = Mjd1 + 1.0/24.0;
    double Mjd3 = Mjd2 + 1.0/24.0;
    
    Matrix Rs(3, 1);
    Rs(1) = -5466082.0; Rs(2) = -2404436.0; Rs(3) = 2242887.0;
    
    Matrix eopdata(13, 3);
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 3; j++) {
            eopdata(i, j) = 0.0;
        }
    }
    eopdata(4, 1) = std::floor(Mjd1);
    eopdata(4, 2) = std::floor(Mjd2);  
    eopdata(4, 3) = std::floor(Mjd3);
    
    Matrix *r2_result = nullptr;
    Matrix *v2_result = nullptr;
    
    anglesg(az1, az2, az3, el1, el2, el3, Mjd1, Mjd2, Mjd3, 
            Rs, Rs, Rs, eopdata, r2_result, v2_result);
    
    printf("RESULTADO C++:\n");
    printf("r2 = [%.6f, %.6f, %.6f] m\n", (*r2_result)(1), (*r2_result)(2), (*r2_result)(3));
    printf("||r2|| = %.6f km\n", r2_result->norm()/1000.0);
    printf("v2 = [%.6f, %.6f, %.6f] m/s\n", (*v2_result)(1), (*v2_result)(2), (*v2_result)(3));
    printf("||v2|| = %.6f m/s\n", v2_result->norm());
    
    delete r2_result; delete v2_result;
    printf("=== FIN DEBUG AZIMUTS C++ ===\n");
}

REGISTER_TEST(test_anglesg);