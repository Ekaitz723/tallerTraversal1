#ifndef _NUT_MATRIX_
#define _NUT_MATRIX_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// NutMatrix: Transformation from mean to true equator and equinox
//
// Input:
//   Mjd_TT    Modified Julian Date (Terrestrial Time)
//
// Output:
//   NutMat    Nutation matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix NutMatrix(double Mjd_TT);

#endif