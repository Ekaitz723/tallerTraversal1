#include "Legendre.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void Legendre(int n, int m, double fi, Matrix*& pnm, Matrix*& dpnm)
{
    pnm = new Matrix(n+1, m+1);
    dpnm = new Matrix(n+1, m+1);
    
    (*pnm)(1,1) = 1.0;
    (*dpnm)(1,1) = 0.0;
    if (n >= 1 && m >= 1) {
        (*pnm)(2,2) = sqrt(3.0) * cos(fi);
        (*dpnm)(2,2) = -sqrt(3.0) * sin(fi);
    }
    
    // Diagonal coefficients
    for (int i = 2; i <= n; i++) {
        if (i+1 <= n+1 && i+1 <= m+1) {
            (*pnm)(i+1, i+1) = sqrt((2.0*i+1)/(2.0*i)) * cos(fi) * (*pnm)(i, i);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (i+1 <= n+1 && i+1 <= m+1) {
            (*dpnm)(i+1, i+1) = sqrt((2.0*i+1)/(2.0*i)) * ((cos(fi)*(*dpnm)(i, i)) - 
                               (sin(fi)*(*pnm)(i, i)));
        }
    }
    
    // Horizontal first step coefficients
    for (int i = 1; i <= n; i++) {
        if (i+1 <= n+1 && i <= m+1) {
            (*pnm)(i+1, i) = sqrt(2.0*i+1) * sin(fi) * (*pnm)(i, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i+1 <= n+1 && i <= m+1) {
            (*dpnm)(i+1, i) = sqrt(2.0*i+1) * ((cos(fi)*(*pnm)(i, i)) + (sin(fi)*(*dpnm)(i, i)));
        }
    }
    
    // Horizontal second step coefficients
    int j = 0;
    int k = 2;
    while (j <= m) {
        for (int i = k; i <= n; i++) {
            if (i+1 <= n+1 && j+1 <= m+1 && i-1 >= 1 && j+1 <= m+1) {
                double term1 = sqrt(2.0*i-1) * sin(fi) * (*pnm)(i, j+1);
                double term2 = 0.0;
                if (i-1 >= 1 && j+1 <= m+1 && (i+j-1) > 0 && (i-j-1) > 0 && (2*i-3) > 0) {
                    term2 = sqrt(((i+j-1)*(i-j-1))/(2.0*i-3)) * (*pnm)(i-1, j+1);
                }
                (*pnm)(i+1, j+1) = sqrt((2.0*i+1)/((i-j)*(i+j))) * (term1 - term2);
            }
        }
        j = j + 1;
        k = k + 1;
        if (j > m) {
            break;
        }
    }
    
    j = 0;
    k = 2;
    while (j <= m) {
        for (int i = k; i <= n; i++) {
            if (i+1 <= n+1 && j+1 <= m+1 && i-1 >= 1) {
                double term1 = sqrt(2.0*i-1) * sin(fi) * (*dpnm)(i, j+1);
                double term2 = sqrt(2.0*i-1) * cos(fi) * (*pnm)(i, j+1);
                double term3 = 0.0;
                if (i-1 >= 1 && j+1 <= m+1 && (i+j-1) > 0 && (i-j-1) > 0 && (2*i-3) > 0) {
                    term3 = sqrt(((i+j-1)*(i-j-1))/(2.0*i-3)) * (*dpnm)(i-1, j+1);
                }
                (*dpnm)(i+1, j+1) = sqrt((2.0*i+1)/((i-j)*(i+j))) * (term1 + term2 - term3);
            }
        }
        j = j + 1;
        k = k + 1;
        if (j > m) {
            break;
        }
    }
}

void test_Legendre()
{
    Matrix *pnm = nullptr;
    Matrix *dpnm = nullptr;
    
    // Test 1: Caso basico n=2, m=2
    Legendre(2, 2, 0.0, pnm, dpnm);  // fi = 0 (ecuador)
    
    // Verificar dimensiones
    assert(pnm->size() == 9);  // (2+1)*(2+1) = 9 elementos
    assert(dpnm->size() == 9);
    
    // Valores conocidos en ecuador (fi=0): cos(0)=1, sin(0)=0
    assert(fabs((*pnm)(1,1) - 1.0) < 1e-14);     // P_0^0 = 1
    assert(fabs((*dpnm)(1,1) - 0.0) < 1e-14);    // dP_0^0/dfi = 0
    assert(fabs((*pnm)(2,2) - sqrt(3.0)) < 1e-14); // P_1^1 = sqrt(3)*cos(0) = sqrt(3)
    assert(fabs((*dpnm)(2,2) - 0.0) < 1e-14);    // dP_1^1/dfi = -sqrt(3)*sin(0) = 0
    
    delete pnm; pnm = nullptr;
    delete dpnm; dpnm = nullptr;
    
    // Test 2: Caso en polo norte (fi = pi/2)
    Legendre(2, 2, M_PI/2, pnm, dpnm);  // fi = pi/2 (polo norte)
    
    // En polo: cos(pi/2)=0, sin(pi/2)=1
    assert(fabs((*pnm)(1,1) - 1.0) < 1e-14);     // P_0^0 = 1 siempre
    assert(fabs((*pnm)(2,2) - 0.0) < 1e-14);     // P_1^1 = sqrt(3)*cos(pi/2) = 0
    assert(fabs((*dpnm)(2,2) + sqrt(3.0)) < 1e-14); // dP_1^1/dfi = -sqrt(3)*sin(pi/2) = -sqrt(3)
    
    delete pnm; pnm = nullptr;
    delete dpnm; dpnm = nullptr;
    
    // Test 3: Caso simetrico en fi = pi/4 (45 grados)
    Legendre(2, 2, M_PI/4, pnm, dpnm);
    
    double cos45 = cos(M_PI/4);  // sqrt(2)/2
    
    assert(fabs((*pnm)(1,1) - 1.0) < 1e-14);
    assert(fabs((*pnm)(2,2) - sqrt(3.0)*cos45) < 1e-14);
    
    delete pnm; pnm = nullptr;
    delete dpnm; dpnm = nullptr;
    
    // Test 4: Caso n=1, m=1 (dimensiones minimas utiles)
    Legendre(1, 1, M_PI/6, pnm, dpnm);  // 30 grados
    
    assert(fabs((*pnm)(1,1) - 1.0) < 1e-14);
    assert(fabs((*pnm)(2,2) - sqrt(3.0)*cos(M_PI/6)) < 1e-14);
    
    delete pnm; pnm = nullptr;
    delete dpnm; dpnm = nullptr;
    
    // Test 5: Verificar n mayor que m (caso tipico)
    Legendre(3, 2, M_PI/6, pnm, dpnm);  // n=3, m=2, fi=30°
    
    // Verificar que las matrices tienen el tamaño correcto
    assert(pnm->size() == 12);  // (3+1)*(2+1) = 12 elementos
    assert(dpnm->size() == 12);
    assert(fabs((*pnm)(1,1) - 1.0) < 1e-14);  // P_0^0 = 1 siempre
    
    delete pnm; pnm = nullptr;
    delete dpnm; dpnm = nullptr;
}

REGISTER_TEST(test_Legendre);