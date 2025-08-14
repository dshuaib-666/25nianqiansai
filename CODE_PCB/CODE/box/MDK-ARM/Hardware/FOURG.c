#include "main.h"
#include "usart.h"
#include "stdarg.h"
#include <string.h>
#include <stdlib.h>
#include "all.h"
#define TX_BUF_LEN  256     /* ���ͻ�����������������Ҫ���е��� */
uint8_t TxBuf[TX_BUF_LEN];  /* ���ͻ�����                       */

FOUR four;


void FOURG_DATA_INIT(void)
{
			for(int k=0;k<10;k++)
			{   four.DATA_buffer[k]=0;
			}
			for(int k=0;k<99;k++)
			{
				four.RESEIVE[k]=0;
			
			}
			for(int i=0;i<=19;i++)
			{
			four.PHONE_BUFFER[i]=0;
			four.DOCTORPHONE_BUFFER[i]=0;
						
			}
			//four.Reload=0;
}
void FOURG_INIT(void)
{
     __HAL_UART_ENABLE_IT(&huart6, UART_IT_IDLE);  
	HAL_UART_Receive_DMA(&huart6,four.RESEIVE,100);
	   FOURG_DATA_INIT();
	
}

void MyPrintf(const char *__format, ...)
{
  va_list ap;
  va_start(ap, __format);
  
  /* ��շ��ͻ����� */
  memset(TxBuf, 0x0, TX_BUF_LEN);
  
  /* ��䷢�ͻ����� */
  vsnprintf((char*)TxBuf, TX_BUF_LEN, (const char *)__format, ap);
  va_end(ap);
  int len = strlen((const char*)TxBuf);
  
  /* �����ڷ������� */
  HAL_UART_Transmit(&huart6, (uint8_t*)&TxBuf, len, 0xFFFF);
}



//�����ϴ�ʹ��heart���������
//Ϊ1��ʱ�򣬽����ݶ��ϴ���������
//Ϊ2��ʱ�������·���
//Ϊ3��ʱ���������·����ϴ�
//Ϊ4��ʱ��ֻ�ϴ���ʪ��
//Ϊ5��ʱ��ֻ�ϴ���ʪ��+���ʣ��ֻ�����
//Ϊ6��ʱ��ֻ�ϴ�ҩƷ����
void FOURG_UP(int number)
{
	/*ʹ�����ݰ�!(hert)&( spo2)^ (bk)#(tired)@( systolic_pressure)/( diastolic_pressure)+
( heart_output)-( peripheral_resistance)=( rr_period) *( CH4(����))|( humidity(��ʪ��))?
!4564987979&666^777#888@999/11111+22222-333333=444444*101010|111111111111111~?
	*/
	//heart
	//MyPrintf("auint=s%d",as);           //11
	//smoke.data=612413241125;
	
	dht11.humi_Sent=(int)dht11.humi;
	dht11.temp_Sent=(int)dht11.temp;
	if(number==0)
	 {
		heart.rr_period=4;
		four.SERVER_UP=9; 
								
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio,(int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 if(number==1)
	 {
		four.SERVER_UP=10; 
							
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 else if(number==2)
	 {
		four.SERVER_UP=11; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	  else if(number==3)
	 {
		four.SERVER_UP=12; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	  else if(number==4)
	 {
		four.SERVER_UP=10; 
		 heart.rr_period=2;
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 else if(number==5)
	 {
		heart.rr_period=3; 
		four.SERVER_UP=10; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 else if(number==6)
	 {
		heart.rr_period=1;
		 
		four.SERVER_UP=10; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 
	 //֮���Ƕ��Ų���  
	 //14��ʾΪ��ͨ / ����
	 else if(number==10)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=14; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 
	 
	 //15��ʾΪ��ͨ / �м���
	 else if(number==11)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=15; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 
	 
	 //17��ʾΪ���� / ����
	 else if(number==12)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=17; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 
 
	 //18��ʾΪ���� / �м���
	 else if(number==13)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=18; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	  //֮��ȡҩ����
	  //
	 else if(number==20)
	 {
		heart.rr_period=5;//Ϊ5��ʾȡҩ
		 
		four.SERVER_UP=10;//����post�ϱ� 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //��ʪ�Ȼ�û��ģ����Բ࣬������λ��
	 }
	 
}
//���н����$Reload&+phone+^DOCTORphone%
void FOURG_RECEVIE_unpack(void)
{
	  for(int i=0;i<100;i++)
	{
		 if(four.RESEIVE[i]=='$')
		 {
			  four.heart_location= i;
			  break;
		 
		 }
		 if(i>=98)  //�������������ز���û�м�⵽��ͷ��˵�����ݰ������ˣ�Ҫ�ں�������Ļ�Ͻ��б���
		 {
			 break;
		 }
	
	}
	
	for(int i=four.heart_location;i<99;i++)//�Ӱ�ͷ��ʼ����
	{
		 
		if(four.RESEIVE[i]=='&'){
			 four.tail_location=i;
			 //���㵽�˳���
			 four.data_length=four.tail_location-four.heart_location;
			 for(int i=0;i<(four.data_length-1);i++)
			{
			   four.DATA_buffer[i]=four.RESEIVE[four.heart_location+i+1];
			}
			four.Reload=atoi(four.DATA_buffer) ;
			      
		}
		else if(four.RESEIVE[i]=='^') //�ҵ���
		{
			four.PHONE_location=i-1;
			four.PHONE_length=four.PHONE_location-four.tail_location;
		   for(int i=0;i<(four.PHONE_length);i++)
			{
			   four.PHONE_BUFFER[i]=four.RESEIVE[four.tail_location+i+1];
			}
			 for(int k=0;k<=19;k++)
			{
			four.PHONE[k]=four.PHONE_BUFFER[k];
			}
		}
		else if(four.RESEIVE[i]=='%') //�ҵ���
		{
			four.DOCTORPHONE_location=i-1;
			four.DOCTORPHONE_length=four.DOCTORPHONE_location-four.PHONE_location-1;
		   for(int i=0;i<(four.DOCTORPHONE_length);i++)
			{
			   four.DOCTORPHONE_BUFFER[i]=four.RESEIVE[four.PHONE_location+i+2];
				
			}
			  for(int k=0;k<=19;k++)
			{
			four.DOCTORPHONE[k]=four.DOCTORPHONE_BUFFER[k];
			}
			 for(int k=0;k<(four.DOCTORPHONE_length);k++)
			{
			  four.DATA_DOCTORPHONE[k]=four.DOCTORPHONE[k]-'0';    
				
			}
			for(int k=0;k<(four.PHONE_length);k++)
			{
			  four.DATA_PHONE[k]=four.PHONE[k]-'0';
			}
		
			
			
			
			
			  
				FOURG_DATA_INIT();
			 break;  
		}
		
		
		
		
	}

}
//�ϴ������մ��룬
void UPLOAD_DATA(void)
{
	HEART_NRF2401_RECEIVE();
   if(nrf2401.staus==1)  //��������ڼ�ⴥ�����ϵ��Ƿ��ϴ�
   {
	  FOURG_UP(1);
   }
	  
	
	
	
}

void DOWN_COUNTER_ZIWEIXIAN(void)
{
//	if(four.Reload==31)
//	{
//	     ZIWAIXIAN_ON();
//	
//	}
//	else if(four.Reload==30)
//	{
//		ZIWAIXIAN_OFF();
//	
//	}



}
void FOUR_COMMON(void)
{
	//DOWN_COUNTER_ZIWEIXIAN();
	//UPLOAD_DATA();
}
