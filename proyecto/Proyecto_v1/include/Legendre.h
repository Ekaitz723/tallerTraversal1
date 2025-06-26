#ifndef _LEGENDRE_
#define _LEGENDRE_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// Legendre: Computes associated Legendre polynomials and their derivatives
//
// Inputs:
//   n       Maximum degree
//   m       Maximum order
//   fi      Latitude [rad]
//
// Outputs:
//   pnm     Associated Legendre polynomials
//   dpnm    Derivatives of associated Legendre polynomials
//
//--------------------------------------------------------------------------
void Legendre(int n, int m, double fi, Matrix*& pnm, Matrix*& dpnm);

#endif