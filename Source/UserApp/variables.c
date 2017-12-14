/*++

Copyright (c) 2013-2014 Razer Ltd.
All rights reserved. This program contains proprietary and confidential information.

Module Name:
  variables.c

Compiler:
  Keil Software µVision v5.11, with NXP Semiconductor LPC11U2x proccessor support.

Abstract:
  This file provides the definitions for all of the global variables.

--*/
#include <SN32F240B.h>
#include "variables.h"
#include "Type.h"

//PROFILE_PARM OBMemory[profileNO];


U8  deviceMode;                                           // 0=Normal, 1=Bootloader, 2=Test, 3=Driver Mode
U8  deviceState;                                          // 0=Boot, 1=HW_init, 2=Var_init, 3=USB_init
U8  wakeupEvents;
U16 milliseconds;
//U8  calStatus;                                            // To indicate the calibration status
//U8  calEnable;                                            // To recorder calibration function Enable or Disable

U8  ntfType;                                              // To store the notification type
U8  ntfValue;                                             // To store the notification event value 

U8  updateStorage = 0;                                    // Variable Storage needs updating flags
U16 updateOneshot = 0;                                    // Variable Storage updating oneshot timer                              


U8  usbReceiveFlag;
U8  protocolTransmit[PROTOCOL_DATA_SIZE] = {0};           // 8 bytes command + 80 bytes payload + 1 byte checksum + 1 Reserved

U8 pollingTimer = 0;
S16 sensor_X = 0;
S16 sensor_Y = 0;

U8 pollingChange = 0;
U8 blinkCount = 0;
//const U32 fw_signature __attribute__((at(SIGNATURE_ADDR))) = STD_SIGNATURE;

//volatile U8 sw_bootloader __attribute__((at(0x10000FF8))); // Soft enter bootloader flag

#if BASIC_FW
const U8 firmwareVersion[4]  = {0,00,0,0};                // Basic Firmware v0.00.00.00
#else
const U8 firmwareVersion[4]  = {0,1,0,0};                 // Firmware version 
#endif

STORAGE1 sys;                                             // Variables filled from dft_special table
STORAGE2 ram __attribute__((aligned(4)));                                             // Variables filled from dft_generic & dft_profile tables
//STORAGE3 ramPr;
                                       

