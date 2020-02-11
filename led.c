/**************************************************************************/
/* 	This Program is to demonstrate the LED Interfacing                    */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	LED Connection:P0.12-P0.19										      */
/*  Jumper Setting : SW20: towards LED_ON 	SW21:away from LCD_ON 		  */
/**************************************************************************/


#include<LPC214X.h>
void delay();

void delay()
{
	int i;
	for(i=0;i<=500000;i++);																																																																																																																																			
}

void main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	IODIR0=0x000FF000;			   //LED connected to P0.12-P0.19

	while(1)
	{
		IOSET0=0x000AA000;		  //Turn ON LED'S
		delay();
		IOCLR0=0x000AA000;
		delay();
		IOSET0=0x00055000;		  //Turn OFF LED's
		delay();
		IOCLR0=0x00055000;
		delay();
	}
} 

