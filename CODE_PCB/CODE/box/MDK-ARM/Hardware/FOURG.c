#include "main.h"
#include "usart.h"
#include "stdarg.h"
#include <string.h>
#include <stdlib.h>
#include "all.h"
#define TX_BUF_LEN  256     /* 发送缓冲区容量，根据需要进行调整 */
uint8_t TxBuf[TX_BUF_LEN];  /* 发送缓冲区                       */

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
  
  /* 清空发送缓冲区 */
  memset(TxBuf, 0x0, TX_BUF_LEN);
  
  /* 填充发送缓冲区 */
  vsnprintf((char*)TxBuf, TX_BUF_LEN, (const char *)__format, ap);
  va_end(ap);
  int len = strlen((const char*)TxBuf);
  
  /* 往串口发送数据 */
  HAL_UART_Transmit(&huart6, (uint8_t*)&TxBuf, len, 0xFFFF);
}



//进行上传使用heart里面的数据
//为1的时候，将数据都上传到服务器
//为2的时候，请求下发，
//为3的时候，请求又下发又上传
//为4的时候，只上传温湿度
//为5的时候，只上传温湿度+心率，手环控制
//为6的时候，只上传药品的码
void FOURG_UP(int number)
{
	/*使用数据包!(hert)&( spo2)^ (bk)#(tired)@( systolic_pressure)/( diastolic_pressure)+
( heart_output)-( peripheral_resistance)=( rr_period) *( CH4(甲烷))|( humidity(温湿度))?
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
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio,(int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 if(number==1)
	 {
		four.SERVER_UP=10; 
							
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 else if(number==2)
	 {
		four.SERVER_UP=11; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	  else if(number==3)
	 {
		four.SERVER_UP=12; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	  else if(number==4)
	 {
		four.SERVER_UP=10; 
		 heart.rr_period=2;
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 else if(number==5)
	 {
		heart.rr_period=3; 
		four.SERVER_UP=10; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 else if(number==6)
	 {
		heart.rr_period=1;
		 
		four.SERVER_UP=10; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 
	 //之后是短信部分  
	 //14表示为普通 / 有事
	 else if(number==10)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=14; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 
	 
	 //15表示为普通 / 有急事
	 else if(number==11)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=15; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 
	 
	 //17表示为紧急 / 有事
	 else if(number==12)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=17; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 
 
	 //18表示为紧急 / 有急事
	 else if(number==13)
	 {
		heart.rr_period=4;
		 
		four.SERVER_UP=18; 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	  //之后取药部分
	  //
	 else if(number==20)
	 {
		heart.rr_period=5;//为5表示取药
		 
		four.SERVER_UP=10;//进行post上报 
	MyPrintf("!%d&%d^%d#%d@%d/%d+%d-%d=%d*%d|%d~?",heart.heartrate, heart.spo2, heart.bk,four.SERVER_UP,openmv.Drug_code,
	dht11.temp,openmv.TAIL_code,openmv.LOW_code,heart.rr_period,(int)smoke.ratio, (int)dht11.humi); //温湿度还没有模块可以侧，先留着位置
	 }
	 
}
//进行解包，$Reload&+phone+^DOCTORphone%
void FOURG_RECEVIE_unpack(void)
{
	  for(int i=0;i<100;i++)
	{
		 if(four.RESEIVE[i]=='$')
		 {
			  four.heart_location= i;
			  break;
		 
		 }
		 if(i>=98)  //如果都到了这个地步还没有检测到包头，说明数据包出错了，要在后续的屏幕上进行报错
		 {
			 break;
		 }
	
	}
	
	for(int i=four.heart_location;i<99;i++)//从包头开始查找
	{
		 
		if(four.RESEIVE[i]=='&'){
			 four.tail_location=i;
			 //计算到了长度
			 four.data_length=four.tail_location-four.heart_location;
			 for(int i=0;i<(four.data_length-1);i++)
			{
			   four.DATA_buffer[i]=four.RESEIVE[four.heart_location+i+1];
			}
			four.Reload=atoi(four.DATA_buffer) ;
			      
		}
		else if(four.RESEIVE[i]=='^') //找到了
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
		else if(four.RESEIVE[i]=='%') //找到了
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
//上传的最终代码，
void UPLOAD_DATA(void)
{
	HEART_NRF2401_RECEIVE();
   if(nrf2401.staus==1)  //这个是用于检测触摸屏上的是否上传
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
