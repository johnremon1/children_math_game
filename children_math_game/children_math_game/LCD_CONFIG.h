/*
 * LCD_CONFIG.h
 *
 * Created: 8/13/2023 9:44:37 PM
 *  Author: johnr
 */


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_





#define DATA_PORT 'C' //choose the data port that the data pins will be on it you can choose ('A','B','C','D')

#define CONTROL_PORT 'C'//choose the port that the enable pin and the register select pin will be on it you can choose between ('A','B','C','D')

#define EN 4 //the enable pin that will be triggered very command make sure that the pin is not used in the data pins


#define RS 5//the register select pin that will choose the register that will receive on the data lines on the lcd (data,instructions)


#define FOUR_BITS_MODE_LOW_NIBBLE
/*you must choose on mode
#define EIGHT_BITS_MODE
OR
#define FOUR_BITS_MODE_HIGH_NIBBLE
OR
#define FOUR_BITS_MODE_LOW_NIBBLE
and by choosing one mode you choosing the what you will communicate with the LCD
*/

/*
HIGH_NIBBLE OR LOW_NIBBLE
if you choose to use the four bits mood you must choose the pins you will use to communicate with the lcd

#define LCD_high_nibble  by choosing this you choose the pins 4,5,6,7 on the selected data port
OR
#define LCD_low_nibble  by choosing this you choose the pins 0,1,2,3 on the selected data port

make sure to choose one
*/






#endif /* LCD_CONFIG_H_ */
