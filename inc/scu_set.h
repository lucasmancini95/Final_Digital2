
#ifndef _SCU_SET_H_
#define _SCU_SET_H_
#include "struct_base.h"

void SCU_SetPin(SCU_T *pSCU, unsigned char port, unsigned char pin, unsigned char funcion);
void SCU_EnableBuffer(SCU_T *pSCU, unsigned char port, unsigned char pin);//Setup buffer
void SCU_PINTSEL(SCU_T *pSCU, unsigned char ); //interruptions
void SCU_DisableGlitchFilter(SCU_T *pSCU, unsigned char port, unsigned char pin);

#endif
