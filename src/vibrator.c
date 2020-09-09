#include "vibrator.h"

void vibrator_ON(zones_t zone){ //falta definir que valor del DAC ponerle para cada zona puede ser 1V 2V 3V
	switch(zone){

		case ZONE_1:
			Chip_DAC_UpdateValue(LPC_DAC, 3);
			break;

		case ZONE_2:
			Chip_DAC_UpdateValue(LPC_DAC, 2);
			break;

		case ZONE_3:
			Chip_DAC_UpdateValue(LPC_DAC, 1);
			break;
		}
	return;
}
void vibrator_OFF(){
	Chip_DAC_UpdateValue(LPC_DAC, 0); //Dac en 0
	return;
}
