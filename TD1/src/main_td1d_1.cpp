/**
 * @file main_td1d_1.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief Implement a calib function that establishes the values of a and b by measuring 
 * the value of iLoop for 4 seconds and for 6 seconds. So that an affine function l(t), 
 * which represents the number of loops performed by an incr function during the time 
 * interval t, is defined as l(t)=a×t+b. With iLoop the variable counting the loop in the 
 * incr function (in the expression for(iLoop=0; iLoop < nLoops; ++iLoop))
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

struct linear
{
    double a;
    double b;
};

/**
 * @brief This function performs a loop incrementing by 1.0 the value 
 * of the counter pointed to by pCounter it performs this loop nLoops times.
 * It is possible to interrupt the process by setting *pStop to true. 
 * Returns the value of 'iLoop' iterations made before stopping.  
 * 
 * @param nLoops 
 * @param pCounter 
 * @param pStop 
 * @return unsigned 
 */
unsigned incr(unsigned int nLoops, double* pCounter, bool* pStop)
{
    unsigned iLoop;
    for(iLoop=0 ; iLoop < nLoops ; ++iLoop)
    {
        *(pCounter) += 1.0;  
        if(*pStop == true) break;
    }  
    return iLoop;
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
}

/**
 * @brief Implementation of a Posix timer with a varaible stopping
 *  time that measures the number of iterations made before expiring. 
 * 
 * @param t 
 * @return double 
 */
double timerT(time_t t)
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
    its.it_value.tv_sec = t;                    // Duration of the 1st timer expiry :
    its.it_value.tv_nsec = 0;                   // t seconds
    its.it_interval.tv_sec = 0;                 // Periodic timer expiry time :
    its.it_interval.tv_nsec = 0;              
    timer_settime(tid, 0, &its, nullptr);       // Timer start

    double iLoop = (double) incr(nLoops, &counter, &stop);
    std::cout << " - " << counter << " loops made in " << t <<"s"<<std::endl; 

    timer_delete(tid);
    return iLoop;
}

/**
 * @brief Function that establishes the values of a and b by 
 * measuring the value of iLoop for 4 seconds and for 6 seconds.
 * 
 * @return linear 
 */
linear calib()
{

    linear coeffs;
    double iLoop4s = timerT((time_t)4);
    double iLoop6s = timerT((time_t)6);

    coeffs.a = (iLoop6s - iLoop4s)/2;
    coeffs.b = ((iLoop6s + iLoop4s) - 10*(coeffs.a))/2;

    return coeffs;
}


int main()
{
    std::cout<<"\n"<<std::endl;

    timespec start = timespec_now();
    linear coeffs = calib();
    timespec end = timespec_now(); 
    
    std::cout<<"\n"<<std::endl;
    std::cout<<" - a = "<<coeffs.a<<std::endl;
    std::cout<<" - b = "<< coeffs.b<<std::endl;
    std::cout<<" - Time = "<< timespec_to_ms(end-start)/1000.0 <<"s"<<std::endl;

    std::cout<<"\n"<<std::endl;
    std::cout<<" -> l(t) = a*t+b when t = 1s : "<< coeffs.a + coeffs.b <<std::endl;
    std::cout<<"\n"<<std::endl;

    return 0;
}