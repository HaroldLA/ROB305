#include<time.h>

/**
 * @brief Convertion from timespec to miliseconds 
 * 
 * @param time_ts 
 * @return double 
 */
double timespec_to_ms(const timespec& time_ts);

/**
 * @brief Convertion from miliseconds to timespec  
 * 
 * @param time_ms 
 * @return timespec 
 */
timespec timespec_from_ms(double time_ms);

/**
 * @brief Capture of the current real time
 * 
 * @return timespec 
 */
timespec timespec_now();

/**
 * @brief Negation of the input value
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec timespec_negate(const timespec& time_ts);

/**
 * @brief Addition of two timespec values
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Substraction of two timespec values
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Intoruction of a delay time in miliseconds
 * 
 * @param delay_ts 
 * @return timespec 
 */
timespec timespec_wait(const timespec& delay_ts);