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
    usart_setup();
}

int main(void)
{
    system_init();

    uint16_t rx;

    while (1) {
        // toggle status LED per second
        if (secflag) {
            gpio_toggle(STATUS_LED_PORT, STATUS_LED_PIN);
            secflag = 0;
        }

        do {
            // wait and accept a character
            rx = usart_recv_blocking(USART1);
            // print the same character back
            usart_send_blocking(USART1, rx);
        } while (rx != '\n');   // exit if we encouter a newline
    }

    return 0;
}