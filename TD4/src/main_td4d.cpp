#include<iostream>
#include<pthread.h>
#include<vector>

#include "../../TD3/src/Chrono/Chrono.h"
#include "FifoProducer/FifoProducer.hpp"
#include "FifoConsumer/FifoConsumer.hpp"

int main(int argc, char const *argv[])
{
    if(argc<4){
            std::cout<<"'nCons', 'nProd' and 'countLimit' parameters are needed. "<<std::endl;
            return 0;
        }

    unsigned nCons = std::stoi(argv[1]);
    unsigned nProds = std::stoi(argv[2]);
    unsigned countLimit = std::stoi(argv[3]);

    unsigned prodQuantity = 0;
    unsigned consQuantity = 0;
    unsigned prodTotalSum = 0;
    unsigned consTotalSum = 0;

    double tProd_ms = 0;
    double tCons_ms = 0;

    Fifo<int> fifo;
    Chrono chrono;

    std::vector<FifoConsumer> consumerVect;
    std::vector<FifoProducer> producerVect;

    unsigned i = 0;

    for (i=0; i<nProds; i++)
        producerVect.push_back(FifoProducer(&fifo, countLimit));

    for (i=0; i<nCons-1; i++)
        consumerVect.push_back(FifoConsumer(&fifo, (int) nProds*countLimit/nCons));
    consumerVect.push_back(FifoConsumer(&fifo, (nProds*countLimit - (nCons-1)* ((int) nProds*countLimit/nCons))));
    
    for (i=0; i<nProds; i++)
        producerVect[i].start();

    for (i=0; i<nCons; i++)
        consumerVect[i].start();

    std::cout <<"\n"<<std::endl;
    for (i=0; i<nProds; i++)
    {
        producerVect[i].join();
        prodQuantity += producerVect[i].getCount();
        tProd_ms += producerVect[i].execTime_ms();
        prodTotalSum += producerVect[i].getCumulative();
        std::cout << "Fifo producer " << i << " pushed "<<  producerVect[i].getCount() << " tokens in "<< 
        producerVect[i].execTime_ms() << "ms / Sum = "<< producerVect[i].getCumulative()<<std::endl;
    }

    std::cout <<"\n"<<std::endl;
    for (i=0; i<nCons; i++)
    {
        consumerVect[i].join();
        consQuantity += consumerVect[i].getCount();
        tCons_ms += consumerVect[i].execTime_ms(); 
        consTotalSum += consumerVect[i].getCumulative(); 
        std::cout << "Fifo consumer " << i << " poped "<<  consumerVect[i].getCount() << " tokens in "<< 
        consumerVect[i].execTime_ms() << "ms / Sum = "<< consumerVect[i].getCumulative()<<std::endl;
    }

    chrono.stop();

    std::cout <<"\n"<<std::endl;
    std::cout << "Total quantity of produced tokens : " << prodQuantity << std::endl;
    std::cout << "Total quantity of consumed tokens : " << consQuantity << std::endl; 
    std::cout << "Producer cumulated sum : " << prodTotalSum << std::endl;
    std::cout << "Consumer cumulated sum: " << consTotalSum <<"\n"<<std::endl;    

    std::cout << "Execution time cumulated by the producers : " << tProd_ms << " ms" << std::endl;
    std::cout << "Execution time cumulated by the consumers : " << tCons_ms << " ms" << std::endl;
    std::cout << "Total execution time : " << chrono.lap() << " ms" << std::endl;

    return 0;
}
