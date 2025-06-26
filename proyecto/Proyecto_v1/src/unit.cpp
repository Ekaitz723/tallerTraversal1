#include "unit.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix unit(const Matrix& vec)
{
    if (!vec.isVector3D()) {
        throw std::runtime_error("unit: el vector debe ser 3D");
    }
    
    double small = 0.000001;
    double magv = vec.norm();
    
    Matrix outvec(3, 1);  // Vector columna 3D
    
    if (magv > small) {
        for (int i = 1; i <= 3; i++) {
            outvec(i) = vec(i) / magv;
        }
    } else {
        for (int i = 1; i <= 3; i++) {
            outvec(i) = 0.0;
        }
    }
    
    return outvec;
}

void test_unit()
{
    // Test 1: Vector normal [3, 4, 0] - debe dar [0.6, 0.8, 0.0]
    Matrix v1(3.0, 4.0, 0.0);
    Matrix u1 = unit(v1);
    assert(fabs(u1(1) - 0.6) < 1e-10);
    assert(fabs(u1(2) - 0.8) < 1e-10);
    assert(fabs(u1(3)) < 1e-10);
    assert(fabs(u1.norm() - 1.0) < 1e-10);
    
    // Test 2: Vector unitario ya [1, 0, 0] - debe mantener [1, 0, 0]
    Matrix v2(1.0, 0.0, 0.0);
    Matrix u2 = unit(v2);
    assert(fabs(u2(1) - 1.0) < 1e-10);
    assert(fabs(u2(2)) < 1e-10);
    assert(fabs(u2(3)) < 1e-10);
    assert(fabs(u2.norm() - 1.0) < 1e-10);
    
    // Test 3: Vector cero [0, 0, 0] - debe dar [0, 0, 0]
    Matrix v3(0.0, 0.0, 0.0);
    Matrix u3 = unit(v3);
    assert(fabs(u3(1)) < 1e-10);
    assert(fabs(u3(2)) < 1e-10);
    assert(fabs(u3(3)) < 1e-10);
    
    // Test 4: Vector muy pequeño [1e-8, 1e-8, 1e-8] - debe dar [0, 0, 0]
    Matrix v4(1e-8, 1e-8, 1e-8);
    Matrix u4 = unit(v4);
    assert(fabs(u4(1)) < 1e-10);
    assert(fabs(u4(2)) < 1e-10);
    assert(fabs(u4(3)) < 1e-10);
    
    // Test 5: Vector [1, 1, 1] - debe dar [1/sqrt(3), 1/sqrt(3), 1/sqrt(3)]
    Matrix v5(1.0, 1.0, 1.0);
    Matrix u5 = unit(v5);
    double expected = 1.0 / std::sqrt(3.0);
    assert(fabs(u5(1) - expected) < 1e-10);
    assert(fabs(u5(2) - expected) < 1e-10);
    assert(fabs(u5(3) - expected) < 1e-10);
    assert(fabs(u5.norm() - 1.0) < 1e-10);
    
    // Test 6: Vector negativo [-3, -4, 0] - debe dar [-0.6, -0.8, 0.0]
    Matrix v6(-3.0, -4.0, 0.0);
    Matrix u6 = unit(v6);
    assert(fabs(u6(1) + 0.6) < 1e-10);
    assert(fabs(u6(2) + 0.8) < 1e-10);
    assert(fabs(u6(3)) < 1e-10);
    assert(fabs(u6.norm() - 1.0) < 1e-10);
}

REGISTER_TEST(test_unit);