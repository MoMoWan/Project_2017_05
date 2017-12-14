
#ifndef __MOUSE_KEYCODE_H__
#define __MOUSE_KEYCODE_H__
#include <SN32F240B.h>

//=============================================================================
//; Standard USB usage codes.
//;=============================================================================
#define KEY_RESERVED	 		0x00
#define KEY_ERRORROLLOVER		0x01
#define KEY_POSTFAIL			0x02
#define KEY_ERRORUNDEFINED		0x03
#define KEY_A			0x04
#define KEY_B   		0x05
#define KEY_C   		0x06
#define KEY_D   		0x07
#define KEY_E   		0x08	
#define KEY_F   		0x09
#define KEY_G   		0x0a
#define KEY_H  			0x0b
#define KEY_I  			0x0c
#define KEY_J  			0x0d
#define KEY_K   		0x0e
#define KEY_L   		0x0f
#define KEY_M   		0x10
#define KEY_N   		0x11
#define KEY_O 			0x12
#define KEY_P   		0x13	
#define KEY_Q   		0x14
#define KEY_R   		0x15
#define KEY_S   		0x16
#define KEY_T   		0x17
#define KEY_U  			0x18
#define KEY_V   		0x19
#define KEY_W   		0x1a
#define KEY_X  			0x1b
#define KEY_Y   		0x1c
#define KEY_Z   		0x1d
#define KEY_1  			0x1e
#define KEY_2  			0x1f
#define KEY_3  			0x20
#define KEY_4  			0x21
#define KEY_5  			0x22
#define KEY_6   		0x23
#define KEY_7  			0x24
#define KEY_8   		0x25
#define KEY_9  			0x26
#define KEY_0  			0x27	
#define KEY_ENTER  		0x28	
#define KEY_ESCAPE 		0x29
#define KEY_BACKSPACE	0x2a	
#define KEY_TAB     	0x2b
#define KEY_SPACEBAR	0x2c
#define KEY_MIS         0x2d	//; - and _
#define KEY_EQU         0x2e	//; = and +
#define KEY_OQO         0x2f	//; [ and {
#define KEY_EQO        	0x30	//; ] and }
#define KEY_BSL        	0x31	//; \ and |
#define KEY_NUP         0x32	//; Non-US # and ~
#define KEY_COL         0x33	//; ; and :
#define KEY_CC         	0x34	//; ' and "
#define KEY_GAT        	0x35	//; ` and ~
#define KEY_CMA       	0x36	//; , and <
#define KEY_DOT        	0x37	//; . and >
#define KEY_SL         	0x38	//; / and ?
#define KEY_CAPLOCK     0x39
#define KEY_F1          0x3a
#define KEY_F2          0x3b
#define KEY_F3          0x3c	
#define KEY_F4          0x3d
#define KEY_F5          0x3e	
#define KEY_F6          0x3f	
#define KEY_F7         	0x40	
#define KEY_F8          0x41	
#define KEY_F9          0x42	
#define KEY_F10         0x43
#define KEY_F11         0x44
#define KEY_F12        	0x45	
#define KEY_PRINTSCREEN 0x46	
#define KEY_SCROLLLOCK  0x47	
#define KEY_PAUSE       0x48
#define KEY_INSERT      0x49	
#define KEY_HOME       	0x4a
#define KEY_PAGEUP      0x4b
#define KEY_DELETE      0x4c
#define KEY_END        	0x4d	
#define KEY_PAGEDOWN   	0x4e
#define KEY_RIGHT      	0x4f
#define KEY_LEFT       	0x50
#define KEY_DOWN        0x51
#define KEY_UP         	0x52	
#define KEY_PADNUMLOCK  0x53
#define KEY_PADNSL      0x54	// keypad /
#define KEY_PADNMU     	0x55	// keypad *
#define KEY_PADNMI     	0x56	//; keypad -
#define KEY_PADNPL     	0x57	//; keypad +
#define KEY_PADENTER    0x58
#define KEY_PAD1       	0x59
#define KEY_PAD2       	0x5a
#define KEY_PAD3        0x5b	
#define KEY_PAD4       	0x5c
#define KEY_PAD5        0x5d	
#define KEY_PAD6        0x5e	
#define KEY_PAD7        0x5f
#define KEY_PAD8       	0x60
#define KEY_PAD9        0x61
#define KEY_PAD0        0x62	
#define KEY_PADDEL      0x63
#define KEY_NBS        	0x64	//; non-US \ AND |
#define KEY_APPLICATION 0x65	
#define KEY_POWER      	0x66
#define KEY_PADEQU     	0x67	//; keypad =  
#define KEY_F13         0x68
#define KEY_F14        	0x69
#define KEY_F15        	0x6a
#define KEY_F16        	0x6b
#define KEY_F17         0x6c	
#define KEY_F18         0x6d
#define KEY_F19         0x6e	
#define KEY_F20         0x6f	
#define KEY_F21         0x70	
#define KEY_F22         0x71	
#define KEY_F23        	0x72	
#define KEY_F24        	0x73
#define KEY_EXECUT      0x74	
#define KEY_HELP        0x75	
#define KEY_MEMU        0x76	
#define KEY_SELECT      0x77
#define KEY_STOP        0x78	
#define KEY_AGAIN       0x79	
#define KEY_UNDO       	0x7a
#define KEY_CU         	0x7b	
#define KEY_COPY       	0x7c	
#define KEY_PASTE       0x7d	
#define KEY_FIND        0x7e	
#define KEY_MUTE        0x7f
#define KEY_VOLUMEUP    0x80
#define KEY_VOLUMEDOWN 	0x81
#define KEY_LOCKINGCAPSLOCK		0x82	
#define KEY_LOCKINGNUMLOCK  	0x83
#define KEY_LOCKINGSCROLLLOCK	0x84	
#define KEY_COMM               	0x85	//; keypad ,
#define KEY_EQUALSIGN          	0x86	//;
#define KEY_INTERNATIONAL1     	0x87	//; Japanese (Refer P61 note 15 in HUT table)
#define KEY_INTERNATIONAL2     	0x88	//; Japanese (Refer P61 note 16 in HUT table)
#define KEY_INTERNATIONAL3     	0x89	//; Japanese (Refer P61 note 17 in HUT table)
#define KEY_INTERNATIONAL4     	0x8a	//; Japanese XFER (Refer P61 note 18 in HUT table)
#define KEY_INTERNATIONAL5     	0x8b	//; Japanese NFER (Refer P61 note 19 in HUT table)
#define KEY_INTERNATIONAL6     	0x8c	//; Japanese (Refer P61 note 20 in HUT table)
#define KEY_INTERNATIONAL7     	0x8d	
#define KEY_INTERNATIONAL8     	0x8e	
#define KEY_INTERNATIONAL9     	0x8f	
#define KEY_LANG1       0x90
#define KEY_LANG2       0x91	
#define KEY_LANG3       0x92	
#define KEY_LANG4      	0x93	
#define KEY_LANG5       0x94	
#define KEY_LANG6      	0x95	
#define KEY_LANG7      	0x96
#define KEY_LANG8      	0x97
#define KEY_LANG9       0x98	
#define KEY_ALTERNATEERASE  	0x99	
#define KEY_SYSREQ     	0x9a	
#define KEY_CANCEL     	0x9b
#define KEY_CLEAR      	0x9c
#define KEY_PRIOR      	0x9d	
#define KEY_RETURN     	0x9e	
#define KEY_SEPARATOR   0x9f	

