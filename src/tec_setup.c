#include "tec_setup.h"
#include "gpio_set.h"
#include "scu_set.h"
#include "struct_base.h"

void TEC_cfg(tec_t tec){
	
	unsigned char port, pin, port_gpio, pin_gpio, function, ezi;
	port=1; //todas las teclas son port 1
	function=0x0;
	ezi=6;

	if(tec==TEC1 || tec==TEC2 || tec==TEC3){
		port_gpio=0;
		if(tec==TEC1){
			pin=0;
			pin_gpio=4;
		}
		else if(tec==TEC2){
			pin=1;
			pin_gpio=8;
		}
		else if(tec==TEC3){
			pin=2;
			pin_gpio=9;
		}
	}
	else if(tec==TEC4){
		pin=6;
		port_gpio=1;
		pin_gpio=9;
	}



	SCU_SetPin(SCU, port, pin, function);

	SCU_SetEZI(SCU, port, pin, ezi);
	GPIO_SetPinDIR(GPIO, port_gpio, pin_gpio, INPUT);
}

state_t TEC_GetState(tec_t tec){

	unsigned char port_gpio, pin_gpio;

	if(tec==TEC1 || tec==TEC2 || tec==TEC3){
		port_gpio=0;
		if(tec==TEC1){
			pin_gpio=4;
		}
		else if(tec==TEC2){
			pin_gpio=8;
		}
		else if(tec==TEC3){
			pin_gpio=9;
		}
	}
	else if(tec==TEC4){
		port_gpio=1;
		pin_gpio=9;
	}
	return GPIO_GetPinState(GPIO, port_gpio, pin_gpio);
}

void TEC_ALL(){
	TEC_cfg(TEC1);
	TEC_cfg(TEC2);
	TEC_cfg(TEC3);
	TEC_cfg(TEC4);
}



