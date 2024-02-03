#ifndef __DCMOTOR_H__
#define __DCMOTOR_H__

#include "REGX52.h" 
#define IN1   P2_5
#define IN2   P2_4

void DCmotorstart(u8 dir,u8 zkb);//使用前需要对T1初始化
#endif             //dir=1,正转；0停止；2反转；zkb 0——1000
