/*++

Copyright (c) 2012-2014 Razer Ltd.
All rights reserved. This program contains proprietary and confidential information.

Module Name:
  main.h

Compiler:
  Keil Software µVision v5.11, with NXP Semiconductor LPC11U2x proccessor support.

Abstract:
  This file contains the definitions for main.c, which provides the overall structure
  along with the initialization procedures.

--*/

#ifndef _MAIN_H_
#define _MAIN_H_

#include "stdint.h"
#include "string.h"
//#include "lpc11U6x.h"
#include "Type.h"
#include "stdbool.h"

 
#define EVENT_RESET                  (1 << 3)
#define NOTIFY_MAKE                  (1 << 4)
#define NOTIFY_BREAK                 (1 << 5)
#define NOTIFY_20sTimeout            (1 << 6)
#define NOTIFY_11MinTimeout          (1 << 7)


#define  UFALSE                    0x10
#define  UTRUE                     0x02


#define LPC_RAM_BASE                  (0x10000000UL)

#define SW_DFU_FLAG_ADDR              (0x20004800-4)        // Soft enter dfu flag address in ram
#define SW_DFU_SIGNATURE               (0xAAAAAAAA)         // Enter DFU by ram signature value

//#define APPLICATION_START             0x1000              // address 0x0000-0x0FFF for bootloader code
//#define APPLICATION_END               0xFff0              // address 0x5F00- 0x5FFF for SW bootloader flag

#define MANUFACTURING_SATRT           0x0000              // EEPROM, 0x0000-0x0039, first 64 bytes for manufacturing data, SN...
#define USER_SETTING_START            0x0040              // EEPROM, 0x0040-0xAF, third 50 bytes for user setting data
#define Profile_SETTING_START         0x00B0              // EEPORM, 0x00A4-0x0a00, for profile (1/2/3/4/5)
#define MACRO_START                   0x0938              // EEPORM, 0x0A00-end ,2247bytes
#define BLOCK_MAMAGE_START            0x0F1D              // EEPORM, 0x0f1d-0xfbf ,164 bytes


#define FAILURE                       0                   // Value is 'FAILURE'
#define SUCCESS                       1                   // Value is 'SUCCESS'

#define SHOUT_CASTER_MOUSE            1

#define DEVICE_VID                    0x1532              // Device Vendor ID (Razer)
#define DEVICE_PID                    0x0060              // Device PID for DA2000

#define LOADER_VID                    0x1532              // Device Vendor ID (Razer)
#define LOADER_PID                    0x110D              // Bootloader Product ID

//#define GENERIC_STORAGE               0xb000              // Generic Variable Storage (Last Page)
#define SPECIAL_STORAGE               0x0E00              // Special Variable Storage (BootBlock)
#define SPECIAL_LAST                  0x0FC0              // Last valid Special Storage address
#define STORAGE_ABANDON               0x00                // Special Storage has been abandon
#define STORAGE_VALID                 0xAA                // Special Storage is valid
#define STORAGE_UNUSED                0xFF                // Special Storage is unused

#define GENERIC_DATA                  (1 << 0)            // Generic data updating flag
#define SPECIAL_DATA                  (1 << 1)            // Manufacturing data updating flag
#define GENERICPr_DATA                (1 << 2)            // Profile data unpdate
#define MACRO_DATA_UPDATE             (1 << 3)            // Macro data update  
#define BLOCK_MANAGE_DATA             (1 << 4)            // Storage block management 

#define USER_CHANGED                  (1 << 0)            // Generic data update with no delay
#define SW_CHANGED                    (1 << 1)            // Generic data update with longer delay
#define FACTORY_CHANGED               (1 << 2)            // Manufacturing data update
#define SW_CHANGEDPr                  (1 << 3)            // Profile data unpdate
#define DEVICE_CHANGED                (1 << 4)
#define MACRO_CHANGE                  (1 << 5)            // Need to change macro data
#define BLOCK_ASSIGN_CHANGE           (1 << 6)            // Storage block management 
#define BOOTLOADER_CHANGE             (1 << 7)            // Bootloader 

