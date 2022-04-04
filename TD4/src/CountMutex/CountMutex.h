#ifndef CountMutex_h_INCLUDED
#define CountMutex_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../CountThread/CountThread.h"
#include "../Lock/Lock.h"

class CountMutex : public Thread
{
private:
    Data* data;
    Mutex& mutex;
public:
    CountMutex(Data* data, Mutex& m);
    int get_count();
protected:
    void run();
};

#endif