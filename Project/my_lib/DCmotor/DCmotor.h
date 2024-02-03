#ifndef __DCMOTOR_H__
#define __DCMOTOR_H__

#include "REGX52.h" 
#define IN1   P3_1
#define IN2   P3_0
extern unsigned int PWM_zkb;
void DCmotorstart(unsigned char dir,unsigned int zkb);//使用前需要对T1初始化
#endif             //dir=1,正转；0停止；2反转；zkb 0——1000
