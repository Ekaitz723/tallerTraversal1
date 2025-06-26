#ifndef _LTC_
#define _LTC_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// LTC: Transformation from Greenwich meridian system to 
//      local tangent coordinates
//
// Inputs:
//   lon      Geodetic East longitude [rad]
//   lat      Geodetic latitude [rad]
//   
// Output:
//   M        Rotation matrix from the Earth equator and Greenwich meridian
//            to the local tangent (East-North-Zenith) coordinate system
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix LTC(double lon, double lat);

#endif