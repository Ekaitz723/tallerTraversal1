#ifndef _POLE_MATRIX_
#define _POLE_MATRIX_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// PoleMatrix: Transformation from pseudo Earth-fixed to Earth-fixed coordinates
//             for a given date
//
// Input:
//   xp        Pole coordinate [rad]
//   yp        Pole coordinate [rad]
//
// Output:
//   PoleMat   Pole matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix PoleMatrix(double xp, double yp);

#endif