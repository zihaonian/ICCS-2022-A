#include <REGX52.H>
#include "Delay.h"
#include "LED_KEY.h"

u8 key_return=0;
unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(KEY1==0){Delay(20);while(KEY1==0);Delay(20);KeyNumber=1;}
	if(KEY2==0){Delay(20);while(KEY2==0);Delay(20);KeyNumber=2;}
	if(KEY3==0){Delay(20);while(KEY3==0);Delay(20);KeyNumber=3;}
	if(KEY4==0){Delay(20);while(KEY4==0);Delay(20);KeyNumber=4;}
	
	return KeyNumber;
}