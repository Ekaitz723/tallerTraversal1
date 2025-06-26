#ifndef _EKF_GEOS3_
#define _EKF_GEOS3_

#include "Matrix.h"

//--------------------------------------------------------------------------
//
// EKF_GEOS3: Initial Orbit Determination using Gauss and Extended Kalman Filter methods
//
// Purpose:
//   Implements the Extended Kalman Filter for orbit determination using
//   azimuth, elevation and range observations from the GEOS-3 mission
//
// References:
//   O. Montenbruck, E. Gill, "Satellite Orbits - Models, Methods, and
//   Applications", Springer Verlag, Heidelberg, 2000.
//   
//   D. Vallado, "Fundamentals of Astrodynamics and Applications", 
//   4th Edition, 2013.
//
//   G. Seeber, "Satellite Geodesy", 2nd Edition, 2003.
//
// Last modified:   2020/03/16   Meysam Mahooti
//
//--------------------------------------------------------------------------

struct EKFResults {
    Matrix* Y0;          // Estaod final estimado en t0
    Matrix* P;           // Matriz de covarianza final 
    double position_error[3];  // Errores de posicion [m]
    double velocity_error[3];  // Errores de velocidad [m/s]
    
    EKFResults() : Y0(nullptr), P(nullptr) {
        for (int i = 0; i < 3; i++) {
            position_error[i] = 0.0;
            velocity_error[i] = 0.0;
        }
    }
    
    ~EKFResults() {
        delete Y0;
        delete P;
    }
};

//--------------------------------------------------------------------------
//
// EKF_GEOS3: Main function for orbit determination using Extended Kalman Filter
//
// Purpose:
//   Processes GEOS-3 observations using Extended Kalman Filter to determine
//   satellite orbit. Reads observations, applies Gauss method for initial
//   orbit determination, then refines using EKF with azimuth, elevation 
//   and range measurements.
//
// Inputs:
//   None (reads from data files)
//
// Output:
//   results      Pointer to structure containing final state estimation and errors
//
//--------------------------------------------------------------------------
EKFResults* EKF_GEOS3();

#endif