//=============================================================================
// Mouse usage key code.
//=============================================================================
#define MS_KEY_L          	0x01
#define MS_KEY_M           	0x04
#define MS_KEY_R           	0x02 
#define MS_KEY_4           	0x08 //back to last page
#define MS_KEY_5           	0x10 //go to next page

#define MS_WHEEL_CW        	0x01
#define MS_WHEEL_CCW        0xFF


#define MS_KEY_DPI_INDEX  		0x50
#define	MS_M1_BTN				0x51						
#define	MS_M2_BTN				0x52

#define MS_KEY_DPI_UP  			0x53
#define MS_KEY_DPI_DOWN  		0x54
#define MS_KEY_DPI_LOOP_UP  	0x55
#define MS_KEY_DPI_LOOP_DOWN  	0x56
#define MS_APP_DPI_SETTING 	 	0xEA  //** Setting special case for APP update game profile



//;=============================================================================
//; Standard USB usage codes for different languages 
//;=============================================================================
#define KEY_K29			0x31	//;K29
#define KEY_K42			0x32	//;K42
#define KEY_K45			0x64	//;K45
#define KEY_K56			0x87	//;K56
#define KEY_K133		0x88	//;K133
#define KEY_K14			0x89	//;K14
#define KEY_K132		0x8A	//;K132
#define KEY_K131		0x8B	//;K131
#define KEY_K150		0x91	//;K150
#define KEY_K151		0x90	//;K151
#define KEY_K107		0x85	//;K107
#define KEY_LAST_STANDARD_KEY	0xa4

