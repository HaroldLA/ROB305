#include <iostream>
#include <string>
#include "Chrono/Chrono.h"
#include "../../Time_Lib/include/Fonctions.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
    std::cout << "Insert value for 'chronoTime_ms'." << std::endl;
    return 0;
    }
    int chronoTime_ms = std::atoi(argv[1]);
    Chrono chrono;
    
    std::cout << "Chrono time : " << chrono.lap() << ", Active : " << chrono.isActive() <<std::endl;
    std::cout<<"Wait " << (double)chronoTime_ms/1000.0 <<" seconds \n"<<std::endl;
    timespec_wait(timespec_from_ms(chronoTime_ms));
    
    std::cout << "Chrono time : " << chrono.lap() << ", Active : " << chrono.isActive() <<std::endl;
    std::cout<<"Wait " << (double)chronoTime_ms/1000.0 <<" seconds to stop \n"<<std::endl;
    timespec_wait(timespec_from_ms(chronoTime_ms));
    
    chrono.stop();
    std::cout << "Chrono time : " << chrono.lap() << ", Active : " << chrono.isActive() <<std::endl;
    std::cout << "Stop time : " << chrono.stopTime() << ", Active : " << chrono.isActive()<< "\n"<<std::endl;

    chrono.restart();
    std::cout << "Restart time : " << chrono.startTime() << ", Active : " << chrono.isActive() <<std::endl;
    std::cout << "Stop time after resart : " << chrono.stopTime() << ", Active : " << chrono.isActive()<< "\n" <<std::endl;

    return 0;
}