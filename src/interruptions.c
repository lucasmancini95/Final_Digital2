#include "interruptions.h"
#include "struct_base.h"

void Enable_NVIC(interrupt_t interrnum){
	/*
	Esta funcion habilita la interrupcion del core de ARM, en el caso de NXP, solo tenemos interrupciones en los registros 
	ISER 0 Y 1. La interrupcion se la pasamos con un enum que tiene los numeros de interrupciones de NXP 
	*/

	unsigned char isernum;

	if(0<=interrnum && interrnum<=31){
		isernum=0;
	}
	else if (32<=interrnum && interrnum<=63){
		isernum=1;
		interrnum -= 32; //esto funciona como x=x-4
		//resto 32 para poder usarlo como desplazamiento dentro de iser.
	}
	else{
		return;
	}

	(NVIC->ISER)[isernum]|=(1<<(unsigned int)interrnum);

}
void SelectEdge_PIN_INT(int ISELnum){
	if(ISELnum <=7){
		(PIN_INT->ISEL) &= ~(0x01<<ISELnum);
		//si quiero un 0 en alguna posicion tengo que poner un 1 en una pos, negarlo y AND
		//pues 0 es edge sensivility
	}
}
void Enable_PIN_INT(int SIENRnum){
	if(SIENRnum <=7){
		(PIN_INT->SIENR)|= (0x01<<SIENRnum); 
	}
	SelectEdge_PIN_INT(SIENRnum);
}

void Select_GPIO_interrupt(unsigned char port, unsigned char pin, unsigned char interrnum){
	int desp=(interrnum & 3) << 3;
	(SCU->PINTSEL)[interrnum >> 2]|= ( ( ( port & 7 ) << 5) | (pin & 0x1F) ) << desp;
}
