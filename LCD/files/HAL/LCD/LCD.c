
#include "..\..\Services\std_types.h"
#include "..\..\Services\bit_math.h"

#include "..\..\MCAL\DIO\DIO_interface.h"
  
#include "LCD_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include <util/delay.h>



void LCD_voidInit(void){
    DIO_voidSetPortDirection(LCD_DATA_PORT,0xff);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_ENABLE_PIN,DIO_u8_OUTPUT);
    _delay_ms(50);

    // Function Set (DATA LINE = 4 & 2 Line Display & 5 x 8 Dots)
    LCD_voidSendCmd(LCD_u8_FUNCTION_SET);
    _delay_us(50);

    // Display Control (Display ON + Cursor ON + Blink OFF)
    LCD_voidSendCmd(LCD_u8_DISPLAY);
    _delay_us(50);

    // Clear Display
    LCD_voidSendCmd(LCD_u8_CLEAR_DISPLAY);
    _delay_ms(2);
    
    // Entry Mode Set
    LCD_voidSendCmd(LCD_u8_ENTRY_MODE_SET);
    _delay_ms(1);


}



void LCD_voidSendData(u8 Copy_u8data){

    DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8data);
    DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH); // RS = 1
    // Falling Edge
    DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_ENABLE_PIN,DIO_u8_HIGH); // EN = 1
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_ENABLE_PIN,DIO_u8_LOW); // EN = 0
    _delay_ms(1);

}


void LCD_voidSendCmd(u8 Copy_u8cmd){
    DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8cmd);
    DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW); // RS = 0
    // Falling Edge
    DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_ENABLE_PIN,DIO_u8_HIGH); // EN = 1
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_ENABLE_PIN,DIO_u8_LOW); // EN = 0
    _delay_ms(1);
    
}


void LCD_voidWriteString(u8 * Copy_u8PtrString){
    while(*Copy_u8PtrString){
        LCD_voidSendData(*(Copy_u8PtrString++));
    }   
}



void LCD_voidWriteInteger(u64 Copy_u32Number){
    u8 LOC_digits[20];
    u8 LOC_size = 0;
    while(Copy_u32Number){
        LOC_digits[LOC_size++] = '0' + (Copy_u32Number % 10);
        Copy_u32Number /= 10;
    }
    if(!LOC_size)
        LCD_voidSendData('0');
    else
        for(s8 i = LOC_size - 1;i>=0;i--)
            LCD_voidSendData(LOC_digits[i]);
}





void LCD_voidClearDisplay(void){
    LCD_voidSendCmd(LCD_u8_CLEAR_DISPLAY);
    _delay_ms(2);
    
}




void LCD_voidMoveCursor(u8 Copy_u8Row,u8 Copy_u8Col){
    u8 LOC_bias = (Copy_u8Row - 1) * 0x40;
    LCD_voidSendCmd((1 << 7) | (LOC_bias + Copy_u8Col - 1));
    _delay_us(50);
}




void LCD_voidReturnHome(void){
    LCD_voidSendCmd(LCD_u8_RETURN_HOME);
    _delay_ms(2);
}




void LCD_voidAddCharacter(){
    LCD_voidSendCmd((1 << 6));
    _delay_us(50);
    for(u8 i = 0;i<sizeof(LCD_u8_Chars) / sizeof(LCD_u8_Chars[0]);i++){
        LCD_voidSendData(LCD_u8_Chars[i]);
        _delay_us(50);
    }
    LCD_voidMoveCursor(1,1);
}