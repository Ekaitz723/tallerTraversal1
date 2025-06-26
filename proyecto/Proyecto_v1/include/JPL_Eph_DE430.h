#ifndef _JPL_EPH_DE430_
#define _JPL_EPH_DE430_

#include "Matrix.h"

// Variable global para coeficientes planetarios DE430
extern Matrix* PC;

//--------------------------------------------------------------------------
//
// JPL_Eph_DE430: Computes the sun, moon, and nine major planets' equatorial
//                position using JPL Ephemerides
//
// Inputs:
//   Mjd_TDB         Modified julian date of TDB
//
// Output:
//   r_Mercury,r_Venus,r_Earth,r_Mars,r_Jupiter,r_Saturn,r_Uranus,
//   r_Neptune,r_Pluto,r_Moon,r_Sun - Geocentric equatorial position ([m]) 
//   referred to the International Celestial Reference Frame (ICRF)
//
// Notes: Light-time is already taken into account
//
// Last modified:   2018/01/11   M. Mahooti
//
//--------------------------------------------------------------------------
void JPL_Eph_DE430(double Mjd_TDB, 
                   Matrix*& r_Mercury, Matrix*& r_Venus, Matrix*& r_Earth, Matrix*& r_Mars,
                   Matrix*& r_Jupiter, Matrix*& r_Saturn, Matrix*& r_Uranus, 
                   Matrix*& r_Neptune, Matrix*& r_Pluto, Matrix*& r_Moon, Matrix*& r_Sun);

#endif