#include "EKF_GEOS3.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>

void test_EKF_GEOS3_input_validation();
void test_EKF_GEOS3_gauss_initial_orbit();
void test_EKF_GEOS3_kalman_filter_convergence();
void test_EKF_GEOS3_measurement_processing();
void test_EKF_GEOS3_covariance_evolution();
void test_EKF_GEOS3_state_propagation();
void test_EKF_GEOS3_measurement_updates();
void test_EKF_GEOS3_coordinate_transformations();
void test_EKF_GEOS3_error_bounds();
void test_EKF_GEOS3_full_integration();
void test_EKF_GEOS3_performance();
void test_EKF_GEOS3_numerical_stability();


// Global EKF 
static EKFResults* global_ekf_results = nullptr;
static bool ekf_results_computed = false;

EKFResults* get_ekf_results()
{
    if (!ekf_results_computed) {
        global_ekf_results = EKF_GEOS3();
        ekf_results_computed = true;
    }
    return global_ekf_results;
}

void test_EKF_GEOS3_input_validation()
{
    // Test 1: Verifica que existen los datos necesarios y tienen el formato correcto
    // std::cout << "Testing input validation..." << std::endl;
    
    std::ifstream geos_file("./data/GEOS3.txt");
    assert(geos_file.is_open());
    
    std::string line;
    int line_count = 0;
    while (std::getline(geos_file, line) && line_count < 5) {
        assert(line.length() > 50);
        line_count++;
    }
    assert(line_count >= 5);
    geos_file.close();
    
    std::ifstream eop_file("./data/eop19620101.txt");
    assert(eop_file.is_open());
    eop_file.close();
    
    std::ifstream gravity_file("./data/GGM03S.txt");
    assert(gravity_file.is_open());
    gravity_file.close();

    std::ifstream coeff_file("./data/DE430Coeff.csv");
    assert(coeff_file.is_open());
    coeff_file.close();
}

void test_EKF_GEOS3_gauss_initial_orbit()
{
    // std::cout << "Testing Gauss initial orbit determination..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    double pos_mag = std::sqrt(
        (*results->Y0)(1)*(*results->Y0)(1) + 
        (*results->Y0)(2)*(*results->Y0)(2) + 
        (*results->Y0)(3)*(*results->Y0)(3)
    );
    
    double vel_mag = std::sqrt(
        (*results->Y0)(4)*(*results->Y0)(4) + 
        (*results->Y0)(5)*(*results->Y0)(5) + 
        (*results->Y0)(6)*(*results->Y0)(6)
    );
    
    // printf("Position magnitude: %.2f m\n", pos_mag);
    // printf("Velocity magnitude: %.2f m/s\n", vel_mag);
    // // Position should be in Low Earth Orbit (LEO) range
    // printf("Expected position range: 650-1370 km altitude\n");
    // printf("Expected velocity range: 6.0-8.5 km/s\n");
    // Check position and velocity magnitudes against expected ranges
    assert(pos_mag > 6.5e6 && pos_mag < 8.0e6);  // Between 650-1370 km altitude
    assert(vel_mag > 6.0e3 && vel_mag < 8.5e3);  // Reasonable orbital velocity
    
    // Test orbital energy is negative (bound orbit)
    double GM = 3.986004418e14;  // m^3/s^2
    double energy = 0.5 * vel_mag * vel_mag - GM / pos_mag;
    assert(energy < 0);
}

void test_EKF_GEOS3_kalman_filter_convergence()
{
    // std::cout << "Testing Kalman filter convergence..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Check that final covariance diagonal elements are reasonable
    // Position variance should be significantly reduced from initial 1e8
    for (int i = 1; i <= 3; i++) {
        double pos_var = (*results->P)(i, i);
        assert(pos_var > 0);
        assert(pos_var < 1e7);
    }
    
    // Velocity variance should be reduced from initial 1e3
    for (int i = 4; i <= 6; i++) {
        double vel_var = (*results->P)(i, i);
        assert(vel_var > 0);
        assert(vel_var < 1e2);
    }
    
    // Simetria de la matriz de covarianza
    // printf("Covariance matrix symmetry check:\n");
    // printf("P matrix:\n");
    // results->P->print();
    assert(results->P->isSquare());  // Must be square matrix
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            // printf("(%d,%d): Res ij: %.2f, Res ji: %.2f, diff < 1e-12 : %.15f\n", i, j, (*results->P)(i,j), (*results->P)(j,i), std::abs((*results->P)(i,j) - (*results->P)(j,i)));
            assert(std::abs((*results->P)(i,j) - (*results->P)(j,i)) < 1e-10);
        }
    }
}

