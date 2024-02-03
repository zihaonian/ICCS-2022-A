#ifndef _DHT11_H_
#define _DHT11_H_

#include "REGX52.h"
#include "intrins.h"
//定义变量

#ifndef uchar
#define uchar unsigned char
#endif
						 
#ifndef uint 
#define uint unsigned int
#endif
extern uint RH,RL,TH,TL,R,T;
#define  Data    P3_6
extern uint rec_dat[];//用于保存接收到的数据组

void DHT11_delay_us(uchar n);
void DHT11_delay_ms(uint z);
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();

#endif