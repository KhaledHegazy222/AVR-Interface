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


#include <util\delay.h>

#define DRAW_SIZE 4
u8 GLOB_idx;




void toggle1();
void toggle2();
void changeDraw();
void draw();

// Main Function
int main(void){

	DIO_voidActivePullUp(DIO_u8_PORTD,DIO_PIN_2); // INT0 Pin
	DIO_voidActivePullUp(DIO_u8_PORTD,DIO_PIN_3); // INT1 Pin
	DIO_voidActivePullUp(DIO_u8_PORTB,DIO_PIN_2); // INT2 Pin

	DIO_voidSetPortDirection(DIO_u8_PORTA,0xff);
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_PIN_0,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_PIN_1,DIO_u8_OUTPUT);

	EXT_INT_voidCallBackFun(toggle1,EXT_INT_u8_INT0);
	EXT_INT_voidCallBackFun(toggle2,EXT_INT_u8_INT1);
	EXT_INT_voidCallBackFun(changeDraw,EXT_INT_u8_INT2);
	EXT_INT_voidInit();
	GIE_voidEnable();

	DIO_voidSetPortValue(DIO_u8_PORTA,0x00);
	DIO_voidSetPinValue(DIO_u8_PORTB,DIO_PIN_0,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PORTB,DIO_PIN_1,DIO_u8_LOW);


	while(1){
		draw();
	}	

}




void toggle1(){
	DIO_voidTogglePin(DIO_u8_PORTB,DIO_PIN_0);
}
void toggle2(){
	DIO_voidTogglePin(DIO_u8_PORTB,DIO_PIN_1);
}
void changeDraw(){
	GLOB_idx++;
	GLOB_idx %= DRAW_SIZE;
	DIO_voidSetPortValue(DIO_u8_PORTA,0x00);
}

void draw(){
	switch(GLOB_idx){
		case 0 :
			for(u8 i =0;i<8;i++){
				if(GLOB_idx != 0)
					break;
				DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_LOW);
			}
			break;
		case 1 :
			for(s8 i =7;i>=0;i--){
				if(GLOB_idx != 1)
					break;
				DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_LOW);
			}
			break;
		case 2 :
			for(u8 l = 0 , r = 7;l <= r;l++,r--){
				if(GLOB_idx != 2)
					break;
				DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_HIGH);
				DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_HIGH);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_LOW);
			}
			break;
		case 3 :
			for(u8 l = 3 , r = 4;r < 7;l--,r++){
				if(GLOB_idx != 3)
					break;
				DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_HIGH);
				DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_HIGH);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_LOW);
			}
			break;
	}
}