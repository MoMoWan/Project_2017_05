/******************** (C) COPYRIGHT 2014 SONiX *******************************
* COMPANY:			SONiX
* DATE:				2014/12
* AUTHOR:			SA1
* IC:						
* DESCRIPTION:	 Main functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0			  2014/12/12	SA1			1. First release
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/
/*_____ I N C L U D E S ____________________________________________________*/
#include	"SN32F240B.h"
#include 	"Mouse.h"
#include	"Mouse_RamSetting.h"
#include	"Mouse_Const.h"
#include 	"Mouse_Wheel.h"
#include 	"Mouse_Sensor.h"
#include	"LED_RamSetting.h"
#include 	"LED_Const.h"
#include	"CT16B0.h"
#include	"variables.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/
/*_____ M A C R O S ________________________________________________________*/
/*_____ F U N C T I O N S __________________________________________________*/
	

/*****************************************************************************
* Function			: MS_Init
* Description		: MS_Init
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_Init(void)
{
	MS_WheelInit();				// Scroll Wheel Initialization 
	MS_SensorInit();			// Sensor Initialization
	MS_TimerInit();				// Timer Initialization
	
	SN_WDT->CFG |= 0x5AFA0001; 			//Enable
}	

/*****************************************************************************
* Function			: MS_GpioInit
* Description		: MS_GpioInit
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_GpioInit(void)
{
	SN_GPIO0->MODE = 0x0;				//Set P0
	SN_GPIO0->CFG = 0x0;					//Set P0 as pullup
	
	SN_GPIO1->MODE = 0;					//Set P1 mode as input
	SN_GPIO1->CFG = 0;					//Set P1 as pullup	
		
	SN_GPIO2->MODE = 0;					//Set P2 mode as input
	SN_GPIO2->CFG = 0;					//Set P2 as pullup

//	SN_GPIO3->MODE = 0;					//Set P3 mode as input
//	SN_GPIO3->CFG = 0;					//Set P3 as pullup
	
//	__SPI0_OUTPUTMODE_SEL0;
	SN_GPIO0->MODE |= 0x20;	//set P05 is ouput mode
}
 // uint8_t buttons;
/*****************************************************************************
* Function			: MS_RamInit
* Description		: MS_RamInit
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_RamInit(void)
{ 
	uint8_t i,j;

	// Init State Machine
	bMN_State = S_MAIN_BOOT_STATE;	
	bKB_State = S_MS_SCAN_STATE;
	
	wLED_RandomValue_N_1 = 1;
	wLED_RandomValue_N_2 = 1;
	
	wKB_SendStatus = ZERO;
	wMS_Status = ZERO;
	
	//Debounce buffer
	for(i = 0;i < MS_COLUMN_SIZE;i++)
	{
		for(j = 0;j < MS_ROW_SIZE;j++)
		{
			b_aryKB_Debounce[i][j] = ZERO;
			
		}
	}

	b_aryKB_Consumer[0] = ZERO;
	b_aryKB_Consumer[1] = ZERO;
	
	bKB_System = ZERO;
	
	for(i = 0;i < 7;i++)
	{
		b_aryKB_Mouse[i] = ZERO;
	}

	//** Staggerd macro key 1ms flag and ms report rate 1ms flag   
	bMS_TimeFrame_CNT = 0;
	
	//** LED Default Value = 0
	wLED_Status &= ~mskLED_ReactionFlag;	
	bLED_ReativeJustMake = 0;	
//[ s load the user settings 
   memoryCopy(&ram,(void *)USER_SETTING_START,sizeof(ram));
   if ((ram.storageSize != sizeof(ram)) || (ram.crc != crc16((U8 *)&ram, (sizeof(ram)-2)))) {
     memoryCopy(&ram, (void *)&dft_generic1, sizeof(ram));            // copy dft_generic to ram
   }
   
   dpiCurrent.x = ram.profile[0].dpiCur.x;
   dpiCurrent.y = ram.profile[0].dpiCur.y;
//]  
  
 //[ S check the button upon power on 
  // 1 D Q B F R M L button mapping 
  buttons = button_input;
     switch (button_input) {
       case 0xE6:             // B+F+L
         pollingChange = 1;
         ram.profile[0].Sensor.pollingRate = 8;
         break;
       case 0xE5:             // B+F+R 
         pollingChange = 2;
         ram.profile[0].Sensor.pollingRate = 2;
         break;
       case 0xE3:             // B+F+M
         pollingChange = 3;
         ram.profile[0].Sensor.pollingRate = 4;
         break;
       case 0xA7:             // B+F+D
         pollingChange = 4;
         ram.profile[0].Sensor.pollingRate = 1;
         break;       
       default:
         break;                            
     }
  while (button_input != 0xFF){
  
  }  
     if (pollingChange) {
       requestVariableUpdate(SW_CHANGED);
       bLED_Mode = S_LED_MODE_BLINK;
       wLED_Status |= mskLED_ModeChange;
     } else {
       bLED_Mode = ram.profile[0].led.effect;
       wLED_Status |= mskLED_ModeChange;
     }    
  //]  
}

/*****************************************************************************
* Function			: MS_TimerInit
* Description		: MS_TimerInit
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_TimerInit(void)
{
	CT16B0_Init();
}





