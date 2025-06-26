#ifndef _TIMEDIFF_
#define _TIMEDIFF_

//--------------------------------------------------------------------------
//
// timediff: Time differences [s]
//
// Inputs:
//   UT1_UTC     UT1-UTC time difference [s]
//   TAI_UTC     TAI-UTC time difference [s]
//
// Outputs:
//   UT1_TAI     UT1-TAI time difference [s]
//   UTC_GPS     UTC-GPS time difference [s]  
//   UT1_GPS     UT1-GPS time difference [s]
//   TT_UTC      TT-UTC time difference [s]
//   GPS_UTC     GPS-UTC time difference [s]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void timediff(double UT1_UTC, double TAI_UTC, 
              double& UT1_TAI, double& UTC_GPS, double& UT1_GPS, 
              double& TT_UTC, double& GPS_UTC);

#endif