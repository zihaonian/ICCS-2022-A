#include "REGX52.h"
#include "ultra.h"
#include <intrins.h>
unsigned int  time=0;
unsigned int  timer=0;
unsigned long S=0;
bit      ultra_flag =0;
//--定义全局变量--//

unsigned char disbuff[4]	   ={ 0,0,0,0,};

void Conut(void)
	{
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	
	 S= (long)(time*0.17);     //算出来是CM
	 if((S>=4000)||ultra_flag==1) //超出测量范围显示“ERR0”
	 {	 
	 ultra_flag=0;
	  disbuff[0]=0x3f;	   //“-”
	  disbuff[1]=0x50;	   //“-”
	  disbuff[2]=0x50;	   //“-”
	  disbuff[3]=0x79;	   //“-”
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
//     void zd0() interrupt 1 		 //T0中断用来计数器溢出,超过测距范围
//  {
//    ultra_flag=1;							 //中断溢出标志
//  }
///********************************************************/
//   void  zd3()  interrupt 3 		 //T1中断用来扫描数码管和计800MS启动模块
//  {
//	 TH1=0xf8;
//	 TL1=0x30;
//	 timer++;
//	 if(timer>=100)
//	 {
//	  timer=0;
//	  TX=1;			                //800MS  启动一次模块
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
    TMOD=0x11;		   //设T0为方式1，GATE=1；
	TH0=0;
	TL0=0;          
	TH1=0xf8;		   //2MS定时
	TL1=0x30;
	ET0=1;             //允许T0中断
	ET1=1;			   //允许T1中断
	TR1=1;			   //开启定时器
	EA=1;

}


void get_distance()
{
	 while(!RX);		//当RX为零时等待
	 TR0=1;			    //开启计数
	 while(RX);			//当RX为1计数并等待
	 TR0=0;				//关闭计数
   Conut();
}
