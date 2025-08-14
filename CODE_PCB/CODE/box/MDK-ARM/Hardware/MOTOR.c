#include "main.h"
#include "usart.h"
#include "stdint.h"
#include "all.h"
 //电机启动 发送 01 F3 AB 01 00 6B
//01是电机的符号，要改名字或者控制其他电机就把开头的01改掉
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
 //电机停止 发送01 FE 98 00 6B
 uint8_t MOTOR_stop[]={0x01,0xfe,0x98,0x00,0x6b};
 void MOTOR_STOP(void)
 {
	 HAL_UART_Transmit_DMA(&huart3,MOTOR_stop,5);
	  HAL_Delay(100); 
 
 
 }
 //解除堵转保护
 uint8_t MOTOR_locked_rotor_stop[]={0x01,0x0e,0x52,0x6B};
 void MOTOR_locked_rotor(void)
 {
 
   HAL_UART_Transmit_DMA(&huart3,MOTOR_locked_rotor_stop,4);
	 HAL_Delay(100);  
 }
 //回归零点模式进行控制
  uint8_t MOTOR_location_parameter_Counter[]={0x01, 0x4C, 0xAE, 0x01, 0x00, 0x00, 0x00, 0x1E ,
	  0x00, 0x00, 0x27, 0x10, 0x01, 0x2C, 0x03, 0x20, 0x00, 0x3C, 0x01, 0x6B};
 void MOTOR_LOCATION_parameter_Counter(void)                           
 {
	HAL_Delay(100);
    HAL_UART_Transmit_DMA(&huart3,MOTOR_location_parameter_Counter,20);
	HAL_Delay(100);  
 
 }
 //零点确定，发送01 93 88 01 6B
 uint8_t MOTOR_location_init[]={0x01,0x93,0x88,0x01,0x6b};
 void MOTOR_LOCATION_Init(void)
 {
	 MOTOR_communication_init();
	 MOTOR_START();
	  HAL_UART_Transmit_DMA(&huart3,MOTOR_location_init,5);
	   HAL_Delay(100); 
 }
//回归零点 发送01 9A 00 00 6B
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
//输入要旋转到的状态
//为1时是回归零点，默认状态
//这些使用的都是绝对位置的转动     00 64 为100rpm转速，可以再降点                  0C80(3200)01绝对
uint8_t MOTOR_LOCATION_STAUE_ONE_100_ONE_circle[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0C,0x80,0x01,0x00,0x6B};//转一圈绝对位置
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x01,0x0a,0x01,0x00,0x6B};//30度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_SIX_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x02,0x14,0x01,0x00,0x6B};//60度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_NINE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x03,0x1e,0x01,0x00,0x6B};//90度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENTWO_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x04,0x28,0x01,0x00,0x6B};//120度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENFIVE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x05,0x23,0x01,0x00,0x6B};//150度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENEIGHT_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x06,0x3C,0x01,0x00,0x6B};//180度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TWOTENONE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x07,0x46,0x01,0x00,0x6B};//210度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TWOTENFOUR_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x08,0x50,0x01,0x00,0x6B};//240度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_TWOTENEVERN_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x09,0x5A,0x01,0x00,0x6B};//270度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREETENZERO_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0A,0x64,0x01,0x00,0x6B};//300度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREETENTHREE_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0B,0x6E,0x01,0x00,0x6B};//330度
uint8_t MOTOR_LOCATION_STAUE_ONE_100_THREETENSIX_degree[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0C,0x78,0x01,0x00,0x6B};//360度

uint8_t MOTOR_LOCATION_STAUE_ONE_100_TENFIVE_degree_yong[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x04,0x25,0x01,0x00,0x6B};//调位置用的
void MOTOR_LOACTION_COUNTER(int num)
{    //MOTOR_START();  
	if(num==1)//转30度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREE_degree,13);
		 HAL_Delay(100); 
	}
	if(num==2)//转60度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_SIX_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==3)//转90度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_NINE_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==4)//转120度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TENTWO_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==5)//转150度
	{    
	HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TENFIVE_degree,13);
		
		 HAL_Delay(100); 
	}
	  if(num==6)//转180度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TENEIGHT_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==7)//转210度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TWOTENONE_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==8)//转240度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TWOTENFOUR_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==9)//转270度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_TWOTENEVERN_degree,13);
		 HAL_Delay(100); 
	}
	  if(num==10)//转300度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREETENZERO_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==11)//转330度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREETENTHREE_degree,13);
		 HAL_Delay(100); 
	}
	 if(num==12)//转360度
	{
	    HAL_UART_Transmit_DMA(&huart3,MOTOR_LOCATION_STAUE_ONE_100_THREETENSIX_degree,13);
		 HAL_Delay(100); 
	}
	 HAL_Delay(1000); 
	MOTOR_STOP();
}

//用于测试位置的
//放在while因为有5s延时
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
//输入药箱编号。输入0的时候为默认关闭，
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

