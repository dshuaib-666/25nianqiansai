#include "MYDELAY.h"
#include "tim.h"       
#include "all.h"
void user_delaynus_tim(uint32_t nus) //us����ʱ  ,��Χ���ܴ���10000��Ҳ����10ms(ʵ����60000��������)
{
 
 uint16_t  differ = 0xffff-nus-5;   //1us��һ�Σ���
 //���ö�ʱ��2�ļ�����ʼֵ
  __HAL_TIM_SetCounter(&htim5,differ);
  //������ʱ��
  HAL_TIM_Base_Start(&htim5);
 
  while( differ<0xffff-5)       //4*8 32λ -5�������
 {
  differ = __HAL_TIM_GetCounter(&htim5);
 };
 //�رն�ʱ��
  HAL_TIM_Base_Stop(&htim5);
}



