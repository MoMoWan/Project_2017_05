
#include "Mouse_RamSetting.h"

//**  Main State Machine variable
uint8_t		bMN_State;
//**  KeyScan State Machine variable
uint8_t		bKB_State;

uint32_t 	wKB_SendStatus;

//**  Mouse Status variable
uint32_t	wMS_Status;

uint8_t		bMS_NFireKeyCode;
uint8_t		bMS_NFireKeyToggleBit;
uint8_t		bMS_NFireOperationCounter;

uint8_t		b_aryKB_Debounce[MS_COLUMN_SIZE][MS_ROW_SIZE];

uint8_t 	b_aryKB_Mouse[7];

uint8_t		b_aryKB_Consumer[2];
uint8_t		bKB_System;
uint8_t		b_aryKB_VendorKey[2];
uint8_t		b_aryKB_ExtraFunctionKey[2];
uint8_t 	b_aryKB_UsageKey_Standard[7];

uint8_t		bMS_TimeFrame_CNT = 0;
uint8_t		bMS_MacroTimeFrame_CNT;
uint8_t		bMS_TimeFrame_2ms;
uint8_t		bMS_TimeFrame_4ms;
uint8_t		bMS_TimeFrame_8ms;
volatile uint16_t	dbMS_LED_ReflashTimeFrame;

//===========================//
//**  Wheel Variable         //
//===========================//
uint8_t		bWHEEL_WheelStatus = 0;
uint8_t		bWHEEL_PreviousStatus;
uint8_t		bWHEEL_DebounceStatus=0; //** Bit7 : wheel Clockwise bit
																	//** Bit6 : wheel CounterClockwise bit	
//Sensor Variable
uint8_t 	bMSReportRate;
uint8_t		bMSDPI_Index;

uint8_t		b_arySPI_Rx_Fifo[12];
uint8_t 	b_arySPI_Tx_Fifo[8];




