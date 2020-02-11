/**************************************************************************/
/* 	This Program is to demonstrate the UART Functionality                 */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/**************************************************************************/

#include<LPC214X.h>

void delay()
{
	int i;
	for(i=0;i<=500000;i++);																																																																																																																																			
}

unsigned char a[]={"Fergusson College,Pune"};

void init_uart(void)
{
	PINSEL0=0X00000005;		//enable TxD0 and RxD0
	U0LCR=0X00000083;	    //8 bits,no parity,1 stop bit
	U0DLL=0X000000C2;	    //baud rate 9600
	U0LCR=0X00000003;		//DLAB=0
}

int send_char(char x)		//write character to serial port
{
	while(!(U0LSR&0x20));
	return(U0THR=x);
}

void main()
{
 int i;
 VPBDIV=0X00000002;			//set up peripheral clock for 30MHz

 init_uart();

 for(i=0;i<=21;i++)
 	{
		send_char(a[i]);
		delay();
	}
}