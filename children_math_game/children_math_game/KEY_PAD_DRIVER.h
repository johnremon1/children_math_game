/*
 * KEY_PAD_DRIVER.h
 *
 * Created: 8/16/2023 7:51:06 PM
 *  Author: johnr
 */ 


#ifndef KEY_PAD_DRIVER_H_
#define KEY_PAD_DRIVER_H_
#include "DIO_DRIVER.h"

#define PORT_NAME 'B'

#define PROTEUS_KEYPAD
/*you can choose the proteus_keypad OR REAL_KEYPAD
#defined PROTEUS_KEYPAD
unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};4OR#defined REAL_KEYPADunsigned char arr[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};*/  



/*
Function name   : Keypad_init
Function return :  void
Function Arguments : void
Function description : this function only initiate the key pad so it make the first four pins is output pins and the second four pins 
is an input pins and activate the pull up resistance on the three input pins 
*/
void Keypad_init();


/*
Function name   : Keypad_u8check_press
Function return :  char
Function Arguments : void
Function description : this function loops on the the buttons on the key pad and check if ant button is pressed and if any button is pressed it 
sends the ASCI code for the chosen one number and returns 0XFF if not any button is pressed 
*/
char Keypad_u8check_press();






#endif /* KEY_PAD_DRIVER_H_ */