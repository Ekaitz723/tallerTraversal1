#ifndef _HGIBBS_
#define _HGIBBS_

#include "Matrix.h"
#include <string>

//--------------------------------------------------------------------------
//
// hgibbs: Implements the Herrick-Gibbs approximation for orbit determination,
//         and finds the middle velocity vector for the 3 given position vectors.
//
// Inputs:
//   r1          ijk position vector #1         m
//   r2          ijk position vector #2         m  
//   r3          ijk position vector #3         m
//   Mjd1        Modified Julian Date of 1st sighting    days from 4713 bc
//   Mjd2        Modified Julian Date of 2nd sighting    days from 4713 bc
//   Mjd3        Modified Julian Date of 3rd sighting    days from 4713 bc
//
// Outputs:
//   v2          ijk velocity vector for r2     m/s (output parameter)
//   theta       angle between vectors          rad
//   theta1      angle between vectors          rad  
//   copa        coplanarity angle              rad
//   error       flag indicating success        'ok' or error message
//
//--------------------------------------------------------------------------
void hgibbs(const Matrix& r1, const Matrix& r2, const Matrix& r3,
            double Mjd1, double Mjd2, double Mjd3,
            Matrix*& v2, double& theta, double& theta1, double& copa, std::string& error);

#endif