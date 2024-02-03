#include "REGX52.h"
#include "ultra.h"
#include <intrins.h>
unsigned int  time=0;
unsigned int  timer=0;
unsigned long S=0;
bit      ultra_flag =0;
//--����ȫ�ֱ���--//

unsigned char disbuff[4]	   ={ 0,0,0,0,};

void Conut(void)
	{
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	
	 S= (long)(time*0.17);     //�������CM
	 if((S>=4000)||ultra_flag==1) //����������Χ��ʾ��ERR0��
	 {	 
	 ultra_flag=0;
	  disbuff[0]=0x3f;	   //��-��
	  disbuff[1]=0x50;	   //��-��
	  disbuff[2]=0x50;	   //��-��
	  disbuff[3]=0x79;	   //��-��
	 }
	 else
	 {
	  disbuff[0]=S%10000/1000;
	  disbuff[1]=S%1000/100;
	  disbuff[2]=S%100/10;
	  disbuff[3]=S%10/1;
	 }
	}
/********************************************************/
//     void zd0() interrupt 1 		 //T0�ж��������������,������෶Χ
//  {
//    ultra_flag=1;							 //�ж������־
//  }
///********************************************************/
//   void  zd3()  interrupt 3 		 //T1�ж�����ɨ������ܺͼ�800MS����ģ��
//  {
//	 TH1=0xf8;
//	 TL1=0x30;
//	 timer++;
//	 if(timer>=100)
//	 {
//	  timer=0;
//	  TX=1;			                //800MS  ����һ��ģ��
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_();
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_(); 
//	  _nop_();
//	  TX=0;
//	 } 
//  }
/*********************************************************/
void ultra_timerInit()
{
    TMOD=0x11;		   //��T0Ϊ��ʽ1��GATE=1��
	TH0=0;
	TL0=0;          
	TH1=0xf8;		   //2MS��ʱ
	TL1=0x30;
	ET0=1;             //����T0�ж�
	ET1=1;			   //����T1�ж�
	TR1=1;			   //������ʱ��
	EA=1;

}


void get_distance()
{
	 while(!RX);		//��RXΪ��ʱ�ȴ�
	 TR0=1;			    //��������
	 while(RX);			//��RXΪ1�������ȴ�
	 TR0=0;				//�رռ���
   Conut();
}
