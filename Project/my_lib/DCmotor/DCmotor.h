#ifndef __DCMOTOR_H__
#define __DCMOTOR_H__

#include "REGX52.h" 
#define IN1   P3_1
#define IN2   P3_0
extern unsigned int PWM_zkb;
void DCmotorstart(unsigned char dir,unsigned int zkb);//ʹ��ǰ��Ҫ��T1��ʼ��
#endif             //dir=1,��ת��0ֹͣ��2��ת��zkb 0����1000
