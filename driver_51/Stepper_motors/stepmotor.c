 #include "stepmotor.h"
 #include "Delay.h"
void stepmotor_forward(unsigned int speed)
 {
		         StepMotor_AllPin=0x01;      //��Ч��S_D=0,S_C=0,S_B=0,S_A=1
             Delay(speed); //��ʱ���޸Ĵ˲��������޸ĵ��ת��
             StepMotor_AllPin=0x03;      //��Ч��S_D=0,S_C=0,S_B=1,S_A=1
             Delay(speed); 
             StepMotor_AllPin=0x02;      //i��Ч��S_D=0,S_C=0,S_B=1,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x06;      //��Ч��S_D=0,S_C=1,S_B=1,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x04;      //��Ч��S_D=0,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x0c;      //��Ч��S_D=1,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x08;      //��Ч��S_D=1,S_C=0,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x09;      //��Ч��S_D=1,S_C=0,S_B=0,S_A=1
             Delay(speed); 
 } 
 
void stepmotor_Back(unsigned int speed)
 {
		         StepMotor_AllPin=0x09; //��Ч��S_D=0,S_C=0,S_B=0,S_A=1
             Delay(speed); //��ʱ���޸Ĵ˲��������޸ĵ��ת��
             StepMotor_AllPin=0x08;     //��Ч��S_D=0,S_C=0,S_B=1,S_A=1
             Delay(speed); 
             StepMotor_AllPin=0x0c;   //i��Ч��S_D=0,S_C=0,S_B=1,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x04;     //��Ч��S_D=0,S_C=1,S_B=1,S_A=0
             Delay(speed); 
						 StepMotor_AllPin=0x06; 	 //��Ч��S_D=0,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x02; 	 //��Ч��S_D=1,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x03; 	 //��Ч��S_D=1,S_C=0,S_B=0,S_A=0
             Delay(speed); 
					   StepMotor_AllPin=0x01;	 //��Ч��S_D=1,S_C=0,S_B=0,S_A=1
             Delay(speed); 
 } 
void stepmotor_Stop(void)
 {
    StepMotor_AllPin&=0xF0;
 } 