
#ifndef __MOUSE_CONST_H__
#define __MOUSE_CONST_H__
#include <SN32F240B.h>

//Define to Select Sensor
//#define PMW3325
//#define PMW3360

//=============================//
//  Main State Machine states  //
//=============================//
#define		S_MAIN_BOOT_STATE  			0x00
#define		S_MAIN_IDLE_STATE  			0x01
#define		S_MAIN_SENSOR_STATE 		0x02
#define		S_MAIN_KEYSCAN_STATE 	  	0x03
#define		S_MAIN_LED_STATE  			0x04
#define		S_MAIN_WHEEL_STATE			0x05

#define		S_MAIN_MAX_STATE_NUMBER 	0x05

//#define		S_MAIN_APP_STATE  			0x06
//#define		S_MAIN_MACRO_STATE  		0x07

//=============================//
//   Key Scan State Machine    //
//=============================//
#define		S_MS_SCAN_STATE 				0x00
#define		S_MS_CHECK_MATRIX_MAP  			0x01
#define		S_KB_NFIRE_STATE				0x02

//#define		S_KB_MAX_STATE_NUMBER  		0x04
//#define		S_KB_MACRO_KEY_STATE  		0x02
//#define		S_KB_MARGE_STATE 			0x03

 	/* KB wKB_SendStatus Register */
 	#define mskKB_SendKBFlag				(0x1<<0)
	#define mskKB_SendSystemFlag			(0x1<<1)
	#define mskKB_SendConsumerFlag			(0x1<<2)
	#define mskKB_SendVendorKeyFlag			(0x1<<3)
	#define mskKB_PressErrorFlag			(0x1<<4)
	
	#define mskKB_SendMouseFlag				(0x1<<22)

//=============================//
//      Wheel case       			 //
//=============================//
#define		S_WHEEL_BA_LL  		0x00
#define		S_WHEEL_BA_LH  		0x01
#define		S_WHEEL_BA_HL 		0x02
#define		S_WHEEL_BA_HH 		0x03


#define		WHEEL_BA_LL  					0x00
#define		WHEEL_BA_LH  					0x01
#define		WHEEL_BA_HL 					0x02
#define		WHEEL_BA_HH 					0x03
#define		WHEEL_BA_STABLE_LL 		(0x01<<2)
#define		WHEEL_BA_STABLE_HH 		(0x02<<2)

#define		mskWheel_CurrentStatus		(0x03 << 0)
#define		mskWheel_StableStatus		(0x0C << 0)
#define		mskWheel_Clockwise 			(0x01<<7)
#define		mskWheel_CounterClockwise 	(0x01<<6)

#define		mskWheel_JustStable 		(0x01<<5)

#define		WHEEL_DEBOUNCE_COUNT				8 //** 2ms
#define		WHEEL_NEW_DEBOUNCE_VALUE		(WHEEL_DEBOUNCE_COUNT)	

#define		mskWHEEL_A_BIT0		(0x01 << 0)
#define		mskWHEEL_B_BIT1		(0x01 << 1)

#define 	MS_WHEEL_CW        	0x01
#define 	MS_WHEEL_CCW        0xFF


//Sensor 3325 & 3360
	#define	WRITE_BIT		(0x01 << 7)
	#define	READ_BIT		(0x00 << 7)	

 	#define SENSOR_PRODUCT_ID				0x00
			#define	PMW3325_PRODUCT_ID				0x43
			#define	PMW3360_PRODUCT_ID				0x42
      #define	PMW3389_PRODUCT_ID				0x47
	#define SENSOR_MOTION_STATUS			0x02
			#define mskSENSOR_MotionStaus			(0x01<<7)	
			
 	#define SENSOR_DELTA_X_L				0x03
	#define SENSOR_DELTA_X_H				0x04
 	#define SENSOR_DELTA_Y_L				0x05
	#define SENSOR_DELTA_Y_H				0x06	
	
	#define SENSOR_SQUAL					0x07
		
	#define SENSOR_PIX_SUM					0x08	
	#define SENSOR_PIX_MAX					0x09	
 	#define SENSOR_PIX_MIN					0x0A
	
 	#define SENSOR_SHUT_LOW					0x0B	
	#define SENSOR_SHUT_HIGH				0x0C	
	
	#define	SENSOR_BURST_3325				0x16
		
	#define	SENSOR_RESOLUTION_3325			0x1B
			#define	SENSOR_RESOLUTION_400_3325			0x09
			#define SENSOR_RESOLUTION_800_3325			0x13
			#define	SENSOR_RESOLUTION_1600_3325			0x27
			#define	SENSOR_RESOLUTION_3200_3325			0x4F
			#define	SENSOR_RESOLUTION_4800_3325			0x77
		
	#define SENSOR_RESET					0x3A
			#define SETTING_POWER_UP_RESET			0x5A
			
	#define SENSOR_INV_PID					0x3F
			#define INVERSE_PRODUCT_ID_3325			0xBC
			#define INVERSE_PRODUCT_ID_3360			0xBD
			
	#define	SENSOR_SHUTDOWN					0x3B
			#define	SENSOR_POWER_DOWN				0xB6
			
	#define	SENSOR_CONFIG_3325				0x40
			#define	REST_MODE_ENABLE				0x00
			#define	REST_MODE_DISENABLE				0x80

