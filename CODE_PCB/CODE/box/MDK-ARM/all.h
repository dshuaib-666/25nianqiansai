#ifndef __ALL_H_
#define __ALL_H_ 			   

//内置头文件
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdarg.h"
#include <string.h>
#include <stdlib.h>


//自置头文件
#include "delay.h"
#include "lcd.h"
#include "lcd_init.h"
#include "touch.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lvgl_init.h"
#include "breate.h"
#include "FOURG.h"
#include "DHT11.h"
#include "heart.h"
#include "MOTOR.h"
#include "MYDELAY.h"
#include "NF.h"
#include "smoke.h"
#include "ziwaixian.h"
#include "LCD_COUNTER.h"
#include "openmv.h"
#include "voice.h"
#include "DHT11.h"


extern int32_t warmth11;
extern int32_t medicine_state;
extern int32_t lvgl_task_time;
extern int32_t lvgl_handler_time;
extern int cheak;
extern uint8_t Receive[33];//接收数组
extern int32_t load_state;//上传数据按钮
extern int32_t shine_state;//紫外线
extern int32_t load_medicin_state;//药物数据上传
extern int16_t medicine_reconfig_state;//药物识别
extern int16_t lvgl_medicine_reconfig_state;
extern int16_t medicine_none_ok;

void resources_init(void);
void all_init(void);
void code_carry(void);
#endif

