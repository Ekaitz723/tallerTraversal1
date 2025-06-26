#ifndef _ANGLESG_
#define _ANGLESG_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// anglesg: Solves the problem of orbit determination using three
//          optical sightings
//
// Inputs:
//   az1         Azimuth at t1                     rad
//   az2         Azimuth at t2                     rad  
//   az3         Azimuth at t3                     rad
//   el1         Elevation at t1                   rad
//   el2         Elevation at t2                   rad
//   el3         Elevation at t3                   rad
//   Mjd1        Modified julian date of t1
//   Mjd2        Modified julian date of t2  
//   Mjd3        Modified julian date of t3
//   Rs1         ijk site1 position vector         m
//   Rs2         ijk site2 position vector         m
//   Rs3         ijk site3 position vector         m
//   eopdata     IERS Earth orientation parameters
//
// Outputs:
//   r2          ijk position vector at t2         m (output parameter)
//   v2          ijk velocity vector at t2         m/s (output parameter)
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void anglesg(double az1, double az2, double az3, double el1, double el2, double el3,
             double Mjd1, double Mjd2, double Mjd3, 
             const Matrix& Rs1, const Matrix& Rs2, const Matrix& Rs3,
             const Matrix& eopdata, Matrix*& r2, Matrix*& v2);

#endif