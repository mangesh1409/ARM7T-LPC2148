/**************************************************************************/
/* 	This Program is to demonstrate the keypad/LCD Interfacing             */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	Keypad Mapping:P0.2  through P0.9									  */
/*	
/**************************************************************************/

#include<LPC214x.H>
#define bdel 10000
void disp_ssd(unsigned int val);
unsigned int
i=0,a[16]={0x0,0x070000,0x660000,0x060000,0x3F0000,0x7F0000,0x6D0000,0x5B0000,0x0,0x6F0000,0x7D0000,0x4F0000,0x0000,0x0,0x0000,0x00000};
void delay(unsigned int i);
void readkbd(void);

void readkbd(void)
{
while(1)
  {
    //First Row
	IOCLR0 = 0x00000004;
	IOSET0 = 0x00000038;
	if(!(IOPIN0 & (1<<6)))
	{
	  disp_ssd(a[0]);
	  break;
	}

	if(!(IOPIN0 & (1<<7)))
	{
	  disp_ssd(a[1]);
	  break;
	}

	if(!(IOPIN0 & (1<<8)))
	{
	  disp_ssd(a[2]);;
	  break;
	}

    if(!(IOPIN0 & (1<<9)))
	{
	  disp_ssd(a[3]);;
	  break;
	}

	//Second Row
  	/*IOCLR0 = 0x00000008;
  	IOSET0 = 0x00000034;

 		 if(!(IOPIN0 & (1<<6)))
	{
	  disp_ssd(a[4]);;
	  break;
	}

	if(!(IOPIN0 & (1<<7)))
	{
	  disp_ssd(a[5]);;
	  break;
	}

	if(!(IOPIN0 & (1<<8)))
	{
	  disp_ssd(a[6]);
	  break;
	}

	if(!(IOPIN0 & (1<<9)))
	{
	  disp_ssd(a[7]);
	  break;
	}

	//Third Row
  	IOCLR0 = 0x00000010;
  	IOSET0 = 0x0000002C;

  	if(!(IOPIN0 & (1<<6)))
	{
	  disp_ssd(a[8]);
	  break;
	}

	if(!(IOPIN0 & (1<<7)))
	{
	  disp_ssd(a[9]);
	  break;
	}

	if(!(IOPIN0 & (1<<8)))
	{
	  disp_ssd(a[10]);
	  break;
	}

	if(!(IOPIN0 & (1<<9)))
	{
	  disp_ssd(a[11]);
	  break;
	}

	//Forth Row
	IOCLR0 = 0x00000020;
    IOSET0 = 0x0000001C;

	if(!(IOPIN0 & (1<<6)))
	{
	  disp_ssd(a[12]);
	  break;
	}

	if(!(IOPIN0 & (1<<7)))
	{
	  disp_ssd(a[13]);
	  break;
	}

	 if(!(IOPIN0 & (1<<8)))
	{
	  disp_ssd(a[14]);
	  break;
	}

	if(!(IOPIN0 & (1<<9)))
	{
	  disp_ssd(a[15]);
	  break;
	}*/
  }
}

int main (void)
 {
    PINSEL1 = 0x00000000;
	PINSEL2 = 0x00;
	IODIR1 = 0x00FF0000;
    IODIR0 = 0x0000003C;
	disp_ssd(a[10]);
	readkbd( );
	while(1)
	{
	  delay(bdel*20);
	  readkbd();
    }
	return 0;
}

void delay(unsigned int i)
{
	long x=0;
	while(x!=i)
	{
		x++;
	}
	return;
}

void disp_ssd(unsigned int val)
{
	IOCLR1 = 0xFF0000;
	IOSET1 = val;
}
