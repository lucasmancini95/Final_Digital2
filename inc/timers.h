/*
 * timers.h
 *
 *  Created on: 9 sep. 2020
 *      Author: sasha
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "main.h"

#define TIMER0_BASE				0x40084000
#define TIMER_0					((TIMER_T *) TIMER0_BASE)
#define TIMER1_BASE				0x40085000
#define TIMER_1					((TIMER_T *) TIMER1_BASE)
#define TIMER2_BASE				0x400C3000
#define TIMER_2					((TIMER_T *) TIMER2_BASE)
#define TIMER3_BASE				0x400C4000
#define TIMER_3					((TIMER_T *) TIMER3_BASE)
#define CCU1_BASE_TIMER0		0x40051520
#define CCU1_TIMER0				((CCU_T *)CCU1_BASE_TIMER0)
#define CCU1_BASE_TIMER1		0x40051528
#define CCU1_TIMER1				((CCU_T *)CCU1_BASE_TIMER0)
#define CCU1_BASE_TIMER2		0x40051618
#define CCU1_TIMER2				((CCU_T *)CCU1_BASE_TIMER0)
#define CCU1_BASE_TIMER3		0x40051620
#define CCU1_TIMER3				((CCU_T *)CCU1_BASE_TIMER0)

typedef enum {TIMER0, TIMER1, TIMER2, TIMER3} timer_t;

#define MAX_FREQ	204000000  //204 MHz
#define US_FREQ		1000000		//1 MHz => 1us
typedef struct{
	uint32_t IR;	/* Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending*/
	uint32_t TCR;	/* Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR. */
	uint32_t TC; 	/* Timer Counter. The 32 bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR. */
	uint32_t PR;	/* Prescale Register. The Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC. */
	uint32_t PC;	/* Prescale Counter. The 32 bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface. */
	uint32_t MCR;	/* Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs. */
	uint32_t MR[4];	/* Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC. */
	uint32_t CCR;	/* Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place. */
	uint32_t CR[4];	/* Capture Register. CR is loaded with the value of TC when there is an event on the CAPn.0 input. */
	uint32_t EMR;	/* External Match Register. The EMR controls the external match pins MATn.0-3 (MAT0.0-3 and MAT1.0-3 respectively). */
	uint32_t RESERVED_timer[12];
	uint32_t CTCR;	/* Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting. */

}TIMER_T;

typedef struct{
	uint32_t CFG;	/* configuration register */
	unit32_t STAT;	/* status register */
}CCU_T;


void delay_us(unsigned int time);
TIMER_T* TIMER_getPTR(timer_t timer_number);
void Clock_enable(timer_t timer_number);
void TIMER_init(timer_t timer_number);
void TIMER_enable(timer_t timer_number);
void TIMER_disable(timer_t timer_number);
void TIMER_reset(timer_t timer_number);
uint32_t TIMER_ReadCount(timer_t timer_number);

#endif /* TIMERS_H_ */
