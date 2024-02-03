


#ifndef __XPT2046_H__
#define __XPT2046_H__
#include <REGX52.H>
#include <INTRINS.H>
#define XPT2046_VBAT	0xAC	    //��ȡAIN2����������
#define XPT2046_AUX		0xEC	    //��ȡAIN3
#define XPT2046_XP		0x9C	   	//��ȡAIN0���ɵ�����
#define XPT2046_YP		0xDC      //��ȡAIN1����������

//���Ŷ���
sbit XPY2046_DIN=P3^4;
sbit XPY2046_CS=P3^5;
sbit XPY2046_DCLK=P3^6;
sbit XPY2046_DOUT=P3^7;



unsigned int XPT2046_ReadAD(unsigned char Command); //��ȡģ����

#endif
