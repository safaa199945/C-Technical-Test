#ifndef TIME_MGT_H
#define TIME_MGT_H

#include <stdint.h>

/**
 * @brief Update the current timestemps
 */
void update_timestamp(void);

/**
 * @brief Return the current timestamp in µs
 */
uint32_t get_timestamp(void);

#endif