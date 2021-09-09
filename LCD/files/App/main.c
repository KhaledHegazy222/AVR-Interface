



#include "..\MCAL\DIO\DIO_interface.h"
#include "..\HAL\LCD\LCD_interface.h"
#include "..\Services\std_types.h"
#include "..\Services\bit_math.h"


#include <util\delay.h>


// Main Function
int main(void){

	LCD_voidInit();

	LCD_voidAddCharacter();
	LCD_voidSendData(4);
	LCD_voidSendData(3);
	LCD_voidSendData(5);
	LCD_voidSendData(2);
	LCD_voidSendData(3);
	LCD_voidSendData(2);
	LCD_voidSendData(1);
	LCD_voidSendData(0);


	while(1){

	}

}