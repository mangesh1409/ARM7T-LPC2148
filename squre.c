/**************************************************************************/
/* 	This Program is to demonstrate the DAC Functionality                  */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	P0.25:On Chip DAC Output		Squre Wave							  */
/**************************************************************************/

#include<LPC214X.h>

void main()
{
	unsigned val;
	unsigned dataout;
	PINSEL0=0x00000000;
	PINSEL1=0x00080000;

	while(1)
	{
		dataout=0;
		DACR=(dataout<<6);

		for(val=0;val<0x00000010;val++);
			
				dataout=0x0000FFC0;
				DACR=(dataout<<6);
			
		for(val=0;val<0x00000010;val++);
	}
}