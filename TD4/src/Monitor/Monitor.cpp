
#include "Monitor.h"

Mutex::Monitor::Monitor(Mutex& m) : mutex(m){}

void Mutex::Monitor::wait()
{
    pthread_cond_wait(&mutex.posixCondId,&mutex.posixId);
}

bool Mutex::Monitor::wait(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    return !(bool) pthread_cond_timedwait(&mutex.posixCondId, &mutex.posixId, &timeout_ts);
}

void Mutex::Monitor::notify()
{
    pthread_cond_signal(&mutex.posixCondId);
}

void Mutex::Monitor::notifyAll()
{
    pthread_cond_broadcast(&mutex.posixCondId);
}

const char* Mutex::Monitor::TimeoutException::launchingException() const noexcept
{
    return "Time out Exception";
}
