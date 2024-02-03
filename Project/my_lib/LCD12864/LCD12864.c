#include <LCD12864.h>
#include "Delay.h"
#include "REGX52.h" 
/*******************************************************************/                                                    
unsigned char code dis1[] = {"22油烟机"};
unsigned char code dis2[] = {"Y005"};
unsigned char i;
void Disp_Roll()
{
	  Delay(10);                 //延时
    LCD12864_init();                //初始化LCD      
	  LCD12864_ShowString(0,0,dis1);//字符串返回的的本质还是它在内存中的起始地址   
	  LCD12864_ShowString(1,0,dis2);   
	  LCD12864_ShowString(2,32,dis1);//字符串返回的的本质还是它在内存中的起始地址   
	  LCD12864_ShowString(3,32,dis2);   
	for(i=0;i<8;i++)
	{
		LCD_RS = 0;
		LCD_RW = 0;
		if(i!=7)
		{
		LCD_wcmd(0x34);	            //进入扩充指令操作 0011 x1xx
		LCD_wcmd(0x03);	            //设置滚屏 0000 0011
		LCD_wcmd(0x40 + 8*i);
		}			//设置纵向滚屏地址
		if(i==7)
		{
			LCD12864_init();                //初始化LCD      
			LCD12864_ShowString(0,0,dis1);//字符串返回的的本质还是它在内存中的起始地址   
			LCD12864_ShowString(1,0,dis2);   
			LCD12864_ShowString(2,32,dis1);//字符串返回的的本质还是它在内存中的起始地址   
			LCD12864_ShowString(3,32,dis2); 
		}
		LCD_wcmd(0x30);	            //返回基本指令操作 0011 x000		
		Delay(300);
	}
}
/*******************************************************************/                                                         
/*检查LCD忙状态                                                    */
/*lcd_busy为1时，忙，等待。lcd-busy为0时,闲，可写指令与数据。      */                                                          
/*******************************************************************/ 
bit LCD_busy()
 {                          
    bit result;
    LCD_RS = 0;
    LCD_RW = 1;
    LCD_EN = 1;
     Delay(1);
    result = (bit)(LCD_data&0x80);
    LCD_EN = 0;
    return(result); 
 }
/*******************************************************************/                                                               
/*写指令数据到LCD                                                  */
/*RS=L，RW=L，E=高脉冲，D0-D7=指令码。                             */                                                                
/*******************************************************************/
void LCD_wcmd(uchar cmd)
{                          
   while(LCD_busy());
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 0;
   Delay(1);
    LCD_data = cmd;
   Delay(1);
    LCD_EN = 1;
   Delay(1);
    LCD_EN = 0;  
}
/*******************************************************************/
/*写显示数据到LCD                                                  */
/*RS=H，RW=L，E=高脉冲，D0-D7=数据。                               */
/*******************************************************************/
void LCD_wdat(uchar dat)
{                          
   while(LCD_busy());
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_EN = 0;
    LCD_data = dat;
   Delay(1);
    LCD_EN = 1;
  Delay(1);
    LCD_EN = 0; 
}
/*******************************************************************/
/*  LCD初始化设定                                                  */
/*******************************************************************/
void LCD12864_init()
{ 


    LCD_PSB = 1;         //并口方式
    
    LCD_wcmd(0x34);      //扩充指令操作
    Delay(5);
    LCD_wcmd(0x30);      //基本指令操作
    Delay(5);
    LCD_wcmd(0x0C);      //显示开，关光标
   Delay(5);
    LCD_wcmd(0x01);      //清除LCD的显示内容
    Delay(5);
}


/*********************************************************/
/* 设定显示位置       X:行数                Y：列数                                   */
/*********************************************************/
void LCD_pos(uchar X,uchar Y)
{                          
   uchar  pos;
   if (X==0)
     {X=0x80;}
   else if (X==1)
     {X=0x90;}
   else if (X==2)
     {X=0x88;}
   else if (X==3)
     {X=0x98;}
   pos = X+Y ;  
   LCD_wcmd(pos);     //显示地址
}

/**
  * @brief  返回值=X的Y次方
  */
int LCD12864_Pow(int X,int Y)  
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

/*********************************************************/
/* 在设定位置显示字符（串）                                         */
/*********************************************************/
void LCD12864_ShowString (uchar X,uchar Y,uchar *dis)
{
    uchar i;
LCD_pos(X,Y);   
     i = 0;
    while(dis[i] != '\0')
     {                         //显示字符
       LCD_wdat(dis[i]);
       i++;
     }
}

/**
  * @brief  在LCD12864指定位置开始显示所给数字
  * @param  X 起始行位置
  * @param  Y 起始列位置
  * @param  Number 要显示的数字，范围：0~65535
  * @param  Length 要显示数字的长度，范围：1~5
  * @retval 无
  */
void LCD12864_ShowNum(uchar X,uchar Y,uint Number,uchar Length)
{
  uchar i;
	LCD_pos(X,Y); 
	for(i=Length;i>0;i--)
	{
		LCD_wdat(Number/LCD12864_Pow(10,i-1)%10+'0');
	}
}