//;=============================================================================
//; System control's temp code. 
//;=============================================================================
#define SYSKEY_POWER	    0xa8    //; system control POWER
#define SYSKEY_SLEEP      	0xa9    //; system control SLEEP
#define SYSKEY_WAKEUP 	    0xaa    //; system control WAKEUP

//;=============================================================================
//; Special function's temp code.
//;=============================================================================
#define KEY_LED_MODE0			0xa0	//Demo Wave 
#define KEY_LED_MODE1			0xa1	//Demo Spectrum 
#define KEY_LED_MODE2			0xa2	//Demo Static Red 
#define KEY_LED_MODE3			0xa3	//Demo Static Green
#define KEY_LED_MODE4			0xa4	//Demo Static Blue
#define KEY_LED_MODE5			0xa5	//Demo Static White 
#define KEY_LED_SPEEDUP			0xa6	//;
#define KEY_LED_SPEEDDN			0xa7	//;
#define KEY_LED_BRIGHTNESSUP	0xa8	//;
#define KEY_LED_BRIGHTNESSDN	0xa9	//;

#define KEY_LOCK			0xae	//; Win Key Lock 
#define KEY_FN				0xaf	//; Fn key

//;=============================================================================
//; Consumer hot key's Index and its usge code
//;=============================================================================
#define CSMKEY_BASE				0xb0

