#ifndef SemaphoreProducer_h_INCLUDED
#define SemaphoreProducer_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"
#include "../Semaphore/Semaphore.h"

class SemaphoreProducer : public Thread
{
private:
    Semaphore *semaphore;
    unsigned int counter;
    unsigned int maxCounter;
public:
    SemaphoreProducer(Semaphore *semaphore, unsigned int maxCount);
    int getCount();
protected:
    void run();
};

#endif