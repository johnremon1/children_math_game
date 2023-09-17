/*
 * functions.c
 *
 * Created: 9/14/2023 3:04:20 PM
 *  Author: johnr
 */ 

#include "functions.h"

extern unsigned char simple_random_difficalty;
extern unsigned char simple_random_correct_answer;//if this variable is one then the answer in simple random mood was correct
extern unsigned char simple_random_score;
extern unsigned char simple_random_var;

void addition_mood()
{
	unsigned char difficalty_mood=0;
	if (simple_random_var>0)
	{
	  difficalty_mood=simple_random_difficalty;
	}
	else
	{
	 difficalty_mood=difficalty();
	}	
	unsigned char score=0;
	unsigned char position=0;
	unsigned char answer[6]={0,0,0,0,0,0};
	unsigned char keypad=0;
	unsigned short rang=0;
	unsigned short x=0;
	unsigned short y=0;
	unsigned long user_answer[6]={0};
	unsigned char take_action=1;
    unsigned char correct=0;
	unsigned char right_answer=1;	
	
while(1)
{
	position=0;
	if (simple_random_var==3)
	{
		simple_random();
		if (simple_random_correct_answer==0)
		{
			break;
		}
	}
	else if (simple_random_var==5)
	{
		complex_random();
		if (simple_random_correct_answer==0)
		{
			break;
		}
	}	
	
	if (right_answer==0)
	{
		break;
	}
	
	
	 if (take_action==1)
	 {
          for(char i=0;i<6;i++)
          {
	          user_answer[i]=0XFF;
			  answer[i]=0XFF;
          }

		  LCD_Clear_Screen();
		  LCD_Move_cursor(2,15);
		  LCD_Send_Char('O');
		  LCD_Send_Char('K');
		  LCD_Move_cursor(2,1);
		  LCD_String("delete");
		  write_the_score(score);
		
		 switch (difficalty_mood)
		 {
			 case 0:
			 rang=10;
			 while (1)
			 {
			 x=rand()%10;
			 y=rand()%10;
			 if ((x>0)&&(y>0))
			 {
				 break;
			 }
			 }			 
			 break;
			 
			 case 1:
			 rang=100;
			 x=rand()%100;
			 y=rand()%100;
			 break;
			 
			 case 2:
			 rang=1000;
			 x=rand()%1000;
			 y=rand()%1000;
			 break;
			 
			 case 3:
			 rang=10000;
			 x=rand()%10000;
			 y=rand()%10000;
			 break;
			 
			 case 4:
			 rang=65535;
			 while (1)
			 {
				 x=rand();
				 if(x<65535)
				 {
					 break;
				 }					 
			 }
			 while (1)
			 { 
				 y=rand();
				 if(y<65535)
				 {
					 break;
				 } 
			 }	
			 break;
		 }
		 LCD_Send_Cmd(RETURN_HOME);
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_ON);
		 LCD_send_short_number(x);
		 LCD_Send_Char('+');
		 LCD_send_short_number(y);
		 LCD_Send_Char('=');
		 if((x+y)<10)
		 {
		     answer[0]=(x+y);
			 answer[1]=0XFF;
			 answer[2]=0XFF;
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
		 }
		 else if ((x+y)<100)
		 {
			 answer[0]=((x+y)/10);
			 answer[1]=((x+y)%10);
			 answer[2]=0XFF;
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
		 }
		 else if ((x+y)<1000)
		 {
			 answer[0]=((x+y)/100);
			 answer[1]=((x+y)/10%10);
			 answer[2]=((x+y)%10);
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
			 
	     }
		 else if ((x+y)<10000)
		 {
			 answer[0]=((x+y)/1000);
			 answer[1]=((x+y)/100%10);
			 answer[2]=((x+y)/10%10);
			 answer[3]=((x+y)%10);
			 answer[4]=0XFF;
			 answer[5]=0XFF;
	     }
		 else if ((x+y)<100000)
		 {
		   answer[0]=((x+y)/10000);
		   answer[1]=((x+y)/1000%10);
		   answer[2]=((x+y)/100%10);
		   answer[3]=((x+y)/10%10);
		   answer[4]=((x+y)%10);
		   answer[5]=0XFF;
	     }
		 else
		 { 
			answer[0]=((x+y)/100000);
			answer[1]=((x+y)/10000%10);
			answer[2]=((x+y)/1000%10);
			answer[3]=((x+y)/100%10);
			answer[4]=((x+y)/10%10);
			answer[5]=((x+y)%10);
		 }
		 
		 take_action=0;
	}
	

   while(1)
   {
	   
	keypad=Keypad_u8check_press();
	if (keypad!=0xFF)
	{
		LCD_Send_Char(keypad);
		user_answer[position]=keypad-48;//this because keypad returns the asci code not the real number
		position++;
		if (position>=6)
		{
			position=5;
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
		}
		_delay_ms(250);
		
	}
	else if (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1)
	{
		if(position>0)
		{
			user_answer[position]=0XFF;
			LCD_Send_Char(' ');
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
			position--;
		}
		
		while (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1);
	}
	
	
	else if (Button_u8read(OUTPUT_PORT,OK_BUTTON)==1||Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1)
	{
		correct=0;
		for (int i=0;i<6;i++)
		{
			if (answer[i]!=user_answer[i])
			{
				correct=1;//you can increase it every wrong in the debug process
			}
		}
	 if (correct==0)
	 {
		 if (simple_random_var>0)
		 {
			 simple_random_correct_answer=1;
			 simple_random_var++;
		 }
		LCD_Clear_Screen();
		LCD_Move_cursor(1,3);
		LCD_String("right answer");
		LCD_Move_cursor(2,1) ;
		LCD_String("score=");
		if (simple_random_var>1)
		{
			simple_random_score++;
			LCD_send_char_number(simple_random_score);
			score=simple_random_score;
		}
		else
		{
			score++;
			LCD_send_char_number(score);
		}
		
		LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		_delay_ms(3000);
		take_action=1;
		 for(char i=0;i<6;i++)
		 {
			user_answer[i]=0XFF;
		 }
		break;
	 }
	 else if (correct==1)
	 {
		 if (simple_random_var>0)
		 {
			 simple_random_correct_answer=0;
			 simple_random_var++;
		 }
		 correct=0;
		 right_answer=0;
		 LCD_Clear_Screen();
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		 LCD_Move_cursor(1,3);
		 LCD_String("wrong answer");
		 _delay_ms(2000);
		 LCD_Clear_Screen();
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		 if (simple_random_var>0)
		 {
			 score=simple_random_score;
		 }

		 switch (rang)
		 {
			case 10 :
			if (score>EEPROM_u8Read(BEST_VERY_EASY_SCORE_LOCATION))
			{
				
				EEPROM_Write(BEST_VERY_EASY_SCORE_LOCATION,score);	
			}
			correct=1;				 
			break; 
			
			case 100 :
			if (score>EEPROM_u8Read(BEST_EASY_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_EASY_SCORE_LOCATION,score);
				
			}
			correct=2;
			break;
			
			case 1000 :
			if (score>EEPROM_u8Read(BEST_MEDIUM_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_MEDIUM_SCORE_LOCATION,score);
				
			}
			correct=3;
			break;
			
			case 10000 :
			if (score>EEPROM_u8Read(BEST_HARD_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_HARD_SCORE_LOCATION,score);
				
			}
			  correct=4;
			break;
			/*
			case 65535://the mathmatician mood
			if (score>EEPROM_u8Read(BEST_VERY_HARD_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_VERY_HARD_SCORE_LOCATION,score);
				
			}*/
			correct=5;
			break; 
		 }
			 LCD_Clear_Screen();
			 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
			 LCD_String("your score=");
			 LCD_send_char_number(score);
			 LCD_Move_cursor(2,1);
			 LCD_String("high score=");
			 LCD_send_char_number(EEPROM_u8Read(THE_NON_USED_LOCATION+correct));
			 _delay_ms(3000);
			 break;
	 }	
	}
	}	 
	
}
	
}

