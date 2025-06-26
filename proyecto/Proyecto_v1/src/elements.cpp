#include "elements.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void elements(const Matrix& y, double& p, double& a, double& e, double& i, 
              double& Omega, double& omega, double& M)
{
    const double pi2 = 2.0 * M_PI;
    
    Matrix r(3, 1);
    Matrix v(3, 1);
    r(1) = y(1); r(2) = y(2); r(3) = y(3);  // Position
    v(1) = y(4); v(2) = y(5); v(3) = y(6);  // Velocity
    
    // Areal velocity
    Matrix h = Matrix::cross(r, v);
    double magh = h.norm();
    p = magh * magh / GM_Earth;
    double H = h.norm();
    
    // Long. ascend. node 
    Omega = std::atan2(h(1), -h(2));
    Omega = std::fmod(Omega, pi2);
    if (Omega < 0) Omega += pi2;  // me aseguro que pos
    
    // Inclination
    i = std::atan2(std::sqrt(h(1)*h(1) + h(2)*h(2)), h(3));
    
    // Arg. of latitude
    double u = std::atan2(r(3)*H, -r(1)*h(2) + r(2)*h(1));
    
    // Distance
    double R = r.norm();
    
    // Semi-major axis
    double v_squared = Matrix::dot(v, v);
    a = 1.0 / (2.0/R - v_squared/GM_Earth);
    
    // e*cos(E) y e*sin(E)
    double eCosE = 1.0 - R/a;
    double eSinE = Matrix::dot(r, v) / std::sqrt(GM_Earth * a);
    
    // Eccentricity
    double e2 = eCosE*eCosE + eSinE*eSinE;
    e = std::sqrt(e2);
    
    // Eccentric anomaly
    double E = std::atan2(eSinE, eCosE);
    
    // Mean anomaly
    M = std::fmod(E - eSinE, pi2);
    if (M < 0) M += pi2;  // Ensure positive
    
    // True anomaly
    double nu = std::atan2(std::sqrt(1.0 - e2) * eSinE, eCosE - e2);
    
    // Arg. of pericenter
    omega = std::fmod(u - nu, pi2);
    if (omega < 0) omega += pi2;  // pos
}

