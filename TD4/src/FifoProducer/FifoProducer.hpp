#ifndef FifoProducer_h_INCLUDED
#define FifoProducer_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"
#include "../Fifo/Fifo.hpp"

class FifoProducer :public Thread
{
private:
    Fifo<int> *fifo;
    unsigned counter = 0;
    unsigned n;
    unsigned cumulative = 0;
public:
    FifoProducer(Fifo<int> *fifo, unsigned int maxCount);
    unsigned getCount();
    unsigned getCumulative();
protected:
    void run();
};

FifoProducer::FifoProducer(Fifo<int> *fifo, unsigned int maxCount): Thread(), fifo(fifo), n(maxCount){}

void FifoProducer::run()
{
    while (counter<n)
    {
        cumulative += counter;
        fifo->push(counter);
        counter++;
    }
}

unsigned FifoProducer::getCount(){
    return counter;
}

unsigned FifoProducer::getCumulative(){
    return cumulative;
}


#endif

