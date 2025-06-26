#include "Accel.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "Mjday_TDB.h"
#include "JPL_Eph_DE430.h"
#include "AccelHarmonic.h"
#include "AccelPointMass.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

AuxParam auxParam;
Matrix* eopdata = nullptr;
bool test_mode = false;

void test_Accel();

// esque sino va a dar problemas el PC matrix
void JPL_Eph_DE430_mock(double Mjd_TDB, 
    Matrix*& r_Mercury, Matrix*& r_Venus, Matrix*& r_Earth, Matrix*& r_Mars,
    Matrix*& r_Jupiter, Matrix*& r_Saturn, Matrix*& r_Uranus, 
    Matrix*& r_Neptune, Matrix*& r_Pluto, Matrix*& r_Moon, Matrix*& r_Sun);


Matrix Accel(double x, const Matrix& Y)
{
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS(*eopdata, auxParam.Mjd_UTC + x/86400.0, 'l', 
         x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    
    double Mjd_UT1 = auxParam.Mjd_UTC + x/86400.0 + UT1_UTC/86400.0;
    double Mjd_TT = auxParam.Mjd_UTC + x/86400.0 + TT_UTC/86400.0;
    
    Matrix P = PrecMatrix(MJD_J2000, Mjd_TT);
    Matrix N = NutMatrix(Mjd_TT);
    Matrix T = N * P;
    Matrix E = PoleMatrix(x_pole, y_pole) * GHAMatrix(Mjd_UT1) * T;
    
    double MJD_TDB = Mjday_TDB(Mjd_TT);
    
    Matrix *r_Mercury, *r_Venus, *r_Earth, *r_Mars, *r_Jupiter;
    Matrix *r_Saturn, *r_Uranus, *r_Neptune, *r_Pluto, *r_Moon, *r_Sun;

    if(test_mode) {
        JPL_Eph_DE430_mock(MJD_TDB, r_Mercury, r_Venus, r_Earth, r_Mars,
                        r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);
    } else {
        JPL_Eph_DE430(MJD_TDB, r_Mercury, r_Venus, r_Earth, r_Mars,
                    r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);
    }
    
    Matrix r(3, 1);
    r(1) = Y(1);
    r(2) = Y(2);
    r(3) = Y(3);
    
    Matrix a = AccelHarmonic(r, E, auxParam.n, auxParam.m);
    
    if (auxParam.sun) {
        a = a + AccelPointMass(r, *r_Sun, GM_Sun);
    }
    
    if (auxParam.moon) {
        a = a + AccelPointMass(r, *r_Moon, GM_Moon);
    }
    
    if (auxParam.planets) {
        a = a + AccelPointMass(r, *r_Mercury, GM_Mercury);
        a = a + AccelPointMass(r, *r_Venus, GM_Venus);
        a = a + AccelPointMass(r, *r_Mars, GM_Mars);
        a = a + AccelPointMass(r, *r_Jupiter, GM_Jupiter);
        a = a + AccelPointMass(r, *r_Saturn, GM_Saturn);
        a = a + AccelPointMass(r, *r_Uranus, GM_Uranus);
        a = a + AccelPointMass(r, *r_Neptune, GM_Neptune);
        a = a + AccelPointMass(r, *r_Pluto, GM_Pluto);
    }
    
    Matrix dY(6, 1);
    dY(1) = Y(4);  // vx
    dY(2) = Y(5);  // vy
    dY(3) = Y(6);  // vz
    dY(4) = a(1);  // ax
    dY(5) = a(2);  // ay
    dY(6) = a(3);  // az
    
    // Cleanup
    delete r_Mercury; delete r_Venus; delete r_Earth; delete r_Mars;
    delete r_Jupiter; delete r_Saturn; delete r_Uranus; delete r_Neptune;
    delete r_Pluto; delete r_Moon; delete r_Sun;
    
    return dY;
}

// Mock de JPL_Eph_DE430 para tests
void JPL_Eph_DE430_mock(double Mjd_TDB, 
    Matrix*& r_Mercury, Matrix*& r_Venus, Matrix*& r_Earth, Matrix*& r_Mars,
    Matrix*& r_Jupiter, Matrix*& r_Saturn, Matrix*& r_Uranus, 
    Matrix*& r_Neptune, Matrix*& r_Pluto, Matrix*& r_Moon, Matrix*& r_Sun)
{
    // Posiciones realistas para tests
    r_Mercury = new Matrix(3, 1);
    r_Venus = new Matrix(3, 1);
    r_Earth = new Matrix(3, 1);
    r_Mars = new Matrix(3, 1);
    r_Jupiter = new Matrix(3, 1);
    r_Saturn = new Matrix(3, 1);
    r_Uranus = new Matrix(3, 1);
    r_Neptune = new Matrix(3, 1);
    r_Pluto = new Matrix(3, 1);
    r_Moon = new Matrix(3, 1);
    r_Sun = new Matrix(3, 1);

    // Sol a ~1 AU
    (*r_Sun)(1) = 1.496e11;  // 149.6 millones km
    (*r_Sun)(2) = 0.0;
    (*r_Sun)(3) = 0.0;

    // Luna a ~384400 km
    (*r_Moon)(1) = 3.844e8;  // 384400 km
    (*r_Moon)(2) = 0.0;
    (*r_Moon)(3) = 0.0;

    // Planetas con distancias tipicas
    (*r_Mercury)(1) = 5.79e10;   // 0.39 AU
    (*r_Mercury)(2) = 0.0;
    (*r_Mercury)(3) = 0.0;

    (*r_Venus)(1) = 1.082e11;    // 0.72 AU
    (*r_Venus)(2) = 0.0;
    (*r_Venus)(3) = 0.0;

    (*r_Mars)(1) = 2.279e11;     // 1.52 AU
    (*r_Mars)(2) = 0.0;
    (*r_Mars)(3) = 0.0;

    (*r_Jupiter)(1) = 7.786e11;  // 5.2 AU
    (*r_Jupiter)(2) = 0.0;
    (*r_Jupiter)(3) = 0.0;

    (*r_Saturn)(1) = 1.434e12;   // 9.58 AU
    (*r_Saturn)(2) = 0.0;
    (*r_Saturn)(3) = 0.0;

    (*r_Uranus)(1) = 2.873e12;   // 19.2 AU
    (*r_Uranus)(2) = 0.0;
    (*r_Uranus)(3) = 0.0;

    (*r_Neptune)(1) = 4.495e12;  // 30.05 AU
    (*r_Neptune)(2) = 0.0;
    (*r_Neptune)(3) = 0.0;

    (*r_Pluto)(1) = 5.906e12;    // 39.48 AU
    (*r_Pluto)(2) = 0.0;
    (*r_Pluto)(3) = 0.0;

    // Earth está en el origen (posiciones geocentricas)
    (*r_Earth)(1) = 0.0;
    (*r_Earth)(2) = 0.0;
    (*r_Earth)(3) = 0.0;
}

void test_Accel()
{
    // Backup de variables globales existentes
    extern Matrix* Cnm;
    extern Matrix* Snm;
    extern Matrix* PC;
    
    Matrix* Cnm_backup = Cnm;
    Matrix* Snm_backup = Snm;
    Matrix* eopdata_backup = eopdata;
    
    test_mode = true;  // Activar modo test
    
    // Inicializar Cnm y Snm para AccelHarmonic
    Cnm = new Matrix(5, 5);
    Snm = new Matrix(5, 5);
    (*Cnm)(1,1) = 1.0;
    (*Cnm)(3,1) = -1082.63e-6;  // J2
    
    // Inicializar eopdata
    eopdata = new Matrix(13, 3);
    (*eopdata)(4,1) = 51544.0;  // J2000 MJD
    (*eopdata)(5,1) = 0.035;    // x_pole
    (*eopdata)(6,1) = 0.32;     // y_pole
    (*eopdata)(7,1) = -0.184;   // UT1_UTC
    (*eopdata)(13,1) = 32.0;    // TAI_UTC
    
    (*eopdata)(4,2) = 51545.0;
    (*eopdata)(5,2) = 0.034;
    (*eopdata)(6,2) = 0.319;
    (*eopdata)(7,2) = -0.185;
    (*eopdata)(13,2) = 32.0;
    
    auxParam.Mjd_UTC = 51544.5;  // J2000.0
    auxParam.n = 4;
    auxParam.m = 4;
    auxParam.sun = true;
    auxParam.moon = true;
    auxParam.planets = false;
    
    // Test 1: Orbita circular LEO
    Matrix Y(6, 1);
    Y(1) = 7000.0e3;  // x [m]
    Y(2) = 0.0;       // y
    Y(3) = 0.0;       // z
    Y(4) = 0.0;       // vx [m/s]
    Y(5) = 7.5e3;     // vy
    Y(6) = 0.0;       // vz
    
    Matrix dY = Accel(0.0, Y);
    
    assert(dY.size() == 6);
    assert(fabs(dY(1) - 0.0) < 1e-10);      // dY(1) = Y(4) = vx
    assert(fabs(dY(2) - 7.5e3) < 1e-10);    // dY(2) = Y(5) = vy
    assert(fabs(dY(3) - 0.0) < 1e-10);      // dY(3) = Y(6) = vz
    assert(dY(4) < 0);                       // ax negativa (hacia centro)
    
    // Test 2: Verificar magnitud de aceleracion
    double a_mag = std::sqrt(dY(4)*dY(4) + dY(5)*dY(5) + dY(6)*dY(6));
    assert(a_mag > 7.0 && a_mag < 10.0);    // ~8-9 m/s² en LEO
    
    // Test 3: Orbita inclinada
    Matrix Y2(6, 1);
    Y2(1) = 6500.0e3;
    Y2(2) = 1000.0e3;
    Y2(3) = 2000.0e3;
    Y2(4) = -1.0e3;
    Y2(5) = 7.0e3;
    Y2(6) = 2.0e3;
    
    Matrix dY2 = Accel(0.0, Y2);
    
    assert(dY2.size() == 6);
    assert(fabs(dY2(1) - Y2(4)) < 1e-10);
    assert(fabs(dY2(2) - Y2(5)) < 1e-10);
    assert(fabs(dY2(3) - Y2(6)) < 1e-10);
    
    // Test 4: Sin perturbaciones
    auxParam.sun = false;
    auxParam.moon = false;
    auxParam.planets = false;
    
    Matrix dY_no_pert = Accel(0.0, Y);
    
    // La aceleracion debe ser diferente sin perturbaciones
    // Las perturbaciones son del orden de 10^-6 a 10^-5 m/s²
    double diff = std::sqrt((dY(4)-dY_no_pert(4))*(dY(4)-dY_no_pert(4)) + 
                           (dY(5)-dY_no_pert(5))*(dY(5)-dY_no_pert(5)) + 
                           (dY(6)-dY_no_pert(6))*(dY(6)-dY_no_pert(6)));
    assert(diff > 1e-6 && diff < 1e-4);  // Perturbaciones tipicas
    
    // Test 5: Posicion GEO
    auxParam.sun = true;
    auxParam.moon = true;
    
    Matrix Y_geo(6, 1);
    Y_geo(1) = 42164.0e3; // Radio GEO
    Y_geo(2) = 0.0;
    Y_geo(3) = 0.0;
    Y_geo(4) = 0.0;
    Y_geo(5) = 3.07e3; // Velocidad GEO
    Y_geo(6) = 0.0;
    
    Matrix dY_geo = Accel(0.0, Y_geo);
    
    double a_geo_mag = std::sqrt(dY_geo(4)*dY_geo(4) + dY_geo(5)*dY_geo(5) + dY_geo(6)*dY_geo(6));
    assert(a_geo_mag > 0.1 && a_geo_mag < 0.3);  // ~0.22 m/s² en GEO
    
    // Restaurar variables globales
    delete Cnm; delete Snm; delete eopdata;
    Cnm = Cnm_backup;
    Snm = Snm_backup;
    eopdata = eopdata_backup;
    
    test_mode = false;  // Desactivar modo test
}

REGISTER_TEST(test_Accel);