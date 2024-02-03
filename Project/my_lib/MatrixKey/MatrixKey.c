#include <REGX52.H>
#include "Delay.h"
#include "MatrixKey.h"

unsigned char matrixkey_return=0;

unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
	MKEY_ALL=0xFF;
	L1=0;
	if(H1==0){Delay(20);while(H1==0);Delay(20);KeyNumber=1;}
	if(H2==0){Delay(20);while(H2==0);Delay(20);KeyNumber=5;}
	if(H3==0){Delay(20);while(H3==0);Delay(20);KeyNumber=9;}
	if(H4==0){Delay(20);while(H4==0);Delay(20);KeyNumber=13;}
	
	MKEY_ALL=0xFF;
	L2=0;
	if(H1==0){Delay(20);while(H1==0);Delay(20);KeyNumber=2;}
	if(H2==0){Delay(20);while(H2==0);Delay(20);KeyNumber=6;}
	if(H3==0){Delay(20);while(H3==0);Delay(20);KeyNumber=10;}
	if(H4==0){Delay(20);while(H4==0);Delay(20);KeyNumber=14;}
	
	MKEY_ALL=0xFF;
	L3=0;
	if(H1==0){Delay(20);while(H1==0);Delay(20);KeyNumber=3;}
	if(H2==0){Delay(20);while(H2==0);Delay(20);KeyNumber=7;}
	if(H3==0){Delay(20);while(H3==0);Delay(20);KeyNumber=11;}
	if(H4==0){Delay(20);while(H4==0);Delay(20);KeyNumber=15;}
	
	MKEY_ALL=0xFF;
	L4=0;
	if(H1==0){Delay(20);while(H1==0);Delay(20);KeyNumber=4;}
	if(H2==0){Delay(20);while(H2==0);Delay(20);KeyNumber=8;}
	if(H3==0){Delay(20);while(H3==0);Delay(20);KeyNumber=12;}
	if(H4==0){Delay(20);while(H4==0);Delay(20);KeyNumber=16;}
	
	return KeyNumber;
}

