#include <stdio.h>
#include "overcurrent_calculator.h"




int main(void){

    double pickup_current, fault_current, time_multiplier_setting;
    
    int curve_type, standard;

    printf("Overcurrent Protection Trip Time Calculator\n");
    
    printf("========================================\n");
 
    // Prompt user for curve standard
    printf("Select Curve Standard:\n");
    
    
    do {
    printf("Select Curve Standard (20 for IEC, 30 for IEEE): ");
    scanf("%d", &standard);
    } while (standard != IEC && standard != IEEE);




    printf("Enter Pickup Current (A): ");
    scanf("%lf", &pickup_current);
    printf("Enter Fault Current (A): ");
    scanf("%lf", &fault_current);
    printf("Enter Time Multiplier Setting: ");
    scanf("%lf", &time_multiplier_setting);


    if (standard == IEC)
    {
      printf("Select IEC Curve Type (0: Inverse, 1: Very Inverse, 2: Extremely Inverse, 3: Long Time Standard Inverse): ");
      scanf("%d", &curve_type);
      calculate_trip_time_iec(pickup_current, fault_current, time_multiplier_setting, curve_type);
    } else if (standard == IEEE) {
        printf("Select IEEE Curve Type (4: Moderate Inverse, 5: Very Inverse, 6: Extremely Inverse): ");
        scanf("%d", &curve_type);
        calculate_trip_time_ieee(pickup_current, fault_current, time_multiplier_setting, curve_type);
    } else {
        printf("Invalid Curve Standard selected.\n");
    }

    return 0;
}