/*_____ I N C L U D E S ____________________________________________________*/
#include 	"Mouse_Function.h"

#include 	"Mouse_Const.h"
#include 	"Mouse_Table.h"
#include 	"Mouse_IOSetting.h"
#include 	"Mouse_Sensor.h"
#include 	"LED_Function.h"
#include 	"SPI.h"
#include 	"CT16B1.h"
#include 	"CT16B0.h"
#include 	"Utility.h"
#include 	"variables.h"
#include 	"LED.h"
/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/


/*****************************************************************************
* Function			: MS_SensorDPISetting_by_SPI
* Description		: MS_SensorDPISetting_by_SPI
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_SensorDPISetting_by_SPI(void)
{ 
//	if(++bMSDPI_Index>4)
//		bMSDPI_Index = 0;
	if(++ram.profile[0].Sensor.dpiStage > (ram.profile[0].Sensor.maxStages -1))
    ram.profile[0].Sensor.dpiStage = 0;
#ifdef PMW3325
//	SPI_W_2BYTE(SENSOR_RESOLUTION_3325, tabSensor_DPI[bMSDPI_Index]);
  SPI_W_2BYTE(SENSOR_RESOLUTION_3325, (ram.profile[0].Sensor.stageDPI[ram.profile[0].Sensor.dpiStage].x/40));
#else
//	SPI_W_2BYTE(SENSOR_CONFIG1_3360, tabSensor_DPI[bMSDPI_Index]);
//  SPI_W_2BYTE(SENSOR_CONFIG1_3360, (ram.profile[0].Sensor.stageDPI[ram.profile[0].Sensor.dpiStage].x/40));
  ram.profile[ram.ProNO].dpiCur.x = ram.profile[0].Sensor.stageDPI[ram.profile[0].Sensor.dpiStage].x;
  ram.profile[ram.ProNO].dpiCur.y = ram.profile[0].Sensor.stageDPI[ram.profile[0].Sensor.dpiStage].y;
  setResolution(ram.profile[ram.ProNO].dpiCur.x,ram.profile[ram.ProNO].dpiCur.y);
  decode_DPI_Stage();
#endif	
}

/*****************************************************************************
* Function		: N-Fire Page
* Description	: 
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_NFirePage(uint8_t bKeyCode, uint8_t bKeyEvent)
{
	if(bKeyEvent == KB_MAKE_EVENT)
	{
		if(!(wMS_Status & mskMS_NFireKeyAction))		//** Check any NFire key action
		{
			wMS_Status |= mskMS_NFireKeyAction;		//** Enable N-Fire key action
			//** Action Counter of N Fire Key: BYTE[1]
			bMS_NFireOperationCounter =  3;	//3Á¬»÷
			//** MS Key Code of N-Fire Key: BYTE[2]
			bMS_NFireKeyCode=  bKeyCode;		//** Set combo key index
			//** Setting Toggle Bit0 = 1 for switching N Fire Key Make/Break event. 
			bMS_NFireKeyToggleBit = BIT_0;
		}
	}		
}
/*****************************************************************************
* Function		: MS_SuspendSetting
* Description	: Setting Timer Disable, WDT Disable.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_SuspendSetting(void)
{
	MS_SetKeyIOInputMode();
	MS_SetKeyIOPullUp();
	//LED Enable IO Output High
	LED_AllEnIO_SetOutputHigh();
	UT_MAIN_DelayNx10us(2);	
	//** Setting Wheel status as HH or LL, to avoid current leakage.
	MS_SetWheelIOSuspend();
	
	SPI_W_2BYTE(SENSOR_SHUTDOWN, SENSOR_POWER_DOWN);
	UT_MAIN_DelayNms(50);
	
	__SPI0_SET_SEL0	

	//Disable RGB LED 		PWM IO forced to 0
	//SN_CT16B1->PWMCTRL = 0x2A;
	
	//Disable timer & pwm
	CT16B1_Disable();
	CT16B0_Disable();
	//Disable WDT
	SN_WDT->CFG = 0x5AFA0000;
}

/*****************************************************************************
* Function		: KB_SetRowPullUp
* Description	: Set Row pull up
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_SetKeyIOPullUp(void)
{
	__MS_KEY_IO_0_SETPUR
	__MS_KEY_IO_1_SETPUR
	__MS_KEY_IO_2_SETPUR
	__MS_KEY_IO_3_SETPUR
	__MS_KEY_IO_4_SETPUR
	__MS_KEY_IO_5_SETPUR
	__MS_KEY_IO_6_SETPUR

}

/*****************************************************************************
* Function		: MS_SetKeyIOInputMode
* Description	: Set MS button GPIO as Input Mode
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_SetKeyIOInputMode(void)
{
	__MS_KEY_IO_0_INPUTM
	__MS_KEY_IO_1_INPUTM
	__MS_KEY_IO_2_INPUTM
	__MS_KEY_IO_3_INPUTM
	__MS_KEY_IO_4_INPUTM
	__MS_KEY_IO_5_INPUTM
	__MS_KEY_IO_6_INPUTM
	
}

/*****************************************************************************
* Function		: MS_SetWheelIOInputMode
* Description	: Set MS Wheel GPIO as Input Mode
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_SetWheelIOInputMode(void)
{
	__MS_WHEEL_IO_A_INPUTM
	__MS_WHEEL_IO_B_INPUTM
}

/*****************************************************************************
* Function		: MS_SetWheelIOPullUp
* Description	: Set Wheel IO as Pull up
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_SetWheelIOPullUp(void)
{
	__MS_WHEEL_IO_A_SETPUR
	__MS_WHEEL_IO_B_SETPUR
}

/*****************************************************************************
* Function		: MS_SetWheelIOSuspend
* Description	: Set Wheel IO as Pull up
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void MS_SetWheelIOSuspend(void)
{
	//** Read MS IO status
	bWHEEL_WheelStatus &= ~mskWheel_CurrentStatus;		
	if (MS_WHEEL_PM_0->DATA & mskMS_WHEEL_IO_PM_A)
	{
		//** Setting Wheel as input pullup to avoid current leakage.
		__MS_WHEEL_IO_A_INPUTM
		__MS_WHEEL_IO_A_SETPUR
	}
	else
	{
		//** Setting Wheel as output L to avoid current leakage.
		__MS_WHEEL_IO_A_OUTPUTM
		__MS_WHEEL_IO_A_OUTPUTL		
	}
	
	
	if (MS_WHEEL_PM_0->DATA & mskMS_WHEEL_IO_PM_B)
	{
		//** Setting Wheel as input pullup to avoid current leakage.
		__MS_WHEEL_IO_B_INPUTM
		__MS_WHEEL_IO_B_SETPUR	
	}
	else
	{
		//** Setting Wheel as input floating to avoid current leakage. (wheel short IO to GND)	
		__MS_WHEEL_IO_B_OUTPUTM
		__MS_WHEEL_IO_B_OUTPUTL			
	}
}

