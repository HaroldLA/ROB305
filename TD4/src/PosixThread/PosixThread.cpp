
#include "PosixThread.h"


PosixThread::PosixThread()
{
    this -> posixId = 0;
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&posixAttr, SCHED_OTHER);

    sched_param schedParam;
    schedParam.sched_priority = 0;
    pthread_attr_setschedparam(&posixAttr, &schedParam);
}

PosixThread::PosixThread(pthread_t posixId) : posixId(posixId) 
{
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    
    sched_param schedParam;
    int policy= 0;
    
    int param = pthread_getschedparam(this -> posixId, &policy, &schedParam);
    if(param == 0)
    {
        this -> isActive = true;
    	pthread_attr_setschedpolicy(&posixAttr, policy);
    	pthread_attr_setschedparam(&posixAttr, &schedParam); 
    }
    else
    {
        throw PosixThread::Exception();    	
    }
}

PosixThread::~PosixThread()
{
    pthread_attr_destroy(&posixAttr);
}


void PosixThread::start(void*(*threadFunc)(void*), void* threadArg)
{
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);
    isActive = true;
}

bool PosixThread::setScheduling(int schedPolicy, int priority)
{    
    struct sched_param schedParam;
    schedParam.sched_priority = priority;

    if(isActive)
    {
        pthread_setschedparam(posixId, schedPolicy, &schedParam);
    } 
    else
    {
        pthread_attr_setschedpolicy(&posixAttr,schedPolicy);
        pthread_attr_setschedparam(&posixAttr,&schedParam);
    }
    return isActive;
}

bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{
    struct sched_param schedParam;
    *p_priority = schedParam.sched_priority ;

    if(isActive)
    {
        pthread_getschedparam(posixId,p_schedPolicy, &schedParam);
    }
    else
    {
        pthread_attr_getschedparam(&posixAttr, &schedParam);
        pthread_attr_getschedpolicy(&posixAttr,p_schedPolicy);
    }
    return isActive;
}

void PosixThread::join()
{
    pthread_join(posixId,nullptr);
}

const char *PosixThread::Exception::launchingException() const noexcept
{
		return "\nThread does not exist!\n";
}