#define CSMKEY_NTRACK_INDEX   	0xb0    //; (0c b5) scan next track
#define CSMKEY_NTRACK			0xb5
//;-----------------------------------------------------------------------------
#define CSMKEY_PTRACK_INDEX     0xb1    //; (0c b6) scan previous track
#define CSMKEY_PTRACK			0xb6
//;-----------------------------------------------------------------------------
#define CSMKEY_STOP_INDEX   	0xb2    //; (0c b7) stop
#define CSMKEY_STOP				0xb7
//;-----------------------------------------------------------------------------
#define CSMKEY_PLAYPAUSE_INDEX	0xb3   // ; (0c cd) play/pause
#define CSMKEY_PLAYPAUSE		0xcd
//;----------------------------------------------------------------------------
#define CSMKEY_VOLUME_INDEX		0xb4	//; (0c e0) Volume
#define CSMKEY_VOLUME			0xe0
//;-----------------------------------------------------------------------------
#define CSMKEY_MUTE_INDEX 	    0xb5    //; (0c e2) mute
#define CSMKEY_MUTE				0xe2
//;-----------------------------------------------------------------------------
#define CSMKEY_BASS_INDEX       0xb6    //; (0c e3) bass
#define CSMKEY_BASS				0xe3
//;-----------------------------------------------------------------------------
#define CSMKEY_TREBLE_INDEX     0xb7    //; (0c e4) treble
#define CSMKEY_TREBLE			0xe4
//;-----------------------------------------------------------------------------
#define CSMKEY_BASSBOOST_INDEX  0xb8    //; (0c e5) bass boost
#define CSMKEY_BASSBOOST		0xe5
//;-----------------------------------------------------------------------------
#define CSMKEY_VOLINC_INDEX  	0xb9    //; (0c e9) volume increment
#define CSMKEY_VOLINC			0xe9
//;-----------------------------------------------------------------------------
#define CSMKEY_VOLDEC_INDEX 	0xba    //; (0c ea) volume decrement
#define CSMKEY_VOLDEC			0xea
//;-----------------------------------------------------------------------------
#define CSMKEY_BASSINC_INDEX    0xbb    //; (0c 152) bass increment
#define CSMKEY_BASSINC			0x152
//;-----------------------------------------------------------------------------
#define CSMKEY_BASSDEC_INDEX    0xbc    //; (0c 153) bass decrement
#define CSMKEY_BASSDEC			0x153
//-----------------------------------------------------------------------------
#define CSMKEY_TREBLEINC_INDEX  0xbd    //; (0c 154) treble increment
#define CSMKEY_TREBLEINC		0x154
//-----------------------------------------------------------------------------
//#define CSMKEY_TREBLEDEC_INDEX  0xbe    //; (0c 155) treble decrement
//#define CSMKEY_TREBLEDEC		0x155
#define CSMKEY_MEDIA_INDEX  	0xbe    //; (0c 155) treble decrement
#define CSMKEY_MEDIA			0x183
//-----------------------------------------------------------------------------
#define CSMKEY_ALEMAIL_INDEX  	0xbf    //; (0c 18a) al email reader
#define CSMKEY_ALEMAIL			0x18a
//-----------------------------------------------------------------------------
#define CSMKEY_ACSEARCH_INDEX   0xc0    //; (0c 221) ac search
#define CSMKEY_ACSEARCH			0x221
//;-----------------------------------------------------------------------------
#define CSMKEY_ACHOME_INDEX     0xc1    //; (0c 223) ac home (??)
#define CSMKEY_ACHOME			0x223
//;-----------------------------------------------------------------------------
#define CSMKEY_ACBACK_INDEX   	0xc2   // ; (0c 224) ac back
#define CSMKEY_ACBACK			0x224
//;-----------------------------------------------------------------------------
#define CSMKEY_ACFORWARD_INDEX	0xc3    //; (0c 225) ac forward
#define CSMKEY_ACFORWARD		0x225
//;-----------------------------------------------------------------------------
#define CSMKEY_ACSTOP_INDEX 	0xc4    //; (0c 226) ac stop
#define CSMKEY_ACSTOP			0x226
//;-----------------------------------------------------------------------------
#define CSMKEY_ACREFRESH_INDEX	0xc5    //; (0c 227) ac refresh
#define CSMKEY_ACREFRESH		0x227
//;-----------------------------------------------------------------------------
#define CSMKEY_ACBOOKMARK_INDEX 0xc6    //; (0c 22a) ac bookmarks (我的最愛)
#define CSMKEY_ACBOOKMARK		0x22a
//;-----------------------------------------------------------------------------
#define CSMKEY_ALCALCULATOR_INDEX	0xc7    //; (0c 192) al calculator (???)
#define CSMKEY_ALCALCULATOR		0x192
//;-----------------------------------------------------------------------------
#define CSMKEY_ALBROWSER_INDEX	    0xc8    //; (0c 194) al browser (????)
#define CSMKEY_ALBROWSER		0x194
//-----------------------------------------------------------------------------
#define CSMKEY_ALCONSUMER_INDEX 0xc9    //; (0c 183) al consumer control configuration (?????)
#define CSMKEY_ALCONSUMER		0x183
//-----------------------------------------------------------------------------
#define CSMKEY_ACOPEN_INDEX		0xca	//; (0c 202) ac open
#define CSMKEY_ACOPEN			0x202
//-----------------------------------------------------------------------------
#define CSMKEY_ACCLOSE_INDEX	0xcb	//; (0c 203) ac close
#define CSMKEY_ACCLOSE			0x203
//-----------------------------------------------------------------------------
#define CSMKEY_ACSAVE_INDEX		0xcc	//; (0c 207) ac save
#define CSMKEY_ACSAVE			0x207
//-----------------------------------------------------------------------------
#define CSMKEY_ACUSER_INDEX		0xcd	//; (0c 218) ac user
#define CSMKEY_ACUSER			0x218
//-----------------------------------------------------------------------------
#define CSMKEY_ACUNDO_INDEX		0xce	//; (0c 21a) ac undo
#define CSMKEY_ACUNDO			0x21a
//-----------------------------------------------------------------------------
#define CSMKEY_EJECT_INDEX		0xcf	//; (0c b8) Eject
#define CSMKEY_EJECT			0xb8
//-----------------------------------------------------------------------------

//=============================================================================
// User Macro key's usage key code.
//=============================================================================
#define KEY_M1           	0xD1
#define KEY_M2           	0xD2
#define KEY_M3           	0xD3 
#define KEY_M4           	0xD4
#define KEY_M5           	0xD5

//;=============================================================================
//; Modifier key's usage key code.
//;=============================================================================
#define KEY_LEFTCTRL			0xe0	
#define KEY_LEFTSHIFT			0xe1	
#define KEY_LEFTALT				0xe2	
#define KEY_LEFTGUI				0xe3	
#define KEY_RIGHTCTRL			0xe4	
#define KEY_RIGHTSHIFT		0xe5	
#define KEY_RIGHTALT			0xe6	
#define KEY_RIGHTGUI			0xe7	