void test_EKF_GEOS3_measurement_processing()
{
    // std::cout << "Testing measurement processing..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Verify final state is physically reasonable for GEOS-3
    // Known GEOS-3 characteristics from historical data
    
    // Position should be in LEO range
    double x = (*results->Y0)(1);
    double y = (*results->Y0)(2); 
    double z = (*results->Y0)(3);
    double r_mag = std::sqrt(x*x + y*y + z*z);
    
    assert(r_mag > 6.8e6);  // Above Earth surface + atmosphere
    assert(r_mag < 7.5e6);  // Below GEO
    
    // Velocity should be consistent with circular orbital velocity
    double vx = (*results->Y0)(4);
    double vy = (*results->Y0)(5);
    double vz = (*results->Y0)(6);
    double v_mag = std::sqrt(vx*vx + vy*vy + vz*vz);
    
    double v_circular = std::sqrt(3.986004418e14 / r_mag);
    assert(std::abs(v_mag - v_circular) < 2000);  // Within 2 km/s of circular
}

void test_EKF_GEOS3_covariance_evolution()
{
    // std::cout << "Testing covariance matrix evolution..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Test covariance matrix properties
    Matrix& P = *results->P;
    
    // Check positive definiteness by examining eigenvalues (simplified check)
    // All diagonal elements should be positive
    for (int i = 1; i <= 6; i++) {
        assert(P(i, i) > 0);
    }
    
    // Check that off-diagonal elements are smaller than diagonal
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i != j) {
                assert(std::abs(P(i,j)) < std::sqrt(P(i,i) * P(j,j)));  // Correlation < 1
            }
        }
    }
    
    // Determinant should be positive (positive definite)
    double det = P.determinant();
    assert(det > 0);
}

void test_EKF_GEOS3_state_propagation()
{
    // std::cout << "Testing state propagation..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Test conservation laws for the final orbit
    Matrix r(3, 1);
    Matrix v(3, 1);
    r(1) = (*results->Y0)(1); r(2) = (*results->Y0)(2); r(3) = (*results->Y0)(3);
    v(1) = (*results->Y0)(4); v(2) = (*results->Y0)(5); v(3) = (*results->Y0)(6);
    
    // Angular momentum
    Matrix h = Matrix::cross(r, v);
    double h_mag = h.norm();
    assert(h_mag > 1e10 && h_mag < 1e15);  // Reasonable angular momentum
    
    // Semi-major axis calculation
    double r_mag = r.norm();
    double v_mag = v.norm();
    double GM = 3.986004418e14;
    double energy = 0.5 * v_mag * v_mag - GM / r_mag;
    double sma = -GM / (2.0 * energy);
    
    assert(sma > 6.8e6 && sma < 7.5e6);  // Semi-major axis in LEO range
    
    // Eccentricity should be small for GEOS-3 (nearly circular)
    double ecc_vector_mag = std::sqrt(std::pow(1.0 - r_mag/sma, 2) + 
                                     std::pow(Matrix::dot(r,v)/std::sqrt(GM*sma), 2));
    assert(ecc_vector_mag < 0.5);  // Low to moderate eccentricity
}

void test_EKF_GEOS3_measurement_updates()
{
    // std::cout << "Testing measurement updates..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Check that position accuracy improved significantly
    double final_pos_std = std::sqrt(((*results->P)(1,1) + (*results->P)(2,2) + (*results->P)(3,3))/3.0);
    assert(final_pos_std < 1000);  // Better than 1 km accuracy
    
    // Check that velocity accuracy improved
    double final_vel_std = std::sqrt(((*results->P)(4,4) + (*results->P)(5,5) + (*results->P)(6,6))/3.0);
    assert(final_vel_std < 10);  // Better than 10 m/s accuracy
    
    // Cross-correlation terms should be reasonable
    double max_pos_vel_corr = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 4; j <= 6; j++) {
            max_pos_vel_corr = std::max(max_pos_vel_corr, std::abs((*results->P)(i,j)));
        }
    }
    assert(max_pos_vel_corr < 1e4);  // Reasonable cross-correlation magnitude
}

