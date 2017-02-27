#define Timer0	/*	Define which Timer you will use (Timer0 - Timer1A - Timer1B - Timer2)	*/

#include "Timer_Config.h"

/********************************************************************************************
  Name:     Timer_Init.
  Purpose:  Initialize, Timer registers for ATmega32.
  Entry:    ( Struct_Timer Timer_Config ) a STRUCT that setup the following.
							1) Adjust the Pre-Scaler.
							6) Enable Timer overflow and Timer Compare match Interrupts. 
  Exit:     no parameters
********************************************************************************************/
void Timer_Init( Struct_Timer Timer_Config ){
	switch(Timer_Config.Prescaler_Select){
		case No_Clock_Source				: TCCRm &=~(1 << CSm2); TCCRm &=~(1 << CSm1); TCCRm &=~(1 << CSm0); break;
		case Division_Factor_OFF			: TCCRm &=~(1 << CSm2); TCCRm &=~(1 << CSm1); TCCRm |= (1 << CSm0); break;
		case Division_Factor_8				: TCCRm &=~(1 << CSm2); TCCRm |= (1 << CSm1); TCCRm &=~(1 << CSm0); break;
		case Division_Factor_64				: TCCRm &=~(1 << CSm2); TCCRm |= (1 << CSm1); TCCRm |= (1 << CSm0); break;
		case Division_Factor_256			: TCCRm |= (1 << CSm2); TCCRm &=~(1 << CSm1); TCCRm &=~(1 << CSm0); break;
		case Division_Factor_1024			: TCCRm |= (1 << CSm2); TCCRm &=~(1 << CSm1); TCCRm |= (1 << CSm0); break;
		case External_Clk_Src_Falling_egde	: TCCRm |= (1 << CSm2); TCCRm |= (1 << CSm1); TCCRm &=~(1 << CSm0); break;
		case External_Clk_Src_Rising_egde	: TCCRm |= (1 << CSm2); TCCRm |= (1 << CSm1); TCCRm |= (1 << CSm0); break;
		default								: TCCRm |= (1 << CSm2); TCCRm &=~(1 << CSm1); TCCRm |= (1 << CSm0); break;	
	}
	
	switch(Timer_Config.Interrupt_Set){
		case Timer_Overflow_Enable : TIMSK |= (1 << TOIEm); break;
		case Timer_Compare_Enable  : TIMSK |= (1 << OCIEm); break;
		default					   : TIMSK &=~(1 << TOIEm); TIMSK &=~(1 << OCIEm); break;
	}
}

/********************************************************************************************
  Name:     Timer_Compare_Value.
  Purpose:  Initialize the Compare Match Register.
  Entry:    ( u16 Compare_Value ) Initialize the Output Compare register OCR 0 ~ 65535.
  Exit:     no parameters
********************************************************************************************/
void Timer_Compare_Value ( u16 Compare_Value ){
	OCRm = Compare_Value;
}

/********************************************************************************************
  Name:     Timer_Counter_Init.
  Purpose:  Initialize The Timer Counter Register.
  Entry:    ( u16 Initvalue ) a Parameter to initialize a value in the Timer Counter (TCNT).
  Exit:     no parameters
********************************************************************************************/
void Timer_Counter_Init ( u16 Initvalue ){
	TCNTm = Initvalue;
}