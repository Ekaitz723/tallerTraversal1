#include "hgibbs.h"
#include "angl.h"
#include "unit.h"
#include "Sat_const.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

void hgibbs(const Matrix& r1, const Matrix& r2, const Matrix& r3,
            double Mjd1, double Mjd2, double Mjd3,
            Matrix*& v2, double& theta, double& theta1, double& copa, std::string& error)
{
    error = "          ok";
    theta = 0.0;
    theta1 = 0.0;
    
    double magr1 = r1.norm();
    double magr2 = r2.norm();
    double magr3 = r3.norm();
    
    v2 = new Matrix(3, 1);
    
    double tolangle = 0.01745329251994;
    double dt21 = (Mjd2 - Mjd1) * 86400.0;
    double dt31 = (Mjd3 - Mjd1) * 86400.0;
    double dt32 = (Mjd3 - Mjd2) * 86400.0;
    
    Matrix p = Matrix::cross(r2, r3);
    Matrix pn = unit(p);
    Matrix r1n = unit(r1);
    copa = std::asin(Matrix::dot(pn, r1n));
    
    double dot_check = Matrix::dot(r1n, pn);
    // printf("DEBUG: abs(dot(r1n,pn)) = %.6f, limit = 0.017452406\n", std::abs(dot_check));
    
    if (std::abs(Matrix::dot(r1n, pn)) > 0.017452406) {
        // printf("DEBUG: Setting error to 'not coplanar'\n");
        error = "not coplanar";
    }
    
    theta = angl(r1, r2);
    theta1 = angl(r2, r3);
    
    if ((theta > tolangle) || (theta1 > tolangle)) {
        error = "   angl > 1ø";
    }
    
    double term1 = -dt32 * (1.0 / (dt21 * dt31) + GM_Earth / (12.0 * magr1 * magr1 * magr1));
    double term2 = (dt32 - dt21) * (1.0 / (dt21 * dt32) + GM_Earth / (12.0 * magr2 * magr2 * magr2));
    double term3 = dt21 * (1.0 / (dt32 * dt31) + GM_Earth / (12.0 * magr3 * magr3 * magr3));
    
    *v2 = r1 * term1 + r2 * term2 + r3 * term3;
}


