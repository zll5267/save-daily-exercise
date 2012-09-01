/*exercise for timer*/

#include <REG51.H>

sbit LED = P2;
/*init for the timer*/
void init_timer0(void)
{
	TMOD |= 0x01;
	TH0 = (65536-500)/256;
	TL0 = (65536-500)*256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

main()
{
	init_timer0();
	while(1);
}

/*ISR*/
void timer0_isr(void) interrupt 1 using 1
{
	static unsigned char i;
	TH0 = (65536-500)/256;
	TL0 = (65536-500)%256;
	i++;
	P2 = i;
	LED = P2;
}
