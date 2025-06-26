#ifndef _CHEB3D_
#define _CHEB3D_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// Cheb3D: Chebyshev approximation of 3-dimensional vectors
//
// Inputs:
//   t           Time
//   N           Number of coefficients
//   Ta          Begin interval
//   Tb          End interval
//   Cx          Coefficients of Chebyshev polynomial (x-coordinate)
//   Cy          Coefficients of Chebyshev polynomial (y-coordinate)
//   Cz          Coefficients of Chebyshev polynomial (z-coordinate)
//
// Output:
//   ChebApp     3D vector approximation
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix Cheb3D(double t, int N, double Ta, double Tb, 
              double Cx[], double Cy[], double Cz[]);

#endif