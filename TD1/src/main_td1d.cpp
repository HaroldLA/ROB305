/**
 * @file main_td1d.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief Implementation code of the function 'incr(unsigned nLoops, double* pCounter)' 
 * @version 0.1
 * @date 2022-03-26
 * 
 */

#include <iostream>
#include <string>
#include <time.h>
#include <climits>
#include <signal.h>
#include "../../Time_Lib/include/Fonctions.h"
#include "../../Time_Lib/include/Operateurs.h"


/**
 * @brief This function performs a loop incrementing by 1.0 the value 
 * of the counter pointed to by pCounter it performs this loop nLoops times.
 * It is possible to interrupt the process by setting *pStop to true 
 * 
 * @param nLoops 
 * @param pCounter 
 * @param pStop 
 */
void incr(unsigned nLoops, double* pCounter, bool* pStop)
{
    for(unsigned i=0; i<nLoops; i++)
    {
        *(pCounter) += 1.0;  
        if(*pStop == true) break;
    }  
}

/**
 * @brief Callback function setting the pStop value to true when the timer expires
 * 
 * @param si 
 */
void myHandler(int, siginfo_t* si, void*)
{
    volatile bool& pStop = *((bool*) si->si_value.sival_ptr);
    pStop = true;
    std::cout<<"pStop : " << pStop << std::endl;
}


int main()
{

    unsigned int nLoops = UINT_MAX;
    double counter = 0;
    bool stop = false;

    struct sigaction sa;                        // Action to be taken when timer expires
    sa.sa_flags = SA_SIGINFO;                   // The action is a function call with parameters
    sa.sa_sigaction = myHandler;                // Pointer to the function 'myHandler' to be called
    sigemptyset(&sa.sa_mask);                   // Blocking flags at 0: no signal blocked during callback execution
    sigaction(SIGRTMIN, &sa, nullptr);          // Action associated with a real-time signal: between SIGRTMIN and SIGRTMAX

    struct sigevent sev;                        // Timer expiry event
    sev.sigev_notify = SIGEV_SIGNAL;            // The event will be of the "signal" type
    sev.sigev_signo = SIGRTMIN;                 // Number of the transmitted signal: the same as the one associated with the action
    sev.sigev_value.sival_ptr = (void*) &stop;  // Data to be transmitted to 'myHandler'

    timer_t tid;                                // Timer identifier
    timer_create(CLOCK_REALTIME, &sev, &tid);   // Creation of the timer
    itimerspec its;                             // Structure containing the expiry time(s) of the timer
    std::cout<<"Waiting 1 seconds" << std::endl;
    its.it_value.tv_sec = 1;                    // Duration of the 1st timer expiry :
    its.it_value.tv_nsec = 0;                   // 1 seconds
    its.it_interval.tv_sec = 0;                 // Periodic timer expiry time :
    its.it_interval.tv_nsec = 1e9;              // 1Hz
    timer_settime(tid, 0, &its, nullptr);       // Timer start

    timespec start = timespec_now();            // Measure of the real initial time from the 'fonctions.h' library 
    incr(nLoops, &counter, &stop);              // Calling the incr() function including the parameter 'stop'
    timespec end = timespec_now();              // Measure of the real final time from the 'fonctions.h' library 
    
    std::cout<<"Count : "<<counter << "/ Time : "<< timespec_to_ms(end-start)/1000.0 <<"s"<<std::endl;

    timer_delete(tid);                          // Destruction of the timer
    return 0;
}