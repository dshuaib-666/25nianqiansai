#include "main.h"
#include "all.h"
//���.c�ļ������ж�ͨ�Ų㣬���ֻ���ͨ���Լ����
//��������ڽ���ֻ����ݹ�����ֵ���������ݴ���ģ���4Gģ�����
//�����ʱ���Ǵ����˹�32λ��
//��������
void NRF2401_DISPOSE(void)
{    
   if(NRF24L01_RxPacket(nrf2401.SNET_buffer)==0)
    {
     
   }
	else{} //��������Զ
		

}
//���в��ϵ�����
void HEART_NRF2401_RECEIVE(void)
{
		 NRF2401_DISPOSE(); 
	
		if(nrf2401.SNET_buffer[20]==21)//��ʾ���ţ�real
		{ heart.heartrate=nrf2401.SNET_buffer[2];
		  heart.spo2=nrf2401.SNET_buffer[3];
		  heart.bk=nrf2401.SNET_buffer[4];
		  heart.tired=nrf2401.SNET_buffer[5];
		  heart.systolic_pressure=nrf2401.SNET_buffer[6]; 
		  heart.diastolic_pressure=nrf2401.SNET_buffer[7];
		  
		  heart.heart_output=nrf2401.SNET_buffer[8];
		  heart.peripheral_resistance=nrf2401.SNET_buffer[9];
	      nrf2401.staus =1;
		}
		else if(nrf2401.SNET_buffer[20]==20) //��ʾ�����ţ�
		{
		 /* heart.heartrate=0;
		  heart.spo2=0;
		  heart.bk=0;
		  heart.tired=0;
		  heart.systolic_pressure=0; 
		  heart.diastolic_pressure=0;
		  
		  heart.heart_output=0;
		  heart.peripheral_resistance=0;  */
			 heart.heartrate=nrf2401.SNET_buffer[2];
		  heart.spo2=nrf2401.SNET_buffer[3];
		  heart.bk=nrf2401.SNET_buffer[4];
		  heart.tired=nrf2401.SNET_buffer[5];
		  heart.systolic_pressure=nrf2401.SNET_buffer[6]; 
		  heart.diastolic_pressure=nrf2401.SNET_buffer[7];
		  
		  heart.heart_output=nrf2401.SNET_buffer[8];
		  heart.peripheral_resistance=nrf2401.SNET_buffer[9];
		  nrf2401.staus =2;
		}
		 
	
	
	
}

