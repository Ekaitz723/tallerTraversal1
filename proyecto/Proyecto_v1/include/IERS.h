#ifndef _IERS_
#define _IERS_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// IERS: Management of IERS time and polar motion data
//
// Inputs:
//   eop        IERS Earth orientation parameter data matrix
//   Mjd_UTC    Modified Julian Date (UTC)
//   interp     Interpolation flag ('l' for linear, 'n' for none)
//
// Outputs:
//   x_pole     Pole coordinate [rad]
//   y_pole     Pole coordinate [rad] 
//   UT1_UTC    UT1-UTC time difference [s]
//   LOD        Length of day [s]
//   dpsi       Nutation in longitude [rad]
//   deps       Nutation in obliquity [rad]
//   dx_pole    Pole coordinate [rad]
//   dy_pole    Pole coordinate [rad]
//   TAI_UTC    TAI-UTC time difference [s]
//
// Last modified:   2018/02/01   M. Mahooti
//
//--------------------------------------------------------------------------
void IERS(const Matrix& eop, double Mjd_UTC, char interp,
          double& x_pole, double& y_pole, double& UT1_UTC, double& LOD,
          double& dpsi, double& deps, double& dx_pole, double& dy_pole, double& TAI_UTC);

#endif