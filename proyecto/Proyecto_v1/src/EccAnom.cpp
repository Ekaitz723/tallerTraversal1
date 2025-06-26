#include "EccAnom.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <stdexcept>

double EccAnom(double M, double e)
{
    const int maxit = 15;
    const double eps = 2.220446049250313e-16;
    const double tolerance = 1e2 * eps;
    
    double M_mod = fmod(M, 2.0 * M_PI);
    if (M_mod < 0) M_mod += 2.0 * M_PI;
    
    double E;
    if (e < 0.8) {
        E = M_mod;
    } else {
        E = M_PI;
    }
    
    double f = E - e * sin(E) - M_mod;
    E = E - f / (1.0 - e * cos(E));
    
    int i = 1;
    while (fabs(f) > tolerance) {
        f = E - e * sin(E) - M_mod;
        E = E - f / (1.0 - e * cos(E));
        i++;
        if (i == maxit) {
            throw std::runtime_error("convergence problems in EccAnom");
        }
    }
    
    return E;
}

void test_EccAnom()
{
    const double pi = M_PI;
    
    // Test 1: Orbita circular (e=0) - E debe ser igual a M
    double M1 = pi/4;
    double e1 = 0.0;
    double E1 = EccAnom(M1, e1);
    assert(fabs(E1 - M1) < 1e-14);
    
    // Test 2: Caso conocido - e=0.5, M=pi/2
    double M2 = pi/2;
    double e2 = 0.5;
    double E2 = EccAnom(M2, e2);
    // Para e=0.5 y M=pi/2, E ≈ 2.020979938 radianes
    assert(fabs(E2 - 2.020979938) < 1e-8);
    
    // Test 3: Excentricidad alta e=0.9, M=pi
    double M3 = pi;
    double e3 = 0.9;
    double E3 = EccAnom(M3, e3);
    // Para M=pi, sin(pi)=0, entonces E debe ser igual a M
    assert(fabs(E3 - M3) < 1e-12);
    assert(E3 > 0 && E3 < 2*pi);
    
    // Test 4: Anomalia media mayor que 2pi debe normalizarse
    double M4 = 3*pi;
    double e4 = 0.3;
    double E4 = EccAnom(M4, e4);
    double E4_equiv = EccAnom(pi, e4);
    assert(fabs(E4 - E4_equiv) < 1e-12);
    
    // Test 5: Verificar ecuacion de Kepler: M = E - e*sin(E)
    double M5 = pi/3;
    double e5 = 0.6;
    double E5 = EccAnom(M5, e5);
    double M_calculated = E5 - e5 * sin(E5);
    assert(fabs(M_calculated - M5) < 1e-12);
    
    // Test 6: Casos extremos - excentricidad muy baja
    double M6 = pi/6;
    double e6 = 0.001;
    double E6 = EccAnom(M6, e6);
    assert(fabs(E6 - M6) < 0.01);
    
    // Test 7: Anomalia media negativa (debe manejar normalizacion)
    double M7 = -pi/4;
    double e7 = 0.4;
    double E7 = EccAnom(M7, e7);
    assert(E7 > 0);
    assert(E7 < 2*pi);
    
    // Test 8: Verificar que no converge con demasiadas iteraciones (artificial)
    double M8 = pi;
    double e8 = 0.99;
    double E8 = EccAnom(M8, e8);
    assert(E8 > 0 && E8 < 2*pi);
}

REGISTER_TEST(test_EccAnom);