#include "VarEqn.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "AccelHarmonic.h"
#include "G_AccelHarmonic.h"
#include "Accel.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix VarEqn(double x, const Matrix& yPhi)
{
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS(*eopdata, auxParam.Mjd_UTC, 'l', 
         x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    
    double Mjd_UT1 = auxParam.Mjd_TT + (UT1_UTC - TT_UTC) / 86400.0;
    
    // Transformation matrix
    Matrix P = PrecMatrix(MJD_J2000, auxParam.Mjd_TT + x/86400.0);
    Matrix N = NutMatrix(auxParam.Mjd_TT + x/86400.0);
    Matrix T = N * P;
    Matrix E = PoleMatrix(x_pole, y_pole) * GHAMatrix(Mjd_UT1) * T;
    
    // State vector components
    Matrix r(3, 1);
    Matrix v(3, 1);
    r(1) = yPhi(1); r(2) = yPhi(2); r(3) = yPhi(3);
    v(1) = yPhi(4); v(2) = yPhi(5); v(3) = yPhi(6);
    
    Matrix Phi(6, 6);
    
    // State transition matrix
    for (int j = 1; j <= 6; j++) {
        for (int i = 1; i <= 6; i++) {
            Phi(i, j) = yPhi(6*j + i);
        }
    }
    
    // Acceleration and gradient
    Matrix a = AccelHarmonic(r, E, auxParam.n, auxParam.m);
    Matrix G = G_AccelHarmonic(r, E, auxParam.n, auxParam.m);
    
    // Time derivative of state transition matrix
    Matrix yPhip(42, 1);
    Matrix dfdy(6, 6);
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            dfdy(i, j) = 0.0;                    // dv/dr(i,j)
            dfdy(i+3, j) = G(i, j);              // da/dr(i,j)
            if (i == j) {
                dfdy(i, j+3) = 1.0;
            } else {
                dfdy(i, j+3) = 0.0;              // dv/dv(i,j)
            }
            dfdy(i+3, j+3) = 0.0;                // da/dv(i,j)
        }
    }
    
    Matrix Phip = dfdy * Phi;
    
    // Derivative of combined state vector and state transition matrix
    for (int i = 1; i <= 3; i++) {
        yPhip(i) = v(i);                         // dr/dt(i)
        yPhip(i+3) = a(i);                       // dv/dt(i)
    }
    
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            yPhip(6*j + i) = Phip(i, j);         // dPhi/dt(i,j)
        }
    }
    
    return yPhip;
}

