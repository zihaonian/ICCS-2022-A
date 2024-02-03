#include "Delay.h"
#include "REGX52.h"  
#include "intrins.h"
//延时子函数
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
void Delay1us(unsigned int us)		//@12.000MHz
{
	while(us--)
	{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	}
}


