/*
 * ADC_drives.c
 *
 * Created: 16/07/2023 01:47:11 م
 *  Author: handsa
 */ 
#include "prog init.h"
#include "std_macros1.h"
void adc_init(void)
{
	set_bit(ADMUX,REFS0);
	set_bit(ADCSRA,ADEN);
	set_bit(ADCSRA,ADPS2);
set_bit(ADCSRA,ADPS1);
}
unsigned short adc_read(void)
{
	unsigned short read_val;
	set_bit(ADCSRA,ADSC);
	while(read_bit(ADCSRA,ADSC)==1);
	read_val=ADCL;
	read_val=read_val|(ADCH<<8);
	return read_val;
	
}