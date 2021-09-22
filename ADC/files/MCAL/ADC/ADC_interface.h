#ifndef ADC_INTERFACE_H
    #define ADC_INTERFACE_H
    
    void ADC_voidInit(void);
    void ADC_voidEnable(void);
    void ADC_voidDisable(void);
    u16 ADC_u16GetValue(u8);
    
    #define ADC_u8_ADC0_CHANNEL     0
    #define ADC_u8_ADC1_CHANNEL     1
    #define ADC_u8_ADC2_CHANNEL     2
    #define ADC_u8_ADC3_CHANNEL     3
    #define ADC_u8_ADC4_CHANNEL     4
    #define ADC_u8_ADC5_CHANNEL     5
    #define ADC_u8_ADC6_CHANNEL     6
    #define ADC_u8_ADC7_CHANNEL     7


    


    
    
#endif