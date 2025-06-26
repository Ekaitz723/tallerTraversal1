#ifndef _GEODETIC_
#define _GEODETIC_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// Geodetic: Computes geodetic coordinates (Longitude [rad], latitude [rad], 
//           altitude [m]) from given position vector (r [m])
//
// Inputs:
//   r           Position vector [m] (3x1 Matrix: X, Y, Z coordinates)
//
// Outputs:
//   lon         Geodetic East longitude [rad]  
//   lat         Geodetic latitude [rad]
//   h           Altitude above reference ellipsoid [m]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void Geodetic(const Matrix& r, double& lon, double& lat, double& h);

#endif