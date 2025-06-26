#ifndef _VAR_EQN_
#define _VAR_EQN_

#include "Matrix.h"

//------------------------------------------------------------------------------
//
// VarEqn: Computes the variational equations, i.e. the derivative of the state vector
//         and the state transition matrix
//
// Input:
//   x           Time since epoch in [s]
//   yPhi        (6+36)-dim vector comprising the state vector (y) and the
//               state transition matrix (Phi) in column wise storage order
//
// Output:
//   yPhip       Derivative of yPhi
// 
// Last modified:   2015/08/12   M. Mahooti
//
//------------------------------------------------------------------------------
Matrix VarEqn(double x, const Matrix& yPhi);

#endif