void elements_debug(const Matrix& y)
{
    const double pi2 = 2.0 * M_PI;
    
    printf("=== ELEMENTS DEBUG ===\n");
    printf("Input state vector:\n");
    printf("r = [%.6f, %.6f, %.6f] m\n", y(1), y(2), y(3));
    printf("v = [%.6f, %.6f, %.6f] m/s\n", y(4), y(5), y(6));
    
    // Extract position and velocity vectors
    Matrix r(3, 1);
    Matrix v(3, 1);
    r(1) = y(1); r(2) = y(2); r(3) = y(3);
    v(1) = y(4); v(2) = y(5); v(3) = y(6);
    
    printf("\npi2 = %.10f\n", pi2);
    
    // Cross product h = cross(r,v)
    Matrix h = Matrix::cross(r, v);
    printf("h = cross(r,v) = [%.10f, %.10f, %.10f] m²/s\n", h(1), h(2), h(3));
    
    double magh = h.norm();
    printf("magh = norm(h) = %.10f m²/s\n", magh);
    
    double p = magh * magh / GM_Earth;
    printf("p = magh²/GM_Earth = %.10f / %.10f = %.10f m\n", 
           magh*magh, GM_Earth, p);
    
    double H = h.norm();
    printf("H = norm(h) = %.10f m²/s (same as magh)\n", H);
    
    // Longitude of ascending node
    double Omega_raw = std::atan2(h(1), -h(2));
    printf("Omega_raw = atan2(h(1), -h(2)) = atan2(%.10f, %.10f) = %.10f rad\n", 
           h(1), -h(2), Omega_raw);
    
    double Omega = std::fmod(Omega_raw, pi2);
    if (Omega < 0) Omega += pi2;
    printf("Omega = mod(Omega_raw, pi2) = %.10f rad = %.6f deg\n", 
           Omega, Omega * 180.0/M_PI);
    
    // Inclination  
    double sqrt_term = std::sqrt(h(1)*h(1) + h(2)*h(2));
    printf("sqrt(h(1)² + h(2)²) = sqrt(%.10f + %.10f) = %.10f\n", 
           h(1)*h(1), h(2)*h(2), sqrt_term);
    
    double i = std::atan2(sqrt_term, h(3));
    printf("i = atan2(sqrt_term, h(3)) = atan2(%.10f, %.10f) = %.10f rad = %.6f deg\n", 
           sqrt_term, h(3), i, i * 180.0/M_PI);
    
    // Argument of latitude
    double u_num = r(3) * H;
    double u_den = -r(1)*h(2) + r(2)*h(1);
    printf("u_num = r(3)*H = %.10f * %.10f = %.10f\n", r(3), H, u_num);
    printf("u_den = -r(1)*h(2) + r(2)*h(1) = %.10f*%.10f + %.10f*%.10f = %.10f\n", 
           -r(1), h(2), r(2), h(1), u_den);
    
    double u = std::atan2(u_num, u_den);
    printf("u = atan2(u_num, u_den) = %.10f rad = %.6f deg\n", 
           u, u * 180.0/M_PI);
    
    // Distance
    double R = r.norm();
    printf("R = norm(r) = %.10f m\n", R);
    
    // Semi-major axis
    double v_squared = Matrix::dot(v, v);
    printf("v_squared = dot(v,v) = %.10f m²/s²\n", v_squared);
    
    double energy_term = 2.0/R - v_squared/GM_Earth;
    printf("energy_term = 2/R - v²/GM = %.10f - %.10f = %.10f\n", 
           2.0/R, v_squared/GM_Earth, energy_term);
    
    double a = 1.0 / energy_term;
    printf("a = 1/energy_term = %.10f m\n", a);
    
    // e*cos(E) and e*sin(E)
    double eCosE = 1.0 - R/a;
    printf("eCosE = 1 - R/a = 1 - %.10f/%.10f = %.10f\n", R, a, eCosE);
    
    double r_dot_v = Matrix::dot(r, v);
    printf("dot(r,v) = %.10f m²/s\n", r_dot_v);
    
    double sqrt_GM_a = std::sqrt(GM_Earth * a);
    printf("sqrt(GM*a) = sqrt(%.10f * %.10f) = %.10f\n", GM_Earth, a, sqrt_GM_a);
    
    double eSinE = r_dot_v / sqrt_GM_a;
    printf("eSinE = dot(r,v)/sqrt(GM*a) = %.10f/%.10f = %.10f\n", 
           r_dot_v, sqrt_GM_a, eSinE);
    
    // Eccentricity
    double e2 = eCosE*eCosE + eSinE*eSinE;
    printf("e² = eCosE² + eSinE² = %.10f + %.10f = %.10f\n", 
           eCosE*eCosE, eSinE*eSinE, e2);
    
    double e = std::sqrt(e2);
    printf("e = sqrt(e²) = %.10f\n", e);
    
    // Eccentric anomaly
    double E = std::atan2(eSinE, eCosE);
    printf("E = atan2(eSinE, eCosE) = atan2(%.10f, %.10f) = %.10f rad = %.6f deg\n", 
           eSinE, eCosE, E, E * 180.0/M_PI);
    
    // Mean anomaly
    double M_raw = E - eSinE;
    printf("M_raw = E - eSinE = %.10f - %.10f = %.10f\n", E, eSinE, M_raw);
    
    double M = std::fmod(M_raw, pi2);
    if (M < 0) M += pi2;
    printf("M = mod(M_raw, pi2) = %.10f rad = %.6f deg\n", M, M * 180.0/M_PI);
    
    // True anomaly
    double nu_num = std::sqrt(1.0 - e2) * eSinE;
    double nu_den = eCosE - e2;
    printf("nu_num = sqrt(1-e²)*eSinE = sqrt(%.10f)*%.10f = %.10f\n", 
           1.0-e2, eSinE, nu_num);
    printf("nu_den = eCosE - e² = %.10f - %.10f = %.10f\n", eCosE, e2, nu_den);
    
    double nu = std::atan2(nu_num, nu_den);
    printf("nu = atan2(nu_num, nu_den) = %.10f rad = %.6f deg\n", 
           nu, nu * 180.0/M_PI);
    
    // Argument of pericenter
    double omega_raw = u - nu;
    printf("omega_raw = u - nu = %.10f - %.10f = %.10f\n", u, nu, omega_raw);
    
    double omega = std::fmod(omega_raw, pi2);
    if (omega < 0) omega += pi2;
    printf("omega = mod(omega_raw, pi2) = %.10f rad = %.6f deg\n", 
           omega, omega * 180.0/M_PI);
    
    printf("\n=== FINAL RESULTS ===\n");
    printf("p = %.6f m\n", p);
    printf("a = %.6f m\n", a);
    printf("e = %.10f\n", e);
    printf("i = %.6f deg\n", i * 180.0/M_PI);
    printf("Omega = %.6f deg\n", Omega * 180.0/M_PI);
    printf("omega = %.6f deg\n", omega * 180.0/M_PI);
    printf("M = %.6f deg\n", M * 180.0/M_PI);
    printf("======================\n\n");
}

