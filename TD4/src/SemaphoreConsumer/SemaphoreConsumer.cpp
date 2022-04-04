#include "SemaphoreConsumer.h"

SemaphoreConsumer::SemaphoreConsumer(Semaphore *semaphore, unsigned int maxCount) : Thread(), semaphore(semaphore), counter(0), maxCounter(maxCount){}

void SemaphoreConsumer::run()
{
    while (counter<maxCounter)
    {
        semaphore->take();
        counter++;
    } 
}

int SemaphoreConsumer::getCount(){
    return counter;
}
