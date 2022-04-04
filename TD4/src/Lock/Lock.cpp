
#include "Lock.h"

Mutex::Lock::Lock(Mutex& m) : Monitor(m)
{
    m.lock();
}

Mutex::Lock::Lock(Mutex& m, double timeout_ms) : Monitor(m)
{
    if(mutex.lock(timeout_ms) == false)
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::Lock::~Lock()                                    
{
    mutex.unlock();
}

