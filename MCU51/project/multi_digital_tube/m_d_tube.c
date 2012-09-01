/*
 display the number from 999 to 0, and circle to this
*/
#include <reg51.h>
#define dataPort  P0
sbit wei = P2^3;
sbit duan = P2^2;

unsigned char duan_in[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};/*0-9*/
unsigned char wei_in[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};/*0-7*/
unsigned char portData[8];
void delay(unsigned int t);
void display(unsigned char firstBit,unsigned char num);
unsigned char getDisplay(int n);
int main()
{
/*
	int num = 100;
	int j = 0;
	while(1)
	{
		j++;
		portData[0] = getDisplay(num/100);
		portData[1] = getDisplay((num%100)/10);
		if((portData[1] == 0x00)&&(portData[0] != 0x00))
			portData[1] = duan_in[0];
		portData[2] = getDisplay(num%10);
		if((portData[2] == 0x00)&&((portData[0] != 0x00)||(portData[1] != 0x00)))
			portData[2] = duan_in[0];
		display(4,3);
		if(j > 50){
			if(!(--num)) num = 100;
			j = 0;
		}
	}
	return 0;
*/
	unsigned char i,j,k,l;
	while(1)
	{
		i++;
		if(0==k)
		{
			for(j=0;j<8;j++)
			{
				portData[j] = 0;
			}
		}
		//portData[0] = duan_in[0];
		display(0,8);
		if(i > 20)
		{
			i = 0;
			if(0 == l)
			{
				portData[7-l] = duan_in[k];
			    k++;l++;
			}
			else if(8 == k)
			{
				k = 0; l = 0;
			}
			else if(l == (9 - k))
			{
				l = 0;
			}
			else
			{
				portData[8-l-1] = portData[8-l];
				portData[8-l] = 0;
				l++;
			}
		}
	}
}
/* make sure the n < sizeof(duan_in)
unsigned char getDisplay(int n)
{
	if(n == 0)
		return 0x00;
	return duan_in[n];
}*/
/* delay for a while */
void delay(unsigned int t)
{
	while(--t);
}
/* the display function
   firstBit: from while wei to display the digital(0-7).
   num : how many wei need to dispaly (1-8).
   Note:make sure firstBit + num <= 8;
*/
void display(unsigned char firstBit,unsigned char num)
{
	unsigned char i;
	for( i = 0; i < num; i++)
	{
		
	    dataPort = 0;//·ÀÖ¹½»ÌæÖØÓ°
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