//PMW 3360
	#define	SENSOR_CONTROL_3360				0x0D
			#define DEGREE_0_3360					0x00
	#define SENSOR_CONFIG1_3360				0x0F
	#define SENSOR_CONFIG2_3360				0x10
			#define REST_ENABLE						0x20
			#define	REST_DISENABLE					0x00
			
	#define SENSOR_CONFIG5_3360				0x2F
	
			#define SENSOR_CPI_500_3360					0x04
			#define SENSOR_CPI_1000_3360				0x09
			#define	SENSOR_CPI_3000_3360				0x1D
			#define SENSOR_CPI_5000_3360				0x31
			#define	SENSOR_CPI_7500_3360				0x4A
			#define SENSOR_CPI_10000_3360				0x63
			#define	SENSOR_CPI_12000_3360				0x77
			
	#define SENSOR_BURST_3360				0x50	
	
//=============================//
//      Report Rate case       //
//=============================//
#define		S_REPORT_RATE_1000Hz  		0x00
#define		S_REPORT_RATE_500Hz  		0x01
#define		S_REPORT_RATE_250Hz 		0x02
#define		S_REPORT_RATE_125Hz  		0x03


//=============================//
//   Debounce State Machine    //
//=============================//
#define		S_DEBOUNCE_STABLE_BREAK_STATE  	(0x00<<4)
#define		S_DEBOUNCE_CURRENT_MAKE_STATE  	(0x01<<4)
#define		S_DEBOUNCE_STABLE_MAKE_STATE  	(0x02<<4)
#define		S_DEBOUNCE_CURRENT_BREAK_STATE  (0x03<<4)


#define		mskDebounceState  			(0x03<<4)
#define		mskDebounce_JustStable  (0x01<<6)


#define		DEBOUNCE_JUST_STABLE 	0x40
#define		KB_MAKE_EVENT  			0x00
#define		KB_REPEAT_EVENT  		0x01
#define		KB_BREAK_EVENT  		0x02

/*============================================================================
; KB_CheckDebounce
;============================================================================*/

#define		NEW_MAKE_VALUE		(KB_MAKE_DEBOUNCE_COUNT)	
#define		NEW_BREAK_VALUE		(KB_BREAK_DEBOUNCE_COUNT)

#define		KB_MAKE_DEBOUNCE_COUNT		5	//20ms
#define		KB_BREAK_DEBOUNCE_COUNT		8	//20ms

#define 	ZERO 	0x00
#define 	mskLOW_NIBBLE  0x0F
#define 	HIGH_NIBBLE    0xF0
#define 	COUNT_FINISH   0x00

#define		MS_COLUMN_SIZE 1		//the pins of Column numbers
#define		MS_ROW_SIZE    8			//the pins of Row numbers
#define		MS_KEYBUFFER_SIZE 8			//the pins of MS numbers
#define		KB_MAX_KEY_CNT	  6				//
	
#define 	MAKE_EVENT		0x80
#define 	BREAK_EVENT		0x00

#define 	BOOT_MODE	0x00

/*============================================================================
; KB_Table
;============================================================================*/
#define 	CUSTOM_TABLELENGTH		22
#define 	CONSUMER_TABLELENGTH	32

//----------------------------------------------------------------------------
#define	BIT_0		(0x01 << 0)
#define	BIT_1		(0x01 << 1)
#define	BIT_2		(0x01 << 2)
#define	BIT_3		(0x01 << 3)
#define	BIT_4		(0x01 << 4)
#define	BIT_5		(0x01 << 5)
#define	BIT_6		(0x01 << 6)
#define	BIT_7		(0x01 << 7)

#define	BIT_8		(0x01 << 8)
#define	BIT_9		(0x01 << 9)
#define	BIT_10		(0x01 << 10)
#define	BIT_11		(0x01 << 11)
#define	BIT_12		(0x01 << 12)
#define	BIT_13		(0x01 << 13)
#define	BIT_14		(0x01 << 14)
#define	BIT_15		(0x01 << 15)


#define	__SPI0_SDIO_OUTPUTMODE 		SN_GPIO0->MODE |= (0x01<<2);
#define __SPI0_SDIO_INPUTMODE		SN_GPIO0->MODE &=~ (0x01<<2);				//P0.2
#define __SPI0_SDIO_PULLUP			SN_GPIO0->CFG_b.CFG2 = 0x0;

#define	__SPI0_CLR_SDIO 			SN_GPIO0->BCLR |= (0x01<<2);				//P0.2
#define __SPI0_SET_SDIO				SN_GPIO0->BSET |= (0x01<<2);				//P0.2

#define	__SPI0_SDIO_DATA			SN_GPIO0->DATA_b.DATA2

#define	__SPI0_MOSI_OUTPUTMODE 		SN_GPIO0->MODE |= (0x01<<3);
#define	__SPI0_CLR_MOSI 			SN_GPIO0->BCLR |= (0x01<<3);				//P0.3
#define __SPI0_SET_MOSI				SN_GPIO0->BSET |= (0x01<<3);				//P0.3

#define	__SPI0_SCK_OUTPUTMODE 		SN_GPIO0->MODE |= (0x01<<4);
#define __SPI0_SET_SCK  			SN_GPIO0->BSET |= (0x01<<4);				//P0.4
#define __SPI0_CLR_SCK				SN_GPIO0->BCLR |= (0x01<<4);				//P0.4

#define	__SPI0_OUTPUTMODE_SEL 		SN_GPIO0->MODE |= (0x01<<5);				//set P05 is ouput mode
#define	__SPI0_SET_SEL			 	SN_GPIO0->BSET |= (0x01<<5);
#define	__SPI0_CLR_SEL			 	SN_GPIO0->BCLR |= (0x01<<5);



#endif //__MOUSE_CONST_H__

