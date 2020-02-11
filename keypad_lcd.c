/**************************************************************************/
/* 	This Program is to demonstrate the keypad/LCD Interfacing             */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	LCD Mapping :  D0 to D7 : P0.12 thru P0.19   RS-P1.20,EN-P1.21        */
/*	Keypad Colo:P0.4-P0.7  Keypad Row:P0.8-P0.11						  */
/*  Jumper Setting : SW21: Towards LCD_ON	SW22: Towards KPAD_ON 		  */
/**************************************************************************/

#include<LPC214X.h>													 						   
void delay();
void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

void readkbd(void);

unsigned char a[]={"Enter any key="},i ;

void delay()
{
	int i;
	for(i=0;i<=5000;i++);																																																																																																																																			
}

void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
}

void lcd_cmd(unsigned char x)
{
	IOCLR0=0x000FF000;
	IOSET0=((x<<12)&(0X000FF000));
	IOCLR1=0x00100000;				//RS=0
	delay();
	IOSET1=0x00200000;				//EN=1
	delay();
	IOCLR1=0x00200000;	  			//EN=0
	delay();
}

void lcd_data(unsigned char y)
{
	IOCLR0=0x000FF000;
	IOSET0=((y<<12)&(0x000FF000));
	IOSET1=0x00100000;				//RS=1
	delay();
	IOSET1=0x00200000;				//EN=1
	delay();
	IOCLR1=0x00200000;	  			//EN=0
	delay();
}

void readkbd(void)
{
	while(1)
		{
			//1st Colum
			IOCLR0=0x00000010;
			IOSET0=0x000000E0;
			
			if(!(IOPIN0&(1<<8)))
			{
				//disp_ssd(a[0]);
				lcd_data('0');
				break;
			}

			if(!(IOPIN0&(1<<9)))
			{
				//disp_ssd(a[1]);
				lcd_data('4');
				break;
			}

			if(!(IOPIN0&(1<<10)))
			{
				//disp_ssd(a[2]);
				lcd_data('8');
				break;
			}

			if(!(IOPIN0&(1<<11)))
			{
				//disp_ssd(a[3]);
				lcd_data('C');
				break;
			}

			//2nd Colum
			IOCLR0=0x00000020;
			IOSET0=0x000000D0;
			
			if(!(IOPIN0&(1<<8)))
			{
				//disp_ssd(a[4]);
				lcd_data('1');
				break;
			}

			if(!(IOPIN0&(1<<9)))
			{
				//disp_ssd(a[5]);
				lcd_data('5');
				break;
			}

			if(!(IOPIN0&(1<<10)))
			{
				//disp_ssd(a[6]);
				lcd_data('9');
				break;
			}

			if(!(IOPIN0&(1<11)))
			{
				//disp_ssd(a[7]);
				lcd_data('D');
				break;
			}

			//3rd Colum
			IOCLR0=0x00000040;
			IOSET0=0x000000B0;
			
			if(!(IOPIN0&(1<<8)))
			{
				//disp_ssd(a[8]);
				lcd_data('2');
				break;
			}

			if(!(IOPIN0&(1<<9)))
			{
				//disp_ssd(a[9]);
				lcd_data('6');
				break;
			}

			if(!(IOPIN0&(1<<10)))
			{
				//disp_ssd(a[10]);
				lcd_data('A');
				break;
			}

			if(!(IOPIN0&(1<<11)))
			{
				//disp_ssd(a[11]);
				lcd_data('E');
				break;
			}

			//4th Colum
			IOCLR0=0x00000080;
			IOSET0=0x00000070;
			
			if(!(IOPIN0&(1<<8)))
			{
				//disp_ssd(a[12]);
				lcd_data('3');
				break;
			}

			if(!(IOPIN0&(1<<9)))
			{
				//disp_ssd(a[13]);
				lcd_data('7');
				break;
			}

			if(!(IOPIN0&(1<<10)))
			{
				//disp_ssd(a[14]);
				lcd_data('B');
				break;
			}

			if(!(IOPIN0&(1<<11)))
			{
				//disp_ssd(a[15]);
				lcd_data('F');
				break;
			}
	}
}

int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;

	IODIR0=0x000FF0F0;		//ROW as INPUT and COLUMS as OUTPUT
	IODIR1=0x00300000;

	lcd_init();
		
		lcd_cmd(0x80);
		for(i=0;i<=13;i++)
		{
			lcd_data(a[i]);
			delay();
		}
	while(1)
	{	
		lcd_cmd(0xC0);
		readkbd();
		delay();
	}
return 0;		
}