#include "int.h"
#include "REGX52.h"
#include "Delay.h"
void Int0Init()
{
//���� INT0
IT0=1;//�����س�����ʽ���½��أ�
EX0=1;//�� INT0 ���ж�����
EA=1;//�����ж�
}

void Int1Init()
{
	//����INT1
	IT1=1;//�����س�����ʽ���½��أ�
	EX1=1;//��INT1���ж�����	
	EA=1;//�����ж�	
}
void Int0() interrupt 0  using 3   //�ⲿ�ж� 0 ���жϺ���
{  
	
	  Delay(200);
		if(P3^2==0)
		{
			
		P2_3=~P2_3;
			
		}
	 Delay(200);
}

void Int1()	interrupt 2 using 2		//�ⲿ�ж�1���жϺ���
{
		Delay(200);
		if(P3^3==0)
		{
			
		P2_4=~P2_4;
			
		}
		Delay(200);
}
