/*
 * zones.h
 *
 *  Created on: 8 sep. 2020
 *      Author: sasha
 */

#ifndef ZONES_H_
#define ZONES_H_

#include "main.h"

typedef enum{ZONE_1, ZONE_2, ZONE_3, ZONE_OUT} zones_t;

status_t zone(zones_t ZONE);

#endif /* ZONES_H_ */
