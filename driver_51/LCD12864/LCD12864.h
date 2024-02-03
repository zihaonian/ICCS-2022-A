#include <REGX52.H>


#ifndef __LCD12864_H__
#define __LCD12864_H__

#define uchar unsigned char
#define uint  unsigned int

/*12864端口定义*/
#define LCD_data  P0             //数据口
sbit LCD_RS  =  P2^6;            //寄存器选择输入 
sbit LCD_RW  =  P2^5;            //液晶读/写控制
sbit LCD_EN  =  P2^7;            //液晶使能控制
sbit LCD_PSB =  P3^3;            //串/并方式控制


/*函数声明*/
void LCD12864_init();  //初始化
void LCD_wcmd(uchar cmd);
void LCD_pos(uchar X,uchar Y);  //确定显示位置
void LCD12864_ShowString (uchar X,uchar Y,uchar *dis);  //X(0-3) 起始行位置 Y       起始列位置 *dis 字符串地址
void LCD12864_ShowNum(uchar X,uchar Y,uint Number,uchar Length);  //X 起始行位置 Y 起始列位置 Number 要显示的数字 Length 要显示数字的长度

#endif
