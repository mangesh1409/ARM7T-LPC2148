/**************************************************************************/
/* 	This Program is to demonstrate the LCD Interfacing                    */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	LCD Mapping :  D0 to D7 : P0.12 thru P0.19   RS-P1.20,EN-P1.21        */
/*  Jumper Setting : SW21: towards LCD_ON 								  */
/**************************************************************************/


#include<LPC214X.h>
void delay();
void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

unsigned char a[]={"Mangesh Jadhav"};
unsigned char b[]={"M.Sc.-2"};

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

void main()
{
	int i,j;

	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;

	IODIR0=0X000FF000;
	IODIR1=0X00300000;

	lcd_init();
		
		lcd_cmd(0x80);
		for(i=0;i<=13;i++)
		{
			lcd_data(a[i]);
			delay();
		}
		
		lcd_cmd(0xC0);
		for(j=0;j<=6;j++)
		{
			lcd_data(b[j]);
			delay();
		}
}