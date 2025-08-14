#ifndef __DELAY_H
#define __DELAY_H 			   

#include "stdint.h"
#define u8   uint8_t 
#define u16  uint16_t 
#define u32  uint32_t 


void HAL_Delay_us_init(uint8_t SYSCLK);

void delay_us(u32 nus);
void delay_ms(uint32_t nms);

#endif






























