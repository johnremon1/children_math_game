/*
 * EEPROM_DRIVER.c
 *
 * Created: 8/6/2023 4:59:31 PM
 *  Author: john
 */ 
#include <avr/io.h>
#include "STD_MACROS1.h"

void EEPROM_Write(unsigned short adress,unsigned char data)
{
	EEAR=adress;// writing the adress in the eeprom adress resgister
	EEDR=data;//writing the data in the eeprom data register 
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while((read_bit(EECR,EEWE))==1);//waiting until the writing end and the writing endes only when the bit EEWE became zero not 1	
}

unsigned char EEPROM_u8Read(unsigned short adress)
{
	EEAR=adress;
	set_bit(EECR,EERE);
	return EEDR;
}