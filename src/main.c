/*
===============================================================================
 Name        : Final_D2_LPCOpen.c
 Author      : Sasha y solo sasha
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

static uint32_t time_echo=0;//ta bien esto?
static uint32_t distance=600;

status_t PERIPHERAL_init(){
	//en esta funcion se inician todos los perifericos (TIMERS, GPIO, UART)
	LED_ALL();
	DAC_init();
	SCU_init();
	GPIO_init();
	TIMERS_init();
	UART_init();
	return OK_ZONE;
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
	Chip_TIMER_ReadCount(LPC_TIMER0); //Returns the current timer terminal count
//	Chip_TIMER_SetMatch(LPC_TIMER0, MATCH(0), SystemCoreClock*0.00001);//Trigger 10us
//	Chip_TIMER_SetMatch(LPC_TIMER1, MATCH(0), SystemCoreClock*0.0000005);//Sampleo 0.5us

	return;
}

void UART_init(){
	Chip_UART_Init(LPC_USART0);
	//Chip_UART_Send(LPC_USART_T *pUART, const void *data, int numBytes);
}

void GPIO0_IRQHandler(void){ //activar el nvic
	//if recieve an echo signal

	Chip_TIMER_Reset(LPC_TIMER0);
	Chip_TIMER_Enable(LPC_TIMER0);

	while(Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ECHO_PORT, GPIO_ECHO_PIN)!= 0){

	}//esta bien poner estos while sin nada?
	//hay que armar la get pin state nuestra

	//esto si mal no recuerdo no puede devolver nada, asi que tengo que cambiar una variable global
	time_echo = Chip_TIMER_ReadCount(LPC_TIMER0);
	distance = distance_sensor_listen_echo(time_echo);
	//si pongo el time echo como parametro no tengo que usar la variable global
}

int main(void) {

    SystemCoreClockUpdate(); //solo si usamos match

    uint32_t distance=0; //esto generaria que esta pegado al sensor la logica tendria que ser infinito
    status_t status=OK_INIT;

    status = PERIPHERAL_init(); //GPIO, TIMERS, PWM/DAC, UART en alto nivel
    if(status != OK_INIT){
    	//MODO MANTENIMIENTO
    }

    while(1){

    	//empezar a medir distacia
    	distance_sensor_trigger();
    	//delay(DELAY_SENSOR_TE); ??
    	distance = distance_sensor_listen_echo(); //esto no deberia estar en una interrupcion?

    	//the distance determinates the zone of action
    	if(0<distance<Z1){
    		zone(ZONE_1);
    		vibrator_ON(ZONE_1);
    	}
    	if(Z1<distance<Z2){
    		zone(ZONE_2);
    		vibrator_ON(ZONE_1);
    	}
    	if(Z2<distance<Z3){
    		zone(ZONE_3);
    		vibrator_ON(ZONE_1);
    	}
    	if(Z3<distance){
    		zone(ZONE_OUT);
    		vibrator_OFF();
    	}

    	delay(DELAY_TRIGGER);

    	LED_ALL_OFF();
    	vibrator_OFF(); //Este es para que apague el vibrador entre uno y otro? dudoso ahre

    }
    return 0;
}


