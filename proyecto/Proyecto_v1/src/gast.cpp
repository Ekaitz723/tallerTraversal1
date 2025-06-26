#include "gast.h"
#include "gmst.h"
#include "EqnEquinox.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double gast(double Mjd_UT1)
{
    return fmod(gmst(Mjd_UT1) + EqnEquinox(Mjd_UT1), pi2);
}

void test_gast()
{
    const double pi = M_PI;
    
    // Test 1: J2000.0 epoca (MJD 51544.5 UT1)
    double gast_j2000 = gast(51544.5);
    
    // GAST debe estar en rango [0, 2π]
    assert(gast_j2000 >= 0.0);
    assert(gast_j2000 < pi2);
    
    // Test 2: Comparar con GMST - GAST = GMST + equation of equinoxes
    double gmst_j2000 = gmst(51544.5);
    double eqe_j2000 = EqnEquinox(51544.5);
    double gast_manual = fmod(gmst_j2000 + eqe_j2000, pi2);
    
    assert(fabs(gast_j2000 - gast_manual) < 1e-15);
    
    // Test 3: GAST debe ser muy cercano a GMST (equation of equinoxes es pequeña)
    double diff_gast_gmst = fabs(gast_j2000 - gmst_j2000);
    if (diff_gast_gmst > pi) diff_gast_gmst = pi2 - diff_gast_gmst;
    assert(diff_gast_gmst < 1e-3);  // Diferencia típica < 1 mrad (~3 arcsec)
    
    // Test 4: Epoca diferente - 2020
    double gast_2020 = gast(58849.0);  // 1 enero 2020
    
    assert(gast_2020 >= 0.0);
    assert(gast_2020 < pi2);
    
    // Test 5: Verificar que cambia con el tiempo
    double gast_1 = gast(51544.5);     // J2000.0
    double gast_2 = gast(52000.0);     // ~1.25 años después
    
    assert(fabs(gast_1 - gast_2) > 1e-6);
    
    // Test 6: Un día después . debe aumentar ~2π + pequeña corrección
    double gast_next_day = gast(51545.5);
    
    assert(gast_next_day >= 0.0);
    assert(gast_next_day < pi2);
    
    // Test 7: Medio día después . debe aumentar ~π radianes
    double gast_12h = gast(51545.0);
    double diff_12h = gast_12h - gast_j2000;
    if (diff_12h < 0) diff_12h += pi2;
    
    assert(fabs(diff_12h - pi) < 0.2);  // ~pi ± tolerancia
    
    // Test 8: Casos históricos
    double gast_1980 = gast(44239.0);   // 1980
    double gast_2050 = gast(69807.0);   // 2050
    
    assert(gast_1980 >= 0.0 && gast_1980 < pi2);
    assert(gast_2050 >= 0.0 && gast_2050 < pi2);
    
    // Test 9: Continuidad temporal - valores próximos
    double gast_base = gast(51544.5);
    double gast_close = gast(51544.500001);  // ~8.6 segundos después
    
    double diff_small = fabs(gast_close - gast_base);
    assert(diff_small < 1e-4);
    
    // Test 10: Verificar periodicidad aproximada (día sideral)
    double sidereal_day = 0.9972696;  // dias
    double gast_sideral = gast(51544.5 + sidereal_day);
    
    // Después de 1 día sideral, GAST debe ser muy similar
    double diff_sidereal = fabs(gast_sideral - gast_j2000);
    if (diff_sidereal > pi) diff_sidereal = pi2 - diff_sidereal;
    assert(diff_sidereal < 0.02);
    
    // Test 11: Comparación entre diferentes épocas
    double gast_morning = gast(51544.25);   // 6:00 UT
    double gast_evening = gast(51544.75);   // 18:00 UT
    
    double diff_12h_test = gast_evening - gast_morning;
    if (diff_12h_test < 0) diff_12h_test += pi2;
    
    assert(fabs(diff_12h_test - pi) < 0.1);
    
    // Test 12: Casos extremos temporales
    double gast_far_past = gast(20000.0);
    double gast_far_future = gast(80000.0);
    
    assert(gast_far_past >= 0.0 && gast_far_past < pi2);
    assert(gast_far_future >= 0.0 && gast_far_future < pi2);
    
    // Test 13: Verificar que no es NaN o infinito
    assert(!std::isnan(gast_j2000) && !std::isinf(gast_j2000));
    assert(!std::isnan(gast_2020) && !std::isinf(gast_2020));
}

REGISTER_TEST(test_gast);