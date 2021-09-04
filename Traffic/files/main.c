
// Libraries Included

#include "DIO_interface.h"
#include <util/delay.h>

void display(u8 sevenSegNum){
	// This Function Takes about 10 ms
	u8 digits[] = {
		0x3f, // 0 
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F  // 9
	};
	DIO_voidSetPortValue(DIO_u8_PORTC,digits[sevenSegNum % 10]);
	DIO_voidSetPinValue(DIO_u8_PORTC,DIO_PIN_7,1); // First Digit
	_delay_ms(5);
	DIO_voidSetPortValue(DIO_u8_PORTC,digits[sevenSegNum / 10]);
	DIO_voidSetPinValue(DIO_u8_PORTC,DIO_PIN_7,0); // Second Digit 
	_delay_ms(5); 

}

void printRange(u8 range){
	for(u8 i = 0;i <= range;i++)
		for(u8 j = 0;j < 50;j++) // 50 * 10 ms = 500ms To Display one Number
			display(i);
}


// Main Function
int main(void){
	DIO_voidSetPortDirection(DIO_u8_PORTA,0x07); 
	DIO_voidSetPortDirection(DIO_u8_PORTC,0xff); 
	
	while(1){
		u8 signal = 1;
		DIO_voidSetPortValue(DIO_u8_PORTA,signal); // red LED ON
		printRange(30);
		signal <<= 1;
		DIO_voidSetPortValue(DIO_u8_PORTA,signal); // Yellow LED ON
		printRange(5);
		signal <<= 1;
		DIO_voidSetPortValue(DIO_u8_PORTA,signal); // Green LED ON
		printRange(30);
	}

	return 0;
}