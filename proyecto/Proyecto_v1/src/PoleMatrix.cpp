#include "PoleMatrix.h"
#include "R_e.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix PoleMatrix(double xp, double yp)
{
    Matrix PoleMat = R_y(-xp) * R_x(-yp);
    return PoleMat;
}

void test_PoleMatrix()
{
    const double pi = M_PI;
    const double arcsec_to_rad = pi / (180.0 * 3600.0);  // Conversion arcsec to rad
    
    // Test 1: Caso ideal (xp=0, yp=0) -> debe dar matriz identidad
    Matrix I_test = PoleMatrix(0.0, 0.0);
    Matrix I_expected = Matrix::eye(3);
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(I_test(i, j) - I_expected(i, j)) < 1e-15);
        }
    }
    
    // Test 2: Valores típicos pequeños (coordenadas polares reales)
    double xp_typical = 0.035 * arcsec_to_rad;  // ~0.035 arcsec
    double yp_typical = 0.32 * arcsec_to_rad;   // ~0.32 arcsec
    
    Matrix P_typical = PoleMatrix(xp_typical, yp_typical);
    
    // Debe ser muy cercana a la identidad (coordenadas polares son pequeñas)
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                assert(fabs(P_typical(i, j) - 1.0) < 1e-5);  // Diagonal ~1
            } else {
                assert(fabs(P_typical(i, j)) < 1e-5);        // Off-diagonal ~0
            }
        }
    }
    
    // Test 3: Verificar que es matriz ortogonal (det = 1)
    double det_typical = P_typical.determinant();
    assert(fabs(det_typical - 1.0) < 1e-12);
    
    // Test 4: Verificar que transpuesta = inversa (propiedad ortogonal)
    Matrix P_T = P_typical.transpose();
    Matrix P_inv = P_typical.inverse();
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(P_T(i, j) - P_inv(i, j)) < 1e-12);
        }
    }
    
    // Test 5: Verificar ortogonalidad (P * P' = I)
    Matrix I_check = P_typical * P_T;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                assert(fabs(I_check(i, j) - 1.0) < 1e-12);
            } else {
                assert(fabs(I_check(i, j)) < 1e-12);
            }
        }
    }
    
    // Test 6: Caso con xp≠0, yp=0
    double xp_only = 0.1 * arcsec_to_rad;
    Matrix P_x_only = PoleMatrix(xp_only, 0.0);
    
    assert(fabs(P_x_only.determinant() - 1.0) < 1e-12);
    assert(P_x_only.isSquare());
    
    // Test 7: Caso con xp=0, yp≠0  
    double yp_only = 0.2 * arcsec_to_rad;
    Matrix P_y_only = PoleMatrix(0.0, yp_only);
    
    assert(fabs(P_y_only.determinant() - 1.0) < 1e-12);
    assert(P_y_only.isSquare());
    
    // Test 8: Valores extremos pero realistas (±1 arcsec)
    double xp_max = 1.0 * arcsec_to_rad;
    double yp_max = 1.0 * arcsec_to_rad;
    
    Matrix P_max = PoleMatrix(xp_max, yp_max);
    Matrix P_min = PoleMatrix(-xp_max, -yp_max);
    
    assert(fabs(P_max.determinant() - 1.0) < 1e-12);
    assert(fabs(P_min.determinant() - 1.0) < 1e-12);
    
    // Test 9: Comprobar que matrices diferentes dan resultados diferentes
    Matrix P1 = PoleMatrix(0.1 * arcsec_to_rad, 0.2 * arcsec_to_rad);
    Matrix P2 = PoleMatrix(0.3 * arcsec_to_rad, 0.4 * arcsec_to_rad);
    
    bool different = false;
    for (int i = 1; i <= 3 && !different; i++) {
        for (int j = 1; j <= 3; j++) {
            if (fabs(P1(i, j) - P2(i, j)) > 1e-15) {
                different = true;
                break;
            }
        }
    }
    assert(different);
    
    // Test 10: Verificar simetría en signos
    Matrix P_pos = PoleMatrix(xp_typical, yp_typical);
    Matrix P_neg = PoleMatrix(-xp_typical, -yp_typical);
    
    // P(-x,-y) deberia ser diferente de P(x,y)
    different = false;
    for (int i = 1; i <= 3 && !different; i++) {
        for (int j = 1; j <= 3; j++) {
            if (fabs(P_pos(i, j) - P_neg(i, j)) > 1e-12) {
                different = true;
                break;
            }
        }
    }
    assert(different);
    
    // Test 11: Caso basado en datos IERS reales (enero 2020)
    double xp_iers = 0.035312 * arcsec_to_rad;  // Del test IERS
    double yp_iers = 0.320328 * arcsec_to_rad;
    
    Matrix P_iers = PoleMatrix(xp_iers, yp_iers);
    
    assert(fabs(P_iers.determinant() - 1.0) < 1e-12);
    assert(P_iers.isSquare());
    
    // Debe estar muy cerca de la identidad
    for (int i = 1; i <= 3; i++) {
        assert(fabs(P_iers(i, i) - 1.0) < 1e-5);
    }
    
    // Test 12: Verificar que la matriz es invertible
    Matrix P_test = PoleMatrix(0.05 * arcsec_to_rad, 0.15 * arcsec_to_rad);
    Matrix P_inv_test = P_test.inverse();
    Matrix I_final = P_test * P_inv_test;
    
    for (int i = 1; i <= 3; i++) {
        assert(fabs(I_final(i, i) - 1.0) < 1e-12);
    }
}

REGISTER_TEST(test_PoleMatrix);