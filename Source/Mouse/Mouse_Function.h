
#ifndef __MOUSE_FUNCTION_H__
#define __MOUSE_FUNCTION_H__

#include "Mouse_RamSetting.h"

extern void MS_SensorDPISetting_by_SPI(void);
extern void MS_NFirePage(uint8_t bKeyCode, uint8_t bKeyEvent);
extern void MS_SuspendSetting(void);

/*	GPIO Status Setting function */
void	MS_SetKeyIOPullUp(void);
void	MS_SetKeyIOInputMode(void);
void	KB_ClrSchmitt(void);

void	MS_SetWheelIOInputMode(void);
void	MS_SetWheelIOPullUp(void);
extern  void MS_SetWheelIOSuspend(void);

//Time flag define 
	//================================//	
	//** wMS_Status Mouse Flag      **//
	//================================//		
 	#define mskMS_Timer1msFlag				(0x1<<0)
	#define mskMS_Timer1msFlag_Temp			(0x1<<1) //purpose to count timer flag 2/4/8ms 
	#define mskMS_Timer2msFlag				(0x1<<2)
	#define mskMS_Timer4msFlag				(0x1<<3)
	
	#define mskMS_LEDReflashTimeFlag		(0x1<<4)	
 	#define mskMS_Timer250usFlag			(0x1<<5)
	#define mskMS_ReportRate1msFlag			(0x1<<6)		
	#define mskMS_ReportRate2msFlag			(0x1<<7)	
	
	#define mskMS_ReportRate4msFlag			(0x1<<8)		
	#define mskMS_ReportRate8msFlag			(0x1<<9)	
	#define	mskMS_DPIChangeFlag				(0x1<<10)
	#define mskMS_MacroKeyPlay1msFlag		(0x1<<11)
	
//	#define mskMS_MacroKeyPlay_Done			(0x1<<12)
	#define mskMS_NFireKeyAction			(0x1<<13)
	
#define	__Set_Timer1msFlag					wMS_Status |= mskMS_Timer1msFlag;				//set MS Timer1msFlag	
#define	__Set_Timer1msFlag_Temp				wMS_Status |= mskMS_Timer1msFlag_Temp;			//set MS Timer1msFlag	
#define	__Set_Timer2msFlag					wMS_Status |= mskMS_Timer2msFlag;				//set MS Timer2msFlag	
#define	__Set_Timer4msFlag					wMS_Status |= mskMS_Timer4msFlag;				//set MS Timer4msFlag	
#define	__Set_LEDReflashTimeFlag			wMS_Status |= mskMS_LEDReflashTimeFlag;			//set MS LED Reflash Timer Flag	
#define	__Set_Timer250usFlag				wMS_Status |= mskMS_Timer250usFlag;				//set MS Timer250usFlag	
#define	__Set_TimerMacroPlay1msFlag 		wMS_Status |= mskMS_MacroKeyPlay1msFlag;		//set MS Macro Key play 1ms Flag	


#define	__Set_ReportRate1msFlag				wMS_Status |= mskMS_ReportRate1msFlag;			//set MS Report Rate Timer1msFlag	
#define	__Set_ReportRate2msFlag				wMS_Status |= mskMS_ReportRate2msFlag;			//set MS Report Rate Timer2msFlag	
#define	__Set_ReportRate4msFlag				wMS_Status |= mskMS_ReportRate4msFlag;			//set MS Report Rate Timer4msFlag	
#define	__Set_ReportRate8msFlag				wMS_Status |= mskMS_ReportRate8msFlag;			//set MS Report Rate Timer8msFlag	


#define	__Clear_Timer1msFlag				wMS_Status &= ~(mskMS_Timer1msFlag);
#define	__Clear_Timer1msFlag_Temp			wMS_Status &= ~(mskMS_Timer1msFlag_Temp);
#define	__Clear_Timer2msFlag				wMS_Status &= ~(mskMS_Timer2msFlag);				
#define	__Clear_Timer4msFlag				wMS_Status &= ~(mskMS_Timer4msFlag);				
#define	__Clear_LEDReflashTimeFlag			wMS_Status &= ~(mskMS_LEDReflashTimeFlag);			
#define	__Clear_Timer250usFlag				wMS_Status &= ~(mskMS_Timer250usFlag);	
#define	__Clear_TimerMacroPlay1msFlag 		wMS_Status &= ~mskMS_MacroKeyPlay1msFlag;			//clear MS Macro Key play 1ms Flag	

#define	__Clear_ReportRate1msFlag			wMS_Status &= ~(mskMS_ReportRate1msFlag);			//clear MS Report Rate Timer1msFlag	
#define	__Clear_ReportRate2msFlag			wMS_Status &= ~(mskMS_ReportRate2msFlag);			//clear MS Report Rate Timer2msFlag	
#define	__Clear_ReportRate4msFlag			wMS_Status &= ~(mskMS_ReportRate4msFlag);			//clear MS Report Rate Timer4msFlag	
#define	__Clear_ReportRate8msFlag			wMS_Status &= ~(mskMS_ReportRate8msFlag);			//clear MS Report Rate Timer8msFlag	

#endif //__MOUSE_FUNCTION_H__


