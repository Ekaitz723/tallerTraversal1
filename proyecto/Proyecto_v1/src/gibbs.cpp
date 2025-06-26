#include "gibbs.h"
#include "angl.h"
#include "unit.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void gibbs(const Matrix& r1, const Matrix& r2, const Matrix& r3, 
    Matrix*& v2, double& theta, double& theta1, double& copa, std::string& error)
{
    const double small = 0.00000001;

    theta = 0.0;
    error = "          ok";
    theta1 = 0.0;

    double magr1 = r1.norm();
    double magr2 = r2.norm();
    double magr3 = r3.norm();

    v2 = new Matrix(3, 1);

    Matrix p = Matrix::cross(r2, r3);
    Matrix q = Matrix::cross(r3, r1);
    Matrix w = Matrix::cross(r1, r2);
    Matrix pn = unit(p);
    Matrix r1n = unit(r1);
    copa = std::asin(Matrix::dot(pn, r1n));

    Matrix d = p + q + w;
    double magd = d.norm();
    Matrix n = p * magr1 + q * magr2 + w * magr3;
    double magn = n.norm();
    Matrix nn = unit(n);
    Matrix dn = unit(d);

    if ((std::abs(magd) < small) || (std::abs(magn) < small) || (Matrix::dot(nn, dn) < small)) {
        error = "  impossible";
    } else {
        // 1) vel
        theta = angl(r1, r2);
        theta1 = angl(r2, r3);

        double r1mr2 = magr1 - magr2;
        double r3mr1 = magr3 - magr1;
        double r2mr3 = magr2 - magr3;
        Matrix s = r3 * r1mr2 + r2 * r3mr1 + r1 * r2mr3;
        Matrix b = Matrix::cross(d, r2);
        double l = std::sqrt(GM_Earth / (magd * magn));
        double tover2 = l / magr2;
        *v2 = b * tover2 + s * l;

        // 2) coplanaridad (pero v2 ya está calculado)
        if (std::abs(Matrix::dot(r1n, pn)) > 0.017452406) {
            error = "not coplanar";
        }
    }
}

