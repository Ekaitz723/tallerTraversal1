#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <array>

/** @brief Constante gravitacional estándar de la Tierra (m³/s²) */
constexpr double MU = 3.986004418e14;  // m^3/s^2

/** @brief Valor pequeño para comparaciones numéricas */
constexpr double SMALL = 1.0e-6;

/**
 * @brief Clase para representar vectores 3D y operaciones vectoriales
 * 
 * Esta clase encapsula las operaciones básicas de álgebra vectorial
 * necesarias para los cálculos orbitales.
 */
class Vector3D {
public:
    double x, y, z;  ///< Componentes del vector 3D
    
    /** @brief Constructor por defecto, inicializa el vector nulo */
    Vector3D() : x(0.0), y(0.0), z(0.0) {}
    
    /**
     * @brief Constructor con componentes específicas
     * @param x_ Componente x
     * @param y_ Componente y  
     * @param z_ Componente z
     */
    Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
    
    /**
     * @brief Suma de vectores
     * @param other Vector a sumar
     * @return Vector resultado de la suma
     */
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }
    
    /**
     * @brief Resta de vectores
     * @param other Vector a restar
     * @return Vector resultado de la resta
     */
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }
    
    /**
     * @brief Multiplicación por escalar
     * @param scalar Valor escalar
     * @return Vector escalado
     */
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }
    
    /**
     * @brief División por escalar
     * @param scalar Valor escalar divisor
     * @return Vector dividido
     */
    Vector3D operator/(double scalar) const {
        return Vector3D(x / scalar, y / scalar, z / scalar);
    }
    
    /**
     * @brief Producto punto entre vectores
     * @param other Vector con el cual calcular el producto punto
     * @return Resultado del producto punto
     */
    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
    /**
     * @brief Producto cruz entre vectores
     * @param other Vector con el cual calcular el producto cruz
     * @return Vector resultado del producto cruz
     */
    Vector3D cross(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
    
    /**
     * @brief Calcula la magnitud (norma) del vector
     * @return Magnitud del vector
     */
    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    /** @brief Imprime el vector en formato [x, y, z] */
    void print() const {
        std::cout << "[" << x << ", " << y << ", " << z << "]";
    }
};

/** @brief Coeficientes c para la serie de Battin */
const std::array<double, 21> c_coeffs = {{
    0.2,
    9.0/35.0,
    16.0/63.0,
    25.0/99.0,
    36.0/143.0,
    49.0/195.0,
    64.0/255.0,
    81.0/323.0,
    100.0/399.0,
    121.0/483.0,
    144.0/575.0,
    169.0/675.0,
    196.0/783.0,
    225.0/899.0,
    256.0/1023.0,
    289.0/1155.0,
    324.0/1295.0,
    361.0/1443.0,
    400.0/1599.0,
    441.0/1763.0,
    484.0/1935.0
}};

/** @brief Coeficientes d para la serie de Battin */
const std::array<double, 21> d_coeffs = {{
    1.0/3.0,
    4.0/27.0,
    8.0/27.0,
    2.0/9.0,
    22.0/81.0,
    208.0/891.0,
    340.0/1287.0,
    418.0/1755.0,
    598.0/2295.0,
    700.0/2907.0,
    928.0/3591.0,
    1054.0/4347.0,
    1330.0/5175.0,
    1480.0/6075.0,
    1804.0/7047.0,
    1978.0/8091.0,
    2350.0/9207.0,
    2548.0/10395.0,
    2968.0/11655.0,
    3190.0/12987.0,
    3658.0/14391.0
}};

/**
 * @brief Implementación del método de Lambert-Battin para el problema de dos puntos en órbita
 * 
 * Esta clase resuelve el problema clásico de determinar la órbita que conecta dos vectores de posición en un tiempo dado, utilizando el método de Battin.
 */
class LambertBattin {
private:
    
    /**
     * @brief Función auxiliar de Battin para el cálculo iterativo
     * @param v Parámetro de entrada para la serie
     * @return Valor calculado de la función
     */
    static double seebatt(double v) {
        double sqrtopv = std::sqrt(1.0 + v);
        double eta = v / std::pow(1.0 + sqrtopv, 2);
        
        double delold = 1.0;
        double termold = c_coeffs[0];
        double sum1 = termold;
        int i = 0;
        
        while (i < 20 && std::abs(termold) > 1e-8) {
            double del_val = 1.0 / (1.0 + c_coeffs[i+1] * eta * delold);
            double term = termold * (del_val - 1.0);
            sum1 = sum1 + term;
            i = i + 1;
            delold = del_val;
            termold = term;
        }
        
        double seebat = 1.0 / ((1.0/(8.0*(1.0+sqrtopv))) * (3.0 + sum1 / (1.0+eta*sum1)));
        return seebat;
    }
    
