#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pedaling_mgt.h"
#include "time_mgt.h"

#define NUMBER_OF_INTERRUPTION 10

int main(void)
{
    for (uint8_t i = 0; i < NUMBER_OF_INTERRUPTION; i++)
    {
        update_timestamp();

        // Call handler interrupt
        gpio_interrupt();

        /* USER CODE BEGIN */

        /* USER CODE END */

        printf("Interrupt number: %d\n", i);
        printf("Pedaling speed: %2.1f\n", get_pedaling_speed());
        printf("Average pedaling speed: %2.1f\n\n", get_average_pedaling_speed());
    }

    return 0;
}