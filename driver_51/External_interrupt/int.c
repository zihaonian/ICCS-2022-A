#include "int.h"
#include "REGX52.h"
#include "Delay.h"
void Int0Init()
{
//设置 INT0
IT0=1;//跳变沿出发方式（下降沿）
EX0=1;//打开 INT0 的中断允许。
EA=1;//打开总中断
}

void Int1Init()
{
	//设置INT1
	IT1=1;//跳变沿出发方式（下降沿）
	EX1=1;//打开INT1的中断允许。	
	EA=1;//打开总中断	
}
void Int0() interrupt 0  using 3   //外部中断 0 的中断函数
{  
	
	  Delay(200);
		if(P3^2==0)
		{
			
		P2_3=~P2_3;
			
		}
	 Delay(200);
}

void Int1()	interrupt 2 using 2		//外部中断1的中断函数
{
		Delay(200);
		if(P3^3==0)
		{
			
		P2_4=~P2_4;
			
		}
		Delay(200);
}