    /**
     * @brief Segunda función auxiliar de Battin para el cálculo iterativo
     * @param v Parámetro de entrada para la serie
     * @return Valor calculado de la función
     */
    static double seebattk(double v) {
        double sum1 = d_coeffs[0];
        double delold = 1.0;
        double termold = d_coeffs[0];
        int i = 0;
        
        while (i <= 20 && std::abs(termold) > 1e-6) {
            double del_val = 1.0 / (1.0 + d_coeffs[i+1] * v * delold);
            double term = termold * (del_val - 1.0);
            sum1 = sum1 + term;
            i = i + 1;
            delold = del_val;
            termold = term;
        }
        
        return sum1;
    }

public:
    /**
     * @brief Estructura para almacenar el resultado del cálculo
     * 
     * Contiene los vectores de velocidad inicial y final, además de
     * un indicador de exito del cálculo.
     */
    struct Result {
        Vector3D vo;    ///< Vector velocidad inicial
        Vector3D v;     ///< Vector velocidad final
        bool success;   ///< Indica si el cálculo fue exitoso
        
        /** @brief Constructor para resultado fallido */
        Result(bool success_ = false) : success(success_) {}
        
        /**
         * @brief Constructor para resultado exitoso
         * @param vo_ Vector velocidad inicial
         * @param v_ Vector velocidad final
         * @param success_ Estado del cálculo (true por defecto)
         */
        Result(const Vector3D& vo_, const Vector3D& v_, bool success_ = true) 
            : vo(vo_), v(v_), success(success_) {}
    };
    
