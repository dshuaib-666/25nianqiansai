#include "DHT11.h"

 #define  RESET GPIO_PIN_RESET 
 #define  SET   GPIO_PIN_SET  
 
 DHT11 dht11;
 void DHT11_OUT(void);
 void DHT11_IN(void);
//	
//void GPIO_IN()//ԉԚˇߪ©ģʽìղձԦԚٟ֧ƽʱࠉӔޓ˕ˤɫхۅ
//{
//	
//	GPIO_InitTypeDef GPIO_InitStructure = {0};

//  /*Configure GPIO pin : PA0 */
//  GPIO_InitStructure.Pin = GPIO_PIN_0;
//  GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
//  GPIO_InitStructure.Pull = GPIO_PULLUP;
//  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
//}

//void GPIO_Out(GPIO_PinState PinState)
//{
//	GPIO_InitTypeDef GPIO_InitStructure = {0};

//  /*Configure GPIO pin : PA0 */
//   GPIO_InitStructure.Pin = GPIO_PIN_0;
//  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStructure.Pull = GPIO_PULLUP;
//  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,PinState);
//}

 
int8_t DHT11_GetByte()
{ uint8_t Byte=0x00;
	uint8_t i;
	int8_t timeout=100;
	for(i=0;i<8;i++)
	{		timeout=80;
			while(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==SET&&(timeout--)>0)
			{
				delay_us(1);
			}
	  	timeout=80;
			while(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==RESET&&(timeout--)>0)
			{
				delay_us(1);
			}
			
	  delay_us(55);
		if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==SET)
		{
			Byte|=(0x80>>i);
			
			}
		
	
	}
	return Byte;
	

}
 
 
 

uint8_t High_hum,Low_hum,High_warmth,Low_warmth,check;
void DHT11_Init(uint8_t *warmth,uint8_t *hum)
{
	
	int8_t timeout=100;
	DHT11_OUT();
  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,RESET);//ߪʼхۅ
	HAL_Delay(22);
	
	 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,SET);//ɃDHT11ޓڜ
	delay_us(30);
	DHT11_IN();
	
	
  	while(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==SET&&(timeout--)>0)
		{
			delay_us(1);
		}
   	timeout=100;
		while(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==RESET&&(timeout--)>0)
		{
			delay_us(1);
		}
		
	High_hum=DHT11_GetByte();
	Low_hum=DHT11_GetByte();
	High_warmth=DHT11_GetByte();
	Low_warmth=DHT11_GetByte();
	check=DHT11_GetByte();
	
	 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,SET);
	delay_us(60);
	
	if (High_hum + Low_hum + High_warmth + Low_warmth == check)
	{
		*hum  = High_hum;
		*warmth = High_warmth;
	}
	
	
}





 



void DHT11_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct = {0};
 
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}
 
void DHT11_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct = {0};
 
	GPIO_InitStruct.Pin  = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}
 
// 
//void DHT11_Strat(void)
//{
//	
//	DHT11_OUT();
//	DHT11_LOW;
//	HAL_Delay(20);
//	DHT11_HIGH;
//	Delay_us(30);
//}
// 
// 
//uint8_t DHT11_Check(void)
//{
//	uint8_t retry = 0 ;
//	DHT11_IN();
//		
//	while(DHT11_IO_IN && retry <100) 
//	{
//		retry++;
//		Delay_us(1);//1us
//	}
//	if(retry>=100) 
//	{return  1;}
//	 else retry =  0 ;
//		
//	while(!DHT11_IO_IN && retry<100)
//	{
//		retry++;
//		Delay_us(1);//1us
//	}
//		
//	if(retry>=100)
//	{return 1;}
//	return 0 ;
//}
// 
// 
//uint8_t DHT11_Read_Bit(void)
//{
//	uint8_t retry = 0 ;
//	while(DHT11_IO_IN && retry <100)
//	{
//		retry++;
//		Delay_us(1);
//	}
//		retry = 0 ;
//	while(!DHT11_IO_IN && retry<100)
//	{
//		retry++;
//		Delay_us(1);
//	}
//	Delay_us(40);
//	if(DHT11_IO_IN) return 1;
//	else 
//	return 0 ;
//}
// 
// 
//uint8_t DHT11_Read_Byte(void)
//{
//	uint8_t i , dat ;
//	dat = 0 ;
//	for(i=0; i<8; i++)
//	{
//		dat <<= 1;
//		dat |= DHT11_Read_Bit();
//	}
//	return dat ; 
//}
// 
// 
//uint8_t DHT11_Read_Data(uint8_t* temp , uint8_t* humi)
//{
//	uint8_t buf[5];
//	uint8_t i;
//	DHT11_Strat();
//    if(DHT11_Check() == 0)
//	{
//		for(i=0; i<5; i++)
//		{
//			buf[i] = DHT11_Read_Byte();
//		}
//		if(buf[0]+buf[1]+buf[2]+buf[3] == buf[4])
//		{
//			*humi = buf[0];
//			*temp = buf[2];
//		}
//	}else return 1;
//	
//   return 0 ;
//}
// 








