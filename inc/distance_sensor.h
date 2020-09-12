#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "main.h"

#define MAX_ECHO_TIME 1000000000000 //NO ES ESE VALOR (random)
#define TIME_TRIGGER 10 //us

void distance_sensor_trigger();
uint32_t distance_sensor_listen_echo();
uint32_t distance_cm(uint32_t time_echo);

#endif