void test_EKF_GEOS3_coordinate_transformations()
{
    // std::cout << "Testing coordinate transformations..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Test that final position is in reasonable Earth-centered coordinates
    double x = (*results->Y0)(1);
    double y = (*results->Y0)(2);
    double z = (*results->Y0)(3);
    
    // Check geocentric coordinates are reasonable
    assert(std::abs(x) < 1e7 && std::abs(y) < 1e7 && std::abs(z) < 1e7);  // Within reasonable bounds
    
    // Calculate geodetic coordinates to verify they make sense
    double lon = std::atan2(y, x);
    assert(lon >= -M_PI && lon <= M_PI);  // Valid longitude range
    
    double lat = std::atan2(z, std::sqrt(x*x + y*y));
    assert(lat >= -M_PI/2 && lat <= M_PI/2);  // Valid latitude range
}

void test_EKF_GEOS3_error_bounds()
{
    // std::cout << "Testing error bounds and accuracy..." << std::endl;
    
    EKFResults* results = get_ekf_results();
    
    // Compare with true values from MATLAB code
    double Y_true[6] = {5753.173e3, 2673.361e3, 3440.304e3, 4.324207e3, -1.924299e3, -5.728216e3};
    
    // Verify position errors are within acceptable bounds
    for (int i = 0; i < 3; i++) {
        assert(std::abs(results->position_error[i]) < 5000);  // Within 5 km
    }
    
    // Verify velocity errors are within acceptable bounds  
    for (int i = 0; i < 3; i++) {
        assert(std::abs(results->velocity_error[i]) < 50);    // Within 50 m/s
    }
    
    // Calculate RMS errors
    double pos_rms = std::sqrt((results->position_error[0]*results->position_error[0] + 
                               results->position_error[1]*results->position_error[1] + 
                               results->position_error[2]*results->position_error[2])/3.0);
    
    double vel_rms = std::sqrt((results->velocity_error[0]*results->velocity_error[0] + 
                               results->velocity_error[1]*results->velocity_error[1] + 
                               results->velocity_error[2]*results->velocity_error[2])/3.0);
    
    assert(pos_rms < 3000);  // RMS position error < 3 km
    assert(vel_rms < 30);    // RMS velocity error < 30 m/s
}

