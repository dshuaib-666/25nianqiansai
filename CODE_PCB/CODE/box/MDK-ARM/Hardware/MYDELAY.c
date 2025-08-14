#include "MYDELAY.h"
#include "tim.h"       
#include "all.h"
void user_delaynus_tim(uint32_t nus) //us级延时  ,范围不能大于10000，也就是10ms(实际是60000，懒得算)
{
 
 uint16_t  differ = 0xffff-nus-5;   //1us增一次，则
 //设置定时器2的技术初始值
  __HAL_TIM_SetCounter(&htim5,differ);
  //开启定时器
  HAL_TIM_Base_Start(&htim5);
 
  while( differ<0xffff-5)       //4*8 32位 -5避免溢出
 {
  differ = __HAL_TIM_GetCounter(&htim5);
 };
 //关闭定时器
  HAL_TIM_Base_Stop(&htim5);
}



