#include <REG51.H>

#define dataPort P0
#define keyPort P1
sbit duan = P2^2;
sbit wei = P2^3;

unsigned char duan_in[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};/*0-9*/
unsigned char wei_in[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};/*0-7*/
unsigned char portData[8];
unsigned char keyPressed;
void delay(unsigned char t)
{
	while(--t);
}

void display(unsigned char firstBit,unsigned char num)
{
	static unsigned char i;
	//for(i = 0; i < num; i++)
	//{
		dataPort = 0;
		duan = 1;
		duan = 0;

		dataPort = wei_in[i + firstBit];
		wei = 1;
		wei = 0;

		dataPort = portData[i];
		duan = 1;
		duan = 0;
		
		i++;
		if(i > num - 1) i = 0;

		delay(100);
	//}
}

unsigned char key_scan()
{
/*	unsigned char keyValue;
	keyPort = 0x0F;//0xF0
	if(keyPort != 0x0F)
	{
		delay(6000);
		if(keyPort != 0x0F)
		{
			keyPort = 0xEF;
			if(keyPort != 0xEF)
			{
				keyValue = keyPort&0x0F;
 			    keyValue = keyPort|0xE0;
				return keyValue;
			}
			keyPort = 0xDF;
			if(keyPort != 0xDF)
			{
				keyValue = keyPort&0x0F;
 			    keyValue = keyPort|0xD0;
				return keyValue;
			}
			keyPort = 0xBF;
			if(keyPort != 0xBF)
			{
				keyValue = keyPort&0x0F;
 			    keyValue = keyPort|0xB0;
				return keyValue;
			}
			keyPort = 0x7F;
			if(keyPort != 0x7F)
			{
				keyValue = keyPort&0x0F;
 			    keyValue = keyPort|0x70;
				return keyValue;
			}
		}

	}
*/
	unsigned char keyValue;
	keyPort = 0xF0;
	if(keyPort != 0xF0)
	{
		delay(6000);
		if(keyPort != 0xF0);
		{
			keyValue = keyPort&0xF0;
			keyPort = 0x0F;
			if(keyPort != 0x0F)
			{
				delay(60000);
				if(keyPort != 0x0F)
				{
					keyValue = keyValue|keyPort;
					return keyValue;
				}
			}
		}
	}
	return 0;
}

unsigned char getNum(){
	unsigned char keyValue;
	keyValue = key_scan();
	switch(keyValue)
	{
		case 0x7E: return 1;
		case 0x7D: return 2;
		case 0x7B: return 3;
		case 0x77: return 4;
		case 0xBE: return 5;
		case 0xBD: return 6;
		case 0xBB: return 7;
		case 0xB7: return 8;
		case 0xDE: return 9;
		case 0xDD: return 10;
		case 0xDB: return 11;
		case 0xD7: return 12;
		case 0xEE: return 13;
		case 0xED: return 14;
		case 0xEB: return 15;
		case 0xE7: return 16;
		default: return  0;
	}
}

void time0_init(void)
{
	TMOD |= 0x01;

	//TH0 = (65535-2000)/256;
	//TL0 = (65535-2000)%256;

	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void time0_isr(void) interrupt 1 using 1
{
	TH0 = (65535-2000)/256;
	TL0 = (65535-2000)%256;
	display(1,2);
}

void int0_init(void)
{
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}
void int0_isr(void) interrupt 0
{
	keyPressed = 1;
}

main()
{
	unsigned char num;
	time0_init();
	int0_init();
	portData[0] = duan_in[0];
	portData[1] = duan_in[0];

	while(1)	
	{
		keyPort = 0xF0;
		if(keyPressed){
			//display(1,2);
			keyPressed = 0;
			num = getNum();
			portData[0] = duan_in[num/10];
			portData[1] = duan_in[num%10];
		}
	}
}
