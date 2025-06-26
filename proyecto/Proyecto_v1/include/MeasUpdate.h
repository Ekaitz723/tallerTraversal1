#ifndef _MEAS_UPDATE_
#define _MEAS_UPDATE_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// MeasUpdate: Measurement update for Kalman filtering with scalar measurements
//
// Inputs:
//   x         State vector
//   z         Measurement scalar
//   g         Predicted measurement scalar  
//   s         Measurement standard deviation scalar
//   G         Observation matrix (Jacobian) 1xn
//   P         Covariance matrix nxn
//   n         State dimension
//
// Outputs:
//   K         Kalman gain vector
//   x         Updated state vector  
//   P         Updated covariance matrix
//
//--------------------------------------------------------------------------
void MeasUpdate(Matrix& x, double z, double g, double s, 
                const Matrix& G, Matrix& P, int n, Matrix*& K);

#endif