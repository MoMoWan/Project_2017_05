/*_____ I N C L U D E S ____________________________________________________*/
#include "LED.h"
#include "LED_Function.h"
#include "LED_RamSetting.h"
#include "LED_Const.h"
#include "LED_Table.h"

#include "Mouse_RamSetting.h"
#include "Mouse_Const.h"
#include "variables.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/


/*****************************************************************************
* Function		: MN_LEDState
* Description	: Select LED Effect
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void MN_LEDState(void)
{
	if(wLED_Status & mskLED_ModeChange)							//LED Mode Change
	{
		wLED_Status &=~ mskLED_ModeChange;
		LED_Mode_ReInit();
	}
	
	switch(bLED_Mode)
	{
		case S_LED_MODE_BREATH:
			LED_Mode_Breath();
			break;
		case S_LED_MODE_REACTION:
			LED_Mode_Reaction();
			break;
		case S_LED_MODE_SPECTRUM:
			LED_Mode_Spectrum();
			break;
		case S_LED_MODE_STATIC:
			LED_Mode_Static();
			break;
 		case S_LED_MODE_NONE:
			LED_Mode_None();
			break;   
 		case S_LED_MODE_BLINK:
			LED_Mode_Blink();
			break;     
		default:	
			break;
	}
	
	bMN_State = S_MAIN_IDLE_STATE;
	
}

/*****************************************************************************
* Function		: LED_Init
* Description	: LED_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Init(void)
{
//	LED_Mode_Breath_Init();
//	bLED_Mode = S_LED_MODE_BREATH;
	
//	LED_Mode_Spectrum_Init();
//	bLED_Mode = S_LED_MODE_SPECTRUM;							// LED Effect Init
//  flash_buttfer[1] = bLED_Mode = *((uint8_t *)MANUFACTURING_SATRT+1);
//  if (bLED_Mode == 0) {
//    bLED_Mode = 1;
//  }
//  bLED_Mode = ram.profile[0].led.effect;
  LED_Mode_ReInit();
	
//	LED_Mode_Reaction_Init();
//	bLED_Mode = S_LED_MODE_REACTION;
	
//	LED_Mode_Static_Init();
//	bLED_Mode = S_LED_MODE_STATIC;
}

/*****************************************************************************
* Function		: LED_Mode_ReInit
* Description	: LED_Mode_ReInit
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_ReInit(void)
{
	uint8_t i;
	//PWM BUF Set To ZERO
	for(i=0;i<6;i++)
	{
		rPWM_Buf[i] = 0x0;
		rPWM_Buf[i] = 0x0;
		rPWM_Buf[i] = 0x0;
	}
	dbMS_LED_ReflashTimeFrame = 0;
	
	switch(bLED_Mode)
	{
		case S_LED_MODE_BREATH:
			LED_Mode_Breath_Init();
			break;
		case S_LED_MODE_REACTION:
			LED_Mode_Reaction_Init();
			break;
		case S_LED_MODE_SPECTRUM:
			LED_Mode_Spectrum_Init();
			break;
		case S_LED_MODE_STATIC:
    case S_LED_MODE_NONE:  
			LED_Mode_Static_Init();
			break;
    case S_LED_MODE_BLINK:
      LED_Mode_Blink_Init();
      break;
		default:	
      bLED_Mode = S_LED_MODE_SPECTRUM;
      LED_Mode_Spectrum_Init();
			break;
	}
}

/*****************************************************************************
* Function		: LED_Mode_Breath_Init
* Description	: LED_Mode_Breath_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Breath_Init(void)
{
	bLED_DataRefreshTime_Reload = ram.profile[0].led.speed;//BREATH_REFRESH_TIME;
	rTab_Index = 0;
	LED_SettingDefaultColor();
	rPWM_Value = gPWM_Value = bPWM_Value = 0;
}

/*****************************************************************************
* Function		: LED_Mode_Breath
* Description	: LED_Mode_Breath
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Breath(void)
{
	LED_ReflashPWMDuty();
	LED_Effect_Breath();
}

/*****************************************************************************
* Function		: LED_Effect_Breath
* Description	: LED_Effect_Breath
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Effect_Breath(void)
{
	uint8_t i;
	
	if( rTab_Index < BREATH_TABLE_LENGTH )
	{
		rPWM_Value = (structLED_BreathEffect.bRed * LED_BREATH_TABLE[rTab_Index])>>8;	
		gPWM_Value = (structLED_BreathEffect.bGreen * LED_BREATH_TABLE[rTab_Index])>>8;	
		bPWM_Value = (structLED_BreathEffect.bBlue * LED_BREATH_TABLE[rTab_Index++])>>8;		
	}
	else
	{
		rTab_Index = 0;
//		LED_EffectRandomValueGen();
//		structLED_BreathEffect.bRed = *(RandomColor + (wLED_RandomValue &0xF));			//LED_R	
//		structLED_BreathEffect.bGreen = *(RandomColor + (wLED_RandomValue &0xF))>>8;	//LED_G
//		structLED_BreathEffect.bBlue = *(RandomColor + (wLED_RandomValue &0xF))>>16;	//LED_B
//	}
    structLED_BreathEffect.bRed = ram.profile[0].led.color.R;
    structLED_BreathEffect.bGreen = ram.profile[0].led.color.G;
    structLED_BreathEffect.bBlue = ram.profile[0].led.color.B;
  }
  
	for(i=0;i<6;i++)
	{
		rPWM_Buf[i] = rPWM_Value;
		gPWM_Buf[i] = gPWM_Value;
		bPWM_Buf[i] = bPWM_Value;
	}
}

/*****************************************************************************
* Function		: LED_Mode_Spectrum_Init
* Description	: LED_Mode_Spectrum_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Spectrum_Init(void)
{
	rPWM_Value = PWM_MAX;
	gPWM_Value = 0;
	bPWM_Value = 0;
	bLED_DataRefreshTime_Reload = ram.profile[0].led.speed;//SPECTRUM_REFRESH_TIME;
	bLED_StepPWM = LED_SPECTRUM_PWM_STEP_VALUE;
	rTab_Index = 0;
}

/*****************************************************************************
* Function		: LED_Mode_Spectrum
* Description	: LED_Mode_Spectrum
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Spectrum(void)
{
	uint8_t i;
	
	LED_ReflashPWMDuty();

	switch(rTab_Index)
	{
		case 0:			//-R+G Yellow-> Red
			LED_EffectSpectrumProcess(&rPWM_Value, &gPWM_Value, &rTab_Index,PWM_MAX);				
			break;
			//----------------------------------------------------------------
		
		case 1:			//-G+B		
			LED_EffectSpectrumProcess(&gPWM_Value, &bPWM_Value, &rTab_Index,PWM_MAX);
		break;
			//-----------------------------------------------------------

		case 2:			//-B+R				
			LED_EffectSpectrumProcess(&bPWM_Value, &rPWM_Value, &rTab_Index,PWM_MAX);			
		break;
		
		default:
			return;
	}
	
	for(i=0;i<6;i++)
	{
		rPWM_Buf[i] = rPWM_Value;
		gPWM_Buf[i] = gPWM_Value;
		bPWM_Buf[i] = bPWM_Value;
	}
}

/*****************************************************************************
* Function		: LED_EffectSpectrumProcess
* Description	: LED_EffectSpectrumProcess
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_EffectSpectrumProcess(uint8_t* nNumber_Down, uint8_t* nNumber_UP,uint8_t* nRGB_Step,uint8_t nHalforMax)
{

	if((*nNumber_Down) != ZERO)
	{
		(*nNumber_Down) -= bLED_StepPWM;
	}
	
	if((*nNumber_UP) != nHalforMax)
	{
		(*nNumber_UP) += bLED_StepPWM;
	}
	else
	{
		(*nRGB_Step)++;
		if((*nRGB_Step) == 3)
		{
			(*nRGB_Step) = 0;
		}	
	}	
	
}

/*****************************************************************************
* Function		: LED_Mode_Reaction_Init
* Description	: LED_Mode_Reaction_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Reaction_Init(void)
{
//	if(bLED_Mode == S_LED_MODE_REACTION)
//		return;
	
	bLED_DataRefreshTime_Reload = ram.profile[0].led.speed;//REACTION_REFRESH_TIME;
	if(bLED_ReativeJustMake == 0)
	{
		rTab_Index = 0;
		rPWM_Value = gPWM_Value = bPWM_Value = 0;
	}
}

/*****************************************************************************
* Function		: LED_Mode_Reaction
* Description	: LED_Mode_Reaction
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Reaction(void)
{
	uint8_t i;
	
	uint16_t db_tabLED_BREACTIVE[80]=								//** Breath gamma table
	{
		  0,   0,   0,   3,   7,   11,   15,   19,   23,   27,   31,   35,  39,
		 43,  47,  50,  55,  58,  62,  70,  78,  86,  94,  101,	
		 109,  117,  125,  133,  141,  149,  156,  164,  172,  188,  196,
		 207,  219,  231,  243,  254,  266,  278,  290,  301,  313,  329,
		 345,  360,  376, 392, 407, 423, 439, 454, 470, 486, 494,
		513, 533, 552, 592, 611, 631, 650, 670, 690, 709, 730,
		750, 760, 780, 803, 827, 854, 882, 909, 937, 964, 988, 1024	
	};	
	
	LED_ReflashPWMDuty();
	if(wLED_Status & mskLED_ReactionFlag)
	{	
		wLED_Status &= ~mskLED_ReactionFlag;	
		//** If bLED_ReativeJustMake == 0, reactive effect color change avalible.
		if(bLED_ReativeJustMake == 0)
		{
//			//Random color gen
//			LED_EffectRandomValueGen();
//			structLED_BreathEffect.bRed = *(RandomColor + (wLED_RandomValue &0xF));			//LED_R	
//			structLED_BreathEffect.bGreen = *(RandomColor + (wLED_RandomValue &0xF))>>8;	//LED_G
//			structLED_BreathEffect.bBlue = *(RandomColor + (wLED_RandomValue &0xF))>>16;	//LED_B	
     structLED_BreathEffect.bRed =  ram.profile[0].led.color.R;
     structLED_BreathEffect.bGreen = ram.profile[0].led.color.G;
     structLED_BreathEffect.bBlue = ram.profile[0].led.color.B;          
		}
		
		bLED_ReativeJustMake = 1;		
		rTab_Index = 79; //** Max index in the db_tabLED_BREATH table.
	}
	else
	{
		if(rTab_Index > 0)
		{
			//**  Calculate color multiply gamma table2
			rPWM_Value   = (structLED_BreathEffect.bRed * (*(db_tabLED_BREACTIVE + rTab_Index)))>> 10; //** Div 1024, LED_R1 
			gPWM_Value = (structLED_BreathEffect.bGreen * (*(db_tabLED_BREACTIVE + rTab_Index)))>> 10; //** Div 1024, LED_G1
			bPWM_Value  = (structLED_BreathEffect.bBlue * (*(db_tabLED_BREACTIVE + rTab_Index)))>> 10; //** Div 1024, LED_B1	
			rTab_Index--;	
			
			//** To avoid system run the reactive of "Black Color"  
			if((rPWM_Value ==0) && (gPWM_Value == 0) && (bPWM_Value == 0))	
			{
				//**if R/G/B PWM=0 , leaving current path  
				rTab_Index = 0;
			}
			
			//** when LED dimming step match to Gamma table brightness [step40]
			//** clear bLED_ReativeJustMake flag and next key make will exchange LED color.
			if((rTab_Index<40) && (bLED_ReativeJustMake == 1))
			{	
				bLED_ReativeJustMake = 0;			
			}
		}				
	}	

	for(i=0;i<6;i++)
{
		rPWM_Buf[i] = rPWM_Value;
		gPWM_Buf[i] = gPWM_Value;
		bPWM_Buf[i] = bPWM_Value;
}
}

/*****************************************************************************
* Function		: LED_Mode_Wave_Init
* Description	: LED_Mode_Wave_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Wave_Init(void)
{
	
	bLED_DataRefreshTime_Reload = WAVE_REFRESH_TIME;
	
//		rPWM_Buf[i] = gamma32[bLED_Rbuf[i]];
//		gPWM_Buf[i] = gamma32[bLED_Gbuf[i]];
//		bPWM_Buf[i] = gamma32[bLED_Bbuf[i]];		
	
}

/*****************************************************************************
* Function		: LED_Mode_Wave
* Description	: LED_Mode_Wave
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Wave(void)
{	

}

/*****************************************************************************
* Function		: LED_Mode_Static_Init
* Description	: LED_Mode_Static_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Static_Init(void)
{
	bLED_DataRefreshTime_Reload = STATIC_REFRESH_TIME;
}
/*****************************************************************************
* Function		: LED_Mode_Blink_Init
* Description	: LED_Mode_Blink_Init
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Blink_Init(void)
{
	bLED_DataRefreshTime_Reload = BLINK_REFRESH_TIME;
}
/*****************************************************************************
* Function		: LED_Mode_Static
* Description	: LED_Mode_Static
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Static(void)
{
	LED_ReflashPWMDuty();
	LED_PWMBuf_Update(ram.profile[0].led.color.R,ram.profile[0].led.color.G,ram.profile[0].led.color.B);			// White
}
/*****************************************************************************
* Function		: LED_Mode_Static
* Description	: LED_Mode_Static
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_None(void)
{
	LED_ReflashPWMDuty();
	LED_PWMBuf_Update(0x0,0x0,0x0);			// White
}
/*****************************************************************************
* Function		: LED_Mode_Static
* Description	: LED_Mode_Static
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_Mode_Blink(void)
{
  if ((blinkCount & 0x01) == 0) {
    switch (pollingChange) {
      case 1:
        LED_PWMBuf_Update(0xFF,0,0);			// red 
        break;
      case 2:
        LED_PWMBuf_Update(0,0xFF,0);			// green
        break;
      case 3:
        LED_PWMBuf_Update(0,0,0xFF);			// blue
        break;
      case 4:
        LED_PWMBuf_Update(0xFF,0xFF,0xFF);			// White
        break; 
      default:
        break;          
    }
  } else {
    LED_PWMBuf_Update(0,0,0);			// off
  }
	LED_ReflashPWMDuty();
  if (++blinkCount >= 24) {
    pollingChange = 0;
    blinkCount =0;
    bLED_Mode = ram.profile[0].led.effect;
    wLED_Status |= mskLED_ModeChange;    
  } 
}
/*****************************************************************************
* Function		: LED_PWMBuf_Update
* Description	: LED_PWMBuf_Update
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_PWMBuf_Update(uint8_t rpwm_buf,uint8_t gpwm_buf,uint8_t bpwm_buf)
{
	uint8_t i;
	for(i=0;i<6;i++)
	{
		rPWM_Buf[i] = rpwm_buf;
		gPWM_Buf[i] = gpwm_buf;
		bPWM_Buf[i] = bpwm_buf;
	}
 
}

/*****************************************************************************
* Function		: LED_SettingDefaultColor
* Description	: LED_SettingDefaultColor
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_SettingDefaultColor(void)
{
	structLED_BreathEffect.bRed = ram.profile[0].led.color.R;		//Breath temp LED_R
	structLED_BreathEffect.bGreen = ram.profile[0].led.color.G;	//Breath temp LED_G
	structLED_BreathEffect.bBlue = ram.profile[0].led.color.B;	//Breath temp LED_B
}

/*****************************************************************************
* Function		: LED_ReflashPWMDuty
* Description	: LED_ReflashPWMDuty
* Input			: None
* Output		: None		
* Return		: None
* Note			: None
*****************************************************************************/
void LED_ReflashPWMDuty(void)
{
	uint8_t i;
	for(i=0;i<6;i++)
	{
		bReload_MR[i*3] = rPWM_Buf[i] * LED_LIGHT_PARAM[bLED_Light_Param] / LIGHT_PARAM;	
		bReload_MR[i*3+1] = gPWM_Buf[i] * LED_LIGHT_PARAM[bLED_Light_Param] / LIGHT_PARAM;	
		bReload_MR[i*3+2] = bPWM_Buf[i] * LED_LIGHT_PARAM[bLED_Light_Param] / LIGHT_PARAM;	
	}
}

