#ifndef __HX711_H__
#define __HX711_H__


#include <REGX52.h>
#include <intrins.h>

//HX711AD模块IO端口设置
#define HX711_DOUT  P3_6 
#define HX711_SCK   P3_7

//函数或者变量声明
void Delay__hx711_us(void);
void Delay_ms(unsigned int n);
unsigned long HX711_Read(void);
unsigned int Get_Weight();
void Get_Maopi();

#endif