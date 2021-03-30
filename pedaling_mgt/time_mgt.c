#include "time_mgt.h"
#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <stdio.h>

#define NUMBER_SAMPLE_TIME 30

static uint32_t timestamp = 0;

static const uint32_t timestamp_array[NUMBER_SAMPLE_TIME] = {
    100000,
    189287,
    269932,
    349298,
    422824,
    486928,
    549428,
    616095,
    685539,
    759067,
    851661,
    970709,
    1137375,
    1315947,
    1482613,
    1643904,
    1800152,
    1943011,
    2068011,
    2184291,
    2297926,
    2406622,
    2513004,
    2617172,
    2719213,
    2819212,
    2915367,
    3009708,
    3102300,
    3202301};

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
