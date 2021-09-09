#ifndef LCD_PRIVATE_H
    #define LCD_PRIVATE_H
    
    

    #define LCD_u8_8_BIT_MODE 1
    #define LCD_u8_4_BIT_MODE 2





    #define LCD_u8_FUNCTION_SET_8_BIT   0x3C // 0b0011 1100 (DATA LINE = 4 & 2 Line Display & 5 x 8 Dots)
    #define LCD_u8_FUNCTION_SET_4_BIT   0x2C // 0b0010 1100 (DATA LINE = 4 & 2 Line Display & 5 x 8 Dots)
    #define LCD_u8_DISPLAY              0x0E // 0b0000 1110 (Display ON & Cursor ON & Blink OFF)
    #define LCD_u8_CLEAR_DISPLAY        0x01 // 0b0000 0001 (Clear Display)
    #define LCD_u8_ENTRY_MODE_SET       0x06 // 0b0000 0110 (Increament Cursor on Typing & No Shift)
    #define LCD_u8_RETURN_HOME          0x02 // 0b0000 0010 (Return Home (Move Cursor To pos(0,0)) )



#endif