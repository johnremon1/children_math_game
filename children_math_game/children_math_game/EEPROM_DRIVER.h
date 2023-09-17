/*
 * EEPROM_DRIVER.h
 *
 * Created: 8/6/2023 5:10:26 PM
 *  Author: john
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_



/*
Function name   : DIO_SetPinDir
Function return : void
Function Arguments : unsigned short adress,unsigned char data
Function description : this function write on the eeprom and making sure that the writing has completed 
*/
void EEPROM_Write(unsigned short adress,unsigned char data);



/*
Function name   : EEPROM_Read
Function return : unsigned char
Function Arguments : unsigned short adress
Function description : this function reads the content from the adress you sent and return the data as an unsigned char 
not that the return value is unsigned char  
*/
unsigned char EEPROM_u8Read(unsigned short adress);




#endif /* EEPROM_DRIVER_H_ */