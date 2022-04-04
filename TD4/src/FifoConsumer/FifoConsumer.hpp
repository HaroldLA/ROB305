#ifndef FifoConsumer_h_INCLUDED
#define FifoConsumer_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"
#include "../Fifo/Fifo.hpp"

class FifoConsumer :public Thread
{
private:
    Fifo<int> *fifo;
    unsigned counter = 0;
    unsigned n;
    unsigned cumulative = 0;
public:
    FifoConsumer(Fifo<int> *fifo, unsigned int maxCount);
    unsigned getCount();
    unsigned getCumulative();
protected:
    void run();
};

FifoConsumer::FifoConsumer(Fifo<int> *fifo, unsigned int maxCount): Thread(), fifo(fifo), n(maxCount){}

void FifoConsumer::run()
{
    while (counter<n)
    {
        cumulative += fifo->pop();
        counter++;
    }
}

unsigned FifoConsumer::getCount(){
    return counter;
}

unsigned FifoConsumer::getCumulative(){
    return cumulative;
}

#endif

