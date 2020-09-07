/*
===============================================================================
 Name        : Final_D2_LPCOpen.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "chip.h"

#include <cr_section_macros.h>

#define GPIO_TRIGGER_PORT 3 //para el Trigger usamos GPIO0
#define GPIO_TRIGGER_PIN 0
#define GPIO_ECHO_PORT 3	//para el echo usamos GPIO2
#define GPIO_ECHO_PIN 4
#define	SCU_TRIGGER_GROUP 6
#define	SCU_TRIGGER_PIN 1
#define	SCU_ECHO_GROUP 6
#define	SCU_ECHO_PIN 5

void PERIPHERAL_init(){
	//en esta funcion se inician todos los perifericos (TIMERS, GPIO, UART)
	LED_ALL();
	DAC_init();
	SCU_init();
	GPIO_init();
	TIMERS_init();
	UART_init();
	return;
}

void DAC_init(){
	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_UpdateValue(LPC_DAC, 0); //lo inicializamos en 0
	//	DAC_enable();
	//	/*hacerla a partir de :
	//	void Enable_DMA(){
	//	(DAC->CTRL)|=(1<<3) | (1<<2) | (1<<1) | (1<<0);
	//	}
	//	//DMA_ENA(posicion 3) en 1: Habilitación del DAC y la entrada 15 (DMA Burst Request).*/
	//
	//	Enable_ENAIO();
}

void SCU_init(){
	SCU_SetPin(SCU, SCU_TRIGGER_GROUP, SCU_TRIGGER_PIN, 0);
	SCU_SetPin(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN, 0);
}

void GPIO_init(){
	GPIO_SetPinDIR(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, OUTPUT);
	GPIO_SetPinDIR(GPIO, GPIO_ECHO_PORT, GPIO_ECHO_PIN, INPUT);
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, LOW);
	return;
}

void TIMERS_init(){
	Chip_TIMER_Init(LPC_TIMER0);
	Chip_TIMER_Reset(LPC_TIMER0);
	//Chip_TIMER_ReadCount(LPC_TIMER0);
	Chip_TIMER_SetMatch(LPC_TIMER0, MATCH(0), SystemCoreClock*0.00001);//Trigger 10us
	Chip_TIMER_SetMatch(LPC_TIMER0, MATCH(1), SystemCoreClock*0.0000005);//Sampleo 0.5us
	Chip_TIMER_MatchEnableInt(LPC_TIMER0, MATCH(0));
	Chip_TIMER_MatchEnableInt(LPC_TIMER1, MATCH(0));

	//trigger
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER0, MATCH(0));
	Chip_TIMER_StopOnMatchDisable(LPC_TIMER0, MATCH(0));
	//sampleo
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, MATCH(0));
	Chip_TIMER_StopOnMatchDisable(LPC_TIMER1, MATCH(0));

	NVIC_ClearPendingIRQ(TIMER0_IRQn); //limpia si hay una interrup pendiente
	NVIC_EnableIRQ(TIMER0_IRQn);
	NVIC_ClearPendingIRQ(TIMER1_IRQn);
	NVIC_EnableIRQ(TIMER1_IRQn);

	return;
}

void UART_init(){
	Chip_UART_Init(LPC_USART0);
	//Chip_UART_Send(LPC_USART_T *pUART, const void *data, int numBytes);
}

int main(void) {

    SystemCoreClockUpdate();
    PERIPHERAL_init();

    while(1) {
        __asm volatile ("nop");
    }
    return 0 ;
}