    /**
     * @brief Resuelve el problema de Lambert-Battin
     * 
     * Calcula los vectores de velocidad necesarios para ir desde la posición inicial ro hasta la posición final r en el tiempo especificado.
     * 
     * @param ro Vector posición inicial (m)
     * @param r Vector posición final (m)
     * @param dm Dirección del movimiento ("pro" para prograde, "retro" para retrógrado)
     * @param dtsec Tiempo de vuelo en segundos
     * @return Estructura Result con las velocidades calculadas
     */
    static Result solve(const Vector3D& ro, const Vector3D& r, const std::string& dm, double dtsec) {
        double y1 = 0.0;
        
        double magr = r.magnitude();
        double magro = ro.magnitude();
        double cos_delta_nu = ro.dot(r) / (magro * magr);
        Vector3D rcrossr = ro.cross(r);
        double magrcrossr = rcrossr.magnitude();
        
        double sin_delta_nu;
        if (dm == "pro") {
            sin_delta_nu = magrcrossr / (magro * magr);
        } else {
            sin_delta_nu = -magrcrossr / (magro * magr);
        }
        
        double dnu = std::atan2(sin_delta_nu, cos_delta_nu);
        
        if (dnu < 0.0) {
            dnu = 2.0 * M_PI + dnu;
        }
        
        double ror = magr / magro;
        double eps = ror - 1.0;
        double tan2w = 0.25 * eps * eps / (std::sqrt(ror) + ror * (2.0 + std::sqrt(ror)));
        double rp = std::sqrt(magro * magr) * (std::pow(std::cos(dnu * 0.25), 2) + tan2w);
        
        double L;
        if (dnu < M_PI) {
            L = (std::pow(std::sin(dnu * 0.25), 2) + tan2w) / 
                (std::pow(std::sin(dnu * 0.25), 2) + tan2w + std::cos(dnu * 0.5));
        } else {
            L = (std::pow(std::cos(dnu * 0.25), 2) + tan2w - std::cos(dnu * 0.5)) / 
                (std::pow(std::cos(dnu * 0.25), 2) + tan2w);
        }
        
        double m = MU * dtsec * dtsec / (8.0 * rp * rp * rp);
        double x = 10.0;
        double xn = L;
        double chord = std::sqrt(magro * magro + magr * magr - 2.0 * magro * magr * std::cos(dnu));
        double s = (magro + magr + chord) * 0.5;
        double lim1 = std::sqrt(m / L);
        
        int loops = 1;
        double y = 0.0;
        
        while (true) {
            x = xn;
            double tempx = seebatt(x);
            double denom = 1.0 / ((1.0 + 2.0*x + L) * (4.0*x + tempx*(3.0 + x)));
            double h1 = std::pow(L + x, 2) * (1.0 + 3.0*x + tempx) * denom;
            double h2 = m * (x - L + tempx) * denom;
            
            double b = 0.25 * 27.0 * h2 / std::pow(1.0 + h1, 3);
            
            if (b < -1.0) {
                xn = 1.0 - 2.0 * L;
            } else {
                if (y1 > lim1) {
                    xn = xn * (lim1 / y1);
                } else {
                    double u = 0.5 * b / (1.0 + std::sqrt(1.0 + b));
                    double k2 = seebattk(u);
                    y = ((1.0 + h1) / 3.0) * (2.0 + std::sqrt(1.0 + b) / (1.0 + 2.0*u*k2*k2));
                    xn = std::sqrt(std::pow((1.0 - L) * 0.5, 2) + m/(y*y)) - (1.0 + L) * 0.5;
                }
            }
            
            loops = loops + 1;
            y1 = std::sqrt(m / ((L + x) * (1.0 + x)));
            
            if ((std::abs(xn - x) < SMALL) || (loops > 30)) {
                break;
            }
        }
        
        double a = MU * dtsec * dtsec / (16.0 * rp * rp * xn * y1 * y1);
        
        double f, g, gdot;
        
        if (a < -SMALL) {
            // Órbita hiperbólica
            double arg1 = std::sqrt(s / (-2.0 * a));
            double arg2 = std::sqrt((s - chord) / (-2.0 * a));
            double alph = 2.0 * std::asinh(arg1);
            double beth = 2.0 * std::asinh(arg2);
            double dh = alph - beth;
            f = 1.0 - (a/magro) * (1.0 - std::cosh(dh));
            gdot = 1.0 - (a/magr) * (1.0 - std::cosh(dh));
            g = dtsec - std::sqrt(-a*a*a/MU) * (std::sinh(dh) - dh);
        } else if (a > SMALL) {
            // Órbita elíptica
            double arg1 = std::sqrt(s / (2.0 * a));
            double arg2 = std::sqrt((s - chord) / (2.0 * a));
            double sinv = arg2;
            double cosv = std::sqrt(1.0 - (magro + magr - chord)/(4.0 * a));
            double bete = 2.0 * std::acos(cosv);
            bete = 2.0 * std::asin(sinv);
            
            if (dnu > M_PI) {
                bete = -bete;
            }
            
            cosv = std::sqrt(1.0 - s/(2.0 * a));
            sinv = arg1;
            double am = s * 0.5;
            double ae = M_PI;
            double be = 2.0 * std::asin(std::sqrt((s - chord)/s));
            double tm = std::sqrt(am*am*am/MU) * (ae - (be - std::sin(be)));
            
            double alpe;
            if (dtsec > tm) {
                alpe = 2.0 * M_PI - 2.0 * std::asin(sinv);
            } else {
                alpe = 2.0 * std::asin(sinv);
            }
            
            double de = alpe - bete;
            f = 1.0 - (a/magro) * (1.0 - std::cos(de));
            gdot = 1.0 - (a/magr) * (1.0 - std::cos(de));
            g = dtsec - std::sqrt(a*a*a/MU) * (de - std::sin(de));
        } else {
            // Órbita parabólica
            std::cerr << "Error: orbita parabolica no soportada" << std::endl;
            return Result(false);
        }
        
        Vector3D vo = (r - ro * f) / g;
        Vector3D v = (r * gdot - ro) / g;
        
        return Result(vo, v, true);
    }
};

/**
 * @brief Función de prueba para la implementación de Lambert-Battin
 * 
 * Ejecuta un caso de prueba con vectores de posición predefinidos y muestra los resultados de velocidad calculados.
 */
void test_lambert_battin() {
    std::cout << "Prueba de implementacion de Lambert-Battin en C++" << std::endl;
    
    Vector3D r1(20.0e6, 20.0e6, 0);
    Vector3D r2(-20.0e6, 10.0e6, 0);
    double tof = 1.0 * 86400; // 1 dia en s
    
    auto result = LambertBattin::solve(r1, r2, "retro", tof);
    
    if (result.success) {
        std::cout << "V1 = ";
        result.vo.print();
        std::cout << " m/s" << std::endl;
        
        std::cout << "V2 = ";
        result.v.print();
        std::cout << " m/s" << std::endl;
    } else {
        std::cout << "Error en el calculo" << std::endl;
    }
}

/**
 * @brief Función principal del programa
 * @return Código de salida del programa
 */
int main() {
    test_lambert_battin();
    return 0;
}