#ifndef Fifo_hpp_INCLUDED
#define Fifo_hpp_INCLUDED

#include <queue>
#include <exception>
#include "../Lock/Lock.h" 

template<typename T>
class Fifo
{
private:
    Mutex mutex;
    std::queue<T> elements;
public:
    void push(T element);
    T pop();
    T pop(double timeout_ms);
    
    class EmptyException : std::exception
	{
		public:
			const char* throwException() const noexcept;
	};	
};

template<typename T>
void Fifo<T>::push(T element)
{
    Mutex::Lock lock(mutex);
	elements.push(element);
	lock.notify();
}

template<typename T>
T Fifo<T>::pop()
{
	Mutex::Lock lock(mutex);
	T popElem = elements.front();
    if (elements.empty()) 
	{
		lock.wait();
	}
	else
	{
		elements.pop();
	}	
	lock.notify();
	return popElem;
}

template<typename T>
T Fifo<T>::pop(double timeout_ms)
{
	Mutex::Lock lock(mutex);
	T popElem = elements.front(); 
	if (elements.empty())
	{
		throw Fifo<T>::EmptyException();
		lock.wait(timeout_ms);
		lock.notify();
    }    
	else
	{
		elements.pop();
		lock.notify();
	}
	return popElem;
}

template <typename T> const char *Fifo<T>::EmptyException::throwException() const noexcept
{
	return "Empty exception!\n";
}


#endif