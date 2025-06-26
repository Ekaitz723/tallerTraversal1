#include "../include/Matrix.h"
#include <iostream>
#include "TestFramework.h"
#include <cassert>
#include <cmath>

Matrix::Matrix(int fil) : fil(fil), col(1)
{
    initMatrix();
}

// Para vector fila
Matrix Matrix::row_vector(int n)
{
    if (n <= 0) {
        throw std::runtime_error("Dimensión debe ser positiva");
    }
    
    Matrix result(1, n);
    // printf("Matrix::row_vector(int n) - Creando vector fila de dimensión %d\n", n);
    
    return result;
}


Matrix::Matrix(int fil, int col) : fil(fil), col(col)
{
    initMatrix();
}
 
Matrix::Matrix(double x, double y, double z) : fil(3), col(1)
{
    initMatrix();

    matrix[0][0] = x;
    matrix[1][0] = y;
    matrix[2][0] = z;
}

Matrix::Matrix(int fil, int col, const double v[], int n): fil(fil), col(col)
{
    // printf("Matrix::Matrix(int fil, int col, double v[], int n) - Creando matriz de %d filas y %d columnas con %d elementos\n", fil, col, n);
    initMatrix();
 
    int k = 0;
    
    for (int i = 0; i < col; i++)
        for (int j = 0; j < fil; j++){
            if (k < n)
                matrix[j][i] = v[k++];
            else
                matrix[j][i] = 0;
        }
}
 
Matrix::Matrix(const Matrix& m) : fil(m.fil), col(m.col)
{
    // printf("Matrix::Matrix(const Matrix& m) - Copia de matriz\n");
    initMatrix();
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = m.matrix[i][j];
}
 
Matrix::~Matrix()
{
    for (int i = 0; i < fil; i++)
        delete[] matrix[i];
 
    delete[] matrix;
}
 
void Matrix::initMatrix()
{
    if (fil <= 0 || col <= 0) {
        throw std::runtime_error("Dimensiones de la matriz deben ser positivas");
    }

    matrix = new double*[fil];
    for (int i = 0; i < fil; i++)
        matrix[i] = new double[col];
 
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = 0.0;
}
 
Matrix& Matrix::operator=(const Matrix& matrix2)
{
    // printf("Matrix::operator=(const Matrix& matrix2) - Asignación de matriz\n");
    if (this == &matrix2) {
        return *this; // Evitar autoasignación
    }
    if (fil != matrix2.fil || col != matrix2.col) {
        throw std::runtime_error("Dimensiones de las matrices no coinciden para la asignación");
    }
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            this->matrix[i][j] = matrix2.matrix[i][j];
 
    return *this;
}
 
Matrix Matrix::operator+(const Matrix& matrix2) const
{
    if (fil != matrix2.fil || col != matrix2.col) {
        throw std::runtime_error("Dimensiones de las matrices no coinciden para la suma");
    }
    Matrix result(fil, col);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
 
    return result;
}
 
Matrix Matrix::operator-(const Matrix& matrix2) const
{
    if (fil != matrix2.fil || col != matrix2.col) {
        throw std::runtime_error("Dimensiones de las matrices no coinciden para la resta");
    }
    Matrix result(fil, col);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] - matrix2.matrix[i][j];
 
    return result;
}
 
Matrix Matrix::operator*(const Matrix& matrix2) const
{
    if (col != matrix2.fil) {
        throw std::runtime_error("Dimensiones de las matrices no coinciden para la multiplicación");
    }
    Matrix result(fil, matrix2.col);
 
    for (int i = 0; i < this->fil ; i++){
        for (int j = 0; j < matrix2.col; j++){
            result.matrix[i][j] = 0;
            for (int k = 0; k < this->col; k++){
                result.matrix[i][j] = result.matrix[i][j] + this->matrix[i][k] * matrix2.matrix[k][j];
            }
        }
    }
 
    return result;
}
 
double& Matrix::operator()(const int i, const int j) const
{
    return matrix[i-1][j-1];
}

double& Matrix::operator()(const int n) const
{
    int nrow = (n - 1) / col;
    int ncol = (n - 1) % col;
    return matrix[nrow][ncol];
}

