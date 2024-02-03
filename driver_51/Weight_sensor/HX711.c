#include "HX711.h"
#include "REGX52.h" 
#define GapValue 440


unsigned long HX711_Buffer = 0;
unsigned long Weight_Maopi = 0;
long Weight_Shiwu = 0;
unsigned char flag = 0;
bit Flag_ERROR=0;
#define GapValue 440
//****************************************************
//��ʱ����
//****************************************************
void Delay__hx711_us(void)
{
	_nop_();
	_nop_();
}

//****************************************************
//��ȡHX711
//****************************************************
unsigned long HX711_Read(void)	//����128
{

  	unsigned long count; 
	  unsigned char i; 
  	HX711_DOUT=1; 
	  Delay__hx711_us();
  	HX711_SCK=0; 
  	count=0;
	  EA = 1; 
  	while(HX711_DOUT); 
	  EA = 0;
  	for(i=0;i<24;i++)
	  { 
	  HX711_SCK=1; 
	  count=count<<1; 
		HX711_SCK=0; 
	  if(HX711_DOUT)
			count++; 
	  } 
 	  HX711_SCK=1; 
    count=count^0x800000;//��25�������½�����ʱ��ת������
	  Delay__hx711_us();
	  HX711_SCK=0;  
	  return(count);
}

unsigned int Get_Weight()
{
	Weight_Shiwu = HX711_Read();
	Weight_Shiwu = Weight_Shiwu - Weight_Maopi;		//��ȡ����
	if(Weight_Shiwu > 0)			
	{	
		Weight_Shiwu = (unsigned int)((float)Weight_Shiwu/GapValue); 	//����ʵ���ʵ������																																
		if(Weight_Shiwu > 3000)		//���ر���
		{	
			Flag_ERROR = 1;	
		}
		else
		{  
			Flag_ERROR = 0;
		}
	}
	else
	{
		Weight_Shiwu = 0;			
	}	
	return Weight_Shiwu;
}

//****************************************************
//��ȡëƤ����
//****************************************************
void Get_Maopi()
{
	Weight_Maopi=HX711_Read();	
} 

//****************************************************
//MS��ʱ����(12M�����²���)
//****************************************************
void Delay_ms(unsigned int n)
{
	unsigned int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<1000;j++);
}




