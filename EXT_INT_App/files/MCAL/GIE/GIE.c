#include "..\..\Services\bit_math.h"
#include "..\..\Services\std_types.h"


#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnable(){
    set_bit(SREG,GIE);
}

void GIE_voidDisable(){
    clear_bit(SREG,GIE);
}

