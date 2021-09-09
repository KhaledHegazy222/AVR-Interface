// Include Files (Services)
#include "..\..\Services\std_types.h"
#include "..\..\Services\bit_math.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"




    
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction){
    // if(Copy_u8Direction)
    //     Copy_u8Direction = 0xff;
    switch (Copy_u8Port){
        case DIO_u8_PORTA:
            DDRA = Copy_u8Direction;
            break;
        case DIO_u8_PORTB:
            DDRB = Copy_u8Direction;
            break;
        case DIO_u8_PORTC:
            DDRC = Copy_u8Direction;
            break;
        case DIO_u8_PORTD:
            DDRD = Copy_u8Direction;
    }    

} 
void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction){
    switch(Copy_u8Port){
        case DIO_u8_PORTA :
            write_bit(DDRA,Copy_u8Pin,Copy_u8Direction);
            break;
        case DIO_u8_PORTB :
            write_bit(DDRB,Copy_u8Pin,Copy_u8Direction);
            break;
        case DIO_u8_PORTC :
            write_bit(DDRC,Copy_u8Pin,Copy_u8Direction);
            break;
        case DIO_u8_PORTD :
            write_bit(DDRD,Copy_u8Pin,Copy_u8Direction);
            break;
    }
}

void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value){
    //if(Copy_u8Value)
        //Copy_u8Value = 0xff;
    switch (Copy_u8Port){
        case DIO_u8_PORTA:
            PORTA = Copy_u8Value;
            break;
        case DIO_u8_PORTB:
            PORTB = Copy_u8Value;
            break;
        case DIO_u8_PORTC:
            PORTC = Copy_u8Value;
            break;
        case DIO_u8_PORTD:
            PORTD = Copy_u8Value;
    }    
}
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
    switch(Copy_u8Port){
        case DIO_u8_PORTA :
            write_bit(PORTA,Copy_u8Pin,Copy_u8Value);
            break;
        case DIO_u8_PORTB :
            write_bit(PORTB,Copy_u8Pin,Copy_u8Value);
            break;
        case DIO_u8_PORTC :
            write_bit(PORTC,Copy_u8Pin,Copy_u8Value);
            break;
        case DIO_u8_PORTD :
            write_bit(PORTD,Copy_u8Pin,Copy_u8Value);
            break;
    }
}

u8 DIO_u8ReadPinValue(u8 Copy_u8Port,u8 Copy_u8Pin){
    u8 LOC_u8PinState = 0;
    switch(Copy_u8Port){
        case DIO_u8_PORTA :
            LOC_u8PinState = get_bit(PINA,Copy_u8Pin);
            break;
        case DIO_u8_PORTB :
            LOC_u8PinState = get_bit(PINB,Copy_u8Pin);
            break;
        case DIO_u8_PORTC :
            LOC_u8PinState = get_bit(PINC,Copy_u8Pin);
            break;
        case DIO_u8_PORTD :
            LOC_u8PinState = get_bit(PIND,Copy_u8Pin);

    }
    return LOC_u8PinState;
}


void DIO_voidActivePullUp(u8 Copy_u8Port,u8 Copy_u8Pin){
    switch(Copy_u8Port){
        case DIO_u8_PORTA :
            clear_bit(DDRA,Copy_u8Pin);
            set_bit(PORTA,Copy_u8Pin);
            break;
        case DIO_u8_PORTB :
            clear_bit(DDRB,Copy_u8Pin);
            set_bit(PORTB,Copy_u8Pin);
            break;
        case DIO_u8_PORTC :
            clear_bit(DDRC,Copy_u8Pin);
            set_bit(PORTC,Copy_u8Pin);
            break;
        case DIO_u8_PORTD :
            clear_bit(DDRD,Copy_u8Pin);
            set_bit(PORTD,Copy_u8Pin);
            break;

    }
}


void DIO_voidTogglePin(u8 Copy_u8Port,u8 Copy_u8Pin){
    switch (Copy_u8Port){
    case DIO_u8_PORTA:
        toggle_bit(PORTA,Copy_u8Pin);
        break;
    case DIO_u8_PORTB:
        toggle_bit(PORTB,Copy_u8Pin);
        break;
    case DIO_u8_PORTC:
        toggle_bit(PORTC,Copy_u8Pin);
        break;
    case DIO_u8_PORTD:
        toggle_bit(PORTD,Copy_u8Pin);
        break;
    
    }
}

