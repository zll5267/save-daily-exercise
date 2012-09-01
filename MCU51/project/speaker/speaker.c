/*exercise for the speaker*/
#include <REG51.H>

sbit SPEAKER = P2^0;
unsigned char frq;
void delay(unsigned char t);
void t0_init(void)
{
	TMOD = TMOD|0x01;
	TH0 = 0xFE;
	TL0 = frq;

	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void t0_isr(void) interrupt 1
{
	TH0 = 0xFA;
	TL0 = frq;

	SPEAKER = !SPEAKER;
}
main()
{
	unsigned char i;
	t0_init();
	while(1)
	{
		
		for(i = 0; i < 200; i++){
			delay(10000);frq = i;
		}
		
		for(i = 200; i > 0; i--){
			delay(10000);frq = i;
		}
	}
}

void delay(unsigned char t)
{
	while(--t);	
}
