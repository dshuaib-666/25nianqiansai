#ifndef __voice_h
#define __voice_h

#include "stdint.h"
typedef struct VOICE//openmv������
{
   uint8_t voice_buffer[100];//���ջ�����
   uint8_t voice_location;//֡ͷλ��,֡ͷ0xff����87λ������Ҫ������	
	 uint16_t Rx_len;
	 uint8_t heart_location;//��ͷ0x11��λ��
   uint8_t tail_location;//��β0x22��λ��
   uint8_t data_length;  //���ݵ��ܳ���
	 int Reload;       //���ڴ���·�������
	
	 char DATA_buffer[10]; //���ڽ��ղ���ת���Ļ�����
	 uint8_t staus;
}VOICE;

extern VOICE voice;

void voice_init(void);
void VOICE_DATA_INIT(void);
void VOICE_RECEVIE_unpack(void);
void voice_prase(void);
void voice_order(void);
	

#endif


