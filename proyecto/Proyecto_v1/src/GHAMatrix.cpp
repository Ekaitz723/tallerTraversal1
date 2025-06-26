#include "GHAMatrix.h"
#include "R_e.h"
#include "gast.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix GHAMatrix(double Mjd_UT1)
{
    return R_z(gast(Mjd_UT1));
}

void test_GHAMatrix()
{
    const double pi = M_PI;
    
    // Test 1: J2000.0 epoca (MJD 51544.5 UT1)
    Matrix GHA_j2000 = GHAMatrix(51544.5);
    
    // Verificar que es matriz 3x3
    assert(GHA_j2000.isSquare());
    assert(GHA_j2000.size() == 9);
    
    // Test 2: Verificar que es matriz de rotacion (ortogonal)
    Matrix GHA_T = GHA_j2000.transpose();
    Matrix I_test = GHA_j2000 * GHA_T;
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
    double det_j2000 = GHA_j2000.determinant();
    assert(fabs(det_j2000 - 1.0) < 1e-12);
    
    // Test 4: Epoca diferente - 12 horas despues
    Matrix GHA_12h = GHAMatrix(51545.0);  // 12 horas despues
    
    // Matrices deben ser diferentes (Earth rota)
    bool different = false;
    for (int i = 1; i <= 3 && !different; i++) {
        for (int j = 1; j <= 3; j++) {
            if (fabs(GHA_j2000(i, j) - GHA_12h(i, j)) > 1e-12) {
                different = true;
                break;
            }
        }
    }
    assert(different);
    
    // Test 5: Un dia despues - rotacion completa mas un poco
    Matrix GHA_1day = GHAMatrix(51545.5);
    
    assert(fabs(GHA_1day.determinant() - 1.0) < 1e-12);
    
    // Test 6: Epoca historica - 1980
    Matrix GHA_1980 = GHAMatrix(44239.0);   // 1 enero 1980
    
    assert(GHA_1980.isSquare());
    assert(fabs(GHA_1980.determinant() - 1.0) < 1e-12);
    
    // Test 7: Epoca futura - 2050  
    Matrix GHA_2050 = GHAMatrix(69807.0);   // ~1 enero 2050
    
    assert(fabs(GHA_2050.determinant() - 1.0) < 1e-12);
    
    // Test 8: Verificar continuidad temporal
    Matrix GHA_close = GHAMatrix(51544.5 + 1.0/86400.0);  // 1 segundo despues
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(GHA_j2000(i, j) - GHA_close(i, j)) < 1e-4);
        }
    }
    
    // Test 9: Verificar que transpuesta = inversa (propiedad ortogonal)
    Matrix GHA_test = GHAMatrix(52000.0);
    Matrix GHA_test_T = GHA_test.transpose();
    Matrix GHA_test_inv = GHA_test.inverse();
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(GHA_test_T(i, j) - GHA_test_inv(i, j)) < 1e-12);
        }
    }
    
    // Test 10: Matriz debe rotar aproximadamente 2π en ~1 dia sideral
    double sidereal_day = 0.9972696;  // dias
    Matrix GHA_sideral = GHAMatrix(51544.5 + sidereal_day);
    
    // Despues de 1 dia sideral, la matriz debe estar muy cerca de la original
    double diff_total = 0.0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            diff_total += fabs(GHA_j2000(i, j) - GHA_sideral(i, j));
        }
    }
    assert(diff_total < 0.01);  // Muy similar tras 1 dia sideral
    
    // Test 11: Casos extremos temporales
    Matrix GHA_past = GHAMatrix(20000.0);    // Muy en el pasado
    Matrix GHA_future = GHAMatrix(80000.0);  // Muy en el futuro
    
    assert(fabs(GHA_past.determinant() - 1.0) < 1e-12);
    assert(fabs(GHA_future.determinant() - 1.0) < 1e-12);
    
    // Test 12: Verificar que elementos estan en rangos razonables
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(GHA_j2000(i, j)) <= 1.0);  // Elementos de matriz rotacion
            assert(!std::isnan(GHA_j2000(i, j)));
            assert(!std::isinf(GHA_j2000(i, j)));
        }
    }
    
    // Test 13: Diferentes momentos del mismo dia
    Matrix GHA_6h = GHAMatrix(51544.25);   // 6:00 UT
    Matrix GHA_18h = GHAMatrix(51544.75);  // 18:00 UT
    
    // 12 horas = π radianes de rotacion aprox
    assert(fabs(GHA_6h.determinant() - 1.0) < 1e-12);
    assert(fabs(GHA_18h.determinant() - 1.0) < 1e-12);
    
    // Matrices deben ser notablemente diferentes
    different = false;
    for (int i = 1; i <= 3 && !different; i++) {
        for (int j = 1; j <= 3; j++) {
            if (fabs(GHA_6h(i, j) - GHA_18h(i, j)) > 0.1) {
                different = true;
                break;
            }
        }
    }
    assert(different);
}

REGISTER_TEST(test_GHAMatrix);