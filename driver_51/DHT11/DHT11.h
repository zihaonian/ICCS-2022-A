#ifndef _DHT11_H_
#define _DHT11_H_

#include "REGX52.h"
#include "intrins.h"
//�������

#ifndef uchar
#define uchar unsigned char
#endif
						 
#ifndef uint 
#define uint unsigned int
#endif
extern uint RH,RL,TH,TL,R,T;
#define  Data    P3_6
extern uint rec_dat[];//���ڱ�����յ���������

void DHT11_delay_us(uchar n);
void DHT11_delay_ms(uint z);
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();

#endif