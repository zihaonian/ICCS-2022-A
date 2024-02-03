#ifndef __STEPMOTOR_H__
#define __STEPMOTOR_H__
#include "REGX52.h" 
#define StepMotor_AllPin P2

 void stepmotor_forward(unsigned int speed);
 void stepmotor_Back(unsigned int speed);
 void stepmotor_Stop(void)；
#endif