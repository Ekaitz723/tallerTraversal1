#ifndef _UNIT_
#define _UNIT_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// unit: Calculates a unit vector given the original vector. If a
//       zero vector is input, the vector is set to zero.
//
// Input:
//   vec         vector
//
// Output:
//   outvec      unit vector
//
//--------------------------------------------------------------------------
Matrix unit(const Matrix& vec);

#endif