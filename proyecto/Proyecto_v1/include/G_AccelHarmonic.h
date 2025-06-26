#ifndef _G_ACCEL_HARMONIC_
#define _G_ACCEL_HARMONIC_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// G_AccelHarmonic: Computes the gradient of the Earth's harmonic gravity field 
//
// Inputs:
//   r           Satellite position vector in the true-of-date system
//   U           Transformation matrix to body-fixed system
//   n_max       Gravity model degree
//   m_max       Gravity model order
//
// Output:
//   G           Gradient (G=da/dr) in the true-of-date system
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix G_AccelHarmonic(const Matrix& r, const Matrix& U, int n_max, int m_max);

#endif