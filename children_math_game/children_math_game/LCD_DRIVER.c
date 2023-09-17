/*
 * LCD_DRIVER.c
 *
 * Created: 8/13/2023 8:33:31 PM
 *  Author: john
 */ 

#include "LCD_DRIVER.h"

#define F_CPU 8000000UL
#include <util/delay.h>


void LCD_init(void)
{
	#if defined EIGHT_BITS_MODE
	_delay_ms(200);
	DIO_Set_Port_Direction(DATA_PORT,0XFF);
	DIO_SetPinDir(CONTROL_PORT,EN,1);
	DIO_SetPinDir(CONTROL_PORT,RW,1);
	DIO_SetPinDir(CONTROL_PORT,RS,1);
	
	LCD_Send_Cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_Send_Cmd(CURSOR_ON_DISPLAY_ON);//display on cursor on
	_delay_ms(1);
	LCD_Send_Cmd(CLEAR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_Send_Cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);	
	
	#elif defined FOUR_BITS_MODE_HIGH_NIBBLE
    _delay_ms(200);	
	DIO_Set_Port_Direction(DATA_PORT,0XF0);
	DIO_SetPinDir(CONTROL_PORT,EN,1);
	DIO_SetPinDir(CONTROL_PORT,RW,1);
    DIO_SetPinDir(CONTROL_PORT,RS,1);
	
	LCD_Send_Cmd(RETURN_HOME);
	_delay_ms(5);
	LCD_Send_Cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_Send_Cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_Send_Cmd(CLEAR_SCREEN);
	_delay_ms(5);
	LCD_Send_Cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined FOUR_BITS_MODE_LOW_NIBBLE
	_delay_ms(200);
	 DIO_Set_Port_Direction(DATA_PORT,0X0F);
	 DIO_SetPinDir(CONTROL_PORT,EN,1);
	// DIO_SetPinDir(CONTROL_PORT,RW,1);
	 DIO_SetPinDir(CONTROL_PORT,RS,1);
	 
	 LCD_Send_Cmd(RETURN_HOME);
	 _delay_ms(5);
	 LCD_Send_Cmd(FOUR_BITS);
	 _delay_ms(1);
	 LCD_Send_Cmd(DISPLAY_ON_CURSOR_ON);
	 _delay_ms(1);
	 LCD_Send_Cmd(CLEAR_SCREEN);
	 _delay_ms(5);
	 LCD_Send_Cmd(ENTRY_MODE);
	 _delay_ms(1);
	 
	#endif
		
	
}





void LCD_Send_Cmd(unsigned char cmd)
{
	#if defined EIGHT_BITS_MODE
	
		  DIO_Write(CONTROL_PORT,RS,0);
	      DIO_Write_Port(DATA_PORT,cmd);
	      enable();
	     _delay_ms(1);
		 
    #elif defined FOUR_BITS_MODE_HIGH_NIBBLE

		  DIO_Write_high_nibble(DATA_PORT,cmd>>4);
		  DIO_Write(CONTROL_PORT,RS,0);
		  enable();
		  _delay_ms(1);
		  DIO_Write_high_nibble(DATA_PORT,cmd);
		  enable();
		  _delay_ms(1);
		  
	#elif  defined FOUR_BITS_MODE_LOW_NIBBLE
	
		  DIO_Write_low_nibble(DATA_PORT,cmd>>4);
		  DIO_Write(CONTROL_PORT,RS,0);
		  enable();
		  _delay_ms(1);
		  DIO_Write_low_nibble(DATA_PORT,cmd);
		  enable();
		  _delay_ms(1);
		  
	#endif
	   
}



 void enable()
{
	DIO_Write(CONTROL_PORT,EN,1);
	_delay_ms(3);
	DIO_Write(CONTROL_PORT,EN,0);
}



void LCD_Send_Char(unsigned char data)
{
	#if defined EIGHT_BITS_MODE
	    DIO_Write(CONTROL_PORT,RS,1);
	    DIO_Write_Port(DATA_PORT,data);
	    enable();
	    _delay_ms(1);
	#elif defined FOUR_BITS_MODE_HIGH_NIBBLE
	     DIO_Write(CONTROL_PORT,RS,1);
		 DIO_Write_high_nibble(DATA_PORT,data>>4);
		 enable();
		 DIO_Write_high_nibble(DATA_PORT,data);
		 enable();
		 _delay_ms(1);
	#elif defined FOUR_BITS_MODE_LOW_NIBBLE
	     DIO_Write(CONTROL_PORT,RS,1);
		 DIO_Write_low_nibble(DATA_PORT,data>>4);
		 enable();
		 DIO_Write_low_nibble(DATA_PORT,data);
		 enable();
		 _delay_ms(1);
	#endif
	   
}

