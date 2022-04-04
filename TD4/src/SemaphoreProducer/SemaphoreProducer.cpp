#include "SemaphoreProducer.h"

SemaphoreProducer::SemaphoreProducer(Semaphore *semaphore, unsigned int maxCount): Thread(), semaphore(semaphore), counter(0), maxCounter(maxCount){}

void SemaphoreProducer::run()
{
    while (counter<maxCounter)
    {
        semaphore->give();
        counter++;
    }
}

int SemaphoreProducer::getCount(){
    return counter;
}
