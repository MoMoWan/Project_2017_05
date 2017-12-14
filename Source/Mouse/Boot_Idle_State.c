/*_____ I N C L U D E S ____________________________________________________*/
#include  "Boot_Idle_State.h"
#include 	"Mouse.h"
#include  "Mouse_Const.h"
#include 	"Mouse_Function.h"
#include 	"usbepfunc.h"
#include 	"usbram.h"
#include 	"usbhw.h"
#include 	"LED.h"
#include	"LED_RamSetting.h"
#include 	"LED_Function.h"
#include 	"CT16B1.h"
#include 	"variables.h"
#include "avago_api.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/


/*****************************************************************************
* Function			: MN_BootState
* Description		: MN_BootState
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MN_BootState(void)
{
	//Given a init Random value , by the set configuration time
	LED_EffectRandomValueGen();
	
	//** Check BusSuspend
	if (sUSB_EumeData.wUSB_Status & mskBUSSUSPEND)	
	{
		MS_SuspendSetting();					//进入挂起前的设置
		
		USB_Suspend();
		
		//**(bSetconfiguration=1) --> Leave BOOT STATE
		if(sUSB_EumeData.wUSB_SetConfiguration & BIT_0)
		{
			LED_AllEnIO_SetOutputLow();
			//** Timer Initial	
			CT16B1_Init();
			MS_Init();	
			bMN_State = S_MAIN_IDLE_STATE;
		}
	}
	//**(bSetconfiguration=1) --> Leave BOOT STATE
	else if(sUSB_EumeData.wUSB_SetConfiguration & BIT_0)
	{
		LED_AllEnIO_SetOutputLow();
		CT16B1_Init();	
		MS_Init();	
		bMN_State = S_MAIN_IDLE_STATE;
	}
}

/*****************************************************************************
* Function			: MN_IdleState
* Description		: MN_IdleState
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MN_IdleState(void)
{
	//**if system in Suspend or not ready set configuration
	if((sUSB_EumeData.wUSB_Status & mskBUSSUSPEND) || (!(sUSB_EumeData.wUSB_SetConfiguration & BIT_0)))
	{
		bMN_State = S_MAIN_BOOT_STATE;
		return;
	}
	
	//** Design Note: checking the looping Max. time
	//** between (sensor state + keyscan state)
	//** To make sure the follows state change flow could work smoothly
	if(wMS_Status & mskMS_Timer250usFlag)		
	{
		__Clear_Timer250usFlag
		bMN_State = S_MAIN_WHEEL_STATE;		
	}
	else if(wMS_Status & mskMS_Timer1msFlag)
	{
		__Clear_Timer1msFlag
    if (updateOneshot) {
      updateOneshot--;
    }
    if (++pollingTimer >= ram.profile[0].Sensor.pollingRate) {
		  bMN_State = S_MAIN_SENSOR_STATE;
      pollingTimer = 0;
    }
    if (sensorIntegrity!=0)
		  sensorIntegrity--;
	}
	else if(wMS_Status & mskMS_Timer4msFlag)
	{
		__Clear_Timer4msFlag	
		bMN_State = S_MAIN_KEYSCAN_STATE;
	}		
	else if(wMS_Status & mskMS_LEDReflashTimeFlag)
	{
		__Clear_LEDReflashTimeFlag
		bMN_State = S_MAIN_LED_STATE;		
	}		
//	else if(wLED_Status & mskLED_ModeChange)
//	{
//		bMN_State = S_MAIN_LED_STATE;	
//	}

	//**Send MS/KB Data to Host 
	USB_EP1Function();
	USB_EP2Function(); 
  processPendingCommand();	
  processVariableUpdate();
	
}



