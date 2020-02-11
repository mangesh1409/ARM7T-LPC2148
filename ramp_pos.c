/**************************************************************************/
/* 	This Program is to demonstrate the DAC			                      */
/*  Board No: 7                                                           */
/*  Processor: LPC2148													  */
/*	P0.25:On Chip DAC Output		Positive Ramp							          */
/**************************************************************************/

#include<LPC214X.h>

void main()
{
	unsigned int dataout=0;
	PINSEL0=0x00000000;
	PINSEL1=0x00080000;

	while(1)
	{
		DACR=(dataout<<6);
		dataout++;

		if(dataout>1023)
		dataout=0;
	}
}
