
/**
 * @brief Operator 'negate' definition for timespec
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time_ts);

/**
 * @brief Operator 'addition' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Operator 'subtraction' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Operator 'increment' definition for timespec
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

/**
 * @brief Operator 'decrement' definition for timespec
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

/**
 * @brief Logic operator '==' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator== (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Logic operator '!=' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Logic operator '<' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator< (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Logic operator '>' definition for timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator> (const timespec& time1_ts, const timespec& time2_ts);