#include <iostream>
#include <iomanip>
#include "../include/Matrix.h"
#include "../include/R_e.h"
#include "TestFramework.h"
#include <cmath>
#include <cassert>

//-------------------------------------------------------------
//  input:
//    angle       - angle of rotation [rad]
//
//  output:
//    rotmat      - vector result
//-------------------------------------------------------------


Matrix R_y(double alpha)
{
    Matrix rotmat(3,3);
    double C, S;
    
    C = std::cos(alpha);
    S = std::sin(alpha);
    // rotmat = zeros(3,3);
    
    rotmat(1,1) =   C;  rotmat(1,2) = 0.0;  rotmat(1,3) = -1.0*S;
    rotmat(2,1) = 0.0;  rotmat(2,2) = 1.0;  rotmat(2,3) =    0.0;
    rotmat(3,1) =   S;  rotmat(3,2) = 0.0;  rotmat(3,3) =      C;
    
    return rotmat;
}

void test_R_y()
{
    const double pi = M_PI;
    
    // Test 1: Rotacion cero debe ser matriz identidad
    Matrix I = R_y(0.0);
    assert(fabs(I(1,1) - 1.0) < 1e-15);
    assert(fabs(I(2,2) - 1.0) < 1e-15);
    assert(fabs(I(3,3) - 1.0) < 1e-15);
    
    // Test 2: Rotacion 90 grados
    Matrix R90 = R_y(pi/2);
    assert(fabs(R90(2,2) - 1.0) < 1e-15);  // Y no cambia
    assert(fabs(R90(1,1)) < 1e-15);        // cos(90°) = 0
    assert(fabs(R90(1,3) + 1.0) < 1e-15);  // -sin(90°) = -1
    assert(fabs(R90(3,1) - 1.0) < 1e-15);  // sin(90°) = 1
    assert(fabs(R90(3,3)) < 1e-15);        // cos(90°) = 0
    
    // Test 3: Rotacion 180 grados
    Matrix R180 = R_y(pi);
    assert(fabs(R180(2,2) - 1.0) < 1e-15); // Y no cambia
    assert(fabs(R180(1,1) + 1.0) < 1e-15); // cos(180°) = -1
    assert(fabs(R180(3,3) + 1.0) < 1e-15); // cos(180°) = -1
    
    // Test 4: Verificar que R_y no afecta componente Y
    Matrix v = Matrix(1.0, 2.0, 3.0);
    Matrix v_rot = R90 * v;
    // printf("Vector rotado:\n");
    // v_rot.print();
    assert(fabs(v_rot(2) - 2) < 1e-15);  // Y no cambia
    
    // Test 5: Determinante debe ser 1
    double det = R90.determinant();
    assert(fabs(det - 1.0) < 1e-15);
}

REGISTER_TEST(test_R_y);
