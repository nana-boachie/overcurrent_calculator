#ifndef OVERCURRENT_CALCULATOR_H
#define OVERCURRENT_CALCULATOR_H
enum CurveStandard {
    IEC,
    IEEE
};

enum IECCurveType {
    inverse = 0,
    veryInverse=1,
    extremelyInverse=2
};
enum IEEECurveType {
   moderateInverse = 3,
    VeryInverse=4,
    ExtremelyInverse=5
 
};


int curve_selector(
    CurveStandard standard
);



int calculate_trip_time_iec(double pickup_current,double fault_current,
    double time_multiplier_setting, IECCurveType 
);

int calculate_trip_time_ieee(double pickup_current, double fault_current,
    double time_multiplier_setting, IEEECurveType 
);





#endif // OVERCURRENT_CALCULATOR_H