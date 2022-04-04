#ifndef Thread_h_INCLUDED
#define Thread_h_INCLUDED

#include <time.h>
#include "../PosixThread/PosixThread.h"
#include "../../../Time_Lib/include/Operateurs.h"

class Thread : public PosixThread
{
private:

	timespec startTime_;
	timespec stopTime_;
    static void* call_run(void* v_thread);
    bool started = false;
public:
    
    Thread();
    ~Thread();
    void start();
    void sleep_ms(double delay_ms);
    
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();

protected:
    virtual void run() = 0;    
};

#endif