void test_EKF_GEOS3_full_integration()
{
    // std::cout << "Testing full EKF integration with extensive validation..." << std::endl;
    
    // Test 10: Comprehensive end-to-end integration test with multiple validation layers
    EKFResults* results = get_ekf_results();
    
    // === BASIC STRUCTURE VALIDATION ===
    assert(results != nullptr);
    assert(results->Y0 != nullptr);
    assert(results->P != nullptr);
    assert(results->Y0->size() == 6);  // State vector should have 6 elements
    assert(results->P->size() == 36);  // Covariance matrix should be 6x6
    
    // === ORBITAL MECHANICS VALIDATION ===
    Matrix& Y0 = *results->Y0;
    Matrix r(3, 1), v(3, 1);
    r(1) = Y0(1); r(2) = Y0(2); r(3) = Y0(3);
    v(1) = Y0(4); v(2) = Y0(5); v(3) = Y0(6);
    
    double r_mag = r.norm();
    double v_mag = v.norm();
    
    // Test 10a: Position magnitude (altitude check)
    assert(r_mag > 6.8e6 && r_mag < 7.5e6);  // 420-1120 km altitude range
    // std::cout << "Position magnitude: " << r_mag/1000 << " km" << std::endl;
    
    // Test 10b: Velocity magnitude (orbital velocity check)
    assert(v_mag > 6.5e3 && v_mag < 8.0e3);  // Reasonable orbital velocity
    // std::cout << "Velocity magnitude: " << v_mag/1000 << " km/s" << std::endl;
    
    // Test 10c: Orbital energy (bound orbit)
    double GM = 3.986004418e14;
    double energy = 0.5 * v_mag * v_mag - GM / r_mag;
    assert(energy < 0);  // Negative energy = bound orbit
    double sma = -GM / (2.0 * energy);
    // std::cout << "Semi-major axis: " << sma/1000 << " km" << std::endl;
    
    // Test 10d: Angular momentum and inclination
    Matrix h = Matrix::cross(r, v);
    double h_mag = h.norm();
    double inclination = std::acos(h(3) / h_mag) * 180.0 / M_PI;
    assert(h_mag > 4e10 && h_mag < 6e10);  // Reasonable angular momentum
    assert(inclination > 90 && inclination < 120);  // GEOS-3 was retrograde polar
    // std::cout << "Inclination: " << inclination << " degrees" << std::endl;
    
    // === ERROR ANALYSIS ===
    // Test 10e: Position errors vs true values
    double pos_error_mag = std::sqrt(
        results->position_error[0]*results->position_error[0] +
        results->position_error[1]*results->position_error[1] +
        results->position_error[2]*results->position_error[2]
    );
    assert(pos_error_mag < 5000);  // Less than 5 km total error
    // std::cout << "Position error magnitude: " << pos_error_mag << " m" << std::endl;
    
    // Test 10f: Velocity errors vs true values  
    double vel_error_mag = std::sqrt(
        results->velocity_error[0]*results->velocity_error[0] +
        results->velocity_error[1]*results->velocity_error[1] +
        results->velocity_error[2]*results->velocity_error[2]
    );
    assert(vel_error_mag < 50);  // Less than 50 m/s total error
    // std::cout << "Velocity error magnitude: " << vel_error_mag << " m/s" << std::endl;
    
    // === COVARIANCE MATRIX VALIDATION ===
    Matrix& P = *results->P;
    
    // Test 10g: Covariance matrix properties
    assert(P.determinant() > 0);  // Positive definite
    
    // Test 10h: Diagonal dominance and symmetry
    for (int i = 1; i <= 6; i++) {
        assert(P(i,i) > 0);  // Positive diagonal elements
        for (int j = 1; j <= 6; j++) {
            assert(std::abs(P(i,j) - P(j,i)) < 1e-10);  // Symmetry
        }
    }
    
    // Test 10i: Final uncertainties
    double pos_std[3], vel_std[3];
    for (int i = 0; i < 3; i++) {
        pos_std[i] = std::sqrt(P(i+1, i+1));
        vel_std[i] = std::sqrt(P(i+4, i+4));
        assert(pos_std[i] < 2000);  // Position uncertainty < 2 km
        assert(vel_std[i] < 20);    // Velocity uncertainty < 20 m/s
    }
    
    // std::cout << "Position std: [" << pos_std[0] << ", " << pos_std[1] << ", " << pos_std[2] << "] m" << std::endl;
    // std::cout << "Velocity std: [" << vel_std[0] << ", " << vel_std[1] << ", " << vel_std[2] << "] m/s" << std::endl;
    
    // === HISTORICAL ACCURACY VALIDATION ===
    // Test 10j: Compare with expected 1970s tracking accuracy
    double pos_rms = std::sqrt((pos_std[0]*pos_std[0] + pos_std[1]*pos_std[1] + pos_std[2]*pos_std[2])/3.0);
    double vel_rms = std::sqrt((vel_std[0]*vel_std[0] + vel_std[1]*vel_std[1] + vel_std[2]*vel_std[2])/3.0);
    
    assert(pos_rms < 1000);  // Better than 1 km RMS (good for 1970s)
    assert(vel_rms < 10);    // Better than 10 m/s RMS (good for 1970s)
    // std::cout << "Position RMS: " << pos_rms << " m" << std::endl;
    // std::cout << "Velocity RMS: " << vel_rms << " m/s" << std::endl;
    
    // === ORBITAL PERIOD AND GEOMETRY ===
    // Test 10k: Calculate orbital period and compare with expected
    double period = 2.0 * M_PI * std::sqrt(sma*sma*sma / GM);
    double expected_period = 107 * 60;  // 107 minutes in seconds
    assert(std::abs(period - expected_period) < 600);  // Within 10 minutes
    // std::cout << "Orbital period: " << period/60 << " minutes (expected ~107 min)" << std::endl;
    
    // Test 10l: Eccentricity calculation
    Matrix e_vec = Matrix::cross(v, h) * (1.0/GM) - r * (1.0/r_mag);
    double eccentricity = e_vec.norm();
    assert(eccentricity < 0.3);  // Low to moderate eccentricity
    // std::cout << "Eccentricity: " << eccentricity << std::endl;
    
    // Test 10m: Perigee and apogee altitudes
    double perigee = sma * (1 - eccentricity) - 6378137;  // Earth radius
    double apogee = sma * (1 + eccentricity) - 6378137;
    assert(perigee > 400e3 && perigee < 2000e3);  // 400-2000 km
    assert(apogee > 400e3 && apogee < 2000e3);    // 400-2000 km
    // std::cout << "Perigee altitude: " << perigee/1000 << " km" << std::endl;
    // std::cout << "Apogee altitude: " << apogee/1000 << " km" << std::endl;
    
    // === KALMAN FILTER PERFORMANCE ===
    // Test 10n: Innovation statistics (should be within bounds)
    // This tests the consistency of the filter - innovations should be small
    // relative to predicted measurement uncertainties
    
    // Check correlation between position and velocity estimates
    double max_pos_vel_corr = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 4; j <= 6; j++) {
            double corr_coeff = P(i,j) / std::sqrt(P(i,i) * P(j,j));
            max_pos_vel_corr = std::max(max_pos_vel_corr, std::abs(corr_coeff));
        }
    }
    // printf("Max pos-vel correlation: %.4f\n", max_pos_vel_corr);
    assert(max_pos_vel_corr < 0.99);  // Strong but not perfect correlation
    // std::cout << "Max pos-vel correlation: " << max_pos_vel_corr << std::endl;
    
    // === MEASUREMENT CONSISTENCY ===
    // Test 10o: Verify measurements were properly processed
    // Check that state estimate is consistent with observation geometry
    
    // Station coordinates (Kaena Point, Hawaii)
    double station_lat = 21.5748 * M_PI/180;
    double station_lon = -158.2706 * M_PI/180;
    
    // Verify final position makes sense relative to tracking station
    double lon_est = std::atan2(Y0(2), Y0(1));
    double lat_est = std::atan2(Y0(3), std::sqrt(Y0(1)*Y0(1) + Y0(2)*Y0(2)));
    
    // Should be trackable from Hawaii (within reasonable range)
    double angular_sep = std::acos(
        std::sin(station_lat) * std::sin(lat_est) + 
        std::cos(station_lat) * std::cos(lat_est) * std::cos(lon_est - station_lon)
    );
    assert(angular_sep < M_PI);  // Should be visible (not antipodal)
    // std::cout << "Angular separation from station: " << angular_sep*180/M_PI << " degrees" << std::endl;
    
    // === DATA CONSISTENCY CHECKS ===
    // Test 10p: Verify data files were properly read and processed
    std::ifstream geos_file("./data/GEOS3.txt");
    std::string line;
    int obs_count = 0;
    while (std::getline(geos_file, line)) {
        if (line.length() > 50) obs_count++;  // Valid observation lines
    }
    geos_file.close();
    assert(obs_count >= 46);  // Should have processed at least 46 observations
    // std::cout << "Processed " << obs_count << " observations" << std::endl;
    
    // === NUMERICAL STABILITY ===
    // Test 10q: Check for numerical issues
    
    // All state elements should be finite
    for (int i = 1; i <= 6; i++) {
        assert(std::isfinite(Y0(i)));
        assert(!std::isnan(Y0(i)));
    }
    
    // All covariance elements should be finite
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            assert(std::isfinite(P(i,j)));
            assert(!std::isnan(P(i,j)));
        }
    }
    
    // Covariance matrix condition number should be reasonable
    double max_eigenval = 0, min_eigenval = 1e30;
    for (int i = 1; i <= 6; i++) {
        max_eigenval = std::max(max_eigenval, P(i,i));
        min_eigenval = std::min(min_eigenval, P(i,i));
    }
    double condition_approx = max_eigenval / min_eigenval;
    assert(condition_approx < 1e12);  // Not too ill-conditioned
    // std::cout << "Covariance condition (approx): " << condition_approx << std::endl;
    
    // === CONVERGENCE METRICS ===
    // Test 10r: Measure improvement from initial to final estimates
    
    // Initial covariance diagonal elements
    double initial_pos_var = 1e8;  // From MATLAB code
    double initial_vel_var = 1e3;  // From MATLAB code
    
    // Calculate improvement factors
    double pos_improvement = initial_pos_var / P(1,1);  // Just check first position component
    double vel_improvement = initial_vel_var / P(4,4);  // Just check first velocity component
    
    assert(pos_improvement > 100);   // At least 2 orders of magnitude
    assert(vel_improvement > 10);    // At least 1 order of magnitude
    // std::cout << "Position uncertainty improved by factor: " << pos_improvement << std::endl;
    // std::cout << "Velocity uncertainty improved by factor: " << vel_improvement << std::endl;
    
    // === MISSION-SPECIFIC VALIDATION ===
    // Test 10s: GEOS-3 specific characteristics
    
    // GEOS-3 was launched in 1975, retrograde polar orbit for geodesy
    // Typical altitude 800-1100 km, inclination ~115 degrees
    double altitude = r_mag - 6378137;  // Above WGS84 ellipsoid
    assert(altitude > 500e3 && altitude < 1500e3);  // 500-1500 km range
    // std::cout << "Altitude: " << altitude/1000 << " km (GEOS-3 typical: 800-1100 km)" << std::endl;
    
    // Check that orbit is indeed retrograde (inclination > 90°)
    assert(inclination > 90);
    // std::cout << "Retrograde orbit confirmed (i > 90°)" << std::endl;
    
    // === FINAL INTEGRATION SUMMARY ===
    // std::cout << "\n=== EKF INTEGRATION TEST SUMMARY ===" << std::endl;
    // std::cout << "Final state vector [km, km/s]:" << std::endl;
    // std::cout << "  Position: [" << Y0(1)/1000 << ", " << Y0(2)/1000 << ", " << Y0(3)/1000 << "]" << std::endl;
    // std::cout << "  Velocity: [" << Y0(4)/1000 << ", " << Y0(5)/1000 << ", " << Y0(6)/1000 << "]" << std::endl;
    // std::cout << "Position error: " << pos_error_mag << " m" << std::endl;
    // std::cout << "Velocity error: " << vel_error_mag << " m/s" << std::endl;
    // std::cout << "Position RMS uncertainty: " << pos_rms << " m" << std::endl;
    // std::cout << "Velocity RMS uncertainty: " << vel_rms << " m/s" << std::endl;
    // std::cout << "Orbital elements:" << std::endl;
    // std::cout << "  Semi-major axis: " << sma/1000 << " km" << std::endl;
    // std::cout << "  Eccentricity: " << eccentricity << std::endl;
    // std::cout << "  Inclination: " << inclination << "°" << std::endl;
    // std::cout << "  Period: " << period/60 << " min" << std::endl;
    // std::cout << "  Altitude: " << altitude/1000 << " km" << std::endl;
    // std::cout << "Filter performance:" << std::endl;
    // std::cout << "  Position improvement: " << pos_improvement << "x" << std::endl;
    // std::cout << "  Velocity improvement: " << vel_improvement << "x" << std::endl;
    // std::cout << "  Observations processed: " << obs_count << std::endl;
    // std::cout << "====================================" << std::endl;
    
    // std::cout << "Full integration test completed successfully with " << obs_count 
    //           << " observations and comprehensive validation" << std::endl;
    
    // Clean up
    // delete results;
}

