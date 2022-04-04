#ifndef CountThread_h_INCLUDED
#define CountThread_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"


struct Data 
{
    volatile unsigned int nLoops;
    volatile double pCounter;
    int schedPolicy;
};

class CountThread : public Thread
{
private:
    Data* data;
public:
    CountThread(Data* data);
    int get_count();
protected:
    void run();
};


#endif