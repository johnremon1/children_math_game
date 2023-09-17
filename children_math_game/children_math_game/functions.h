/*
 * functions.h
 *
 * Created: 9/12/2023 2:30:29 PM
 *  Author: johnr
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD_CONFIG.h"
#include "LCD_DRIVER.h"
#include "KEY_PAD_DRIVER.h"
#include "LED_DRIVER.h"
#include "PUSH_BUTTON.h"
#include "EEPROM_DRIVER.h"
#include "TIMER_DRIVER.h"
#include <avr/interrupt.h>
#include <stdio.h>

#include <avr/io.h>


#define THE_NON_USED_LOCATION 0X30 //THIS LOCTION BECAUSE WE CAN NOT ADD ZERO AT LEAST WE CAN ADD ONE SO WHEN WE ADD 1 WE HAVE BEST_VERY_EASY_SCORE_LOCATION AND SO ON WITH THE REST
#define BEST_VERY_EASY_SCORE_LOCATION 0X31
#define BEST_EASY_SCORE_LOCATION 0X32
#define BEST_MEDIUM_SCORE_LOCATION 0X33
#define BEST_HARD_SCORE_LOCATION 0X34
#define BEST_VERY_HARD_SCORE_LOCATION 0X35
#define MULTIPLICATION_SCORE_LOCATION 0X36


#define OUTPUT_PORT 'D'
#define RIGHT_BUTTON 0
#define OK_BUTTON 1
#define LEFT_BUTTON 2
#define GREEN_LED 3
#define RED_LED 4





void addition_mood();
void subtraction_mood();
void multiplication_mood();
void simple_random();
void complex_random();
unsigned char difficalty();
void write_the_score(unsigned char score);
void DEBUG();
unsigned short rand();






#endif /* FUNCTIONS_H_ */