const STORAGE1 dft_special = {
                              {
                               sizeof(STORAGE1),          // Size of variable storage
                               {0, 0},                    // Mouse edtion informations
                               {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
//                               {
//                                 {0xFF, 0xFF, 0xFF, 0xFF}, // Logo led calibration
//															   {0xFF, 0xFF, 0xFF, 0xFF}, // Scroll led calibration
//																 {0xFF, 0xFF, 0xFF, 0xFF}, // Left side calibration
//																 {0xFF, 0xFF, 0xFF, 0xFF}, // Right side calibration
//														   },
														  },
                              0,                          // crc
                             };

const STORAGE2 dft_generic1 = {
                               sizeof(STORAGE2),          // Size of variable storage
                               8,         // Mouse buttons make debounce time, default 8ms
                               20,        // Mouse buttons make mask time, default 20ms
                               8,         // Mouse buttons break debounce time, default 8ms
                               20,        // Mouse buttons break mask time, default 20ms
														   0,         // Normal status
															 1,
                               {
                                 {          // profile 0 
                                   0,       // profile ID
                                   { 
                                     3,     // effect 
                                     {      // color 
                                      0xFF, //R
                                      0xFF, //G 
                                      0xFF, //B
                                     },
                                     0,     // speed 
                                     0xFF,  // bright
                                   },
                                   {1600,1600}, // DPI
                                   { 
                                     1,           //polling rate
                                     5,         // max stage
                                     3,         // DPI stage
                                     {
                                      {400,400},
                                      {800,800},
                                      {1600,1600},
                                      {3200,3200},
                                      {4800,4800},
                                     },
                                   },
                                 },
                                 {          // profile 1
                                   1,       // profile ID
                                   { 
                                     3,     // effect 
                                     {      // color 
                                      0xFF, //R
                                      0xFF, //G 
                                      0xFF, //B
                                     },
                                     0,     // speed 
                                     0xFF,  // bright
                                   },
                                   {1600,1600}, // DPI
                                   { 
                                     1,           //polling rate
                                     5,         // max stage
                                     3,         // DPI stage
                                     {
                                      {400,400},
                                      {800,800},
                                      {1600,1600},
                                      {3200,3200},
                                      {4800,4800},
                                     },
                                   },
                                 }, 
                                 {          // profile 2 
                                   2,       // profile ID
                                   { 
                                     3,     // effect 
                                     {      // color 
                                      0xFF, //R
                                      0xFF, //G 
                                      0xFF, //B
                                     },
                                     0,     // speed 
                                     0xFF,  // bright
                                   },
                                   {1600,1600}, // DPI
                                   { 
                                     1,           //polling rate
                                     5,         // max stage
                                     3,         // DPI stage
                                     {
                                      {400,400},
                                      {800,800},
                                      {1600,1600},
                                      {3200,3200},
                                      {4800,4800},
                                     },
                                   },
                                 },
                                 {          // profile 3
                                   3,       // profile ID
                                   { 
                                     3,     // effect 
                                     {      // color 
                                      0xFF, //R
                                      0xFF, //G 
                                      0xFF, //B
                                     },
                                     0,     // speed 
                                     0xFF,  // bright
                                   },
                                   {1600,1600}, // DPI
                                   { 
                                     1,           //polling rate
                                     5,         // max stage
                                     3,         // DPI stage
                                     {
                                      {400,400},
                                      {800,800},
                                      {1600,1600},
                                      {3200,3200},
                                      {4800,4800},
                                     },
                                   },
                                 },
                                 {          // profile 4 
                                   4,       // profile ID
                                   { 
                                     3,     // effect 
                                     {      // color 
                                      0xFF, //R
                                      0xFF, //G 
                                      0xFF, //B
                                     },
                                     0,     // speed 
                                     0xFF,  // bright
                                   },
                                   {1600,1600}, // DPI
                                   { 
                                     1,           //polling rate
                                     5,         // max stage
                                     3,         // DPI stage
                                     {
                                      {400,400},
                                      {800,800},
                                      {1600,1600},
                                      {3200,3200},
                                      {4800,4800},
                                     },
                                   },
                                 },                  
                               },
                               0,         // check sum
													   };                      

            
//#define PROFILE_CONTENT 				    40,                                                                                                                      \
//															      {                                                                                                                         \
//																	    { /* Logo led   */                                                                                                        \
//																	      1,                      /*   // Chroma region ID                                                 */           \
//																	      1,                              /*   // B7=Pending, B6=Limited, B5=Change, B4=Flag, B3-1=Effect, B0=On   */            \
//																         /* //flags,rate,color,r,   g,    b,    v,   rr,  gg, bb,   vv                                                */           \
//																        {0, 0,  1, 	0x00,	0xff, 0x00,0xff,0x00,0xff,0x00,0xff,}, /*EFFECT_PRAMv                                       */    \
//																	      4,                 /*   // effect ID                                                        */          \
//																	      0,                                   /*   // extendeffect                                                     */          \
//																	      4,                 /*   // pendingeffect                                                    */          \
//																	      0xff,                                /*   // extendlevel                                                      */          \
//																	      0,                                   /*    // extendTimer                                                     */           \
//																	      0xff,                                /*   // level: Overall brightness                                        */          \
//																	      5,                                   /*   // blinkOn: Length of "On Period" for Blinking (100ms)              */          \
//																	      5,                                   /*   // blinkOff: Length of "Off Period" for Blinking (100ms)            */          \
//																	      10,                                   /*   // transTime: Length of "Step Time" for Transitioning (1ms)           */        \
//																	      1,                                    /*   // transStep: Size of "Step" in magnitude for Transitioning           */        \
//																	      0,                                    /*   // faderTime: Length of "Step Time" for Dissolving (1ms)              */        \
//																	      0,                                    /*   // faderStep: Size of "Step" in magnitude for Dissolving               */       \
//																	      0,                                    /*   // duration: Effect duration target time, if active (state.6 = 1)      */       \
//																	      0,                                    /*   // scratch: Effect temporary variable to be used as needed             */       \
//																	      0,                                    /*   // script: Effect temporary index to be used as needed                 */       \
//																        0,                                    /*   // pwm: Pulse Width Modulator temporary variable                       */       \
//																	      0,                                    /*   // tmr: tmr recorder variables                                         */       \
//																	      0,                                    /*   // index: LED_ID to Index value                                        */       \
//															        },                                      /*                                                                          */       \
//																	  },                                          /* // LED_PARM                                                           */    \
															                   /* //pollingRate,dpiStage,                                                                              */    \
//															      {/*DPI_1800, DPI_1800*/},                                                                                                    \
//                                    {/*2,5,1,{{DPI_800,DPI_800,DPI_800},{DPI_1800,DPI_1800,DPI_1800},{DPI_4500,DPI_4500,DPI_4500},{DPI_9000,DPI_9000,DPI_9000},{DPI_16000,DPI_16000,DPI_16000}}*/},                 /*   // LIFTOFF_SENSOR_PARM                                                                  */    \
//                                    {/*Button ID,  Mode ,  Type[0],Type[1]  Size, D1[0],D1[1]    D2[0],D2[1]  D3[0],D3[1]   D4[0],D4[1]    D5[0],D5[1]         */    \
//                                      /*{BTN_LFT,  MODE_NORM, {BTN_MOUSE,0},   {1,0}, {BTN_LFT,0},     {0,0},      {0,0},        {0,0},         {0,0},  },  */             \
                                      /*{BTN_RGT,  MODE_NORM, {BTN_MOUSE,0},   {1,0}, {BTN_RGT,0},     {0,0},      {0,0},        {0,0},         {0,0},  },*/               \
                                      /*{BTN_MID,  MODE_NORM, {BTN_MOUSE,0},   {1,0}, {BTN_MID,0},     {0,0},      {0,0},        {0,0},         {0,0},  },*/               \
                                      /*{BTN_BCK,  MODE_NORM, {BTN_MOUSE,0},   {1,0}, {BTN_BCK,0},     {0,0},      {0,0},        {0,0},         {0,0},  },*/               \
                                     /* {BTN_FWD,  MODE_NORM, {BTN_MOUSE,0},   {1,0}, {BTN_FWD,0},     {0,0},      {0,0},        {0,0},         {0,0},  }, */              \
																			/*{BTN_RBCK,  MODE_NORM,{BTN_MOUSE,0},   {1,0}, {BTN_BCK,0},     {0,0},      {0,0},        {0,0},         {0,0},  },*/               \
                             	        /*{BTN_DUP,  MODE_NORM, {BTN_DPI,0},     {1,0}, {BTN_STAGE_UP,0},{0,0},      {0,0},        {0,0},         {0,0},  },*/               \
                                      /*{SCROLL_UP, MODE_NORM,{BTN_MOUSE,0},   {1,0}, {SCROLL_UP,0},{0,0},     {0,0},        {0,0},         {0,0},  },*/               \
																			/*{SCROLL_DN, MODE_NORM,{BTN_MOUSE,0},   {1,0}, {SCROLL_DN,0},{0,0},     {0,0},        {0,0},         {0,0},  }, */             \
//																		}                
														 
//                                      {BTN_RFWD,  MODE_NORM,{BTN_MOUSE,0},   {1,0}, {BTN_FWD,0},     {0,0},      {0,0},        {0,0},         {0,0},  },               \														 
//                                      {BTN_DDN,  MODE_NORM, {BTN_DPI,0},     {1,0}, {BTN_STAGE_DN,0},{0,0},      {0,0},        {0,0},         {0,0},  },               \
//																			{BTN_PFS,  MODE_NORM, {BTN_PROFILE,0}, {1,0}, {PROFILE_UP,0},  {0,0},      {0,0},        {0,0},         {0,0},  },              \														 
//																      {    /*  Scroll led                                                                                                 */       \
//																	      CHROMA_WHEEL_ID,                      /*   // Chroma region ID                                                    */       \
//																	      LED_ON,                               /*   // B0=On                                                               */       \
//																            /* //effect_ID ,     flags,rate,color,r,   g,    b,    v,   rr,  gg, bb,   vv                                 */        \
//																        {0, 0,  1, 	0x00,	0xff, 0x00,0xff,0x00,0xff,0x00,0xff,},                                                                  \
//																	      CHROMA_EFX_SPECTRUM,                  /*    // effect ID                                                         */         \
//																	      0,                                    /*   // extendeffect                                                       */        \
//																	      CHROMA_EFX_SPECTRUM,                  /*   // pendingeffect                                                      */        \
//																	      0xff,                                 /*   // extendlevel                                                        */        \
//																	      0,                                    /*   // extendTimer                                                        */        \
//																	      0xff,                                 /*   // level: Overall brightness                                          */        \
//																	      5,                                    /*   // blinkOn: Length of "On Period" for Blinking (100ms)                */        \
//																	      5,                                    /*   // blinkOff: Length of "Off Period" for Blinking (100ms)              */        \
//																	      10,                                    /*  // transTime: Length of "Step Time" for Transitioning (1ms)              */    \
//																	      1,                                     /*  // transStep: Size of "Step" in magnitude for Transitioning              */    \
//																	      0,                                     /*  // faderTime: Length of "Step Time" for Dissolving (1ms)                 */    \
//																	      0,                                     /*  // faderStep: Size of "Step" in magnitude for Dissolving                 */    \
//																	      0,                                     /*  // duration: Effect duration target time, if active (state.6 = 1)        */    \
//																	      0,                                     /*  // scratch: Effect temporary variable to be used as needed               */    \
//																	      0,                                     /*  // script: Effect temporary index to be used as needed                   */    \
//																        0,                                     /*  // pwm: Pulse Width Modulator temporary variable                         */    \
//																	      0,                                     /*  // tmr: tmr recorder variables                                           */    \
//																	      1,                                     /*  // index: LED_ID to Index value                                          */    \
//															        },                                                                                                                          \
//																			{  /* // Left side led                                                                                                */    \
//																	      CHROMAR_LS_ID,                         /*// Chroma region ID                                                        */   \
//																	      LED_ON,                                /* // B7=Pending, B6=Limited, B5=Change, B4=Flag, B3-1=Effect, B0=On         */   \
//																         /* //flags,rate,color,r,   g,    b,    v,   rr,  gg, bb,   vv                                                      */    \
//																        {0, 0,  1, 	0x00,	0xff, 0x00,0xff,0x00,0xff,0x00,0xff,},  /* // EFFECT_PRAMv                                        */    \
//																	      CHROMA_EFX_SPECTRUM,                    /* // effect ID                                                             */    \
//																	      0,                                      /* // extendeffect                                                          */     \
//																	      CHROMA_EFX_SPECTRUM,                    /* // pendingeffect                                                         */     \
//																	      0xff,                                   /* // extendlevel                                                           */     \
//																	      0,                                      /* // extendTimer                                                           */     \
//																	      0xff,                                   /* // level: Overall brightness                                             */    \
//																	      5,                                      /* // blinkOn: Length of "On Period" for Blinking (100ms)                    */     \
//																	      5,                                      /* // blinkOff: Length of "Off Period" for Blinking (100ms)                  */     \
//																	      10,                                      /*// transTime: Length of "Step Time" for Transitioning (1ms)               */     \
//																	      1,                                       /*// transStep: Size of "Step" in magnitude for Transitioning               */     \
//																	      0,                                       /*// faderTime: Length of "Step Time" for Dissolving (1ms)                   */   \
//																	      0,                                       /*// faderStep: Size of "Step" in magnitude for Dissolving                   */   \
//																	      0,                                       /*// duration: Effect duration target time, if active (state.6 = 1)          */   \
//																	      0,                                       /*// scratch: Effect temporary variable to be used as needed                 */   \
//																	      0,                                       /*// script: Effect temporary index to be used as needed                     */   \
//																        0,                                       /*// pwm: Pulse Width Modulator temporary variable                           */   \
//																	      0,                                       /*// tmr: tmr recorder variables                                             */   \
//																	      0,                                       /*// index: LED_ID to Index value                                            */   \
//															        },                                                                                                                           \
//																			{  /*// Right side led                                                                                                  */  \
//																	      CHROMAR_RS_ID,                           /*// Chroma region ID                                                       */   \
//																	      LED_ON,                                 /* // B7=Pending, B6=Limited, B5=Change, B4=Flag, B3-1=Effect, B0=On         */   \
//																         /*//flags,rate,color,r,   g,    b,    v,   rr,  gg, bb,   vv                                                        */   \
//																        {0, 0,  1, 	0x00,	0xff, 0x00,0xff,0x00,0xff,0x00,0xff,},  /* // EFFECT_PRAMv                                        */     \
//																	      CHROMA_EFX_SPECTRUM,                    /*// effect ID                                                             */      \
//																	      0,                                      /*// extendeffect                                                          */     \
//																	      CHROMA_EFX_SPECTRUM,                    /*// pendingeffect                                                         */     \
//																	      0xff,                                   /*// extendlevel                                                           */     \
//																	      0,                                      /*// extendTimer                                                           */     \
//																	      0xff,                                   /*// level: Overall brightness                                             */     \
//																	      5,                                      /*// blinkOn: Length of "On Period" for Blinking (100ms)                   */     \
//																	      5,                                      /*// blinkOff: Length of "Off Period" for Blinking (100ms)                 */     \
//																	      10,                                     /*// transTime: Length of "Step Time" for Transitioning (1ms)             */      \
//																	      1,                                      /*// transStep: Size of "Step" in magnitude for Transitioning             */      \
//																	      0,                                      /*// faderTime: Length of "Step Time" for Dissolving (1ms)                */      \
//																	      0,                                      /*// faderStep: Size of "Step" in magnitude for Dissolving               */    \
//																	      0,                                      /*// duration: Effect duration target time, if active (state.6 = 1)      */    \
//																	      0,                                      /*// scratch: Effect temporary variable to be used as needed             */    \
//																	      0,                                      /*// script: Effect temporary index to be used as needed                 */    \
//																        0,                                      /*// pwm: Pulse Width Modulator temporary variable                       */    \
//																	      0,                                      /*// tmr: tmr recorder variables                                         */    \
//																	      0,                                      /*// index: LED_ID to Index value                                        */    \
//															        },                                        /*                                                                       */    \														 
														 
														 
//const STORAGE3 dft_generic2 = {
//	                              sizeof(STORAGE3),                            // Size of variable storage
//																1,                                           // profile Class 
//																0,                                           // profile[profileNO] PClass-1
//																2,                                           // Show the active profile
//                                1,
//                                0,               
//	                              {
//																	{// [ profile 1
//																    1,                                         // Pofile ID 1
//																		0,                                         // Profile name address
//																		0,                                         // Profile name size
//                                    0,                                         // Profile name crc
//                                    0,                                         // Profile stage, 0 is the name not available
//                                   PROFILE_CONTENT,                                    
//														      }, // ] profile 1
//															    {// [ profile 2
//																    2,                                         // Pofile ID 2
//																		0,                                         // Profile name address
//																		0,                                         // Profile name size
//                                    0,                                         // Profile name crc
//                                    0,                                         // Profile stage, 0 is the name not available
//                                    PROFILE_CONTENT,
//														      }, // ] profile 2
//																	{// [ profile 3
//																    3,                                         // Pofile ID 3
//																		0,                                         // Profile name address
//																		0,                                         // Profile name size
//                                    0,                                         // Profile name crc
//                                    0,                                         // Profile stage, 0 is the name not available
//                                    PROFILE_CONTENT,
//														      }, // ] profile 3
//																	{// [ profile 4
//																    4,                                         // Pofile ID 4
//																		0,                                         // Profile name address
//																		0,                                         // Profile name size
//                                    0,                                         // Profile name crc
//                                    0,                                         // Profile stage, 0 is the name not available
//                                    PROFILE_CONTENT,
//														      }, // ] profile 4
//																	{// [ profile 5
//																    5,                                         // Pofile ID 5
//																		0,                                         // Profile name address
//																		0,                                         // Profile name size
//                                    0,                                         // Profile name crc
//                                    0,                                          // Profile stage, 0 is the name not available
//                                    PROFILE_CONTENT,
//														      }, // ] profile 5
////																	{// [ profile 5
////																    6,                                         // Pofile ID 6
////                                    PROFILE_CONTENT,
////														      }, // ] profile 5
//																},
//                                0,                           // check sum	
//                              };

 const BREATH_PARM breathPr = {
															 	 150,                     // pulseOn: Length of "On Period" for Pulsating (1ms)                  
																 1700,                    // pulseOff: Length of "Off Period" for Pulsating (1ms)                
																 5,                       // pulseRiseTime: Length of "Step Rising step Time" for Pulsating (1ms)
																 140,                     // pulseRise1Step: Size of "Rise 1 Step" in magnitude for Pulsating    
																 140,                     // pulseRise2Step: Size of "Rise 2 Step" in magnitude for Pulsating    
																 5,                       // pulseFallTime: Length of "Fall Step Time" for Pulsating (1ms)       
																 117,                     // pulseFall1Step: Size of "Fall 1 Step" in magnitude for Pulsating   
																 117,                     // pulseFall2Step: Size of "Fall 2 Step" in magnitude for Pulsating   
																 30000,                   // pulseNeckLine: Size of "Neck line" of Rise or Fall 1 and 2        
															 };                        




