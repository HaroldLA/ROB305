/**
 * @file Chrono.h
 * @author Harold Exinover (harlozar@gmail.com)
 * @brief Class that implements the time measurement features of a stopwatch.
 * @version 0.1
 * @date 2022-03-28
 * 
 */

#ifndef Chrono_h_INCLUDED
#define Chrono_h_INCLUDED

#include<time.h>

class Chrono
{
    private:

    timespec startTime_;
    timespec stopTime_;

    public:
    
    Chrono(); //Constructor
    void stop();
    void restart();
    bool isActive();
    double startTime();
    double stopTime();
    double lap();
};


#endif