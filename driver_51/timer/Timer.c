#include "Timer.h"
#include <REGX52.H>
static u16 i=0;	
static u32 j=0;
static u32 k=0;
void Timer0Init(void)		//50����@12.000MHz
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

void Timer0() interrupt 1 using 0
{
	TL0 = 0xB0;		//���ö�ʱ��ֵ
	TH0 = 0x3C;		//���ö�ʱ��ֵ
  i++;	
  if(i%20==0)	
  {	  
   P2_0=~P2_0;
  }
}

void Timer1() interrupt 3 using 1
{
	TL1 = 0xF6;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
  j++;	
  if(j%1000==0)	
  {	  
   P2_1=~P2_1;
  }
}

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
