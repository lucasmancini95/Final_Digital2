
#ifndef _GPIO_SET_H_
#define _GPIO_SET_H_
#include "struct_base.h"
typedef enum{INPUT,OUTPUT}IO_t;
typedef enum{LOW,HIGH}state_t; //defino un tipo de dato para el estado que solo puede tomar los valores high o low

void GPIO_SetPinDIR(GPIO_T *pGPIO, unsigned char port, unsigned char pin, IO_t IO);
void GPIO_SetPin(GPIO_T *pGPIO, unsigned char port, unsigned char pin, state_t state); 
state_t GPIO_GetPinState(GPIO_T *pGPIO, unsigned char port, unsigned char pin);
//int GPIO_GetPinDIR(GPIO_T *pGPIO, unsigned char port, unsigned char pin); 
//int GPIO_GetPortDIR(GPIO_T *pGPIO, unsigned char port);
void GPIO_TogglePin(GPIO_T* pGPIO, unsigned char port, unsigned char pin);
#endif
