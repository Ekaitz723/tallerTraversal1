#include "NutMatrix.h"
#include "MeanObliquity.h"
#include "NutAngles.h"
#include "R_e.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix NutMatrix(double Mjd_TT)
{
    // Mean obliquity of the ecliptic
    double eps = MeanObliquity(Mjd_TT);
    
    // Nutation in longitude and obliquity
    double dpsi, deps;
    NutAngles(Mjd_TT, dpsi, deps);
    
    Matrix NutMat = R_x(-eps - deps) * R_z(-dpsi) * R_x(eps);
    return NutMat;
}

void test_NutMatrix()
{
    // Test 1: J2000.0 epoch (MJD 51544.5)
    Matrix nut_j2000 = NutMatrix(51544.5);
    
    // Verificar que es una matriz 3x3
    assert(nut_j2000.isSquare());
    assert(nut_j2000.size() == 9);
    
    // Test 2: Verificar que es una matriz de rotacion (ortogonal)
    Matrix nut_T = nut_j2000.transpose();
    Matrix I_test = nut_j2000 * nut_T;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                assert(fabs(I_test(i, j) - 1.0) < 1e-12);
            } else {
                assert(fabs(I_test(i, j)) < 1e-12);
            }
        }
    }
    
    // Test 3: Determinante debe ser +1 (rotacion propia)
    double det_j2000 = nut_j2000.determinant();
    assert(fabs(det_j2000 - 1.0) < 1e-12);
    
    // Test 4: Epoca diferente - 2020
    Matrix nut_2020 = NutMatrix(58849.0);  // ~1 enero 2020
    
    assert(nut_2020.isSquare());
    double det_2020 = nut_2020.determinant();
    assert(fabs(det_2020 - 1.0) < 1e-12);
    
    // Test 5: Las matrices deben ser diferentes para epocas diferentes
    bool different = false;
    for (int i = 1; i <= 3 && !different; i++) {
        for (int j = 1; j <= 3; j++) {
            if (fabs(nut_j2000(i, j) - nut_2020(i, j)) > 1e-12) {
                different = true;
                break;
            }
        }
    }
    assert(different);
    
    // Test 6: Matriz debe estar cerca de identidad (nutacion es pequeña)
    Matrix I = Matrix::eye(3);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(nut_j2000(i, j) - I(i, j)) < 1e-3);  // Diferencias pequeñas
        }
    }
    
    // Test 7: Elementos diagonales cerca de 1
    assert(fabs(nut_j2000(1, 1) - 1.0) < 1e-4);
    assert(fabs(nut_j2000(2, 2) - 1.0) < 1e-4);
    assert(fabs(nut_j2000(3, 3) - 1.0) < 1e-4);
    
    // Test 8: Casos historicos
    Matrix nut_1980 = NutMatrix(44239.0);   // 1980
    Matrix nut_2050 = NutMatrix(69807.0);   // 2050
    
    assert(fabs(nut_1980.determinant() - 1.0) < 1e-12);
    assert(fabs(nut_2050.determinant() - 1.0) < 1e-12);
    
    // Test 9: Verificar continuidad temporal
    Matrix nut_close = NutMatrix(51544.5001);  // Un dia despues
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(nut_j2000(i, j) - nut_close(i, j)) < 1e-6);
        }
    }
    
    // Test 10: Caso extremo temporal
    Matrix nut_future = NutMatrix(100000.0);
    assert(fabs(nut_future.determinant() - 1.0) < 1e-12);
    
    // Test 11: Verificar que es invertible
    Matrix nut_inv = nut_j2000.inverse();
    Matrix should_be_I = nut_j2000 * nut_inv;
    for (int i = 1; i <= 3; i++) {
        assert(fabs(should_be_I(i, i) - 1.0) < 1e-12);
    }
    
    // Test 12: Verificar comportamiento con T negativo
    Matrix nut_past = NutMatrix(30000.0);  // Epoca muy anterior a J2000
    assert(fabs(nut_past.determinant() - 1.0) < 1e-12);
    assert(nut_past.isSquare());
    
    // Test 13: Matriz transpuesta debe ser igual a la inversa
    Matrix nut_test = NutMatrix(52000.0);
    Matrix nut_test_T = nut_test.transpose();
    Matrix nut_test_inv = nut_test.inverse();
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(nut_test_T(i, j) - nut_test_inv(i, j)) < 1e-12);
        }
    }
}

REGISTER_TEST(test_NutMatrix);