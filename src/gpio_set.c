#include "struct_base.h"
#include "gpio_set.h"

//setea pines como de entrada o salida
void GPIO_SetPinDIR(GPIO_T *pGPIO, unsigned char port, unsigned char pin, IO_t IO){
	
	if(IO==OUTPUT)
		(pGPIO->DIR)[port]|=(1<<pin);
	else if(IO==INPUT)
		(pGPIO->DIR)[port]&= ~(1<<pin);
}

void GPIO_SetPin(GPIO_T *pGPIO, unsigned char port, unsigned char pin, state_t state){
	
	if(state==HIGH)
		(pGPIO->SET)[port] |= (1<<pin);
	else if (state==LOW)
		(pGPIO->CLR)[port] |= (1<<pin);
}

//Esta funcion me devuelve el estado que hay en un pin
state_t GPIO_GetPinState(GPIO_T *pGPIO, unsigned char port, unsigned char pin){

	//el registro B me da un valor de 1 o 0
	return (state_t)(pGPIO->B)[port][pin]; 
	//hago un casteo porque quiero que 0 sea para LOW y 1 sea para HIGH
}

void GPIO_TogglePin(GPIO_T* pGPIO, unsigned char port, unsigned char pin){
	(pGPIO->NOT)[port] |= (1<<pin);
}




