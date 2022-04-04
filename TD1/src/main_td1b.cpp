/**
 * @file main_td1b.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief Implementation of a periodic Posix timer with a frequency of 2 Hz 
 * printing a message with the value of a regularly incremented counter. 
 * @version 0.1
 * @date 2022-03-26
 * 
 */

#include <time.h>
#include <iostream>
#include <signal.h>


/**
 * @brief Callback function incrementing the timer associated counter
 * 
 * @param si 
 */
void myHandler(int, siginfo_t* si, void*)
{
    volatile int& counter = *((int*) si->si_value.sival_ptr);
    std::cout<<"Counter : " << counter << std::endl;
    counter += 1;
}


int main()
{

    volatile int count = 0;                     // Variable to be passed to the timer

    struct sigaction sa;                        // Action to be taken when timer expires
    sa.sa_flags = SA_SIGINFO;                   // The action is a function call with parameters
    sa.sa_sigaction = myHandler;                // Pointer to the function 'myHandler' to be called
    sigemptyset(&sa.sa_mask);                   // Blocking flags at 0: no signal blocked during callback execution
    sigaction(SIGRTMIN, &sa, nullptr);          // Action associated with a real-time signal: between SIGRTMIN and SIGRTMAX

    struct sigevent sev;                        // Timer expiry event
    sev.sigev_notify = SIGEV_SIGNAL;            // The event will be of the "signal" type
    sev.sigev_signo = SIGRTMIN;                 // Number of the transmitted signal: the same as the one associated with the action
    sev.sigev_value.sival_ptr = (void*) &count; // Data to be transmitted to 'myHandler'

    timer_t tid;                                // Timer identifier
    timer_create(CLOCK_REALTIME, &sev, &tid);   // Creation of the timer
    itimerspec its;                             // Structure containing the expiry time(s) of the timer
    std::cout<<"Wait : 2 seconds" << std::endl;
    its.it_value.tv_sec = 2;                    // Duration of the 1st timer expiry :
    its.it_value.tv_nsec = 0;                   // 2 seconds
    its.it_interval.tv_sec = 0;                 // Periodic timer expiry time :
    its.it_interval.tv_nsec = 5e8;              // 2Hz
    timer_settime(tid, 0, &its, nullptr);       // Timer start

    while(count < 15)                           // The program stops after 15 increments.
        continue;

    timer_delete(tid);                          // Destruction of the timer

    return 0;
}
