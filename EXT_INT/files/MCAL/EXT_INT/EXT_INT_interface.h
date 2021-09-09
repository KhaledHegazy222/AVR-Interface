#ifndef EXT_INT_INTERFACE_H
    #define EXT_INT_INTERFACE_H


    #define EXT_INT_u8_INT0     0
    #define EXT_INT_u8_INT1     1
    #define EXT_INT_u8_INT2     2


    void EXT_INT_voidInit(); 
    void EXT_INT_voidEnable(u8 Copy_u8_Line);
    void EXT_INT_voidDisable(u8 Copy_u8_Line);
    void EXT_INT_voidCallBackFun(void (*fun)(void),u8 Copy_IntLine);
    
    
    
    
#endif