/*
 * sensor.c
 *
 *  Created on: 9 sep. 2020
 *      Author: sasha
 */

#include "sensor.h"
#define TIME_TRIGGER 10 //us .... Aca o en el .h?
#define MAX_TIME_ECHO 29000 //us

void distance_sensor_trigger(){
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, HIGH);
	delay(TIME_TRIGGER);
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, LOW);
	return;
}


uint32_t distance_sensor_listen_echo(uint32_t time_echo){ //en principio uint32_t despues ver que ondu
	uint32_t distance=600; //en cm la maxima distancia medible es 500 => 600 = inf

	distance=time_echo/58; //si time echo esta en us, esto me da la distancia en cm
	time_echo=0; //si es global me conviene ponerla en 0 aca
	return distance;
}
