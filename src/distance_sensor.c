#define TIME_TRIGGER 10 //micro sec


status_t distance_sensor_trigger(){

	int aux=0;

	//Trigger echos del sensor
	Ultrasonic_Trigger_start(); //negasonic teenage warhead

	while(Timer_status(TIMER_TRIGGER) != OK_TIMER){
			print_uart(aux);
			aux++;
			//delay(1);
	}

  GPIO_off(GPIO_TRIGGER);
	
	return OK_START;

}

//empieza el timer (y match?) y pone en ON el pin del trigger
status_t Ultrasonic_Trigger_start(){
		Timer_start(TIMER_TRIGGER,TIME_TRIGGER);
		GPIO_on(GPIO_TRIGGER);
}

//devuelve el estado del trigger (trigger ok ó sigo contando rey)
status_t Timer_status(TIMER_TRIGGER){

	//opc 1:
	//check IRQ ??

	//opc 2:

	//static uint32_t contador;
	//delay(1000); //1 seg
	//contador ++;
	//if(contador == TIMER_TRIGGER){
		//return OK_TIMER
	//}

	return NOT_OK;
}

status_t distance_sensor_listen_echo(){

	uint32_t contador=0;
	//start timer
	Timer_start(TIMER_ECHOR,TIME_ECHO_MAX);

	while(Timer_status(TIMER_ECHO) != OK_TIMER){ // loopea hasta que timer llega al maximo sin recibir nada

		if(GPIO_READ(INPUT_ECHO) == GPIO_ON){ //si volvio el echo
				
				//sale del while si llego al tiempo maximo o si se puso en OFF el pin
				while( GPIO_READ(INPUT_ECHO) == GPIO_OFF || counter == COUNT_MAX){ 
						//se empieza a contar el tiempo
            //contador
				}
				break; //salgo del while
		}
	}
	return procesamiento_distancia(counter);
}

//Hace el calculo necesario para pasar el tiempo de pulso a distancia
uint32_t procesamiento_distancia(counter){
  //En principio seria valor en us/58
  return round(counter/58);
}

