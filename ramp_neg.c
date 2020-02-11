/**************************************************************************/
/* 	This Program is to demonstrate the DAC			                      */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	P0.25:On Chip DAC Output		Negative Ramp						  */
/**************************************************************************/

#include<LPC214X.h>

void main()
{
	unsigned int dataout=1023;
	PINSEL0=0x00000000;
	PINSEL1=0x00080000;

	while(1)
	{
		DACR=(dataout<<6);
		dataout--;

		if(dataout<0)
		dataout=1023;
	}
}
