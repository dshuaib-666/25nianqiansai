#ifndef __SMOKE_H__
#define __SMOKE_H__
 #include "stdint.h"

typedef struct SMOKE//��������
{
   uint32_t adc_buffer[30];
   float data;
   float ratio;//�ٷֱ�	
}SMOKE;
 void ADC_GET(void);


extern SMOKE smoke;
 void SMOKE_GET(void);





#endif
