
#ifndef _SCU_SET_H_
#define _SCU_SET_H_
#include "struct_base.h"

void SCU_SetPin(SCU_T *pSCU, unsigned char port, unsigned char pin, unsigned char funcion);
void SCU_SetEZI(SCU_T *pSCU, unsigned char port, unsigned char pin, unsigned char ezi);//Setup buffer
void SCU_PINTSEL(SCU_T *pSCU, unsigned char ); //interruptions

#endif