//;=============================================================================
//; Vendor hotkey's temp code
//;=============================================================================
#define VENDOR_HOTKEY_1_INDEX	0xe8	
#define VENDOR_HOTKEY_1			(0x08 << 8 | KEY_F)	//; added by user
//-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_2_INDEX	0xe9	
#define VENDOR_HOTKEY_2			0x00f2	//; added by user
//-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_3_INDEX	0xea	
#define VENDOR_HOTKEY_3			0x00f3	//; added by user
//-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_4_INDEX	0xeb	
#define VENDOR_HOTKEY_4			0x00f4	//; added by user
//-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_5_INDEX	0xec	
#define VENDOR_HOTKEY_5			0x0000	//; added by user
//-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_6_INDEX	0xed	
#define VENDOR_HOTKEY_6			0x00f6	//; added by user
//-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_7_INDEX	0xee	
#define VENDOR_HOTKEY_7			0x00f7	//; added by user
//;-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_8_INDEX	0xef	
#define VENDOR_HOTKEY_8			0x00f8	//; added by user
//;-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_9_INDEX	0xf0	
#define VENDOR_HOTKEY_9			0x00f9	//; added by user
//;-----------------------------------------------------------------------------
#define VENDOR_HOTKEY_10_INDEX	0xf1	
#define VENDOR_HOTKEY_10		0x00fa	//; added by user

	
//;=============================================================================
//; Modifier key's bit mapping key code.
//;=============================================================================
#define MASK_CTRL_L_BIT			BIT_0
#define MASK_SHIFT_L_BIT		BIT_1
#define MASK_ALT_L_BIT			BIT_2
#define MASK_GUI_L_BIT			BIT_3
#define MASK_CTRL_R_BIT			BIT_4
#define MASK_SHIFT_R_BIT		BIT_5
#define MASK_ALT_R_BIT			BIT_6
#define MASK_GUI_R_BIT			BIT_7

//;=============================================================================
//; Macro hotkey's temp code
//;=============================================================================
//; Win8 hot key code
//;WIN8_APP_SEARCH	; Win(L) + Q
//;WIN8_APP_SEARCH	; Win(L) + Shift(L) + F21
//;WIN8_SHARE		; Win(L) + H
//;WIN8_SHARE		; Win(L) + Alt(L) + F21
//;WIN8_DEVICES		; Win(L) + K
//;WIN8_DEVICES		; Win(L) + Ctrl(L) + F21
//;WIN8_SETTINGS		; Win(L) + I
//;WIN8_SETTINGS		; Win(L) + F21
//;WIN8_DESKTOP		; Win(L) + D
//;WIN8_BROWSER		; Win(L) + E
//;WIN8_FILE_SEARCH	; Win(L) + F
//;WIN8_CMD		; Win(L) + R
//;WIN8_LOCK		; Win(L) + L
//;WIN8_CHARMS		; Win(L) + C

//; Other hot key code
//;MACROKEY_CUT		; Ctrl(L) + X
//;MACROKEY_COPY		; Ctrl(L) + C
//;MACROKEY_PASTE		; Ctrl(L) + V

//; For example Win-L + Ctrl-L + KEY_F21,
//; The MACRO_MODIFY_KEY_n format is: (GUI_L_BIT | CTRL_L_BIT)
#define MACRO_MODIFY_KEY_0		(MASK_CTRL_L_BIT | MASK_SHIFT_L_BIT)	//; Ctrl(L)+Shift(L)+ Esc
#define MACRO_MODIFY_KEY_1		MASK_GUI_L_BIT	//; Win(L)+X
#define MACRO_MODIFY_KEY_2		MASK_GUI_L_BIT	//; Open the desktop, Win(L)+D
#define MACRO_MODIFY_KEY_3		MASK_ALT_L_BIT	//; Alt(L)+ Esc
#define MACRO_MODIFY_KEY_4		MASK_ALT_L_BIT	//; Alt(L)+ Tab
#define MACRO_MODIFY_KEY_5		MASK_ALT_L_BIT	//; Alt(L)+ F4
#define MACRO_MODIFY_KEY_6		MASK_CTRL_L_BIT	//; CUT Ctrl(L) + X
#define MACRO_MODIFY_KEY_7		MASK_CTRL_L_BIT	//; COPY Ctrl(L) + C
#define MACRO_MODIFY_KEY_8		MASK_CTRL_L_BIT	//; PASTE Ctrl(L) + V
#define MACRO_MODIFY_KEY_9		(MASK_CTRL_L_BIT | MASK_SHIFT_L_BIT)//; SEARCH Win(L) + Shift(L) + F21


