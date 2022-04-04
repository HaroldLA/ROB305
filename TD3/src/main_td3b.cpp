#include <iostream>
#include <string>
#include "CountDown/CountDown.h"
#include "../../Time_Lib/include/Fonctions.h"


int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
    std::cout << "Insert value for 'nLoops'." << std::endl;
    return 0;
    }

    int nLoops = std::atoi(argv[1]);
    CountDown counter(nLoops);
    counter.start(1000);
    while(counter.get_count() != 0){};    
    return 0;
}
