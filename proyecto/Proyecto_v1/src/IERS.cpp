#include "IERS.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <stdexcept>

void IERS(const Matrix& eop, double Mjd_UTC, char interp,
          double& x_pole, double& y_pole, double& UT1_UTC, double& LOD,
          double& dpsi, double& deps, double& dx_pole, double& dy_pole, double& TAI_UTC)
{
    int mjd = (int)floor(Mjd_UTC);
    
    Matrix mjd_row = Matrix::extract_row(eop, 4);
    
    int i = -1;
    for (int j = 1; j <= mjd_row.size(); j++) {
        if ((int)mjd_row(j) == mjd) {
            i = j;
            break;
        }
    }
    
    if (i == -1) {
        throw std::runtime_error("MJD not found in EOP data");
    }
    
    if (interp == 'l') {
        if (i >= mjd_row.size()) {
            throw std::runtime_error("Cannot interpolate: no next EOP data point");
        }
        
        double mfme = 1440.0 * (Mjd_UTC - floor(Mjd_UTC));
        double fixf = mfme / 1440.0;
        
        x_pole  = eop(5, i) + (eop(5, i+1) - eop(5, i)) * fixf;
        y_pole  = eop(6, i) + (eop(6, i+1) - eop(6, i)) * fixf;
        UT1_UTC = eop(7, i) + (eop(7, i+1) - eop(7, i)) * fixf;
        LOD     = eop(8, i) + (eop(8, i+1) - eop(8, i)) * fixf;
        dpsi    = eop(9, i) + (eop(9, i+1) - eop(9, i)) * fixf;
        deps    = eop(10, i) + (eop(10, i+1) - eop(10, i)) * fixf;
        dx_pole = eop(11, i) + (eop(11, i+1) - eop(11, i)) * fixf;
        dy_pole = eop(12, i) + (eop(12, i+1) - eop(12, i)) * fixf;
        TAI_UTC = eop(13, i);
        
        // arcsegundos -> radianes
        x_pole  = x_pole / Arcs;
        y_pole  = y_pole / Arcs;
        dpsi    = dpsi / Arcs;
        deps    = deps / Arcs;
        dx_pole = dx_pole / Arcs;
        dy_pole = dy_pole / Arcs;
        
    } else { // interp == 'n' (sin interpolacion)
        
        x_pole  = eop(5, i) / Arcs;
        y_pole  = eop(6, i) / Arcs;
        UT1_UTC = eop(7, i);
        LOD     = eop(8, i);
        dpsi    = eop(9, i) / Arcs;
        deps    = eop(10, i) / Arcs;
        dx_pole = eop(11, i) / Arcs;
        dy_pole = eop(12, i) / Arcs;
        TAI_UTC = eop(13, i);
    }
}

