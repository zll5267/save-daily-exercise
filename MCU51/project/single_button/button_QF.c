#include <REG51.H>

sbit BTN1 = P2^0;
sbit BTN2 = P2^1;
sbit BTN3 = P2^2;
sbit BTN4 = P2^3;
sbit BTN5 = P2^4;
sbit BTN6 = P2^5;
sbit BTN7 = P2^6;
sbit BTN8 = P2^7;

sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;
sbit LED4 = P0^3;
sbit LED5 = P0^4;
sbit LED6 = P0^5;
sbit LED7 = P0^6;
sbit LED8 = P0^7;

void main()
{
	bit flag;
	while(!flag)
	{
		if(BTN1 == 0){
			LED1 = 0; flag = 1;
		}else if(BTN2 == 0){
			LED2 = 0; flag = 1;
		}else if(BTN3 == 0){
			LED3 = 0; flag = 1;
		}else if(BTN4 == 0){
			LED4 = 0; flag = 1;
		}else if(BTN5 == 0){
			LED5 = 0; flag = 1;
		}else if(BTN6 == 0){
			LED6 = 0; flag = 1;
		}else if(BTN7 == 0){
			LED7 = 0; flag = 1;
		}else if(BTN8 == 0){
			LED8 = 0; flag = 1;
		}

	}
	while(flag);
}

