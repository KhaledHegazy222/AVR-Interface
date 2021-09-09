/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/


// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif




// Libraries Included
#include "..\Services\bit_math.h"
#include "..\Services\std_types.h"

#include "..\MCAL\DIO\DIO_interface.h"
#include "..\MCAL\GIE\GIE_interface.h"
#include "..\MCAL\EXT_INT\EXT_INT_interface.h"

#include <util/delay.h>


void fun(void){
    DIO_voidTogglePin(DIO_u8_PORTA,DIO_PIN_0);
	_delay_ms(250);
    DIO_voidTogglePin(DIO_u8_PORTA,DIO_PIN_0);
}



// Main Function
int main(void){
	

	DIO_voidSetPinDirection(DIO_u8_PORTA,DIO_PIN_0,DIO_u8_OUTPUT);
	DIO_voidActivePullUp(DIO_u8_PORTD,DIO_PIN_2);


	EXT_INT_voidInit();
	EXT_INT_voidCallBackFun(fun,EXT_INT_u8_INT0);
	GIE_voidEnable();

	while(1){

	}

}