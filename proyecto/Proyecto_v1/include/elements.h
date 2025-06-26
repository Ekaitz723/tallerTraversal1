#ifndef _ELEMENTS_
#define _ELEMENTS_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// Purpose:
//   Computes the osculating Keplerian elements from the satellite state
//   vector for elliptic orbits
//
// Input:
//    y        State vector (x,y,z,vx,vy,vz)
// 
// Outputs:
//    p        semilatus rectum [m]
//    a        Semimajor axis 
//    e        Eccentricity 
//    i        Inclination [rad]
//    Omega    Longitude of the ascending node [rad]
//    omega    Argument of pericenter [rad]
//    M        Mean anomaly [rad]
//
// Notes:
//   The function cannot be used with state vectors describing a circular
//   or non-inclined orbit.
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void elements(const Matrix& y, double& p, double& a, double& e, double& i, 
              double& Omega, double& omega, double& M);

#endif