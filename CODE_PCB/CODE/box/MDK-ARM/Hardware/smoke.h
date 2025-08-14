#ifndef __SMOKE_H__
#define __SMOKE_H__
 #include "stdint.h"

typedef struct SMOKE//烟雾传感器
{
   uint32_t adc_buffer[30];
   float data;
   float ratio;//百分比	
}SMOKE;
 void ADC_GET(void);


extern SMOKE smoke;
 void SMOKE_GET(void);





#endif
