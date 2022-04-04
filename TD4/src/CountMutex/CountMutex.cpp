
#include "CountMutex.h"

CountMutex::CountMutex(Data* data, Mutex& m): data(data), mutex(m)
{
	int schedPriority = std::rand()%99 + 1;       //I get a number between 1 and 99
    if(data->schedPolicy == SCHED_OTHER)
        schedPriority = 0;
    
    setScheduling(data->schedPolicy, schedPriority);
}
	
void CountMutex::run(){
    for(unsigned int i=0; i < data->nLoops; i++)
    {
        Mutex::Lock lock(mutex);
        data -> pCounter += 1.0;
        lock.~Lock();
    }  
}

int CountMutex::get_count(){
    return  data -> pCounter;
}

