#include "timediff.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void timediff(double UT1_UTC, double TAI_UTC, 
              double& UT1_TAI, double& UTC_GPS, double& UT1_GPS, 
              double& TT_UTC, double& GPS_UTC)
{
    const double TT_TAI = 32.184;   // TT-TAI time difference [s]
    const double GPS_TAI = -19.0;   // GPS-TAI time difference [s]
    
    double TT_GPS = TT_TAI - GPS_TAI;    // TT-GPS time difference [s]
    double TAI_GPS = -GPS_TAI;           // TAI-GPS time difference [s]
    
    UT1_TAI = UT1_UTC - TAI_UTC;         // UT1-TAI time difference [s]
    
    double UTC_TAI = -TAI_UTC;           // UTC-TAI time difference [s]
    
    UTC_GPS = UTC_TAI - GPS_TAI;         // UTC-GPS time difference [s]
    
    UT1_GPS = UT1_TAI - GPS_TAI;         // UT1-GPS time difference [s]
    
    TT_UTC = TT_TAI - UTC_TAI;           // TT-UTC time difference [s]
    
    GPS_UTC = GPS_TAI - UTC_TAI;         // GPS-UTC time difference [s]
}

void test_timediff()
{
    // Test 1: Valores típicos de enero 2020 (TAI-UTC = 37 segundos)
    double UT1_UTC_1 = -0.1845612;  // UT1-UTC típico
    double TAI_UTC_1 = 37.0;        // TAI-UTC en enero 2020
    
    double UT1_TAI_1, UTC_GPS_1, UT1_GPS_1, TT_UTC_1, GPS_UTC_1;
    timediff(UT1_UTC_1, TAI_UTC_1, UT1_TAI_1, UTC_GPS_1, UT1_GPS_1, TT_UTC_1, GPS_UTC_1);
    
    // Verificar constantes conocidas
    assert(fabs(TT_UTC_1 - 69.184) < 1e-12);  // TT-UTC = 32.184 + 37 = 69.184
    assert(fabs(UTC_GPS_1 + 18.0) < 1e-12);   // UTC-GPS = -37 - (-19) = -18
    assert(fabs(GPS_UTC_1 - 18.0) < 1e-12);   // GPS-UTC = -19 - (-37) = 18
    
    // Verificar relaciones matemáticas
    assert(fabs(UT1_TAI_1 - (UT1_UTC_1 - TAI_UTC_1)) < 1e-12);
    assert(fabs(UT1_GPS_1 - (UT1_TAI_1 - (-19.0))) < 1e-12);
    
    // Test 2: Valor histórico de 1980 cuando GPS comenzó (TAI-UTC = 19 segundos)
    double UT1_UTC_2 = 0.0;    // Aproximación para prueba
    double TAI_UTC_2 = 19.0;   // TAI-UTC en 1980
    
    double UT1_TAI_2, UTC_GPS_2, UT1_GPS_2, TT_UTC_2, GPS_UTC_2;
    timediff(UT1_UTC_2, TAI_UTC_2, UT1_TAI_2, UTC_GPS_2, UT1_GPS_2, TT_UTC_2, GPS_UTC_2);
    
    assert(fabs(TT_UTC_2 - 51.184) < 1e-12);  // TT-UTC = 32.184 + 19 = 51.184
    assert(fabs(UTC_GPS_2 - 0.0) < 1e-12);    // UTC-GPS = -19 - (-19) = 0
    assert(fabs(GPS_UTC_2 - 0.0) < 1e-12);    // GPS-UTC = -19 - (-19) = 0
    
    // Test 3: Verificar que TT-TAI = 32.184 siempre se mantiene
    double UT1_UTC_3 = 0.5;
    double TAI_UTC_3 = 25.0;
    
    double UT1_TAI_3, UTC_GPS_3, UT1_GPS_3, TT_UTC_3, GPS_UTC_3;
    timediff(UT1_UTC_3, TAI_UTC_3, UT1_TAI_3, UTC_GPS_3, UT1_GPS_3, TT_UTC_3, GPS_UTC_3);
    
    double implied_TT_TAI = TT_UTC_3 - TAI_UTC_3;
    assert(fabs(implied_TT_TAI - 32.184) < 1e-12);
    
    // Test 4: Verificar que GPS-TAI = -19.0 siempre se mantiene
    double implied_GPS_TAI = GPS_UTC_3 - TAI_UTC_3;
    assert(fabs(implied_GPS_TAI + 19.0) < 1e-12);
    
    // Test 5: Casos con valores fraccionarios típicos
    double UT1_UTC_5 = -0.234567;
    double TAI_UTC_5 = 37.0;
    
    double UT1_TAI_5, UTC_GPS_5, UT1_GPS_5, TT_UTC_5, GPS_UTC_5;
    timediff(UT1_UTC_5, TAI_UTC_5, UT1_TAI_5, UTC_GPS_5, UT1_GPS_5, TT_UTC_5, GPS_UTC_5);
    
    assert(fabs(UT1_TAI_5 - (-37.234567)) < 1e-12);
    assert(fabs(UT1_GPS_5 - (-18.234567)) < 1e-12);
    
    // Test 6: Verificar consistencia de signos y relaciones cruzadas
    // UT1_TAI = UT1_UTC - TAI_UTC
    assert(fabs(UT1_TAI_5 - (UT1_UTC_5 - TAI_UTC_5)) < 1e-12);
    
    // TT_UTC = TT_TAI - UTC_TAI = 32.184 - (-TAI_UTC) = 32.184 + TAI_UTC
    assert(fabs(TT_UTC_5 - (32.184 + TAI_UTC_5)) < 1e-12);
    
    // UTC_GPS = UTC_TAI - GPS_TAI = -TAI_UTC - (-19) = 19 - TAI_UTC
    assert(fabs(UTC_GPS_5 - (19.0 - TAI_UTC_5)) < 1e-12);
    
    // GPS_UTC = GPS_TAI - UTC_TAI = -19 - (-TAI_UTC) = TAI_UTC - 19
    assert(fabs(GPS_UTC_5 - (TAI_UTC_5 - 19.0)) < 1e-12);
    
    // Test 7: Caso extremo con TAI_UTC muy grande (futuro lejano)
    double UT1_UTC_7 = 0.1;
    double TAI_UTC_7 = 100.0;  // Muchos leap seconds en el futuro
    
    double UT1_TAI_7, UTC_GPS_7, UT1_GPS_7, TT_UTC_7, GPS_UTC_7;
    timediff(UT1_UTC_7, TAI_UTC_7, UT1_TAI_7, UTC_GPS_7, UT1_GPS_7, TT_UTC_7, GPS_UTC_7);
    
    assert(fabs(TT_UTC_7 - 132.184) < 1e-12);   // 32.184 + 100
    assert(fabs(UTC_GPS_7 - (-81.0)) < 1e-12);  // 19 - 100 = -81
    assert(fabs(GPS_UTC_7 - 81.0) < 1e-12);     // 100 - 19 = 81
    
    // Test 8: Verificar que todas las diferencias están en segundos y son razonables
    assert(fabs(UT1_TAI_7) < 200.0);
    assert(fabs(UTC_GPS_7) < 200.0);
    assert(fabs(UT1_GPS_7) < 200.0);
    assert(fabs(TT_UTC_7) < 200.0);
    assert(fabs(GPS_UTC_7) < 200.0);
}

REGISTER_TEST(test_timediff);