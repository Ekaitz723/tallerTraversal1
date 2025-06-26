#ifndef _POSITION_
#define _POSITION_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// Position: Position vector (r [m]) from geodetic coordinates (Longitude [rad],
//           latitude [rad], altitude [m])
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix Position(double lon, double lat, double h);

#endif