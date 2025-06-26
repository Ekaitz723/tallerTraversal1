#ifndef _ACCEL_
#define _ACCEL_

#include "Matrix.h"

// Estructura para parametros auxiliares
struct AuxParam {
    double Mjd_UTC;
    double Mjd_TT;
    int n;
    int m;
    bool sun;
    bool moon;
    bool planets;
};

extern AuxParam auxParam;
extern Matrix* eopdata;

//--------------------------------------------------------------------------
//
// Accel: Computes the acceleration of an Earth orbiting satellite due to 
//        - the Earth's harmonic gravity field, 
//        - the gravitational perturbations of the Sun and Moon
//        - the solar radiation pressure and
//        - the atmospheric drag
//
// Inputs:
//   x           Time since epoch in [s]
//   Y           Satellite state vector in the ICRF/EME2000 system
//
// Output:
//   dY          Acceleration (a=d^2r/dt^2) in the ICRF/EME2000 system
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix Accel(double x, const Matrix& Y);

#endif