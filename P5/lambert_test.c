#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MU 3.986004418e14  // m^3/s^2
#define SMALL 1.0e-6
#define EPSILON 1.0e-3  // Tolerancia para comparaciones de punto flotante

#pragma fenv_access (on)

// usando tolerancia EPSILON
int double_equals(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

// Vector3D y operaciones
typedef struct {
    double x, y, z;
} Vector3D;

double dot_product(Vector3D a, Vector3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D cross_product(Vector3D a, Vector3D b) {
    Vector3D result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

double magnitude(Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D subtract_vectors(Vector3D a, Vector3D b) {
    Vector3D result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vector3D scale_vector(Vector3D v, double scalar) {
    Vector3D result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

//  plantando un unusedFunction quien? yo no
Vector3D add_vectors(Vector3D a, Vector3D b) {
    Vector3D result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

double seebatt(double v) {
    double c[21] = {
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
    };
    
    double sqrtopv = sqrt(1.0 + v);
    double eta = v / pow(1.0 + sqrtopv, 2);
    
    double delold = 1.0;
    double termold = c[0];
    double sum1 = termold;
    int i = 0;
    
    while (i < 20 && fabs(termold) > 1e-8) {
        double del_val = 1.0 / (1.0 + c[i+1] * eta * delold);
        double term = termold * (del_val - 1.0);
        sum1 = sum1 + term;
        i = i + 1;
        delold = del_val;
        termold = term;
    }
    
    double seebat = 1.0 / ((1.0/(8.0*(1.0+sqrtopv))) * (3.0 + sum1 / (1.0+eta*sum1)));
    return seebat;
}

double seebattk(double v) {
    double d[21] = {
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
    };
    
    double sum1 = d[0];
    double delold = 1.0;
    double termold = d[0];
    int i = 0;
    
    while (i <= 20 && fabs(termold) > 1e-6) {
        double del_val = 1.0 / (1.0 + d[i+1] * v * delold);
        double term = termold * (del_val - 1.0);
        sum1 = sum1 + term;
        i = i + 1;
        delold = del_val;
        termold = term;
    }
    
    return sum1;
}

int lambert_battin(Vector3D ro, Vector3D r, char* dm, double dtsec, Vector3D* vo, Vector3D* v) {
    double y1 = 0.0;
    
    double magr = magnitude(r);
    double magro = magnitude(ro);
    double cos_delta_nu = dot_product(ro, r) / (magro * magr);
    Vector3D rcrossr = cross_product(ro, r);
    double magrcrossr = magnitude(rcrossr);
    
    double sin_delta_nu;
    if (strcmp(dm, "pro") == 0) {
        sin_delta_nu = magrcrossr / (magro * magr);
    } else {
        sin_delta_nu = -magrcrossr / (magro * magr);
    }
    
    double dnu = atan2(sin_delta_nu, cos_delta_nu);
    
    if (dnu < 0.0) {
        dnu = 2.0 * M_PI + dnu;
    }
    
    double ror = magr / magro;
    double eps = ror - 1.0;
    double tan2w = 0.25 * eps * eps / (sqrt(ror) + ror * (2.0 + sqrt(ror)));
    double rp = sqrt(magro * magr) * (pow(cos(dnu * 0.25), 2) + tan2w);
    
    double L;
    if (dnu < M_PI) {
        L = (pow(sin(dnu * 0.25), 2) + tan2w) / 
            (pow(sin(dnu * 0.25), 2) + tan2w + cos(dnu * 0.5));
    } else {
        L = (pow(cos(dnu * 0.25), 2) + tan2w - cos(dnu * 0.5)) / 
            (pow(cos(dnu * 0.25), 2) + tan2w);
    }
    
    double m = MU * dtsec * dtsec / (8.0 * rp * rp * rp);
    double x = 10.0;
    double xn = L;
    double chord = sqrt(magro * magro + magr * magr - 2.0 * magro * magr * cos(dnu));
    double s = (magro + magr + chord) * 0.5;
    double lim1 = sqrt(m / L);
    
    int loops = 1;
    while (1) {
        x = xn;
        double tempx = seebatt(x);
        double denom = 1.0 / ((1.0 + 2.0*x + L) * (4.0*x + tempx*(3.0 + x)));
        double h1 = pow(L + x, 2) * (1.0 + 3.0*x + tempx) * denom;
        double h2 = m * (x - L + tempx) * denom;
        
        double b = 0.25 * 27.0 * h2 / pow(1.0 + h1, 3);
        
        if (b < -1.0) {
            xn = 1.0 - 2.0 * L;
        } else {
            if (y1 > lim1) {
                xn = xn * (lim1 / y1);
            } else {
                double u = 0.5 * b / (1.0 + sqrt(1.0 + b));
                double k2 = seebattk(u);
                double y = ((1.0 + h1) / 3.0) * (2.0 + sqrt(1.0 + b) / (1.0 + 2.0*u*k2*k2));
                xn = sqrt(pow((1.0 - L) * 0.5, 2) + m/(y*y)) - (1.0 + L) * 0.5;
            }
        }
        
        loops = loops + 1;
        y1 = sqrt(m / ((L + x) * (1.0 + x)));
        
        if ((fabs(xn - x) < SMALL) || (loops > 30)) {
            break;
        }
    }
    
    double a = MU * dtsec * dtsec / (16.0 * rp * rp * xn * y1 * y1);
    
    double f, g, gdot;
    
    if (a < -SMALL) {
        // Hiperbólica
        double arg1 = sqrt(s / (-2.0 * a));
        double arg2 = sqrt((s - chord) / (-2.0 * a));
        double alph = 2.0 * asinh(arg1);
        double beth = 2.0 * asinh(arg2);
        double dh = alph - beth;
        f = 1.0 - (a/magro) * (1.0 - cosh(dh));
        gdot = 1.0 - (a/magr) * (1.0 - cosh(dh));
        g = dtsec - sqrt(-a*a*a/MU) * (sinh(dh) - dh);
    } else if (a > SMALL) {
        // Elíptica
        double arg1 = sqrt(s / (2.0 * a));
        double arg2 = sqrt((s - chord) / (2.0 * a));
        double sinv = arg2;
        double cosv = sqrt(1.0 - (magro + magr - chord)/(4.0 * a));
        double bete = 2.0 * acos(cosv);
        bete = 2.0 * asin(sinv);
        
        if (dnu > M_PI) {
            bete = -bete;
        }
        
        cosv = sqrt(1.0 - s/(2.0 * a));
        sinv = arg1;
        double am = s * 0.5;
        double ae = M_PI;
        double be = 2.0 * asin(sqrt((s - chord)/s));
        double tm = sqrt(am*am*am/MU) * (ae - (be - sin(be)));
        
        double alpe;
        if (dtsec > tm) {
            alpe = 2.0 * M_PI - 2.0 * asin(sinv);
        } else {
            alpe = 2.0 * asin(sinv);
        }
        
        double de = alpe - bete;
        f = 1.0 - (a/magro) * (1.0 - cos(de));
        gdot = 1.0 - (a/magr) * (1.0 - cos(de));
        g = dtsec - sqrt(a*a*a/MU) * (de - sin(de));
    } else {
        // Parabólica
        printf("Error: orbita parabolica no soportada\n");
        return -1;
    }
    
    Vector3D temp1 = subtract_vectors(r, scale_vector(ro, f));
    *vo = scale_vector(temp1, 1.0/g);
    
    Vector3D temp2 = subtract_vectors(scale_vector(r, gdot), ro);
    *v = scale_vector(temp2, 1.0/g);
    
    return 0;
}

// Tests usando assert.h
void test_vector_operations() {
    printf("Test operaciones de vectores\n");
    
    // dot
    Vector3D v1 = {1.0, 2.0, 3.0};
    Vector3D v2 = {4.0, 5.0, 6.0};
    double dot = dot_product(v1, v2);
    assert(double_equals(dot, 32.0, EPSILON));
    
    // cross 
    Vector3D cross = cross_product(v1, v2);
    assert(double_equals(cross.x, -3.0, EPSILON));
    assert(double_equals(cross.y, 6.0, EPSILON));
    assert(double_equals(cross.z, -3.0, EPSILON));
    
    // magnitude
    Vector3D v3 = {3.0, 4.0, 0.0};
    double mag = magnitude(v3);
    assert(double_equals(mag, 5.0, EPSILON));
    
    printf("Operaciones de vectores BIEN\n");
}

void test_seebatt_function() {
    printf("Test funcion seebatt\n");
    
    double result1 = seebatt(0.1);
    assert(result1 > 0.0);
    assert(!isnan(result1));
    assert(!isinf(result1));
    
    double result2 = seebatt(1.0);
    assert(result2 > 0.0);
    assert(!isnan(result2));
    assert(!isinf(result2));
    
    printf("Funcion seebatt BIEN\n");
}

void test_seebattk_function() {
    printf("Test funcion seebattk\n");
    
    double result1 = seebattk(0.1);
    assert(result1 > 0.0);
    assert(!isnan(result1));
    assert(!isinf(result1));
    
    double result2 = seebattk(0.5);
    assert(result2 > 0.0);
    assert(!isnan(result2));
    assert(!isinf(result2));
    
    printf("Funcion seebattk BIEN\n");
}

void test_lambert_battin_basic() {
    printf("Test Lambert-Battin\n");
    
    // Caso de prueba: transferencia entre dos puntos
    Vector3D r1 = {7000000.0, 0.0, 0.0};
    Vector3D r2 = {0.0, 7000000.0, 0.0};
    double tof = 3600.0; // 1h
    
    Vector3D v1, v2;
    
    int result = lambert_battin(r1, r2, "pro", tof, &v1, &v2);

    // retorna exito
    assert(result == 0);
    
    assert(!isnan(v1.x) && !isnan(v1.y) && !isnan(v1.z));
    assert(!isnan(v2.x) && !isnan(v2.y) && !isnan(v2.z));
    assert(!isinf(v1.x) && !isinf(v1.y) && !isinf(v1.z));
    assert(!isinf(v2.x) && !isinf(v2.y) && !isinf(v2.z));
    double mag_v1 = magnitude(v1);
    double mag_v2 = magnitude(v2);
    assert(mag_v1 > 0.0 && mag_v1 < 20000.0);
    assert(mag_v2 > 0.0 && mag_v2 < 20000.0);
    
    printf("Lambert-Battin BIEN\n");
    printf("\tV1 magnitud: %.3f m/s\n", mag_v1);
    printf("\tV2 magnitud: %.3f m/s\n", mag_v2);
}

void test_lambert_battin_edge_cases() {
    printf("Test Lambert-Battin casos limite\n");
    
    Vector3D v1, v2;
    
    // tiempo pequeño (1s)
    Vector3D r1 = {7000000.0, 0.0, 0.0};
    Vector3D r2 = {7100000.0, 0.0, 0.0};
    double small_tof = 1.0;
    
    int result1 = lambert_battin(r1, r2, "pro", small_tof, &v1, &v2);
    
    // posiciones muy diferentes
    Vector3D r3 = {6000000.0, 0.0, 0.0};
    Vector3D r4 = {42000000.0, 0.0, 0.0};
    double long_tof = 86400.0;
    
    int result2 = lambert_battin(r3, r4, "pro", long_tof, &v1, &v2);
    if (result2 == 0) {
        assert(!isnan(v1.x) && !isnan(v1.y) && !isnan(v1.z));
        assert(!isnan(v2.x) && !isnan(v2.y) && !isnan(v2.z));
    }
    
    printf("Lambert-Battin casos limite BIEM\n");
}

void test_lambert_battin_original() {
    printf("Test caso original de Lambert-Battin\n");
    
    Vector3D r1 = {20.0e6, 20.0e6, 0};
    Vector3D r2 = {-20.0e6, 10.0e6, 0};
    double tof = 1.0 * 86400;
    
    Vector3D v1, v2;
    
    int result = lambert_battin(r1, r2, "retro", tof, &v1, &v2);
    
    assert(result == 0);
    assert(!isnan(v1.x) && !isnan(v1.y) && !isnan(v1.z));
    assert(!isnan(v2.x) && !isnan(v2.y) && !isnan(v2.z));
    
    printf("\tV1 = [%.6f, %.6f, %.6f] m/s\n", v1.x, v1.y, v1.z);
    printf("\tV2 = [%.6f, %.6f, %.6f] m/s\n", v2.x, v2.y, v2.z);
    printf("Caso original Lambert-Battin BIEN\n");
}

void run_all_tests() {
    printf("Test con assert.h\n\n");
    
    test_vector_operations();
    test_seebatt_function();
    test_seebattk_function();
    test_lambert_battin_basic();
    test_lambert_battin_edge_cases();
    test_lambert_battin_original();

    printf("Tests pasados\n");
}

int main() {
    // assert: gcc -o test lambert_test.c -lm
    // assertn't: gcc -DNDEBUG -o test lambert_test.c -lm

    run_all_tests();
    return 0;
}