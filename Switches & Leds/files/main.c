


// Libraries Included

#include "DIO_interface.h"
#include <util/delay.h>


void flash(){
	DIO_voidSetPortValue(DIO_u8_PORTA,0xff);
	_delay_ms(200);
	DIO_voidSetPortValue(DIO_u8_PORTA,0x00);
	_delay_ms(200);
}

void shiftRight(){
	for(s8 i = 7;i>=0;i--){
		DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
		_delay_ms(200);
		DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_LOW);
	}
}

void shape1(){
	for(u8 l = 0,r = 7;r >= l;r--,l++){
		DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_HIGH);
		_delay_ms(200);
		DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_LOW);
		}
}
void shape2(){
	for(u8 l = 3,r = 4;r < 8;r++,l--){
		DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_HIGH);
		_delay_ms(200);
		DIO_voidSetPinValue(DIO_u8_PORTA,l,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTA,r,DIO_u8_LOW);
	}

}



// Main Function
int main(void){
	DIO_voidSetPortDirection(DIO_u8_PORTA,0xff);
	DIO_voidActivePullUp(DIO_u8_PORTB,DIO_PIN_0);
	DIO_voidActivePullUp(DIO_u8_PORTB,DIO_PIN_1);
	DIO_voidActivePullUp(DIO_u8_PORTB,DIO_PIN_2);
	while(1){
		u8 s0 = DIO_u8ReadPinValue(DIO_u8_PORTB,DIO_PIN_0);
		u8 s1 = DIO_u8ReadPinValue(DIO_u8_PORTB,DIO_PIN_1);
		u8 s2 = DIO_u8ReadPinValue(DIO_u8_PORTB,DIO_PIN_2);
		u8 val = (!s0) | ((!s1) << 1) | ((!s2) << 2);
		switch (val){
			case 0b001:
				flash();
				break;
			case 0b010:
				shiftRight();
				break;
			case 0b011:
				shape1();
				break;
			case 0b100:
				shape2();
				break;
			default:
				DIO_voidSetPortValue(DIO_u8_PORTA,0x00);
		}

	}	
	return 0;
}