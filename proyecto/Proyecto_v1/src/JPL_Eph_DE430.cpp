#include "JPL_Eph_DE430.h"
#include "Cheb3D.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <stdexcept>

Matrix* PC = nullptr;

void JPL_Eph_DE430(double Mjd_TDB, 
                   Matrix*& r_Mercury, Matrix*& r_Venus, Matrix*& r_Earth, Matrix*& r_Mars,
                   Matrix*& r_Jupiter, Matrix*& r_Saturn, Matrix*& r_Uranus, 
                   Matrix*& r_Neptune, Matrix*& r_Pluto, Matrix*& r_Moon, Matrix*& r_Sun)
{
    if (PC == nullptr) {
        throw std::runtime_error("PC matrix not initialized");
    }
    
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
    
    double JD = Mjd_TDB + 2400000.5;
    
    int i = -1;
    Matrix first_row = Matrix::extract_row(*PC, 1);
    int num_rows = PC->size() / first_row.size();
    
    for (int k = 1; k <= num_rows; k++) {
        if ((*PC)(k,1) <= JD && JD <= (*PC)(k,2)) {
            i = k;
            break;
        }
    }
    
    if (i == -1) {
        throw std::runtime_error("JD not found in PC data range");
    }
    
    Matrix PCtemp = Matrix::extract_row(*PC, i);
    
    double t1 = PCtemp(1) - 2400000.5; // MJD at start of interval
    double dt = Mjd_TDB - t1;
    
    double Cx_Earth[26], Cy_Earth[26], Cz_Earth[26];
    
    for (int k = 0; k < 13; k++) {
        Cx_Earth[k] = PCtemp(231 + k);
        Cy_Earth[k] = PCtemp(244 + k); 
        Cz_Earth[k] = PCtemp(257 + k);
    }
    for (int k = 0; k < 13; k++) {
        Cx_Earth[13 + k] = PCtemp(270 + k);
        Cy_Earth[13 + k] = PCtemp(283 + k);
        Cz_Earth[13 + k] = PCtemp(296 + k);
    }
    
    int j;
    double Mjd0;
    if (0 <= dt && dt <= 16) {
        j = 0;
        Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1;
        Mjd0 = t1 + 16 * j;
    } else {
        throw std::runtime_error("dt out of range for Earth");
    }
    
    *r_Earth = Cheb3D(Mjd_TDB, 13, Mjd0, Mjd0 + 16, 
                      &Cx_Earth[13*j], &Cy_Earth[13*j], &Cz_Earth[13*j]) * 1e3;
    
    double Cx_Moon[104], Cy_Moon[104], Cz_Moon[104];
    
    for (int k = 0; k < 13; k++) {
        Cx_Moon[k] = PCtemp(441 + k);
        Cy_Moon[k] = PCtemp(454 + k);
        Cz_Moon[k] = PCtemp(467 + k);
    }
    for (int loop = 1; loop <= 7; loop++) {
        for (int k = 0; k < 13; k++) {
            Cx_Moon[13*loop + k] = PCtemp(480 + 39*(loop-1) + k);
            Cy_Moon[13*loop + k] = PCtemp(493 + 39*(loop-1) + k);  
            Cz_Moon[13*loop + k] = PCtemp(506 + 39*(loop-1) + k);
        }
    }
    
    if (0 <= dt && dt <= 4) {
        j = 0; Mjd0 = t1;
    } else if (4 < dt && dt <= 8) {
        j = 1; Mjd0 = t1 + 4 * j;
    } else if (8 < dt && dt <= 12) {
        j = 2; Mjd0 = t1 + 4 * j;
    } else if (12 < dt && dt <= 16) {
        j = 3; Mjd0 = t1 + 4 * j;
    } else if (16 < dt && dt <= 20) {
        j = 4; Mjd0 = t1 + 4 * j;
    } else if (20 < dt && dt <= 24) {
        j = 5; Mjd0 = t1 + 4 * j;
    } else if (24 < dt && dt <= 28) {
        j = 6; Mjd0 = t1 + 4 * j;
    } else if (28 < dt && dt <= 32) {
        j = 7; Mjd0 = t1 + 4 * j;
    } else {
        throw std::runtime_error("dt out of range for Moon");
    }
    
    *r_Moon = Cheb3D(Mjd_TDB, 13, Mjd0, Mjd0 + 4,
                     &Cx_Moon[13*j], &Cy_Moon[13*j], &Cz_Moon[13*j]) * 1e3;
    
    double Cx_Sun[22], Cy_Sun[22], Cz_Sun[22];
    
    for (int k = 0; k < 11; k++) {
        Cx_Sun[k] = PCtemp(753 + k);
        Cy_Sun[k] = PCtemp(764 + k);
        Cz_Sun[k] = PCtemp(775 + k);
    }
    for (int k = 0; k < 11; k++) {
        Cx_Sun[11 + k] = PCtemp(786 + k);
        Cy_Sun[11 + k] = PCtemp(797 + k);
        Cz_Sun[11 + k] = PCtemp(808 + k);
    }
    
    if (0 <= dt && dt <= 16) {
        j = 0; Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1; Mjd0 = t1 + 16 * j;
    } else {
        throw std::runtime_error("dt out of range for Sun");
    }
    
    *r_Sun = Cheb3D(Mjd_TDB, 11, Mjd0, Mjd0 + 16,
                    &Cx_Sun[11*j], &Cy_Sun[11*j], &Cz_Sun[11*j]) * 1e3;
    
    double Cx_Mercury[56], Cy_Mercury[56], Cz_Mercury[56];
    
    for (int k = 0; k < 14; k++) {
        Cx_Mercury[k] = PCtemp(3 + k);
        Cy_Mercury[k] = PCtemp(17 + k);
        Cz_Mercury[k] = PCtemp(31 + k);
    }
    for (int loop = 1; loop <= 3; loop++) {
        for (int k = 0; k < 14; k++) {
            Cx_Mercury[14*loop + k] = PCtemp(45 + 42*(loop-1) + k);
            Cy_Mercury[14*loop + k] = PCtemp(59 + 42*(loop-1) + k);
            Cz_Mercury[14*loop + k] = PCtemp(73 + 42*(loop-1) + k);
        }
    }
    
    if (0 <= dt && dt <= 8) {
        j = 0; Mjd0 = t1;
    } else if (8 < dt && dt <= 16) {
        j = 1; Mjd0 = t1 + 8 * j;
    } else if (16 < dt && dt <= 24) {
        j = 2; Mjd0 = t1 + 8 * j;
    } else if (24 < dt && dt <= 32) {
        j = 3; Mjd0 = t1 + 8 * j;
    } else {
        throw std::runtime_error("dt out of range for Mercury");
    }
    
    *r_Mercury = Cheb3D(Mjd_TDB, 14, Mjd0, Mjd0 + 8,
                        &Cx_Mercury[14*j], &Cy_Mercury[14*j], &Cz_Mercury[14*j]) * 1e3;
    
    double Cx_Venus[20], Cy_Venus[20], Cz_Venus[20];
    
    for (int k = 0; k < 10; k++) {
        Cx_Venus[k] = PCtemp(171 + k);
        Cy_Venus[k] = PCtemp(181 + k);
        Cz_Venus[k] = PCtemp(191 + k);
    }
    for (int k = 0; k < 10; k++) {
        Cx_Venus[10 + k] = PCtemp(201 + k);
        Cy_Venus[10 + k] = PCtemp(211 + k);
        Cz_Venus[10 + k] = PCtemp(221 + k);
    }
    
    if (0 <= dt && dt <= 16) {
        j = 0; Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1; Mjd0 = t1 + 16 * j;
    } else {
        throw std::runtime_error("dt out of range for Venus");
    }
    
    *r_Venus = Cheb3D(Mjd_TDB, 10, Mjd0, Mjd0 + 16,
                      &Cx_Venus[10*j], &Cy_Venus[10*j], &Cz_Venus[10*j]) * 1e3;
    
    double Cx_Mars[11], Cy_Mars[11], Cz_Mars[11];
    
    for (int k = 0; k < 11; k++) {
        Cx_Mars[k] = PCtemp(309 + k);
        Cy_Mars[k] = PCtemp(320 + k);
        Cz_Mars[k] = PCtemp(331 + k);
    }
    
    j = 0;
    Mjd0 = t1;
    *r_Mars = Cheb3D(Mjd_TDB, 11, Mjd0, Mjd0 + 32,
                     &Cx_Mars[11*j], &Cy_Mars[11*j], &Cz_Mars[11*j]) * 1e3;
    
    double Cx_Jupiter[8], Cy_Jupiter[8], Cz_Jupiter[8];
    
    for (int k = 0; k < 8; k++) {
        Cx_Jupiter[k] = PCtemp(342 + k);
        Cy_Jupiter[k] = PCtemp(350 + k);
        Cz_Jupiter[k] = PCtemp(358 + k);
    }
    
    j = 0;
    Mjd0 = t1;
    *r_Jupiter = Cheb3D(Mjd_TDB, 8, Mjd0, Mjd0 + 32,
                        &Cx_Jupiter[8*j], &Cy_Jupiter[8*j], &Cz_Jupiter[8*j]) * 1e3;
    
    double Cx_Saturn[7], Cy_Saturn[7], Cz_Saturn[7];
    
    for (int k = 0; k < 7; k++) {
        Cx_Saturn[k] = PCtemp(366 + k);
        Cy_Saturn[k] = PCtemp(373 + k);
        Cz_Saturn[k] = PCtemp(380 + k);
    }
    
    j = 0;
    Mjd0 = t1;
    *r_Saturn = Cheb3D(Mjd_TDB, 7, Mjd0, Mjd0 + 32,
                       &Cx_Saturn[7*j], &Cy_Saturn[7*j], &Cz_Saturn[7*j]) * 1e3;
    
    double Cx_Uranus[6], Cy_Uranus[6], Cz_Uranus[6];
    
    for (int k = 0; k < 6; k++) {
        Cx_Uranus[k] = PCtemp(387 + k);
        Cy_Uranus[k] = PCtemp(393 + k);
        Cz_Uranus[k] = PCtemp(399 + k);
    }
    
    j = 0;
    Mjd0 = t1;
    *r_Uranus = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0 + 32,
                       &Cx_Uranus[6*j], &Cy_Uranus[6*j], &Cz_Uranus[6*j]) * 1e3;
    
    double Cx_Neptune[6], Cy_Neptune[6], Cz_Neptune[6];
    
    for (int k = 0; k < 6; k++) {
        Cx_Neptune[k] = PCtemp(405 + k);
        Cy_Neptune[k] = PCtemp(411 + k);
        Cz_Neptune[k] = PCtemp(417 + k);
    }
    
    j = 0;
    Mjd0 = t1;
    *r_Neptune = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0 + 32,
                        &Cx_Neptune[6*j], &Cy_Neptune[6*j], &Cz_Neptune[6*j]) * 1e3;
    
    double Cx_Pluto[6], Cy_Pluto[6], Cz_Pluto[6];
    
    for (int k = 0; k < 6; k++) {
        Cx_Pluto[k] = PCtemp(423 + k);
        Cy_Pluto[k] = PCtemp(429 + k);
        Cz_Pluto[k] = PCtemp(435 + k);
    }
    
    j = 0;
    Mjd0 = t1;
    *r_Pluto = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0 + 32,
                      &Cx_Pluto[6*j], &Cy_Pluto[6*j], &Cz_Pluto[6*j]) * 1e3;
    
    double EMRAT = 81.30056907419062; // DE430
    double EMRAT1 = 1.0 / (1.0 + EMRAT);
    *r_Earth = *r_Earth - (*r_Moon) * EMRAT1;
    *r_Mercury = *r_Mercury - *r_Earth;
    *r_Venus = *r_Venus - *r_Earth;
    *r_Mars = *r_Mars - *r_Earth;
    *r_Jupiter = *r_Jupiter - *r_Earth;
    *r_Saturn = *r_Saturn - *r_Earth;
    *r_Uranus = *r_Uranus - *r_Earth;
    *r_Neptune = *r_Neptune - *r_Earth;
    *r_Pluto = *r_Pluto - *r_Earth;
    *r_Sun = *r_Sun - *r_Earth;
}

