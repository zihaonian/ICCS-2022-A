 #include "stepmotor.h"
 #include "Delay.h"
void stepmotor_forward(unsigned int speed)
 {
		         StepMotor_AllPin=0x01;      //等效于S_D=0,S_C=0,S_B=0,S_A=1
             Delay(speed); //延时，修改此参数即可修改电机转速
             StepMotor_AllPin=0x03;      //等效于S_D=0,S_C=0,S_B=1,S_A=1
             Delay(speed); 
             StepMotor_AllPin=0x02;      //i等效于S_D=0,S_C=0,S_B=1,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x06;      //等效于S_D=0,S_C=1,S_B=1,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x04;      //等效于S_D=0,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x0c;      //等效于S_D=1,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x08;      //等效于S_D=1,S_C=0,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x09;      //等效于S_D=1,S_C=0,S_B=0,S_A=1
             Delay(speed); 
 } 
 
void stepmotor_Back(unsigned int speed)
 {
		         StepMotor_AllPin=0x09; //等效于S_D=0,S_C=0,S_B=0,S_A=1
             Delay(speed); //延时，修改此参数即可修改电机转速
             StepMotor_AllPin=0x08;     //等效于S_D=0,S_C=0,S_B=1,S_A=1
             Delay(speed); 
             StepMotor_AllPin=0x0c;   //i等效于S_D=0,S_C=0,S_B=1,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x04;     //等效于S_D=0,S_C=1,S_B=1,S_A=0
             Delay(speed); 
						 StepMotor_AllPin=0x06; 	 //等效于S_D=0,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x02; 	 //等效于S_D=1,S_C=1,S_B=0,S_A=0
             Delay(speed); 
             StepMotor_AllPin=0x03; 	 //等效于S_D=1,S_C=0,S_B=0,S_A=0
             Delay(speed); 
					   StepMotor_AllPin=0x01;	 //等效于S_D=1,S_C=0,S_B=0,S_A=1
             Delay(speed); 
 } 
void stepmotor_Stop(void)
 {
    StepMotor_AllPin&=0xF0;
 } 