//; For example Win-L + Ctrl-L + KEY_F21,
//; The MACRO_NORMAL_KEY_n format is: KEY_F21
#define MACRO_NORMAL_KEY_0		KEY_ESCAPE		//; Ctrl(L)+Shift(L)+ Esc
#define MACRO_NORMAL_KEY_1		KEY_X			//; Win(L)+X
#define MACRO_NORMAL_KEY_2		KEY_D			//; Open the desktop, Win(L)+D
#define MACRO_NORMAL_KEY_3		KEY_ESCAPE		//; Alt(L)+ Esc
#define MACRO_NORMAL_KEY_4		KEY_TAB			//; Alt(L)+ Tab
#define MACRO_NORMAL_KEY_5		KEY_F4			//; Alt(L)+ F4
#define MACRO_NORMAL_KEY_6		KEY_X			//; CUT Ctrl(L) + X
#define MACRO_NORMAL_KEY_7		KEY_C			//; COPY Ctrl(L) + C
#define MACRO_NORMAL_KEY_8		KEY_V			//; PASTE Ctrl(L) + V
#define MACRO_NORMAL_KEY_9		KEY_F21			//; SEARCH Win(L) + Shift(L) + F21

//;=============================================================================
//; Macro hotkey's combination temp code
//; The format is: (MACRO_MODIFY_KEY<<8 | MACRO_NORMAL_KEY)
//;=============================================================================


#define MACRO_HOTKEY_0_INDEX		0xf0
#define MACRO_HOTKEY_0			(MACRO_MODIFY_KEY_0<<8 | MACRO_NORMAL_KEY_0)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_1_INDEX		0xf1
#define MACRO_HOTKEY_1			(MACRO_MODIFY_KEY_1<<8 | MACRO_NORMAL_KEY_1)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_2_INDEX		0xf2
#define MACRO_HOTKEY_2			(MACRO_MODIFY_KEY_2<<8 | MACRO_NORMAL_KEY_2)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_3_INDEX		0xf3
#define MACRO_HOTKEY_3			(MACRO_MODIFY_KEY_3<<8 | MACRO_NORMAL_KEY_3)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_4_INDEX		0xf4
#define MACRO_HOTKEY_4			(MACRO_MODIFY_KEY_4<<8 | MACRO_NORMAL_KEY_4)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_5_INDEX		0xf5
#define MACRO_HOTKEY_5			(MACRO_MODIFY_KEY_5<<8 | MACRO_NORMAL_KEY_5)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_6_INDEX		0xf6
#define MACRO_HOTKEY_6			(MACRO_MODIFY_KEY_6<<8 | MACRO_NORMAL_KEY_6)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_7_INDEX		0xf7
#define MACRO_HOTKEY_7			(MACRO_MODIFY_KEY_7<<8 | MACRO_NORMAL_KEY_7)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_8_INDEX		0xf8
#define MACRO_HOTKEY_8			(MACRO_MODIFY_KEY_8<<8 | MACRO_NORMAL_KEY_8)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_9_INDEX		0xf9
#define MACRO_HOTKEY_9			(MACRO_MODIFY_KEY_9<<8 | MACRO_NORMAL_KEY_9)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_10_INDEX		0xfa
//;MACRO_HOTKEY_10		EQU	(MACRO_MODIFY_KEY_10<<8 | MACRO_NORMAL_KEY_10)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_11_INDEX	EQU	0xfb
//;MACRO_HOTKEY_11		EQU	(MACRO_MODIFY_KEY_11<<8 | MACRO_NORMAL_KEY_11)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_12_INDEX	EQU	0xfc
//;MACRO_HOTKEY_12		EQU	(MACRO_MODIFY_KEY_12<<8 | MACRO_NORMAL_KEY_12)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_13_INDEX	EQU	0xfd
//;MACRO_HOTKEY_13		EQU	(MACRO_MODIFY_KEY_13<<8 | MACRO_NORMAL_KEY_13)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_14_INDEX	EQU	0xfe
//;MACRO_HOTKEY_14		EQU	(MACRO_MODIFY_KEY_14<<8 | MACRO_NORMAL_KEY_14)
//;-----------------------------------------------------------------------------
#define MACRO_HOTKEY_15_INDEX	EQU	0xff
//;MACRO_HOTKEY_15		EQU	(MACRO_MODIFY_KEY_15<<8 | MACRO_NORMAL_KEY_15)



#endif //__MOUSE_KEYCODE_H__



