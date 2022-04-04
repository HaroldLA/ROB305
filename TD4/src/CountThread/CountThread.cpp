
#include "CountThread.h"

CountThread::CountThread(Data* data): data(data)
{
	int schedPriority = std::rand()%9 + 1;       //I get a number between 1 and 99
    if(data->schedPolicy == SCHED_OTHER)
        schedPriority = 0;
    
    setScheduling(data->schedPolicy, schedPriority);
}
	
void CountThread::run(){
    for(unsigned int i=0; i < data->nLoops; i++)
    {
        data -> pCounter += 1.0;
    }  
}

int CountThread::get_count(){
    return  data -> pCounter;
}
