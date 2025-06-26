#ifndef _MATRIX_
#define _MATRIX_

// Sí, deberia haber hecho Vector y Vector3D, pero paso por completo no me apetece

class Matrix
{
    public:
        // Por defecto, zeros matrix
        Matrix(int fil); // Para vector columna
        static Matrix row_vector(int n); // Para vector fila
        Matrix(int fil, int col);
        Matrix(double x, double y, double z); // Para vector de 3 elementos (vertical)
        Matrix(int fil, int col, double v[], int n); // se introduce por columnas (se ve transpuesto en v[])
        Matrix(const Matrix& m);
        void assign_column(int col_index, const Matrix& v);
        void assign_column(int col_index, double* data, int datasize);
        void assign_row(int row_index, const Matrix& v);
        void assign_row(int row_index, double* data, int datasize);
        ~Matrix();

        // eye(int n) crea una matriz identidad de nxn, usando eye(conts int n)
        static Matrix eye(const int n);
        static double dot(const Matrix& a, const Matrix& b);
        static Matrix cross(const Matrix& a, const Matrix& b);
        static Matrix union_vector(const Matrix& a, const Matrix& b);
        static Matrix extract_vector(const Matrix& v, int start, int end);
        // estas dos static para marcar que dan nuevas matrices (vectores)
        static Matrix extract_column(const Matrix& m, int col_index);
        static Matrix extract_row(const Matrix& m, int row_index);

        double& operator()(const int i, const int j) const;
        double& operator()(const int n) const;
        Matrix& operator=(const Matrix& matrix2);
        Matrix  operator+(const Matrix& matrix2) const;
        Matrix  operator-(const Matrix& matrix2) const;
        Matrix  operator*(const Matrix& matrix2) const;
        Matrix  operator/(const Matrix& matrix2) const;
        Matrix  transpose() const;
        Matrix  inverse() const;
        double  determinant() const;
        double  norm() const;

        Matrix  operator*(const double scalar) const;
        Matrix  operator/(const double scalar) const;
        Matrix  operator+(const double scalar) const;
        Matrix  operator-(const double scalar) const;

        bool isVector() const { return (fil == 1 || col == 1); }
        bool isVector3D() const { return (fil == 3 && col == 1) || (fil == 1 && col == 3); } //sinceramente, no contemplé usar un vector 3D en horizontal, pero si tu kokoro lo quiere, adelante
        bool isVertical() const { return (isVector() && col == 1); }
        bool isSquare() const { return fil == col; }
        int size() const { return fil * col; }
        void print();
 
    private:
        void initMatrix(); //Zeros // Y siempre positivas las dimensiones
 
    private:
        int fil;
        int col;
        double **matrix;
};

#endif
