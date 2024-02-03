#include <REGX52.H>
#include "DCmotor.h"

#define PWM_MAXcount 1000

u16 PWM_zkb=0;
u16 PWM_count=0;
static u8 dir_flag=0;
void DCmotorstart(u8 dir,u16 zkb)
{ PWM_zkb=zkb;
	if(dir==0)
	{
		ET1=0; 
		IN1=0;
		IN2=0;
	}
	if(dir==1)
	{
		dir_flag=1;
		IN2=0;
	}
	if(dir==2)
	{
		dir_flag=2;
		IN1=0;
	}
}

//void Timer1() interrupt 3 using 1
//{
//	TL1 = 0xF6;		//设置定时初值
//	TH1 = 0xFF;		//设置定时初值
//  PWM_count++;
//	if(PWM_count>PWM_MAXcount)
//	{
//		PWM_count=0;
//	}
//	if(PWM_count>PWM_zkb)
//	{
//		if(dir_flag==1)
//		{
//		 IN1=0;
//		}
//		if(dir_flag==2)
//		{
//		 IN2=0;
//		}
//	}
//	else
//	{
//		if(dir_flag==1)
//		{
//		 IN1=1;
//		}
//		if(dir_flag==2)
//		{
//		 IN2=1;
//		}
//	}
//}