#ifndef __heart_h
#define __heart_h
#include "stdint.h"
typedef struct HEART//��������
{
   uint8_t RX_buffer[100];//���ջ�����
   uint8_t heart_location;//֡ͷλ��,֡ͷ0xff����87λ������Ҫ������	
   uint8_t DISPORT_buffer[100];//������	,
   uint16_t Rx_len;
	
  
   int8_t acdata[64];  //���ʲ��ε�
   uint8_t heartrate; //����
   uint8_t spo2;      //Ѫ��
   uint8_t bk;        //΢ѭ��
   uint8_t rsv[8];
   uint8_t tired;     //ƣ��ָ��
   uint8_t systolic_pressure;//����ѹ
   uint8_t diastolic_pressure;//����ѹ
   uint8_t heart_output;//�����
   uint8_t peripheral_resistance;//��������	
   uint8_t rr_period;//rr����
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
