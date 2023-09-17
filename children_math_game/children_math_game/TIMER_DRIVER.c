/*
 * TIMER_DRIVER.c
 *
 * Created: 9/7/2023 3:51:02 PM
 *  Author: johnr
 */ 

#include "TIMER_DRIVER.h"
#include "STD_MACROS1.h"
#include <avr/io.h>
#include <AVR/interrupt.h>

void Timer_CTC_interrupt_enable(void)
{
	//choosing the mode we want and it is the CTC mood (clear timer on compare match)
	set_bit(TCCR0,WGM01);
	
	//choosing the clock the timer will be on
	clear_bit(TCCR0,CS00);
	clear_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	
	//choosing the number in the OCR0 
	OCR0=250;
	/*
	why 80 because our system clock is 8 mhz so to achieve 10 ms every compare match you must divide the 
	10 ms on the tick time which is 1024/8*10^6 which gives us aproximate number of 80 in the end of calculations
	*/
	
	
	//now we activate the register needed for interrupt activation
	sei();
	set_bit(TIMSK,OCIE0);
	
	
}

void TIMER_OVERFLOW_MOOD()
{
	clear_bit(TCCR0,WGM00);
	clear_bit(TCCR0,WGM01);
	
	//choosing the clock the timer will be on
	clear_bit(TCCR0,CS00);//clock set to be system clock over 64
	clear_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	


}