#include "main.h"

int main(void){

uint32_t distance=0;
status_t status=OK_INIT;

status = Init_hardware(); //GPIO, TIMERS, PWM/DAC, UART en alto nivel
if(status != OK_INIT){
	//MODO MANTENIMIENTO
}

for(;;){

	//empezar a medir distacia
	distance_sensor_trigger();
	//delay(DELAY_SENSOR_TE); ??
	distance = distance_sensor_listen_echo();

	//the distance determinates the zone of action
	if(0<distance<Z1){
		zone_1();
	}
	if(Z1<distance<Z2){
		zone_2();
	}
	if(Z2<distance<Z3){
		zone_3();
	}
	if(Z3<distance){
		zone_out();
	}

	delay(DELAY_TRIGGER);

	GPIO_OFF(LEDS_ALL);
	vibrator_OFF();

}

}

status_t zone_1(){

	GPIO_ON(LED_ZONE_1);
	vibrator_ON(ZONE_1);

	return OK_ZONE;

}

status_t zone_2(){

	GPIO_ON(LED_ZONE_2);
	vibrator_ON(ZONE_2);

	return OK_ZONE;

}

status_t zone_3(){

	GPIO_ON(LED_ZONE_3);
	vibrator_ON(ZONE_3);

	return OK_ZONE;

}

status_t zone_out(){

	GPIO_ON(LED_ZONE_out);

	return OK_ZONE;

}