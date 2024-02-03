#include <LCD12864.h>
#include "Delay.h"
#include "REGX52.h" 
/*******************************************************************/                                                    
unsigned char code dis1[] = {"22���̻�"};
unsigned char code dis2[] = {"Y005"};
unsigned char i;
void Disp_Roll()
{
	  Delay(10);                 //��ʱ
    LCD12864_init();                //��ʼ��LCD      
	  LCD12864_ShowString(0,0,dis1);//�ַ������صĵı��ʻ��������ڴ��е���ʼ��ַ   
	  LCD12864_ShowString(1,0,dis2);   
	  LCD12864_ShowString(2,32,dis1);//�ַ������صĵı��ʻ��������ڴ��е���ʼ��ַ   
	  LCD12864_ShowString(3,32,dis2);   
	for(i=0;i<8;i++)
	{
		LCD_RS = 0;
		LCD_RW = 0;
		if(i!=7)
		{
		LCD_wcmd(0x34);	            //��������ָ����� 0011 x1xx
		LCD_wcmd(0x03);	            //���ù��� 0000 0011
		LCD_wcmd(0x40 + 8*i);
		}			//�������������ַ
		if(i==7)
		{
			LCD12864_init();                //��ʼ��LCD      
			LCD12864_ShowString(0,0,dis1);//�ַ������صĵı��ʻ��������ڴ��е���ʼ��ַ   
			LCD12864_ShowString(1,0,dis2);   
			LCD12864_ShowString(2,32,dis1);//�ַ������صĵı��ʻ��������ڴ��е���ʼ��ַ   
			LCD12864_ShowString(3,32,dis2); 
		}
		LCD_wcmd(0x30);	            //���ػ���ָ����� 0011 x000		
		Delay(300);
	}
}
/*******************************************************************/                                                         
/*���LCDæ״̬                                                    */
/*lcd_busyΪ1ʱ��æ���ȴ���lcd-busyΪ0ʱ,�У���дָ�������ݡ�      */                                                          
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
/*дָ�����ݵ�LCD                                                  */
/*RS=L��RW=L��E=�����壬D0-D7=ָ���롣                             */                                                                
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
/*д��ʾ���ݵ�LCD                                                  */
/*RS=H��RW=L��E=�����壬D0-D7=���ݡ�                               */
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
/*  LCD��ʼ���趨                                                  */
/*******************************************************************/
void LCD12864_init()
{ 


    LCD_PSB = 1;         //���ڷ�ʽ
    
    LCD_wcmd(0x34);      //����ָ�����
    Delay(5);
    LCD_wcmd(0x30);      //����ָ�����
    Delay(5);
    LCD_wcmd(0x0C);      //��ʾ�����ع��
   Delay(5);
    LCD_wcmd(0x01);      //���LCD����ʾ����
    Delay(5);
}


/*********************************************************/
/* �趨��ʾλ��       X:����                Y������                                   */
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
   LCD_wcmd(pos);     //��ʾ��ַ
}

/**
  * @brief  ����ֵ=X��Y�η�
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
/* ���趨λ����ʾ�ַ�������                                         */
/*********************************************************/
void LCD12864_ShowString (uchar X,uchar Y,uchar *dis)
{
    uchar i;
LCD_pos(X,Y);   
     i = 0;
    while(dis[i] != '\0')
     {                         //��ʾ�ַ�
       LCD_wdat(dis[i]);
       i++;
     }
}

/**
  * @brief  ��LCD12864ָ��λ�ÿ�ʼ��ʾ��������
  * @param  X ��ʼ��λ��
  * @param  Y ��ʼ��λ��
  * @param  Number Ҫ��ʾ�����֣���Χ��0~65535
  * @param  Length Ҫ��ʾ���ֵĳ��ȣ���Χ��1~5
  * @retval ��
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