void test_IERS()
{
    // Crear matriz EOP manualmente columna por columna //se ve transpuesta en eop_data[] respecto a eop
    double eop_data[13*3] = {
        // Columna 1: MJD 58849.0 (1 enero 2020)
        2020, 1, 1, 58849.0, 0.035312, 0.320328, -0.1845612, 0.0013, -0.052, -0.007, 0.000, 0.000, 37.0,
        // Columna 2: MJD 58850.0 (2 enero 2020)  
        2020, 1, 2, 58850.0, 0.034156, 0.319142, -0.1856789, 0.0012, -0.053, -0.008, 0.000, 0.000, 37.0,
        // Columna 3: MJD 58851.0 (3 enero 2020)
        2020, 1, 3, 58851.0, 0.033001, 0.317956, -0.1867966, 0.0011, -0.054, -0.009, 0.000, 0.000, 37.0
    };
    
    Matrix eop(13, 3, eop_data, 13*3);
    // eop.print();

    // Matrix eop(13, 3);
    
    // // Día 1: MJD 58849.0 (1 enero 2020)
    // eop(1,1) = 2020; eop(2,1) = 1; eop(3,1) = 1; eop(4,1) = 58849.0;
    // eop(5,1) = 0.035312; eop(6,1) = 0.320328; eop(7,1) = -0.1845612; eop(8,1) = 0.0013;
    // eop(9,1) = -0.052; eop(10,1) = -0.007; eop(11,1) = 0.000; eop(12,1) = 0.000; eop(13,1) = 37.0;
    
    // // Día 2: MJD 58850.0 (2 enero 2020)
    // eop(1,2) = 2020; eop(2,2) = 1; eop(3,2) = 2; eop(4,2) = 58850.0;
    // eop(5,2) = 0.034156; eop(6,2) = 0.319142; eop(7,2) = -0.1856789; eop(8,2) = 0.0012;
    // eop(9,2) = -0.053; eop(10,2) = -0.008; eop(11,2) = 0.000; eop(12,2) = 0.000; eop(13,2) = 37.0;
    
    // // Día 3: MJD 58851.0 (3 enero 2020)
    // eop(1,3) = 2020; eop(2,3) = 1; eop(3,3) = 3; eop(4,3) = 58851.0;
    // eop(5,3) = 0.033001; eop(6,3) = 0.317956; eop(7,3) = -0.1867966; eop(8,3) = 0.0011;
    // eop(9,3) = -0.054; eop(10,3) = -0.009; eop(11,3) = 0.000; eop(12,3) = 0.000; eop(13,3) = 37.0;
    
    // // eop.print();

    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    
    // Test sin interpolacion - día exacto
    IERS(eop, 58849.0, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    assert(fabs(x_pole - 0.035312/Arcs) < 1e-12);
    assert(fabs(y_pole - 0.320328/Arcs) < 1e-12);
    assert(fabs(UT1_UTC - (-0.1845612)) < 1e-12);
    assert(fabs(LOD - 0.0013) < 1e-12);
    assert(fabs(TAI_UTC - 37.0) < 1e-12);
    
    // Test interpolacion lineal - media día
    IERS(eop, 58849.5, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    // Valores interpolados manualmente: (valor1 + valor2) / 2
    double x_pole_expected = (0.035312 + 0.034156) / 2.0 / Arcs;
    double y_pole_expected = (0.320328 + 0.319142) / 2.0 / Arcs;
    double UT1_UTC_expected = (-0.1845612 + -0.1856789) / 2.0;
    
    assert(fabs(x_pole - x_pole_expected) < 1e-12);
    assert(fabs(y_pole - y_pole_expected) < 1e-12);
    assert(fabs(UT1_UTC - UT1_UTC_expected) < 1e-12);
    assert(fabs(TAI_UTC - 37.0) < 1e-12);
    
    // Test interpolacion con fraccion diferente (0.75 del primer día)
    IERS(eop, 58849.75, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    double fixf = 0.75;
    double x_pole_expected_75 = (0.035312 + (0.034156 - 0.035312) * fixf) / Arcs;
    assert(fabs(x_pole - x_pole_expected_75) < 1e-12);
    
    // Test segundo día exacto
    IERS(eop, 58850.0, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    assert(fabs(x_pole - 0.034156/Arcs) < 1e-12);
    assert(fabs(UT1_UTC - (-0.1856789)) < 1e-12);
    
    // Test nutacion y conversion a radianes
    IERS(eop, 58849.0, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    assert(fabs(dpsi - (-0.052)/Arcs) < 1e-12);
    assert(fabs(deps - (-0.007)/Arcs) < 1e-12);
    
    // Test excepciones
    bool exception_thrown = false;
    try {
        IERS(eop, 58900.0, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    // Test interpolacion sin datos siguientes
    exception_thrown = false;
    try {
        IERS(eop, 58851.5, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    // Test valores dentro de rangos razonables
    IERS(eop, 58849.0, 'n', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    
    assert(fabs(x_pole) < 1e-5);  // x_pole típicamente < 1 arcsec ~ 5e-6 rad
    assert(fabs(y_pole) < 1e-5);  // y_pole similar
    assert(fabs(UT1_UTC) < 1.0);  // UT1-UTC típicamente entre -0.9 y +0.9 s
    assert(fabs(LOD) < 0.01);     // LOD típicamente pocos milisegundos
    assert(TAI_UTC > 0.0);        // TAI-UTC siempre positivo (leap seconds)
}

REGISTER_TEST(test_IERS);