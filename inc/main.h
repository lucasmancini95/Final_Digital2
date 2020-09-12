#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdbool.h>
#include "distance_sensor.h"
#include "gpio_set.h"
#include "interruptions.h"
#include "leds_setup.h"
#include "scu_set.h"
#include "status.h"
#include "zones.h"
#include "struct_base.h"
#include "tec_setup.h"
#include "timers.h"
#include "vibrator.h"

#define GPIO_TRIGGER_PORT 3 //para el Trigger usamos GPIO0
#define GPIO_TRIGGER_PIN 0
#define GPIO_ECHO_PORT 3	//para el echo usamos GPIO2
#define GPIO_ECHO_PIN 4
#define	SCU_TRIGGER_GROUP 6
#define	SCU_TRIGGER_PIN 1
#define	SCU_ECHO_GROUP 6
#define	SCU_ECHO_PIN 5

#define uint32_t unsigned int

#endif