void hgibbs_debug_identico()
{
    printf("=== HGIBBS DEBUG MATLAB ===\n");

    // CASO 1: Debe funcionar (coplanar, angulos pequenos)
    printf("\n--- CASO 1: Should work ---\n");
    Matrix r1(7000000.0, 0.0, 0.0);
    Matrix r2(6999650.003, 69998.833, 0.0);
    Matrix r3(6998600.047, 139990.667, 0.0);
    double Mjd1 = 58849.0;
    double Mjd2 = 58849.007;
    double Mjd3 = 58849.014;

    printf("r1 = [%.3f, %.3f, %.3f]\n", r1(1), r1(2), r1(3));
    printf("r2 = [%.3f, %.3f, %.3f]\n", r2(1), r2(2), r2(3));
    printf("r3 = [%.3f, %.3f, %.3f]\n", r3(1), r3(2), r3(3));
    printf("Mjd1 = %.6f, Mjd2 = %.6f, Mjd3 = %.6f\n", Mjd1, Mjd2, Mjd3);

    Matrix *v2;
    double theta, theta1, copa;
    std::string error;
    hgibbs(r1, r2, r3, Mjd1, Mjd2, Mjd3, v2, theta, theta1, copa, error);
    printf("Result: error = \"%s\"\n", error.c_str());
    printf("Result: theta = %.6f rad, theta1 = %.6f rad\n", theta, theta1);
    printf("Result: copa = %.6f rad\n", copa);
    printf("Result: v2 = [%.3f, %.3f, %.3f] m/s\n", (*v2)(1), (*v2)(2), (*v2)(3));
    printf("Result: ||v2|| = %.3f m/s\n", v2->norm());
    delete v2;

    // CASO 2: No coplanar (debe fallar)
    printf("\n--- CASO 2: Not coplanar ---\n");
    r1 = Matrix(7000000.0, 0.0, 0.0);
    r2 = Matrix(0.0, 7000000.0, 0.0);
    r3 = Matrix(0.0, 0.0, 7000000.0);
    Mjd1 = 58849.0;
    Mjd2 = 58849.007;
    Mjd3 = 58849.014;

    printf("r1 = [%.3f, %.3f, %.3f]\n", r1(1), r1(2), r1(3));
    printf("r2 = [%.3f, %.3f, %.3f]\n", r2(1), r2(2), r2(3));
    printf("r3 = [%.3f, %.3f, %.3f]\n", r3(1), r3(2), r3(3));
    printf("Mjd1 = %.6f, Mjd2 = %.6f, Mjd3 = %.6f\n", Mjd1, Mjd2, Mjd3);

    hgibbs(r1, r2, r3, Mjd1, Mjd2, Mjd3, v2, theta, theta1, copa, error);
    printf("Result: error = \"%s\"\n", error.c_str());
    printf("Result: theta = %.6f rad, theta1 = %.6f rad\n", theta, theta1);
    printf("Result: copa = %.6f rad\n", copa);
    printf("Result: v2 = [%.3f, %.3f, %.3f] m/s\n", (*v2)(1), (*v2)(2), (*v2)(3));
    printf("Result: ||v2|| = %.3f m/s\n", v2->norm());
    delete v2;

    // CASO 3: Angulos grandes (debe fallar)
    printf("\n--- CASO 3: Large angles ---\n");
    r1 = Matrix(7000000.0, 0.0, 0.0);
    r2 = Matrix(-7000000.0, 0.0, 0.0);
    r3 = Matrix(0.0, 7000000.0, 0.0);
    Mjd1 = 58849.0;
    Mjd2 = 58849.007;
    Mjd3 = 58849.014;

    printf("r1 = [%.3f, %.3f, %.3f]\n", r1(1), r1(2), r1(3));
    printf("r2 = [%.3f, %.3f, %.3f]\n", r2(1), r2(2), r2(3));
    printf("r3 = [%.3f, %.3f, %.3f]\n", r3(1), r3(2), r3(3));
    printf("Mjd1 = %.6f, Mjd2 = %.6f, Mjd3 = %.6f\n", Mjd1, Mjd2, Mjd3);

    hgibbs(r1, r2, r3, Mjd1, Mjd2, Mjd3, v2, theta, theta1, copa, error);
    printf("Result: error = \"%s\"\n", error.c_str());
    printf("Result: theta = %.6f rad, theta1 = %.6f rad\n", theta, theta1);
    printf("Result: copa = %.6f rad\n", copa);
    printf("Result: v2 = [%.3f, %.3f, %.3f] m/s\n", (*v2)(1), (*v2)(2), (*v2)(3));
    printf("Result: ||v2|| = %.3f m/s\n", v2->norm());
    delete v2;

    // CASO 4: Angulos muy pequenos (debe funcionar)
    printf("\n--- CASO 4: Very small angles ---\n");
    r1 = Matrix(7000000.0, 0.0, 0.0);
    r2 = Matrix(6999998.75, 35000.0, 0.0);
    r3 = Matrix(6999995.0, 70000.0, 0.0);
    Mjd1 = 58849.0;
    Mjd2 = 58849.003;
    Mjd3 = 58849.006;

    printf("r1 = [%.3f, %.3f, %.3f]\n", r1(1), r1(2), r1(3));
    printf("r2 = [%.3f, %.3f, %.3f]\n", r2(1), r2(2), r2(3));
    printf("r3 = [%.3f, %.3f, %.3f]\n", r3(1), r3(2), r3(3));
    printf("Mjd1 = %.6f, Mjd2 = %.6f, Mjd3 = %.6f\n", Mjd1, Mjd2, Mjd3);

    hgibbs(r1, r2, r3, Mjd1, Mjd2, Mjd3, v2, theta, theta1, copa, error);
    printf("Result: error = \"%s\"\n", error.c_str());
    printf("Result: theta = %.6f rad, theta1 = %.6f rad\n", theta, theta1);
    printf("Result: copa = %.6f rad\n", copa);
    printf("Result: v2 = [%.3f, %.3f, %.3f] m/s\n", (*v2)(1), (*v2)(2), (*v2)(3));
    printf("Result: ||v2|| = %.3f m/s\n", v2->norm());
    delete v2;

    printf("\n=== END HGIBBS DEBUG MATLAB ===\n");
}

