#ifndef _MAIN_H_
#define _MAIN_H_

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include <rcc.h>
#include <gpio.h>

extern void system_init(void);

#endif