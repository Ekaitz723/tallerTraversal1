#include "EqnEquinox.h"
#include "NutAngles.h"
#include "MeanObliquity.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double EqnEquinox(double Mjd_TT)
{
    double dpsi, deps;
    
    NutAngles(Mjd_TT, dpsi, deps);
    
    double EqE = dpsi * cos(MeanObliquity(Mjd_TT));
    
    return EqE;
}

void test_EqnEquinox()
{
    // Test 1: J2000.0 epoch (MJD 51544.5)
    double eqe_j2000 = EqnEquinox(51544.5);
    
    // La ecuacion de los equinoccios en J2000 debe ser pequeña
    assert(fabs(eqe_j2000) < 1e-4);  // Menos de ~20 arcseg
    
    // Test 2: Verificar que está en rango típico
    // La ecuacion de equinoccios tipicamente varia ±1 arcseg (~±5e-6 rad)
    assert(fabs(eqe_j2000) < 1e-3);  // Rango conservador
    
    // Test 3: Epoca diferente - 1 año despues de J2000
    double eqe_2001 = EqnEquinox(51910.0);  // ~1 año = 365.25 dias
    
    assert(fabs(eqe_2001) < 1e-3);
    
    // Test 4: Verificar que cambia con el tiempo
    double eqe_1 = EqnEquinox(51544.5);      // J2000.0
    double eqe_2 = EqnEquinox(52000.0);      // ~1.25 años despues
    
    // Los valores deben ser diferentes debido al movimiento lunar/solar
    assert(fabs(eqe_1 - eqe_2) > 1e-10);
    
    // Test 5: Epoca historica - 1980
    double eqe_1980 = EqnEquinox(44239.0);   // 1 enero 1980
    
    assert(fabs(eqe_1980) < 1e-3);
    
    // Test 6: Epoca futura - 2050
    double eqe_2050 = EqnEquinox(69807.0);   // ~1 enero 2050
    
    assert(fabs(eqe_2050) < 1e-3);
    
    // Test 7: Verificar periodicidad aproximada (18.6 años = ciclo principal nutacion)
    double periodo_dias = 18.6 * 365.25;
    double eqe_inicio = EqnEquinox(51544.5);
    double eqe_ciclo = EqnEquinox(51544.5 + periodo_dias);
    
    // Deberian estar relativamente cerca debido al ciclo principal
    assert(fabs(eqe_inicio - eqe_ciclo) < 5e-5);
    
    // Test 8: Casos con T negativo (antes de J2000)
    double eqe_pasado = EqnEquinox(45000.0);  // T negativo grande
    
    assert(fabs(eqe_pasado) < 1e-3);
    
    // Test 9: Verificar comportamiento con casos extremos
    double eqe_futuro = EqnEquinox(100000.0);
    
    assert(fabs(eqe_futuro) < 1e-2);  // Rango mas amplio para casos extremos
    
    // Test 10: Verificar que dpsi*cos(eps) esta implementado correctamente
    double dpsi_test, deps_test;
    NutAngles(52000.0, dpsi_test, deps_test);
    double eps_test = MeanObliquity(52000.0);
    double eqe_manual = dpsi_test * cos(eps_test);
    double eqe_function = EqnEquinox(52000.0);
    
    assert(fabs(eqe_manual - eqe_function) < 1e-15);
    
    // Test 11: Verificar que el signo es correcto
    // La ecuacion puede ser positiva o negativa según la epoca
    double eqe_test = EqnEquinox(52500.0);
    
    assert(!std::isnan(eqe_test) && !std::isinf(eqe_test));
}

REGISTER_TEST(test_EqnEquinox);