#include <REGX52.H>
#include <LCD12864.h>
#include "Delay.h"
#include "DCmotor.h"
#include "XPT2046.h"
#include "Timer.h"
#include "OneWire.h"
#include "DS18B20.h"
#include "MatrixKey.h"
#include "DS1302.h"
#include "int.h"
#include "IR.h"
int time_i=16;
int count_k=0;
int count_j=0;
static int count=600;
unsigned char ttcommand=0;
void main()
{ 
	DS1302_Init();
	IR_Init();
	LCD12864_init();
	Disp_Roll();
	Delay(1000);
	Delay(1000);
	Delay(1000);
	Timer1Init();	
	LCD_wcmd(0x01);
	while(1)
	{   
		DS1302_ReadTime();
		LCD12864_ShowString (0,0,"温度");
		LCD12864_ShowNum(0,2,XPT2046_ReadAD(XPT2046_YP)/4.5,3);
		LCD12864_ShowString (0,4,"浓度");	
		LCD12864_ShowNum(0,6,XPT2046_ReadAD(XPT2046_AUX),3);
		LCD12864_ShowNum(1,0,time_i%24,2);
		LCD12864_ShowString (1,1,"时");
		LCD12864_ShowNum(1,2,DS1302_Time[4]%60,2);
		LCD12864_ShowString (1,3,"分");

		matrixkey_return=MatrixKey();
		if(IR_GetDataFlag()|| IR_GetRepeatFlag())	//如果收到数据帧或者收到连发帧
		{  
			while(IR_GetDataFlag());
			ttcommand=IR_GetCommand();
			if(ttcommand==IR_POWER)
			{
				Timer1Init();	
				DCmotorstart(0,500);
				LCD12864_ShowString (3,0,"挡位");
				LCD12864_ShowString (3,2,"关");
			}
			if(ttcommand==IR_MODE	)
			{
				Timer1Init();	
				DCmotorstart(1,0);
				PWM_zkb=300;
				LCD12864_ShowString (3,0,"挡位");
				LCD12864_ShowString (3,2,"一");
			}
			if(ttcommand==IR_MUTE)
			{
				Timer1Init();	
				DCmotorstart(1,0);
				PWM_zkb=800;
				LCD12864_ShowString (3,0,"挡位");
				LCD12864_ShowString (3,2,"二");
			}
		}
		if(ttcommand==IR_PREVIOUS)
		{
			Timer1Init();	
			DCmotorstart(1,0);
			PWM_zkb=1000;
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"三");
		}
		if(matrixkey_return==1)
		{
			time_i++;
			DS1302_SetTime();
			LCD12864_ShowNum(1,0,time_i%24,2);
			LCD12864_ShowString (1,1,"时");
			LCD12864_ShowNum(1,2,DS1302_Time[4]%60,2);
			LCD12864_ShowString (1,3,"分");
		}
		if(matrixkey_return==5)
		{
			time_i--;
			LCD12864_ShowNum(1,0,time_i%24,2);
			LCD12864_ShowString (1,1,"时");
			LCD12864_ShowNum(1,2,DS1302_Time[4]%60,2);
			LCD12864_ShowString (1,3,"分");
		}
		if(matrixkey_return==2)
		{
			DS1302_Time[4]++;
			DS1302_SetTime();
			LCD12864_ShowNum(1,0,time_i%24,2);
			LCD12864_ShowString (1,1,"时");
			LCD12864_ShowNum(1,2,DS1302_Time[4]%60,2);
			LCD12864_ShowString (1,3,"分");
		}
		if(matrixkey_return==6)
		{
			DS1302_Time[4]--;
			DS1302_SetTime();
			LCD12864_ShowNum(1,0,time_i%24,2);
			LCD12864_ShowString (1,1,"时");
			LCD12864_ShowNum(1,2,DS1302_Time[4]%60,2);
			LCD12864_ShowString (1,3,"分");
		}
		if(matrixkey_return==16)
		{
			Timer1Init();	
			DCmotorstart(0,500);
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"关");
			
		}
		if(matrixkey_return==12)
		{	
			Timer1Init();	
			DCmotorstart(1,0);
			PWM_zkb=300;
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"一");
			
		}
		if(matrixkey_return==8)
		{
			Timer1Init();	
			DCmotorstart(1,0);
			PWM_zkb=800;
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"二");
			
		}
		if(matrixkey_return==4)
		{
			Timer1Init();	
			DCmotorstart(1,0);
			PWM_zkb=1000;
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"三");
		}
		if(matrixkey_return==15)
		{
			Timer1Init();	
			DCmotorstart(1,0);
			PWM_zkb=0;
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"自动");
			count_j=1;
		}
		if(count_j==1)
		{
			PWM_zkb=3*XPT2046_ReadAD(XPT2046_XP);
			Timer1Init();
		}
		if(matrixkey_return==14)
		{	
			PWM_zkb=0;
			Timer1Init();	
			Int0Init();
			Int1Init();			
			DCmotorstart(1,0);
			LCD12864_ShowString (3,0,"挡位");
			LCD12864_ShowString (3,2,"定时");
		}
		if(matrixkey_return==11)
		{
			Timer1Init();
			Timer0Init();
			DCmotorstart(1,0);			
		}	
		if(matrixkey_return==9)
		{
			count=count+50;
			LCD12864_ShowNum(2,0,count,3);
		}
		if(matrixkey_return==10)
		{
			count=count-50;
			LCD12864_ShowNum(2,0,count,3);
		}
		if(3*XPT2046_ReadAD(XPT2046_XP)>count)
		{
			P2_1=0;
			P2_3=0;
		}
		else
		{
			P2_1=1;
			P2_3=1;
		}
		
			
	}
	
}