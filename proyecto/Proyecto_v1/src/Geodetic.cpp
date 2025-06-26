#include "Geodetic.h"
#include "Position.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <limits>
#include <stdexcept>

void Geodetic(const Matrix& r, double& lon, double& lat, double& h)
{
    double R_equ = R_Earth;
    double f = f_Earth;
    
    double epsRequ = std::numeric_limits<double>::epsilon() * R_equ;  // Convergence criterion
    double e2 = f * (2.0 - f);  // Square of eccentricity
    
    double X = r(1);  // Cartesian coordinates
    double Y = r(2);
    double Z = r(3);
    double rho2 = X*X + Y*Y;  // Square of distance from z-axis
    
    // Check validity of input data
    if (r.norm() == 0.0) {
        throw std::runtime_error("invalid input in Geodetic constructor");
    }
    
    // Iteration
    double dZ = e2 * Z;
    
    while (true) {
        double ZdZ = Z + dZ;
        double Nh = std::sqrt(rho2 + ZdZ*ZdZ);
        double SinPhi = ZdZ / Nh;  // Sine of geodetic latitude
        double N = R_equ / std::sqrt(1.0 - e2*SinPhi*SinPhi);
        double dZ_new = N * e2 * SinPhi;
        
        if (std::abs(dZ - dZ_new) < epsRequ) {
            break;
        }
        dZ = dZ_new;
    }
    
    double ZdZ = Z + dZ;
    double Nh = std::sqrt(rho2 + ZdZ*ZdZ);
    double N = R_equ / std::sqrt(1.0 - e2*(ZdZ/Nh)*(ZdZ/Nh));
    
    // Longitude, latitude, altitude
    lon = std::atan2(Y, X);
    lat = std::atan2(ZdZ, std::sqrt(rho2));
    h = Nh - N;
}

