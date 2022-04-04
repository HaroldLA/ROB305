#ifndef CpuLoop_h_INCLUDED
#define CpuLoop_h_INCLUDED

#include "../Calibrator/Calibrator.h"

class CpuLoop : public Looper 
{ 
    Calibrator& calib;   
public:
    CpuLoop(Calibrator& calibrator);
    void runTime(double duration_ms);
};

#endif