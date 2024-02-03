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
//延时函数
//****************************************************
void Delay__hx711_us(void)
{
	_nop_();
	_nop_();
}

//****************************************************
//读取HX711
//****************************************************
unsigned long HX711_Read(void)	//增益128
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
    count=count^0x800000;//第25个脉冲下降沿来时，转换数据
	  Delay__hx711_us();
	  HX711_SCK=0;  
	  return(count);
}

unsigned int Get_Weight()
{
	Weight_Shiwu = HX711_Read();
	Weight_Shiwu = Weight_Shiwu - Weight_Maopi;		//获取净重
	if(Weight_Shiwu > 0)			
	{	
		Weight_Shiwu = (unsigned int)((float)Weight_Shiwu/GapValue); 	//计算实物的实际重量																																
		if(Weight_Shiwu > 3000)		//超重报警
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
//获取毛皮重量
//****************************************************
void Get_Maopi()
{
	Weight_Maopi=HX711_Read();	
} 

//****************************************************
//MS延时函数(12M晶振下测试)
//****************************************************
void Delay_ms(unsigned int n)
{
	unsigned int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<1000;j++);
}




