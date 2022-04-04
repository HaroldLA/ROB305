/**
 * @file main_td2c.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief  Multi-task execution with mutex: Implementation code of 
 * the function 'incr(unsigned nLoops, double* pCounter)'.
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
    pthread_mutex_t mutex;          // Adding a mutex to protect the shared data structure
    volatile bool protect = false;
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
 * It is possible to choose whether or not to use the mutex.
 * 
 * @param data 
 * @return void* 
 */
void* call_incr(void* data)
{
    Data* p_data = (Data*) data;
    if(p_data->protect == 1)
    {
        pthread_mutex_lock(&p_data->mutex);
        incr(p_data->nLoops, (double*)p_data->pCounter); 
        pthread_mutex_unlock(&p_data->mutex);
    }
    else
    {
        incr(p_data->nLoops, (double*)p_data->pCounter); 
    }

    return data;   
}


int main(int argc, char* argv[])
{

    if(argc<3)
    {
        std::cout<<"'nLoops' and 'nTasks' parameters are needed. "<<std::endl;
        return 0;
    }

    unsigned nLoops = std::stoi(argv[1]);
    unsigned nTasks = std::stoi(argv[2]);
    double counter = 0.0;


    timespec begin;
    timespec end;

    pthread_mutex_t mutex;

    Data data = {nLoops, &counter, mutex};
    pthread_mutex_init(&data.mutex, nullptr); // Mutex initialization 
    
    if(argc > 3)
    {
        std::string mode(argv[3]);
        if(mode.compare("Protected") == 0)
        {
            std::cout<<"Protected mode"<<std::endl;
            data.protect = true;
        }
    }
    else
    {
        std::cout<<"Unprotected mode"<<std::endl;
    }
    
    begin = timespec_now();
    pthread_t incrementThread[nTasks];

    for (unsigned i=0; i<nTasks; ++i) 
        pthread_create(&incrementThread[i], nullptr, call_incr, &data); // Creation and start of the task

    for (unsigned i=0; i<nTasks; ++i) 
        pthread_join(incrementThread[i], nullptr);                      // Waiting for the task to finish
    end = timespec_now();

    pthread_mutex_destroy(&data.mutex); // Mutex destruction

    std::cout<<"Count : "<<counter<<std::endl;
    std::cout<<"Duratrion : "<<timespec_to_ms(end - begin)<<std::endl;
    return 0;
}