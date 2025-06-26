#include "AccelHarmonic.h"
#include "Legendre.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix* Cnm = nullptr;
Matrix* Snm = nullptr;

Matrix AccelHarmonic(const Matrix& r, const Matrix& E, int n_max, int m_max)
{
    double r_ref = 6378.1363e3;   // Earth's radius [m]; GGM03S
    double gm = 398600.4415e9;    // [m^3/s^2]; GGM03S
    
    // Body-fixed position 
    Matrix r_bf = E * r;
    
    // Auxiliary quantities
    double d = r_bf.norm();                        // distance
    double latgc = asin(r_bf(3) / d);
    double lon = atan2(r_bf(2), r_bf(1));
    
    Matrix* pnm = nullptr;
    Matrix* dpnm = nullptr;
    Legendre(n_max, m_max, latgc, pnm, dpnm);
    
    double dUdr = 0.0;
    double dUdlatgc = 0.0;
    double dUdlon = 0.0;
    double q3 = 0.0, q2 = 0.0, q1 = 0.0;
    
    for (int n = 0; n <= n_max; n++) {
        double b1 = (-gm / (d * d)) * pow(r_ref / d, n) * (n + 1);
        double b2 = (gm / d) * pow(r_ref / d, n);
        double b3 = (gm / d) * pow(r_ref / d, n);
        
        for (int m = 0; m <= m_max; m++) {
            if (m <= n) {
                q1 = q1 + (*pnm)(n+1, m+1) * ((*Cnm)(n+1, m+1) * cos(m * lon) + (*Snm)(n+1, m+1) * sin(m * lon));
                q2 = q2 + (*dpnm)(n+1, m+1) * ((*Cnm)(n+1, m+1) * cos(m * lon) + (*Snm)(n+1, m+1) * sin(m * lon));
                q3 = q3 + m * (*pnm)(n+1, m+1) * ((*Snm)(n+1, m+1) * cos(m * lon) - (*Cnm)(n+1, m+1) * sin(m * lon));
            }
        }
        
        dUdr = dUdr + q1 * b1;
        dUdlatgc = dUdlatgc + q2 * b2;
        dUdlon = dUdlon + q3 * b3;
        q3 = 0.0; q2 = 0.0; q1 = 0.0;
    }
    
    // Body-fixed acceleration
    double r2xy = r_bf(1) * r_bf(1) + r_bf(2) * r_bf(2);
    
    double ax = (1.0/d * dUdr - r_bf(3)/(d*d*sqrt(r2xy)) * dUdlatgc) * r_bf(1) - (1.0/r2xy * dUdlon) * r_bf(2);
    double ay = (1.0/d * dUdr - r_bf(3)/(d*d*sqrt(r2xy)) * dUdlatgc) * r_bf(2) + (1.0/r2xy * dUdlon) * r_bf(1);
    double az = 1.0/d * dUdr * r_bf(3) + sqrt(r2xy)/(d*d) * dUdlatgc;
    
    Matrix a_bf(3, 1);
    a_bf(1) = ax;
    a_bf(2) = ay;
    a_bf(3) = az;
    
    // Inertial acceleration 
    Matrix a = E.transpose() * a_bf;
    
    delete pnm;
    delete dpnm;
    
    return a;
}

