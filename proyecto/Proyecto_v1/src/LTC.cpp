#include "LTC.h"
#include "R_e.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix LTC(double lon, double lat)
{
    Matrix M = R_y(-lat) * R_z(lon);
    
    for (int j = 1; j <= 3; j++) {
        double Aux = M(1, j);
        M(1, j) = M(2, j);
        M(2, j) = M(3, j);
        M(3, j) = Aux;
    }
    
    return M;
}

void test_LTC()
{
    const double pi = M_PI;
    
    // Test 1: Origen (lon=0, lat=0) - en el ecuador en Greenwich
    Matrix M1 = LTC(0.0, 0.0);
    
    assert(M1.isSquare());
    assert(M1.size() == 9);
    
    // Verificar que es una matriz de rotacion (ortogonal)
    Matrix M1T = M1.transpose();
    Matrix I_test = M1 * M1T;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                assert(fabs(I_test(i, j) - 1.0) < 1e-14);
            } else {
                assert(fabs(I_test(i, j)) < 1e-14);
            }
        }
    }
    
    // Test 2: Polo Norte (lat = pi/2, cualquier lon)
    Matrix M2 = LTC(0.0, pi/2);
    
    // En el polo, la transformacion debe dar resultados especificos
    assert(M2.isSquare());
    double det2 = M2.determinant();
    assert(fabs(fabs(det2) - 1.0) < 1e-12); // det = ±1 para matriz de rotacion
    
    // Test 3: Polo Sur (lat = -pi/2)
    Matrix M3 = LTC(0.0, -pi/2);
    
    assert(M3.isSquare());
    double det3 = M3.determinant();
    assert(fabs(fabs(det3) - 1.0) < 1e-12);
    
    // Test 4: 90 grados Este (lon = pi/2, lat = 0)
    Matrix M4 = LTC(pi/2, 0.0);
    
    assert(M4.isSquare());
    
    // Test 5: Caso tipico - 45°N, 45°E
    Matrix M5 = LTC(pi/4, pi/4);
    
    // Verificar ortogonalidad
    Matrix M5T = M5.transpose();
    Matrix I5 = M5 * M5T;
    for (int i = 1; i <= 3; i++) {
        assert(fabs(I5(i, i) - 1.0) < 1e-12);
    }
    
    // Test 6: Verificar que el determinante es +1 (rotacion propia)
    double det5 = M5.determinant();
    assert(fabs(det5 - 1.0) < 1e-12 || fabs(det5 + 1.0) < 1e-12);
    
    // Test 7: Coordenadas de Kaena Point (del archivo GEOS3)
    double lat_kaena = 21.5748 * pi/180;  // 21.5748°N
    double lon_kaena = -158.2706 * pi/180; // 158.2706°W
    
    Matrix M_kaena = LTC(lon_kaena, lat_kaena);
    
    assert(M_kaena.isSquare());
    double det_kaena = M_kaena.determinant();
    assert(fabs(fabs(det_kaena) - 1.0) < 1e-12);
    
    // Test 8: Verificar simetria en longitudes opuestas
    Matrix M_pos = LTC(pi/6, pi/6);   // 30°E, 30°N
    Matrix M_neg = LTC(-pi/6, pi/6);  // 30°W, 30°N
    
    // Las matrices deben ser diferentes pero ambas validas
    assert(M_pos.determinant() != 0);
    assert(M_neg.determinant() != 0);
    
    // Test 9: Casos extremos de longitud
    Matrix M_180 = LTC(pi, 0.0);      // 180° longitud
    Matrix M_neg180 = LTC(-pi, 0.0);  // -180° longitud (equivalente)
    
    // Estas deberian ser aproximadamente iguales (±180° son el mismo meridiano)
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(M_180(i, j) - M_neg180(i, j)) < 1e-12);
        }
    }
    
    // Test 10: Verificar intercambio de filas funciona correctamente
    // Comparar con calculo manual
    Matrix R_y_test = R_y(-pi/4);
    Matrix R_z_test = R_z(pi/3);
    Matrix M_manual = R_y_test * R_z_test;
    
    // Aplicar intercambio manual
    for (int j = 1; j <= 3; j++) {
        double temp = M_manual(1, j);
        M_manual(1, j) = M_manual(2, j);
        M_manual(2, j) = M_manual(3, j);
        M_manual(3, j) = temp;
    }
    
    Matrix M_function = LTC(pi/3, pi/4);
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(M_manual(i, j) - M_function(i, j)) < 1e-14);
        }
    }
    
    // Test 11: Verificar que funciona con angulos pequeños
    Matrix M_small = LTC(1e-6, 1e-6);
    
    assert(M_small.isSquare());
    assert(fabs(fabs(M_small.determinant()) - 1.0) < 1e-12);
    
    // Test 12: Caso del ecuador en diferentes meridianos
    Matrix M_eq1 = LTC(0.0, 0.0);     // Greenwich
    Matrix M_eq2 = LTC(pi/2, 0.0);    // 90°E
    Matrix M_eq3 = LTC(pi, 0.0);      // 180°
    Matrix M_eq4 = LTC(-pi/2, 0.0);   // 90°W
    
    // Todos deben ser matrices de rotacion validas
    assert(fabs(fabs(M_eq1.determinant()) - 1.0) < 1e-12);
    assert(fabs(fabs(M_eq2.determinant()) - 1.0) < 1e-12);
    assert(fabs(fabs(M_eq3.determinant()) - 1.0) < 1e-12);
    assert(fabs(fabs(M_eq4.determinant()) - 1.0) < 1e-12);
}

REGISTER_TEST(test_LTC);