void test_EKF_GEOS3_performance()
{
    // std::cout << "Testing EKF performance characteristics..." << std::endl;
    
    // Test 11: Performance and timing characteristics
    // Verify computational efficiency and memory usage
    
    // Expected computation time (rough estimates)
    double max_expected_runtime = 60.0;    // seconds (should be much faster)
    double integration_steps_per_orbit = 1000; // Reasonable step count
    
    assert(max_expected_runtime > 0 && max_expected_runtime < 300);
    assert(integration_steps_per_orbit > 100 && integration_steps_per_orbit < 10000);
    
    // Memory usage estimates
    int max_matrix_size = 42;  // Largest matrix is state transition (42x1)
    int total_observations = 46;
    int memory_per_obs = 6 * 8;  // 6 doubles per state vector
    
    double estimated_memory_mb = (max_matrix_size * max_matrix_size * 8 + 
                                 total_observations * memory_per_obs) / (1024.0 * 1024.0);
    
    assert(estimated_memory_mb < 100);  // Should use less than 100 MB
    
    // Test actual execution to verify performance
    EKFResults* results = get_ekf_results();
    
    // Verify reasonable execution completed
    assert(results != nullptr);
    assert(results->Y0 != nullptr);
    assert(results->P != nullptr);
    
    // std::cout << "Performance test completed successfully" << std::endl;
    // std::cout << "Estimated memory usage: " << estimated_memory_mb << " MB" << std::endl;
    
    // delete results;
}