void subtraction_mood()
{
	unsigned char difficalty_mood=0;
	if (simple_random_var>0)
	{
	  difficalty_mood=simple_random_difficalty;
	}
	else
	{
	  difficalty_mood=difficalty();
	}	
	unsigned char score=0;
	unsigned char position=0;
	unsigned char answer[6]={0,0,0,0,0,0};
	unsigned char keypad=0;
	unsigned short rang=0;
	unsigned short x=0;
	unsigned short y=0;
	unsigned long user_answer[6]={0};
	unsigned char take_action=1;
    unsigned char correct=0;
	unsigned char right_answer=1;
		
	
while(1)
{
	position=0;
	if (right_answer==0)
	{
		break;
	}
	if (simple_random_var==3)
	{
		simple_random();
		if (simple_random_correct_answer==0)
		{
			break;
		}
	}
	else if (simple_random_var==5)
	{
		complex_random();
		if (simple_random_correct_answer==0)
		{
			break;
		}
	}
	
	 if (take_action==1)
	 {
          for(char i=0;i<6;i++)
          {
	          user_answer[i]=0XFF;
			  answer[i]=0XFF;
          }

		  LCD_Clear_Screen();
		  LCD_Move_cursor(2,15);
		  LCD_Send_Char('O');
		  LCD_Send_Char('K');
		  LCD_Move_cursor(2,1);
		  LCD_String("delete");
		  
		  write_the_score(score);
		
		 switch (difficalty_mood)
		 {
			 case 0:
			 rang=10;
			 while(1)
			 {
				 x=rand()%10;
			     y=rand()%10;
				 if (x>y)
				 {
					 break;
				 }
			 }
			 break;
			 
			 case 1:
			 rang=100;

			 while(1)
			 {	  
				 x=rand()%100;
			     y=rand()%100;
				 if (x>y)
				 {
					 break;
				 }
			 }
			 break;
			 
			 case 2:
			 rang=1000;
			 
			 while(1)
			 {
				 x=rand()%1000;
				 y=rand()%1000;
				 if (x>y)
				 {
					 break;
				 }
			 }
			 break;
			 
			 case 3:
			 rang=10000;
			
			 while(1)
			 { 
				 x=rand()%10000;
				 y=rand()%10000;
				 if (x>y)
				 {
					 break;
				 }
			 }
			 break;
			 
			 case 4:
			 rang=65535;
	
			 while(1)
			 {			
				  while (1)
			    {
				 x=rand();
				 if(x<65535)
				 {
					 break;
				 }					 
			    }
			    while (1)
			   { 
				 y=rand();
				 if(y<65535)
				 {
					 break;
				 } 
			   }
			if (x>y)
			 {
				break;
			 }
			 }
			 break;
		 }
		 LCD_Send_Cmd(RETURN_HOME);
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_ON);
		 LCD_send_short_number(x);
		 LCD_Send_Char('-');
		 LCD_send_short_number(y);
		 LCD_Send_Char('=');
		 if((x-y)<10)
		 {
		     answer[0]=(x-y);
			 answer[1]=0XFF;
			 answer[2]=0XFF;
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
		 }
		 else if ((x-y)<100)
		 {
			 answer[0]=((x-y)/10);
			 answer[1]=((x-y)%10);
			 answer[2]=0XFF;
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
		 }
		 else if ((x-y)<1000)
		 {
			 answer[0]=((x-y)/100);
			 answer[1]=((x-y)/10%10);
			 answer[2]=((x-y)%10);
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
			 
	     }
		 else if ((x-y)<10000)
		 {
			 answer[0]=((x-y)/1000);
			 answer[1]=((x-y)/100%10);
			 answer[2]=((x-y)/10%10);
			 answer[3]=((x-y)%10);
			 answer[4]=0XFF;
			 answer[5]=0XFF;
	     }
		 else if ((x-y)<100000)
		 {
		   answer[0]=((x-y)/10000);
		   answer[1]=((x-y)/1000%10);
		   answer[2]=((x-y)/100%10);
		   answer[3]=((x-y)/10%10);
		   answer[4]=((x-y)%10);
		   answer[5]=0XFF;
	     }
		 /*
		 else//this case is for if you used the mathmatician mood
		 {
			 answer[0]=((x-y)/100000);
			 answer[1]=((x-y)/10000%10);
			 answer[2]=((x-y)/1000%10);
			 answer[3]=((x-y)/100%10);
			 answer[4]=((x-y)/10%10);
			 answer[5]=((x-y)%10);
		 }
		 */
		 take_action=0;
	}
	

   while(1)
   {
	   
	keypad=Keypad_u8check_press();
	if (keypad!=0xFF)
	{
		LCD_Send_Char(keypad);
		user_answer[position]=keypad-48;//this because keypad returns the asci code not the real number
		position++;
		if (position>=6)
		{
			position=5;
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
		}
		_delay_ms(250);
		
	}
	else if (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1)
	{
		if(position>0)
		{
			user_answer[position]=0XFF;
			LCD_Send_Char(' ');
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
			position--;
		}
		
		while (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1);
	}
	
	
	else if (Button_u8read(OUTPUT_PORT,OK_BUTTON)==1||Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1)
	{
		correct=0;
		for (int i=0;i<6;i++)
		{
			if (answer[i]!=user_answer[i])
			{
				correct=1;//you can increase it every wrong in the debug process
			}
		}
	 if (correct==0)
	 {
		 
		 if (simple_random_var>0)
		 {
			 simple_random_correct_answer=1;
			 simple_random_var++;
		 }
		LCD_Clear_Screen();
		LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		LCD_Move_cursor(1,3);
		LCD_String("right answer");
		LCD_Move_cursor(2,1) ;
		LCD_String("score =");
		if (simple_random_var>1)
		{
			simple_random_score++;
			score=simple_random_score;
			LCD_send_char_number(simple_random_score);
			
		}
		else
		{
			score++;
			LCD_send_char_number(score);
		}
		LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		_delay_ms(3000);
		take_action=1;
		 for(char i=0;i<6;i++)
		 {
			user_answer[i]=0XFF;
		 }
		break;	 
	 }
	 else if (correct==1)
	 {
		 if (simple_random_var>0)
		 {
			 simple_random_correct_answer=0;
		 }
		 correct=0;
		 right_answer=0;
		 LCD_Clear_Screen();
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		 LCD_Move_cursor(1,3);
		 LCD_String("wrong answer");
		 _delay_ms(2000);
		 LCD_Clear_Screen();
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		 if (simple_random_var>0)
		 {
			 score=simple_random_score;
			 
		 }
		 switch (rang)
		 {
			case 10 :
			if (score>EEPROM_u8Read(BEST_VERY_EASY_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_VERY_EASY_SCORE_LOCATION,score);	
			}
			correct=1;				 
			break; 
			
			case 100 :
			if (score>EEPROM_u8Read(BEST_EASY_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_EASY_SCORE_LOCATION,score);
				
			}
			correct=2;
			break;
			
			case 1000 :
			if (score>EEPROM_u8Read(BEST_MEDIUM_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_MEDIUM_SCORE_LOCATION,score);
				
			}
			correct=3;
			break;
			
			case 10000 :
			if (score>EEPROM_u8Read(BEST_HARD_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_HARD_SCORE_LOCATION,score);
				
			}
			  correct=4;
			break;
			/*
			case 65535://the mathmatician mood
			if (score>EEPROM_u8Read(BEST_VERY_HARD_SCORE_LOCATION))
			{
				EEPROM_Write(BEST_VERY_HARD_SCORE_LOCATION,score);
				
			}*/
			correct=5;
			break; 
		 }
			 LCD_Clear_Screen();
			 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
			 LCD_String("your score=");
			 LCD_send_char_number(score);
			 LCD_Move_cursor(2,1);
			 LCD_String("high score=");
			 LCD_send_char_number(EEPROM_u8Read(THE_NON_USED_LOCATION+correct));
			 _delay_ms(3000);
			 break;
	 }	
	}
	}	 
}	
}


