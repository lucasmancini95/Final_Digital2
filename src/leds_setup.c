#include "leds_setup.h"
#include "gpio_set.h"
#include "scu_set.h"

int toggle=0;

void LED_cfg(led_t led){
	unsigned char port,pin,port_gpio,pin_gpio,function;
	port=2; //todos los leds son port 2

	if(led==L0R || led==L0G || led==L0B){
		function=0x4;
		port_gpio=5;
		
		if(led==L0R){
			pin=0;
			pin_gpio=0;
		}
		else if(led==L0G){
			pin=1;
			pin_gpio=1;
		}
		else if(led==L0B){
			pin=2;
			pin_gpio=2;
		}
	}
	else if(led==L1 || led==L2 || led== L3){
		function=0x0;
		if(led==L1){
			pin=10;
			port_gpio=0;
			pin_gpio=14;
		}
		else if(led==L2){
			pin=11;
			port_gpio=1;
			pin_gpio=11;
		}
		else if(led==L3){
			pin=12;
			port_gpio=1;
			pin_gpio=12;
		}
	}
	SCU_SetPin(SCU, port, pin, function);
	GPIO_SetPinDIR(GPIO,port_gpio, pin_gpio,OUTPUT);
}

void LED_high(led_t led){

	unsigned char port,pin,port_gpio,pin_gpio,function;
		
		if(led==L0R || led==L0G || led==L0B){
		port_gpio=5;
		
		if(led==L0R){
			pin_gpio=0;
		}
		else if(led==L0G){
			pin_gpio=1;
		}
		else if(led==L0B){
			pin_gpio=2;
		}
	}
	else if(led==L1 || led==L2 || led== L3){
		
		if(led==L1){
			port_gpio=0;
			pin_gpio=14;
		}
		else if(led==L2){
			port_gpio=1;
			pin_gpio=11;
		}
		else if(led==L3){
			port_gpio=1;
			pin_gpio=12;
		}
	}
	GPIO_SetPin(GPIO, port_gpio, pin_gpio, HIGH);
}

void LED_low(led_t led){

	unsigned char port,pin,port_gpio,pin_gpio;
		
		if(led==L0R || led==L0G || led==L0B){
		port_gpio=5;
		
		if(led==L0R){
			pin_gpio=0;
		}
		else if(led==L0G){
			pin_gpio=1;
		}
		else if(led==L0B){
			pin_gpio=2;
		}
	}
	else if(led==L1 || led==L2 || led== L3){
		
		if(led==L1){
			port_gpio=0;
			pin_gpio=14;
		}
		else if(led==L2){
			port_gpio=1;
			pin_gpio=11;
		}
		else if(led==L3){
			port_gpio=1;
			pin_gpio=12;
		}
	}
	GPIO_SetPin(GPIO, port_gpio, pin_gpio, LOW);
}

void LED_toggle(led_t led){
	unsigned char port,pin,port_gpio,pin_gpio;

			if(led==L0R || led==L0G || led==L0B){
			port_gpio=5;

			if(led==L0R){
				pin_gpio=0;
			}
			else if(led==L0G){
				pin_gpio=1;
			}
			else if(led==L0B){
				pin_gpio=2;
			}
		}
		else if(led==L1 || led==L2 || led== L3){

			if(led==L1){
				port_gpio=0;
				pin_gpio=14;
			}
			else if(led==L2){
				port_gpio=1;
				pin_gpio=11;
			}
			else if(led==L3){
				port_gpio=1;
				pin_gpio=12;
			}
		}
	GPIO_TogglePin(GPIO, port_gpio, pin_gpio);

}

void LED_ALL(){
	LED_cfg(L1);
	LED_cfg(L2);
	LED_cfg(L3);
	LED_cfg(L0R);
	LED_cfg(L0G);
	LED_cfg(L0B);
	return;
}

void LED_ALL_OFF(){
	LED_low(L1);
	LED_low(L2);
	LED_low(L3);
	LED_low(L0R);
	LED_low(L0G);
	LED_low(L0B);
	return;
}
