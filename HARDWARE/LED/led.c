#include "led.h"

void LED_init(void){
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOE_CLK_ENABLE();           	//开启GPIOE时钟
    GPIO_Initure.Pin=LED0_PIN; 				//PE5
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          	//上拉
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //高速
    HAL_GPIO_Init(LED0_GPIO_PORT,&GPIO_Initure);

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//开启GPIOB时钟
    GPIO_Initure.Pin=LED1_PIN; 				//PB5
    HAL_GPIO_Init(LED1_GPIO_PORT,&GPIO_Initure);
}

void LED_on(uint8_t led_num){
    if(led_num == 0){
        HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_PIN, GPIO_PIN_SET);
    }else if(led_num == 1){
        HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_PIN, GPIO_PIN_SET);
    }
}

void LED_off(uint8_t led_num){
    if(led_num == 0){
        HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_PIN, GPIO_PIN_RESET);
    }else if(led_num == 1){
        HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
    }
}
