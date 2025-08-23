#ifndef __LED_H
#define __LED_H

#include "sys.h"

#define LED0_PIN GPIO_PIN_5
#define LED0_GPIO_PORT GPIOE

#define LED1_PIN GPIO_PIN_5
#define LED1_GPIO_PORT GPIOB

#define LED0 PEout(5) //LED0
#define LED1 PBout(5) //LED1

void LED_init(void);
void LED_On(uint8_t led_num);
void LED_Off(uint8_t led_num);

#endif
