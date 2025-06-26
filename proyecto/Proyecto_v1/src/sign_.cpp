#include "sign_.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double sign_(double a, double b)
{
    if (b >= 0.0) {
        return fabs(a);
    } else {
        return -fabs(a);
    }
}

void test_sign_()
{
    // Test 1: b positivo, a positivo
    assert(fabs(sign_(5.0, 3.0) - 5.0) < 1e-15);
    
    // Test 2: b positivo, a negativo  
    assert(fabs(sign_(-5.0, 3.0) - 5.0) < 1e-15);
    
    // Test 3: b negativo, a positivo
    assert(fabs(sign_(5.0, -3.0) - (-5.0)) < 1e-15);
    
    // Test 4: b negativo, a negativo
    assert(fabs(sign_(-5.0, -3.0) - (-5.0)) < 1e-15);
    
    // Test 5: b cero (debe ser tratado como positivo según condición b >= 0.0)
    assert(fabs(sign_(5.0, 0.0) - 5.0) < 1e-15);
    assert(fabs(sign_(-5.0, 0.0) - 5.0) < 1e-15);
    
    // Test 6: a cero
    assert(fabs(sign_(0.0, 5.0) - 0.0) < 1e-15);
    assert(fabs(sign_(0.0, -5.0) - 0.0) < 1e-15);
    
    // Test 7: Casos típicos de uso en DEInteg - paso de tiempo positivo
    double tout = 2000.0;
    double x = 1000.0;
    double h_input = 500.0;
    double h_result = sign_(h_input, tout-x);  // tout-x = 1000 > 0
    assert(fabs(h_result - 500.0) < 1e-12);
    
    // Test 8: Casos típicos de uso en DEInteg - paso de tiempo negativo  
    double h_result2 = sign_(h_input, x-tout);  // x-tout = -1000 < 0
    assert(fabs(h_result2 - (-500.0)) < 1e-12);
    
    // Test 9: Números muy pequeños 
    assert(fabs(sign_(1e-15, 1e-14) - 1e-15) < 1e-16);
    assert(fabs(sign_(1e-15, -1e-14) - (-1e-15)) < 1e-16);
    
    // Test 10: Números muy grandes
    assert(fabs(sign_(1e15, 1e14) - 1e15) < 1e12);
    assert(fabs(sign_(1e15, -1e14) - (-1e15)) < 1e12);
    
    // Test 11: Verificar comportamiento con valores fraccionarios
    assert(fabs(sign_(3.7, 2.1) - 3.7) < 1e-15);
    assert(fabs(sign_(-3.7, 2.1) - 3.7) < 1e-15);
    assert(fabs(sign_(3.7, -2.1) - (-3.7)) < 1e-15);
    assert(fabs(sign_(-3.7, -2.1) - (-3.7)) < 1e-15);
}

REGISTER_TEST(test_sign_);