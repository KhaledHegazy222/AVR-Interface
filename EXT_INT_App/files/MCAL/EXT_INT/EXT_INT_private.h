#ifndef EXT_INT_PRIVATE_H
    #define EXT_INT_PRIVATE_H
    
    
    #define MCUCR   *((volatile u8 *) 0x55)
    #define MCUCSR  *((volatile u8 *) 0x54)
    #define GICR    *((volatile u8 *) 0x5B)
    #define GIFR    *((volatile u8 *) 0x5A)
    
    #define ISC00   0
    #define ISC01   1
    #define ISC10   2
    #define ISC11   3
    #define ISC2    6

    #define INT0    6
    #define INT1    7
    #define INT2    5

    #define INTF0   6
    #define INTF1   7
    #define INTF2   5



    #define EXT_INT_u8_LOW_LEVEL        0
    #define EXT_INT_u8_LOGICAL_CHANGE   1
    #define EXT_INT_u8_FALLING_EDGE     2
    #define EXT_INT_u8_RISING_EDGE      3


    

    static void (*EXT_INT_PtrFuns[3])(void) = {NULL};

    void __vector_1(void) __attribute__ ((signal));
    void __vector_2(void) __attribute__ ((signal));
    void __vector_3(void) __attribute__ ((signal));



#endif