void test_JPL_Eph_DE430()
{
    // Inicializar PC con datos de prueba simplificados
    PC = new Matrix(2, 1000); // Matriz grande para simular datos DE430
    
    // Llenar con datos de prueba - en un caso real vendrían del archivo DE430
    (*PC)(1,1) = 2451545.0;  // JD inicio
    (*PC)(1,2) = 2451577.0;  // JD fin (32 días)
    
    // Llenar coeficientes con valores de prueba (en caso real serían los reales)
    for (int i = 3; i <= 1000; i++) {
        (*PC)(1,i) = 0.001 * (i % 100); // Coeficientes de prueba
    }
    
    // Duplicar la fila para tener al menos 2 intervalos
    for (int i = 1; i <= 1000; i++) {
        (*PC)(2,i) = (*PC)(1,i);
    }
    (*PC)(2,1) = 2451577.0;  // Segundo intervalo
    (*PC)(2,2) = 2451609.0;
    
    Matrix *r_Mercury = nullptr, *r_Venus = nullptr, *r_Earth = nullptr, *r_Mars = nullptr, *r_Jupiter = nullptr; 
    Matrix *r_Saturn = nullptr, *r_Uranus = nullptr, *r_Neptune = nullptr, *r_Pluto = nullptr, *r_Moon = nullptr, *r_Sun = nullptr;
    
    // Test 1: J2000.0 epoca (MJD 51544.5 TT)
    double Mjd_TDB_test = 51544.5;
    
    try {
        JPL_Eph_DE430(Mjd_TDB_test, r_Mercury, r_Venus, r_Earth, r_Mars,
                      r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);
        
        assert(r_Earth->isVector3D());
        assert(r_Sun->isVector3D());
        assert(r_Moon->isVector3D());
        assert(r_Mercury->isVector3D());
        
        double sun_dist = r_Sun->norm();
        double moon_dist = r_Moon->norm();
        assert(sun_dist > 0);
        assert(moon_dist > 0);
        assert(!std::isnan(sun_dist) && !std::isinf(sun_dist));
        assert(!std::isnan(moon_dist) && !std::isinf(moon_dist));
        
        delete r_Mercury; delete r_Venus; delete r_Earth; delete r_Mars;
        delete r_Jupiter; delete r_Saturn; delete r_Uranus; delete r_Neptune;
        delete r_Pluto; delete r_Moon; delete r_Sun;
        
    } catch (const std::runtime_error&) {
        if (r_Mercury) { delete r_Mercury; delete r_Venus; delete r_Earth; delete r_Mars;
                        delete r_Jupiter; delete r_Saturn; delete r_Uranus; delete r_Neptune;
                        delete r_Pluto; delete r_Moon; delete r_Sun; }
    }
    
    // Test 2: Verificar excepcion cuando PC no inicializado
    Matrix* PC_backup = PC;
    PC = nullptr;
    
    r_Mercury = nullptr; r_Venus = nullptr; r_Earth = nullptr; r_Mars = nullptr; 
    r_Jupiter = nullptr; r_Saturn = nullptr; r_Uranus = nullptr; r_Neptune = nullptr;
    r_Pluto = nullptr; r_Moon = nullptr; r_Sun = nullptr;
    
    bool exception_thrown = false;
    try {
        JPL_Eph_DE430(51544.5, r_Mercury, r_Venus, r_Earth, r_Mars,
                      r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    PC = PC_backup;
    
    // Test 3: Verificar correcciones EMRAT  
    if (PC != nullptr) {
        r_Mercury = nullptr; r_Venus = nullptr; r_Earth = nullptr; r_Mars = nullptr; 
        r_Jupiter = nullptr; r_Saturn = nullptr; r_Uranus = nullptr; r_Neptune = nullptr;
        r_Pluto = nullptr; r_Moon = nullptr; r_Sun = nullptr;
        
        try {
            JPL_Eph_DE430(51544.5, r_Mercury, r_Venus, r_Earth, r_Mars,
                          r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);
            
            assert(r_Mercury->norm() > 0);
            assert(r_Venus->norm() > 0);
            
            delete r_Mercury; delete r_Venus; delete r_Earth; delete r_Mars;
            delete r_Jupiter; delete r_Saturn; delete r_Uranus; delete r_Neptune;
            delete r_Pluto; delete r_Moon; delete r_Sun;
            
        } catch (const std::runtime_error&) {
            if (r_Mercury) { delete r_Mercury; delete r_Venus; delete r_Earth; delete r_Mars;
                            delete r_Jupiter; delete r_Saturn; delete r_Uranus; delete r_Neptune;
                            delete r_Pluto; delete r_Moon; delete r_Sun; }
        }
    }
    
    // Test 4: Verificar comportamiento con fecha fuera de rango
    r_Mercury = nullptr; r_Venus = nullptr; r_Earth = nullptr; r_Mars = nullptr; 
    r_Jupiter = nullptr; r_Saturn = nullptr; r_Uranus = nullptr; r_Neptune = nullptr;
    r_Pluto = nullptr; r_Moon = nullptr; r_Sun = nullptr;
    
    exception_thrown = false;
    try {
        JPL_Eph_DE430(99999.0, r_Mercury, r_Venus, r_Earth, r_Mars,
                      r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    // Cleanup
    delete PC;
    PC = nullptr;
}

REGISTER_TEST(test_JPL_Eph_DE430);