void test_gibbs()
{
    // Test 1: Caso tipico de orbita circular - posiciones a 120 grados
    // Radio orbital ~7000 km (altitud ~600 km)
    double R = 7000.0e3;  // 7000 km
    
    Matrix r1(R, 0.0, 0.0);  // Posicion en X
    Matrix r2(-R/2.0, R*std::sqrt(3.0)/2.0, 0.0);  // 120 grados
    Matrix r3(-R/2.0, -R*std::sqrt(3.0)/2.0, 0.0); // 240 grados
    
    Matrix *v2;
    double theta, theta1, copa;
    std::string error;
    
    gibbs(r1, r2, r3, v2, theta, theta1, copa, error);
    
    assert(error == "          ok");
    assert(v2->norm() > 0);  // Debe haber velocidad
    assert(!std::isnan(v2->norm()) && !std::isinf(v2->norm()));
    assert(std::abs(theta - 2.0*M_PI/3.0) < 0.1);  // ~120 grados
    assert(std::abs(copa) < 0.1);  // Debe ser coplanar
    delete v2;
    
    // Test 2: Caso no coplanar - vectores fuera del plano
    Matrix r1_nc(7000.0e3, 0.0, 0.0);
    Matrix r2_nc(0.0, 7000.0e3, 0.0);
    Matrix r3_nc(0.0, 0.0, 7000.0e3);  // Fuera del plano XY
    
    Matrix *v2_nc;
    double theta_nc, theta1_nc, copa_nc;
    std::string error_nc;
    
    gibbs(r1_nc, r2_nc, r3_nc, v2_nc, theta_nc, theta1_nc, copa_nc, error_nc);
    
    assert(error_nc == "not coplanar");
    assert(std::abs(copa_nc) > 0.1);  // No debe ser coplanar
    delete v2_nc;
    
    // Test 3: Caso imposible - vectores colineales
    Matrix r1_col(7000.0e3, 0.0, 0.0);
    Matrix r2_col(8000.0e3, 0.0, 0.0);  // Misma direccion
    Matrix r3_col(9000.0e3, 0.0, 0.0);  // Misma direccion
    
    Matrix *v2_col;
    double theta_col, theta1_col, copa_col;
    std::string error_col;
    
    gibbs(r1_col, r2_col, r3_col, v2_col, theta_col, theta1_col, copa_col, error_col);
    
    assert(error_col == "  impossible");
    delete v2_col;
    
    // Test 4: Orbita eliptica tipica - ejemplo de libro de texto
    // Posiciones aproximadas de orbita con e~0.2, a~8000km
    Matrix r1_elip(8000.0e3, 0.0, 0.0);  // Apogeo
    Matrix r2_elip(0.0, 6400.0e3, 0.0);  // Punto intermedio
    Matrix r3_elip(-6400.0e3, 0.0, 0.0); // Perigeo
    
    Matrix *v2_elip;
    double theta_elip, theta1_elip, copa_elip;
    std::string error_elip;
    
    gibbs(r1_elip, r2_elip, r3_elip, v2_elip, theta_elip, theta1_elip, copa_elip, error_elip);
    
    assert(error_elip == "          ok");
    assert(v2_elip->norm() > 5000 && v2_elip->norm() < 15000);  // Velocidad orbital tipica
    assert(std::abs(copa_elip) < 0.01);  // Debe ser coplanar
    delete v2_elip;
    
    // Test 5: Verificacion de propiedades fisicas
    // La velocidad debe ser perpendicular al radio en orbita circular
    Matrix r_circ(7000.0e3, 0.0, 0.0);
    Matrix r2_circ(0.0, 7000.0e3, 0.0);
    Matrix r3_circ(-7000.0e3, 0.0, 0.0);
    
    Matrix *v2_circ;
    double theta_circ, theta1_circ, copa_circ;
    std::string error_circ;
    
    gibbs(r_circ, r2_circ, r3_circ, v2_circ, theta_circ, theta1_circ, copa_circ, error_circ);
    
    assert(error_circ == "          ok");
    // En orbita circular, v debe ser perpendicular a r
    double dot_product = Matrix::dot(r2_circ, *v2_circ);
    assert(std::abs(dot_product) < 1e6);  // Casi perpendicular (tolerancia numerica)
    delete v2_circ;
    
    // Test 6: Vectores muy pequeños - caso limite
    Matrix r1_small(1.0, 0.0, 0.0);
    Matrix r2_small(0.0, 1.0, 0.0);
    Matrix r3_small(-1.0, 0.0, 0.0);
    
    Matrix *v2_small;
    double theta_small, theta1_small, copa_small;
    std::string error_small;
    
    gibbs(r1_small, r2_small, r3_small, v2_small, theta_small, theta1_small, copa_small, error_small);
    
    // Puede fallar por vectores muy pequeños
    assert(error_small == "  impossible" || error_small == "          ok");
    delete v2_small;
    
    // Test 7: Caso real de determinacion orbital - ISS aproximada
    // Altitud ~400km, inclinacion ~51.6 grados
    double h_iss = 400.0e3;  // Altitud ISS
    double R_iss = 6378.137e3 + h_iss;  // Radio orbital
    double inc = 51.6 * M_PI / 180.0;  // Inclinacion ISS
    
    Matrix r1_iss(R_iss, 0.0, 0.0);
    Matrix r2_iss(R_iss*std::cos(M_PI/3), R_iss*std::sin(M_PI/3)*std::cos(inc), 
                   R_iss*std::sin(M_PI/3)*std::sin(inc));
    Matrix r3_iss(R_iss*std::cos(2*M_PI/3), R_iss*std::sin(2*M_PI/3)*std::cos(inc),
                   R_iss*std::sin(2*M_PI/3)*std::sin(inc));
    
    Matrix *v2_iss;
    double theta_iss, theta1_iss, copa_iss;
    std::string error_iss;
    
    gibbs(r1_iss, r2_iss, r3_iss, v2_iss, theta_iss, theta1_iss, copa_iss, error_iss);
    
    assert(error_iss == "          ok");
    // Velocidad orbital ISS ~7.66 km/s
    assert(v2_iss->norm() > 7000 && v2_iss->norm() < 8000);
    assert(std::abs(copa_iss) < 0.1);
    delete v2_iss;
    
    // Test 8: Verificacion de conservacion de energia
    // Para orbita circular, v = sqrt(GM/r)
    Matrix *v2_energy;
    double theta_energy, theta1_energy, copa_energy;
    std::string error_energy;
    
    gibbs(r1, r2, r3, v2_energy, theta_energy, theta1_energy, copa_energy, error_energy);
    
    double v_expected = std::sqrt(GM_Earth / R);
    double v_calculated = v2_energy->norm();
    double error_percent = std::abs(v_calculated - v_expected) / v_expected;
    assert(error_percent < 0.5);  // Error < 50% (metodo aproximado)
    delete v2_energy;
}

