

#ifndef LCD_CONFIG_H
    #define LCD_CONFIG_H
    /*
        PORTS : 
            1- DIO_u8_PORTA
            2- DIO_u8_PORTB
            3- DIO_u8_PORTC
            4- DIO_u8_PORTD

        PINS : 
            1- DIO_PIN_0
            2- DIO_PIN_1
            3- DIO_PIN_2
            4- DIO_PIN_3
            5- DIO_PIN_4
            6- DIO_PIN_5
            7- DIO_PIN_6
            8- DIO_PIN_7
    */


    
    #define LCD_DATA_PORT       DIO_u8_PORTA
    #define LCD_CONTROL_PORT    DIO_u8_PORTB

    #define LCD_RS_PIN          DIO_PIN_0
    #define LCD_ENABLE_PIN      DIO_PIN_1

    //#define LCD_u8_PIN_MODE     LCD_u8_4BIT_MODE
    //#define LCD_u8_PIN_MODE     LCD_u8_8BIT_MODE

    
    static u8 LCD_u8_Chars[] = {
        0x00,0x04,0x00,0x0E,0x01,0x1F,0x00,0x00,
        0x04,0x04,0x04,0x04,0x04,0x07,0x00,0x00,
        0x02,0x02,0x02,0x02,0x02,0x1E,0x00,0x00,
        0x00,0x00,0x00,0x02,0x02,0x0F,0x00,0x00,
        0x00,0x00,0x00,0x00,0x02,0x03,0x1C,0x00,
        0x00,0x00,0x00,0x09,0x09,0x1F,0x00,0x0A
    };

#endif


