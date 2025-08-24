#include "key.h"
#include "delay.h"

void KEY_init(void){
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOE_CLK_ENABLE();           	    //开启GPIOE时钟
    __HAL_RCC_GPIOA_CLK_ENABLE();           	    //开启GPIOA时钟
    GPIO_Initure.Pin=KEY0_PIN; 				        //PE4
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      	    //输入模式
    GPIO_Initure.Pull=GPIO_PULLUP;          	    //上拉
    HAL_GPIO_Init(KEY0_GPIO_PORT,&GPIO_Initure);

    GPIO_Initure.Pin=KEY1_PIN; 				        //PE3
    HAL_GPIO_Init(KEY1_GPIO_PORT,&GPIO_Initure);

    GPIO_Initure.Pin=WK_UP_PIN;				        //PA0
    GPIO_Initure.Pull=GPIO_PULLDOWN;
    HAL_GPIO_Init(WK_UP_GPIO_PORT,&GPIO_Initure);
}


u8 KEY_scan(u8 mode){
    static u8 key_up = 1;
    if(mode==1)key_up=1;
    if(key_up&&(KEY0==0||KEY1==0||WK_UP==1)){
        delay_ms(10);
        key_up=0;
        if(KEY0==0)         return KEY0_PRES;
        else if(KEY1==0)    return KEY1_PRES;
        else if(WK_UP==1)   return WKUP_PRES;
    }else if(KEY0==1&&KEY1==1&&WK_UP==0) key_up=1;
    return 0;
}

