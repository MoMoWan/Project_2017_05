/******************** (C) COPYRIGHT 2017 SONiX *******************************
* COMPANY: SONiX
* DATE:		 2017/07
* AUTHOR:	 SA1
* IC:			 SN32F240B
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.00			2017/07/07	Tim		1. First release
* 1.01			2017/07/17	Tim		1. Modified the BL jump address
															2. Added the EMC protect
_____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/
/*____________________________________________________________________________
* REVISION		Date			User		Description
* 1.00			2017/08/10		SA1			1. First Release
* 1.01			2017/11/29		SA1			1. Modify IO Define 
*											2. Add 6 RGB LED PWM Define  
*_____________________________________________________________________________
*/
/*_____ I N C L U D E S ____________________________________________________*/
#include	"SN32F240B.h"
#include	"SN32F200_Def.h"

//Usb Init
#include	"usbhw.h"
#include	"usbram.h"

//Sensor Key Wheel Init
#include 	"Mouse.h"
#include	"Mouse_Const.h"
#include	"Mouse_RamSetting.h"
#include 	"Mouse_Key.h"
#include	"Mouse_Sensor.h"
#include 	"Mouse_Wheel.h"
#include	"Boot_Idle_State.h"

//LED Init
#include 	"LED.h"

//CT16B1(PWM) Init
#include	"CT16B1.h"

//SPI Init
#include 	"SPI.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/
void SysTick_Init(void);
void NDT_Init(void);
void WDT_Init(void);
void PFPA_Init(void);

/*****************************************************************************
* Function		: main
* Description	: USB Mouse demo code 
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
int	main (void)
{
	SystemInit();				// SET SYSCLK(IHRC) = 48MHz  HCLK = 48MHz
	SystemCoreClockUpdate();
	
	PFPA_Init();
	
	USB_Init();					/* USB Initialization */
	
	MS_GpioInit();				// Mouse GPIO Initialization
	
	MS_RamInit();				// Mouse Ram Initialization
	
	LED_Init();					// LED Initialization 
	
	SPI0_Init();				// SPI0 Initialization
	
	CT16B1_Init();				// CT16B1(PWM) Initialization 
	
	WDT_Init();					// WatchDogTimer Initialization
	
//	NDT_Init();					// Noise Detect Initialization 			maybe not use
		
	//--------------------------------------------------------------------------
	//User Code starts HERE!!!
	while (1)
	{	
		SN_WDT->FEED = 0x5AFA55AA;		
		switch(bMN_State)
		{
			case S_MAIN_BOOT_STATE:	
				MN_BootState();	
				break;
			
			case S_MAIN_IDLE_STATE:
				MN_IdleState();		
				break;	
			
			case S_MAIN_WHEEL_STATE:	//必要时放中断中处理	避免跳动 	
				MN_WheelState();		//if main process takes too long, Wheel Process should put in Interrupt		//add by le
				break;			
			
			case S_MAIN_SENSOR_STATE:	
				MN_SensorState();				
				break;				
			
			case S_MAIN_KEYSCAN_STATE:	
				MN_KeyScanState();			
				break;			
			
			case S_MAIN_LED_STATE: 
				MN_LEDState();					
				break; 			
			
			default:
				bMN_State = S_MAIN_BOOT_STATE;
				break;				
		}
	
}
}

/*****************************************************************************
* Function		: PFPA
* Description	: Select each IO as PWM Output
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void PFPA_Init(void)
{
	SN_PFPA->CT16B1 |= 0x7C03F;			//PWMB Set 0 1 2 3 4 5 14 15 16 17 18 
}

/*****************************************************************************
* Function		 : SysTick_Init
* Description	 : For EFT Protection
* Input	(Global) : None
* Input	(Local)	 : None
* Output (Global): None
* Return (Local) : None
*****************************************************************************/
void SysTick_Init (void)
{
	SysTick->LOAD = 0x000752FF;		//RELOAD = (system tick clock frequency ? 10 ms)/1000 -1
	SysTick->VAL = 0xFF; 			//__SYSTICK_CLEAR_COUNTER_AND_FLAG;
	SysTick->CTRL = 0x7;			//Enable SysTick timer and interrupt	
}

/*****************************************************************************
* Function		 : SysTick_Handler
* Description	 : For EFT Protection
* Input	(Global) : None
* Input	(Local)	 : None
* Output (Global): None
* Return (Local) : None
*****************************************************************************/
__irq void SysTick_Handler(void)
{
	if(bNDT_Flag)			//** Check NDT
	{
		if(SN_SYS0->NDTSTS_b.NDT5V_DET == 1)
		{
			dbNDT_Cnt = 0;
		}
		else
		{
		  dbNDT_Cnt++;
			if(dbNDT_Cnt == 90)//** 900ms
			{
				bNDT_Flag = 0;
			}
		}
	}	
}


/*****************************************************************************
* Function		 : NDT_Init
* Description	 : Noise Detect Init
* Input	(Global) : None
* Input	(Local)	 : None
* Output (Global): None
* Return (Local) : None
*****************************************************************************/
void NDT_Init(void)
{
	SN_SYS0->NDTCTRL = 0x2;					//** Enable NDT 5V
	NVIC_EnableIRQ(NDT_IRQn);
	SN_SYS0->ANTIEFT = 0x04;	
}


/*****************************************************************************
* Function		: NDT_IRQHandler
* Description	: ISR of NDT interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void NDT_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(NDT_IRQn);
	if (SN_SYS0->NDTSTS)				//** Check NDT 5V detected
	{
		bNDT_Flag = 1;
	}
	SN_SYS0->NDTSTS = 0x3;				//** Clear NDT 5V flag
}

/*****************************************************************************
* Function		  : WDT_Init
* Description	 : Watch Dog Timer init using reset
* Input(Global)	: None
* Input(Local)  : None
* Output(Global): None
* Return(Local)	: None
*****************************************************************************/
void WDT_Init(void)
{
	SN_WDT->CFG = 0x5AFA0000;  			//** use WDT Reset!
	SN_SYS1->APBCP1 = (0x0<<20);		//** 31.25 us * 128 = 4ms
	SN_WDT->TC = 0x5AFA003E;			//** (TC + 2) * 4ms = 256ms @ ILRC / 1 = 32KHz 
	SN_WDT->CFG |= 0x5AFA0001; 			//** Enable
}

/*****************************************************************************
* Function		: HardFault_Handler
* Description	: ISR of Hard fault interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void HardFault_Handler(void)
{
	NVIC_SystemReset();
}



