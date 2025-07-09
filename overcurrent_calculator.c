#include <stdio.h>
#include "overcurrent_calculator.h"
#include <math.h>



int calculate_trip_time_iec(double pickup_current,double fault_current,
    double time_multiplier_setting,int IECCurveType)
{
    double trip_time;
    printf("Calculating trip time for IEC standard...\n");
    printf("Pickup Current: %.2f A, Fault Current: %.2f A, Time Multiplier Setting: %.2f\n",
           pickup_current, fault_current, time_multiplier_setting);
   
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
    case 1: // Very Inverse
    k = 13.5; // Example constant for Very Inverse curve
    a = 1;
    trip_time = (k / (pow((pickup_current / fault_current), a) - 1)) * time_multiplier_setting;
    printf("Trip time (Very Inverse): %.2f seconds\n", trip_time);
    break;
 case 2: //Extremely Inverse
    a = 2;
    trip_time = (80 / (pow((pickup_current / fault_current), a) - 1)) * time_multiplier_setting;
    printf("Trip time (Extremely Inverse): %.2f seconds\n", trip_time);
    break;
 case 3: // Long time standard inverse
    k = 120; // Example constant for Very Inverse curve
    a = 1;
    trip_time = (k / (pow((pickup_current / fault_current), a) - 1)) * time_multiplier_setting;
    printf("Trip time (Long time standard inverse): %.2f seconds\n", trip_time);
    break;
    default:
    printf("Invalid IEC curve type.\n");
    return -2; // Error code for invalid curve type
    
     
    }

    return 0;
}

int calculate_trip_time_ieee(double pickup_current, double fault_current,
    double time_multiplier_setting, int IEEECurveType)
{
    double trip_time;
    printf("Calculating trip time for IEEE standard...\n");
    printf("Pickup Current: %.2f A, Fault Current: %.2f A, Time Multiplier Setting: %.2f\n",
           pickup_current, fault_current, time_multiplier_setting);
   
    // Placeholder for actual IEEE trip time calculation logic
    if (pickup_current <= 0 || fault_current <= 0 || time_multiplier_setting <= 0) {
        printf("Invalid input values.\n");
        return -1; // Error code for invalid input
    }

    switch (IEEECurveType) 
    {
    case 3: // Moderate Inverse
        trip_time = ((.0515 / (pow((pickup_current / fault_current), .02)-1))+.114 ) * time_multiplier_setting;
        printf("Trip time (Moderate Inverse): %.2f seconds\n", trip_time);
        break;
    case 4: // Very Inverse
        trip_time = ((19.61/ (pow((pickup_current / fault_current), 2)-1))+.491 ) * time_multiplier_setting;
        printf("Trip time (Very Inverse): %.2f seconds\n", trip_time);
        break;
    case 5: // Extremely Inverse
        trip_time = ((28.2 / (pow((pickup_current / fault_current), 2)-1))+.1217 ) * time_multiplier_setting;
        printf("Trip time (Extremely Inverse): %.2f seconds\n", trip_time);
        break;
    default:
        printf("Invalid IEEE curve type.\n");
        return -2; // Error code for invalid curve type
    }


    return 0;
}