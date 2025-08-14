#include "all.h"

VOICE voice;


void VOICE_DATA_INIT(void)
{
			for(int k=0;k<10;k++)
			{   voice.DATA_buffer[k]=0;
			}
			for(int k=0;k<99;k++)
			{
				voice.voice_buffer[k]=0;
			
			}
			
}

//void voice_init()
//{
//   __HAL_UART_ENABLE_IT(&huart4, UART_IT_IDLE);  
//	 HAL_UART_Receive_DMA(&huart4,voice.voice_buffer,100);
//   VOICE_DATA_INIT();
//}

void voice_init()
{

	   __HAL_UART_ENABLE_IT(&huart4, UART_IT_IDLE);  
	 HAL_UART_Receive_DMA(&huart4,voice.voice_buffer,100);
   VOICE_DATA_INIT();
}




//进行解包，0x11 + DATA + 0x22
void VOICE_RECEVIE_unpack(void)
{
	  for(int i=0;i<100;i++)
	{
		 if(voice.voice_buffer[i]==0x11)
		 {
			  voice.heart_location= i;
			  break;
		 
		 }
		 if(i>=98)  //如果都到了这个地步还没有检测到包头，说明数据包出错了，要在后续的屏幕上进行报错
		 {
			 break;
		 }
	
	}
	
	for(int i=voice.heart_location;i<99;i++)//从包头开始查找
	{
		 
		if(voice.voice_buffer[i]==0x22){
			 voice.tail_location=i;
			 //计算到了长度
			 voice.data_length=voice.tail_location-voice.heart_location;
			 for(int i=0;i<(voice.data_length-1);i++)
			{
			   voice.DATA_buffer[i]=voice.voice_buffer[voice.heart_location+i+1];
			}
			voice.Reload=voice.DATA_buffer[0];
			VOICE_DATA_INIT();
			 break;      
		}
		
		
		
	}

}


void voice_order()
{
	if(voice.Reload==0x11)
	{  if(voice.staus!=0)
							{
							voice.staus=0;
							MOTOR_ZERO();
							}
							else{
							
							} 
	}
	else if(voice.Reload==0x1)
	{
			if(voice.staus!=1)
				{
				voice.staus=1;
				medicine_box_counter(1);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x2)
	{
			if(voice.staus!=2)
				{
				voice.staus=2;
				medicine_box_counter(2);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x3)
	{
			if(voice.staus!=3)   
				{
				voice.staus=3;
				medicine_box_counter(3);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x4)
	{
			if(voice.staus!=4)
				{
				voice.staus=4;
				medicine_box_counter(4);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x5)
	{
			if(voice.staus!=5)
				{
				voice.staus=5;
				medicine_box_counter(5);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x8) //紫外线
	{
			if(voice.staus!=8)
				{
				voice.staus=8;
			
				}
				else{
				
				}
	}
	else if(voice.Reload==0x9)
	{
			if(voice.staus!=9)
				{
				voice.staus=9;
			
				}
				else{
				
				}
	}
	else if(voice.Reload==0x14)
	{
			if(voice.staus!=14)
				{
				voice.staus=14;
				FOURG_UP(10);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x15)
	{
			if(voice.staus!=15)
				{
				voice.staus=15;
				FOURG_UP(11);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x17)
	{
			if(voice.staus!=17)
				{
				voice.staus=17;
				FOURG_UP(12);
				}
				else{
				
				}
	}
	else if(voice.Reload==0x18)
	{
			if(voice.staus!=18)
				{
				voice.staus=18;
				FOURG_UP(13);
				}
				else{
				
				}
	}
		
			
		
		
		
		
		

}



void voice_prase()
{

//	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==GPIO_PIN_SET)//鍥炴鑽
//	{
//		 
//	   MOTOR_ZERO();
//	}
//	else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==GPIO_PIN_SET)//浜屽彿鑽
//	{
//	   MOTOR_LOACTION_COUNTER(4);
//	}


}

