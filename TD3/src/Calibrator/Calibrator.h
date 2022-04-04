#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED

#include<vector>
#include "../PeriodicTimer/PeriodicTimer.h"
#include "../Looper/Looper.h"

class Calibrator : public PeriodicTimer
{
private:
    double a;
    double b;
    std::vector<double> samples;
    unsigned count = 0;
public:
    Calibrator(double samplingPeriod_ms, unsigned nSamples);
    double nLoops(double duration_ms);
protected:
    void callback(); 
    Looper looper;   
};

#endif