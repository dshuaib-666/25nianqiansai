#ifndef __FOURG_H
#define __FOURG_H

#include "stdint.h"
void FOURG_UP(int number);

 typedef struct FOUR//NRF2401接口
{
   uint8_t SNET_buffer[40]; //发送缓冲区
   uint8_t RESEIVE[100];//接收缓冲区
   uint8_t heart_location;//包头$的位置
   uint8_t tail_location;//包尾&的位置
   uint8_t data_length;  //紫外线的总长度
   uint8_t PHONE_location;
   
   uint8_t DOCTORPHONE_location;
   
   char DATA_buffer[10]; //用于接收并且转化的缓冲区
	 //缓冲区
   char PHONE_BUFFER[20];
   char DOCTORPHONE_BUFFER[20];
	 
	
	//屏幕使用这个
	uint8_t PHONE[20]; 
	uint8_t DOCTORPHONE[20];
	uint8_t DATA_PHONE[20];
	uint8_t DATA_DOCTORPHONE[20];
	
	uint8_t PHONE_length;//联系人的长度
	uint8_t DOCTORPHONE_length;//紧急联系人的长度
	
   int Reload;       //用于存放下发的数据
	
	
   uint8_t SERVER_UP;//为10时，一直上传，为11时候，一直下传，为12时候，又上传又下传
	
   int time_delay;//用于在5ms的中断中，计算出200次表示1s执行一次
	
	
}FOUR;
extern FOUR four;
 void FOURG_INIT(void);
void FOURG_RECEVIE_unpack(void);
 void UPLOAD_DATA(void);
 void FOUR_COMMON(void);


#endif
