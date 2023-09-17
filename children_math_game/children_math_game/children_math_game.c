/*
 * children_math_game.c
 *
 * Created: 9/10/2023 3:21:40 PM
 *  Author: johnr
 */ 


#include "functions.h"


unsigned char simple_random_var=0;
unsigned char countner=0;
unsigned char simple_random_difficalty=0;
unsigned char simple_random_correct_answer=1;//if this variable is one then the answer in simple random mood was correct
unsigned char simple_random_score=0;





  
int main(void)
{
	LCD_init();
	Keypad_init();
	Timer_CTC_interrupt_enable();
    Button_vinit(OUTPUT_PORT,RIGHT_BUTTON);
	Button_vinit(OUTPUT_PORT,OK_BUTTON);
	Button_vinit(OUTPUT_PORT,LEFT_BUTTON);
	Led_vinit(OUTPUT_PORT,GREEN_LED);
	Led_vinit(OUTPUT_PORT,RED_LED);
	LCD_Send_Cmd(DISPLAY_OFF_CURSOR_OFF);
	LCD_Move_cursor(1,4);
	LCD_String("CHILDREN");
	LCD_Move_cursor(2,6);
	LCD_String("MATH");
	LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(3000);	
	LCD_Clear_Screen();

	/*for (unsigned char i=0;i<5;i++)
	{
		EEPROM_Write(BEST_VERY_EASY_SCORE_LOCATION+i,0);
	}*/
	unsigned char enbable=1;//this varible is taking action in the loop


    while(1)
    {
		unsigned char position=0;//this varible is an indiction for the position of the user on the lcd choises
	    while(1)
		{
            
		  if (enbable==1)
		   {
			   LCD_Clear_Screen();
			   LCD_Send_Cmd(DISPLAY_OFF_CURSOR_OFF);
			   LCD_Move_cursor(2,1);
			   LCD_Send_Char('<');
			   LCD_Move_cursor(2,8);
			   LCD_Send_Char('O');
			   LCD_Send_Char('K');
			   LCD_Move_cursor(2,16);
			   LCD_Send_Char('>');
			 if (position==0)
			 {
				LCD_Move_cursor(1,4);
				LCD_String("Addition");
			 }
			 else if (position==1)
			 {
			    LCD_Move_cursor(1,3);
				LCD_String("subtraction");
			 }
			 else if (position==2)
			 {
			    LCD_Move_cursor(1,2);
				LCD_String("multiplication");
			 }
			 /*else if (position==3)
			 {
				 LCD_Move_cursor(1,5);
				 LCD_String("division");
			 }
			 */
			 
			 else if (position==3)
			 {
				 LCD_Move_cursor(1,1);
				 LCD_String("simple random");
			 }
			 else if (position==4)
			 {
				 LCD_Move_cursor(1,1);
				 LCD_String("complex random");
			 }
			 enbable=0;
			 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		   }			
		 
		 if (Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1)
		 {
			 if (position>=4)
			 {
				 position=0;
			 }
			 else
			 {
			 position++ ;
			 }
			 enbable=1;	
			 while(Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1);	 
		 }	
		 else if (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1)
		 {
			 if (position==0)
			 {
				position=4; 
			 }	
			 else
			 {
				position--; 			 
		     }
			 enbable=1;
			 while(Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1);	
		}
		else if (Button_u8read(OUTPUT_PORT,OK_BUTTON)==1)
		{
			
			enbable=1;
			break;
		}						
		}
		while(Button_u8read(OUTPUT_PORT,OK_BUTTON)==1);
		switch (position)
		{
			case 0:
			 simple_random_var=0;
			 addition_mood();
			break;
			
			case 1:
			 simple_random_var=0;
			 subtraction_mood();
			break;
			
			case 2:
			 simple_random_var=0;
			 multiplication_mood();
			break;
			
			case 3:
			  simple_random_var=1;
			  simple_random_correct_answer=1;
			  simple_random();
			break;
			
			case 4:
			 simple_random_var=1;
             simple_random_difficalty=0;
             simple_random_correct_answer=1;//if this variable is one then the answer in simple random mood was correct
             simple_random_score=0;
			 complex_random();
			break;

		}
					
    }
}


ISR(TIMER0_COMP_vect)
{
	countner++;
}


