#include "all.h"
#include <string.h>
#include <stdlib.h>
OPENMV openmv;

uint8_t data_start[] = {0x12, 0x01,0x23};//��ʼʶ��
uint8_t data_end[] = {0x12, 0x00,0x23};//ʶ�����


void OPENMV_DATA_INIT(void)
{
			for(int k=0;k<10;k++)
			{   openmv.DATA_buffer[k]=0;
			}
			for(int k=0;k<99;k++)
			{
				openmv.openmv_buffer[k]=0;
			
			}
			
}

//void openmv_init()
//{

//   __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);  
//	 HAL_UART_Receive_DMA(&huart1,openmv.openmv_buffer,100);
//	 OPENMV_DATA_INIT();

//}

void openmv_init()
{

   __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);  
	 HAL_UART_Receive_DMA(&huart1,openmv.openmv_buffer,100);
	 OPENMV_DATA_INIT();

}




//���н����0x11 + DATA + 0x22
void OPENMV_RECEVIE_unpack(void)
{
	  for(int i=0;i<100;i++)
	{
		 if(openmv.openmv_buffer[i]=='$')
		 {
			  openmv.heart_location= i;
			  break;
		 
		 }
		 if(i>=98)  //�������������ز���û�м�⵽��ͷ��˵�����ݰ������ˣ�Ҫ�ں�������Ļ�Ͻ��б���
		 {
			 break;
		 }
	
	}
	
	for(int i=openmv.heart_location;i<99;i++)//�Ӱ�ͷ��ʼ����
	{
		 
		if(openmv.openmv_buffer[i]=='&'&&openmv.openmv_buffer[i-9]=='$')
			{//˵���ҵ��˰�β
			for(int k=0;k<8;k++)
			{
				openmv.LOW_buffer[k]=openmv.openmv_buffer[i-8+k];}
			openmv.LOW_code=atoi(openmv.LOW_buffer);
				
			}
			
		if(openmv.openmv_buffer[i]=='^'&&openmv.openmv_buffer[i-9]=='&')
		{for(int k=0;k<8;k++)
			{
				openmv.TAIL_buffer[k]=openmv.openmv_buffer[i-8+k];}
			openmv.TAIL_code=atoi(openmv.TAIL_buffer);
			
		}
		if(openmv.openmv_buffer[i]=='@'&&openmv.openmv_buffer[i-2]=='^')
		{
			openmv.staus=openmv.openmv_buffer[i-1];
			medicine_reconfig_state=2;
		}			
		
	}

}

void Send_Hex_Data(uint8_t *hex_data, uint16_t len) {
    HAL_UART_Transmit(&huart1, hex_data, len, 0xFFFF); // ?????????
}



void Data_send_openmv(void)
{
		int i = 0;
		if(medicine_reconfig_state==1)//ʶ��ҩ��
		{
			
			lvgl_medicine_reconfig_state=1;
			update_aa_label() ;
				for(i=0;i<5;i++)
			{
				Send_Hex_Data(data_start,sizeof(data_start));
				HAL_Delay(5);
			}
			i=0;
				medicine_reconfig_state=0;
		}
		else if(medicine_reconfig_state==2)//��ʶ��ҩ��
		{
			
			lvgl_medicine_reconfig_state=2;
			update_aa_label() ;
			 for(i=0;i<5;i++)
			{
				Send_Hex_Data(data_end,sizeof(data_end));
				HAL_Delay(5);
			}
				medicine_reconfig_state=0;
		}
		
}


