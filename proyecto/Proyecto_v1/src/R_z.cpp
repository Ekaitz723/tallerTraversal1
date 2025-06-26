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


Matrix R_z(double alpha)
{
    Matrix rotmat(3,3);
    double C, S;
    
    C = std::cos(alpha);
    S = std::sin(alpha);
    // rotmat = zeros(3,3);
    
    rotmat(1,1) =      C;  rotmat(1,2) =   S;  rotmat(1,3) = 0.0;
    rotmat(2,1) = -1.0*S;  rotmat(2,2) =   C;  rotmat(2,3) = 0.0;
    rotmat(3,1) =    0.0;  rotmat(3,2) = 0.0;  rotmat(3,3) = 1.0;
    
    return rotmat;
}

void test_R_z()
{
    const double pi = M_PI;
    
    // Test 1: Rotacion cero debe ser matriz identidad
    Matrix I = R_z(0.0);
    assert(fabs(I(1,1) - 1.0) < 1e-15);
    assert(fabs(I(2,2) - 1.0) < 1e-15);
    assert(fabs(I(3,3) - 1.0) < 1e-15);
    
    // Test 2: Rotacion 90 grados
    Matrix R90 = R_z(pi/2);
    assert(fabs(R90(3,3) - 1.0) < 1e-15);  // Z no cambia
    assert(fabs(R90(1,1)) < 1e-15);        // cos(90°) = 0
    assert(fabs(R90(1,2) - 1.0) < 1e-15);  // sin(90°) = 1
    assert(fabs(R90(2,1) + 1.0) < 1e-15);  // -sin(90°) = -1
    assert(fabs(R90(2,2)) < 1e-15);        // cos(90°) = 0
    
    // Test 3: Rotacion 180 grados
    Matrix R180 = R_z(pi);
    assert(fabs(R180(3,3) - 1.0) < 1e-15); // Z no cambia
    assert(fabs(R180(1,1) + 1.0) < 1e-15); // cos(180°) = -1
    assert(fabs(R180(2,2) + 1.0) < 1e-15); // cos(180°) = -1
    
    // Test 4: Verificar que R_z no afecta componente Z
    Matrix v = Matrix(1.0, 2.0, 3.0);
    Matrix v_rot = R90 * v;
    // printf("Vector rotado z:\n");
    // v_rot.print();
    assert(fabs(v_rot(3) - 3.0) < 1e-15);  // Z no cambia
    
    // Test 5: Determinante debe ser 1
    double det = R90.determinant();
    assert(fabs(det - 1.0) < 1e-15);
    
    // Test 6: Caso conocido - rotar vector (1,0,0) 90° debe dar (0,-1,0)
    Matrix vec_x = Matrix(1.0, 0.0, 0.0);
    Matrix result = R90 * vec_x;
    // printf("Vector rotado:\n");
    // result.print();
    assert(fabs(result(1)) < 1e-15);
    assert(fabs(result(2) + 1.0) < 1e-15);
    assert(fabs(result(3)) < 1e-15);
}

REGISTER_TEST(test_R_z);
