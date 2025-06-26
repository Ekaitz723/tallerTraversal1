#include "Frac.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double Frac(double x)
{
    return x - floor(x);
}

void test_Frac()
{
    // Test 1: Numeros positivos con parte fraccionaria
    assert(fabs(Frac(3.7) - 0.7) < 1e-15);
    assert(fabs(Frac(2.25) - 0.25) < 1e-15);
    assert(fabs(Frac(1.9999) - 0.9999) < 1e-15);
    
    // Test 2: Numeros enteros positivos
    assert(fabs(Frac(5.0) - 0.0) < 1e-15);
    assert(fabs(Frac(100.0) - 0.0) < 1e-15);
    
    // Test 3: Numeros entre 0 y 1
    assert(fabs(Frac(0.5) - 0.5) < 1e-15);
    assert(fabs(Frac(0.1234) - 0.1234) < 1e-15);
    
    // Test 4: Cero
    assert(fabs(Frac(0.0) - 0.0) < 1e-15);
    
    // Test 5: Numeros negativos 
    // floor(-2.3) = -3, entonces -2.3 - (-3) = 0.7
    assert(fabs(Frac(-2.3) - 0.7) < 1e-15);
    assert(fabs(Frac(-1.25) - 0.75) < 1e-15);
    
    // Test 6: Enteros negativos
    assert(fabs(Frac(-5.0) - 0.0) < 1e-15);
    
    // Test 7: Casos relacionados con gmst (uso tipico)
    // Simular calculo de gmst donde se usa Frac(gmst/Secs)
    double gmst = 86400.0 + 12345.678;  // Segundos
    double Secs = 86400.0;
    double frac_result = Frac(gmst/Secs);
    assert(frac_result >= 0.0 && frac_result < 1.0);
    assert(fabs(frac_result - 0.142889792) < 1e-6);
    
    // Test 8: Numeros muy grandes
    double big_num = 1234567.89;
    double frac_big = Frac(big_num);
    assert(fabs(frac_big - 0.89) < 1e-6);
    
    // Test 9: Numeros muy pequeños
    double small_num = 0.00001234;
    assert(fabs(Frac(small_num) - small_num) < 1e-15);
}

REGISTER_TEST(test_Frac);