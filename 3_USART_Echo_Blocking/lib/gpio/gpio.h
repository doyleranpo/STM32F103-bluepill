#ifndef _GPIO_H_
#define _GPIO_H_

/* Global variables */
#define STATUS_LED_PORT      GPIOC
#define STATUS_LED_PIN       GPIO13

/* Function definitions */
extern void gpio_setup(void);

#endif