
#include <SN32F240B.h>
#include <SN32F200_Def.h>
#include "Timer.h"
#include "..\Mouse\Mouse_Function.h"
#include "..\LED\LED_RamSetting.h"

/*****************************************************************************
* Function			: Timer_Init
* Description		: Initialize CT16B0 and interrupt. The interval time is 250us 
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void Timer_Init(void)
{
	//Enable P_CLOCK for CT16B0.
	SN_SYS1->AHBCLKEN_b.CT16B0CLKEN = 1;

	//CT16B0 PCLK prescalar setting
	//SN_SYS1->APBCP0_b.CT16B0PRE = 0x00;		//PCLK = HCLK/1
	
	//Set MR0 value for 250us period 
	SN_CT16B0->MR0 = 12000;						//(12000 * 1 / 48000000)s = 0.25ms

	//Set MR0 match as TC RESET, and enable MR0 interrupt
	SN_CT16B0->MCTRL = ((0x01<<1)|(0x01<<0));						

	//Set CT16B0 as the up-counting mode.
	SN_CT16B0->TMRCTRL = mskCT16Bn_CRST;

	//Wait until timer reset done.
	while (SN_CT16B0->TMRCTRL & mskCT16Bn_CRST);	

	//Let TC start counting.
	SN_CT16B0->TMRCTRL |= mskCT16Bn_CEN;			
	
	NVIC_ClearPendingIRQ(CT16B0_IRQn);
	//Enable CT16B0's NVIC interrupt.	
	NVIC_EnableIRQ(CT16B0_IRQn);
	
}

/*****************************************************************************
* Function	    : CT16B0_IRQHandler
* Description  	: 250us Timer ISR, CT16B0 timer initail after USB enumeration
* Input(Global)	: None
* Input(Local)  : None
* Output(Global): None
* Return(Local)	: None
*****************************************************************************/
__irq void CT16B0_IRQHandler(void)
{
	SN_CT16B0->IC = 0x01;		//MR0 interrupt clear
	
//	if(bNDT_Flag == 1)			//Check NDT
//	{
//		if(SN_SYS0->NDTSTS_b.NDT5V_DET == 1)
//		{
//			bNDT_Cnt = 0;
//		}
//		else
//		{
//		  bNDT_Cnt++;
//			if(bNDT_Cnt==3400)
//			{
//				bNDT_Flag = 0;
//			}
//		}
//	}
	
	__Set_Timer250usFlag
	
	bMS_TimeFrame_CNT++;
	//** Staggerd macro key 1ms flag and ms report rate 1ms flag   
	bMS_MacroTimeFrame_CNT++;
	
	if(bMS_TimeFrame_CNT==4)
	{
		bMS_TimeFrame_CNT = 0;									//** clr timer count
		//** Set MS 1ms timer Flag	, and it will clear at sensor state
		__Set_Timer1msFlag
		__Set_Timer1msFlag_Temp
		__Set_ReportRate1msFlag	
	}
		
//	if(bMS_MacroTimeFrame_CNT==4)
//	{
//		bMS_MacroTimeFrame_CNT = 0;									//** clr timer count
//		//** Set Macro Play Flag each 1ms whem macro action flag set
//		if(wKB_MacroKeyStatus & mskKB_Macro_Action)
//		{
//			__Set_TimerMacroPlay1msFlag
//		}
//	}		
	
	if(wMS_Status & mskMS_Timer1msFlag_Temp)		//1ms
	{
		//clear mouse 1ms timer flag for counting timer 2/4/8ms flag
		__Clear_Timer1msFlag_Temp
		
		bMS_TimeFrame_2ms ++;
		bMS_TimeFrame_4ms ++;			
		bMS_TimeFrame_8ms ++;	
		dbMS_LED_ReflashTimeFrame++;
    
		if(bMS_TimeFrame_2ms == 2)
		{
			bMS_TimeFrame_2ms = 0;	
			__Set_Timer2msFlag
			__Set_ReportRate2msFlag	
		}
		if(bMS_TimeFrame_4ms == 4)
		{
			bMS_TimeFrame_4ms = 0;				
			__Set_Timer4msFlag
			__Set_ReportRate4msFlag				
		}			
		if(bMS_TimeFrame_8ms == 8)
		{
			bMS_TimeFrame_8ms = 0;				
			__Set_ReportRate8msFlag				
		}		
		if(dbMS_LED_ReflashTimeFrame >= (8 + bLED_DataRefreshTime_Reload))
		{
			dbMS_LED_ReflashTimeFrame = 0;				
			__Set_LEDReflashTimeFlag				
		}		
	}
	
}





