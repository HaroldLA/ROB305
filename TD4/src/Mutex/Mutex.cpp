
#include "Mutex.h"

Mutex::Mutex()
{
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&posixId, &mutexAttr);
    pthread_cond_init(&posixCondId, NULL);
    pthread_mutexattr_destroy(&mutexAttr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&posixId);
    pthread_cond_destroy(&posixCondId);
}
 
void Mutex::lock()
{
    pthread_mutex_lock(&posixId);
} 

void Mutex::unlock()
{
    pthread_mutex_unlock(&posixId);
} 

bool Mutex::lock(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    return !(bool)pthread_mutex_timedlock(&posixId, &timeout_ts);
} 

bool Mutex::trylock()
{
    return !(bool)pthread_mutex_trylock(&posixId);
} 