void test_AccelHarmonic()
{
    Cnm = new Matrix(4, 4);
    Snm = new Matrix(4, 4);
    
    // Coeficientes tipicos de gravedad terrestre
    (*Cnm)(1,1) = 1.0;           // C00 = 1 (termino central)
    (*Cnm)(3,1) = -1082.63e-6;   // C20 = -J2 (achatamiento terrestre)
    (*Cnm)(4,1) = 2.54e-6;       // C30
    (*Cnm)(4,3) = 1.62e-6;       // C22
    
    // Test 1: Caso simple con solo termino central (n_max=0, m_max=0)
    Matrix r1(7000.0e3, 0.0, 0.0);  // 7000 km en X
    Matrix E1 = Matrix::eye(3);      // Sin rotacion
    
    Matrix a1 = AccelHarmonic(r1, E1, 0, 0);
    
    assert(a1.isVector3D());
    assert(a1(1) < 0);  // Aceleracion hacia el centro (negativa en X)
    assert(fabs(a1(2)) < 1e-10);  // Y debe ser ~0
    assert(fabs(a1(3)) < 1e-10);  // Z debe ser ~0
    
    double mag_esperada = 398600.4415e9 / (7000.0e3 * 7000.0e3);  // GM/r²
    assert(fabs(fabs(a1(1)) - mag_esperada) < mag_esperada * 0.01);  // 1% tolerancia
    
    // Test 2: Con termino J2 (n_max=2, m_max=0)
    Matrix a2 = AccelHarmonic(r1, E1, 2, 0);
    
    assert(a2.isVector3D());
    assert(fabs(a2(1)) > fabs(a1(1)));  // J2 aumenta magnitud en ecuador
    
    // Test 3: Posicion cerca del polo (evitar division por cero exacta)
    Matrix r3(100.0, 0.0, 7000.0e3);  // Ligeramente fuera del polo
    Matrix a3 = AccelHarmonic(r3, E1, 2, 0);
    
    assert(a3(3) < 0);  // Aceleracion hacia el centro
    assert(fabs(a3(1)) < 1e-3);  // X debe ser pequeño
    assert(fabs(a3(2)) < 1e-6);  // Y debe ser ~0
    
    // Test 4: Con matriz de transformacion rotada
    Matrix E4 = Matrix::eye(3);
    // Rotacion simple de 90° en Z
    E4(1,1) = 0.0; E4(1,2) = 1.0;
    E4(2,1) = -1.0; E4(2,2) = 0.0;
    
    Matrix r4(0.0, 7000.0e3, 0.0);  // Posicion en Y
    Matrix a4 = AccelHarmonic(r4, E4, 1, 0);
    
    assert(a4.isVector3D());
    assert(a4(2) < 0);  // Aceleracion hacia centro en Y
    
    // Test 5: Verificar que magnitud disminuye con distancia
    Matrix r5(14000.0e3, 0.0, 0.0);  // Doble distancia
    Matrix a5 = AccelHarmonic(r5, E1, 0, 0);
    
    // Aceleracion debe ser aprox. 1/4 (ley cuadratica inversa)
    assert(fabs(a5(1)) < fabs(a1(1)) / 3.0);  // Menor que 1/3 de original
    
    // Test 6: Caso LEO tipico (400 km altitud)
    Matrix r6(6778.137e3, 0.0, 0.0);  // Radio tierra + 400km
    Matrix a6 = AccelHarmonic(r6, E1, 2, 2);
    
    double mag_leo = a6.norm();
    assert(mag_leo > 8.0 && mag_leo < 10.0);  // ~9 m/s² en LEO
    
    // Test 7: Con n_max > m_max (caso tipico)
    Matrix a7 = AccelHarmonic(r1, E1, 3, 2);
    assert(a7.isVector3D());
    assert(a7.norm() > 0);
    
    // Test 8: Comparar con y sin J2 en ecuador vs polo
    Matrix r_ecuador(6378.137e3, 0.0, 0.0);
    Matrix r_polo(0.0, 0.0, 6356.752e3);  // Radio polar
    
    Matrix a_ecuador_J0 = AccelHarmonic(r_ecuador, E1, 0, 0);
    Matrix a_ecuador_J2 = AccelHarmonic(r_ecuador, E1, 2, 0);
    Matrix a_polo_J0 = AccelHarmonic(r_polo, E1, 0, 0);
    Matrix a_polo_J2 = AccelHarmonic(r_polo, E1, 2, 0);
    
    // J2 tiene efectos diferentes en ecuador vs polo
    double diff_ecuador = fabs(a_ecuador_J2.norm() - a_ecuador_J0.norm());
    double diff_polo = fabs(a_polo_J2.norm() - a_polo_J0.norm());
    assert(diff_ecuador != diff_polo);
    
    // Cleanup
    delete Cnm; delete Snm;
}

REGISTER_TEST(test_AccelHarmonic);