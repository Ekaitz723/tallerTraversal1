#ifndef _TIME_UPDATE_
#define _TIME_UPDATE_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// TimeUpdate: Time update of the covariance matrix for Kalman filtering
//
// Inputs:
//   P         Covariance matrix
//   Phi       State transition matrix
//   Qdt       Process noise covariance matrix (optional, default 0.0)
//
// Output:
//   P         Updated covariance matrix P = Phi*P*Phi' + Qdt
//
//--------------------------------------------------------------------------
Matrix TimeUpdate(const Matrix& P, const Matrix& Phi, double Qdt = 0.0); // si hay algo que no sea 0, se tratara como I * Qdt
Matrix TimeUpdate(const Matrix& P, const Matrix& Phi, const Matrix& Qdt);

#endif