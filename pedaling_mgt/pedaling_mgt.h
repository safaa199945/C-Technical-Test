#ifndef PEDALING_MGT_H
#define PEDALING_MGT_H

/**
 * @brief Return current pedaling speed in RPM
 */
float get_pedaling_speed(void);

/**
 * @brief Return average current pedaling speed in RPM
 */
float get_average_pedaling_speed(void);

/**
 * @brief Callback when a magnet passes in front of the pedaling sensor
 */
void new_magnet_cb(void);

#endif