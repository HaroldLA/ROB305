#include <time.h>
#include <pthread.h>
#include "Chrono.h"
#include "../../../Time_Lib/include/Fonctions.h"


Chrono::Chrono()
{
    startTime_ = timespec_now(); 
    stopTime_ = timespec_from_ms(0.0);
}

void Chrono::stop()
{
    stopTime_ = timespec_now(); 
}

void Chrono::restart()
{
    startTime_ = timespec_now(); 
    stopTime_ = timespec_from_ms(0.0);
}

bool Chrono::isActive()
{
    return Chrono::stopTime() == 0;
}

double Chrono::lap()
{
    if(isActive()){
        return timespec_to_ms(timespec_subtract(timespec_now(), startTime_));
    }else{
        return timespec_to_ms(timespec_subtract(stopTime_,startTime_));
    }
}

double Chrono::startTime()
{
    return timespec_to_ms(startTime_);
}

double Chrono::stopTime()
{
    return timespec_to_ms(stopTime_);
}
