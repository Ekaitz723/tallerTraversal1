#ifndef _MJDAY_TDB_
#define _MJDAY_TDB_

//--------------------------------------------------------------------------
//
// Mjday_TDB: Computes the Modified Julian Date for barycentric dynamical
//            time
//
// Inputs:
//   Mjd_TT      Modified julian date (TT)
//
// Output:
//   Mjd_TDB     Modified julian date (TDB)
//
// Reference:
// Vallado D. A; Fundamentals of Astrodynamics and Applications; McGraw-Hill;
// New York; 3rd edition(2007).
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double Mjday_TDB(double Mjd_TT);

#endif