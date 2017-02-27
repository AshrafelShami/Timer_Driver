#include "Timer_Config.h"

volatile u16 Timer_OVERFLOW_Flag;

int main(void){
	DDRC |= 0xFF;
	Timer_OVERFLOW_Flag = 0;

	Struct_Timer Timer_Init_Struct;
	Timer_Init_Struct.Prescaler_Select	= Division_Factor_1024;
	Timer_Init_Struct.Interrupt_Set		= Timer_Compare_Enable;
	
	Timer_Init(Timer_Init_Struct);
	
	Timer_Compare_Value(64);
	
	sei();
    while (1){
		if (Timer_OVERFLOW_Flag >= 64){
			PORTC ^= 0xFF;
			Timer_OVERFLOW_Flag = 0;
		}
    }
}

ISR (TIMER0_COMP_vect){
	Timer_OVERFLOW_Flag++;
	Timer_Counter_Init(0);
}