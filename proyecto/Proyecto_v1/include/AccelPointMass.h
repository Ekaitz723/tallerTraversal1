#ifndef _ACCEL_POINT_MASS_
#define _ACCEL_POINT_MASS_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// AccelPointMass: Computes the perturbational acceleration due to a point
//				   mass
//
// Inputs:
//   r           Satellite position vector 
//   s           Point mass position vector
//   GM          Gravitational coefficient of point mass
//
// Output:
//   a    		Acceleration (a=d^2r/dt^2)
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix AccelPointMass(const Matrix& r, const Matrix& s, double GM);

#endif