#include "int.h"
#include "REGX52.h"
#include "Delay.h"
void Int0Init()
{
//���� INT0
IT0=1;//�����س�����ʽ���½��أ�
EX0=1;//�� INT0 ���ж�����
EA=1;//�����ж�
}

void Int1Init()
{
	//����INT1
	IT1=1;//�����س�����ʽ���½��أ�
	EX1=1;//��INT1���ж�����	
	EA=1;//�����ж�	
}

