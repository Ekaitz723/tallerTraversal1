#ifndef _EQN_EQUINOX_
#define _EQN_EQUINOX_

//--------------------------------------------------------------------------
//
// EqnEquinox: Computation of the equation of the equinoxes
//
// Input:
//   Mjd_TT    Modified Julian Date (Terrestrial Time)
// 
// Output:
//   EqE       Equation of the equinoxes
//
// Notes:
//   The equation of the equinoxes dpsi*cos(eps) is the right ascension of
//   the mean equinox referred to the true equator and equinox and is equal
//   to the difference between apparent and mean sidereal time.
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double EqnEquinox(double Mjd_TT);

#endif