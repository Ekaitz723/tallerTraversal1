#include "MeasUpdate.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void MeasUpdate(Matrix& x, double z, double g, double s, 
                const Matrix& G, Matrix& P, int n, Matrix*& K)
{
    // % Inverse weight (measurement covariance)
    double Inv_W = s * s;
    
    // Kalman gain: K = P*G'*inv(Inv_W+G*P*G')
    Matrix GT = G.transpose();
    Matrix GPS = G * P * GT;
    double denominator = Inv_W + GPS(1,1);
    
    K = new Matrix(P * GT * (1.0 / denominator));
    
    // State update: x = x + K*(z-g)
    double innovation = z - g;
    x = x + (*K) * innovation;
    
    // Covariance update: P = (I-K*G)*P
    Matrix I = Matrix::eye(n);
    Matrix IKG = I - (*K) * G;
    P = IKG * P;
}

void test_MeasUpdate()
{
    // Test 1: Caso tipico azimuth measurement del EKF_GEOS3
    Matrix x(6, 1);  // State vector [posicion, velocidad]
    x(1) = 7000.0e3; x(2) = 0.0; x(3) = 0.0;  // r [m]
    x(4) = 0.0; x(5) = 7.5e3; x(6) = 0.0;     // v [m/s]
    
    Matrix P = Matrix::eye(6) * 1e6;  // Covariance inicial
    
    Matrix G(1, 6);  // Jacobian tipico dAdY
    G(1,1) = 1e-7; G(1,2) = 2e-7; G(1,3) = 0.0;
    G(1,4) = 0.0; G(1,5) = 0.0; G(1,6) = 0.0;
    
    double z = 1.2;      // Azimuth observado [rad]
    double g = 1.15;     // Azimuth predicho [rad] 
    double sigma = 0.0224;  // sigma_az del GEOS3
    
    Matrix x_orig = x;
    double P_orig = P(1,1);
    Matrix* K = nullptr;
    
    MeasUpdate(x, z, g, sigma, G, P, 6, K);
    
    // K debe ser vector 6x1
    assert(K != nullptr);
    assert(K->isVector());
    assert(K->size() == 6);
    
    // Estado debe cambiar por la innovacion
    assert(fabs(x(1) - x_orig(1)) > 1e-3);
    
    // Covarianza debe reducirse
    assert(P(1,1) < P_orig);
    
    delete K;
    
    // Test 2: Elevation measurement
    Matrix x2(6, 1);
    x2(1) = 6500.0e3; x2(2) = 1000.0e3; x2(3) = 2000.0e3;
    x2(4) = 100.0; x2(5) = -200.0; x2(6) = 7400.0;
    
    Matrix P2 = Matrix::eye(6) * 5e5;
    
    Matrix G2(1, 6);  // dEdY
    G2(1,1) = -1e-8; G2(1,2) = 3e-8; G2(1,3) = 2e-7;
    G2(1,4) = 0.0; G2(1,5) = 0.0; G2(1,6) = 0.0;
    
    double el_obs = 0.45;     // Elevacion observada
    double el_pred = 0.42;    // Elevacion predicha
    double sigma_el = 0.0139; // del GEOS3
    
    Matrix* K2 = nullptr;
    MeasUpdate(x2, el_obs, el_pred, sigma_el, G2, P2, 6, K2);
    
    assert(K2 != nullptr);
    assert(K2->size() == 6);
    
    delete K2;
    
    // Test 3: Range measurement  
    Matrix x3(6, 1);
    x3(1) = 6378.0e3; x3(2) = 0.0; x3(3) = 400.0e3;  // LEO orbit
    x3(4) = 0.0; x3(5) = 7600.0; x3(6) = 0.0;
    
    Matrix P3 = Matrix::eye(6) * 2e5;
    
    Matrix G3(1, 6);  // dDdY para range
    G3(1,1) = 0.8; G3(1,2) = 0.0; G3(1,3) = 0.6;
    G3(1,4) = 0.0; G3(1,5) = 0.0; G3(1,6) = 0.0;
    
    double dist_obs = 1500.0e3;   // Distancia observada [m]
    double dist_pred = 1485.0e3;  // Distancia predicha [m]
    double sigma_range = 92.5;    // del GEOS3
    
    Matrix* K3 = nullptr;
    Matrix x3_orig = x3;
    
    MeasUpdate(x3, dist_obs, dist_pred, sigma_range, G3, P3, 6, K3);
    
    // Range es muy preciso, debe corregir bastante
    assert(fabs(x3(1) - x3_orig(1)) > 1e3);
    
    delete K3;
    
    // Test 4: Verificar formula Kalman correcta
    Matrix x4(2, 1);
    x4(1) = 5.0; x4(2) = 3.0;
    
    Matrix P4(2, 2);
    P4(1,1) = 100.0; P4(1,2) = 0.0;  // Alta incertidumbre inicial
    P4(2,1) = 0.0; P4(2,2) = 100.0;
    
    Matrix G4(1, 2);
    G4(1,1) = 1.0; G4(1,2) = 0.0;  // Solo observa primera componente
    
    double s_small = 0.1;  // Medicion muy precisa
    Matrix* K4 = nullptr;
    Matrix x4_orig = x4;
    
    MeasUpdate(x4, 6.0, 5.0, s_small, G4, P4, 2, K4);
    
    // Con alta incertidumbre inicial y medicion precisa, debe corregir bastante
    assert(fabs(x4(1) - x4_orig(1)) > 0.5);
    
    delete K4;
    
    // Test 5: Innovacion zero (medicion = prediccion)
    Matrix x5(3, 1);
    x5(1) = 1.0; x5(2) = 2.0; x5(3) = 3.0;
    
    Matrix P5 = Matrix::eye(3) * 2.0;
    Matrix x5_orig = x5;
    
    Matrix G5(1, 3);
    G5(1,1) = 1.0; G5(1,2) = 0.0; G5(1,3) = 0.0;
    
    Matrix* K5 = nullptr;
    MeasUpdate(x5, 2.0, 2.0, 1.0, G5, P5, 3, K5);  // z = g = 2.0
    
    // Estado debe cambiar menos (innovacion zero)
    assert(fabs(x5(1) - x5_orig(1)) < 1e-10);
    
    // Pero covarianza aun debe reducirse
    assert(P5(1,1) < 2.0);
    
    delete K5;
}

REGISTER_TEST(test_MeasUpdate);