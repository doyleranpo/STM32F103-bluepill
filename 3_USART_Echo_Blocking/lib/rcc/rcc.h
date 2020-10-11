#ifndef _RCC_H_
#define _RCC_H_

/* Global variables */
extern volatile uint32_t us_ticks;
extern volatile uint8_t secflag;

/* Function definitions */
extern void rcc_setup(void);
extern void systick_setup(void);
extern void delay_us(uint32_t dly_ticks);
extern void delay_ms(uint32_t ms_count);

#endif