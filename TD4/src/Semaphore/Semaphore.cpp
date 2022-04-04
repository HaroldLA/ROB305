#include "Semaphore.h"

Semaphore::Semaphore(unsigned initCount, unsigned maxCount) : counter(initCount), maxCount(maxCount){}
 
void Semaphore::give()
{
    Mutex::Lock lock(mutex);
    if(counter < maxCount) counter++; 
    lock.notify();
    lock.~Lock();
}

void Semaphore::take()
{   
    Mutex::Lock lock(mutex);
    if (counter == 0)  
    {
        lock.wait();
    }
    else
    {
        counter--;
    }
    lock.notify();
    lock.~Lock();      
}

bool Semaphore::take(double timeout_ms)
{
    Mutex::Lock lock(mutex);
    if (counter == 0)  
    {
        lock.wait(timeout_ms);
        lock.notify();
        lock.~Lock();
        return 0;
    }
    else
    {
        counter--;
        lock.notify();
        lock.~Lock();    
        return 1;  
    }
}
 
int Semaphore::getCounter(){
    return counter;
}

int Semaphore::getMaxCount(){
    return maxCount;
}

