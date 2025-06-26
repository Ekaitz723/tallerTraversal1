#include "TimeUpdate.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix TimeUpdate(const Matrix& P, const Matrix& Phi, double Qdt)
{
    if (!P.isSquare() || !Phi.isSquare()) {
        throw std::runtime_error("P y Phi deben ser matrices cuadradas");
    }
    
    return Phi * P * Phi.transpose() + Matrix::eye(std::sqrt(P.size())) * Qdt;
}

Matrix TimeUpdate(const Matrix& P, const Matrix& Phi, const Matrix& Qdt)
{
    if (!P.isSquare() || !Phi.isSquare() || !Qdt.isSquare()) {
        throw std::runtime_error("P, Phi y Qdt deben ser matrices cuadradas");
    }
    
    return Phi * P * Phi.transpose() + Qdt;
}

void test_TimeUpdate()
{
    // Test 1: Caso basico 2x2 sin ruido de proceso (Qdt=0)
    Matrix P(2, 2);
    P(1,1) = 1.0; P(1,2) = 0.5;
    P(2,1) = 0.5; P(2,2) = 2.0;
    
    Matrix Phi(2, 2);
    Phi(1,1) = 1.0; Phi(1,2) = 1.0;
    Phi(2,1) = 0.0; Phi(2,2) = 1.0;
    
    Matrix P_updated = TimeUpdate(P, Phi);
    
    // Verificar dimension
    assert(P_updated.size() == 4);
    
    // Calcular manualmente: Phi*P*Phi'
    // Phi*P = [1 1; 0 1] * [1 0.5; 0.5 2] = [1.5 2.5; 0.5 2]
    // (Phi*P)*Phi' = [1.5 2.5; 0.5 2] * [1 0; 1 1] = [4 2.5; 2.5 2]
    assert(fabs(P_updated(1,1) - 4.0) < 1e-14);
    assert(fabs(P_updated(1,2) - 2.5) < 1e-14);
    assert(fabs(P_updated(2,1) - 2.5) < 1e-14);
    assert(fabs(P_updated(2,2) - 2.0) < 1e-14);
    
    // Test 2: Ruido de proceso diagonal
    Matrix Qdt_diagonal = Matrix::eye(2) * 0.1;
    Matrix P2b_updated = TimeUpdate(P, Phi, Qdt_diagonal);
    
    assert(fabs(P2b_updated(1,1) - 4.1) < 1e-14);  // 4.0 + 0.1
    assert(fabs(P2b_updated(2,2) - 2.1) < 1e-14);  // 2.0 + 0.1
    assert(fabs(P2b_updated(1,2) - 2.5) < 1e-14);  // Sin cambio
    
    // Test 3: Matriz identidad como transicion
    Matrix Phi_identity = Matrix::eye(2);
    Matrix P3_updated = TimeUpdate(P, Phi_identity);

    // Con Phi = I, resultado debe ser P = I*P*I' + 0 = P
    assert(fabs(P3_updated(1,1) - P(1,1)) < 1e-14);
    assert(fabs(P3_updated(1,2) - P(1,2)) < 1e-14);
    assert(fabs(P3_updated(2,1) - P(2,1)) < 1e-14);
    assert(fabs(P3_updated(2,2) - P(2,2)) < 1e-14);
    
    // Test 4: Con matriz de ruido de proceso Qdt
    Matrix Qdt_matrix(2, 2);
    Qdt_matrix(1,1) = 0.01; Qdt_matrix(1,2) = 0.005;
    Qdt_matrix(2,1) = 0.005; Qdt_matrix(2,2) = 0.02;
    
    Matrix P4_updated = TimeUpdate(P, Phi, Qdt_matrix);
    
    // Resultado debe ser Phi*P*Phi' + Qdt_matrix
    assert(fabs(P4_updated(1,1) - (4.0 + 0.01)) < 1e-14);
    assert(fabs(P4_updated(1,2) - (2.5 + 0.005)) < 1e-14);
    assert(fabs(P4_updated(2,1) - (2.5 + 0.005)) < 1e-14);
    assert(fabs(P4_updated(2,2) - (2.0 + 0.02)) < 1e-14);
    
    // Test 5: Caso 3x3 mas complejo
    Matrix P5(3, 3);
    P5(1,1) = 1.0; P5(1,2) = 0.1; P5(1,3) = 0.0;
    P5(2,1) = 0.1; P5(2,2) = 0.5; P5(2,3) = 0.05;
    P5(3,1) = 0.0; P5(3,2) = 0.05; P5(3,3) = 0.25;
    
    Matrix Phi5(3, 3);
    Phi5(1,1) = 1.0; Phi5(1,2) = 0.1; Phi5(1,3) = 0.005;
    Phi5(2,1) = 0.0; Phi5(2,2) = 1.0; Phi5(2,3) = 0.1;
    Phi5(3,1) = 0.0; Phi5(3,2) = 0.0; Phi5(3,3) = 1.0;
    
    Matrix P5_updated = TimeUpdate(P5, Phi5);
    
    assert(P5_updated.size() == 9);
    assert(P5_updated(1,1) > P5(1,1));  // Debe crecer la incertidumbre
    assert(P5_updated(3,3) >= P5(3,3)); // La diagonal debe crecer o mantenerse
    
    // Test 6: Verificar simetria en resultado
    Matrix P6 = Matrix::eye(3);
    Matrix Phi6(3, 3);
    Phi6(1,1) = 0.9; Phi6(1,2) = 0.1; Phi6(1,3) = 0.0;
    Phi6(2,1) = 0.0; Phi6(2,2) = 0.95; Phi6(2,3) = 0.05;
    Phi6(3,1) = 0.0; Phi6(3,2) = 0.0; Phi6(3,3) = 1.0;
    
    Matrix P6_updated = TimeUpdate(P6, Phi6, 0.01);
    
    // Verificar simetria
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            assert(fabs(P6_updated(i,j) - P6_updated(j,i)) < 1e-14);
        }
    }
    
    // Test 7: Caso extremo con Phi muy pequeño (casi cero)
    Matrix Phi_small(2, 2);
    Phi_small(1,1) = 0.001; Phi_small(1,2) = 0.0;
    Phi_small(2,1) = 0.0; Phi_small(2,2) = 0.001;
    
    Matrix P7_updated = TimeUpdate(P, Phi_small, 1.0);
    
    // Con Phi pequeño, el resultado debe estar dominado por Qdt
    assert(P7_updated(1,1) > 0.9);  // Principalmente el valor de Qdt
    assert(P7_updated(2,2) > 0.9);
    
    // Test 8: Verificar comportamiento con matriz nula
    Matrix Qdt_zero = Matrix::eye(2) * 0.0;
    Matrix P_zero(2, 2);
    Matrix P8_updated = TimeUpdate(P_zero, Phi, Qdt_zero);
    
    // Con P=0, resultado debe ser solo Qdt (que es 0)
    assert(fabs(P8_updated(1,1) - 0.0) < 1e-14);
    assert(fabs(P8_updated(2,2) - 0.0) < 1e-14);
    assert(fabs(P8_updated(1,2) - 0.0) < 1e-14);
    
    // Test 9: Verificar excepciones con matrices no cuadradas
    Matrix P_rect(2, 3);  // Matriz rectangular
    Matrix Phi_rect(3, 2);  // Otra rectangular
    
    bool exception_thrown = false;
    try {
        TimeUpdate(P_rect, Phi);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    exception_thrown = false;
    try {
        TimeUpdate(P, Phi_rect);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    exception_thrown = false;
    try {
        Matrix Qdt_rect(2, 3);
        TimeUpdate(P, Phi, Qdt_rect);
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
}

REGISTER_TEST(test_TimeUpdate);