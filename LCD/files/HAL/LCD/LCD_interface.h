#ifndef LCD_INTERFACE_H
    #define LCD_INTERFACE_H
    
    
    void LCD_voidInit(void);
    void LCD_voidSendData(u8 Copy_u8data);
    void LCD_voidSendCmd(u8 Copy_u8cmd);
    void LCD_voidWriteString(u8 * Copy_u8PtrString);
    
    void LCD_voidWriteInteger(u64 Copy_u32Number);
    void LCD_voidClearDisplay(void);
    void LCD_voidMoveCursor(u8 Copy_u8Row,u8 Copy_u8Col);
    void LCD_voidReturnHome(void);
    void LCD_voidAddCharacter();

#endif