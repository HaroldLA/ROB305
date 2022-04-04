/**
 * @file main_td2b.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief Execution time measurement: Implementation code of the function 
 * 'incr(unsigned nLoops, double* pCounter)' with real-time scheduling.
 * @version 0.1
 * @date 2022-03-28
 * 
 */
#include<time.h>
#include<iostream>
#include<string>
#include<pthread.h>
#include "../../Time_Lib/include/Fonctions.h"
#include "../../Time_Lib/include/Operateurs.h"


struct Data 
{
    volatile unsigned int nLoops;
    volatile double* pCounter;
};

/**
 * @brief This function performs a loop incrementing by 1.0 the value 
 * of the counter pointed to by pCounter it performs this loop nLoops times
 * 
 * @param nLoops 
 * @param pCounter 
 */
void incr(unsigned nLoops, double* pCounter)
{
    for(unsigned i=0; i < nLoops; i++)
    { 
        *(pCounter) += 1.0;
    }    
}

/**
 * @brief Function that calls the incr() function describing the task made by a thread 
 * 
 * @param data 
 * @return void* 
 */
void* call_incr(void* data)
{
    Data* p_data = (Data*) data;
    incr(p_data->nLoops, (double*)p_data->pCounter); 

    return data;   
}

int main(int argc, char* argv[])
{

    if(argc<4)
    {
        std::cout<<"'nLoops', 'nTasks' and 'SchedPolicy' parameters are needed. "<<std::endl;
        return 0;
    }

    unsigned nLoops = std::stoi(argv[1]);
    unsigned nTasks = std::stoi(argv[2]);
    std::string policy(argv[3]);

    double counter = 0.0;
    int schedPolicy;


    // Choice of a scheduling policy
    if(policy == "SCHED_RR")
        schedPolicy = SCHED_RR;
    else if(policy == "SCHED_FIFO") 
        schedPolicy = SCHED_FIFO;
    else if(policy == "SCHED_OTHER") 
        schedPolicy = SCHED_OTHER;

    struct sched_param schedParam;                                      // Application of scheduling 
    schedParam.sched_priority = sched_get_priority_max(schedPolicy);    // parameters (priority)
    pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);    //

    timespec begin;
    timespec end;

    Data data = {nLoops, &counter};


    begin = timespec_now();
    pthread_t incrementThread[nTasks];
    for (unsigned i=0; i<nTasks; ++i) 
        pthread_create(&incrementThread[i], nullptr, call_incr, &data); // Creation and start of the task

    for (unsigned i=0; i<nTasks; ++i) 
        pthread_join(incrementThread[i], nullptr);                      // Waiting for the task to finish
        
    end = timespec_now();
    std::cout<<"Count : "<<counter<<std::endl;
    std::cout<<"Duratrion : "<<timespec_to_ms(end - begin)<<"ms"<<std::endl;
    return 0;
}