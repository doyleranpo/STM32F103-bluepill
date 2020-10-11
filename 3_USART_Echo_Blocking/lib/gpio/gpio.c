/* GPIO Functions */

#include <libopencm3/stm32/gpio.h>

#include "gpio.h"

void gpio_setup(void)
{
    // GPIO LEDs
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}