void multiplication_mood()
{
	//unsigned char difficalty_mood=difficalty();
	unsigned char score=0;
	unsigned char position=0;
	unsigned char answer[6]={0,0,0,0,0,0};
	unsigned char keypad=0;
	unsigned short x=0;
	unsigned short y=0;
	unsigned long user_answer[6]={0};
	unsigned char take_action=1;
    unsigned char correct=0;
	unsigned char right_answer=1;
while(1)
{
	position=0;
	
		if (simple_random_var==3)
		{
			simple_random();
			if (simple_random_correct_answer==0)
			{
				break;
			}
		}
		else if (simple_random_var==5)
		{
			complex_random();
			if (simple_random_correct_answer==0)
			{
				break;
			}
		}
	if (right_answer==0)
	{
		break;
	}
	
	 if (take_action==1)
	 {
          for(char i=0;i<6;i++)
          {
	          user_answer[i]=0XFF;
			  answer[i]=0XFF;
          }

		  LCD_Clear_Screen();
		  LCD_Move_cursor(2,15);
		  LCD_Send_Char('O');
		  LCD_Send_Char('K');
		  LCD_Move_cursor(2,1);
		  LCD_String("delete");
		  
		  write_the_score(score);
		  
		  while (1)
		  {
			  x=rand()%100;
			  if (x<=12&&x!=0)
			  {
				  break;
			  }				  
		  }
		  while(1)
		  {
			  y=rand()%100;
			  if (y<=12&&y!=0)
			  {
				  break;
			  }	  
		  }
		  
		 LCD_Send_Cmd(RETURN_HOME);
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_ON);
		 LCD_send_short_number(x);
		 LCD_Send_Char('*');
		 LCD_send_short_number(y);
		 LCD_Send_Char('=');
		 if((x*y)<10)
		 {
		     answer[0]=(x*y);
			 answer[1]=0XFF;
			 answer[2]=0XFF;
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
		 }
		 else if ((x*y)<100)
		 {
			 answer[0]=((x*y)/10);
			 answer[1]=((x*y)%10);
			 answer[2]=0XFF;
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
		 }
		 else if ((x*y)<1000)
		 {
			 answer[0]=((x*y)/100);
			 answer[1]=((x*y)/10%10);
			 answer[2]=((x*y)%10);
			 answer[3]=0XFF;
			 answer[4]=0XFF;
			 answer[5]=0XFF;
			 
	     }
		 take_action=0;
	}
	

   while(1)
   {
	   
	keypad=Keypad_u8check_press();
	if (keypad!=0xFF)
	{
		LCD_Send_Char(keypad);
		user_answer[position]=keypad-48;//this because keypad returns the asci code not the real number
		position++;
		if (position>=6)
		{
			position=5;
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
		}
		_delay_ms(250);
		
	}
	else if (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1)
	{
		if(position>0)
		{
			user_answer[position]=0XFF;
			LCD_Send_Char(' ');
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
			LCD_Send_Cmd(SHIFT_CURSOR_LEFT);
			position--;
		}
		
		while (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1);
	}
	
	
	else if (Button_u8read(OUTPUT_PORT,OK_BUTTON)==1||Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1)
	{
		correct=0;
		for (int i=0;i<6;i++)
		{
			if (answer[i]!=user_answer[i])
			{
				correct=1;//you can increase it every wrong in the debug process
			}
		}
	 if (correct==0)
	 {
		 if (simple_random_var>0)
		 {
			 simple_random_correct_answer=1;
			 simple_random_var++;
		 }
		LCD_Clear_Screen();
		LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		LCD_Move_cursor(1,3);
		LCD_String("right answer");
		LCD_Move_cursor(2,1) ;
		LCD_String("score =");
		if (simple_random_var>1)
		{
			simple_random_score++;
			score=simple_random_score;
			LCD_send_char_number(simple_random_score);
			
		}
		else
		{
			score++;
			LCD_send_char_number(score);
		}
		LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		_delay_ms(3000);
		take_action=1;
		 for(char i=0;i<6;i++)
		 {
			user_answer[i]=0XFF;
		 }
		break;	 
	 }
	 else if (correct==1)
	 {
		 if (simple_random_var>0)
		 {
			 simple_random_correct_answer=0;
			 score=simple_random_score;
		 }
		 correct=0;
		 right_answer=0;
		 LCD_Clear_Screen();
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		 LCD_Move_cursor(1,3);
		 LCD_String("wrong answer");
		 _delay_ms(2000);
		 LCD_Clear_Screen();
		 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		 if(score>EEPROM_u8Read(MULTIPLICATION_SCORE_LOCATION))
		 {
			 EEPROM_Write(MULTIPLICATION_SCORE_LOCATION,score);
		 }
			 LCD_Clear_Screen();
			 LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
			 LCD_String("your score=");
			 LCD_send_char_number(score);
			 LCD_Move_cursor(2,1);
			 LCD_String("high score=");
			 LCD_send_char_number(EEPROM_u8Read(MULTIPLICATION_SCORE_LOCATION));
			 _delay_ms(3000);
			 break;
	 }	
	}
	}	 
}	
}


