#include "angl.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double angl(const Matrix& vec1, const Matrix& vec2)
{
    const double small = 0.00000001;
    const double undefined = 999999.1;
    
    double magv1 = vec1.norm();
    double magv2 = vec2.norm();
    
    if (magv1 * magv2 > small * small) {
        double temp = Matrix::dot(vec1, vec2) / (magv1 * magv2);
        if (std::abs(temp) > 1.0) {
            temp = (temp > 0) ? 1.0 : -1.0;  // sign(temp) * 1.0
        }
        return std::acos(temp);
    } else {
        return undefined;
    }
}

void test_angl()
{
    const double pi = M_PI;
    
    // Test 1: Vectores ortogonales - deben dar 90 grados
    Matrix v1(1.0, 0.0, 0.0);  // Vector X
    Matrix v2(0.0, 1.0, 0.0);  // Vector Y
    double angle1 = angl(v1, v2);
    assert(std::abs(angle1 - pi/2) < 1e-12);
    
    // Test 2: Vectores paralelos - deben dar 0 grados
    Matrix v3(1.0, 0.0, 0.0);
    Matrix v4(2.0, 0.0, 0.0);  // Mismo sentido, diferente magnitud
    double angle2 = angl(v3, v4);
    assert(std::abs(angle2) < 1e-12);
    
    // Test 3: Vectores antiparalelos - deben dar 180 grados
    Matrix v5(1.0, 0.0, 0.0);
    Matrix v6(-1.0, 0.0, 0.0);
    double angle3 = angl(v5, v6);
    assert(std::abs(angle3 - pi) < 1e-12);
    
    // Test 4: Angulo de 60 grados conocido
    Matrix v7(1.0, 0.0, 0.0);
    Matrix v8(0.5, std::sqrt(3.0)/2.0, 0.0);  // 60 grados
    double angle4 = angl(v7, v8);
    assert(std::abs(angle4 - pi/3) < 1e-12);
    
    // Test 5: Vectores 3D tipicos de aplicaciones orbitales
    Matrix r1(7000.0e3, 0.0, 0.0);        // Posicion en X
    Matrix r2(0.0, 7000.0e3, 0.0);        // Posicion en Y
    double angle5 = angl(r1, r2);
    assert(std::abs(angle5 - pi/2) < 1e-12);
    
    // Test 6: Caso con magnitudes diferentes pero angulo conocido
    Matrix v9(3.0, 4.0, 0.0);  // Magnitud 5
    Matrix v10(5.0, 0.0, 0.0); // Solo en X
    double angle6 = angl(v9, v10);
    double expected6 = std::acos(3.0/5.0);  // cos(θ) = 3/5
    assert(std::abs(angle6 - expected6) < 1e-12);
    
    // Test 7: Vectores muy pequeños - debe dar undefined
    Matrix v11(1e-10, 0.0, 0.0);
    Matrix v12(0.0, 1e-10, 0.0);
    double angle7 = angl(v11, v12);
    assert(std::abs(angle7 - 999999.1) < 1e-6);
    
    // Test 8: Un vector cero - debe dar undefined
    Matrix v13(0.0, 0.0, 0.0);
    Matrix v14(1.0, 0.0, 0.0);
    double angle8 = angl(v13, v14);
    assert(std::abs(angle8 - 999999.1) < 1e-6);
    
    // Test 9: Vectores identicos - angulo cero
    Matrix v15(2.5, 3.7, 1.2);
    Matrix v16(2.5, 3.7, 1.2);
    double angle9 = angl(v15, v16);
    assert(std::abs(angle9) < 1e-12);
    
    // Test 10: Caso limite con coseno = -1 (producto escalar negativo)
    Matrix v17(1.0, 1.0, 1.0);
    Matrix v18(-1.0, -1.0, -1.0);
    double angle10 = angl(v17, v18);
    assert(std::abs(angle10 - pi) < 1e-12);
    
    // Test 11: Vectores en diferentes planos
    Matrix v19(1.0, 0.0, 0.0);
    Matrix v20(0.0, 0.0, 1.0);  // Vector Z
    double angle11 = angl(v19, v20);
    assert(std::abs(angle11 - pi/2) < 1e-12);
    
    // Test 12: Caso tipico de determinacion orbital
    Matrix pos1(6000.0e3, 2000.0e3, 1000.0e3);
    Matrix pos2(5000.0e3, 3000.0e3, 2000.0e3);
    double angle12 = angl(pos1, pos2);
    assert(angle12 > 0 && angle12 < pi);  // Debe estar en rango valido
    assert(!std::isnan(angle12) && !std::isinf(angle12));
}

REGISTER_TEST(test_angl);