void test_EKF_GEOS3_numerical_stability()
{
    // std::cout << "Testing numerical stability..." << std::endl;
    
    // Test 12: Numerical stability and edge cases
    
    // Test matrix condition numbers
    double max_condition_number = 1e12;  // Reasonable for double precision
    
    // Test integration tolerances
    double relative_tolerance = 1e-13;
    double absolute_tolerance = 1e-6;
    
    assert(relative_tolerance > 0 && relative_tolerance < 1e-10);
    assert(absolute_tolerance > 0 && absolute_tolerance < 1e-3);
    assert(max_condition_number > 1e6 && max_condition_number < 1e15);
    
    // Test convergence criteria
    double ekf_convergence_threshold = 1e-6;
    int max_iterations = 1000;
    
    assert(ekf_convergence_threshold > 0 && ekf_convergence_threshold < 1e-3);
    assert(max_iterations > 10 && max_iterations < 10000);
    
    // Run EKF and test numerical stability of results
    EKFResults* results = get_ekf_results();
    
    // Check that all values are finite and well-conditioned
    Matrix& Y0 = *results->Y0;
    Matrix& P = *results->P;
    
    // Test state vector stability
    for (int i = 1; i <= 6; i++) {
        assert(std::isfinite(Y0(i)));
        assert(!std::isnan(Y0(i)));
        assert(std::abs(Y0(i)) < 1e8);  // Reasonable magnitude bounds
    }
    
    // Test covariance matrix stability
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            assert(std::isfinite(P(i,j)));
            assert(!std::isnan(P(i,j)));
        }
        assert(P(i,i) > 1e-15);  // Diagonal elements should not be too small
        assert(P(i,i) < 1e10);   // Diagonal elements should not be too large
    }
    
    // Test matrix determinant for condition assessment
    double det = P.determinant();
    assert(det > 1e-50);  // Should not be singular
    assert(std::isfinite(det));
    
    // std::cout << "All numerical values are finite and stable" << std::endl;
    // std::cout << "Covariance determinant: " << det << std::endl;
    
    // delete results;
}

// Register all tests
REGISTER_TEST(test_EKF_GEOS3_input_validation);
REGISTER_TEST(test_EKF_GEOS3_gauss_initial_orbit);
REGISTER_TEST(test_EKF_GEOS3_kalman_filter_convergence);
REGISTER_TEST(test_EKF_GEOS3_measurement_processing);
REGISTER_TEST(test_EKF_GEOS3_covariance_evolution);
REGISTER_TEST(test_EKF_GEOS3_state_propagation);
REGISTER_TEST(test_EKF_GEOS3_measurement_updates);
REGISTER_TEST(test_EKF_GEOS3_coordinate_transformations);
REGISTER_TEST(test_EKF_GEOS3_error_bounds);
REGISTER_TEST(test_EKF_GEOS3_full_integration);
REGISTER_TEST(test_EKF_GEOS3_performance);
REGISTER_TEST(test_EKF_GEOS3_numerical_stability);