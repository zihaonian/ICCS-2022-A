#include "Timer.h"
#include <REGX52.H>
#include "DCmotor.h"
#include <LCD12864.h>
#include "Delay.h"
static unsigned int i=0;	
static unsigned long j=0;
static unsigned long k=0;
unsigned int time_ds=0;
void Timer0Init()		//50����@12.000MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xB0;		//���ö�ʱ��ֵ
	TH0 = 0x3C;		//���ö�ʱ��ֵ
	ET0=1;            //�򿪶�ʱ�� 0 �ж�����	
  EA=1;             //�����ж�	
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}

void Timer1Init(void)		//10΢��@12.000MHz
{
	TMOD &= 0x0F;	//���ö�ʱ��ģʽ
	TL1 = 0xF6;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
	ET1=1;        //�򿪶�ʱ�� 1 �ж�����	
  EA=1;         //�����ж�	
	TF1 = 0;		  //���TF1��־
	TR1 = 1;		  //��ʱ��1��ʼ��ʱ
}

void Timer2Init(void)		//100΢��@12.000MHz
{
	T2MOD = 0;		//��ʼ��ģʽ�Ĵ���
	T2CON = 0;		//��ʼ�����ƼĴ���
	TL2 = 0x9C;		//���ö�ʱ��ֵ
	TH2 = 0xFF;		//���ö�ʱ��ֵ
	ET2=1;
	EA=1;
//	IPH |=0x20;
//  PT2=1;
	TR2 = 1;		//��ʱ��2��ʼ��ʱ
}

//void Timer0() interrupt 1 using 0
//{
//	TL0 = 0xB0;		//���ö�ʱ��ֵ
//	TH0 = 0x3C;		//���ö�ʱ��ֵ
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
//	TL1 = 0xF6;		//���ö�ʱ��ֵ
//	TH1 = 0xFF;		//���ö�ʱ��ֵ
//  j++;	
//  if(j%1000==0)	
//  {	  
//   P2_1=~P2_1;
//  }
//}

void Timer2() interrupt 5 
{
  TF2=0;
	RCAP2L = 0x9C;		//���ö�ʱ����ֵ
	RCAP2H = 0xFF;		//���ö�ʱ����ֵ
  k++;	
  if(k%10000==0)	
  {	  
   P2_2=~P2_2;
  }
}
//void Int0() interrupt 0  using 3   //�ⲿ�ж� 0 ���жϺ���
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

//void Int1()	interrupt 2 using 2		//�ⲿ�ж�1���жϺ���
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
