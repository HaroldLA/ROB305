#include<time.h>
#include"../include/Operateurs.h"
#include"../include/Fonctions.h"

/**
 * @brief Operator 'negate' definition for timespec
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time_ts){
    timespec time_neg = timespec_negate(time_ts);
    return time_neg;
}

/**
 * @brief Operator 'addition' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts){
    timespec time_plus = timespec_add(time1_ts,time2_ts);
    return time_plus;
}

/**
 * @brief Operator 'subtraction' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts){
    timespec time_minus = timespec_subtract(time1_ts,time2_ts);
    return time_minus;
}

/**
 * @brief Operator 'increment' definition for timespec
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator+= (timespec& time_ts, const timespec& delay_ts){
    timespec time_delay = timespec_wait(delay_ts);
    time_ts += time_delay;
    return time_ts;
}

/**
 * @brief Operator 'decrement' definition for timespec
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator-= (timespec& time_ts, const timespec& delay_ts){
    timespec time_delay = timespec_wait(delay_ts);
    time_ts -= time_delay;
    return time_ts;
}

/**
 * @brief Logic operator '==' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator== (const timespec& time1_ts, const timespec& time2_ts){
    double time_comp = timespec_to_ms(time1_ts) - timespec_to_ms(time2_ts);
    return time_comp == 0.0;
}

/**
 * @brief Logic operator '!=' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator!= (const timespec& time1_ts, const timespec& time2_ts){
    double time_comp = timespec_to_ms(time1_ts) - timespec_to_ms(time2_ts);
    return time_comp != 0.0;
}

/**
 * @brief Logic operator '<' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator< (const timespec& time1_ts, const timespec& time2_ts){
    double time_comp = timespec_to_ms(time1_ts) - timespec_to_ms(time2_ts);
    return time_comp < 0.0;
}

/**
 * @brief Logic operator '>' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator> (const timespec& time1_ts, const timespec& time2_ts){
    double time_comp = timespec_to_ms(time1_ts) - timespec_to_ms(time2_ts);
    return time_comp > 0.0;
}
