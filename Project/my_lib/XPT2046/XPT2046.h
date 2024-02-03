


#ifndef __XPT2046_H__
#define __XPT2046_H__
#include <REGX52.H>
#include <INTRINS.H>
#define XPT2046_VBAT	0xAC	    //读取AIN2，光敏电阻
#define XPT2046_AUX		0xEC	    //读取AIN3
#define XPT2046_XP		0x9C	   	//读取AIN0，可调电阻
#define XPT2046_YP		0xDC      //读取AIN1，热敏电阻

//引脚定义
sbit XPY2046_DIN=P3^4;
sbit XPY2046_CS=P3^5;
sbit XPY2046_DCLK=P3^6;
sbit XPY2046_DOUT=P3^7;



unsigned int XPT2046_ReadAD(unsigned char Command); //获取模拟量

#endif
