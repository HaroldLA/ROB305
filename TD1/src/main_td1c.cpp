/**
 * @file main_td1c.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief  Implementation code of the function 'incr(unsigned nLoops, double* pCounter)'
 * @version 0.1
 * @date 2022-03-26
 *  
 */

#include <iostream>
#include <string>
#include <time.h>
#include "../../Time_Lib/include/Fonctions.h"
#include "../../Time_Lib/include/Operateurs.h"

/**
 * @brief This function performs a loop incrementing by 1.0 the value 
 * of the counter pointed to by pCounter it performs this loop nLoops times.
 * 
 * @param nLoops 
 * @param pCounter 
 */
void incr(unsigned nLoops, double* pCounter)
{
    for(unsigned i=0; i<nLoops; i++) *(pCounter) += 1.0;    
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout<< "Introduce 'nLoops'" <<std::endl;
        return 0;
    } 

    unsigned nLoops = std::stoi(argv[1]);
    double counter = 0.0;

    timespec start = timespec_now();        // Measure of the real initial time from the 'fonctions.h' library
    incr(nLoops,&counter);                  // Calling the incr() function
    timespec end = timespec_now();          // Measure of the real final time from the 'fonctions.h' library
    
    std::cout<<"Count : "<<counter << "/ Time : "<< timespec_to_ms(end-start)/1000.0 <<"s"<<std::endl;

    return 0;
}