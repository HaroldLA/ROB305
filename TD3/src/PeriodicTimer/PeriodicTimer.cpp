#include "PeriodicTimer.h"
#include "../../../Time_Lib/include/Fonctions.h"

void PeriodicTimer::start(double duration_ms){
    
    itimerspec its;

    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval = its.it_value;

    timer_settime(tid, 0, &its, nullptr);
}