void test_elements()
{
    // Test 1: Orbita circular LEO - caso tipico
    Matrix y1(6, 1);
    y1(1) = 7000.0e3; y1(2) = 0.0; y1(3) = 0.0;
    y1(4) = 0.0; y1(5) = 7546.0; y1(6) = 0.0;
    
    double p1, a1, e1, i1, Omega1, omega1, M1;
    elements(y1, p1, a1, e1, i1, Omega1, omega1, M1);
    
    assert(a1 > 6.9e6 && a1 < 7.1e6);  // ~7000 km
    assert(e1 < 0.01);                 // Practicamente circular
    assert(p1 > 6.9e6 && p1 < 7.1e6);   // p ≈ a para circular
    
    // Test 2: Orbita eliptica - satelite en periastro
    Matrix y2(6, 1);
    y2(1) = 6500.0e3; y2(2) = 0.0; y2(3) = 0.0;  // Radio menor
    y2(4) = 0.0; y2(5) = 8000.0; y2(6) = 0.0;     // Velocidad mayor
    
    double p2, a2, e2, i2, Omega2, omega2, M2;
    elements(y2, p2, a2, e2, i2, Omega2, omega2, M2);
    
    assert(a2 > 6500.0e3);           // Semi-eje mayor > radio periastro
    assert(e2 > 0.01 && e2 < 0.4);   // Eliptica moderada
    assert(p2 > 0);                  // Positivo
    
    // Test 3: Orbita inclinada normal
    Matrix y3(6, 1);
    y3(1) = 6000.0e3; y3(2) = 0.0; y3(3) = 3000.0e3;
    y3(4) = 0.0; y3(5) = 7000.0; y3(6) = 1500.0;
    
    double p3, a3, e3, i3, Omega3, omega3, M3;
    elements(y3, p3, a3, e3, i3, Omega3, omega3, M3);
    
    assert(i3 > 0.2 && i3 < 1.2);   // Inclinada razonable
    assert(a3 > 5000.0e3);          // Radio sensato
    assert(e3 >= 0.0 && e3 < 0.8);  // Elipse valida
    
    // Test 4: Orbita alta tipo GPS
    Matrix y4(6, 1);
    y4(1) = 26000.0e3; y4(2) = 0.0; y4(3) = 0.0;
    y4(4) = 0.0; y4(5) = 3900.0; y4(6) = 0.0;
    
    double p4, a4, e4, i4, Omega4, omega4, M4;
    elements(y4, p4, a4, e4, i4, Omega4, omega4, M4);
    
    assert(a4 > 20000.0e3 && a4 < 35000.0e3);  // Rango amplio
    assert(e4 < 0.3);  // Excentricidad moderada
    
    // Test 5: Verificacion basica de consistencia p = a(1-e²)
    double p_calc = a2 * (1.0 - e2*e2);
    assert(std::abs(p2 - p_calc) < 1000.0);  // Tolerancia 1km
    
    // Test 6: Rangos de angulos
    assert(Omega1 >= 0.0 && Omega1 <= 2.0*M_PI);
    assert(omega1 >= 0.0 && omega1 <= 2.0*M_PI);
    assert(M1 >= 0.0 && M1 <= 2.0*M_PI);
    
    // Test 7: No NaN ni infinitos en casos normales
    assert(!std::isnan(a1) && !std::isinf(a1));
    assert(!std::isnan(e2) && !std::isinf(e2));
    assert(!std::isnan(i3) && !std::isinf(i3));
    assert(!std::isnan(p4) && !std::isinf(p4));
    
    // Test 8: Caso con velocidad en X
    Matrix y5(6, 1);
    y5(1) = 0.0; y5(2) = 7000.0e3; y5(3) = 0.0;
    y5(4) = -7546.0; y5(5) = 0.0; y5(6) = 0.0;
    
    double p5, a5, e5, i5, Omega5, omega5, M5;
    elements(y5, p5, a5, e5, i5, Omega5, omega5, M5);
    
    assert(a5 > 6.5e6 && a5 < 7.5e6);  // Radio similar
    assert(e5 < 0.1);                  // Casi circular
}

REGISTER_TEST(test_elements);