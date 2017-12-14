/*++

Copyright (c) 2013-2014 Razer Ltd.
All rights reserved. This program contains proprietary and confidential information.

Module Name:
  wdt.c

Compiler:
  Keil Software µVision v5.01, with NXP Semiconductor LPC11U3x proccessor support.

Abstract:
  This file provides the Watchdog Timer support.

--*/

#include "wdt.h"
#include "Type.h"

void wdt_initialization(U32 mode)
/*++

Function Description:
  This function initializes the Watchdog Timer mode, to reset the MCU if it times
  out.

Arguments:
  WDTMode - 0: Generate Interrupt only.
            1: Force MCU reset on expiration.
Returns:
  NONE

--*/
{
  LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 15);                 // Set Watchdog Timer mode
  wdt_configuration();
  LPC_WWDT->MOD |= WDT_MODE_RESET;						            // A watchdog time out will cause a chipset reset
}


void wdt_configuration  (void)
/*++

Function Description:
  This function configures the clock for the Watchdog Timer.

Arguments:
  NONE

Returns:
  NONE

--*/
{  
  LPC_SYSCON->CLKOUTSEL = 0x01;	                          // Select Main clock 
  LPC_SYSCON->CLKOUTUEN = 0x01;		                        // Update clock 
  LPC_SYSCON->CLKOUTUEN = 0x00;		                        // Toggle update register once 
  LPC_SYSCON->CLKOUTUEN = 0x01;
  while ( !(LPC_SYSCON->CLKOUTUEN & 0x01) );		          // Wait until updated 
  LPC_SYSCON->CLKOUTDIV = 1;			                        // Divided by 1 
  LPC_SYSCON->PDRUNCFG &= ~(0x1<<6);                      //Let WDT clock run 
  return;
}


void wdt_resetTimer	(void)
/*++Function Description:
  This function feeds the Watchdog Timer, to prevent the MCU reset.

Arguments:
  NONE

Returns:
  NONE

--*/
{
  __disable_irq();                                        // Disable MCU interrupts
  LPC_WWDT->FEED = 0xAA;
  LPC_WWDT->FEED = 0x55;
  __enable_irq();                                         // Enable MCU interrupts
}


void wdt_startTimer(U32 timeout)
/*++

Function Description:
  This function starts Watchdog Timer activity with given timeout value.

Arguments:
  timeout - Timeout value (us).

Returns:
  NONE

--*/
{
	#if releaseFW
  wdt_setTimeout(timeout);
  LPC_WWDT->MOD |= WDT_WDMOD_WDEN;                         // Enable Watchdog Timer
  wdt_resetTimer();
	#endif
}

U8 wdt_setTimeout(U32 timeout)
/*++

Function Description:
  This function sets Watchdog Timer timeout value and Watchdog Timer mode.

Arguments:
  timeout - Timeout value (us).

Returns:
  status - SUCCESS or FAILURE.

--*/
{
  U32 t;

  t = ((48) * (timeout / 4));
  if ((t >= WDT_TIMEOUT_MIN) && (t <= WDT_TIMEOUT_MAX)) { // Check if it valid
    LPC_WWDT->TC = t;
    return SUCCESS;
  }
  return FAILURE;
}

