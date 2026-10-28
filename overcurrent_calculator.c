#include <stdio.h>
#include "overcurrent_calculator.h"
#include <math.h>






int calculate_trip_time_iec(double pickup_current,double fault_current,
    double time_multiplier_setting,int IECCurveType){
    
        double trip_time;
    printf("Calculating trip time for IEC standard...\n");
    printf("Pickup Current: %.2f A, Fault Current: %.2f A, Time Multiplier Setting: %.2f\n",
           pickup_current, fault_current, time_multiplier_setting);
   
    // Placeholder for actual IEC trip time calculation logic
    if (pickup_current <= 0 || fault_current <= 0 || time_multiplier_setting <= 0) {
        printf("Invalid input values.\n");
        return -1; // Error code for invalid input
    }
    if (fault_current <= pickup_current) {
        printf("Fault current is at or below pickup: the relay will not trip.\n");
        return -3; // Error code for no trip
    }

    switch (IECCurveType) 
    {
    case 0: // Inverse
    trip_time = (.14 / (pow((fault_current / pickup_current),.02)-1)) * time_multiplier_setting;
    printf("Trip time (Inverse): %.2f seconds\n", trip_time);
    break;
    case 1: // Very Inverse
    trip_time = (13.5 / (pow((fault_current / pickup_current), 1) - 1)) * time_multiplier_setting;
    printf("Trip time (Very Inverse): %.2f seconds\n", trip_time);
    break;
    case 2: //Extremely Inverse
    trip_time = (80 / (pow((fault_current / pickup_current), 2) - 1)) * time_multiplier_setting;
    printf("Trip time (Extremely Inverse): %.2f seconds\n", trip_time);
    break;
 case 3: // Long time standard inverse
    trip_time = (120/ (pow((fault_current / pickup_current), 1) - 1)) * time_multiplier_setting;
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
    if (fault_current <= pickup_current) {
        printf("Fault current is at or below pickup: the relay will not trip.\n");
        return -3; // Error code for no trip
    }

    switch (IEEECurveType) 
    {
    case moderateInverse:
        trip_time = ((.0515 / (pow((fault_current / pickup_current), .02)-1))+.114 ) * time_multiplier_setting;
        printf("Trip time (Moderate Inverse): %.2f seconds\n", trip_time);
        break;
    case VeryInverse:
        trip_time = ((19.61/ (pow((fault_current / pickup_current), 2)-1))+.491 ) * time_multiplier_setting;
        printf("Trip time (Very Inverse): %.2f seconds\n", trip_time);
        break;
    case ExtremelyInverse:
        trip_time = ((28.2 / (pow((fault_current / pickup_current), 2)-1))+.1217 ) * time_multiplier_setting;
        printf("Trip time (Extremely Inverse): %.2f seconds\n", trip_time);
        break;
    default:
        printf("Invalid IEEE curve type.\n");
        return -2; // Error code for invalid curve type
    }


    return 0;
}