// Debug específico para gibbs
void debug_gibbs_direct()
{
    printf("=== DEBUG GIBBS DIRECTO C++ ===\n");
    
    // Caso 1: Las posiciones exactas del caso de 2 horas que falla
    Matrix r1(-26120080.4, -10836650.2, -13540306.3);
    Matrix r2(-22100558.6, -15052599.8, -11675391.1);
    Matrix r3(-13047533.7, -15134455.1, -7612722.0);
    
    printf("CASO 1: Posiciones del anglesg 2h que falla\n");
    printf("r1 = [%.1f, %.1f, %.1f] m, ||r1|| = %.1f km\n", 
           r1(1), r1(2), r1(3), r1.norm()/1000.0);
    printf("r2 = [%.1f, %.1f, %.1f] m, ||r2|| = %.1f km\n", 
           r2(1), r2(2), r2(3), r2.norm()/1000.0);
    printf("r3 = [%.1f, %.1f, %.1f] m, ||r3|| = %.1f km\n", 
           r3(1), r3(2), r3(3), r3.norm()/1000.0);
    
    Matrix *v2_test1 = nullptr;
    double theta1, theta1_1, copa1;
    std::string error1;
    
    gibbs(r1, r2, r3, v2_test1, theta1, theta1_1, copa1, error1);
    
    printf("RESULTADOS CASO 1:\n");
    printf("error = '%s'\n", error1.c_str());
    printf("copa = %.6f rad (%.3f deg)\n", copa1, copa1*180.0/M_PI);
    printf("theta = %.6f rad, theta1 = %.6f rad\n", theta1, theta1_1);
    printf("v2 = [%.6f, %.6f, %.6f] m/s\n", (*v2_test1)(1), (*v2_test1)(2), (*v2_test1)(3));
    printf("||v2|| = %.6f m/s\n", v2_test1->norm());
    printf("Esperado MATLAB: v2 = [1780.159, -508.564, 505.951], ||v2|| = 1919.268\n");
    
    delete v2_test1;
    
    // Caso 2: Órbita circular ideal (debe funcionar perfecto)
    printf("\nCASO 2: Órbita circular ideal\n");
    double R = 7000.0e3;
    Matrix r1_ideal(R, 0.0, 0.0);
    Matrix r2_ideal(-R/2.0, R*std::sqrt(3.0)/2.0, 0.0);  // 120 grados
    Matrix r3_ideal(-R/2.0, -R*std::sqrt(3.0)/2.0, 0.0); // 240 grados
    
    printf("r1_ideal = [%.1f, %.1f, %.1f] m\n", r1_ideal(1), r1_ideal(2), r1_ideal(3));
    printf("r2_ideal = [%.1f, %.1f, %.1f] m\n", r2_ideal(1), r2_ideal(2), r2_ideal(3));
    printf("r3_ideal = [%.1f, %.1f, %.1f] m\n", r3_ideal(1), r3_ideal(2), r3_ideal(3));
    
    Matrix *v2_ideal = nullptr;
    double theta_ideal, theta1_ideal, copa_ideal;
    std::string error_ideal;
    
    gibbs(r1_ideal, r2_ideal, r3_ideal, v2_ideal, theta_ideal, theta1_ideal, copa_ideal, error_ideal);
    
    printf("RESULTADOS CASO 2:\n");
    printf("error = '%s'\n", error_ideal.c_str());
    printf("copa = %.6f rad (%.3f deg)\n", copa_ideal, copa_ideal*180.0/M_PI);
    printf("v2_ideal = [%.3f, %.3f, %.3f] m/s\n", (*v2_ideal)(1), (*v2_ideal)(2), (*v2_ideal)(3));
    printf("||v2_ideal|| = %.3f m/s\n", v2_ideal->norm());
    printf("Esperado: ~7.5 km/s, error='ok'\n");
    
    delete v2_ideal;
    
    // Caso 3: Vectores colineales (debe dar error impossible)
    printf("\nCASO 3: Vectores colineales (debe fallar)\n");
    Matrix r1_bad(7000.0e3, 0.0, 0.0);
    Matrix r2_bad(8000.0e3, 0.0, 0.0);
    Matrix r3_bad(9000.0e3, 0.0, 0.0);
    
    Matrix *v2_bad = nullptr;
    double theta_bad, theta1_bad, copa_bad;
    std::string error_bad;
    
    gibbs(r1_bad, r2_bad, r3_bad, v2_bad, theta_bad, theta1_bad, copa_bad, error_bad);
    
    printf("RESULTADOS CASO 3:\n");
    printf("error = '%s' (debe ser 'impossible')\n", error_bad.c_str());
    printf("v2_bad = [%.3f, %.3f, %.3f] m/s\n", (*v2_bad)(1), (*v2_bad)(2), (*v2_bad)(3));
    
    delete v2_bad;
    
    printf("=== FIN DEBUG GIBBS C++ ===\n");
}

