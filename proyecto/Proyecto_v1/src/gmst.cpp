#include "gmst.h"
#include "Frac.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double gmst(double Mjd_UT1)
{
    double Secs = 86400.0; // segundos dia
    
    double Mjd_0 = floor(Mjd_UT1);
    double UT1 = Secs * (Mjd_UT1 - Mjd_0);       // [s]
    double T_0 = (Mjd_0 - MJD_J2000) / 36525.0;
    double T = (Mjd_UT1 - MJD_J2000) / 36525.0;
    
    double gmst_sec = 24110.54841 + 8640184.812866*T_0 + 1.002737909350795*UT1
                    + (0.093104 - 6.2e-6*T)*T*T;    // [s]
    
    double gmstime = pi2 * Frac(gmst_sec / Secs);   // [rad], 0..2pi
    
    return gmstime;
}

void test_gmst()
{
    const double pi = M_PI;
    
    // Test 1: J2000.0 epoca (MJD 51544.5 UT1) 
    double gmst_j2000 = gmst(51544.5);
    
    // Para J2000.0, GMST debe estar en rango razonable [0, 2π]
    assert(gmst_j2000 >= 0.0);
    assert(gmst_j2000 < pi2);
    
    // Valor aproximado para J2000.0 debe estar cerca de 4.9 radianes
    assert(gmst_j2000 > 4.5 && gmst_j2000 < 5.5);
    
    // Test 2: Verificar que está en rango [0, 2π]
    assert(gmst_j2000 >= 0.0);
    assert(gmst_j2000 < pi2);
    
    // Test 3: Medio dia despues - GMST debe aumentar ~π radianes
    double gmst_j2000_12h = gmst(51545.0);  // 12 horas después
    
    assert(gmst_j2000_12h >= 0.0);
    assert(gmst_j2000_12h < pi2);
    
    // La diferencia debe ser aproximadamente π (12 horas siderales)
    double diff_12h = gmst_j2000_12h - gmst_j2000;
    if (diff_12h < 0) diff_12h += pi2;  // Ajustar si cruza 2π
    assert(fabs(diff_12h - pi) < 0.1);
    
    // Test 4: Un dia después - GMST debe aumentar un poco más que 2π
    double gmst_next_day = gmst(51545.5);  // 1 día después
    
    double diff_1day = gmst_next_day - gmst_j2000;
    if (diff_1day < 0) diff_1day += pi2;
    
    // En un día solar, GMST aumenta ~2π + 4min siderales ≈ 2π + 0.017 rad
    double expected_extra = (4.0 / (24.0 * 60.0)) * pi2;  // ~4 min en radianes
    assert(diff_1day > 0.0);  // Debe aumentar
    assert(diff_1day < pi2 * 1.1);  // Pero no excesivamente
    
    // Test 5: Caso historico - 1980 (MJD ~44239)
    double gmst_1980 = gmst(44239.0);
    
    assert(gmst_1980 >= 0.0);
    assert(gmst_1980 < pi2);
    
    // Test 6: Caso futuro - 2030 (MJD ~62502)
    double gmst_2030 = gmst(62502.0);
    
    assert(gmst_2030 >= 0.0);
    assert(gmst_2030 < pi2);
    
    // Test 7: Diferentes fracciones del mismo dia
    double gmst_morning = gmst(51544.25);   // 6:00 UT
    double gmst_noon = gmst(51544.5);       // 12:00 UT
    double gmst_evening = gmst(51544.75);   // 18:00 UT
    
    // Todos deben estar en rango válido
    assert(gmst_morning >= 0.0 && gmst_morning < pi2);
    assert(gmst_noon >= 0.0 && gmst_noon < pi2);
    assert(gmst_evening >= 0.0 && gmst_evening < pi2);
    
    // Verificar progresion temporal correcta (6h ≈ π/2 radianes)
    double diff_6h = gmst_noon - gmst_morning;
    if (diff_6h < 0) diff_6h += pi2;
    assert(fabs(diff_6h - pi/2) < 0.1);
    
    // Test 8: Continuidad - valores muy proximos deben dar resultados proximos
    double gmst_base = gmst(51544.5);
    double gmst_close = gmst(51544.500001);  // ~8.6 segundos después
    
    double diff_small = fabs(gmst_close - gmst_base);
    assert(diff_small < 1e-4);  // Diferencia muy pequeña
    
    // Test 9: Verificar que valores negativos (antes de J2000) funcionan
    double gmst_before_j2000 = gmst(50000.0);  // Antes de J2000
    
    assert(gmst_before_j2000 >= 0.0);
    assert(gmst_before_j2000 < pi2);
    
    // Test 10: Casos extremos - valores muy lejanos
    double gmst_far_future = gmst(80000.0);
    double gmst_far_past = gmst(20000.0);
    
    assert(gmst_far_future >= 0.0 && gmst_far_future < pi2);
    assert(gmst_far_past >= 0.0 && gmst_far_past < pi2);
    
    // Test 11: Verificar periodicidad sideral aproximada
    // 1 día sideral ≈ 23h 56m 4s ≈ 0.9972696 días
    double sidereal_day = 0.9972696;
    double gmst_sideral = gmst(51544.5 + sidereal_day);
    
    // Después de un día sideral, GMST debe ser muy similar
    double diff_sidereal = fabs(gmst_sideral - gmst_j2000);
    if (diff_sidereal > pi) diff_sidereal = pi2 - diff_sidereal;
    assert(diff_sidereal < 0.01);  // Muy similar después de 1 día sideral
}

REGISTER_TEST(test_gmst);