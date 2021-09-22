

#ifndef BIT_MATH_H
	#define BIT_MATH_H




	#define set_bit(port,bit) (port|=(1<<bit))
	#define clear_bit(port,bit) (port&=~(1<<bit))
	#define toggle_bit(port,bit) (port^=(1<<bit))
	// #define get_bit(port,bit) ((port&(1<<bit))!=0)
	#define get_bit(port,bit) ((port >> bit) & 1)
	#define write_bit(port,bit,val) ((val) ? set_bit(port,bit) : clear_bit(port,bit))


#endif 