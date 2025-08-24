#include "sys.h"
#include "main.h"
#include "delay.h"
#include "usart.h"
#include "beep.h" 
#include "led.h"
#include "key.h"
/************************************************
 ALIENTEK 精英板STM32F103开发板实验0-1
 Template工程模板-新建工程章节使用-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


/***注意：本工程和教程中的新建工程3.3小节对应***/


void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
	u8 key;
    HAL_Init();                    	 			//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//设置时钟,72M
#if BEEP_TEST
	BEEP_init();
	while(1){
		BEEP=1;
		Delay(0x7FFFFF);
		BEEP=0;
		Delay(0x7FFFFF);
	}
#endif
#if LED_TEST	
	LED_init();
	while(1){
		LED0=1;
		LED1=0;
		Delay(0x7FFFFF);
		LED0=0;
		LED1=1;
		Delay(0x7FFFFF);
	}
#endif
#if KEY_TEST
	LED_init();
	BEEP_init();
	KEY_init();
	while(1){
		key=KEY_scan(0);
		if(key){
			switch(key){
				case KEY0_PRES:
					LED0=!LED0;
					break;
				case KEY1_PRES:
					LED1=!LED1;
					break;
				case WKUP_PRES:
					BEEP=!BEEP;
					break;
				default:
					break;
			}
		}
	}
#endif
	
}
