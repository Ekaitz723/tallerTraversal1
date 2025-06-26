#ifndef _AZELPA_
#define _AZELPA_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// Purpose:
//  Computes azimuth, elevation and partials from local tangent coordinates
//
// Input:
//   s      Topocentric local tangent coordinates (East-North-Zenith frame)
// 
// Outputs:
//   Az     Azimuth [rad]
//   El     Elevation [rad]
//   dAds   Partials of azimuth w.r.t. s (1x3 row vector)
//   dEds   Partials of elevation w.r.t. s (1x3 row vector)
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void AzElPa(const Matrix& s, double& Az, double& El, Matrix*& dAds, Matrix*& dEds);

#endif