#include "Position.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix Position(double lon, double lat, double h)
{
    double R_equ = R_Earth;
    double f = f_Earth;
    
    double e2 = f * (2.0 - f);   // Square of eccentricity
    double CosLat = cos(lat);    // (Co)sine of geodetic latitude
    double SinLat = sin(lat);
    
    // Vector de pos
    double N = R_equ / sqrt(1.0 - e2 * SinLat * SinLat);
    
    Matrix r(3, 1);
    r(1) = (N + h) * CosLat * cos(lon);
    r(2) = (N + h) * CosLat * sin(lon);
    r(3) = ((1.0 - e2) * N + h) * SinLat;
    
    return r;
}

void test_Position()
{
    const double pi = M_PI;
    
    // Test 1: Origen (lat=0, lon=0, h=0) - debe dar (R_Earth, 0, 0)
    Matrix r1 = Position(0.0, 0.0, 0.0);
    assert(fabs(r1(1) - R_Earth) < 1.0);  // X debe ser ~R_Earth
    assert(fabs(r1(2)) < 1e-10);          // Y debe ser 0
    assert(fabs(r1(3)) < 1e-10);          // Z debe ser 0
    
    // Test 2: 90 grados longitud (lat=0, lon=pi/2, h=0)
    Matrix r2 = Position(pi/2, 0.0, 0.0);
    assert(fabs(r2(1)) < 1.0);            // X debe ser ~0
    assert(fabs(r2(2) - R_Earth) < 1.0);  // Y debe ser ~R_Earth
    assert(fabs(r2(3)) < 1e-10);          // Z debe ser 0
    
    // Test 3: Polo Norte (lat=pi/2, cualquier lon, h=0)
    Matrix r3 = Position(0.0, pi/2, 0.0);
    assert(fabs(r3(1)) < 1e-6);           // X debe ser ~0 (precision numerica)
    assert(fabs(r3(2)) < 1e-6);           // Y debe ser ~0 (precision numerica)
    assert(r3(3) > 6.35e6);               // Z debe ser positivo, ~radio polar
    
    // Test 4: Polo Sur (lat=-pi/2, cualquier lon, h=0)
    Matrix r4 = Position(0.0, -pi/2, 0.0);
    assert(fabs(r4(1)) < 1e-6);           // X debe ser ~0 (precision numerica)
    assert(fabs(r4(2)) < 1e-6);           // Y debe ser ~0 (precision numerica)
    assert(r4(3) < -6.35e6);              // Z debe ser negativo
    
    // Test 5: Con altitud - debe aumentar magnitud
    Matrix r5_sea = Position(0.0, 0.0, 0.0);
    Matrix r5_alt = Position(0.0, 0.0, 1000.0);  // 1km altitud
    assert(r5_alt(1) > r5_sea(1));        // Debe estar mas lejos del centro
    assert(fabs(r5_alt(1) - r5_sea(1) - 1000.0) < 1e-10);
    
    // Test 6: Magnitud del vector debe ser razonable
    Matrix r6 = Position(pi/4, pi/6, 0.0);  // 45°E, 30°N
    double mag = r6.norm();
    assert(mag > 6.35e6 && mag < 6.4e6);  // Entre radio polar y ecuatorial
    
    // Test 7: Greenwich Observatory aproximadamente (0° lon, ~51.5°N lat)
    Matrix r7 = Position(0.0, 51.5 * pi/180, 0.0);
    assert(r7(1) > 3.9e6 && r7(1) < 4.1e6);  // Coordenada X
    assert(fabs(r7(2)) < 1e-10);             // Coordenada Y (lon=0)
    assert(r7(3) > 4.9e6 && r7(3) < 5.1e6);  // Coordenada Z
    
    // Test 8: Verificar que vector 3D es correcto
    Matrix r8 = Position(pi/3, pi/4, 500.0);
    assert(r8.isVector3D());
    assert(r8.isVertical());
    
    // Test 9: Coordenadas de Kaena Point (del archivo GEOS3)
    double lat_kaena = 21.5748 * pi/180;
    double lon_kaena = -158.2706 * pi/180;
    double alt_kaena = 300.20;
    Matrix r9 = Position(lon_kaena, lat_kaena, alt_kaena);
    
    // Verificar que da coordenadas razonables para Hawaii
    double mag_kaena = r9.norm();
    assert(mag_kaena > 6.37e6 && mag_kaena < 6.38e6);
    assert(r9(1) < 0);  // X negativo (longitud oeste)
    assert(r9(2) < 0);  // Y negativo (longitud oeste)
    assert(r9(3) > 0);  // Z positivo (latitud norte)
}

REGISTER_TEST(test_Position);