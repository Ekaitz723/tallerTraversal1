#include "EKF_GEOS3.h"
#include "anglesg.h"
#include "Mjday.h"
#include "DEInteg.h"
#include "Accel.h"
#include "LTC.h"
#include "IERS.h"
#include "timediff.h"
#include "VarEqn.h"
#include "gmst.h"
#include "TimeUpdate.h"
#include "AzElPa.h"
#include "MeasUpdate.h"
#include "Position.h"
#include "R_e.h"
#include "Sat_const.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

extern Matrix* Cnm;
extern Matrix* Snm;
extern AuxParam auxParam;
extern Matrix* eopdata;
extern Matrix* PC;

static int n_eqn = 6;

EKFResults* EKF_GEOS3()
{
    EKFResults* results = new EKFResults();
    
    // Cargar coefficientes, leer dimensiones, inicializar PC cnm snm

    std::ifstream de430File("./data/DE430Coeff.csv");
    if (!de430File.is_open()) {
        std::cerr << "Error: Cannot open ./data/DE430Coeff.csv" << std::endl;
        std::cerr << "Please convert DE430Coeff.mat to CSV using MATLAB:" << std::endl;
        std::cerr << "load('./data/DE430Coeff.mat'); csvwrite('./data/DE430Coeff.csv', DE430Coeff);" << std::endl;
        results->Y0 = new Matrix(6, 1);
        return results;
    }

    std::vector<std::vector<double>> de430_data;
    std::string line;
    int cols = 0;

    while (std::getline(de430File, line)) {
        std::vector<double> row;
        std::istringstream iss(line);
        std::string cell;

        while (std::getline(iss, cell, ',')) {
            row.push_back(std::stod(cell));
        }

        if (row.size() > 0) {
            if (cols == 0) cols = row.size();
            de430_data.push_back(row);
        }
    }
    de430File.close();

    int rows = de430_data.size();
    PC = new Matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols && j < (int)de430_data[i].size(); j++) {
            (*PC)(i+1, j+1) = de430_data[i][j];
        }
    }

    // std::cout << "DE430 coefficients loaded: " << rows << "x" << cols << " matrix" << std::endl;
    
    Cnm = new Matrix(181, 181);  // zeros(181,181)
    Snm = new Matrix(181, 181);  // zeros(181,181)
    
    std::ifstream gravFile("./data/GGM03S.txt");
    if (!gravFile.is_open()) {
        std::cerr << "Error: Cannot open GGM03S.txt" << std::endl;
        results->Y0 = new Matrix(6, 1);
        return results;
    }
    
    for (int n = 0; n <= 180; n++) {
        for (int m = 0; m <= n; m++) {
            int temp_n, temp_m;
            double temp_cnm, temp_snm, temp_dummy1, temp_dummy2;
            gravFile >> temp_n >> temp_m >> temp_cnm >> temp_snm >> temp_dummy1 >> temp_dummy2;
            (*Cnm)(n+1, m+1) = temp_cnm;
            (*Snm)(n+1, m+1) = temp_snm;
        }
    }
    gravFile.close();
    
    // Read Earth orientation parameters
    std::ifstream eopFile("./data/eop19620101.txt");
    if (!eopFile.is_open()) {
        std::cerr << "Error: Cannot open eop19620101.txt" << std::endl;
        results->Y0 = new Matrix(6, 1);
        return results;
    }
    
    // EOP data matrix (13 x number_of_records)
    std::vector<std::vector<double>> eop_vector;
    // std::string line;
    while (std::getline(eopFile, line)) {
        std::istringstream iss(line);
        std::vector<double> row;
        double value;
        for (int i = 0; i < 13; i++) {
            if (iss >> value) {
                row.push_back(value);
            }
        }
        if (row.size() == 13) {
            eop_vector.push_back(row);
        }
    }
    eopFile.close();
    
    eopdata = new Matrix(13, eop_vector.size());
    for (size_t i = 0; i < eop_vector.size(); i++) {
        for (int j = 0; j < 13; j++) {
            (*eopdata)(j+1, i+1) = eop_vector[i][j];
        }
    }
    
    const int nobs = 46;
    Matrix obs(nobs, 4);
    
    std::ifstream obsFile("./data/GEOS3.txt");
    if (!obsFile.is_open()) {
        std::cerr << "Error: Cannot open GEOS3.txt" << std::endl;
        results->Y0 = new Matrix(6, 1);
        return results;
    }
    
    for (int i = 1; i <= nobs; i++) {
        std::string tline;
        if (!std::getline(obsFile, tline)) break;
        
        int Y = std::stoi(tline.substr(0, 4));
        int M = std::stoi(tline.substr(5, 2));
        int D = std::stoi(tline.substr(8, 2));
        int h = std::stoi(tline.substr(12, 2));
        int m = std::stoi(tline.substr(15, 2));
        double s = std::stod(tline.substr(18, 6));
        double az = std::stod(tline.substr(25, 8));
        double el = std::stod(tline.substr(35, 7));
        double Dist = std::stod(tline.substr(44, 10));
        
        obs(i, 1) = Mjday(Y, M, D, h, m, s);
        obs(i, 2) = Rad * az;
        obs(i, 3) = Rad * el;
        obs(i, 4) = 1e3 * Dist;
    }
    obsFile.close();
    
    // ruido
    double sigma_range = 92.5;           // [m]
    double sigma_az = 0.0224 * Rad;      // [rad]
    double sigma_el = 0.0139 * Rad;      // [rad]
    
    // Kaena Point 
    double lat = Rad * 21.5748;          // [rad]
    double lon = Rad * (-158.2706);      // [rad]
    double alt = 300.20;                 // [m]
    
    Matrix Rs = Position(lon, lat, alt);
    
    // Initial orbit determination . Gauss
    double Mjd1 = obs(1, 1);
    double Mjd2 = obs(9, 1);
    double Mjd3 = obs(18, 1);
    
    Matrix* r2 = nullptr;
    Matrix* v2 = nullptr;
    anglesg(obs(1,2), obs(9,2), obs(18,2), obs(1,3), obs(9,3), obs(18,3),
            Mjd1, Mjd2, Mjd3, Rs, Rs, Rs, *eopdata, r2, v2);
    
    Matrix Y0_apr = Matrix::union_vector(*r2, *v2);  // [r2;v2]
    
    double Mjd0 = Mjday(1995, 1, 29, 2, 38, 0);
    double Mjd_UTC = obs(9, 1);
    
    auxParam.Mjd_UTC = Mjd_UTC;
    auxParam.n = 20;
    auxParam.m = 20;
    auxParam.sun = true;
    auxParam.moon = true;
    auxParam.planets = true;
    
    n_eqn = 6;
    
    Matrix Y = DEInteg(Accel, 0, -(obs(9,1) - Mjd0) * 86400.0, 1e-13, 1e-6, 6, Y0_apr);
    
    // Cov
    Matrix P = Matrix::eye(6);
    for (int i = 1; i <= 3; i++) {
        P(i, i) = 1e8;
    }
    for (int i = 4; i <= 6; i++) {
        P(i, i) = 1e3;
    }
    
    Matrix LT = LTC(lon, lat);
    
    Matrix yPhi(42, 1);
    Matrix Phi(6, 6);
    
    // Measurement loop
    double t = 0;
    
    for (int i = 1; i <= nobs; i++) {
        // Previous step
        double t_old = t;
        Matrix Y_old = Y;
        
        // Time increment and propagation
        Mjd_UTC = obs(i, 1);
        t = (Mjd_UTC - Mjd0) * 86400.0;
        
        double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
        IERS(*eopdata, Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
        
        double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
        timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
        
        double Mjd_TT = Mjd_UTC + TT_UTC/86400.0;
        double Mjd_UT1 = Mjd_TT + (UT1_UTC - TT_UTC)/86400.0;
        
        auxParam.Mjd_UTC = Mjd_UTC;
        auxParam.Mjd_TT = Mjd_TT;
        
        for (int ii = 1; ii <= 6; ii++) {
            yPhi(ii) = Y_old(ii);
            for (int j = 1; j <= 6; j++) {
                if (ii == j) {
                    yPhi(6*j + ii) = 1.0;
                } else {
                    yPhi(6*j + ii) = 0.0;
                }
            }
        }
        
        yPhi = DEInteg(VarEqn, 0, t - t_old, 1e-13, 1e-6, 42, yPhi);
        
        // Extract state transition matrix
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                Phi(k, j) = yPhi(6*j + k);
            }
        }
        
        Y = DEInteg(Accel, 0, t - t_old, 1e-13, 1e-6, 6, Y_old);
        
        // Topocentric coordinates
        double theta = gmst(Mjd_UT1);
        Matrix U = R_z(theta);
        Matrix r(3, 1);
        r(1) = Y(1); r(2) = Y(2); r(3) = Y(3);
        Matrix s = LT * (U * r - Rs);
        
        // Time update
        P = TimeUpdate(P, Phi);
        
        // Azimuth and partials
        double Azim, Elev;
        Matrix* dAds = nullptr;
        Matrix* dEds = nullptr;
        AzElPa(s, Azim, Elev, dAds, dEds);
        
        Matrix dAdY(1, 6);
        Matrix LT_col1 = Matrix::extract_column(LT, 1);
        // Matrix LT_col2 = Matrix::extract_column(LT, 2);
        // Matrix LT_col3 = Matrix::extract_column(LT, 3);
        Matrix U_col1 = Matrix::extract_column(U, 1);
        // Matrix U_col2 = Matrix::extract_column(U, 2);
        // Matrix U_col3 = Matrix::extract_column(U, 3);

        // printf("dimensiones de LT, U, y dAds (usando matrix.size() y extract_column) \n");
        // // usa matrix.size() y extract_column para ver dimensiones NO COL NI ROWS. PARA ELLO USA EXTRACT COLUMN
        // std::cout << "LT: " << LT.size() << ", U: " << U.size() << ", dAds: " << dAds->size() << std::endl;
        // std::cout << "LT_col1: " << LT_col1.size() << ", U_col1: " << U_col1.size() << std::endl;
        // std::cout << "dAds: " << dAds->size() << std::endl;
        // // print dAds:
        // dAds->print();
        
        Matrix LTU = LT * U;           // LT*U (3x3)
        // printf("LTU: ");
        // LTU.print();

        Matrix dAdY_pos = (*dAds) * LTU;  // dAds*LT*U (1x3)

        dAdY(1, 1) = dAdY_pos(1, 1);
        dAdY(1, 2) = dAdY_pos(1, 2); 
        dAdY(1, 3) = dAdY_pos(1, 3);
        
        // dAdY(1, 1) = (*dAds)(1) * Matrix::dot(LT_col1, U_col1) + (*dAds)(2) * Matrix::dot(LT_col2, U_col1) + (*dAds)(3) * Matrix::dot(LT_col3, U_col1);
        // dAdY(1, 2) = (*dAds)(1) * Matrix::dot(LT_col1, U_col2) + (*dAds)(2) * Matrix::dot(LT_col2, U_col2) + (*dAds)(3) * Matrix::dot(LT_col3, U_col2);
        // dAdY(1, 3) = (*dAds)(1) * Matrix::dot(LT_col1, U_col3) + (*dAds)(2) * Matrix::dot(LT_col2, U_col3) + (*dAds)(3) * Matrix::dot(LT_col3, U_col3);
        dAdY(1, 4) = 0.0;
        dAdY(1, 5) = 0.0;
        dAdY(1, 6) = 0.0;
        
        Matrix* K = nullptr;
        MeasUpdate(Y, obs(i,2), Azim, sigma_az, dAdY, P, 6, K);
        delete K;
        delete dAds;
        delete dEds;
        
        // Elevation and partials
        r(1) = Y(1); r(2) = Y(2); r(3) = Y(3);
        s = LT * (U * r - Rs);
        AzElPa(s, Azim, Elev, dAds, dEds);
        
        Matrix dEdY(1, 6);

        // printf("dimensiones de LT, U, y dEds (usando matrix.size() y extract_column) \n");
        // // usa matrix.size() y extract_column para ver dimensiones NO COL NI ROWS. PARA ELLO USA EXTRACT COLUMN
        // std::cout << "LT: " << LT.size() << ", U: " << U.size() << ", dEds: " << dEds->size() << std::endl;
        // std::cout << "LT_col1: " << LT_col1.size() << ", U_col1: " << U_col1.size() << std::endl;
        // printf("dEds: ");
        // dEds->print();
        // Matrix LTU = LT * U;           // LT*U (3x3)
        Matrix dEdY_pos = (*dEds) * LTU;  // dAds*LT*U (1x3)
        
        dEdY(1, 1) = dEdY_pos(1, 1);
        dEdY(1, 2) = dEdY_pos(1, 2); 
        dEdY(1, 3) = dEdY_pos(1, 3);
        // dEdY(1, 1) = (*dEds)(1) * Matrix::dot(LT_col1, U_col1) + (*dEds)(2) * Matrix::dot(LT_col2, U_col1) + (*dEds)(3) * Matrix::dot(LT_col3, U_col1);
        // dEdY(1, 2) = (*dEds)(1) * Matrix::dot(LT_col1, U_col2) + (*dEds)(2) * Matrix::dot(LT_col2, U_col2) + (*dEds)(3) * Matrix::dot(LT_col3, U_col2);
        // dEdY(1, 3) = (*dEds)(1) * Matrix::dot(LT_col1, U_col3) + (*dEds)(2) * Matrix::dot(LT_col2, U_col3) + (*dEds)(3) * Matrix::dot(LT_col3, U_col3);
        dEdY(1, 4) = 0.0;
        dEdY(1, 5) = 0.0;
        dEdY(1, 6) = 0.0;
        
        K = nullptr;
        MeasUpdate(Y, obs(i,3), Elev, sigma_el, dEdY, P, 6, K);
        delete K;
        delete dAds;
        delete dEds;
        
        // Range and partiasl
        r(1) = Y(1); r(2) = Y(2); r(3) = Y(3);
        s = LT * (U * r - Rs);
        double Dist = s.norm();
        Matrix dDds = s * (1.0/Dist);  // s/Dist as row vector
        
        Matrix dDdY(1, 6);

        // Matrix LTU = LT * U;           // LT*U (3x3)
        Matrix dDdY_pos = dDds.transpose() * LTU;  // dAds*LT*U (1x3)

        dDdY(1, 1) = dDdY_pos(1, 1);
        dDdY(1, 2) = dDdY_pos(1, 2); 
        dDdY(1, 3) = dDdY_pos(1, 3);
        // dDdY(1, 1) = dDds(1) * Matrix::dot(LT_col1, U_col1) + dDds(2) * Matrix::dot(LT_col2, U_col1) + dDds(3) * Matrix::dot(LT_col3, U_col1);
        // dDdY(1, 2) = dDds(1) * Matrix::dot(LT_col1, U_col2) + dDds(2) * Matrix::dot(LT_col2, U_col2) + dDds(3) * Matrix::dot(LT_col3, U_col2);
        // dDdY(1, 3) = dDds(1) * Matrix::dot(LT_col1, U_col3) + dDds(2) * Matrix::dot(LT_col2, U_col3) + dDds(3) * Matrix::dot(LT_col3, U_col3);
        dDdY(1, 4) = 0.0;
        dDdY(1, 5) = 0.0;
        dDdY(1, 6) = 0.0;
        
        // Measurement update
        K = nullptr;
        MeasUpdate(Y, obs(i,4), Dist, sigma_range, dDdY, P, 6, K);
        delete K;
    }
    
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS(*eopdata, obs(46,1), 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    double Mjd_TT = obs(46,1) + TT_UTC/86400.0;
    auxParam.Mjd_UTC = obs(46,1);
    auxParam.Mjd_TT = Mjd_TT;
    
    Matrix Y0 = DEInteg(Accel, 0, -(obs(46,1) - obs(1,1)) * 86400.0, 1e-13, 1e-6, 6, Y);
    
    const double Y_true[6] = {5753.173e3, 2673.361e3, 3440.304e3, 4.324207e3, -1.924299e3, -5.728216e3};
    
    results->Y0 = new Matrix(Y0);
    results->P = new Matrix(P);
    for (int i = 0; i < 3; i++) {
        results->position_error[i] = Y0(i+1) - Y_true[i];
    }
    for (int i = 0; i < 3; i++) {
        results->velocity_error[i] = Y0(i+4) - Y_true[i+3];
    }
    
    // Print results
    std::cout << "\nError of Position Estimation" << std::endl;
    std::cout << "dX " << std::setw(10) << std::fixed << std::setprecision(1) << results->position_error[0] << " [m]" << std::endl;
    std::cout << "dY " << std::setw(10) << std::fixed << std::setprecision(1) << results->position_error[1] << " [m]" << std::endl;
    std::cout << "dZ " << std::setw(10) << std::fixed << std::setprecision(1) << results->position_error[2] << " [m]" << std::endl;
    std::cout << "\nError of Velocity Estimation" << std::endl;
    std::cout << "dVx " << std::setw(8) << std::fixed << std::setprecision(1) << results->velocity_error[0] << " [m/s]" << std::endl;
    std::cout << "dVy " << std::setw(8) << std::fixed << std::setprecision(1) << results->velocity_error[1] << " [m/s]" << std::endl;
    std::cout << "dVz " << std::setw(8) << std::fixed << std::setprecision(1) << results->velocity_error[2] << " [m/s]" << std::endl;
    
    // Cleanup allocated memory
    delete r2;
    delete v2;
    delete Cnm;
    delete Snm;
    delete eopdata;
    
    return results;
}
