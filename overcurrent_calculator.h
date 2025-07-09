#ifndef OVERCURRENT_CALCULATOR_H
#define OVERCURRENT_CALCULATOR_H
enum CurveStandard {
    IEC=20,
    IEEE=30
};

enum IECCurveType {
    inverse = 0,
    veryInverse=1,
    extremelyInverse=2,
    longTimeStandardInverse=3
};
enum IEEECurveType {
   moderateInverse = 4,
    VeryInverse=5,
    ExtremelyInverse=6,
 
};


int curve_selector(
    int CurveStandard 
);



int calculate_trip_time_iec(double pickup_current,double fault_current,
    double time_multiplier_setting, int IECCurveType 
);

int calculate_trip_time_ieee(double pickup_current, double fault_current,
    double time_multiplier_setting,int IEEECurveType 
);





#endif // OVERCURRENT_CALCULATOR_H