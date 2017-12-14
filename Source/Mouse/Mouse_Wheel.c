/*_____ I N C L U D E S ____________________________________________________*/
#include 	"Mouse_Wheel.h"
#include 	"Mouse_RamSetting.h"
#include 	"Mouse_Const.h"
#include 	"Mouse_Function.h"
#include 	"Mouse_IOSetting.h"

#include 	"Utility.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/


/*****************************************************************************
* Function			: MS_WheelInit
* Description		: MS_WheelInit
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_WheelInit(void)
{
	uint8_t bWheelStatus = 0;
	
	MS_SetWheelIOInputMode();
	MS_SetWheelIOPullUp();	
	//Delay 40us to make sure pull-up ok
	UT_MAIN_DelayNx10us(4);	
	
	if (MS_WHEEL_PM_0->DATA & mskMS_WHEEL_IO_PM_A)
	{
		bWheelStatus |= mskWHEEL_A_BIT0; 
	}
	if (MS_WHEEL_PM_0->DATA & mskMS_WHEEL_IO_PM_B)
	{
		bWheelStatus |= mskWHEEL_B_BIT1; 
	}
	bWHEEL_PreviousStatus	= bWheelStatus;
	//** Wheel Initial status
	bWHEEL_DebounceStatus |= WHEEL_NEW_DEBOUNCE_VALUE;	
}

/*****************************************************************************
* Function			: MN_WheelState
* Description		: MN_WheelState
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MN_WheelState(void)
{
	//** Read MS IO status
	bWHEEL_WheelStatus &= ~mskWheel_CurrentStatus;
	
	if (MS_WHEEL_PM_0->DATA & mskMS_WHEEL_IO_PM_A)
	{
		bWHEEL_WheelStatus |= mskWHEEL_A_BIT0; 
	}
	if (MS_WHEEL_PM_0->DATA & mskMS_WHEEL_IO_PM_B)
	{
		bWHEEL_WheelStatus |= mskWHEEL_B_BIT1; 
	}


	switch(bWHEEL_WheelStatus & mskWheel_CurrentStatus)
	{
		case S_WHEEL_BA_LL:
		
				if((bWHEEL_PreviousStatus & mskWheel_StableStatus)!= WHEEL_BA_STABLE_LL)
				{	
					if(((bWHEEL_PreviousStatus & mskWheel_CurrentStatus) == WHEEL_BA_LL) && ((bWHEEL_DebounceStatus & mskLOW_NIBBLE) != COUNT_FINISH))
					{						
						bWHEEL_DebounceStatus--;
						//** First time stable , setting Just Stable Flag 
						if(((bWHEEL_DebounceStatus & mskLOW_NIBBLE) == COUNT_FINISH) && (!(bWHEEL_DebounceStatus & mskWheel_JustStable)))
						{
							bWHEEL_DebounceStatus |= mskWheel_JustStable;	
							//Clear State and write in new status
							bWHEEL_PreviousStatus &= ~mskWheel_StableStatus;							
							bWHEEL_PreviousStatus |= WHEEL_BA_STABLE_LL;
						}						
					}
				}			
				bWHEEL_PreviousStatus &= ~mskWheel_CurrentStatus;				
				bWHEEL_PreviousStatus |= WHEEL_BA_LL;
			break;
		
		case S_WHEEL_BA_LH:
			
				if((bWHEEL_PreviousStatus & mskWheel_StableStatus) == WHEEL_BA_STABLE_LL)
				{
					bWHEEL_DebounceStatus = (mskWheel_Clockwise|WHEEL_NEW_DEBOUNCE_VALUE);
				}
				else if((bWHEEL_PreviousStatus & mskWheel_StableStatus) == WHEEL_BA_STABLE_HH) 
				{
					bWHEEL_DebounceStatus = (mskWheel_CounterClockwise|WHEEL_NEW_DEBOUNCE_VALUE);
				}				
				else
				{
					bWHEEL_DebounceStatus &= ~mskLOW_NIBBLE;
					bWHEEL_DebounceStatus |= WHEEL_NEW_DEBOUNCE_VALUE;										
				}

				bWHEEL_PreviousStatus &= ~mskWheel_CurrentStatus;							
				bWHEEL_PreviousStatus |= WHEEL_BA_LH;		
			break;
		
		case S_WHEEL_BA_HL://** B signal = H, A signal = L	
				
				if((bWHEEL_PreviousStatus & mskWheel_StableStatus) == WHEEL_BA_STABLE_LL)
				{				
					bWHEEL_DebounceStatus = (mskWheel_CounterClockwise|WHEEL_NEW_DEBOUNCE_VALUE);
				}
				else if((bWHEEL_PreviousStatus & mskWheel_StableStatus) == WHEEL_BA_STABLE_HH) 
				{
					bWHEEL_DebounceStatus = (mskWheel_Clockwise|WHEEL_NEW_DEBOUNCE_VALUE);
				}				
				else //For setting first time
				{
					bWHEEL_DebounceStatus &= ~mskLOW_NIBBLE;
					bWHEEL_DebounceStatus |= WHEEL_NEW_DEBOUNCE_VALUE;										
				}					

				bWHEEL_PreviousStatus &= ~mskWheel_CurrentStatus;							
				bWHEEL_PreviousStatus |= WHEEL_BA_HL;	
			break;
		
		case S_WHEEL_BA_HH:
				if((bWHEEL_PreviousStatus & mskWheel_StableStatus)!= WHEEL_BA_STABLE_HH)
				{		
					if(((bWHEEL_PreviousStatus & mskWheel_CurrentStatus) == WHEEL_BA_HH) && ((bWHEEL_DebounceStatus & mskLOW_NIBBLE) != COUNT_FINISH))
					{	
						bWHEEL_DebounceStatus--;
						//** First time stable , setting Just Stable Flag 
						if(((bWHEEL_DebounceStatus & mskLOW_NIBBLE) == COUNT_FINISH) && (!(bWHEEL_DebounceStatus & mskWheel_JustStable)))
						{
							bWHEEL_DebounceStatus |= mskWheel_JustStable;	
							//Clear State and write in new status
							bWHEEL_PreviousStatus &= ~mskWheel_StableStatus;							
							bWHEEL_PreviousStatus |= WHEEL_BA_STABLE_HH;							
						}						
					}
				}
				bWHEEL_PreviousStatus &= ~mskWheel_CurrentStatus;						
				bWHEEL_PreviousStatus |= WHEEL_BA_HH;					
			break;	
				
		default:
				MS_WheelInit();
			break;
	}

	//** Upload Wheel Data to Mouse Buffer
	if(bWHEEL_DebounceStatus & mskWheel_JustStable)
	{
		bWHEEL_DebounceStatus &= ~mskWheel_JustStable;	
		
		if(bWHEEL_DebounceStatus & mskWheel_Clockwise)
		{
			bWHEEL_DebounceStatus &= ~mskWheel_Clockwise;				
			b_aryKB_Mouse[5] = MS_WHEEL_CW;				
			wKB_SendStatus |= mskKB_SendMouseFlag;
		}
		else if(bWHEEL_DebounceStatus & mskWheel_CounterClockwise) 
		{
			bWHEEL_DebounceStatus &= ~mskWheel_CounterClockwise;
			b_aryKB_Mouse[5] = MS_WHEEL_CCW;		
			wKB_SendStatus |= mskKB_SendMouseFlag;				
		}
	}
	
	bMN_State = S_MAIN_IDLE_STATE;			
			
}



