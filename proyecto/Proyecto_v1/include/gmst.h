#ifndef _GMST_
#define _GMST_

//--------------------------------------------------------------------------
//
// gmst: Greenwich Mean Sidereal Time
//
// Input:
//   Mjd_UT1    Modified Julian Date UT1
//
// Output:
//   gmstime    GMST in [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double gmst(double Mjd_UT1);

#endif