#ifndef _GAST_
#define _GAST_

//--------------------------------------------------------------------------
//
// gast: Greenwich Apparent Sidereal Time
//
// Input:
//   Mjd_UT1   Modified Julian Date UT1
//
// Output:
//   gstime    GAST in [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double gast(double Mjd_UT1);

#endif