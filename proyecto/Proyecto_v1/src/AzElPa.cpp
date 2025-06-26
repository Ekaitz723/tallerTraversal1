#include "AzElPa.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void AzElPa(const Matrix& s, double& Az, double& El, Matrix*& dAds, Matrix*& dEds)
{
    double rho = sqrt(s(1)*s(1) + s(2)*s(2));
    
    Az = std::atan2(s(1), s(2));
    
    if (Az < 0.0) {
        Az = Az + pi2;
    }
    
    El = std::atan(s(3) / rho);
    
    dAds = new Matrix(1, 3);
    dEds = new Matrix(1, 3);
    // dAds = &(Matrix::row_vector(3));
    // dEds = &(Matrix::row_vector(3));
    
    dAds->operator()(1, 1) = s(2) / (rho * rho);
    dAds->operator()(1, 2) = -s(1) / (rho * rho);
    dAds->operator()(1, 3) = 0.0;
    
    double dot_s_s = Matrix::dot(s, s);
    dEds->operator()(1, 1) = -s(1) * s(3) / rho / dot_s_s;
    dEds->operator()(1, 2) = -s(2) * s(3) / rho / dot_s_s;
    dEds->operator()(1, 3) = rho / dot_s_s;
}

void test_AzElPa()
{
    double Az, El;
    
    Matrix *dAds = nullptr;
    Matrix *dEds = nullptr;
    
    Matrix s1(0.0, 1.0, 0.0);
    
    
    AzElPa(s1, Az, El, dAds, dEds);
    
    assert(fabs(Az - 0.0) < 1e-14);
    assert(fabs(El - 0.0) < 1e-14);
    assert(dAds->isVector());
    assert(dEds->isVector());
    
    Matrix s2(1.0, 0.0, 0.0);
    AzElPa(s2, Az, El, dAds, dEds);
    
    assert(fabs(Az - pi/2) < 1e-14);
    assert(fabs(El - 0.0) < 1e-14);
    
    Matrix s3(0.0, 0.0, 1.0);
    AzElPa(s3, Az, El, dAds, dEds);
    
    assert(fabs(El - pi/2) < 1e-14);
    
    Matrix s4(1.0, 1.0, 0.0);
    AzElPa(s4, Az, El, dAds, dEds);
    
    assert(fabs(Az - pi/4) < 1e-14);
    assert(fabs(El - 0.0) < 1e-14);
    
    Matrix s5(1.0, 0.0, 1.0);
    AzElPa(s5, Az, El, dAds, dEds);
    
    assert(fabs(Az - pi/2) < 1e-14);
    assert(fabs(El - pi/4) < 1e-14);
    
    Matrix s6(0.0, -1.0, 0.0);
    AzElPa(s6, Az, El, dAds, dEds);
    
    assert(fabs(Az - pi) < 1e-14);
    assert(fabs(El - 0.0) < 1e-14);
    
    Matrix s7(-1.0, 0.0, 0.0);
    AzElPa(s7, Az, El, dAds, dEds);
    
    assert(fabs(Az - 3*pi/2) < 1e-14);
    assert(fabs(El - 0.0) < 1e-14);
    
    Matrix s8(-0.5, -0.5, 0.0);
    AzElPa(s8, Az, El, dAds, dEds);
    
    assert(Az >= 0.0 && Az < pi2);
    
    Matrix s9(1.0, 1.0, 1.0);
    AzElPa(s9, Az, El, dAds, dEds);
    
    assert(!dAds->isVertical());
    assert(!dEds->isVertical());
    assert(dAds->size() == 3);
    assert(dEds->size() == 3);
    
    Matrix s10(100.0, 500.0, 200.0);
    AzElPa(s10, Az, El, dAds, dEds);
    
    assert(Az >= 0.0 && Az < pi2);
    assert(El >= -pi/2 && El <= pi/2);
    
    double expected_El = atan(200.0 / sqrt(100.0*100.0 + 500.0*500.0));
    assert(fabs(El - expected_El) < 1e-12);
    
    double expected_Az = atan2(100.0, 500.0);
    if (expected_Az < 0.0) expected_Az += pi2;
    assert(fabs(Az - expected_Az) < 1e-12);

    delete dAds;
    delete dEds;
}

REGISTER_TEST(test_AzElPa);