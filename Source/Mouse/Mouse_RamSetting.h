

#ifndef __MOUSE_RAMSETTING_H__
#define __MOUSE_RAMSETTING_H__
#include	<SN32F240B.h>
#include 	"Mouse_Const.h"

extern  uint8_t		bMN_State;

extern  uint8_t		bKB_State;

extern	uint32_t 	wKB_SendStatus;
extern  uint32_t	wMS_Status;

extern  uint8_t 	bMS_NFireKeyCode;
extern  uint8_t 	bMS_NFireKeyToggleBit;
extern  uint8_t 	bMS_NFireOperationCounter;

extern  uint8_t		b_aryKB_Debounce[MS_COLUMN_SIZE][MS_ROW_SIZE];

extern  uint8_t 	b_aryKB_Mouse[];

extern  uint8_t		b_aryKB_Consumer[];
extern  uint8_t		bKB_System;
extern  uint8_t		b_aryKB_VendorKey[];
extern  uint8_t		b_aryKB_ExtraFunctionKey[];
extern  uint8_t 	b_aryKB_UsageKey_Standard[];


extern uint8_t		bMS_TimeFrame_CNT;
extern uint8_t		bMS_MacroTimeFrame_CNT;
extern uint8_t		bMS_TimeFrame_2ms;
extern uint8_t		bMS_TimeFrame_4ms;
extern uint8_t		bMS_TimeFrame_8ms;
extern volatile uint16_t	dbMS_LED_ReflashTimeFrame;

extern uint8_t		bWHEEL_WheelStatus ;
extern uint8_t		bWHEEL_PreviousStatus;
extern uint8_t		bWHEEL_DebounceStatus; //** Bit7 : wheel Clockwise bit
																	//** Bit6 : wheel CounterClockwise bit	
extern uint8_t 		bMSReportRate;
extern uint8_t		bMSDPI_Index;

extern uint8_t		b_arySPI_Rx_Fifo[];
extern uint8_t 		b_arySPI_Tx_Fifo[];

#endif //__MOUSE_RAMSETTING_H__

