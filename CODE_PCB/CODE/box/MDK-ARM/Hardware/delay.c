#include "delay.h"
#include "gpio.h" 

uint32_t fac_us;

void HAL_Delay_us_init(uint8_t SYSCLK)//???????????????,???????168MHZ,???169??
{
     fac_us=SYSCLK; 
}

void delay_us(uint32_t nus)
{
    uint32_t ticks;
    uint32_t told,tnow,tcnt=0;
    uint32_t reload=SysTick->LOAD;
    ticks=nus*fac_us; 
    told=SysTick->VAL; 
    while(1)
    {
        tnow=SysTick->VAL;
        if(tnow!=told)
        {
            if(tnow<told)tcnt+=told-tnow;
            else tcnt+=reload-tnow+told;
            told=tnow;
            if(tcnt>=ticks)break; 
        }
    };
}


void delay_ms(uint32_t nms)
{
	uint32_t repeat=nms/540;
	uint32_t remain=nms%540;
	while(repeat)
	{
		delay_us(540*1000); // ?? 540 ms
		repeat--;
	}
	if(remain)
	{
		delay_us(remain*1000); // ??remain ms
	}
}

	    								   


































