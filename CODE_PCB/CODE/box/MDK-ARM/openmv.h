#ifndef __openmv_h
#define __openmv_h
#include "stdint.h"

typedef struct OPENMV//openmv的数据
{
   uint8_t openmv_buffer[100];//接收缓冲区
   uint8_t openmv_location;//帧头位置,帧头0xff往后87位都是想要的数据	
	 uint16_t Rx_len;
	 uint8_t heart_location;//包头'$'的位置
	 int32_t TAIL_code;//存储高八位
	 int32_t LOW_code;//用于存储低八位
	 uint8_t staus;//状态码
	
	char TAIL_buffer[10]; //用于接收并且转化的缓冲区	
	char LOW_buffer[10]; //用于接收并且转化的缓冲区	
	
	
     uint8_t tail_location;//包尾0x22的位置
     uint8_t data_length;  //数据的总长度
	 int Reload;       //用于存放下发的数据
		
	 
	 uint8_t  Drug_code;//选择的药柜的编码 
	
	
	 char DATA_buffer[10]; //用于接收并且转化的缓冲区
}OPENMV;

extern OPENMV openmv;



void openmv_init(void);
void OPENMV_RECEVIE_unpack(void);
void OPENMV_DATA_INIT(void);
void Send_Hex_Data(uint8_t *hex_data, uint16_t len);
void Data_send_openmv(void);
#endif

