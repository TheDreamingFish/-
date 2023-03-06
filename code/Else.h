#ifndef _ELSE_H
#define _ELSE_H

#include "zf_common_headfile.h"
#include "Sys.h"

#define LED1                    (P20_9)
#define LED2                    (P20_8)
#define LED3                    (P21_5)
#define LED4                    (P21_4)

#define    EL_LED(LEDX,led_state)        gpio_set_level(LEDX, led_state);

void EL_LED_Init(void);

#endif
