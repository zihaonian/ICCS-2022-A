#include "int.h"
#include "REGX52.h"
#include "Delay.h"
void Int0Init()
{
//设置 INT0
IT0=1;//跳变沿出发方式（下降沿）
EX0=1;//打开 INT0 的中断允许。
EA=1;//打开总中断
}

void Int1Init()
{
	//设置INT1
	IT1=1;//跳变沿出发方式（下降沿）
	EX1=1;//打开INT1的中断允许。	
	EA=1;//打开总中断	
}

