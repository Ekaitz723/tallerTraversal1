#include "Mjday_TDB.h"
#include "TestFramework.h"
#include <cassert>
#include <cmath>

double Mjday_TDB(double Mjd_TT)
{
    // Julian Centuries . TT
    double T_TT = (Mjd_TT - 51544.5) / 36525.0;
    
    // Modified Julian Date . TDB
    double Mjd_TDB = Mjd_TT + (0.001658 * sin(628.3076 * T_TT + 6.2401) +
                               0.000022 * sin(575.3385 * T_TT + 4.2970) +
                               0.000014 * sin(1256.6152 * T_TT + 6.1969) +
                               0.000005 * sin(606.9777 * T_TT + 4.0212) +
                               0.000005 * sin(52.9691 * T_TT + 0.4444) +
                               0.000002 * sin(21.3299 * T_TT + 5.5431) +
                               0.000010 * sin(628.3076 * T_TT + 4.2490)) / 86400.0;
    
    return Mjd_TDB;
}

void test_Mjday_TDB()
{
    const double eps = 1e-9; // precision
    
    // Test 1: J2000.0 epoch (MJD 51544.5 TT)
    double mjd_tt_j2000 = 51544.5;
    double mjd_tdb_j2000 = Mjday_TDB(mjd_tt_j2000);
    
    // TDB should be very close to TT (difference < 0.002 seconds = ~2.3e-8 days)
    double diff_j2000 = fabs(mjd_tdb_j2000 - mjd_tt_j2000);
    assert(diff_j2000 < 2.5e-8); // Less than 0.002 seconds in days
    
    // Test 2: Different epoch to verify periodic variations
    double mjd_tt_test = 52000.0; // About 1.25 years after J2000
    double mjd_tdb_test = Mjday_TDB(mjd_tt_test);
    
    // Verify the difference is still small
    double diff_test = fabs(mjd_tdb_test - mjd_tt_test);
    assert(diff_test < 2.5e-8);
    
    // Test 3: TDB should be different at different times (periodic nature)
    double mjd_tt_1 = 51544.5;  // J2000.0 (January 1, 2000)
    double mjd_tt_2 = 51726.5;  // ~6 months later (around July 2000)
    
    double mjd_tdb_1 = Mjday_TDB(mjd_tt_1);
    double mjd_tdb_2 = Mjday_TDB(mjd_tt_2);
    
    double correction_1 = mjd_tdb_1 - mjd_tt_1;
    double correction_2 = mjd_tdb_2 - mjd_tt_2;
    
    // Corrections should be different due to Earth's orbital motion (6 months apart)
    assert(fabs(correction_1 - correction_2) > 1e-9);
    
    // Test 4: Verify magnitude of corrections
    double mjd_tt_4 = 50000.0; // Before J2000
    double mjd_tdb_4 = Mjday_TDB(mjd_tt_4);
    double correction_4 = mjd_tdb_4 - mjd_tt_4;
    
    // Correction should be reasonable (between -2ms and +2ms)
    assert(fabs(correction_4) < 2.5e-8);
    
    // Test 5: Test with negative T_TT (before J2000)
    double mjd_tt_old = 40000.0; // Much earlier epoch
    double mjd_tdb_old = Mjday_TDB(mjd_tt_old);
    
    assert(mjd_tdb_old > 39999.99 && mjd_tdb_old < 40000.01);
    
    // Test 6: Verify function works in both directions around J2000
    double mjd_tt_future = 60000.0; // Future epoch
    double mjd_tdb_future = Mjday_TDB(mjd_tt_future);
    
    double diff_future = fabs(mjd_tdb_future - mjd_tt_future);
    assert(diff_future < 2.5e-8);
    
    // Test 7: Check that function is continuous 
    double mjd_tt_base = 51544.5;
    double mjd_tt_close = 51544.50001; // Very close time (0.864 seconds)
    
    double mjd_tdb_base = Mjday_TDB(mjd_tt_base);
    double mjd_tdb_close = Mjday_TDB(mjd_tt_close);
    
    // Results should be very close for very close inputs
    // 0.00001 days difference should give less than 1e-4 days difference in result
    assert(fabs(mjd_tdb_close - mjd_tdb_base) < 1e-4);
}

REGISTER_TEST(test_Mjday_TDB);