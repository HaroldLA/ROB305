/**
 * @file Fonctions.cpp
 * @author Harold Exinover LOZANO ARIAS (harlozar@gmail.com)
 * @brief Functions for simplified use of the timespec structure representing time measurement in the Posix API.
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<time.h>
#include"../include/Fonctions.h"

/**
 * @brief Convertion from timespec to miliseconds 
 * 
 * @param time_ts 
 * @return double 
 */
double timespec_to_ms(const timespec& time_ts){
    double time_ns = (double)time_ts.tv_nsec;
    double time_s = (double)time_ts.tv_sec;
    return time_s*1000. + time_ns/1000000.;
}


/**
 * @brief Convertion from miliseconds to timespec
 * 
 * @param time_ms 
 * @return timespec 
 */
timespec timespec_from_ms(double time_ms){
    timespec time_ts;
    time_ts.tv_sec = time_ms/1000;
    time_ts.tv_nsec = time_ms*1000000 - time_ts.tv_sec*1e9;
    return time_ts;
}

/**
 * @brief Capture of the current real time
 * 
 * @return timespec 
 */
timespec timespec_now(){
    timespec time_ts;
    clock_gettime(CLOCK_REALTIME, &time_ts);
    return time_ts;
}

/**
 * @brief Negation of the input value
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec timespec_negate(const timespec& time_ts){
    timespec time_neg;
    if(time_ts.tv_nsec == 0 ){
        time_neg.tv_sec = -(time_ts.tv_sec); 
    }else{
        time_neg.tv_sec = -(time_ts.tv_sec + 1); 
        time_neg.tv_nsec = 1e9 - time_ts.tv_nsec;
    }
    return time_neg;
}

/**
 * @brief Addition of two timespec values
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts){
    timespec time_add;
    time_add.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;
    time_add.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;

    if(time_add.tv_nsec >= 1e9){
        time_add.tv_sec += 1;
        time_add.tv_nsec -= 1e9; 
    }
    return time_add;
}

/**
 * @brief Substraction of two timespec values
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts){

    timespec time_sub;
    timespec time_1 = time1_ts;
    timespec time_2 = time2_ts;

    time_sub.tv_sec = time_1.tv_sec - time_2.tv_sec;

    if(time_2.tv_nsec > time_1.tv_nsec){
        time_sub.tv_sec -=1;
        time_1.tv_nsec += 1e9;
    }
    time_sub.tv_nsec = time_1.tv_nsec - time_2.tv_nsec;
    return time_sub;
}

/**
 * @brief Intoruction of a delay time in miliseconds
 * 
 * @param delay_ts 
 * @return timespec 
 */
timespec timespec_wait(const timespec& delay_ts){
    timespec time_wait; 
    nanosleep(&delay_ts,&time_wait);
    return time_wait;
}


