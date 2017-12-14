/*++

Copyright (c) 2012-2014 Razer Ltd.
All rights reserved. This program contains proprietary and confidential information.

Module Name:
 timer.h

Compiler:
  Keil Software µVision v5.11, with NXP Semiconductor LPC11U2x proccessor support.

Abstract:


--*/
#ifndef __TIMER_H_ 
#define __TIMER_H_



#define TIMER_16_0_Num        0                           // Timer 16_0  number
#define TIMER_16_1_Num        1
#define TIMER_32_0_Num        0
#define TIMER_32_1_Num        1

void TIMER16_0_IRQHandler(void);
void TIMER16_1_IRQHandler(void);
void Tmr_initialiation(void);

#endif /* end __TIMER16_H */
