# Technical test pedaling speed

## Context
In order to provide top-notch assistance, eBikeLabs needs to know the rider’s pedaling speed.

It is given by a [12 magnets PAS sensor](https://www.amazon.fr/Magnets-Electric-Bicycle-Sensor-Length/dp/B07XWCNH7K) mounted on the bracket housing, that sends a signal every time a magnet passes in front of the sensor.

Our algorithms require knowledge of the current pedaling speed, as well as the average pedaling speed over the last pedal revolution.

## Problem statement  
Please develop a C module (pedaling_mgt) providing 3 public functions:
- float get_pedaling_speed(void)
- float get_average_pedaling_speed(void)
- void gpio_interrupt(void)

You can assume that the following function is already implemented and your code may rely on it:
- uint32_t get_timestamp(void)