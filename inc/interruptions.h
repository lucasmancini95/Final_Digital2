#ifndef _INTERRUPTIONS_H_
#define _INTERRUPTIONS_H_
#include "struct_base.h"
typedef enum {
	/* -------------------------  Cortex-M3 Processor Exceptions Numbers  ----------------------------- */
	Reset_IRQn                        = -15,/*!<   1  Reset Vector, invoked on Power up and warm reset */
	NonMaskableInt_IRQn               = -14,/*!<   2  Non maskable Interrupt, cannot be stopped or preempted */
	HardFault_IRQn                    = -13,/*!<   3  Hard Fault, all classes of Fault */
	MemoryManagement_IRQn             = -12,/*!<   4  Memory Management, MPU mismatch, including Access Violation and No Match */
	BusFault_IRQn                     = -11,/*!<   5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
	UsageFault_IRQn                   = -10,/*!<   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition */
	SVCall_IRQn                       = -5,	/*!<  11  System Service Call via SVC instruction */
	DebugMonitor_IRQn                 = -4,	/*!<  12  Debug Monitor                    */
	PendSV_IRQn                       = -2,	/*!<  14  Pendable request for system service */
	SysTick_IRQn                      = -1,	/*!<  15  System Tick Timer                */

	/* ---------------------------  LPC18xx/43xx Specific Interrupt Numbers  ------------------------------- */
	DAC_IRQn                          =   0,/*!<   0  DAC                              */
	RESERVED0_IRQn                    =   1,
	DMA_IRQn                          =   2,/*!<   2  DMA                              */
	RESERVED1_IRQn                    =   3,/*!<   3  EZH/EDM                          */
	RESERVED2_IRQn                    =   4,
	ETHERNET_IRQn                     =   5,/*!<   5  ETHERNET                         */
	SDIO_IRQn                         =   6,/*!<   6  SDIO                             */
	LCD_IRQn                          =   7,/*!<   7  LCD                              */
	USB0_IRQn                         =   8,/*!<   8  USB0                             */
	USB1_IRQn                         =   9,/*!<   9  USB1                             */
	SCT_IRQn                          =  10,/*!<  10  SCT                              */
	RITIMER_IRQn                      =  11,/*!<  11  RITIMER                          */
	TIMER0_IRQn                       =  12,/*!<  12  TIMER0                           */
	TIMER1_IRQn                       =  13,/*!<  13  TIMER1                           */
	TIMER2_IRQn                       =  14,/*!<  14  TIMER2                           */
	TIMER3_IRQn                       =  15,/*!<  15  TIMER3                           */
	MCPWM_IRQn                        =  16,/*!<  16  MCPWM                            */
	ADC0_IRQn                         =  17,/*!<  17  ADC0                             */
	I2C0_IRQn                         =  18,/*!<  18  I2C0                             */
	I2C1_IRQn                         =  19,/*!<  19  I2C1                             */
	RESERVED3_IRQn                    =  20,
	ADC1_IRQn                         =  21,/*!<  21  ADC1                             */
	SSP0_IRQn                         =  22,/*!<  22  SSP0                             */
	SSP1_IRQn                         =  23,/*!<  23  SSP1                             */
	USART0_IRQn                       =  24,/*!<  24  USART0                           */
	UART1_IRQn                        =  25,/*!<  25  UART1                            */
	USART2_IRQn                       =  26,/*!<  26  USART2                           */
	USART3_IRQn                       =  27,/*!<  27  USART3                           */
	I2S0_IRQn                         =  28,/*!<  28  I2S0                             */
	I2S1_IRQn                         =  29,/*!<  29  I2S1                             */
	RESERVED4_IRQn                    =  30,
	RESERVED5_IRQn                    =  31,
	PIN_INT0_IRQn                     =  32,/*!<  32  PIN_INT0                         */
	PIN_INT1_IRQn                     =  33,/*!<  33  PIN_INT1                         */
	PIN_INT2_IRQn                     =  34,/*!<  34  PIN_INT2                         */
	PIN_INT3_IRQn                     =  35,/*!<  35  PIN_INT3                         */
	PIN_INT4_IRQn                     =  36,/*!<  36  PIN_INT4                         */
	PIN_INT5_IRQn                     =  37,/*!<  37  PIN_INT5                         */
	PIN_INT6_IRQn                     =  38,/*!<  38  PIN_INT6                         */
	PIN_INT7_IRQn                     =  39,/*!<  39  PIN_INT7                         */
	GINT0_IRQn                        =  40,/*!<  40  GINT0                            */
	GINT1_IRQn                        =  41,/*!<  41  GINT1                            */
	EVENTROUTER_IRQn                  =  42,/*!<  42  EVENTROUTER                      */
	C_CAN1_IRQn                       =  43,/*!<  43  C_CAN1                           */
	RESERVED6_IRQn                    =  44,
	RESERVED7_IRQn                    =  45,/*!<                                       */
	ATIMER_IRQn                       =  46,/*!<  46  ATIMER                           */
	RTC_IRQn                          =  47,/*!<  47  RTC                              */
	RESERVED8_IRQn                    =  48,
	WWDT_IRQn                         =  49,/*!<  49  WWDT                             */
	RESERVED9_IRQn                    =  50,
	C_CAN0_IRQn                       =  51,/*!<  51  C_CAN0                           */
	QEI_IRQn                          =  52,/*!<  52  QEI                              */
} interrupt_t;

void Enable_NVIC(interrupt_t interrnum); //habilitar interrupciones en el core de ARM
void SelectEdge_PIN_INT(int ISELnum);//selecciona sensibilidad por flanco (modifica un bit del 0 al 7)
void Enable_PIN_INT(int SIENRnum);
void Select_GPIO_interrupt(unsigned char port, unsigned char pin, unsigned char interrnum);

#endif
