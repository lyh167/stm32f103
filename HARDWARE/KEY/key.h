#ifndef __KEY_H
#define __KEY_H

#include "sys.h"

#define KEY0_PIN GPIO_PIN_4
#define KEY0_GPIO_PORT GPIOE

#define KEY1_PIN GPIO_PIN_3
#define KEY1_GPIO_PORT GPIOE

#define WK_UP_PIN GPIO_PIN_0
#define WK_UP_GPIO_PORT GPIOA

#define KEY0_PRES 	1
#define KEY1_PRES   2
#define WKUP_PRES   3

#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_PORT, KEY0_PIN)
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_PIN)
#define WK_UP HAL_GPIO_ReadPin(WK_UP_GPIO_PORT, WK_UP_PIN)

void KEY_init(void);
uint8_t KEY_scan(uint8_t mode);

#endif
