/*button control the led display*/
#include <REG51.H>

#define dataPort P0

sbit duan = P2^2;
sbit wei = P2^3;

sbit sub = P1^0;
sbit add = P1^1; 

unsigned char duan_in[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};/*0-9*/
unsigned char wei_in[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};/*0-7*/
unsigned char portData[8];
void delay(unsigned char t)
{
	while(--t);
}
void display(unsigned char firstBit,unsigned char num)
{
	unsigned char i;
	for(i = 0; i < num; i++)
	{
		dataPort = 0;
		duan = 1;
		duan = 0;

		dataPort = wei_in[i + firstBit];
		wei = 1;
		wei = 0;

		dataPort = portData[i];
		duan = 1;
		duan = 0;

		delay(200);
	}
}
main()
{
	unsigned char display_num;
	duan = 0;
	wei = 0;
	while(1)
	{
		if(!sub)
		{
			display(2,2);//delay(9000);
			if(!sub)
			{
				while(!sub){display(2,2);};
				//delay(8000);
				if(sub)
				{
					if(display_num>0) display_num--;
				}
				
			}
		}
		if(!add)
		{
			display(2,2);//delay(9000);
			if(!add)
			{
				while(!add){display(2,2);};
				//delay(8000);
				if(add)
				{
					if(display_num<99) display_num++;
				}
			}
		}
		portData[0] = duan_in[display_num/10];
		portData[1] = duan_in[display_num%10];
		display(2,2);
	}
}
