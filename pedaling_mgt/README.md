# Technical test pedaling speed

## Context
In order to provide top-notch assistance, eBikeLabs needs to know the rider’s pedaling speed.

It is given by a [12 magnets PAS sensor](https://www.amazon.fr/Magnets-Electric-Bicycle-Sensor-Length/dp/B07XWCNH7K) mounted on the bracket housing, that sends a signal every time a magnet passes in front of the sensor.

Our algorithms require knowledge of the current pedaling speed, as well as the average pedaling speed over the last pedal revolution.

## Problem statement  
Please implement the 3 public functions of the C module `pedaling_mgt`, as described in the header `pedaling_mgt.h`.

Your code may rely on the public function `uint32_t get_timestamp(void)` provided by the C module `time_mgt`.