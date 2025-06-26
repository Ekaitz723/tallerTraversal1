#include "Cheb3D.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <stdexcept>

Matrix Cheb3D(double t, int N, double Ta, double Tb, 
              const double Cx[], const double Cy[], const double Cz[])
{
    if ((t < Ta) || (Tb < t)) {
        throw std::runtime_error("ERROR: Time out of range in Cheb3D::Value");
    }
    
    double tau = (2*t - Ta - Tb) / (Tb - Ta);
    
    double f1[3] = {0.0, 0.0, 0.0};
    double f2[3] = {0.0, 0.0, 0.0};
    
    for (int i = N-1; i >= 1; i--) {
        const double old_f1[3] = {f1[0], f1[1], f1[2]};
        
        f1[0] = 2*tau*f1[0] - f2[0] + Cx[i];
        f1[1] = 2*tau*f1[1] - f2[1] + Cy[i];
        f1[2] = 2*tau*f1[2] - f2[2] + Cz[i];
        
        f2[0] = old_f1[0];
        f2[1] = old_f1[1];
        f2[2] = old_f1[2];
    }
    
    Matrix ChebApp(3, 1);
    ChebApp(1) = tau*f1[0] - f2[0] + Cx[0];
    ChebApp(2) = tau*f1[1] - f2[1] + Cy[0];
    ChebApp(3) = tau*f1[2] - f2[2] + Cz[0];
    
    return ChebApp;
}

void test_Cheb3D()
{
    // Test 1: Funcion constante - coeficientes [c, 0, 0] da resultado constante c
    double Cx_const[] = {1.0, 0.0, 0.0};
    double Cy_const[] = {2.0, 0.0, 0.0};
    double Cz_const[] = {3.0, 0.0, 0.0};
    
    Matrix result1 = Cheb3D(0.0, 3, 0.0, 1.0, Cx_const, Cy_const, Cz_const);
    Matrix result2 = Cheb3D(0.5, 3, 0.0, 1.0, Cx_const, Cy_const, Cz_const);
    Matrix result3 = Cheb3D(1.0, 3, 0.0, 1.0, Cx_const, Cy_const, Cz_const);
    
    assert(result1.isVector3D());
    assert(fabs(result1(1) - 1.0) < 1e-12);
    assert(fabs(result1(2) - 2.0) < 1e-12);
    assert(fabs(result1(3) - 3.0) < 1e-12);
    
    assert(fabs(result2(1) - 1.0) < 1e-12);
    assert(fabs(result2(2) - 2.0) < 1e-12);
    assert(fabs(result2(3) - 3.0) < 1e-12);
    
    assert(fabs(result3(1) - 1.0) < 1e-12);
    assert(fabs(result3(2) - 2.0) < 1e-12);
    assert(fabs(result3(3) - 3.0) < 1e-12);
    
    // Test 2: Funcion lineal T1(x) = x, coeficientes [0, 1, 0]
    double Cx_linear[] = {0.0, 1.0, 0.0};
    double Cy_linear[] = {0.0, 2.0, 0.0};
    double Cz_linear[] = {0.0, 3.0, 0.0};
    
    // En t=0.5, tau = (2*0.5-0-1)/(1-0) = 0, deberia dar 0*coef = 0
    Matrix result_linear = Cheb3D(0.5, 3, 0.0, 1.0, Cx_linear, Cy_linear, Cz_linear);
    assert(fabs(result_linear(1) - 0.0) < 1e-12);
    assert(fabs(result_linear(2) - 0.0) < 1e-12);
    assert(fabs(result_linear(3) - 0.0) < 1e-12);
    
    // Test 3: Verificar excepciones para tiempo fuera de rango
    bool exception_thrown = false;
    try {
        Cheb3D(2.0, 3, 0.0, 1.0, Cx_const, Cy_const, Cz_const);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    exception_thrown = false;
    try {
        Cheb3D(-0.5, 3, 0.0, 1.0, Cx_const, Cy_const, Cz_const);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
}

REGISTER_TEST(test_Cheb3D);