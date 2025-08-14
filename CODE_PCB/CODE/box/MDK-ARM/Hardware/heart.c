#include "heart.h"
#include "usart.h"
#include "MYDELAY.h"
#include "all.h"
HEART heart;//存储心率数据包什么的
//开启串口idle空闲中断


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
char gather_start[]={0X8A}; //开始采集
char gather_stop[]={0X88}; //关闭采集

char physical_fitness_test_start[]={0X8E}; //开始体测
char physical_fitness_test_stop[]={0X8C};   //关闭体测
void HEART_START(void)
{

	HAL_UART_Transmit_DMA(&huart2,(uint8_t *)gather_start,10);
	user_delaynus_tim(10);
//	HAL_UART_Transmit_DMA(&huart2,(uint8_t *)physical_fitness_test_start,10);
//	user_delaynus_tim(10);
}

void HEART_DATA_dispose(void)//放在中断内，对数据包进行解码  ,只进行采集模式，不进行体测，采集模式每次是88个字节
{
	for(int i=0;i<88;i++)
	{
	   if(heart.RX_buffer[i]==0xFF)
	   {
		heart.heart_location=i+1;
		break;
		   }   
	}
   for(int i=heart.heart_location;i<88;i++)//第一位直接就是心率大礼包
	{
	   heart.DISPORT_buffer[i-1]=heart.RX_buffer[i];//也就是将数据包整体左移
	}
	for(int i=0;i<100;i++)
	{
	   heart.RX_buffer[i]=0;
	
	}
	
	
	//得到了一坨数据进行解包,第0位 0-63是是心率开启包  ,
	for(int i=0;i<64;i++)
	{
	  heart.acdata[i]=  heart.DISPORT_buffer[i];//存入心率大礼包
	}
	  heart.heartrate= heart.DISPORT_buffer[64];
	  heart.spo2     = heart.DISPORT_buffer[65]; //血氧
	  heart.bk       = heart.DISPORT_buffer[66]; //微循环
	for(int i=0;i<8;i++)  //得到rsv8个数据包，
	{
	  heart.rsv[i]   = heart.DISPORT_buffer[i+67];
	}
	  heart.tired    = heart.rsv[0];             //疲劳指数
	  heart.systolic_pressure= heart.rsv[3];     //收缩压
	  heart.diastolic_pressure= heart.rsv[4];    //舒张压
	  heart.heart_output     = heart.rsv[5];     //心输出
	  heart.peripheral_resistance= heart.rsv[6]; //外周阻力
	  heart.rr_period = heart.rsv[7];             //rr周期
	
	  
	
}   

