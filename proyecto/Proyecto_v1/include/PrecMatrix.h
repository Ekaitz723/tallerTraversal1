#ifndef _PREC_MATRIX_
#define _PREC_MATRIX_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// PrecMatrix: Precession transformation of equatorial coordinates
//
// Input:
//   Mjd_1     Epoch given (Modified Julian Date TT)
//   Mjd_2     Epoch to precess to (Modified Julian Date TT)
// 
// Output:
//   PrecMat   Precession transformation matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix PrecMatrix(double Mjd_1, double Mjd_2);

#endif