void test_hgibbs_real()
{
    // CASO 1: debe dar "ok" con v2 ~124 m/s
    Matrix r1_1(7000000.0, 0.0, 0.0);
    Matrix r2_1(6999650.003, 69998.833, 0.0);
    Matrix r3_1(6998600.047, 139990.667, 0.0);
    double Mjd1_1 = 58849.0;
    double Mjd2_1 = 58849.007;
    double Mjd3_1 = 58849.014;
    
    Matrix *v2_1;
    double theta_1, theta1_1, copa_1;
    std::string error_1;
    hgibbs(r1_1, r2_1, r3_1, Mjd1_1, Mjd2_1, Mjd3_1, v2_1, theta_1, theta1_1, copa_1, error_1);
    
    assert(error_1 == "          ok");
    assert(std::abs(theta_1 - 0.010000) < 1e-5);
    assert(std::abs(theta1_1 - 0.010000) < 1e-5);
    assert(std::abs(copa_1 - 0.000000) < 1e-5);
    assert(std::abs((*v2_1)(1) - (-1.239)) < 0.1);
    assert(std::abs((*v2_1)(2) - 123.932) < 0.1);
    assert(std::abs((*v2_1)(3) - 0.000) < 0.1);
    assert(std::abs(v2_1->norm() - 123.938) < 0.1);
    delete v2_1;
    
    // CASO 2: Not coplanar - en realidad da "angl > 1ø" por ángulos grandes
    Matrix r1_2(7000000.0, 0.0, 0.0);
    Matrix r2_2(0.0, 7000000.0, 0.0);
    Matrix r3_2(0.0, 0.0, 7000000.0);
    double Mjd1_2 = 58849.0;
    double Mjd2_2 = 58849.007;
    double Mjd3_2 = 58849.014;
    
    Matrix *v2_2;
    double theta_2, theta1_2, copa_2;
    std::string error_2;
    hgibbs(r1_2, r2_2, r3_2, Mjd1_2, Mjd2_2, Mjd3_2, v2_2, theta_2, theta1_2, copa_2, error_2);
    
    assert(error_2 == "   angl > 1ø");
    assert(std::abs(theta_2 - 1.570796) < 1e-5);
    assert(std::abs(theta1_2 - 1.570796) < 1e-5);
    assert(std::abs(copa_2 - 1.570796) < 1e-5);
    assert(std::abs((*v2_2)(1) - (-6197.026)) < 1.0);
    assert(std::abs((*v2_2)(2) - 0.000) < 0.1);
    assert(std::abs((*v2_2)(3) - 6197.026) < 1.0);
    assert(std::abs(v2_2->norm() - 8763.918) < 1.0);
    delete v2_2;
    
    // CASO 3: Large angles - debe dar "angl > 1ø"
    Matrix r1_3(7000000.0, 0.0, 0.0);
    Matrix r2_3(-7000000.0, 0.0, 0.0);
    Matrix r3_3(0.0, 7000000.0, 0.0);
    double Mjd1_3 = 58849.0;
    double Mjd2_3 = 58849.007;
    double Mjd3_3 = 58849.014;
    
    Matrix *v2_3;
    double theta_3, theta1_3, copa_3;
    std::string error_3;
    hgibbs(r1_3, r2_3, r3_3, Mjd1_3, Mjd2_3, Mjd3_3, v2_3, theta_3, theta1_3, copa_3, error_3);
    
    assert(error_3 == "   angl > 1ø");
    assert(std::abs(theta_3 - 3.141593) < 1e-5);
    assert(std::abs(theta1_3 - 1.570796) < 1e-5);
    assert(std::abs(copa_3 - 0.000000) < 1e-5);
    assert(std::abs((*v2_3)(1) - (-6197.026)) < 1.0);
    assert(std::abs((*v2_3)(2) - 6197.026) < 1.0);
    assert(std::abs((*v2_3)(3) - 0.000) < 0.1);
    assert(std::abs(v2_3->norm() - 8763.918) < 1.0);
    delete v2_3;
    
    // CASO 4: Very small angles - debe dar "ok" con v2 ~137 m/s
    Matrix r1_4(7000000.0, 0.0, 0.0);
    Matrix r2_4(6999998.75, 35000.0, 0.0);
    Matrix r3_4(6999995.0, 70000.0, 0.0);
    double Mjd1_4 = 58849.0;
    double Mjd2_4 = 58849.003;
    double Mjd3_4 = 58849.006;
    
    Matrix *v2_4;
    double theta_4, theta1_4, copa_4;
    std::string error_4;
    hgibbs(r1_4, r2_4, r3_4, Mjd1_4, Mjd2_4, Mjd3_4, v2_4, theta_4, theta1_4, copa_4, error_4);
    
    assert(error_4 == "          ok");
    assert(std::abs(theta_4 - 0.005000) < 1e-5);
    assert(std::abs(theta1_4 - 0.005000) < 1e-5);
    assert(std::abs(copa_4 - 0.000000) < 1e-5);
    assert(std::abs((*v2_4)(1) - (-0.036)) < 0.1);
    assert(std::abs((*v2_4)(2) - 136.788) < 0.1);
    assert(std::abs((*v2_4)(3) - 0.000) < 0.1);
    assert(std::abs(v2_4->norm() - 136.788) < 0.1);
    delete v2_4;
}

REGISTER_TEST(test_hgibbs_real);