#ifndef __MOTOR_h
#define __MOTOR_h
#include "stdint.h"

void MOTOR_START(void);

void MOTOR_STOP(void);
void MOTOR_LOCATION_Init(void);
void MOTOR_INIT(void);
void MOTOR_LOACTION_COUNTER(int num);
 void MOTOR_locked_rotor(void);
 
 
 typedef struct MOTOR//NRF2401�ӿ�
{
   uint8_t REXEVICE[40]; //���ͻ�����
   
	
	
	
	
	
}MOTOR;

  typedef struct BOX//NRF2401�ӿ�
{
   int8_t staus; //���ͻ�����
	
}BOX;
extern  BOX box;

  void MOTOR_LOCATION_parameter_Counter(void) ;
 extern MOTOR motor;
  void MOTOR_communication_init(void);
void MOTOR_TEST_LOCATION(void);
void medicine_box_counter(int number);
void MOTOR_ZERO(void);
#endif
