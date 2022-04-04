#ifndef CountDown_h_INCLUDED
#define CountDown_h_INCLUDED

#include "../PeriodicTimer/PeriodicTimer.h"

class CountDown : public PeriodicTimer
{
private:
    int count;
public:
    CountDown(int n);
    int get_count();
protected:
    void callback();
};

#endif