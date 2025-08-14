#ifndef __DHT11_H__
#define __DHT11_H__
#include "all.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdarg.h"
#include "Delay.h"
#include "gpio.h"


typedef struct
{
uint8_t temp_Sent;
uint8_t humi_Sent;
uint8_t temp;
uint8_t humi;


}DHT11;

extern DHT11 dht11;
void DHT11_Init(uint8_t *warmth,uint8_t *hum);
void DHT11_OUT(void);
extern uint8_t High_hum,Low_hum,High_warmth,Low_warmth,check;




#endif


