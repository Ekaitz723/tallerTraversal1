#include "G_AccelHarmonic.h"
#include "AccelHarmonic.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix G_AccelHarmonic(const Matrix& r, const Matrix& U, int n_max, int m_max)
{
    double d = 1.0;
    Matrix G(3, 3);
    
    for (int i = 1; i <= 3; i++) {
        Matrix dr(3, 1);
        dr(i) = d;
        
        Matrix r_plus = r + dr * 0.5;
        Matrix r_minus = r - dr * 0.5;
        
        Matrix a_plus = AccelHarmonic(r_plus, U, n_max, m_max);
        Matrix a_minus = AccelHarmonic(r_minus, U, n_max, m_max);
        Matrix da = a_plus - a_minus;
        
        Matrix grad_col = da * (1.0 / d);
        G.assign_column(i, grad_col);
    }
    
    return G;
}

void test_G_AccelHarmonic()
{
    extern Matrix* Cnm;
    extern Matrix* Snm;
    
    Matrix* Cnm_backup = Cnm;
    Matrix* Snm_backup = Snm;
    
    Cnm = new Matrix(4, 4);
    Snm = new Matrix(4, 4);
    
    (*Cnm)(1,1) = 1.0;
    (*Cnm)(3,1) = -1082.63e-6;
    
    // Test basico - posicion ecuatorial
    Matrix r(7000.0e3, 0.0, 0.0);
    Matrix U = Matrix::eye(3);
    
    Matrix G1 = G_AccelHarmonic(r, U, 2, 0);
    
    assert(G1.isSquare());
    assert(G1.size() == 9);
    
    // No NaN o infinito
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(!std::isnan(G1(i,j)));
            assert(!std::isinf(G1(i,j)));
        }
    }
    
    // Test con posicion inclinada (evitar polos)
    Matrix r2(5000.0e3, 3000.0e3, 2000.0e3);
    Matrix G2 = G_AccelHarmonic(r2, U, 1, 0);
    
    assert(G2.isSquare());
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(!std::isnan(G2(i,j)));
            assert(!std::isinf(G2(i,j)));
        }
    }
    
    delete Cnm;
    delete Snm;
    Cnm = Cnm_backup;
    Snm = Snm_backup;
}

REGISTER_TEST(test_G_AccelHarmonic);