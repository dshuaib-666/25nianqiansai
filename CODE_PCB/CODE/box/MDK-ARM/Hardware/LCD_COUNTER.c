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
//��Ϊ�еĲ���ֻ�ܷ���while���е�����Ҫ����ʱ�䣬����Ƿ��ڶ�ʱ��2��
void LCD_COUNTER_COMMON_TIM(void)
{   
	if(load_medicin_state==1)//˵�����µ��ϴ�����
	{
		  FOURG_UP(5);	
	}
	
	if(load_state==1&&voice.staus!=14&&voice.staus!=15&&voice.staus!=17&&voice.staus!=18) //�������ϴ���ʪ��
	{
		 FOURG_UP(3);
	}
	if(load_medicin_state!=1&&load_state!=1&&medicine_state==0&&voice.staus!=14&&voice.staus!=15&&voice.staus!=17&&voice.staus!=18) //����û�а��µ�ʱ��
	{
		 FOURG_UP(0);
	}
	
	Drug_identification();

}
//ҩ��ʶ��
void  Drug_identification(void)
{
	if(medicine_state!=0&&openmv.TAIL_code!=0&&openmv.LOW_code!=0)
	{
		   openmv.Drug_code=medicine_state;//ѡ���˵�ǰҩ����
		   FOURG_UP(6);
	}
	
	
	

}


