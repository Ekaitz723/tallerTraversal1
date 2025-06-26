#include "PrecMatrix.h"
#include "R_e.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix PrecMatrix(double Mjd_1, double Mjd_2)
{
    double T = (Mjd_1 - MJD_J2000) / 36525.0;
    double dT = (Mjd_2 - Mjd_1) / 36525.0;
    
    // Precession angles
    double zeta = ((2306.2181 + (1.39656 - 0.000139*T)*T) + 
                   ((0.30188 - 0.000344*T) + 0.017998*dT)*dT) * dT / Arcs;
    
    double z = zeta + ((0.79280 + 0.000411*T) + 0.000205*dT) * dT * dT / Arcs;
    
    double theta = ((2004.3109 - (0.85330 + 0.000217*T)*T) - 
                    ((0.42665 + 0.000217*T) + 0.041833*dT)*dT) * dT / Arcs;
    
    // Precession matrix
    Matrix PrecMat = R_z(-z) * R_y(theta) * R_z(-zeta);
    
    return PrecMat;
}

void test_PrecMatrix()
{
    // Test 1: Mismo epoch - debe dar matriz identidad
    Matrix P_same = PrecMatrix(51544.5, 51544.5);  // J2000.0 a J2000.0
    Matrix I = Matrix::eye(3);
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(P_same(i,j) - I(i,j)) < 1e-14);
        }
    }
    
    // Test 2: J2000.0 a 50 años despues (epoca tipica)
    double Mjd_J2000 = 51544.5;
    double Mjd_50years = Mjd_J2000 + 50*365.25;  // ~50 años
    Matrix P_50y = PrecMatrix(Mjd_J2000, Mjd_50years);
    
    // Debe ser matriz ortogonal
    assert(fabs(P_50y.determinant() - 1.0) < 1e-12);
    
    // Test 3: Verificar ortogonalidad (P * P^T = I)
    Matrix P_T = P_50y.transpose();
    Matrix should_be_I = P_50y * P_T;
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                assert(fabs(should_be_I(i,j) - 1.0) < 1e-12);
            } else {
                assert(fabs(should_be_I(i,j)) < 1e-12);
            }
        }
    }
    
    // Test 4: Precesion 1 siglo (cambios mas notables)
    double Mjd_1century = Mjd_J2000 + 100*365.25;
    Matrix P_100y = PrecMatrix(Mjd_J2000, Mjd_1century);
    
    assert(P_100y.isSquare());
    assert(fabs(P_100y.determinant() - 1.0) < 1e-12);
    
    // Los elementos deben diferir notablemente de la identidad
    bool different_from_identity = false;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (fabs(P_100y(i,j) - I(i,j)) > 1e-6) {
                different_from_identity = true;
                break;
            }
        }
    }
    assert(different_from_identity);
    
    // Test 5: Precesion hacia el pasado
    double Mjd_past = Mjd_J2000 - 50*365.25;
    Matrix P_past = PrecMatrix(Mjd_J2000, Mjd_past);
    
    assert(fabs(P_past.determinant() - 1.0) < 1e-12);
    
    // Test 6: Simetria - precesion ida y vuelta
    Matrix P_forward = PrecMatrix(Mjd_J2000, Mjd_50years);
    Matrix P_backward = PrecMatrix(Mjd_50years, Mjd_J2000);
    Matrix product = P_forward * P_backward;
    
    // Debe dar aproximadamente identidad
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                assert(fabs(product(i,j) - 1.0) < 1e-12);
            } else {
                assert(fabs(product(i,j)) < 1e-12);
            }
        }
    }
    
    // Test 7: Casos historicos - 1950.0 a J2000.0
    double Mjd_B1950 = 33282.0;  // MJD para 1950.0
    Matrix P_1950_2000 = PrecMatrix(Mjd_B1950, Mjd_J2000);
    
    assert(fabs(P_1950_2000.determinant() - 1.0) < 1e-12);
    
    // Test 8: Verificar que pequenos intervalos dan cambios pequeños
    Matrix P_small = PrecMatrix(Mjd_J2000, Mjd_J2000 + 1.0);  // 1 dia
    
    // Debe estar muy cerca de la identidad
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(P_small(i,j) - I(i,j)) < 1e-6);
        }
    }
    
    // Test 9: Epoca futura lejana
    double Mjd_future = Mjd_J2000 + 1000*365.25;  // 1000 años
    Matrix P_future = PrecMatrix(Mjd_J2000, Mjd_future);
    
    assert(fabs(P_future.determinant() - 1.0) < 1e-12);
    assert(P_future.isSquare());
    
    // Test 10: Verificar que la matriz es invertible
    Matrix P_test = PrecMatrix(51544.5, 52910.0);  // ~1 año
    Matrix P_inv = P_test.inverse();
    Matrix check_I = P_test * P_inv;
    
    for (int i = 1; i <= 3; i++) {
        assert(fabs(check_I(i,i) - 1.0) < 1e-12);
    }
    
    // Test 11: Diferente orden de epocas
    Matrix P_order1 = PrecMatrix(51544.5, 52544.5);
    Matrix P_order2 = PrecMatrix(52544.5, 51544.5);
    
    // P_order2 debe ser aproximadamente P_order1^T
    Matrix P1_T = P_order1.transpose();
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(P_order2(i,j) - P1_T(i,j)) < 1e-12);
        }
    }
}

REGISTER_TEST(test_PrecMatrix);