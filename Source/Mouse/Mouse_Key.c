/*_____ I N C L U D E S ____________________________________________________*/
#include 	"Mouse_Key.h"

#include 	"Mouse_Const.h"
#include 	"Mouse_Function.h"
#include 	"Mouse_IOSetting.h"
#include 	"Mouse_RamSetting.h"
#include 	"Mouse_KeyCode.h"
#include 	"Mouse_Table.h"
#include 	"LED_RamSetting.h"
#include 	"LED_Const.h"
#include 	"variables.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function			: MN_KeyScanState
* Description		: Dispatch to each state procedure according to KB_StateMachine
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MN_KeyScanState(void)
{
	switch (bKB_State)				 
	{	
		case S_MS_SCAN_STATE:		
			MS_ScanState();				
			break;
		
		case S_MS_CHECK_MATRIX_MAP:			
			MS_CheckMatrixState();			
			break;
		
		case S_KB_NFIRE_STATE:			
			MS_NFireState();		
			break;			
	
		default:	
			bMN_State = S_MAIN_BOOT_STATE; //Error condition, set Main_State into BOOT STATE
			break;
	}
}

/*****************************************************************************
* Function			: MS_ScanState
* Description		: MS_ScanState
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_ScanState(void)
{
	volatile uint8_t bKeyMap ;
	
	//====================================//
	// Read and debounce for Keys	0-7   //
	//====================================//	
	bKeyMap = 0x00;
	// Read MS IO status
	if (!(MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_0))
	{
		bKeyMap |= BIT_0; 
	}
	if (!(MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_1))
	{
		bKeyMap |= BIT_1; 
	}
	if (!(MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_2))
	{
		bKeyMap |= BIT_2; 
	}
	if (!(MS_KEY_PM_1->DATA & mskMS_KEY_IO_PM_3))
	{
		bKeyMap |= BIT_3; 
	}
	if (!(MS_KEY_PM_1->DATA & mskMS_KEY_IO_PM_4))
	{
		bKeyMap |= BIT_4; 
	}
	if (!(MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_5))
	{
		bKeyMap |= BIT_5; 
	}
	if (!(MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_6))
	{
		bKeyMap |= BIT_6; 
	}

	// after scan the key , save the MS key state in the bufKey_Map.
	KB_CheckDebounce(0, bKeyMap);		
	
//	// (optional for EMI setting)	
//	// Column & Row Schmitt trigger disabled
//	//KB_ClrSchmitt();		
	bKB_State = S_MS_CHECK_MATRIX_MAP;	
}

/*****************************************************************************
* Function			: KB_CheckDebounce
* Description		: Key Debounce has four state: Stable_Break/ Current_Make/ Stable_Make/ Current_Break
* Input				: bCurrentColNum 		(~bKeyMap)
* Output			: b_aryKB_Debounce [2][8]:
*
*									bit[3:0] ->	Make / Break Count
*									bit[5:4] -> 00: Stable Break,
*															01: Current Make,
*															10: Stable Make,
*															11: Current Break
*									bit6		 ->	Just Stable 
* Return			: None
* Note				: None
*****************************************************************************/
void KB_CheckDebounce(uint8_t bCurrentColNum, uint8_t bKeyMap_Data)
{
	uint8_t i;
	uint8_t* b_ptrDebounce;
	
	b_ptrDebounce = &b_aryKB_Debounce[bCurrentColNum][0];
	
	//** for loop to check bit0-bit8 key status	
	for(i = 0;i < MS_KEYBUFFER_SIZE;i++)
	{	
		//** Get b_aryKB_Debounce[0] data bit[5:4] to check the debounce state
		switch((*b_ptrDebounce) & mskDebounceState)
		{
			//** Key pressed,check the bit of MS Buffer 
			//** 1= Key press , 0= Key release 
			//** if current key press -> Debounce state  change to current Make	
			//** if current key release -> Debounce state	stay in Stable Break, do nothing.
			case S_DEBOUNCE_STABLE_BREAK_STATE:
				if(bKeyMap_Data & (BIT_0 << i))				//** current key pressed			
				{
					(*b_ptrDebounce) = (S_DEBOUNCE_CURRENT_MAKE_STATE|NEW_MAKE_VALUE);	
				}		
				break;
				
			//** Key pressed,check the bit of MS Buffer 
			//** 1= Key press, 0= Key release	
			//** if current key press -> Debounce state count-- ,until Stable Make and set JustStable at first time.
			//** if current key release -> Debounce state back to Stable Break					
			case S_DEBOUNCE_CURRENT_MAKE_STATE:				
				if(bKeyMap_Data & (BIT_0 << i))				//** current key pressed			
				{
					(*b_ptrDebounce) --;	
					if(((*b_ptrDebounce) & mskLOW_NIBBLE) == COUNT_FINISH)				
					{	
						//** First time stable Make , setting Just Stable Flag 
						(*b_ptrDebounce) = (S_DEBOUNCE_STABLE_MAKE_STATE|DEBOUNCE_JUST_STABLE|0x00);	
					}			
				}				
				else //** current key release
				{
					(*b_ptrDebounce) = (S_DEBOUNCE_STABLE_BREAK_STATE|0x00);								
				}			
				break;
				
			//** Key pressed,check the bit of MS Buffer 
			//** 1= Key press , 0= Key release 
			//** if current key press -> Debounce state stay in Stable Make, do nothing.
			//** if current key release -> Debounce state change to current Break			
			case S_DEBOUNCE_STABLE_MAKE_STATE:
				if(!(bKeyMap_Data & (BIT_0 << i)))			//** current key release			
				{
					(*b_ptrDebounce) = (S_DEBOUNCE_CURRENT_BREAK_STATE|NEW_BREAK_VALUE);
				}
				break;	
				
			//** Key pressed,check the bit of MS Buffer 
			//** 1= Key press, 0= Key release	
			//** if current key press -> Debounce state back to Stable Make
			//** if current key release -> Debounce state count-- ,until Stable Break	
			case S_DEBOUNCE_CURRENT_BREAK_STATE:
				if(bKeyMap_Data & (BIT_0 << i))				//current key pressed			
				{
					(*b_ptrDebounce) = (S_DEBOUNCE_STABLE_MAKE_STATE|0x00);		
				}				
				else //current key release
				{
					(*b_ptrDebounce) --;	
					if(((*b_ptrDebounce) & mskLOW_NIBBLE) == COUNT_FINISH)
					{		
						//** First time stable Make , setting Just Stable Flag 
						(*b_ptrDebounce) = (S_DEBOUNCE_STABLE_BREAK_STATE|DEBOUNCE_JUST_STABLE|0x00);	
					}					
				}					
				break;
				
			default:
				break;
		}
		//check next key information of Debounce array
		b_ptrDebounce++;
	}
}


