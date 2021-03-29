#include "time_mgt.h"
#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <stdio.h>

#define NUMBER_SAMPLE_TIME 13

static uint32_t timestamp = 0;

static const uint32_t timestamp_array[NUMBER_SAMPLE_TIME] = {
    100000,
    89285,
    80645,
    79365,
    73529,
    64102,
    62500,
    66666,
    69444,
    73529,
    92592,
    119047,
    166666};

void update_timestamp(void)
{
    static uint8_t index = 0;
    timestamp = timestamp_array[index];

    // Update index
    index++;
    if (index > NUMBER_SAMPLE_TIME)
    {
        index = 0;
    }
}

uint32_t get_timestamp(void)
{
    return timestamp;
}
