#include "heart.h"
#include "usart.h"
#include "MYDELAY.h"
#include "all.h"
HEART heart;//�洢�������ݰ�ʲô��
//��������idle�����ж�


 void HEART_DATA_INIT(void)
 {
   heart.heartrate=0;
		  heart.spo2=0;
		  heart.bk=0;
		  heart.tired=0;
		  heart.systolic_pressure=0; 
		  heart.diastolic_pressure=0;
		  
		  heart.heart_output=0;
		  heart.peripheral_resistance=0;	
 }

void HEART_INIT(void)
{
     __HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);  
	HAL_UART_Receive_DMA(&huart2,heart.RX_buffer,100);
	
	
}
char gather_start[]={0X8A}; //��ʼ�ɼ�
char gather_stop[]={0X88}; //�رղɼ�

char physical_fitness_test_start[]={0X8E}; //��ʼ���
char physical_fitness_test_stop[]={0X8C};   //�ر����
void HEART_START(void)
{

	HAL_UART_Transmit_DMA(&huart2,(uint8_t *)gather_start,10);
	user_delaynus_tim(10);
//	HAL_UART_Transmit_DMA(&huart2,(uint8_t *)physical_fitness_test_start,10);
//	user_delaynus_tim(10);
}

void HEART_DATA_dispose(void)//�����ж��ڣ������ݰ����н���  ,ֻ���вɼ�ģʽ����������⣬�ɼ�ģʽÿ����88���ֽ�
{
	for(int i=0;i<88;i++)
	{
	   if(heart.RX_buffer[i]==0xFF)
	   {
		heart.heart_location=i+1;
		break;
		   }   
	}
   for(int i=heart.heart_location;i<88;i++)//��һλֱ�Ӿ������ʴ����
	{
	   heart.DISPORT_buffer[i-1]=heart.RX_buffer[i];//Ҳ���ǽ����ݰ���������
	}
	for(int i=0;i<100;i++)
	{
	   heart.RX_buffer[i]=0;
	
	}
	
	
	//�õ���һ�����ݽ��н��,��0λ 0-63�������ʿ�����  ,
	for(int i=0;i<64;i++)
	{
	  heart.acdata[i]=  heart.DISPORT_buffer[i];//�������ʴ����
	}
	  heart.heartrate= heart.DISPORT_buffer[64];
	  heart.spo2     = heart.DISPORT_buffer[65]; //Ѫ��
	  heart.bk       = heart.DISPORT_buffer[66]; //΢ѭ��
	for(int i=0;i<8;i++)  //�õ�rsv8�����ݰ���
	{
	  heart.rsv[i]   = heart.DISPORT_buffer[i+67];
	}
	  heart.tired    = heart.rsv[0];             //ƣ��ָ��
	  heart.systolic_pressure= heart.rsv[3];     //����ѹ
	  heart.diastolic_pressure= heart.rsv[4];    //����ѹ
	  heart.heart_output     = heart.rsv[5];     //�����
	  heart.peripheral_resistance= heart.rsv[6]; //��������
	  heart.rr_period = heart.rsv[7];             //rr����
	
	  
	
}   

