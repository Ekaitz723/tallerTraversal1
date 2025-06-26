#ifndef _GIBBS_
#define _GIBBS_

#include "Matrix.h"
#include <string>

//--------------------------------------------------------------------------
//
// gibbs: Performs the Gibbs method of orbit determination
//
// This method determines the velocity at the middle point of the 3 given
// position vectors.
//
// Inputs:
//   r1          ijk position vector #1         m
//   r2          ijk position vector #2         m  
//   r3          ijk position vector #3         m
//
// Outputs:
//   v2          ijk velocity vector for r2     m/s
//   theta       angle between vectors          rad
//   theta1      angle between r2,r3           rad
//   copa        coplanarity angle             rad
//   error       flag indicating success       "ok", "not coplanar", "impossible"
//
// Last modified:   2024/06/17   Translation from MATLAB
//
//--------------------------------------------------------------------------
void gibbs(const Matrix& r1, const Matrix& r2, const Matrix& r3, 
           Matrix*& v2, double& theta, double& theta1, double& copa, std::string& error);

#endif