Matrix Matrix::operator/(const Matrix& matrix2) const
{
    // matrix2.fil == matrix2.col
    if (col != matrix2.fil) {
        throw std::runtime_error("Dimensiones de las matrices no coinciden para la división");
    }
    Matrix inv = matrix2.inverse();
    return (*this) * inv;
}

Matrix Matrix::inverse() const
{
    if (fil != col) {
        throw std::runtime_error("Matriz debe ser cuadrada para calcular la inversa");
    }
    
    double det = determinant();
    if (det == 0) {
        throw std::runtime_error("Matriz no invertible (det=0)");
    }

    Matrix adj(fil, col);
    Matrix result(fil, col);

    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {

            Matrix sub(fil-1, col-1);
            int sub_i = 0;
            int sub_j = 0;
            
            for (int k = 0; k < fil; k++) {
                if (k == i) continue;
                sub_j = 0;
                for (int l = 0; l < col; l++) {
                    if (l == j) continue;
                    sub.matrix[sub_i][sub_j] = matrix[k][l];
                    sub_j++;
                }
                sub_i++;
            }
            
            double cofactor = sub.determinant() * ((i + j) % 2 == 0 ? 1 : -1);
            adj.matrix[j][i] = cofactor;
        }
    }

    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            result.matrix[i][j] = adj.matrix[i][j] / det;
        }
    }

    return result;
}

double Matrix::determinant() const
{
    if (fil != col) {
        throw std::runtime_error("Matriz debe ser cuadrada para calcular el determinante");
    }

    if (fil == 1) {
        return matrix[0][0];
    }

    if (fil == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;
    for (int j = 0; j < col; j++) {
        Matrix sub(fil-1, col-1);
        for (int k = 1; k < fil; k++) {
            int sub_col = 0;
            for (int l = 0; l < col; l++) {
                if (l == j) continue;
                sub.matrix[k-1][sub_col] = matrix[k][l];
                sub_col++;
            }
        }
        det += matrix[0][j] * sub.determinant() * (j % 2 == 0 ? 1 : -1);
    }

    return det;
}
double Matrix::norm() const
{
    double sum = 0.0;
    for(int i = 0; i < fil; i++) {
        for(int j = 0; j < col; j++) {
            sum += matrix[i][j] * matrix[i][j];
        }
    }
    // printf("Norma: %f\n", sum);
    return std::sqrt(sum);
}


Matrix Matrix::operator*(const double scalar) const
{
    Matrix result(fil, col);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] * scalar;
 
    return result;
}
Matrix Matrix::operator/(const double scalar) const
{
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    //imprimir filas y columnas
    // printf("Filas: %d, Columnas: %d\n", fil, col);
    Matrix result(fil, col);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] / scalar;
 
    return result;
}
Matrix Matrix::operator+(const double scalar) const
{
    Matrix result(fil, col);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] + scalar;
 
    return result;
}
Matrix Matrix::operator-(const double scalar) const
{
    Matrix result(fil, col);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] - scalar;
 
    return result;
}
Matrix Matrix::transpose() const
{
    Matrix result(col, fil);
    
    for (int i = 0; i < fil; i++)
        for (int j = 0; j < col; j++)
            result.matrix[j][i] = matrix[i][j];
 
    return result;
}


// No se verifica direccionalidad del vector a proposito
void Matrix::assign_column(int col_index, const Matrix& v) {
    if(!v.isVector() || v.size() != fil) {
        throw std::runtime_error("vector debe tener dimension correcta");
    }
    if(col_index < 1 || col_index > col) {
        throw std::runtime_error("indice fuera de rango");
    }
    
    for(int i = 1; i <= fil; i++) {
        (*this)(i, col_index) = v(i);
    }
}
void Matrix::assign_row(int row_index, const Matrix& v) {
    if(!v.isVector() || v.size() != col) {
        throw std::runtime_error("vector debe tener dimension correcta");
    }
    if(row_index < 1 || row_index > fil) {
        throw std::runtime_error("indice fuera de rango");
    }
    
    for(int j = 1; j <= col; j++) {
        (*this)(row_index, j) = v(j);
    }
}

