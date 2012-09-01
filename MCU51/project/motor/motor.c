/* for the step motor*/
#include <REG51.H>

sbit A1 = P1^0;
sbit B1 = P1^1;
sbit C1 = P1^2;
sbit D1 = P1^3;

#define Coil_OFF {A1=0;B1=0;C1=0;D1=0;}
#define Coil_A {A1=1;B1=0;C1=0;D1=0;}
#define Coil_AB {A1=1;B1=1;C1=0;D1=0;}
#define Coil_B {A1=0;B1=1;C1=0;D1=0;}
#define Coil_BC {A1=0;B1=1;C1=1;D1=0;}
#define Coil_C {A1=0;B1=0;C1=1;D1=0;}
#define Coil_CD {A1=0;B1=0;C1=1;D1=1;}
#define Coil_D {A1=0;B1=0;C1=0;D1=1;}
#define Coil_DA {A1=1;B1=0;C1=0;D1=1;}

unsigned char speed = 1;

void delayMs(unsigned char t);

main()
{
	//unsigned char i;
	speed = 3;
	Coil_OFF;
	while(1)
	{
		//i++;
		Coil_A
		delayMs(speed);
		Coil_AB
		delayMs(speed);
		Coil_B
		delayMs(speed);
		Coil_BC
		delayMs(speed);
		Coil_C
		delayMs(speed);
		Coil_CD
		delayMs(speed);
		Coil_D
		delayMs(speed);
		Coil_DA
		delayMs(speed);
		/*
		if(i > 90){
			speed = 50;
			i=0;
		}else if(i > 80){
			speed = 40;
		}else if(i > 70){
			speed = 30;
		}else if(i > 60){
			speed = 20;
		}else if(i > 50){
			speed = 10;
		}else if(i > 40){
			speed = 20;
		}else if(i > 30){
			speed = 30;
		}else if(i > 20){
			speed = 40;
		}
		*/
	}
}

void delayMs(unsigned char t)
{
	unsigned char i;
	while(t--)
	{
		i = 50;
		while(--i);
	}
}
