#ifndef __ULTRA_H__
#define __ULTRA_H__
#include "REGX52.h"

#define RX  P2_0  //Echo
#define TX  P2_1  //Trig
extern unsigned char disbuff[4];

void Conut(void);
void ultra_timerInit();
void get_distance();

#endif