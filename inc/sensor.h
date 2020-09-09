/*
 * sensor.h
 *
 *  Created on: 9 sep. 2020
 *      Author: sasha
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#define TIME_TRIGGER 10 //us
void distance_sensor_trigger();
unsigned int distance_sensor_listen_echo();

#endif /* SENSOR_H_ */
