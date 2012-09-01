/* caculate*/
#include <REG51.H>

#define dataPort P0
#define keyPort P1
sbit duan = P2^2;
sbit wei = P2^3;

unsigned char duan_in[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};/*0-9*/
unsigned char wei_in[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};/*0-7*/
unsigned char portData[8];
unsigned char keyPressed;

int op1;
int op2;
unsigned char operator;
unsigned char num;

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

		dataPort = portData[i + firstBit];
		duan = 1;
		duan = 0;
		
		i++;
		if(i > num - 1) i = 0;

		delay(100);
	//}
}

unsigned char key_scan()
{
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
		case 0x7D: return 4;
		case 0x7B: return 7;
		case 0x77: return 0;
		case 0xBE: return 2;
		case 0xBD: return 5;
		case 0xBB: return 8;
		case 0xB7: return 'C';
		case 0xDE: return 3;
		case 0xDD: return 6;
		case 0xDB: return 9;
		case 0xD7: return '=';
		case 0xEE: return '+';
		case 0xED: return '-';
		case 0xEB: return '*';
		case 0xE7: return '/';
		default: return  0xFF;
	}
}

void time0_init(void)
{
	TMOD |= 0x01;

	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void time0_isr(void) interrupt 1 using 1
{
	TH0 = (65535-2000)/256;
	TL0 = (65535-2000)%256;
	display(3,5);
}

void int0_init(void)
{
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}

void int0_deact(void)
{
	EX0 = 0;
}
void int0_isr(void) interrupt 0
{
	keyPressed = 1;
}

void calc_error(void)
{
	int0_deact();
}

void calc_init(void)
{
	unsigned char i;
	int0_init();
	op1 = 0;
	op2 = 0;
	operator = 0;
	num = 0xFF;
	for(i = 0; i < 8; i++)
	{
		portData[i] = 0;
	}
	portData[7] = duan_in[0];
}
/*stop the function,and display CE ,press RET */
void calc_stop(void)
{
	unsigned char i;
	calc_error();
	for(i = 0; i < 8; i++)
	{
		portData[i] = 0;
	}
	portData[6] = 0x39;//C
	portData[7] = 0x79;//E
}

/* update display :max bits is 5*/
void updatePortData(int disp)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		portData[i] = 0;
	}
	if(!(disp/10000)){
		portData[3] = 0;
		disp = disp%10000;
		if(!(disp/1000)){
			portData[4] = 0;
			disp = disp%1000;
			if(!(disp/100)){
				portData[5] = 0;
				disp = disp%100;
				if(!(disp/10)){
					portData[6] = 0;
					disp = disp%10;
					portData[7] = duan_in[disp];
				}else{
					portData[6] = duan_in[disp/10];
					disp = disp%10;
					portData[7] = duan_in[disp];
				}
			}else{
				portData[5] = duan_in[disp/100];
				disp = disp%100;
				portData[6] = duan_in[disp/10];
				disp = disp%10;
				portData[7] = duan_in[disp];
			}
		}else{
			portData[4] = duan_in[disp/1000];
			disp = disp%1000;
			portData[5] = duan_in[disp/100];
			disp = disp%100;
			portData[6] = duan_in[disp/10];
			disp = disp%10;
			portData[7] = duan_in[disp];
		}
	}else{
		portData[3] = duan_in[disp/10000];
		disp = disp%10000;
		portData[4] = duan_in[disp/1000];
		disp = disp%1000;
		portData[5] = duan_in[disp/100];
		disp = disp%100;
		portData[6] = duan_in[disp/10];
		disp = disp%10;
		portData[7] = duan_in[disp];
	}
}

/* input: 1 number,0 operator*/
void updateOper(bit input)
{
	if(input)
	{
		if(operator != 0)
		{
			op2 = op2*10 + num;
			updatePortData(op2);
		}else{
			op1 = op1*10 + num;
			updatePortData(op1);
		}		
	}else{
		if(num == 'C'){
			calc_init();
		}else if(num == '='){
			if(operator == '+'){
				op1 += op2;
				if(op1 > 65535){
					calc_stop();
					return;
				}
				op2 = 0;
				updatePortData(op1);
				operator = 0;
			}else if(operator == '-'){
				if(op1<op2){
			 		calc_stop();
					return;
				}
				op1 -= op2;
				op2 = 0;
				updatePortData(op1);
				operator = 0;
			}else if(operator == '*'){
				op1 *= op2;
				if(op1 > 65535){
					calc_stop();
					return;
				}
				op2 = 0;
				updatePortData(op1);
				operator = 0;
			}else if(operator == '/'){
				op1 /= op2;
				if(op2 == 0){
			 		calc_stop();
					return;
				}
				op2 = 0;
				updatePortData(op1);
				operator = 0;
			}else{
				calc_stop();
			}

		}else{
			operator = num;
		}
	}
}

main()
{
	time0_init();	
	calc_init();

	while(1)	
	{
		keyPort = 0xF0;
		if(keyPressed){
			keyPressed = 0;
			num = getNum();
			if((num>=0)&&(num<=9)){
				updateOper(1);
			}else{
				updateOper(0);
			}
		}
	}
}


