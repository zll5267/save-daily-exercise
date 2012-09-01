#include <REG52.H>
sbit LED = P2^0;
/*init for the time2*/
void init_time2(void)
{
	RCAP2H = (65536-60000)/256;
	RCAP2L = (65536-60000)%256;

	ET2 = 1;
	EA = 1;
	TR2 = 1;
}
main()
{
	init_time2();
	while(1);
}
void time2_isr(void) interrupt 5 using 1
{
	TF2 = 0;
	LED = ~LED;
}

