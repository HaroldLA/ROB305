/**
 * @file main_td1a.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief Test of the functions from the 'Fonctions.h' library
 * @version 0.1
 * @date 2022-03-26
 * 
 */

#include<time.h> 
#include<iostream>
#include<signal.h>
#include "../../Time_Lib/include/Fonctions.h"
#include "../../Time_Lib/include/Operateurs.h"


int main(int argc, char **argv)
{

    const timespec time_act = timespec_now();
    double time_ms; 
    timespec time_ts; 

    if(argc < 2)
    {
        std::cout<< "Choose one mode (1, 2 or 3)" <<std::endl;
        return 0;
    }
    
    /**
     * @brief Selection of the different functions to be tested
     * 
     */

    switch (*argv[1])
    {
    case '1':
        time_ms = timespec_to_ms(time_act);
        std::cout<<"ms Time : "<<time_ms<<std::endl;
        time_ts = timespec_from_ms(time_ms);
        std::cout<<"Time : "<<time_ts.tv_sec<<","<<time_ts.tv_nsec<<std::endl;
        break;
    
    case '2':
        time_ts = -(time_act);
        std::cout<<"Time : "<<time_ts.tv_sec<<","<<time_ts.tv_nsec<<std::endl;
        break;

    case '3':
        timespec temp;
        time_ts = timespec_now();
        temp = time_ts;
        time_ts.tv_sec = 3;
        time_ts = timespec_wait(time_ts); 
        std::cout<<"Delay : "<<timespec_to_ms(timespec_now() - temp)/1000.0<<"s"<<std::endl;
        break;

    default:
        std::cout<<"Default"<<std::endl;
        break;
    }
    
    
    return 0;
}