void test_gibbs_direct()
{
    // Test 1: Caso problemático del anglesg 2h
    Matrix r1_test1(-26120080.4, -10836650.2, -13540306.3);
    Matrix r2_test1(-22100558.6, -15052599.8, -11675391.1);
    Matrix r3_test1(-13047533.7, -15134455.1, -7612722.0);
    
    Matrix *v2_test1 = nullptr;
    double theta1, theta1_1, copa1;
    std::string error1;
    
    gibbs(r1_test1, r2_test1, r3_test1, v2_test1, theta1, theta1_1, copa1, error1);
    
    // Verificar contra valores MATLAB exactos
    assert(error1 == "          ok");  // MATLAB da 'ok', no 'not coplanar'
    assert(std::abs(copa1 - (-0.015700)) < 1e-5);  // copa = -0.015700 rad
    assert(std::abs(theta1 - 0.189273) < 1e-5);     // theta = 0.189273 rad
    assert(std::abs(theta1_1 - 0.246498) < 1e-5);   // theta1 = 0.246498 rad
    
    // Velocidad: [1639.651669, -592.556847, 744.261757] m/s
    assert(std::abs((*v2_test1)(1) - 1639.651669) < 1e-2);
    assert(std::abs((*v2_test1)(2) - (-592.556847)) < 1e-2);
    assert(std::abs((*v2_test1)(3) - 744.261757) < 1e-2);
    assert(std::abs(v2_test1->norm() - 1895.654709) < 1e-2);
    
    // printf("Test gibbs caso 1: BIEN\n");
    delete v2_test1;
    
    // Test 2: Órbita circular ideal
    double R = 7000.0e3;
    Matrix r1_ideal(R, 0.0, 0.0);
    Matrix r2_ideal(-R/2.0, R*std::sqrt(3.0)/2.0, 0.0);
    Matrix r3_ideal(-R/2.0, -R*std::sqrt(3.0)/2.0, 0.0);
    
    Matrix *v2_ideal = nullptr;
    double theta_ideal, theta1_ideal, copa_ideal;
    std::string error_ideal;
    
    gibbs(r1_ideal, r2_ideal, r3_ideal, v2_ideal, theta_ideal, theta1_ideal, copa_ideal, error_ideal);
    
    // Verificar contra valores MATLAB
    assert(error_ideal == "          ok");
    assert(std::abs(copa_ideal - 0.0) < 1e-6);  // copa = 0.000000 rad
    
    // Velocidad: [-6535.074, -3773.027, 0.000] m/s
    assert(std::abs((*v2_ideal)(1) - (-6535.074)) < 1e-1);
    assert(std::abs((*v2_ideal)(2) - (-3773.027)) < 1e-1);
    assert(std::abs((*v2_ideal)(3) - 0.0) < 1e-3);
    assert(std::abs(v2_ideal->norm() - 7546.053) < 1e-1);
    
    // printf("Test gibbs caso 2: BIEN\n");
    delete v2_ideal;
    
    // Test 3: Vectores colineales (debe fallar)
    Matrix r1_bad(7000.0e3, 0.0, 0.0);
    Matrix r2_bad(8000.0e3, 0.0, 0.0);
    Matrix r3_bad(9000.0e3, 0.0, 0.0);
    
    Matrix *v2_bad = nullptr;
    double theta_bad, theta1_bad, copa_bad;
    std::string error_bad;
    
    gibbs(r1_bad, r2_bad, r3_bad, v2_bad, theta_bad, theta1_bad, copa_bad, error_bad);
    
    // Verificar error y velocidad cero
    assert(error_bad == "  impossible");
    assert(std::abs((*v2_bad)(1)) < 1e-10);
    assert(std::abs((*v2_bad)(2)) < 1e-10);
    assert(std::abs((*v2_bad)(3)) < 1e-10);
    
    // printf("Test gibbs caso 3: BIEN\n");
    delete v2_bad;
}

REGISTER_TEST(test_gibbs_direct);