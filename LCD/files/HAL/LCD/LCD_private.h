#ifndef LCD_INTERFACE_H
    #define LCD_INTERFACE_H
    
    
    #define LCD_u8_FUNCTION_SET     0x3C // 0b0011 1100 (DATA LINE = 4 & 2 Line Display & 5 x 8 Dots)
    #define LCD_u8_DISPLAY          0x0E // 0b0000 1110 (Display ON & Cursor ON & Blink OFF)
    #define LCD_u8_CLEAR_DISPLAY    0x01 // 0b0000 0001 (Clear Display)
    #define LCD_u8_ENTRY_MODE_SET   0x06 // 0b0000 0110 (Increament Cursor on Typing & No Shift)
    #define LCD_u8_RETURN_HOME      0x02 // 0b0000 0010 (Return Home (Move Cursor To pos(0,0)) )
#endif