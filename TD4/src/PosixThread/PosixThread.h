#ifndef PosixThread_h_INCLUDED
#define PosixThread_h_INCLUDED

#include<pthread.h> 
#include<exception>
#include<iostream>
#include "../../../Time_Lib/include/Fonctions.h"

class PosixThread
{
    private:
        pthread_t posixId;
        pthread_attr_t posixAttr;
    protected:
        bool isActive = false;
    public:
        PosixThread();
        PosixThread(pthread_t posixId);
        ~PosixThread();
        void start(void*(*threadFunc)(void*), void* threadArg); 
        void join();
        bool setScheduling(int schedPolicy, int priority);
        bool getScheduling(int* p_schedPolicy = nullptr, int* p_priority = nullptr);
        class Exception;
};

class PosixThread::Exception : public std::exception
{
public:		
	const char* launchingException() const noexcept;
};

#endif