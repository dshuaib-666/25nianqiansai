#include "all.h"

void LCD_COUNTER_COMMON(void)
{
	
	
	if(shine_state==1||four.Reload==31)
	{
		 ZIWAIXIAN_ON();
	}
	if(shine_state==0&&(four.Reload==30||four.Reload==0))
	{
		 ZIWAIXIAN_OFF();
	}
	if(load_state==0)
	{
		 four.Reload=30;
	}
	
	if(medicine_state==0&&box.staus!=0)
	{
		box.staus=0;
		openmv.Drug_code=0;
		FOURG_UP(0);
	  medicine_box_counter(0);
	
	}
	if(medicine_state==1&&box.staus!=1)
	{
		box.staus=1;
		openmv.Drug_code=1;
	//	FOURG_UP(20);
	  medicine_box_counter(1);
		
	
	}
	if(medicine_state==2&&box.staus!=2)
	{
		box.staus=2;
		openmv.Drug_code=2;
	//	FOURG_UP(20);
	  medicine_box_counter(2);
		
	
	}
	if(medicine_state==3&&box.staus!=3)
	{
		box.staus=3;
		openmv.Drug_code=3;
	//	FOURG_UP(20);
	  medicine_box_counter(3);
		
	
	}
	if(medicine_state==4&&box.staus!=4)
	{  
		box.staus=4;
		openmv.Drug_code=4;
	//	FOURG_UP(20);
	  medicine_box_counter(4);
		
	
	}
	if(medicine_state==5&&box.staus!=5)
	{
		box.staus=5;
		openmv.Drug_code=5;
	//	FOURG_UP(20);
	  medicine_box_counter(5);
		
	
	}
	
	
	
	
	




}
//因为有的操作只能放在while，有的又需要计算时间，这个是放在定时器2的
void LCD_COUNTER_COMMON_TIM(void)
{   
	if(load_medicin_state==1)//说明按下的上传心率
	{
		  FOURG_UP(5);	
	}
	
	if(load_state==1&&voice.staus!=14&&voice.staus!=15&&voice.staus!=17&&voice.staus!=18) //按下了上传温湿度
	{
		 FOURG_UP(3);
	}
	if(load_medicin_state!=1&&load_state!=1&&medicine_state==0&&voice.staus!=14&&voice.staus!=15&&voice.staus!=17&&voice.staus!=18) //当都没有按下的时候
	{
		 FOURG_UP(0);
	}
	
	Drug_identification();

}
//药物识别
void  Drug_identification(void)
{
	if(medicine_state!=0&&openmv.TAIL_code!=0&&openmv.LOW_code!=0)
	{
		   openmv.Drug_code=medicine_state;//选择了当前药柜码
		   FOURG_UP(6);
	}
	
	
	

}