void test_Geodetic()
{
    const double pi = M_PI;
    const double deg2rad = pi / 180.0;
    
    // Test 1: Vector origen debe dar error
    Matrix r_zero(3, 1);
    r_zero(1) = 0.0; r_zero(2) = 0.0; r_zero(3) = 0.0;
    
    bool error_caught = false;
    try {
        double lon, lat, h;
        Geodetic(r_zero, lon, lat, h);
    } catch (const std::runtime_error&) {
        error_caught = true;
    }
    assert(error_caught);
    
    // Test 2: Punto en el ecuador (R_Earth, 0, 0) → lon=0, lat=0, h≈0
    Matrix r_equator(3, 1);
    r_equator(1) = R_Earth; r_equator(2) = 0.0; r_equator(3) = 0.0;
    
    double lon1, lat1, h1;
    Geodetic(r_equator, lon1, lat1, h1);
    
    assert(std::abs(lon1 - 0.0) < 1e-10);  // Longitud = 0
    assert(std::abs(lat1 - 0.0) < 1e-10);  // Latitud = 0
    assert(std::abs(h1) < 1.0);            // Altitud ≈ 0 (tolerancia 1m)
    
    // Test 3: 90 grados longitud (0, R_Earth, 0) → lon=π/2, lat=0, h≈0
    Matrix r_90lon(3, 1);
    r_90lon(1) = 0.0; r_90lon(2) = R_Earth; r_90lon(3) = 0.0;
    
    double lon2, lat2, h2;
    Geodetic(r_90lon, lon2, lat2, h2);
    
    assert(std::abs(lon2 - pi/2) < 1e-10);  // Longitud = 90°
    assert(std::abs(lat2 - 0.0) < 1e-10);   // Latitud = 0
    assert(std::abs(h2) < 1.0);             // Altitud ≈ 0
    
    // Test 4: Polo Norte (0, 0, Z_polar) → lat=π/2
    Matrix r_north(3, 1);
    r_north(1) = 0.0; r_north(2) = 0.0; r_north(3) = 6356752.314245;  // Radio polar WGS84
    
    double lon3, lat3, h3;
    Geodetic(r_north, lon3, lat3, h3);
    
    assert(std::abs(lat3 - pi/2) < 1e-6);   // Latitud = 90° (polo norte)
    assert(std::abs(h3) < 10.0);            // Altitud pequeña en el polo
    
    // Test 5: Polo Sur (0, 0, -Z_polar) → lat=-π/2
    Matrix r_south(3, 1);
    r_south(1) = 0.0; r_south(2) = 0.0; r_south(3) = -6356752.314245;
    
    double lon4, lat4, h4;
    Geodetic(r_south, lon4, lat4, h4);
    
    assert(std::abs(lat4 + pi/2) < 1e-6);   // Latitud = -90° (polo sur)
    assert(std::abs(h4) < 10.0);            // Altitud pequeña en el polo
    
    // Test 6: Con altitud . aumentar radio en 1000m
    Matrix r_alt(3, 1);
    r_alt(1) = R_Earth + 1000.0; r_alt(2) = 0.0; r_alt(3) = 0.0;
    
    double lon5, lat5, h5;
    Geodetic(r_alt, lon5, lat5, h5);
    
    assert(std::abs(lon5 - 0.0) < 1e-10);           // Longitud = 0
    assert(std::abs(lat5 - 0.0) < 1e-10);           // Latitud = 0
    assert(std::abs(h5 - 1000.0) < 1.0);            // Altitud ≈ 1000m
    
    // Test 7: Verificar que es inversa de Position - punto en 45°N, 90°E
    double lon_test = pi/2;      // 90°E
    double lat_test = pi/4;      // 45°N  
    double h_test = 500.0;       // 500m altitud
    
    Matrix r_pos = Position(lon_test, lat_test, h_test);
    
    double lon_back, lat_back, h_back;
    Geodetic(r_pos, lon_back, lat_back, h_back);
    
    assert(std::abs(lon_back - lon_test) < 1e-10);   // Longitud debe coincidir
    assert(std::abs(lat_back - lat_test) < 1e-10);   // Latitud debe coincidir
    assert(std::abs(h_back - h_test) < 1e-6);        // Altitud debe coincidir
    
    // Test 8: Caso con coordenadas conocidas - Greenwich (lat=51.477°, lon=0°)
    Matrix r_greenwich = Position(0.0, 51.477 * deg2rad, 0.0);
    
    double lon_gr, lat_gr, h_gr;
    Geodetic(r_greenwich, lon_gr, lat_gr, h_gr);
    
    assert(std::abs(lon_gr - 0.0) < 1e-10);                      // Longitud = 0° (Greenwich)
    assert(std::abs(lat_gr - 51.477 * deg2rad) < 1e-10);         // Latitud = 51.477°
    assert(std::abs(h_gr) < 1.0);                                // Altitud ≈ 0
    
    // Test 9: Verificar continuidad . puntos cercanos deben dar resultados cercanos
    Matrix r_close1(3, 1);
    r_close1(1) = R_Earth + 100.0; r_close1(2) = 100.0; r_close1(3) = 100.0;
    
    Matrix r_close2(3, 1);
    r_close2(1) = R_Earth + 101.0; r_close2(2) = 101.0; r_close2(3) = 101.0;
    
    double lon_c1, lat_c1, h_c1;
    double lon_c2, lat_c2, h_c2;
    
    Geodetic(r_close1, lon_c1, lat_c1, h_c1);
    Geodetic(r_close2, lon_c2, lat_c2, h_c2);
    
    assert(std::abs(lon_c1 - lon_c2) < 1e-6);  // Diferencias pequeñas
    assert(std::abs(lat_c1 - lat_c2) < 1e-6);  // Diferencias pequeñas
    assert(std::abs(h_c1 - h_c2) < 10.0);      // Diferencia de altitud razonable
    
    // Test 10: Caso LEO tipico (satelite en orbita baja)
    Matrix r_leo(3, 1);
    r_leo(1) = 6778137.0;  // R_Earth + 400km (orbita LEO tipica)
    r_leo(2) = 0.0;
    r_leo(3) = 0.0;
    
    double lon_leo, lat_leo, h_leo;
    Geodetic(r_leo, lon_leo, lat_leo, h_leo);
    
    assert(std::abs(lon_leo - 0.0) < 1e-10);                    // Longitud = 0
    assert(std::abs(lat_leo - 0.0) < 1e-10);                    // Latitud = 0  
    assert(h_leo > 390000.0 && h_leo < 410000.0);               // ~400km altitud
}

REGISTER_TEST(test_Geodetic);