// si datasize es 0, pues todo 0 ya ves tu
void Matrix::assign_column(int col_index, const double* data, int datasize) {
    if(col_index < 1 || col_index > col) {
        throw std::runtime_error("indice fuera de rango");
    }
    
    int k = 0;
    for(int i = 1; i <= fil; i++) {
        if(k < datasize) {
            (*this)(i, col_index) = data[k++];
        } else {
            (*this)(i, col_index) = 0;
        }
    }
}
void Matrix::assign_row(int row_index, const double* data, int datasize) {
    if(row_index < 1 || row_index > fil) {
        throw std::runtime_error("indice fuera de rango");
    }
    
    int k = 0;
    for(int j = 1; j <= col; j++) {
        if(k < datasize) {
            (*this)(row_index, j) = data[k++];
        } else {
            (*this)(row_index, j) = 0;
        }
    }
}


Matrix Matrix::eye(const int n) 
{
    if (n <= 0) {
        throw std::runtime_error("Dimension debe ser positiva");
    }
    // printf("Matrix::eye(%d) - Creando matriz identidad\n", n);

    Matrix result(n, n); 
    for(int i = 1; i <= n; i++) {
        result(i, i) = 1.0;
    }
    return result;
}
double Matrix::dot(const Matrix& a, const Matrix& b) {
    if(!a.isVector() || !b.isVector()) {
        throw std::runtime_error("dot requiere vectores");
    }
    
    int len = a.size();
    if(len != b.size()) {
        throw std::runtime_error("vectores deben tener mismo tamaño");
    }
    
    double result = 0.0;
    for(int i = 1; i <= len; i++) { // 1-based index como en MatLab (horrible)
        result += a(i) * b(i);
    }
    return result;
}
Matrix Matrix::cross(const Matrix& a, const Matrix& b) {
    if(!a.isVector3D() || !b.isVector3D()) {
        throw std::runtime_error("cross requiere vectores 3D");
    }
    
    Matrix result(3, 1);
    result(1) = a(2)*b(3) - a(3)*b(2);  // x
    result(2) = a(3)*b(1) - a(1)*b(3);  // y  
    result(3) = a(1)*b(2) - a(2)*b(1);  // z
    
    return result;
}

// Concatenacion vertical [a; b]
// Concatenacion horizontal [a b]  
Matrix Matrix::union_vector(const Matrix& a, const Matrix& b) {
    if(!a.isVector() || !b.isVector()) {
        throw std::runtime_error("union_vector requiere vectores");
    }
    
    bool a_vertical = a.isVertical();
    bool b_vertical = b.isVertical();
    
    if(a_vertical != b_vertical) {
        throw std::runtime_error("vectores deben tener misma orientacion");
    }
    
    int size_a = a.size();
    int size_b = b.size();
    int total_size = size_a + size_b;

    Matrix result = a_vertical ? Matrix(total_size, 1) : Matrix(1, total_size);
    
    for(int i = 1; i <= size_a; i++) {
        result(i) = a(i);
    }
    for(int i = 1; i <= size_b; i++) {
        result(size_a + i) = b(i);
    }
    
    return result;
}

Matrix Matrix::extract_vector(const Matrix& v, int start, int end) {
    if(!v.isVector()) {
        throw std::runtime_error("extract_vector requiere un vector");
    }
    
    if(start < 1 || end > v.size() || start > end) {
        throw std::runtime_error("indices fuera de rango");
    }
    
    int new_size = end - start + 1;
    
    Matrix result = v.isVertical() ? Matrix(new_size, 1) : Matrix(1, new_size);
    
    for(int i = 1; i <= new_size; i++) {
        result(i) = v(start + i - 1);
    }
    
    return result;
}

Matrix Matrix::extract_column(const Matrix& m, int col_index) {
    if(col_index < 1 || col_index > m.col) {
        throw std::runtime_error("indice de columna fuera de rango");
    }
    
    Matrix result(m.fil, 1);
    for(int i = 1; i <= m.fil; i++) {
        result(i, 1) = m(i, col_index);
    }
    return result;
}

