#ifndef __openmv_h
#define __openmv_h
#include "stdint.h"

typedef struct OPENMV//openmv������
{
   uint8_t openmv_buffer[100];//���ջ�����
   uint8_t openmv_location;//֡ͷλ��,֡ͷ0xff����87λ������Ҫ������	
	 uint16_t Rx_len;
	 uint8_t heart_location;//��ͷ'$'��λ��
	 int32_t TAIL_code;//�洢�߰�λ
	 int32_t LOW_code;//���ڴ洢�Ͱ�λ
	 uint8_t staus;//״̬��
	
	char TAIL_buffer[10]; //���ڽ��ղ���ת���Ļ�����	
	char LOW_buffer[10]; //���ڽ��ղ���ת���Ļ�����	
	
	
     uint8_t tail_location;//��β0x22��λ��
     uint8_t data_length;  //���ݵ��ܳ���
	 int Reload;       //���ڴ���·�������
		
	 
	 uint8_t  Drug_code;//ѡ���ҩ��ı��� 
	
	
	 char DATA_buffer[10]; //���ڽ��ղ���ת���Ļ�����
}OPENMV;

extern OPENMV openmv;



void openmv_init(void);
void OPENMV_RECEVIE_unpack(void);
void OPENMV_DATA_INIT(void);
void Send_Hex_Data(uint8_t *hex_data, uint16_t len);
void Data_send_openmv(void);
#endif

