

#include "..\..\Services\bit_math.h"
#include "..\..\Services\std_types.h"




#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


void ADC_voidInit(){

	ADMUX = (1 << REFS0);
	ADCSRA =  (1 << ADPS0) |  (1 << ADPS1) |  (1 << ADPS2);

}
void ADC_voidEnable(){
	set_bit(ADCSRA,ADEN);
}
void ADC_voidDisable(){
	clear_bit(ADCSRA,ADEN);
}
u16 ADC_u16GetValue(u8 ADC_u8_Channel){
	clear_bit(ADMUX,MUX3);
	clear_bit(ADMUX,MUX4);

	switch (ADC_u8_Channel){
		case ADC_u8_ADC0_CHANNEL:
			clear_bit(ADMUX,MUX0);
			clear_bit(ADMUX,MUX1);
			clear_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC1_CHANNEL:
			set_bit(ADMUX,MUX0);
			clear_bit(ADMUX,MUX1);
			clear_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC2_CHANNEL:
			clear_bit(ADMUX,MUX0);
			set_bit(ADMUX,MUX1);
			clear_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC3_CHANNEL:
			set_bit(ADMUX,MUX0);
			set_bit(ADMUX,MUX1);
			clear_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC4_CHANNEL:
			clear_bit(ADMUX,MUX0);
			clear_bit(ADMUX,MUX1);
			set_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC5_CHANNEL:
			set_bit(ADMUX,MUX0);
			clear_bit(ADMUX,MUX1);
			set_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC6_CHANNEL:
			clear_bit(ADMUX,MUX0);
			set_bit(ADMUX,MUX1);
			set_bit(ADMUX,MUX2);
			break;
		case ADC_u8_ADC7_CHANNEL:
			set_bit(ADMUX,MUX0);
			set_bit(ADMUX,MUX1);
			set_bit(ADMUX,MUX2);
			break;
	}

	set_bit(ADCSRA,ADSC);
	while(!get_bit(ADCSRA,ADIF));

	set_bit(ADCSRA,ADIF);
	
    u16 LOC_u16_Result = ADC;
    return LOC_u16_Result;
}


