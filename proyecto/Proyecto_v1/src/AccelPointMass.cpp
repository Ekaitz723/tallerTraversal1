#include "AccelPointMass.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix AccelPointMass(const Matrix& r, const Matrix& s, double GM)
{
    Matrix d = r - s;
    // Matrix d_copia = d; // Copia para imprimir
    // printf("d: ");
    // d_copia.print();
    double norm_d = d.norm();
    // printf("norm_d: %f\n", norm_d);
    double norm_s = s.norm();
    // printf("norm_s: %f\n", norm_s);
    
    Matrix a = (d / (norm_d * norm_d * norm_d) + s / (norm_s * norm_s * norm_s)) * (-GM);
    return a;
}

void test_AccelPointMass()
{
    Matrix r(1000.0, 0.0, 0.0);
    Matrix s(0.0, 1.0, 0.0);
    double GM = 398600.4418;
    
    Matrix a = AccelPointMass(r, s, GM);
    assert(a(1) < 0);
    assert(fabs(a(2) + 398600) < 1);
    assert(fabs(a(3)) < 1e-10);
    
    double expected_mag = GM / (1000.0 * 1000.0);
    assert(fabs(fabs(a(1)) - expected_mag) < 1e-6);
    
    Matrix r2(2000.0, 0.0, 0.0);
    Matrix s2(1000.0, 0.0, 0.0);
    
    Matrix a2 = AccelPointMass(r2, s2, GM);
    assert(a2.norm() > 0);
    
    Matrix r3(0.0, 0.0, 0.0);
    Matrix s3(1000.0, 0.0, 0.0);
    
    Matrix a3 = AccelPointMass(r3, s3, GM);
    assert(fabs(a3(1)) < 1e-10);
    
    Matrix r4(1000.0, 1000.0, 1000.0);
    Matrix s4(500.0, 500.0, 500.0);
    
    Matrix a4 = AccelPointMass(r4, s4, GM);
    assert(a4.norm() > 0);
    assert(a4.isVector3D());
}

REGISTER_TEST(test_AccelPointMass);