void test_VarEqn()
{
    // Backup de las variables globales
    extern Matrix* Cnm;
    extern Matrix* Snm;
    
    Matrix* Cnm_backup = Cnm;
    Matrix* Snm_backup = Snm;
    Matrix* eopdata_backup = eopdata;
    AuxParam auxParam_backup = auxParam;
    
    Cnm = new Matrix(5, 5);
    Snm = new Matrix(5, 5);
    (*Cnm)(1,1) = 1.0;
    (*Cnm)(3,1) = -1082.63e-6;  // J2
    
    eopdata = new Matrix(13, 3);
    (*eopdata)(4,1) = 51544.0;  // J2000 MJD
    (*eopdata)(5,1) = 0.035;    // x_pole [arcsec]
    (*eopdata)(6,1) = 0.32;     // y_pole [arcsec]
    (*eopdata)(7,1) = -0.184;   // UT1_UTC [s]
    (*eopdata)(13,1) = 32.0;    // TAI_UTC [s]
    
    (*eopdata)(4,2) = 51545.0;
    (*eopdata)(5,2) = 0.034;
    (*eopdata)(6,2) = 0.319;
    (*eopdata)(7,2) = -0.185;
    (*eopdata)(13,2) = 32.0;
    
    auxParam.Mjd_UTC = 51544.5;
    auxParam.Mjd_TT = 51544.5;
    auxParam.n = 4;
    auxParam.m = 4;
    
    // Test 1: LEO circular - caso del EKF
    Matrix yPhi(42, 1);
    
    // Estado: r = [7000, 0, 0] km, v = [0, 7.5, 0] km/s
    yPhi(1) = 7000.0e3;  // x [m]
    yPhi(2) = 0.0;       // y
    yPhi(3) = 0.0;       // z  
    yPhi(4) = 0.0;       // vx [m/s]
    yPhi(5) = 7.5e3;     // vy
    yPhi(6) = 0.0;       // vz
    
    // Matriz transicion inicial (identidad)
    for (int i = 7; i <= 42; i++) {
        yPhi(i) = 0.0;
    }
    for (int j = 1; j <= 6; j++) {
        yPhi(6*j + j) = 1.0;
    }
    
    Matrix yPhip = VarEqn(0.0, yPhi);
    
    // Verif. dimension 
    assert(yPhip.size() == 42);
    assert(yPhip.isVertical());
    
    // Primeros 6 elementos: derivadas del estado
    assert(fabs(yPhip(1) - 0.0) < 1e-10);      // dr/dt = v
    assert(fabs(yPhip(2) - 7.5e3) < 1e-10);
    assert(fabs(yPhip(3) - 0.0) < 1e-10);
    assert(yPhip(4) < 0);                       // ax negativa (hacia centro)
    
    // Magnitud de aceleracion realista para LEO
    double a_mag = std::sqrt(yPhip(4)*yPhip(4) + yPhip(5)*yPhip(5) + yPhip(6)*yPhip(6));
    assert(a_mag > 7.0 && a_mag < 10.0);  // ~8-9 m/s² en LEO
    
    // Test 2: Orbita inclinada
    Matrix yPhi2(42, 1);
    yPhi2(1) = 6500.0e3; yPhi2(2) = 1000.0e3; yPhi2(3) = 2000.0e3;
    yPhi2(4) = -1.0e3; yPhi2(5) = 7.0e3; yPhi2(6) = 2.0e3;
    
    for (int i = 7; i <= 42; i++) {
        yPhi2(i) = 0.0;
    }
    for (int j = 1; j <= 6; j++) {
        yPhi2(6*j + j) = 1.0;
    }
    
    Matrix yPhip2 = VarEqn(0.0, yPhi2);
    
    assert(yPhip2.size() == 42);
    assert(fabs(yPhip2(1) - (-1.0e3)) < 1e-10);
    assert(fabs(yPhip2(2) - 7.0e3) < 1e-10);
    assert(fabs(yPhip2(3) - 2.0e3) < 1e-10);
    
    // Test 3: Verificar propagacion matriz transicion 
    Matrix yPhi3(42, 1);
    yPhi3(1) = 7000.0e3; yPhi3(2) = 0.0; yPhi3(3) = 0.0;
    yPhi3(4) = 0.0; yPhi3(5) = 7.5e3; yPhi3(6) = 0.0;
    
    for (int i = 7; i <= 42; i++) {
        yPhi3(i) = 0.0;
    }
    for (int j = 1; j <= 6; j++) {
        yPhi3(6*j + j) = 1.0;
    }
    yPhi3(6*2 + 1) = 0.1;  // Elemento off-diagonal
    
    Matrix yPhip3 = VarEqn(0.0, yPhi3);
    
    // Derivadas de matriz transicion (elementos 7-42) no deben ser zero
    bool has_nonzero_stm = false;
    for (int i = 7; i <= 42; i++) {
        if (fabs(yPhip3(i)) > 1e-10) {
            has_nonzero_stm = true;
            break;
        }
    }
    assert(has_nonzero_stm);
    
    // Test 4: Continuidad temporal
    Matrix yPhip_t1 = VarEqn(0.0, yPhi);
    Matrix yPhip_t2 = VarEqn(1.0, yPhi);  // 1 segundo despues
    
    for (int i = 1; i <= 6; i++) {
        assert(fabs(yPhip_t1(i) - yPhip_t2(i)) < 1e-2);  // Cambio gradual
    }
    
    // Test 5: Caso GEO
    Matrix yPhi_geo(42, 1);
    yPhi_geo(1) = 42164.0e3; yPhi_geo(2) = 0.0; yPhi_geo(3) = 0.0;  // Radio GEO
    yPhi_geo(4) = 0.0; yPhi_geo(5) = 3.07e3; yPhi_geo(6) = 0.0;     // Vel GEO
    
    for (int i = 7; i <= 42; i++) {
        yPhi_geo(i) = 0.0;
    }
    for (int j = 1; j <= 6; j++) {
        yPhi_geo(6*j + j) = 1.0;
    }
    
    Matrix yPhip_geo = VarEqn(0.0, yPhi_geo);
    
    double a_geo = std::sqrt(yPhip_geo(4)*yPhip_geo(4) + yPhip_geo(5)*yPhip_geo(5) + yPhip_geo(6)*yPhip_geo(6));
    assert(a_geo > 0.1 && a_geo < 0.5);  // ~0.22 m/s² en GEO
    
    // Restaurar variables globales usando el backup del inicio
    delete Cnm; delete Snm; delete eopdata;
    Cnm = Cnm_backup;
    Snm = Snm_backup;
    eopdata = eopdata_backup;
    auxParam = auxParam_backup;
}

REGISTER_TEST(test_VarEqn);