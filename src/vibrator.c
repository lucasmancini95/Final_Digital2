#include "vibrator.h"
#include "dac.h"

void vibrator_ON(zones_t zone){
	switch(zone){

		case ZONE_1:
			Values_DAC(3);
			//Chip_DAC_UpdateValue(LPC_DAC, 3);
			break;

		case ZONE_2:
			Values_DAC(2);
			//Chip_DAC_UpdateValue(LPC_DAC, 2);
			break;

		case ZONE_3:
			Chip_DAC_UpdateValue(LPC_DAC, 1);
			//Values_DAC(1);
			break;
		}
	return;
}
void vibrator_OFF(){
	Values_DAC(0);
	//Chip_DAC_UpdateValue(LPC_DAC, 0);
	return;
}

