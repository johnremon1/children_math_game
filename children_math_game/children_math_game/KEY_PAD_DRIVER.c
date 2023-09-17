/*
 * KEY_PAD_DRIVER.c
 *
 * Created: 8/16/2023 7:49:32 PM
 *  Author: john
 */
#include "KEY_PAD_DRIVER.h"
void Keypad_init()
{
	DIO_SetPinDir(PORT_NAME,0,1);
	DIO_SetPinDir(PORT_NAME,1,1);
	DIO_SetPinDir(PORT_NAME,2,1);
	DIO_SetPinDir(PORT_NAME,3,1);
	DIO_SetPinDir(PORT_NAME,4,0);
	DIO_SetPinDir(PORT_NAME,5,0);
	DIO_SetPinDir(PORT_NAME,6,0);
	DIO_SetPinDir(PORT_NAME,7,0);
	DIO_enable_pull_up(PORT_NAME,4,1);
	DIO_enable_pull_up(PORT_NAME,5,1);
	DIO_enable_pull_up(PORT_NAME,6,1);
	DIO_enable_pull_up(PORT_NAME,7,1);
}


char Keypad_u8check_press()
{
	#if defined PROTEUS_KEYPAD
  unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};	#elif defined REAL_KEYPAD   unsigned char arr[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};	#endif  unsigned char return_val=0xff;
  char x=1;
  for (unsigned char row=0;row<4;row++)
  {
	  DIO_Write(PORT_NAME,0,1);
	  DIO_Write(PORT_NAME,1,1);
	  DIO_Write(PORT_NAME,2,1);
	  DIO_Write(PORT_NAME,3,1);
	  DIO_Write(PORT_NAME,row,0);
	  for (unsigned char column=0;column<4;column++)
	  {
		  x=DIO_u8read(PORT_NAME,column+4);
		  if(x==0)
		  {
			return_val=arr[row][column];  
		    break;
		  }			  
	  }
	  if (x==0)
	  {
		  break;
	  } 
  }
	
	  return return_val;
}