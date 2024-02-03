#include <REGX52.H>


#ifndef __LCD12864_H__
#define __LCD12864_H__

#define uchar unsigned char
#define uint  unsigned int

/*12864�˿ڶ���*/
#define LCD_data  P0             //���ݿ�
sbit LCD_RS  =  P2^6;            //�Ĵ���ѡ������ 
sbit LCD_RW  =  P2^5;            //Һ����/д����
sbit LCD_EN  =  P2^7;            //Һ��ʹ�ܿ���
sbit LCD_PSB =  P3^3;            //��/����ʽ����


/*��������*/
void LCD12864_init();  //��ʼ��
void LCD_wcmd(uchar cmd);
void LCD_pos(uchar X,uchar Y);  //ȷ����ʾλ��
void LCD12864_ShowString (uchar X,uchar Y,uchar *dis);  //X(0-3) ��ʼ��λ�� Y       ��ʼ��λ�� *dis �ַ�����ַ
void LCD12864_ShowNum(uchar X,uchar Y,uint Number,uchar Length);  //X ��ʼ��λ�� Y ��ʼ��λ�� Number Ҫ��ʾ������ Length Ҫ��ʾ���ֵĳ���

#endif
