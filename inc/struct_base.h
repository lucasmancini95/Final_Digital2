/*
Este .h tendrá un estructura que apunta directamente a GPIO_BASE y a SCU_BASE por lo tanto moviendome por los campos (que tendran
el mismo tamaño o separación como estan en el micro) me voy a mover directamente por los registros en vez de tener que cargar
 y configurar los offsets.
*/
#ifndef _STRUCT_BASE_H_
#define _STRUCT_BASE_H_

#define SCU_BASE			0X40086000 //direccion base del registro
#define SCU 				((SCU_T *) SCU_BASE) //Apunto la struct a la direccion de memoria base de los seteo de pines (creo)
#define GPIO_PORT_BASE		0x400F4000 //direccion base del registro
#define GPIO 				((GPIO_T *) GPIO_PORT_BASE) //Apunto la struct a la direccion de memoria base de los gpio
#define PIN_INT_BASE		0x40087000
#define PIN_INT 			((PIN_INT_T *) PIN_INT_BASE)
#define NVIC_BASE			0xE000E100
#define NVIC 				((_NVIC_T *) NVIC_BASE)
#define DAC_BASE			0x400E1000
#define DAC 				((DAC_T *) DAC_BASE) 
//por ejemplo si yo quiero usar el led 1 tengo que poner dentro del main (SCU->SFSP)[2][10] = 0x0 lo estoy declarando como gpio
//y lo estoy poniendo todas los demas valores tambien en 0

typedef struct {
	unsigned int  SFSP[16][32];
	unsigned int  RESERVED0[256];
	unsigned int  SFSCLK[4];
	unsigned int  RESERVED16[28];
	unsigned int  SFSUSB;	
	unsigned int  SFSI2C0;
	unsigned int  ENAIO[3];
	unsigned int  RESERVED17[27];
	unsigned int  EMCDELAYCLK;
	unsigned int  RESERVED18[63];
	unsigned int  PINTSEL[2];
} SCU_T;

typedef struct {			
	unsigned char B[128][32];
	unsigned int W[32][32];
	unsigned int DIR[32];
	unsigned int MASK[32];
	unsigned int PIN[32];
	unsigned int MPIN[32];
	unsigned int SET[32];
	unsigned int CLR[32];	
	unsigned int NOT[32];	
} GPIO_T;

typedef struct{
	int ISEL; //0 = Edge sensitive ||1 = Level sensitive || bits del 0 al 7.
	int IENR;
	int SIENR;
	int CIENR;
	int IENF;
	int SIENF;
	int CIENF;
	int RISE;
	int FALL;
	int IST;
} PIN_INT_T;
//pag 452 (de pdf) user manual

typedef struct{
	int ISER[8];
	int RESERVED0[24];
	int ICER[8];
	int RESERVED1[24];
	int ISPR[8];
	int RESERVED2[24];
	int ICPR[8];
	int RESERVED3[24];
	int IABR[8];
	int RESERVED4[56];
	unsigned int IP[240];
	int RESERVED5[644];
	int STIR;
} _NVIC_T;
//pag 253 Definitive guide


typedef struct{
	unsigned int CR; //DAC register (tiene el dato convertido)
	unsigned int CTRL; //DAC control register
	unsigned int CNTVAL;	//DAC counter value register
}DAC_T;
//pag 1350 User Manual
#endif
