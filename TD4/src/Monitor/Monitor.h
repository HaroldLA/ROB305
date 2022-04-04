#ifndef Monitor_h_INCLUDED
#define Monitor_h_INCLUDED

#include <exception>
#include "../Mutex/Mutex.h"

class Mutex::Monitor
{        
    protected:
        Monitor(Mutex& m);
    public:
        Mutex& mutex;
        class TimeoutException;
        void wait();
        bool wait(double timeout_ms);
        void notify();
        void notifyAll();

};

class Mutex::Monitor::TimeoutException : public std::exception
{
public:		
	const char* launchingException() const noexcept;
};

#endif