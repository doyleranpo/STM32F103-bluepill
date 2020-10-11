/* Reset and Clock Control Related Functions */

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>

#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/rcc.h>

#include "rcc.h"

// 1us ticks
volatile uint32_t us_ticks = 0;
// second flag
volatile uint32_t micros = 0;
volatile uint8_t secflag;

void systick_setup(void)
{
    systick_set_frequency(1000000, 72e6);

    systick_interrupt_enable();

    systick_counter_enable();

}

void sys_tick_handler(void)
{
    // increment counter needed for delay()
    us_ticks++;
    micros++;

    if (micros >= 1000000) {
        secflag = 1;
        micros = 0;
    }
}

/* microsecond delay */
void delay_us(uint32_t dly_ticks)
{
      uint32_t cur_ticks;
 
      cur_ticks = us_ticks;
      while ((us_ticks - cur_ticks) < dly_ticks) ;
}

/* millisecond delay */
void delay_ms(uint32_t ms_count)
{
    uint32_t i;
    for (i = 0; i < ms_count; i++) {
        delay_us(1000);
    }
}

void rcc_setup(void)
{
    rcc_clock_setup_in_hse_8mhz_out_72mhz();

    // For status LED
    rcc_periph_clock_enable(RCC_GPIOC);

    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_USART1);
}