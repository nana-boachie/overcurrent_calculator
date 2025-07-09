#include <stdio.h>
#include "overcurrent_calculator.h"
#include <math.h>



int calculate_trip_time_iec(double pickup_current,double fault_current,
    double time_multiplier_setting,int IECCurveType)
{
    double trip_time;

   
    // Placeholder for actual IEC trip time calculation logic
    if (pickup_current <= 0 || fault_current <= 0 || time_multiplier_setting <= 0) {
        printf("Invalid input values.\n");
        return -1; // Error code for invalid input
    }

    switch (IECCurveType) 
    {
    case 0: // Inverse
    double k = 0.14; // Example constant for Inverse curve
    double a = 0.02;
    trip_time = (k / (pow((pickup_current / fault_current),a)-1)) * time_multiplier_setting;
    printf("Trip time (Inverse): %.2f seconds\n", trip_time);
    break;
    
    default:
        break;
    }

    return 0;
}

int calculate_trip_time_ieee()
{
    return 0;
}