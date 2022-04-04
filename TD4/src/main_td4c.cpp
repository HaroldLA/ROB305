#include<iostream>
#include<pthread.h>
#include<vector>

#include "../../TD3/src/Chrono/Chrono.h"
#include "SemaphoreProducer/SemaphoreProducer.h"
#include "SemaphoreConsumer/SemaphoreConsumer.h"


int main(int argc, char const *argv[])
{
    if(argc<4){
        std::cout<<"'nCons', 'nProd' and 'nTokens' parameters are needed. "<<std::endl;
        return 0;
    }

    unsigned nCons = std::stoi(argv[1]);
    unsigned nProds = std::stoi(argv[2]);
    unsigned nTokens = std::stoi(argv[3]);

    unsigned prodQuantity = 0;
    unsigned consQuantity = 0;
    double tProd_ms = 0;
    double tCons_ms = 0;

    Semaphore semaphore;
    Chrono chrono;
    
    std::vector<SemaphoreConsumer> consumerVect;
    std::vector<SemaphoreProducer> producerVect;
    
    unsigned i;

    for (i=0; i<nProds; i++)
        producerVect.push_back(SemaphoreProducer(&semaphore, nTokens));

    for (i=0; i<nCons-1; i++)
        consumerVect.push_back(SemaphoreConsumer(&semaphore, (int) nProds*nTokens/nCons));
    consumerVect.push_back(SemaphoreConsumer(&semaphore, (nProds*nTokens - (nCons-1)* ((int) nProds*nTokens/nCons))));
    
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
        std::cout << "Semaphore producer " << i << " gave "<<  producerVect[i].getCount() << " tokens in "<< producerVect[i].execTime_ms() << " ms." <<std::endl;
    }

    std::cout <<"\n"<<std::endl;
    for (i=0; i<nCons; i++)
    {
        consumerVect[i].join();
        consQuantity += consumerVect[i].getCount();
        tCons_ms += consumerVect[i].execTime_ms();  
        std::cout << "Semaphore consumer " << i << " took "<<  consumerVect[i].getCount() << " tokens in "<< consumerVect[i].execTime_ms() << " ms." << std::endl;
    }

    chrono.stop();

    std::cout <<"\n"<<std::endl;
    std::cout << "Total quantity of produced tokens : " << prodQuantity << std::endl;
    std::cout << "Total quantity of consumed tokens : " << consQuantity << std::endl;        
    std::cout << "Execution time cumulated by the producers : " << tProd_ms << " ms" << std::endl;
    std::cout << "Execution time cumulated by the consumers : " << tCons_ms << " ms" << std::endl;
    std::cout << "Total execution time : " << chrono.lap() << " ms" << std::endl;

    return 0;
}

