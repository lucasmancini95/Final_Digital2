/*
 * zones.c
 *
 *  Created on: 8 sep. 2020
 *      Author: sasha
 */


#include "zones.h"
#include "leds_setup.h"

status_t zone(zones_t zone){
	switch(zone){

	case ZONE_1:
		LED_high(L0G);
		LED_high(L1);
		LED_high(L2);
		LED_high(L3);
		break;

	case ZONE_2:
		LED_high(L0G);
		LED_high(L1);
		LED_high(L2);
		LED_low(L3);
		break;

	case ZONE_3:
		LED_high(L0G);
		LED_high(L1);
		LED_low(L2);
		LED_low(L3);
		break;

	case ZONE_OUT:
		LED_high(L0G);
		LED_low(L1);
		LED_low(L2);
		LED_low(L3);
		break;
	}
	return OK_ZONE;
}

