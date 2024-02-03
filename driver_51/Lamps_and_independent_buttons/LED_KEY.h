#ifndef __LED_KEY_H__
#define __LED_KEY_H__

#include "REGX52.h" 

#define KEY1   P0_7//return=1
#define KEY2   P0_6//return=2
#define KEY3   P0_5//return=3
#define KEY4   P0_4//return=4

#define LED0   P0_3//共阳级 LED=0点亮
#define LED1   P0_2
#define LED2   P0_1

#define HC_SR  P0_7

#define RELAY  P2_0//=0,com->no =1,com->nc 绿灯亮 =0 
#define beer   P2_7//=0 发声

extern u8 key_return;

unsigned char Key();

#endif
