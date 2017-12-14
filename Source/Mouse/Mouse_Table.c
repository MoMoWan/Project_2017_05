/*_____ I N C L U D E S ____________________________________________________*/
#include "Mouse_Table.h"
#include "Mouse_KeyCode.h"
#include "Mouse_Const.h"


//;=============================================================================
//; Keyboard_USB_Consumer_Table --
//; This table is a word table whichs contains the 2-byte consumer key codes.
//;=============================================================================
const uint16_t tabKB_USBConsumer[CONSUMER_TABLELENGTH] =
{
		CSMKEY_NTRACK,		// (0c b5) scan next track
		CSMKEY_PTRACK,		// (0c b6) scan previous track
		CSMKEY_STOP,		// (0c b7) stop
		CSMKEY_PLAYPAUSE, 	// (0c cd) play/pause
		CSMKEY_VOLUME,		// (0c e0) Volume
		CSMKEY_MUTE  , 		// (0c e2) mute
		CSMKEY_BASS	,		// (0c e3) bass
		CSMKEY_TREBLE,		// (0c e4) treble
		CSMKEY_BASSBOOST,	// (0c e5) bass boost
		CSMKEY_VOLINC , 	// (0c e9) volume increment
		CSMKEY_VOLDEC  ,	// (0c ea) volume decrement
		CSMKEY_BASSINC 	,	// (0c 152) bass increment
		CSMKEY_BASSDEC  ,	// (0c 153) bass decrement
		CSMKEY_TREBLEINC,	// (0c 154) treble increment
		CSMKEY_MEDIA,		// (0c 155) treble decrement
		CSMKEY_ALEMAIL,		// (0c 18a) al email reader
		CSMKEY_ACSEARCH,	// (0c 221) ac search
		CSMKEY_ACHOME,		// (0c 223) ac home (??)
		CSMKEY_ACBACK,   	// (0c 224) ac back
		CSMKEY_ACFORWARD,	// (0c 225) ac forward
		CSMKEY_ACSTOP,		// (0c 226) ac stop
		CSMKEY_ACREFRESH,	// (0c 227) ac refresh
		CSMKEY_ACBOOKMARK,	// (0c 22a) ac bookmarks (????)
		CSMKEY_ALCALCULATOR,// (0c 192) al calculator (???)
		CSMKEY_ALBROWSER,	// (0c 194) al browser (????)
		CSMKEY_ALCONSUMER,	// (0c 183) al consumer control configuration (?????)	
		CSMKEY_ACOPEN,		// (0c 202) ac open
		CSMKEY_ACCLOSE,		// (0c 203) ac close
		CSMKEY_ACSAVE,		// (0c 207) ac save
		CSMKEY_ACUSER,		// (0c 218) ac user
		CSMKEY_ACUNDO,		// (0c 21a) ac undo
		CSMKEY_EJECT,		// (0c b8) Eject
};


//;=============================================================================
//; Mouse Usage table
//; Max Size = 8*2
//;=============================================================================
const uint16_t tabMS_UsageTable[MS_ROW_SIZE * MS_COLUMN_SIZE] =
{
	//----------------------------------------------
	//; Key0-Key7
	//;----------------------------------------------
		MS_KEY_L,
		MS_KEY_R,
		MS_KEY_M,
		MS_KEY_5,
		MS_KEY_4,
		MS_M2_BTN,
		MS_KEY_DPI_LOOP_UP,
		KEY_RESERVED,
	
	//----------------------------------------------
	//; Key8-Key15
	//;----------------------------------------------
//		KEY_RESERVED,
//		KEY_RESERVED,
//		KEY_RESERVED,
//		KEY_RESERVED,
//		KEY_RESERVED,
//		KEY_RESERVED,
//		KEY_RESERVED,
//		KEY_RESERVED,	
	
};

#ifdef PMW3325
const uint8_t tabSensor_DPI[5]=
{
	SENSOR_RESOLUTION_400_3325,
	SENSOR_RESOLUTION_800_3325,
	SENSOR_RESOLUTION_1600_3325,
	SENSOR_RESOLUTION_3200_3325,
  SENSOR_RESOLUTION_4800_3325,
};
#else		//PMW3360
const uint8_t tabSensor_DPI[4]=
{
	SENSOR_CPI_500_3360,
	SENSOR_CPI_3000_3360,
	SENSOR_CPI_7500_3360,
	SENSOR_CPI_12000_3360,
};
#endif 












