#include "all.h"

int32_t warmth11=0;
int32_t medicine_state=0;
int32_t lvgl_task_time=0;
int32_t lvgl_handler_time=0;
int cheak=9;
uint8_t Receive[33];//接收数组
int16_t medicine_reconfig_state=0;//药物识别（用于与openmv通讯）（1：识别 2：不识别）
int16_t lvgl_medicine_reconfig_state=1;
int16_t medicine_none_ok=1;//是否以及识别到药物(用于与小程序通讯)
int16_t timeout=0;

//硬件资源初始化
void resources_init()
{
   HAL_TIM_Base_Start_IT(&htim6);

}

//外接外设初始化
void all_init()
{
		HAL_Delay_us_init(168);
	  LCD_Init();
	  TP_Init();
    lv_init();		
    lv_port_disp_init();   
  	lv_port_indev_init();
		init_start_screen();
		HAL_Delay_us_init(168);
	  HAL_Delay(1200);
		DHT11_OUT();
		DHT11_Init(&dht11.temp , &dht11.humi);

		lv_timer_create(xinlv_update_display, 5000, NULL);  
		lv_timer_create(warmth_update_display, 5000, NULL);  
		lv_timer_create(humi_update_display, 5000, NULL);  
		lv_timer_create(Smoke_update_display, 5000, NULL); 
		lv_timer_create(phone_update_display, 5000, NULL);  

	
	
//			MOTOR_communication_init();
//    HAL_TIM_Base_Start_IT(&htim2);
//  
////	DHT11_Strat();
////	dht11.check= DHT11_Check();
//	  MOTOR_INIT();
//	  FOURG_INIT();
//	  while(NRF24L01_Check())
// {                                                                                           
//  	HAL_Delay(1000);
// }
// for(int o;o<40;o++)
//	 {
//	   nrf2401.SNET_buffer[o]=0;
//	 
//	 }
//	
//       NRF24L01_RX_Mode();//???????	  
//	 
//	 
//	 
//	 //    OLED_ShowString(0, 0, "Hello, world", OLED_6X8);
////	OLED_ReverseArea(0,0, 128, 8);
////    OLED_Update();
//		HAL_Delay(500);  
//	// MOTOR_locked_rotor();
//	  HAL_Delay(500);  
//	//MOTOR_LOACTION_COUNTER(8);
//	// HAL_Delay(1000);  
//	 //MOTOR_LOCATION_Init();
//	  FOURG_UP(2);
	 
	 
	 
}


//while循环里面的代码
void code_carry()
{
		if(lvgl_task_time>=1)
		{                    
				lv_task_handler();
				lvgl_task_time=0;
		}
		if(lvgl_handler_time>=2)
		{
				tp_dev.scan(0);//?????????,????
				lvgl_handler_time=0;
		}
		
		if((timeout++)>50)
		{
		DHT11_Init(&dht11.temp , &dht11.humi);
		timeout=0;
    }
	
	
	 // MOTOR_LOACTION_COUNTER(2);
//	   medicine_box_counter(0);
//	   
  //MOTOR_TEST_LOCATION();

}

