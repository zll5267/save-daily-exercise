/*-----------------------------------------------
  ���ƣ�������������ܾ�̬��ʾ
  ��̳��www.doflye.net
  ��д��shifang
  ���ڣ�2009.5
  �޸ģ���
  ���ݣ�ͨ����ֵ��P1�����������ʾ�ض����ַ���������
------------------------------------------------*/
#include<reg52.h> //����ͷ�ļ���һ���������Ҫ�Ķ���
//ͷ�ļ��������⹦�ܼĴ����Ķ���
/*
unsigned char code display[] = {0xC0,0xF9,0xA4,0xB0,0x99,
								0x92,0x82,0xF8,0x80,0x90
								};
*/
unsigned char code display[] = {0x3F,0x06,0x5B,0x4F,0x66,
								0x6D,0x7D,0x07,0x7F,0x6F
								};
/*unsigned char code whichbit[] = {0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x00};*/
unsigned char code whichbit[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
sbit wei = P2^3;
sbit duan = P2^2;
/*
unsigned int num = 10;

unsigned char code display[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};
unsigned int num = 6;
*/
void Delay(unsigned int t);							   

void main (void)
{
/* P1=0xc0;   //������ Ϊ 1100 0000  �ο���������У�
//���Եó�0��Ӧ�Ķε�����1��Ӧ�Ķ�Ϩ�𣬽����ʾ����"0"   
 while(1)
 {

 }

	unsigned char i;
	while(1)
	{
    	for( i = 0; i < num; i++)
		{
			P1 = display[i];
			Delay(60000);
		}
	}

	while(1)
	{
		P1 = P3;
	}
*/
	unsigned char i;
	wei = 0;
	duan = 0;
while(1){

	for( i = 0; i < 8; i++)
	{
		P0 = whichbit[i];
		wei = 1;
		wei = 0;

		P0 = display[i+1];
		duan = 1;
		duan = 0;
		Delay(200);
	}
   }
}
/**/
void Delay(unsigned int t)
{
	while(--t);
}

