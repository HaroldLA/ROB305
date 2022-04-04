#ifndef Lock_h_INCLUDED
#define Lock_h_INCLUDED

#include "../Mutex/Mutex.h"
#include "../Monitor/Monitor.h"

class Mutex::Lock : public Monitor  
{
public:
    Lock(Mutex& m);
    Lock(Mutex& m, double timeout_ms);
    ~Lock();
};

#endif