#ifndef _ECC_ANOM_
#define _ECC_ANOM_

//--------------------------------------------------------------------------
//
// EccAnom: Computes the eccentric anomaly for elliptic orbits
//
// Inputs:
//   M         Mean anomaly in [rad]
//   e         Eccentricity of the orbit [0,1]
// 
// Output:
//   E         Eccentric anomaly in [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double EccAnom(double M, double e);

#endif