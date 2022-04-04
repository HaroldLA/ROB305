#include <iostream>
#include <string>
#include "Chrono/Chrono.h"
#include "CpuLoop/CpuLoop.h"
#include "../../Time_Lib/include/Fonctions.h"


int main(int argc, char const *argv[])
{
    
        if(argc < 4)
        {
        std::cout << "Insert value for 'samplingPeriod_ms', 'nSamples' and 'duration_ms'." << std::endl;
        return 0;
        }

        double samplingPeriod_ms = (double) std::atoi(argv[1]);
        unsigned nSamples = (unsigned) std::atoi(argv[2]);
        double duration_ms = (double) std::atoi(argv[3]);

        std::cout << "Calibration time : " << (double)nSamples*samplingPeriod_ms/1000.0 << "s" << std::endl;
        std::cout << "Estimated chrono time : " << duration_ms/1000.0 << "s" << std::endl;
        Calibrator calibrator(samplingPeriod_ms, nSamples); 
        
        CpuLoop	cpuLoop(calibrator);
        Chrono chrono;
        cpuLoop.runTime(duration_ms);
        chrono.stop();
        std::cout << "Real chrono time : " << chrono.lap()/1000.0 - 0.99 << "s" << std::endl;
    return 0;
}
