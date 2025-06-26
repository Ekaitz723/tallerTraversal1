#include "../include/Mjday.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

/*
 %--------------------------------------------------------------------------
 %  inputs:
 %    year        - year
 %    mon         - month
 %    day         - day
 %    hr          - universal time hour
 %    min         - universal time min
 %    sec         - universal time sec
 %
 %  output:
 %    Mjd         - Modified julian date
 %--------------------------------------------------------------------------
*/

double Mjday(int yr, int mon, int day, int hr, int min, double sec)
{
    double jd, Mjd;
	
    jd = 367.0 * yr - floor( (7 * (yr + floor( (mon + 9) / 12.0) ) ) * 0.25 )
	+ floor( 275 * mon / 9.0 ) + day + 1721013.5 + ( (sec/60.0 + min ) / 60.0 + hr ) / 24.0;

	Mjd = jd-2400000.5;

	return Mjd;
}

void test_Mjday()
{
    // Test 1: Epoch J2000.0 (1 enero 2000, 12:00:00 UTC) = MJD 51544.5
    double mjd1 = Mjday(2000, 1, 1, 12, 0, 0.0);
    assert(fabs(mjd1 - 51544.5) < 1e-10);
    
    // Test 2: Unix Epoch (1 enero 1970, 00:00:00 UTC) = MJD 40587.0
    double mjd2 = Mjday(1970, 1, 1, 0, 0, 0.0);
    assert(fabs(mjd2 - 40587.0) < 1e-10);
    
    // Test 3: Fecha conocida (1 enero 1900, 00:00:00 UTC) = MJD 15019.0
    double mjd3 = Mjday(1900, 1, 1, 0, 0, 0.0);
    assert(fabs(mjd3 - 15019.0) < 1e-10);
    
    // Test 4: Verificar que diferentes horas del mismo dia dan incrementos correctos
    double mjd4a = Mjday(2000, 1, 1, 0, 0, 0.0);  // Medianoche
    double mjd4b = Mjday(2000, 1, 1, 6, 0, 0.0);  // 6 AM
    double mjd4c = Mjday(2000, 1, 1, 18, 0, 0.0); // 6 PM
    
    assert(fabs((mjd4b - mjd4a) - 0.25) < 1e-10);  // 6 horas = 0.25 dias
    assert(fabs((mjd4c - mjd4a) - 0.75) < 1e-10);  // 18 horas = 0.75 dias
    
    // Test 5: Verificar minutos y segundos
    double mjd5a = Mjday(2000, 1, 1, 0, 0, 0.0);
    double mjd5b = Mjday(2000, 1, 1, 0, 30, 0.0);   // 30 minutos
    double mjd5c = Mjday(2000, 1, 1, 0, 0, 3600.0); // 1 hora en segundos
    
    assert(fabs((mjd5b - mjd5a) - (30.0/1440.0)) < 5e-2); // 30 min = 30/1440 dias
    assert(fabs((mjd5c - mjd5a) - (1.0/24.0)) < 5e-2);    // 1 hora = 1/24 dias
    
    // Test 6: Año bisiesto - verificar 29 febrero 2000
    double mjd6a = Mjday(2000, 2, 28, 0, 0, 0.0);
    double mjd6b = Mjday(2000, 2, 29, 0, 0, 0.0);
    double mjd6c = Mjday(2000, 3, 1, 0, 0, 0.0);
    
    assert(fabs((mjd6b - mjd6a) - 1.0) < 1e-10);  // 1 dia de diferencia
    assert(fabs((mjd6c - mjd6b) - 1.0) < 1e-10);  // 1 dia de diferencia
    
    // Test 7: Cambio de año
    double mjd7a = Mjday(1999, 12, 31, 23, 59, 59.0);
    double mjd7b = Mjday(2000, 1, 1, 0, 0, 0.0);
    
    assert(mjd7b > mjd7a);  // Debe ser mayor
    assert(fabs((mjd7b - mjd7a) - (1.0/86400.0)) < 1e-8); // 1 segundo = 1/86400 dias
    
    // Test 8: Fechas en diferentes meses
    double mjd8a = Mjday(2000, 6, 15, 12, 0, 0.0);  // Junio
    double mjd8b = Mjday(2000, 12, 15, 12, 0, 0.0); // Diciembre
    
    assert(mjd8b > mjd8a);  // Diciembre debe ser mayor que junio
    assert((mjd8b - mjd8a) > 180.0);  // Mas de 180 dias de diferencia
}

REGISTER_TEST(test_Mjday);