#define BUFFERING_TIME_USER           0                   // Amount of time to wait before update (ms)
#define BUFFERING_TIME_SW             100                   // Amount of time to wait before update (ms)

#define NORMAL_MODE                   0x00                // Device mode normal definition
#define BOOTLOADER_MODE               0x01                // Device mode bootloader definition
#define TEST_MODE                     0x02                // Device mode test definition
#define DRIVER_MODE                   0x03                // Device mode driver definition
#define DOWNLODAR_MODE                0x04                //
#define RF_TEST_MODE									0x08								// RF test mode

#define WAKE_KEY                     (1 << 0)             // Wakeup on Key activity
#define WAKE_BUTTON                  (1 << 1)             // Wakeup on Button activity
#define WAKE_WHEEL                   (1 << 2)             // Wakeup on Scroll Wheel activity
#define WAKE_MOVEMENT                (1 << 3)             // Wakeup on Mouse Movement activity
#define WAKE_USB_RESET               (1 << 4)             // Wakeup on USB bus reset
#define WAKE_WIRELESS                (1 << 5)             // Wakeup on by wireless mouse sendding data to Dock
#define WAKE_NON_IDLE                (1 << 6)             // Wakeup on USB non-idle activity


#define PROXIMITY_RATE                0x0000
#define PROXIMITY_COUNT               0x0000
#define PROXIMITY_RESULT              0x0000


#define PROXIMITY_LO                  0x0030//(700)               // Default Proximity Low Threshold value
#define PROXIMITY_HI                  (PROXIMITY_LO)      // Default Proximity High Threshold value

#define PROXIMITY_HIGH                0x14                // Default Threshold adjustment: PS0 - ((Height + 10) * 5)
#define PROXIMITY_HYST                0x32                // Default Hysteresis adjustment: Proximity (max - min)

#define PROTOCOL_DATA_SIZE            (1)                // Razer Protocol 2.5 data size

//#define NUMBER_OF_DPI_STAGES          (3)
#define NUMBER_OF_LEDS                (1)                 // Number of LEDs under software control
#define MAXNUMBER_LEDS                (1)                 // Max number of leds per led id 
#define NUMBER_OF_BUTTONS             (7+2)              // Number of buttons: 8 mouse button, +2 is for scroll up and down 
#define profileNO                     (5) //(6)                // Number of profile: 1/2/3/4/5  1£ºfor driver mode profile 0:tmp profile , so actually 

#define NUMBER_OF_STAGES              (5)                 // Number of stages
#define DPI_800                      (800)                // 800 DPI protocol value
#define DPI_1800                     (1800)               // 1800 DPI protocol value
#define DPI_3500                     (3500)               // 3500 DPI protocol value
#define	DPI_4500                     (4500)
#define DPI_5000                     (5000)               // 5000 DPI protocol value
#define DPI_6400                     (6400)               // 6400 DPI protocol value
#define DPI_9000                     (9000)
#define DPI_16000                    (16000)


#define DEVICE_STATUS_NORMAL          0x00
#define DEVICE_STATUS_RETAIL          0x01

#define FW_DPI_EN                     (1)

#define BASIC_FW                      (0)                 // define for basic FW and norma FW switch

#define releaseFW                     (1)                 // 0: disable WDT and SYSMEMREMAP default, for debug
                                                          // 1: enable WDT and SYSMEMREMAP 0x01, for FW release

#define EP_OVERWRITE_PROTECT          (0)                 // For it is mouse, not risk for ep overwrite hapeen. removed.
#define MOUSE_SENSOR_ID               0x04                // Avago 3389 sensor SROM ID  
int  main                (void);
void initializeHardware  (void);
void initializeVariables (void);
//void irq_initialization  (void);
void delayMilliseconds(U16 time);
void delayMicroseconds(U16 time);
U16  crc16(U8* pData, U16 len);
U16 crc16_parm(U8* pData, U16 len,U16 preCrc);
U32  randomGenerate(U32 lower, U32 upper);

#endif // _MAIN_H_
