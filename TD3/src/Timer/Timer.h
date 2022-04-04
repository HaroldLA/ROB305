#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED

#include<time.h>
#include<signal.h>

class Timer
{
protected:
    timer_t tid;
    void virtual callback()=0;
private:
    static void call_callback(int,siginfo_t* si, void*);
public:
    Timer();
    virtual ~Timer();
    void start(double duration_ms);
    void stop();

};

#endif