/*****************************************************************************
* Function			: MS_CheckMatrixState
* Description		: Convert the mapped keys into the specified usage key.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_CheckMatrixState(void)
{
	uint8_t 	i,j;
	uint8_t		bCRCode;
	uint8_t*	b_ptrDebounce;
	uint8_t*	b_ptrDebounceFirst;
	
	//** pointer to the first key status
	b_ptrDebounceFirst = &b_aryKB_Debounce[0][0];
	
	for(i = 0;i < MS_COLUMN_SIZE;i++)
	{
		b_ptrDebounce = (b_ptrDebounceFirst + (i << 3));		//** current COLUMN[0] or [1]	, and begin from Row[0]
		
		//** Check the Mouse Key0~7 status and handle the key data
		for(j = 0;j < MS_ROW_SIZE;j++)
		{
			if(!((*b_ptrDebounce) & DEBOUNCE_JUST_STABLE))		//Key not just stable status, pass and check next
			{
				b_ptrDebounce++;
				continue;
			}				
			//**Calculation Note: for Key0-7: j=0~7 (row), i=0 (column): bCRCode = j = 0-7
			//**									for Key8-15: j=0~7(row), i=1 (column): bCRCode = j+(i<<3) = 8-15
			bCRCode = j + (i<<3);			//** calculate CR Code		
			if((((*b_ptrDebounce) & mskDebounceState) == S_DEBOUNCE_STABLE_BREAK_STATE) && ((*b_ptrDebounce) & DEBOUNCE_JUST_STABLE))
			{
				//** Clear DEBOUNCE_JUST_STABLE
				(*b_ptrDebounce) &= (~DEBOUNCE_JUST_STABLE);		
				//** Stable Break event 
				KB_ConvertUsbUsage(bCRCode, KB_BREAK_EVENT);				
			}
			else if((((*b_ptrDebounce) & mskDebounceState) == S_DEBOUNCE_STABLE_MAKE_STATE) && ((*b_ptrDebounce) & DEBOUNCE_JUST_STABLE))				
			{
				//** Clear DEBOUNCE_JUST_STABLE
				(*b_ptrDebounce) &= (~DEBOUNCE_JUST_STABLE);
				//** if LEDMODE= Reaction Mode, Setting LED Reaction Flag
				if(bLED_Mode == S_LED_MODE_REACTION)
				{
					wLED_Status |= mskLED_ReactionFlag;
				}
				
				//** Stable Make Event
				KB_ConvertUsbUsage(bCRCode, KB_MAKE_EVENT);				
			}
			//**not Stable Make or Break Do nothing, Do nothing
			b_ptrDebounce++;			
		}

	}


	if(wMS_Status & mskMS_NFireKeyAction)
	{
		bKB_State = S_KB_NFIRE_STATE;
	}
	else
	{
		//KB_KeyMerge();	
		bKB_State = S_MS_SCAN_STATE;
	}

	bMN_State = S_MAIN_IDLE_STATE;
}

/*****************************************************************************
* Function			: KB_ConvertUsbUsage
* Description		: KB_ConvertUsbUsage
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void KB_ConvertUsbUsage(uint8_t bCRIndex, uint8_t bKeyEvent)
{
	//point to the Real KEY CODE
	uint8_t bKeyCode;
	
	bKeyCode = tabMS_UsageTable[bCRIndex];
	//** Mouse Data buffer 
	MS_BufferUsbKey(bKeyCode, bKeyEvent);
	
}

/*****************************************************************************
* Function			: MS_BufferUsbKey
* Description		: Determine the bKeyCode function of Mouse.
* Input				: wKeycode - The key code or index in Keyboard_USB_Consumer_Table
						bKeyEvent - Make/Break
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_BufferUsbKey(uint16_t wKeycode, uint8_t bKeyEvent)
{
//	uint8_t bCRType;
	uint8_t bKeyCode = wKeycode;

//	bCRType = wKeycode >> 8;		//2:N-Fire 1: Macro   0: Normal
	// Check if an empty code (00h)
	if(bKeyCode == ZERO) 
	{
		return;
	}
	//-------------------------------DPI KEY functions-------------------------------------------------
//	else if(bKeyCode >= MS_KEY_DPI_INDEX)
//	{
//		if(MS_M1_BTN == bKeyCode)
//		{
//			if(bKeyEvent == KB_MAKE_EVENT)				// make event
//			{
//				if(++bLED_Mode > S_LED_MODE_MAX)
//					bLED_Mode = S_LED_MODE_MIN;
//				wLED_Status |= mskLED_ModeChange;			
//			}			
//		}
//		else if(MS_M2_BTN == bKeyCode)
//		{
//			//do nothing
//			
//		}
//		else if(MS_KEY_DPI_LOOP_UP == bKeyCode)
//		{
//			if(bKeyEvent == KB_MAKE_EVENT)				// make event
//			{
//				//Change current DPI Setting
//				MS_SensorDPISetting_by_SPI();
//			}
//		}
//	}
	else if(bKeyCode >= MS_KEY_DPI_INDEX)
	{
		if(MS_M2_BTN == bKeyCode)
		{
//			if(bKeyEvent == KB_MAKE_EVENT)				// make event
//			{
//				if(bLED_Mode < S_LED_MODE_MAX)
//					bLED_Mode++;
//				else
//					bLED_Mode = S_LED_MODE_MIN;
//				wLED_Status |= mskLED_ModeChange;	
//        //[s 
//          flash_buttfer[1] = bLED_Mode;
//          FLASH_ProgramPage(0x7400,1,(uint32_t*)flash_buttfer);
//        //]        
//			}
      if (deviceMode == DRIVER_MODE) {
        if(bKeyEvent == KB_MAKE_EVENT)
        {
          b_aryKB_Mouse[0] |= 0x20;
          wKB_SendStatus |= mskKB_SendMouseFlag;
        }
        //Key Break Setting Clear Key code and setting 	Sendkey flag		
        else
        {
          b_aryKB_Mouse[0] &= ~0x20;
          wKB_SendStatus |= mskKB_SendMouseFlag;			
        }	        
      } else {
			  MS_NFirePage(MS_KEY_L, bKeyEvent);
      }
		}
		else if(MS_M1_BTN == bKeyCode)
		{
			//do nothing
			
		}
		else if(MS_KEY_DPI_LOOP_UP == bKeyCode)
		{
      if (deviceMode == DRIVER_MODE) {
        if(bKeyEvent == KB_MAKE_EVENT)
        {
          b_aryKB_Mouse[0] |= 0x40;
          wKB_SendStatus |= mskKB_SendMouseFlag;
        }
        //Key Break Setting Clear Key code and setting 	Sendkey flag		
        else
        {
          b_aryKB_Mouse[0] &= ~0x40;
          wKB_SendStatus |= mskKB_SendMouseFlag;			
        }	        
      } else {      
        if(bKeyEvent == KB_MAKE_EVENT)				// make event
        {
          //Change current DPI Setting
          MS_SensorDPISetting_by_SPI();
  //        flash_buttfer[0] = bMSDPI_Index;
  //        FLASH_ProgramPage(0x7000,1,(uint32_t*)flash_buttfer);//bMSDPI_Index 
          requestVariableUpdate(SW_CHANGED);
        }
      }
		}
	}	
	//--------------------------------Standard Mouse Key---------------------------------------------------
	else 
	{
		//Key Make Setting Sendkey flag 
		if(bKeyEvent == KB_MAKE_EVENT)
		{
			b_aryKB_Mouse[0] |= bKeyCode;
			wKB_SendStatus |= mskKB_SendMouseFlag;
		}
		//Key Break Setting Clear Key code and setting 	Sendkey flag		
		else
		{
			b_aryKB_Mouse[0] &= ~bKeyCode;
			wKB_SendStatus |= mskKB_SendMouseFlag;			
		}		
	}	
}

/*****************************************************************************
* Function			: KB_KeyMerge
* Description		: KB_KeyMerge
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void KB_KeyMerge(void)
{
	
}
	
/*****************************************************************************
* Function			: MS_NFireState
* Description		: MS_NFireState
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_NFireState(void)
{
	uint8_t dbKeycode;
	
	dbKeycode = bMS_NFireKeyCode;				//** Get combo key code
	
	if(bMS_NFireOperationCounter == ZERO) //** Check N-Fire Key Operation done
	{
		wMS_Status &= ~mskMS_NFireKeyAction;	//** End N-Fire key action	
		//** Clear N fire Key Variables
		bMS_NFireOperationCounter = ZERO;
		bMS_NFireKeyCode = ZERO;
		bMS_NFireKeyToggleBit = ZERO;
	}
	else
	{
		//dbKeycode |= 0x0200;								//** Set key code type (N-Fire type)
		if(bMS_NFireKeyToggleBit & BIT_0)				//** Break event, increase index & change status into make event
		{
			MS_BufferUsbKey(dbKeycode, KB_MAKE_EVENT);
			bMS_NFireKeyToggleBit ^= BIT_0;
		}
		else
		{
			MS_BufferUsbKey(dbKeycode, KB_BREAK_EVENT);	//** Make event & change status into break event
			bMS_NFireKeyToggleBit ^= BIT_0;
			bMS_NFireOperationCounter--;	
		}
	}
//	KB_KeyMerge();			
	bKB_State = S_MS_SCAN_STATE;
	bMN_State = S_MAIN_IDLE_STATE;		
}
