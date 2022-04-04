
#ifndef SemaphoreConsumer_h_INCLUDED
#define SemaphoreConsumer_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"
#include "../Semaphore/Semaphore.h"

class SemaphoreConsumer : public Thread
{
private:
    Semaphore *semaphore;
    unsigned int counter;
    unsigned int maxCounter;	
public:
    SemaphoreConsumer(Semaphore *semaphore, unsigned int maxCount);
    int getCount();
protected:
    void run();
};

#endif