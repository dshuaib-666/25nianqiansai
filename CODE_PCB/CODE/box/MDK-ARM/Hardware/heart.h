#ifndef __heart_h
#define __heart_h
#include "stdint.h"
typedef struct HEART//体测的数据
{
   uint8_t RX_buffer[100];//接收缓冲区
   uint8_t heart_location;//帧头位置,帧头0xff往后87位都是想要的数据	
   uint8_t DISPORT_buffer[100];//处理区	,
   uint16_t Rx_len;
	
  
   int8_t acdata[64];  //心率波形点
   uint8_t heartrate; //心率
   uint8_t spo2;      //血氧
   uint8_t bk;        //微循环
   uint8_t rsv[8];
   uint8_t tired;     //疲劳指数
   uint8_t systolic_pressure;//收缩压
   uint8_t diastolic_pressure;//舒张压
   uint8_t heart_output;//心输出
   uint8_t peripheral_resistance;//外周阻力	
   uint8_t rr_period;//rr周期
   uint8_t sdnn;
   uint8_t rmssd;
   uint8_t nn50;
   uint8_t pnn50;
   uint8_t rra[6];
   uint8_t rsv2[2];
	
}HEART;

void HEART_INIT(void);
void HEART_START(void);
 void HEART_DATA_dispose(void);
extern  HEART heart;
 void HEART_DATA_INIT(void);

#endif
