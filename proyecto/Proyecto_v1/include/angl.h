#ifndef _ANGL_
#define _ANGL_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// angl: Computes the angle between two vectors
//
// Inputs:
//   vec1         Vector 1
//   vec2         Vector 2
//
// Output:
//   theta        Angle between the two vectors  -pi to pi
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------
double angl(const Matrix& vec1, const Matrix& vec2);

#endif