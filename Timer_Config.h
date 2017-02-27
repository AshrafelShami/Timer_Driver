
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#include "Functions_Prototypes.h"
#include "Datatypes.h"
#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#ifdef Timer0
#define TCCRm	TCCR0
#define CSm0	CS00
#define CSm1	CS01
#define CSm2	CS02
#define FOCm	FOC0
#define TCNTm	TCNT0
#define OCRm	OCR0
#define TOIEm	TOIE0
#define OCIEm	OCIE0
#define TOVm	TOV1
#define OCFm	OCF1A
#endif

#ifdef Timer1A
#define TCCRm	TCCR1B
#define CSm0	CS10
#define CSm1	CS11
#define CSm2	CS12
#define FOCm	FOC1A
#define TCNTm	TCNT1
#define OCRm	OCR1A
#define TOIEm	TOIE1
#define OCIEm	OCIE1A
#define TOVm	TOV1
#define OCFm	OCF1A
#endif

#ifdef Timer1B
#define TCCRm	TCCR1B
#define CSm0	CS10
#define CSm1	CS11
#define CSm2	CS12
#define FOCm	FOC1B
#define TCNTm	TCNT1
#define OCRm	OCR1B
#define TOIEm	TOIE1
#define OCIEm	OCIE1B
#define TOVm	TOV1
#define OCFm	OCF1B
#endif

#ifdef Timer2
#define TCCRm	TCCR2
#define CSm0	CS20
#define CSm1	CS21
#define CSm2	CS22
#define FOCm	FOC2
#define TCNTm	TCNT2
#define OCRm	OCR2
#endif

typedef enum{
	No_Clock_Source,
	Division_Factor_OFF,
	Division_Factor_8,
	Division_Factor_64,
	Division_Factor_256,
	Division_Factor_1024,
	External_Clk_Src_Falling_egde,
	External_Clk_Src_Rising_egde
	
	}Clk_Select;
	
typedef enum{
	Timer_Overflow_Enable,
	Timer_Compare_Enable
	}interrupt_Sel;
	
typedef struct{
	Clk_Select	Prescaler_Select;
	interrupt_Sel	Interrupt_Set;
	}Struct_Timer;
	
void Timer_Init ( Struct_Timer );

#endif /* TIMER_CONFIG_H_ */
