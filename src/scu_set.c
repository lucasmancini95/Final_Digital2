#include "struct_base.h"
#include "scu_set.h"

void SCU_SetPin(SCU_T *pSCU, unsigned char port, unsigned char pin, unsigned char function){	
	(pSCU->SFSP)[port][pin]|= function | (2<<3);
}

//Setup buffer
//EZI=1 enable input buffer
void SCU_EnableBuffer(SCU_T *pSCU, unsigned char port, unsigned char pin){
	(SCU->SFSP)[port][pin]|=(1<<6);
}

//Setup buffer
//ZIF=1 disable input glitch filter
//Input glitch filter. Disable the input glitch filter for clocking signals higher than 30 MHz.
void SCU_DisableGlitchFilter(SCU_T *pSCU, unsigned char port, unsigned char pin){
	(SCU->SFSP)[port][pin]|=(1<<7);
}
