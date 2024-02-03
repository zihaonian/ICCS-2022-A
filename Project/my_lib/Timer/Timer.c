#include "Timer.h"
#include <REGX52.H>
#include "DCmotor.h"
#include <LCD12864.h>
#include "Delay.h"
static unsigned int i=0;	
static unsigned long j=0;
static unsigned long k=0;
unsigned int time_ds=0;
void Timer0Init()		//50毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xB0;		//设置定时初值
	TH0 = 0x3C;		//设置定时初值
	ET0=1;            //打开定时器 0 中断允许	
  EA=1;             //打开总中断	
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}

void Timer1Init(void)		//10微秒@12.000MHz
{
	TMOD &= 0x0F;	//设置定时器模式
	TL1 = 0xF6;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	ET1=1;        //打开定时器 1 中断允许	
  EA=1;         //打开总中断	
	TF1 = 0;		  //清除TF1标志
	TR1 = 1;		  //定时器1开始计时
}

void Timer2Init(void)		//100微秒@12.000MHz
{
	T2MOD = 0;		//初始化模式寄存器
	T2CON = 0;		//初始化控制寄存器
	TL2 = 0x9C;		//设置定时初值
	TH2 = 0xFF;		//设置定时初值
	ET2=1;
	EA=1;
//	IPH |=0x20;
//  PT2=1;
	TR2 = 1;		//定时器2开始计时
}

//void Timer0() interrupt 1 using 0
//{
//	TL0 = 0xB0;		//设置定时初值
//	TH0 = 0x3C;		//设置定时初值
//  i++;
//	PWM_zkb=500;
//  if(i>time_ds*20)	
//  {	  
//    PWM_zkb=0;
//		ET0=0;
//  }

//}

//void Timer1() interrupt 3 using 1
//{
//	TL1 = 0xF6;		//设置定时初值
//	TH1 = 0xFF;		//设置定时初值
//  j++;	
//  if(j%1000==0)	
//  {	  
//   P2_1=~P2_1;
//  }
//}

void Timer2() interrupt 5 
{
  TF2=0;
	RCAP2L = 0x9C;		//设置定时重载值
	RCAP2H = 0xFF;		//设置定时重载值
  k++;	
  if(k%10000==0)	
  {	  
   P2_2=~P2_2;
  }
}
//void Int0() interrupt 0  using 3   //外部中断 0 的中断函数
//{  
//	
//	  Delay(200);
//		if(P3^2==0)
//		{while(P3^2==0);
//			time_ds--;
//		  LCD12864_ShowNum(3,4,time_ds,3); 
//			
//		}
//	 Delay(200);
//}

//void Int1()	interrupt 2 using 2		//外部中断1的中断函数
//{
//		Delay(200);
//		if(P3^3==0)
//		{
//			while(P3^3==0);
//		time_ds--;
//		LCD12864_ShowNum(3,4,time_ds,3); 
//			
//		}
//		Delay(200);
//}
