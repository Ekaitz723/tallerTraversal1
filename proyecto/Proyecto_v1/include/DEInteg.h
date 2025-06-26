#ifndef _DEINTEG_
#define _DEINTEG_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// DEInteg: Numerical integration methods for ordinary differential equations
//
//   This module provides implementation of the variable order variable 
//   stepsize multistep method of Shampine & Gordon.
//
// Inputs:
//   func        Function handle for the right-hand side of the ODE system
//   t           Initial time
//   tout        Final time  
//   relerr      Relative error tolerance
//   abserr      Absolute error tolerance
//   n_eqn       Number of equations
//   y           Initial state vector
//
// Output:
//   y           Final state vector at time tout
//
// Reference:
//   Shampine, Gordon: "Computer solution of Ordinary Differential Equations",
//   Freeman and Comp., San Francisco (1975).
//
// Last modified:   2015/08/25   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix DEInteg(Matrix (*func)(double, const Matrix&), double t, double tout, 
               double relerr, double abserr, int n_eqn, const Matrix& y);

#endif