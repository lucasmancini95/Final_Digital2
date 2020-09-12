#ifndef _DAC_H_
#define _DAC_H_

#include "struct_base.h"
#include "gpdma.h"
#include <stdbool.h>

#define VDDA 3.3 //volts

extern bool flag_T1;
extern bool flag_T2;
extern bool flag_T3;
extern bool flag_T4;
void Enable_DAC();
void Values_DAC(int volts);
//unused
void Enable_DMA();
void cfg_DAC();
void cfg_DMA(LLI_T* p_LLI0,LLI_T* p_LLI1,unsigned int* src_signal_0, unsigned int* src_signal_1);
void signal_fill(unsigned int* src_signal_0, unsigned int* src_signal_1);

#endif
