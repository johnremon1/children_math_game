/*
 * LCD_DRIVER.h
 *
 * Created: 8/13/2023 8:39:31 PM
 *  Author: johnr
 */ 

// important note you must include LCD_COMFIG.h and go into it and edit it so you can use the mode and the pins you want 
#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
#include "LCD_CONFIG.h"
#include "DIO_DRIVER.h"


#if defined(FOUR_BITS_MODE_HIGH_NIBBLE)
#define FOUR_BITS 0x28
#elif defined(FOUR_BITS_MODE_LOW_NIBBLE)
#define FOUR_BITS 0x28
#elif defined(EIGHT_BITS_MODE)
#define EIGHT_BITS 0x38
#endif



#define CLEAR_SCREEN 0X01
#define DISPLAY_OFF_CURSOR_OFF 0X08
#define DISPLAY_OFF_CURSOR_ON  0X0A
#define DISPLAY_ON_CURSOR_OFF 0X0C
#define DISPLAY_ON_CURSOR_ON 0X0E
#define DISPLAY_ON_CURSOR_BLINKING 0X0F
#define RETURN_HOME 0X02
#define ENTRY_MODE 0X06
#define DISPLAY_SHIFT_RIGHT 0X1C
#define DISPLAY_SHIFT_LEFT 0X18
#define SHIFT_CURSOR_RIGHT 0X14
#define SHIFT_CURSOR_LEFT 0X10
 
 
 
 /*
 Function name   : LCD_init
 Function return : void
 Function Arguments : void
 Function description : this function do a lot of tasks first make the pins as output pins and then choose eight mode or four mode from 
 LCD_CONFIG.h and then clear the screen and return home and active the entry mode 
 */
void LCD_init(void);



 /*
 Function name   : LCD_Send_Cmd
 Function return : void
 Function Arguments : the command you want to send 
 Function description :this function receives the command you want the lcd to execute and you must send the command as an hex or a macro that is defined 
 in this file LCD_DRIVER.h   
 */
void LCD_Send_Cmd(unsigned char cmd);

 /*
 Function name   : enable 
 Function return : void
 Function Arguments : void
 Function description : this function send a rising edge on the enable pin and wait for 3 MS and the nsend a falling edge so the enable is activated
 */
 void enable();


 /*
 Function name   : LCD_Send_Char
 Function return : void
 Function Arguments : data (the asci of the character)
 Function description : this function only takes the asci code of the character syou sent and send i the lcd and send the 
 proper commands to execute the it and make it aopear on the screen unless you oredered to make the display off
 */
void LCD_Send_Char(unsigned char data);


 /*
 Function name   : LCD_String
 Function return : void
 Function Arguments : char *ptr
 Function description : this function receives the string that is stored in the .rodata in a pointer and send it to the LCD 
 */
void LCD_String(char *ptr);


 /*
 Function name   : LCD_Clear_Screen
 Function return : void
 Function Arguments : void
 Function description : this function send the command to clear the screen and wait for 5 MS
 */
void LCD_Clear_Screen();


 /*
 Function name   : LCD_Move_cursor
 Function return : void
 Function Arguments : void
 Function description : this function moves the cursotr to the exact row and column you choosed make sure to choose a row 1 or row 2 and collumns between (1-16)
 */
void LCD_Move_cursor(unsigned char row,unsigned char column);



 /*
 Function name   : LCD_send_char_number
 Function return : unsigned char number
 Function Arguments : void
 Function description : this function recieve the char number and write it on the lcd
 */
void LCD_send_char_number(unsigned char number);

 /*
 Function name   : LCD_send_char_number
 Function return : unsigned char number
 Function Arguments : void
 Function description : this function recieve the short number and write it on the lcd
 */
void LCD_send_short_number(unsigned short number);





#endif /* LCD_DRIVER_H_ */