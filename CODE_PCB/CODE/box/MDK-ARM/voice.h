#ifndef __voice_h
#define __voice_h

#include "stdint.h"
typedef struct VOICE//openmv的数据
{
   uint8_t voice_buffer[100];//接收缓冲区
   uint8_t voice_location;//帧头位置,帧头0xff往后87位都是想要的数据	
	 uint16_t Rx_len;
	 uint8_t heart_location;//包头0x11的位置
   uint8_t tail_location;//包尾0x22的位置
   uint8_t data_length;  //数据的总长度
	 int Reload;       //用于存放下发的数据
	
	 char DATA_buffer[10]; //用于接收并且转化的缓冲区
	 uint8_t staus;
}VOICE;

extern VOICE voice;

void voice_init(void);
void VOICE_DATA_INIT(void);
void VOICE_RECEVIE_unpack(void);
void voice_prase(void);
void voice_order(void);
	

#endif


