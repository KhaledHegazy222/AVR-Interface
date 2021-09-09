#include "..\..\Services\bit_math.h"
#include "..\..\Services\std_types.h"

#include "..\DIO\DIO_interface.h"
#include "..\GIE\GIE_interface.h"

#include "EXT_INT_interface.h"
#include "EXT_INT_config.h"
#include "EXT_INT_private.h"




void EXT_INT_voidInit(){

    #ifdef EXT_INT_u8_ENABLE_INT0

        #if EXT_INT_u8_INT0_ISC == EXT_INT_u8_LOW_LEVEL
    
            clear_bit(MCUCR,ISC00);
            clear_bit(MCUCR,ISC01);    

        #endif
        #if EXT_INT_u8_INT0_ISC == EXT_INT_u8_LOGICAL_CHANGE
            
            set_bit(MCUCR,ISC00);
            clear_bit(MCUCR,ISC01);  

        #endif
        #if EXT_INT_u8_INT0_ISC == EXT_INT_u8_FALLING_EDGE
        
            clear_bit(MCUCR,ISC00);
            set_bit(MCUCR,ISC01);  

        #endif
        #if EXT_INT_u8_INT0_ISC == EXT_INT_u8_RISING_EDGE  

            set_bit(MCUCR,ISC00);
            set_bit(MCUCR,ISC01); 

        #endif

        set_bit(GICR,INT0);

    #endif




    #ifdef EXT_INT_u8_ENABLE_INT1

        #if EXT_INT_u8_INT1_ISC == EXT_INT_u8_LOW_LEVEL
        
            clear_bit(MCUCR,ISC10);
            clear_bit(MCUCR,ISC11);

        #endif  
        #if EXT_INT_u8_INT1_ISC == EXT_INT_u8_LOGICAL_CHANGE
    
            set_bit(MCUCR,ISC10);
            clear_bit(MCUCR,ISC11);

        #endif
        #if EXT_INT_u8_INT1_ISC == EXT_INT_u8_FALLING_EDGE
    
            clear_bit(MCUCR,ISC10);
            set_bit(MCUCR,ISC11);

        #endif
        #if EXT_INT_u8_INT1_ISC == EXT_INT_u8_RISING_EDGE
    
            set_bit(MCUCR,ISC10);
            set_bit(MCUCR,ISC11);

        #endif


        set_bit(GICR,INT1);
        
    #endif



    #ifdef EXT_INT_u8_ENABLE_INT2

        #if EXT_INT_u8_INT2_ISC == EXT_INT_u8_FALLING_EDGE

            clear_bit(MCUCSR,ISC2);

        #endif
        #if EXT_INT_u8_INT2_ISC == EXT_INT_u8_RISING_EDGE

            set_bit(MCUCSR,ISC2);

        #endif

        set_bit(GICR,INT2);
        
    #endif
}


void EXT_INT_voidEnable(u8 Copy_u8_Line){
    switch (Copy_u8_Line){
        case EXT_INT_u8_INT0 :
            set_bit(GICR,INT0); 
            break;
        case EXT_INT_u8_INT1 :
            set_bit(GICR,INT1); 
            break;
        case EXT_INT_u8_INT2 :
            set_bit(GICR,INT2); 
            break;
    }

}
void EXT_INT_voidDisable(u8 Copy_u8_Line){
    switch (Copy_u8_Line){
        case EXT_INT_u8_INT0 :
            clear_bit(GICR,INT0); 
            break;
        case EXT_INT_u8_INT1 :
            clear_bit(GICR,INT1); 
            break;
        case EXT_INT_u8_INT2 :
            clear_bit(GICR,INT2); 
            break;
    }
}





void EXT_INT_voidCallBackFun(void (*fun)(void),u8 Copy_IntLine){
    EXT_INT_PtrFuns[Copy_IntLine] = fun;
}




void __vector_1(void){ 
    if(EXT_INT_PtrFuns[EXT_INT_u8_INT0] != NULL)
        EXT_INT_PtrFuns[EXT_INT_u8_INT0]();

    set_bit(GIFR,INTF0);
}

void __vector_2(void){
    if(EXT_INT_PtrFuns[EXT_INT_u8_INT1] != NULL)
        EXT_INT_PtrFuns[EXT_INT_u8_INT1]();
        
    set_bit(GIFR,INTF1);
}


void __vector_3(void){
    if(EXT_INT_PtrFuns[EXT_INT_u8_INT2] != NULL)
        EXT_INT_PtrFuns[EXT_INT_u8_INT2]();
    
    set_bit(GIFR,INTF2);
}