void simple_random()
{
unsigned short dice=0;

while(1)
{
	if (simple_random_correct_answer==0)
	{
		break;
	}
	
	if (simple_random_var==1)
	{
		simple_random_difficalty=difficalty();
		simple_random_score=0;
	}
	simple_random_var=2;
    dice=rand();
	if ((dice%2)==0)
	{
		subtraction_mood();
	}
	else if ((dice%2)==1)
	{
		addition_mood();
	}
}
}

void complex_random()
{
      unsigned char dice=0;

	while(1)
	{
		if (simple_random_correct_answer==0)
		{
			break;
		}
		
		if (simple_random_var==1)
		{
			simple_random_difficalty=difficalty();
			simple_random_score=0;
		}
		simple_random_var=4;
		dice=rand();
		if ((dice%3)==0)
		{
			subtraction_mood();
		}
		else if ((dice%3)==1)
		{
			
			multiplication_mood();
		}
		else if ((dice%3)==2)
		{
			addition_mood();
		}
		
		
	}
}






unsigned char difficalty() //this function return 0 for very easy and 1 for easy and 2 for medium and 3 for hard and 4 for Mathematician
{
	unsigned char enbable=1;
	unsigned char position=0;//this variable is an indication for the position of the user on the lcd choices
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
				LCD_String("very easy");
			}
			else if (position==1)
			{
				LCD_Move_cursor(1,6);
				LCD_String("easy");
			}
			else if (position==2)
			{
				LCD_Move_cursor(1,5);
				LCD_String("medium");
			}
			else if (position==3)
			{
				LCD_Move_cursor(1,6);
				LCD_String("hard");
			}
			/*else if (position==4)
			{
				LCD_Move_cursor(1,1);
				LCD_String("Mathematician");
			}*/
           
			enbable=0;
			LCD_Send_Cmd(DISPLAY_ON_CURSOR_OFF);
		}
		
		if (Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1)
		{
			if (position>=3)
			{
				position=0;
			}
			else
			{
				position++;
			}
			while(Button_u8read(OUTPUT_PORT,RIGHT_BUTTON)==1);
			enbable=1;
		}
		else if (Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1)
		{
			if (position==0)
			{
				//position=4;//disable this if you closed the mathmatician mood
				position=3;
			}
			else
			{
				position--;
			}
			while(Button_u8read(OUTPUT_PORT,LEFT_BUTTON)==1);
			enbable=1;
		}
		else if (Button_u8read(OUTPUT_PORT,OK_BUTTON)==1)
		{
			while(Button_u8read(OUTPUT_PORT,OK_BUTTON)==1);
			return position;
			
		}

	}

}


void write_the_score(unsigned char score)
{
	if (simple_random_var>0)
	{
	LCD_Move_cursor(2,8);
	LCD_Send_Char('(');
	LCD_send_char_number(simple_random_score);
	LCD_Send_Char(')');
	}
	else
	{
	LCD_Move_cursor(2,8);
	LCD_Send_Char('(');
	LCD_send_char_number(score);
	LCD_Send_Char(')');
	}	

}



void DEBUG()
{
	LCD_Move_cursor(2,8);
	LCD_String("DEBUG");
	_delay_ms(2000);
}