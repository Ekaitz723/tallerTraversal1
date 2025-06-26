#ifndef _MEAN_OBLIQUITY_
#define _MEAN_OBLIQUITY_

//--------------------------------------------------------------------------
//
// MeanObliquity: Computes the mean obliquity of the ecliptic
//
// Input:
//   Mjd_TT    Modified Julian Date (Terrestrial Time)
//
// Output:
//   MOblq     Mean obliquity of the ecliptic [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double MeanObliquity(double Mjd_TT);

#endif