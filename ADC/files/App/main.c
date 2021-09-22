/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/


// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif




// Libraries Included
#include "..\Services\std_types.h"
#include "..\Services\bit_math.h"


#include "..\MCAL\ADC\ADC_interface.h"
#include "..\HAL\LCD\LCD_interface.h"
#include "..\MCAL\DIO\DIO_interface.h"



void LedFun(u8 level){
	DIO_voidSetPortValue(DIO_u8_PORTD,0x00);
	for(u8 i = 0;i< level;i++)
		DIO_voidSetPinValue(DIO_u8_PORTD,i,DIO_u8_HIGH);
}


// Main Function
int main(void){


	DIO_voidSetPortDirection(DIO_u8_PORTD,0xff);
	DIO_voidSetPinDirection(DIO_u8_PORTC,DIO_PIN_7,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTC,DIO_PIN_6,DIO_u8_OUTPUT);



	ADC_voidInit();
	ADC_voidEnable();
	LCD_voidInit();

	while(1){

		LCD_voidMoveCursor(1,1);
		u16 LOC_Ret = ADC_u16GetValue(ADC_u8_ADC0_CHANNEL) * 5.0 * 100 / 1023.0;
		LCD_voidWriteString("Temprature=");
		LCD_voidWriteInteger(LOC_Ret);
		LCD_voidWriteString(" C      ");
		if(LOC_Ret > 40){
			DIO_voidSetPinValue(DIO_u8_PORTC,DIO_PIN_7,DIO_u8_HIGH);
		}
		else{
			DIO_voidSetPinValue(DIO_u8_PORTC,DIO_PIN_7,DIO_u8_LOW);
		}

		LOC_Ret = ADC_u16GetValue(ADC_u8_ADC1_CHANNEL) * 500.0 / 1023.0;
		LCD_voidMoveCursor(2,1);
		LCD_voidWriteString("Volatage=");
		LCD_voidWriteInteger(LOC_Ret / 100);
		LCD_voidWriteString(".");
		LCD_voidWriteInteger(LOC_Ret % 100);
		LCD_voidWriteString(" V     ");

		if(LOC_Ret > 250){
			DIO_voidSetPinValue(DIO_u8_PORTC,DIO_PIN_6,DIO_u8_HIGH);
		}
		else{
			DIO_voidSetPinValue(DIO_u8_PORTC,DIO_PIN_6,DIO_u8_LOW);
		}
		
		LOC_Ret = ADC_u16GetValue(ADC_u8_ADC2_CHANNEL) * 500.0 / 1023.0;
		LedFun(8.0 * LOC_Ret / 500.0);
		


		
	}

}