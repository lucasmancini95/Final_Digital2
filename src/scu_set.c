#include "struct_base.h"
#include "scu_set.h"

void SCU_SetPin(SCU_T *pSCU, unsigned char port, unsigned char pin, unsigned char function){	
	(pSCU->SFSP)[port][pin]|= function | (2<<3);
}

void SCU_SetEZI(SCU_T *pSCU, unsigned char port, unsigned char pin, unsigned char ezi){
	(SCU->SFSP)[port][pin]|=(1<<ezi);
	//Setup buffer
}

