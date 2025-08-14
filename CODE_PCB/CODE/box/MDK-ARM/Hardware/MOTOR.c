#include "main.h"
#include "usart.h"
#include "stdint.h"
#include "all.h"
 //������� ���� 01 F3 AB 01 00 6B
//01�ǵ���ķ��ţ�Ҫ�����ֻ��߿�����������Ͱѿ�ͷ��01�ĵ�
 uint8_t MOTOR_start[]={0x01,0xf3,0xab,0x01,0x00,0x6b};
 //uint8_t MOTOR_stop[]={0x01,0xfe,0x98,0x00,0x6b};
 // uint8_t MOTOR_location_init[]={0x01,0x93,0x88,0x01,0x6b};
 MOTOR motor;
 BOX box;
 void MOTOR_communication_init(void)
 {      __HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);
 	HAL_UART_Receive_DMA(&huart3,motor.REXEVICE,100);
 
 }
 
 void MOTOR_START(void)
 {
 
	 HAL_UART_Transmit_DMA(&huart3,MOTOR_start,6);
	  HAL_Delay(100); 
 }
 //���ֹͣ ����01 FE 98 00 6B
 uint8_t MOTOR_stop[]={0x01,0xfe,0x98,0x00,0x6b};
 void MOTOR_STOP(void)
 {
	 HAL_UART_Transmit_DMA(&huart3,MOTOR_stop,5);
	  HAL_Delay(100); 
 
 
 }
 //�����ת����
 uint8_t MOTOR_locked_rotor_stop[]={0x01,0x0e,0x52,0x6B};
 void MOTOR_locked_rotor(void)
 {
 
   HAL_UART_Transmit_DMA(&huart3,MOTOR_locked_rotor_stop,4);
	 HAL_Delay(100);  
 }
 //�ع����ģʽ���п���
  uint8_t MOTOR_location_parameter_Counter[]={0x01, 0x4C, 0xAE, 0x01, 0x00, 0x00, 0x00, 0x1E ,
	  0x00, 0x00, 0x27, 0x10, 0x01, 0x2C, 0x03, 0x20, 0x00, 0x3C, 0x01, 0x6B};
 void MOTOR_LOCATION_parameter_Counter(void)                           
 {
	HAL_Delay(100);
    HAL_UART_Transmit_DMA(&huart3,MOTOR_location_parameter_Counter,20);
	HAL_Delay(100);  
 
 }
 //���ȷ��������01 93 88 01 6B
 uint8_t MOTOR_location_init[]={0x01,0x93,0x88,0x01,0x6b};
 void MOTOR_LOCATION_Init(void)
 {
	 MOTOR_communication_init();
	 MOTOR_START();
	  HAL_UART_Transmit_DMA(&huart3,MOTOR_location_init,5);
	   HAL_Delay(100); 
 }
//�ع���� ����01 9A 00 00 6B
 uint8_t MOTOR_init[]={0x01,0x9a,0x00,0x00,0x6b}; 
void MOTOR_INIT(void)
{     
	  box.staus=0;
	  MOTOR_communication_init();   
	  MOTOR_LOCATION_parameter_Counter();
	 MOTOR_START();
	   HAL_Delay(200);
	 HAL_UART_Transmit_DMA(&huart3,MOTOR_init,5);
	 HAL_Delay(1000); 
}
void MOTOR_ZERO(void)
{
	// MOTOR_START();
	 HAL_UART_Transmit_DMA(&huart3,MOTOR_init,5);
	 HAL_Delay(1000); 
}
//����Ҫ��ת����״̬
//Ϊ1ʱ�ǻع���㣬Ĭ��״̬
//��Щʹ�õĶ��Ǿ���λ�õ�ת��     00 64 Ϊ100rpmת�٣������ٽ���                  0C80(3200)01����
uint8_t MOTOR_LOCATION_STAUE_ONE_100_ONE_circle[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0C,0x80,0x01,0x00,0x6B};//תһȦ����λ��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x01,0x0a,0x01,0x00,0x6B};//30��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_SIX_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x02,0x14,0x01,0x00,0x6B};//60��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_NINE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x03,0x1e,0x01,0x00,0x6B};//90��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENTWO_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x04,0x28,0x01,0x00,0x6B};//120��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENFIVE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x05,0x23,0x01,0x00,0x6B};//150��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENEIGHT_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x06,0x3C,0x01,0x00,0x6B};//180��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TWOTENONE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x07,0x46,0x01,0x00,0x6B};//210��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TWOTENFOUR_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x08,0x50,0x01,0x00,0x6B};//240��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TWOTENEVERN_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x09,0x5A,0x01,0x00,0x6B};//270��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREETENZERO_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0A,0x64,0x01,0x00,0x6B};//300��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREETENTHREE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0B,0x6E,0x01,0x00,0x6B};//330��
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREETENSIX_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0C,0x78,0x01,0x00,0x6B};//360��

uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENFIVE_degree_yong[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x04,0x25,0x01,0x00,0x6B};//��λ���õ�
void MOTOR_LOACTION_COUNTER(int num)
{    //MOTOR_START();  
	if(num==1)//ת30��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREE_degree,13);
		 HAL_Delay(100); 
	}
	if(num==2)//ת60��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_SIX_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==3)//ת90��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_NINE_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==4)//ת120��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TENTWO_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==5)//ת150��
	{    
	HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TENFIVE_degree,13);
		
		 HAL_Delay(100); 
	}
	  if(num==6)//ת180��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TENEIGHT_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==7)//ת210��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TWOTENONE_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==8)//ת240��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TWOTENFOUR_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==9)//ת270��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TWOTENEVERN_degree,13);
		 HAL_Delay(100); 
	}
	  if(num==10)//ת300��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREETENZERO_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==11)//ת330��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREETENTHREE_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==12)//ת360��
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREETENSIX_degree,13);
		 HAL_Delay(100); 
	}
	 HAL_Delay(1000); 
	MOTOR_STOP();
}

//���ڲ���λ�õ�
//����while��Ϊ��5s��ʱ
void MOTOR_TEST_LOCATION(void)
{       
		MOTOR_LOACTION_COUNTER(10);
	    HAL_Delay(5000);
		MOTOR_LOACTION_COUNTER(8);
	    HAL_Delay(5000); 
		MOTOR_LOACTION_COUNTER(6);
	    HAL_Delay(5000); 
	    MOTOR_LOACTION_COUNTER(4);
	    HAL_Delay(5000); 
	    MOTOR_LOACTION_COUNTER(2);
	    HAL_Delay(5000);
		MOTOR_LOACTION_COUNTER(12);
				HAL_Delay(5000); 	
}
//����ҩ���š�����0��ʱ��ΪĬ�Ϲرգ�
void medicine_box_counter(int number)
{    MOTOR_START();
	if(number==0)
	{
	   MOTOR_ZERO();
	   
	}
	if(number==1)
	{
	  MOTOR_LOACTION_COUNTER(2);
	  
	}
	if(number==2)
	{
	  MOTOR_LOACTION_COUNTER(4);
	  
	}
	if(number==3)
	{
	  MOTOR_LOACTION_COUNTER(6);
	  
	}
	if(number==4)
	{
	  MOTOR_LOACTION_COUNTER(8);
	  
	}
	if(number==5)
	{
	  MOTOR_LOACTION_COUNTER(10);
	  
	}
	
	HAL_Delay(5000);
	MOTOR_STOP();
	HAL_Delay(1000);
}

