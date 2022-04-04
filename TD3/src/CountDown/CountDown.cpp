#include <iostream>
#include "CountDown.h"

CountDown::CountDown(int n){
    count = n;
}
	
void CountDown::callback(){
	--count;
    std::cout << "Count = "<< count << std::endl;
	if (count == 0)
		stop();
}


int CountDown::get_count(){
    return count;
}
