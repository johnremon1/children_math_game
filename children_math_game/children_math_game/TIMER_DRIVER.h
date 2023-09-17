/*
 * TIMER_DRIVER.h
 *
 * Created: 9/7/2023 3:52:16 PM
 *  Author: johnr
 */ 


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_




/*
Function name   : Timrer_CTC_interrupt_enable
Function return : void
Function Arguments : (void)
Function description : this function activate the ctc mood,but 80 in OCR0,and activate the interrupt for CTC mood 
*/
void Timer_CTC_interrupt_enable(void);

void TIMER_OVERFLOW_MOOD();



#endif /* TIMER_DRIVER_H_ */