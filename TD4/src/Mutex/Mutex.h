#ifndef Mutex_h_INCLUDE
#define Mutex_h_INCLUDE

#include <pthread.h>
#include <time.h>

#include "../../../Time_Lib/include/Fonctions.h"

class Mutex
{
private:
    pthread_mutex_t posixId;
    pthread_cond_t posixCondId;

    void lock();
    bool lock(double timeout_ms);
    bool trylock();
    void unlock();

public:
    class Lock;
    //class TryLock;
    class Monitor;

    Mutex();
    ~Mutex();

};

#endif 