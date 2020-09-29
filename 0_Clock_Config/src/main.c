#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void clock_config(void)
{
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

int main(void)
{
    clock_config();
    while(1) 
    {
        for(int i = 0; i < 8000000; i++)
            __asm__("nop");
    }
    return 0;
}