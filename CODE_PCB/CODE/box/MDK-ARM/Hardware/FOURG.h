#ifndef __FOURG_H
#define __FOURG_H

#include "stdint.h"
void FOURG_UP(int number);

 typedef struct FOUR//NRF2401�ӿ�
{
   uint8_t SNET_buffer[40]; //���ͻ�����
   uint8_t RESEIVE[100];//���ջ�����
   uint8_t heart_location;//��ͷ$��λ��
   uint8_t tail_location;//��β&��λ��
   uint8_t data_length;  //�����ߵ��ܳ���
   uint8_t PHONE_location;
   
   uint8_t DOCTORPHONE_location;
   
   char DATA_buffer[10]; //���ڽ��ղ���ת���Ļ�����
	 //������
   char PHONE_BUFFER[20];
   char DOCTORPHONE_BUFFER[20];
	 
	
	//��Ļʹ�����
	uint8_t PHONE[20]; 
	uint8_t DOCTORPHONE[20];
	uint8_t DATA_PHONE[20];
	uint8_t DATA_DOCTORPHONE[20];
	
	uint8_t PHONE_length;//��ϵ�˵ĳ���
	uint8_t DOCTORPHONE_length;//������ϵ�˵ĳ���
	
   int Reload;       //���ڴ���·�������
	
	
   uint8_t SERVER_UP;//Ϊ10ʱ��һֱ�ϴ���Ϊ11ʱ��һֱ�´���Ϊ12ʱ�����ϴ����´�
	
   int time_delay;//������5ms���ж��У������200�α�ʾ1sִ��һ��
	
	
}FOUR;
extern FOUR four;
 void FOURG_INIT(void);
void FOURG_RECEVIE_unpack(void);
 void UPLOAD_DATA(void);
 void FOUR_COMMON(void);


#endif
