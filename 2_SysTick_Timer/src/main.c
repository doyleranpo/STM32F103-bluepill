#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>

#include "main.h"

#define GREEN_LED_PORT GPIOC
#define GREEN_LED_PIN GPIO13

volatile uint32_t us_ticks = 0;

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOC);

    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

}

void systick_setup(void)
{
    systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);

    systick_set_frequency(1000000, 72e6);

    systick_interrupt_enable();

    systick_counter_enable();

}

void sys_tick_handler(void)
{
    us_ticks++;
}

void delay_us(uint32_t dly_ticks)
{
    uint32_t cur_ticks;

    cur_ticks = us_ticks;
    while ((us_ticks - cur_ticks) < dly_ticks);
}

void delay_ms(uint32_t ms_count)
{
    uint32_t i;
    for (i = 0; i < ms_count; i++)
        delay_us(1000);

}

int main(void)
{
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    systick_setup();
    gpio_setup();

    while (1)
    {
        gpio_toggle(GREEN_LED_PORT, GREEN_LED_PIN);
        delay_ms(1000);
    }

    return 0;
    
}