 #include "CpuLoop.h"


CpuLoop::CpuLoop(Calibrator& calibrator):calib(calibrator){}

void CpuLoop::runTime(double duration_ms)
{   
    runLoop(calib.nLoops(duration_ms));

}