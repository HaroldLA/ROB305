
#include "Thread.h"

Thread::Thread(){}

Thread::~Thread(){}

void Thread::start()
{
    if(!started){
        startTime_ = timespec_now();
        PosixThread::start(call_run, (void*) this);
        stopTime_ = timespec_now();
        started = true;
    }
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}
    
double Thread::startTime_ms()
{
    return timespec_to_ms(startTime_);

}
double Thread::stopTime_ms()
{ 
    return timespec_to_ms(stopTime_);
}
double Thread::execTime_ms()
{
    return timespec_to_ms(stopTime_ - startTime_);
}

void* Thread::call_run(void* v_thread)
{
    Thread* thread = (Thread*) v_thread;
    thread->run();
    return (void*) thread;
}


