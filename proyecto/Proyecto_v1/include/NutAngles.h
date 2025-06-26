#ifndef _NUT_ANGLES_
#define _NUT_ANGLES_

//--------------------------------------------------------------------------
//
// NutAngles: Nutation in longitude and obliquity
//
// Input:
//   Mjd_TT     Modified Julian Date (Terrestrial Time)
//
// Output:
//   dpsi       Nutation in longitude [rad]
//   deps       Nutation in obliquity [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void NutAngles(double Mjd_TT, double& dpsi, double& deps);

#endif