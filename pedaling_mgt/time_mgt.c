#include "time_mgt.h"
#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <stdio.h>

#define NUMBER_SAMPLE_TIME 30

static uint32_t timestamp = 0;

static const uint32_t timestamp_array[NUMBER_SAMPLE_TIME] = {
    100000,
    89286,
    80645,
    79365,
    73529,
    64103,
    62500,
    66667,
    69444,
    73529,
    92593,
    119048,
    166667,
    178571,
    166667,
    161290,
    156250,
    142857,
    125000,
    116279,
    113636,
    108696,
    106383,
    104167,
    102041,
    100000,
    96154,
    94340,
    92593,
    100000};

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
