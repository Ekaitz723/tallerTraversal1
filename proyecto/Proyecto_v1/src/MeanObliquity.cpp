#include "MeanObliquity.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double MeanObliquity(double Mjd_TT)
{
    double T = (Mjd_TT - MJD_J2000) / 36525.0;
    
    double MOblq = Rad * (84381.448/3600.0 - (46.8150 + (0.00059 - 0.001813*T)*T)*T/3600.0);
    
    return MOblq;
}

void test_MeanObliquity()
{
    const double pi = M_PI;
    
    // Test 1: Para J2000.0 (Mjd_TT = 51544.5), oblicuidad ≈ 23.4392911°
    double Mjd_J2000 = 51544.5;
    double oblq_J2000 = MeanObliquity(Mjd_J2000);
    double expected_J2000_deg = 23.4392911;
    double expected_J2000_rad = expected_J2000_deg * pi/180.0;
    assert(fabs(oblq_J2000 - expected_J2000_rad) < 1e-6);
    
    // Test 2: Para 1 enero 2020 (Mjd_TT ≈ 58849.0), oblicuidad ≈ 23.4366°  
    double Mjd_2020 = 58849.0;
    double oblq_2020 = MeanObliquity(Mjd_2020);
    double expected_2020_deg = 23.4366;
    double expected_2020_rad = expected_2020_deg * pi/180.0;
    assert(fabs(oblq_2020 - expected_2020_rad) < 1e-3);
    
    // Test 3: Para 1900 (Mjd_TT ≈ 15020.0), oblicuidad ≈ 23.4522°
    double Mjd_1900 = 15020.0;
    double oblq_1900 = MeanObliquity(Mjd_1900);
    double expected_1900_deg = 23.4522;
    double expected_1900_rad = expected_1900_deg * pi/180.0;
    assert(fabs(oblq_1900 - expected_1900_rad) < 1e-3);
    
    // Test 4: Verificar que la oblicuidad disminuye con el tiempo
    double oblq_past = MeanObliquity(40000.0);   // Fecha anterior
    double oblq_future = MeanObliquity(70000.0); // Fecha posterior
    assert(oblq_past > oblq_future);
    
    // Test 5: Valores dentro del rango esperado astronómico (22° - 24.5°)
    double oblq_test = MeanObliquity(51544.5);
    double oblq_degrees = oblq_test * 180.0/pi;
    assert(oblq_degrees > 22.0 && oblq_degrees < 24.5);
    
    // Test 6: Verificar precisión numérica con valor específico conocido
    // Para T = 1.0 (un siglo después de J2000), oblicuidad ≈ 23.4392° - 46.815" 
    double Mjd_2100 = 51544.5 + 36525.0; // +100 años
    double oblq_2100 = MeanObliquity(Mjd_2100);
    double T = 1.0;
    double expected_arcsec = 84381.448 - (46.8150 + (0.00059 - 0.001813*T)*T)*T;
    double expected_rad = (pi/180.0) * expected_arcsec/3600.0;
    assert(fabs(oblq_2100 - expected_rad) < 1e-12);
    
    // Test 7: Comportamiento asintótico - la oblicuidad no cambia drásticamente
    double oblq_near = MeanObliquity(51544.5);
    double oblq_day_later = MeanObliquity(51545.5);
    assert(fabs(oblq_near - oblq_day_later) < 1e-8);
}

REGISTER_TEST(test_MeanObliquity);