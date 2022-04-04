#include<iostream>
#include<pthread.h>
#include<vector>

#include "CountThread/CountThread.h"
#include "../../TD3/src/Chrono/Chrono.h"

int main(int argc, char const *argv[])
{
    if(argc<4){
        std::cout<<"'nLoops', 'nTasks' and 'SchedPolicy' parameters are needed. "<<std::endl;
        return 0;
    }
    unsigned nLoops = std::stoi(argv[1]);
    unsigned nTasks = std::stoi(argv[2]);
    std::string policy(argv[3]);

    int schedPolicy = 0;
    double threadTime = 0.0;

    if(policy == "SCHED_RR")
        schedPolicy = SCHED_RR;
    else if(policy == "SCHED_FIFO") 
        schedPolicy = SCHED_FIFO;
    else if(policy == "SCHED_OTHER") 
        schedPolicy = SCHED_OTHER;

    Data data = {nLoops, 0.0, schedPolicy};

    Chrono chrono;

    CountThread* incrementThread[nTasks];


    for (unsigned i=0;i<nTasks;i++)
    {
        incrementThread[i] = new CountThread(&data);
    }

    for (unsigned i=0; i<nTasks; ++i) 
    {
        incrementThread[i]->start();
        threadTime += incrementThread[i]->execTime_ms();
    }
    for (unsigned i=0; i<nTasks; ++i) 
        incrementThread[i]->join();

    chrono.stop();

    std::cout << "Count : " <<  incrementThread[0]->get_count() << std::endl;
    std::cout << "Cumulated time for all thread operations : " << threadTime << " ms" << std::endl;
    std::cout << "Total duration : " << chrono.lap() << "ms" << std::endl;

    return 0;
}
