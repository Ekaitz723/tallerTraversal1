#ifndef _ACCEL_HARMONIC_
#define _ACCEL_HARMONIC_

#include "Matrix.h"

// Variables globales para coeficientes gravitacionales
extern Matrix* Cnm;
extern Matrix* Snm;

//--------------------------------------------------------------------------
//
// AccelHarmonic: Computes the acceleration due to the harmonic gravity field of the 
//                central body
//
// Inputs:
//   r           Satellite position vector in the inertial system
//   E           Transformation matrix to body-fixed system
//   n_max       Maximum degree
//   m_max       Maximum order (m_max<=n_max; m_max=0 for zonals, only)
//
// Output:
//   a           Acceleration (a=d^2r/dt^2)
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix AccelHarmonic(const Matrix& r, const Matrix& E, int n_max, int m_max);

#endif