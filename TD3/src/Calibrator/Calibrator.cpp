#include "Calibrator.h"

Calibrator::Calibrator(double samplingPeriod_ms, unsigned nSamples)
{
    count = nSamples;

    PeriodicTimer::start(samplingPeriod_ms);
    looper.runLoop();


    double sumX=0, sumX2=0, sumY=0, sumXY=0;

    for (unsigned i = 0; i < nSamples; i++)
    {
        sumX  += samplingPeriod_ms*i;
        sumX2 += (samplingPeriod_ms*i)*(samplingPeriod_ms*i);
        sumY  += samples[i];
        sumXY += (samplingPeriod_ms*i)*samples[i];
    }

    a = (sumXY-sumX*sumY/nSamples)/(sumX2 - (sumX*sumX)/nSamples);
    b = (sumX2*sumY - sumXY*sumX)/(nSamples*sumX2 - sumX*sumX);
}

double Calibrator::nLoops(double duration_ms)
{
    return (a*duration_ms+b);
}

void Calibrator::callback()
{
    count--;
	if (count == 0)
	{
    	samples.push_back(looper.stopLoop());
        stop();
    }
    else
        samples.push_back(looper.getSample());

}

