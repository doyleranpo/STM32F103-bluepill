/*
 * USART Echo: without interrupts
 * Blocks till it receives a character via serial
 */

#include "main.h"

void system_init(void)
{
    rcc_setup();
    systick_setup();
    gpio_setup();
}

int main(void)
{
    system_init();

    while (1) {
        // toggle status LED per second
        if (secflag) {
            gpio_toggle(STATUS_LED_PORT, STATUS_LED_PIN);
            secflag = 0;
        }
    }

    return 0;
}