void LCD_send_short_number(unsigned short number)
{
	if (number<10)
	{
		LCD_Send_Char(number+48);
	}
	else if (number<100)
	{
		LCD_Send_Char((number/10)+48);
		LCD_Send_Char((number%10)+48);
	}
	else if (number<1000)
	{
		LCD_Send_Char((number/100)+48);
		LCD_Send_Char((number/10%10)+48);
		LCD_Send_Char((number%10)+48);	
	}
	else if (number<10000)
	{
		LCD_Send_Char((number/1000)+48);
		LCD_Send_Char((number/100%10)+48);
		LCD_Send_Char((number/10%10)+48);
		LCD_Send_Char((number%10)+48);	
	}
	else if (number<65536)
	{
		LCD_Send_Char((number/10000)+48);
		LCD_Send_Char((number/1000%10)+48);
		LCD_Send_Char((number/100%10)+48);
		LCD_Send_Char((number/10%10)+48);
		LCD_Send_Char((number%10)+48);
		
	}
	

}

void LCD_send_char_number(unsigned char number)
{
		if (number<10)
		{
			LCD_Send_Char(number+48);
		}
		else if (number<100)
		{
			LCD_Send_Char((number/10)+48);
			LCD_Send_Char((number%10)+48);
		}
		else if (number<256)
		{
			LCD_Send_Char((number/100)+48);
			LCD_Send_Char((number/10%10)+48);
			LCD_Send_Char((number%10)+48);
		}
}


void LCD_String(char *ptr)
{
	while((*ptr)!='\0')
	{
		LCD_Send_Char(*ptr);
		ptr++;
	
	}
}



void LCD_Clear_Screen()
{
	LCD_Send_Cmd(CLEAR_SCREEN);
	_delay_ms(10);
}



void LCD_Move_cursor(unsigned char row,unsigned char column)
{
	char data=0; 
	if ((row<1)||(row>2)||(column<1)||(column>16))
	{
		data=0x08;
	}
	if (row==1)
	{
		data=0X80+column-1;
	}
	if(row==2)
	{
		data=0XC0+column-1;
	}
	LCD_Send_Cmd(data);
}


void LCD_Return_Home()
{
	LCD_Send_Cmd(RETURN_HOME);
}


void LCD_JENO_BRAND()
{
	LCD_Send_Cmd(64);
	 LCD_Send_Char(0B11111);//the up of (J)
	 LCD_Send_Char(0B11111);
	 LCD_Send_Char(0B00011);
	 LCD_Send_Char(0B00011);
	 LCD_Send_Char(0B00011);
	 LCD_Send_Char(0B00011);
	 LCD_Send_Char(0B00011);
	 LCD_Send_Char(0B00011);
	 
	 
	  LCD_Send_Char(0B00011);//the down of the (J)
	  LCD_Send_Char(0B00011);
	  LCD_Send_Char(0B00011);
	  LCD_Send_Char(0B00011);
	  LCD_Send_Char(0B10011);
	  LCD_Send_Char(0B10011);
	  LCD_Send_Char(0B11111);
	  LCD_Send_Char(0B11111);
	
		 
	
	 LCD_Send_Char(0B11111);//the up of the (E)
	 LCD_Send_Char(0B11111);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B11111);
	 
	 LCD_Send_Char(0B11111);
	 LCD_Send_Char(0B11111);//the down of the (E)
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B10000);
	 LCD_Send_Char(0B11111);
	 LCD_Send_Char(0B11111);
	 

	 LCD_Send_Char(0B10001);//the up of (N)
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B11001);
	 LCD_Send_Char(0B11001);
	 LCD_Send_Char(0B11001);
	 LCD_Send_Char(0B10101);
	 LCD_Send_Char(0B10101);
	 LCD_Send_Char(0B10101);
	  
	  
	 LCD_Send_Char(0B10101);//the down of the (N)
	 LCD_Send_Char(0B10101);
	 LCD_Send_Char(0B10101);
	 LCD_Send_Char(0B10011);
	 LCD_Send_Char(0B10011);
	 LCD_Send_Char(0B10011);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 
	 LCD_Send_Char(0B11111);//the up of the (O)
	 LCD_Send_Char(0B11111);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 
	 
	 LCD_Send_Char(0B10001);//the down of the (O)
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B10001);
	 LCD_Send_Char(0B11111);
	 LCD_Send_Char(0B11111); 
	 
	 
	 LCD_Move_cursor(1,7);
	 LCD_Send_Char(0);
	 LCD_Move_cursor(2,7);
	 LCD_Send_Char(1);
	 LCD_Move_cursor(1,8);
	 LCD_Send_Char(2);
	 LCD_Move_cursor(2,8);
	 LCD_Send_Char(3);
	 LCD_Move_cursor(1,9);
	 LCD_Send_Char(4);
	 LCD_Move_cursor(2,9);
	 LCD_Send_Char(5);
	 LCD_Move_cursor(1,10);
	 LCD_Send_Char(6);
	 LCD_Move_cursor(2,10); 
	 LCD_Send_Char(7);  

}