Matrix Matrix::extract_row(const Matrix& m, int row_index) {
    if(row_index < 1 || row_index > m.fil) {
        throw std::runtime_error("indice de fila fuera de rango");
    }
    
    Matrix result(1, m.col);
    for(int j = 1; j <= m.col; j++) {
        result(1, j) = m(row_index, j);
    }
    return result;
}

void Matrix::print()
{
    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void test_Matrix_constructors()
{
    // Test 1: Constructor basico Matrix(fil, col)
    Matrix m1(2, 3);
    assert(m1.size() == 6);
    
    // Test 2: Constructor vector columna Matrix(fil)
    Matrix v1(3);
    assert(v1.isVector());
    assert(v1.isVertical());
    assert(v1.size() == 3);
    
    // Test 3: Constructor vector 3D Matrix(x,y,z) 
    Matrix v3d(1.0, 2.0, 3.0);
    assert(v3d.isVector3D());
    assert(v3d.isVertical());
    assert(fabs(v3d(1) - 1.0) < 1e-15);
    assert(fabs(v3d(2) - 2.0) < 1e-15);
    assert(fabs(v3d(3) - 3.0) < 1e-15);
    
    // Test 4: Vector fila static
    Matrix vrow = Matrix::row_vector(4);
    assert(vrow.isVector());
    assert(!vrow.isVertical());
    assert(vrow.size() == 4);
    
    // Test 5: Constructor con array (por columnas) (se ve transpuesto en data[])
    double data[] = {1.0, 3.0, 
                    2.0, 4.0};
    Matrix m2(2, 2, data, 4);
    assert(fabs(m2(1,1) - 1.0) < 1e-15);
    assert(fabs(m2(1,2) - 2.0) < 1e-15);
    assert(fabs(m2(2,1) - 3.0) < 1e-15);
    assert(fabs(m2(2,2) - 4.0) < 1e-15);
}

void test_Matrix_operators()
{
    // Test 1: Acceso con indices - recordar que es base 1
    Matrix m(2, 2);
    m(1,1) = 1.0;
    m(1,2) = 2.0; 
    m(2,1) = 3.0;
    m(2,2) = 4.0;
    
    assert(fabs(m(1,1) - 1.0) < 1e-15);
    assert(fabs(m(2,2) - 4.0) < 1e-15);
    
    // Test 2: Acceso lineal
    assert(fabs(m(1) - 1.0) < 1e-15);  // Primer elemento
    assert(fabs(m(3) - 3.0) < 1e-15);  // Tercer elemento (por columnas)
    
    // Test 3: Suma de matrices
    Matrix a(2, 2);
    Matrix b(2, 2);
    a(1,1) = 1.0; a(1,2) = 2.0;
    a(2,1) = 3.0; a(2,2) = 4.0;
    b(1,1) = 5.0; b(1,2) = 6.0; 
    b(2,1) = 7.0; b(2,2) = 8.0;
    
    Matrix c = a + b;
    assert(fabs(c(1,1) - 6.0) < 1e-15);
    assert(fabs(c(2,2) - 12.0) < 1e-15);
    
    // Test 4: Multiplicacion por escalar
    Matrix d = a * 2.0;
    assert(fabs(d(1,1) - 2.0) < 1e-15);
    assert(fabs(d(2,2) - 8.0) < 1e-15);
    
    // Test 5: Multiplicacion de matrices
    Matrix e(2, 2);
    e(1,1) = 1.0; e(1,2) = 0.0;
    e(2,1) = 0.0; e(2,2) = 1.0;  // Matriz identidad
    
    Matrix f = a * e;  // a * I = a
    assert(fabs(f(1,1) - 1.0) < 1e-15);
    assert(fabs(f(2,2) - 4.0) < 1e-15);

    // Test 6: Más multiplicacion de matrices
    Matrix g(2, 2);
    g(1,1) = 2.0; g(1,2) = 3.0;
    g(2,1) = 7.0; g(2,2) = 5.0;
    Matrix h = a * g;  // Multiplicación de matrices

    // printf("Matriz h:\n");
    // h.print();
    // printf("Matriz a\n");
    // a.print();
    // printf("Matriz g\n");
    // g.print();
    assert(fabs(h(1,1) - 16.0) < 1e-15); // 1*2 + 2*4
    assert(fabs(h(1,2) - 13.0) < 1e-15); // 3*3 + 4*5
    assert(fabs(h(2,1) - 34.0) < 1e-15); // 1*3 + 2*5
    assert(fabs(h(2,2) - 29.0) < 1e-15); // 3*2 + 4*4

    // Test 7: Multiplicación por vector
    Matrix v(2, 1);
    v(1,1) = 1.0; v(2,1) = 2.0; // Vector columna
    Matrix result = a * v;  // Multiplicación de matriz por vector
    assert(fabs(result(1,1) - 5.0) < 1e-15); // 1*1 + 2*2 + 3*3
    assert(fabs(result(2,1) - 11.0) < 1e-15); // 1*2 + 2*3 + 3*4
    // dimensiones de result deben ser 2x1
    assert(result.size() == 2 && result.isVertical());
    // printf("Resultado de a * v:\n");
    // result.print();

    // Test 8: Transpuesta
    Matrix transposed = a.transpose();
    assert(fabs(transposed(1,1) - 1.0) < 1e-15);
    assert(fabs(transposed(1,2) - 3.0) < 1e-15);
    assert(fabs(transposed(2,1) - 2.0) < 1e-15);
    assert(fabs(transposed(2,2) - 4.0) < 1e-15);

    // Test 9: Inversa de matriz 2x2
    Matrix inv_test(2, 2);
    inv_test(1,1) = 4.0; inv_test(1,2) = 7.0;
    inv_test(2,1) = 2.0; inv_test(2,2) = 6.0;
    Matrix inv = inv_test.inverse();
    Matrix should_be_I = inv_test * inv;
    assert(fabs(should_be_I(1,1) - 1.0) < 1e-12);
    assert(fabs(should_be_I(2,2) - 1.0) < 1e-12);
    // printf("Matriz inversa:\n");
    // inv.print();
    // printf("Producto de matriz y su inversa (debe ser identidad):\n");
    // should_be_I.print();

}

void test_Matrix_math_functions()
{
    // Test 1: Matriz identidad
    Matrix I = Matrix::eye(3);
    
    // printf("Matriz identidad2:\n");
    assert(fabs(I(1,1) - 1.0) < 1e-15);
    assert(fabs(I(2,2) - 1.0) < 1e-15);
    assert(fabs(I(3,3) - 1.0) < 1e-15);
    assert(fabs(I(1,2)) < 1e-15);
    
    // Test 2: Transpuesta
    Matrix a(2, 3);
    a(1,1) = 1.0; a(1,2) = 2.0; a(1,3) = 3.0;
    a(2,1) = 4.0; a(2,2) = 5.0; a(2,3) = 6.0;
    
    Matrix aT = a.transpose();
    assert(fabs(aT(1,1) - 1.0) < 1e-15);
    assert(fabs(aT(2,1) - 2.0) < 1e-15);
    assert(fabs(aT(1,2) - 4.0) < 1e-15);
    assert(fabs(aT(3,2) - 6.0) < 1e-15);
    
    // Test 3: Determinante matriz 2x2
    Matrix det2(2, 2);
    det2(1,1) = 1.0; det2(1,2) = 2.0;
    det2(2,1) = 3.0; det2(2,2) = 4.0;
    double d = det2.determinant();
    assert(fabs(d - (-2.0)) < 1e-15);  // 1*4 - 2*3 = -2
    
    // Test 4: Norma de vector
    Matrix v(1.0, 2.0, 2.0);  // Vector (1,2,2)
    double norm = v.norm();
    assert(fabs(norm - 3.0) < 1e-15);  // sqrt(1+4+4) = 3
    
    // Test 5: Inversa matriz 2x2
    Matrix inv_test(2, 2);
    inv_test(1,1) = 4.0; inv_test(1,2) = 7.0;
    inv_test(2,1) = 2.0; inv_test(2,2) = 6.0;
    
    Matrix inv = inv_test.inverse();
    Matrix should_be_I = inv_test * inv;
    assert(fabs(should_be_I(1,1) - 1.0) < 1e-12);
    assert(fabs(should_be_I(2,2) - 1.0) < 1e-12);
}

void test_Matrix_vector_operations()
{
    // Test 1: Producto escalar
    Matrix a(3.0, 4.0, 0.0);
    Matrix b(1.0, 0.0, 5.0);
    double dot_result = Matrix::dot(a, b);
    assert(fabs(dot_result - 3.0) < 1e-15);  // 3*1 + 4*0 + 0*5 = 3
    
    // Test 2: Producto cruz
    Matrix v1(1.0, 0.0, 0.0);
    Matrix v2(0.0, 1.0, 0.0);
    Matrix cross_result = Matrix::cross(v1, v2);
    assert(fabs(cross_result(1)) < 1e-15);
    assert(fabs(cross_result(2)) < 1e-15);
    assert(fabs(cross_result(3) - 1.0) < 1e-15);  // i x j = k
    
    // Test 3: Union de vectores verticales
    Matrix va(2, 1);
    Matrix vb(2, 1);
    va(1) = 1.0; va(2) = 2.0;
    vb(1) = 3.0; vb(2) = 4.0;
    
    Matrix united = Matrix::union_vector(va, vb);
    assert(united.size() == 4);
    assert(fabs(united(1) - 1.0) < 1e-15);
    assert(fabs(united(4) - 4.0) < 1e-15);
    
    // Test 4: Extraccion de vector
    Matrix big_v(5, 1);
    for(int i = 1; i <= 5; i++) {
        big_v(i) = i * 10.0;
    }
    
    Matrix extracted = Matrix::extract_vector(big_v, 2, 4);
    assert(extracted.size() == 3);
    assert(fabs(extracted(1) - 20.0) < 1e-15);
    assert(fabs(extracted(3) - 40.0) < 1e-15);
}

void test_Matrix_assign_extract()
{
    // Test 1: Asignar columna con vector
    Matrix m(3, 3);
    Matrix col_vec(3, 1);
    col_vec(1) = 10.0; col_vec(2) = 20.0; col_vec(3) = 30.0;
    
    m.assign_column(2, col_vec);
    assert(fabs(m(1,2) - 10.0) < 1e-15);
    assert(fabs(m(2,2) - 20.0) < 1e-15);
    assert(fabs(m(3,2) - 30.0) < 1e-15);
    
    // Test 2: Extraer columna
    Matrix extracted_col = Matrix::extract_column(m, 2);
    assert(fabs(extracted_col(1) - 10.0) < 1e-15);
    assert(fabs(extracted_col(3) - 30.0) < 1e-15);
    
    // Test 3: Asignar fila con array
    double row_data[] = {100.0, 200.0, 300.0};
    m.assign_row(1, row_data, 3);
    assert(fabs(m(1,1) - 100.0) < 1e-15);
    assert(fabs(m(1,3) - 300.0) < 1e-15);
    
    // Test 4: Extraer fila
    Matrix extracted_row = Matrix::extract_row(m, 1);
    assert(extracted_row.size() == 3);
    assert(!extracted_row.isVertical());
    assert(fabs(extracted_row(1) - 100.0) < 1e-15);
}

void test_Matrix_properties()
{
    // Test 1: Verificaciones de tipo
    Matrix square(3, 3);
    Matrix rect(2, 4);
    Matrix vec_col(5, 1);
    Matrix vec_row = Matrix::row_vector(5);
    Matrix vec3d(1.0, 2.0, 3.0);
    
    assert(!square.isVector());
    assert(!rect.isVector());
    assert(vec_col.isVector());
    assert(vec_row.isVector());
    assert(vec3d.isVector());
    
    assert(vec_col.isVertical());
    assert(!vec_row.isVertical());
    assert(vec3d.isVertical());
    
    assert(vec3d.isVector3D());
    assert(!vec_col.isVector3D());  // Es de tamaño 5, no 3
    
    // Test 2: Tamaños
    assert(square.size() == 9);
    assert(rect.size() == 8);
    assert(vec_col.size() == 5);
}

REGISTER_TEST(test_Matrix_constructors);
REGISTER_TEST(test_Matrix_operators);
REGISTER_TEST(test_Matrix_math_functions);
REGISTER_TEST(test_Matrix_vector_operations);
REGISTER_TEST(test_Matrix_assign_extract);
REGISTER_TEST(test_Matrix_properties);