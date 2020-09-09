/*
 * timers.c
 *
 *  Created on: 9 sep. 2020
 *      Author: sasha
 */

#include "timers.h"

//seria clave que los tiempos esten en microsegundos
void delay(uint32_t time){ //declararlo asi o castear dentro del while
	Chip_TIMER_Reset(LPC_TIMER0);
	Chip_TIMER_Enable(LPC_TIMER0);
	while(Chip_TIMER_ReadCount(LPC_TIMER0) != time){

	}
	//LPCopen no tiene una funcion que sea PARAR el timer, pero si apagarlo
	return;
}

