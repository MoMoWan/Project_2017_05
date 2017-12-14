/**
  ******************************************************************************
  * @file    FLASH/FLASH_EraseProgram/Inc/main.h
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    11-September-2015
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/

#include	"SN32F240B.h"
#include	"SN32F200_Def.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

typedef int8_t                        S8;                 // 8-bit signed integer
typedef uint8_t                       U8;                 // 8-bit unsigned integer
typedef int16_t                       S16;                // 16-bit signed integer
typedef uint16_t                      U16;                // 16-bit unsigned integer
typedef int32_t                       S32;                // 32-bit signed integer
typedef uint32_t                      U32;                // 32-bit unsigned integer
typedef int64_t                       S64;                // 64-bit signed integer
typedef uint64_t                      U64;                // 64-bit unsigned integer
typedef char                          BOOL;               // Boolean

#ifndef NULL
#define NULL    ((void *)0)
#endif

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif

#ifndef UP
#define UP    (1)
#endif

#ifndef DOWN
#define DOWN    (0)
#endif

#ifndef RGB
#define RGB    (1)
#endif

#ifndef SIG
#define SIG    (0)
#endif

#ifndef ENABLE
#define ENABLE  (1)
#endif

#ifndef DISABLE
#define DISABLE (0)
#endif

/* Base address of the Flash sectors */
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0, 2 Kbytes */
#define ADDR_FLASH_PAGE_1     ((uint32_t)0x08000800) /* Base @ of Page 1, 2 Kbytes */
#define ADDR_FLASH_PAGE_2     ((uint32_t)0x08001000) /* Base @ of Page 2, 2 Kbytes */
#define ADDR_FLASH_PAGE_3     ((uint32_t)0x08001800) /* Base @ of Page 3, 2 Kbytes */
#define ADDR_FLASH_PAGE_4     ((uint32_t)0x08002000) /* Base @ of Page 4, 2 Kbytes */
#define ADDR_FLASH_PAGE_5     ((uint32_t)0x08002800) /* Base @ of Page 5, 2 Kbytes */
#define ADDR_FLASH_PAGE_6     ((uint32_t)0x08003000) /* Base @ of Page 6, 2 Kbytes */
#define ADDR_FLASH_PAGE_7     ((uint32_t)0x08003800) /* Base @ of Page 7, 2 Kbytes */
#define ADDR_FLASH_PAGE_8     ((uint32_t)0x08004000) /* Base @ of Page 8, 2 Kbytes */
#define ADDR_FLASH_PAGE_9     ((uint32_t)0x08004800) /* Base @ of Page 9, 2 Kbytes */
#define ADDR_FLASH_PAGE_10    ((uint32_t)0x08005000) /* Base @ of Page 10, 2 Kbytes */
#define ADDR_FLASH_PAGE_11    ((uint32_t)0x08005800) /* Base @ of Page 11, 2 Kbytes */
#define ADDR_FLASH_PAGE_12    ((uint32_t)0x08006000) /* Base @ of Page 12, 2 Kbytes */
#define ADDR_FLASH_PAGE_13    ((uint32_t)0x08006800) /* Base @ of Page 13, 2 Kbytes */
#define ADDR_FLASH_PAGE_14    ((uint32_t)0x08007000) /* Base @ of Page 14, 2 Kbytes */
#define ADDR_FLASH_PAGE_15    ((uint32_t)0x08007800) /* Base @ of Page 15, 2 Kbytes */
#define ADDR_FLASH_PAGE_16    ((uint32_t)0x08008000) /* Base @ of Page 16, 2 Kbytes */
#define ADDR_FLASH_PAGE_17    ((uint32_t)0x08008800) /* Base @ of Page 17, 2 Kbytes */
#define ADDR_FLASH_PAGE_18    ((uint32_t)0x08009000) /* Base @ of Page 18, 2 Kbytes */
#define ADDR_FLASH_PAGE_19    ((uint32_t)0x08009800) /* Base @ of Page 19, 2 Kbytes */
#define ADDR_FLASH_PAGE_20    ((uint32_t)0x0800A000) /* Base @ of Page 20, 2 Kbytes */
#define ADDR_FLASH_PAGE_21    ((uint32_t)0x0800A800) /* Base @ of Page 21, 2 Kbytes  */
#define ADDR_FLASH_PAGE_22    ((uint32_t)0x0800B000) /* Base @ of Page 22, 2 Kbytes  */
#define ADDR_FLASH_PAGE_23    ((uint32_t)0x0800B800) /* Base @ of Page 23, 2 Kbytes */
#define ADDR_FLASH_PAGE_24    ((uint32_t)0x0800C000) /* Base @ of Page 24, 2 Kbytes */
#define ADDR_FLASH_PAGE_25    ((uint32_t)0x0800C800) /* Base @ of Page 25, 2 Kbytes */
#define ADDR_FLASH_PAGE_26    ((uint32_t)0x0800D000) /* Base @ of Page 26, 2 Kbytes */
#define ADDR_FLASH_PAGE_27    ((uint32_t)0x0800D800) /* Base @ of Page 27, 2 Kbytes */
#define ADDR_FLASH_PAGE_28    ((uint32_t)0x0800E000) /* Base @ of Page 28, 2 Kbytes */
#define ADDR_FLASH_PAGE_29    ((uint32_t)0x0800E800) /* Base @ of Page 29, 2 Kbytes */
#define ADDR_FLASH_PAGE_30    ((uint32_t)0x0800F000) /* Base @ of Page 30, 2 Kbytes */
#define ADDR_FLASH_PAGE_31    ((uint32_t)0x0800F800) /* Base @ of Page 31, 2 Kbytes */
#define ADDR_FLASH_PAGE_32    ((uint32_t)0x08010000) /* Base @ of Page 32, 2 Kbytes */
#define ADDR_FLASH_PAGE_33    ((uint32_t)0x08010800) /* Base @ of Page 33, 2 Kbytes */
#define ADDR_FLASH_PAGE_34    ((uint32_t)0x08011000) /* Base @ of Page 34, 2 Kbytes */
#define ADDR_FLASH_PAGE_35    ((uint32_t)0x08011800) /* Base @ of Page 35, 2 Kbytes */
#define ADDR_FLASH_PAGE_36    ((uint32_t)0x08012000) /* Base @ of Page 36, 2 Kbytes */
#define ADDR_FLASH_PAGE_37    ((uint32_t)0x08012800) /* Base @ of Page 37, 2 Kbytes */
#define ADDR_FLASH_PAGE_38    ((uint32_t)0x08013000) /* Base @ of Page 38, 2 Kbytes */
#define ADDR_FLASH_PAGE_39    ((uint32_t)0x08013800) /* Base @ of Page 39, 2 Kbytes */
#define ADDR_FLASH_PAGE_40    ((uint32_t)0x08014000) /* Base @ of Page 40, 2 Kbytes */
#define ADDR_FLASH_PAGE_41    ((uint32_t)0x08014800) /* Base @ of Page 41, 2 Kbytes */
#define ADDR_FLASH_PAGE_42    ((uint32_t)0x08015000) /* Base @ of Page 42, 2 Kbytes */
#define ADDR_FLASH_PAGE_43    ((uint32_t)0x08015800) /* Base @ of Page 43, 2 Kbytes */
#define ADDR_FLASH_PAGE_44    ((uint32_t)0x08016000) /* Base @ of Page 44, 2 Kbytes */
#define ADDR_FLASH_PAGE_45    ((uint32_t)0x08016800) /* Base @ of Page 45, 2 Kbytes */
#define ADDR_FLASH_PAGE_46    ((uint32_t)0x08017000) /* Base @ of Page 46, 2 Kbytes */
#define ADDR_FLASH_PAGE_47    ((uint32_t)0x08017800) /* Base @ of Page 47, 2 Kbytes */
#define ADDR_FLASH_PAGE_48    ((uint32_t)0x08018000) /* Base @ of Page 48, 2 Kbytes */
#define ADDR_FLASH_PAGE_49    ((uint32_t)0x08018800) /* Base @ of Page 49, 2 Kbytes */
#define ADDR_FLASH_PAGE_50    ((uint32_t)0x08019000) /* Base @ of Page 50, 2 Kbytes */
#define ADDR_FLASH_PAGE_51    ((uint32_t)0x08019800) /* Base @ of Page 51, 2 Kbytes */
#define ADDR_FLASH_PAGE_52    ((uint32_t)0x0801A000) /* Base @ of Page 52, 2 Kbytes */
#define ADDR_FLASH_PAGE_53    ((uint32_t)0x0801A800) /* Base @ of Page 53, 2 Kbytes  */
#define ADDR_FLASH_PAGE_54    ((uint32_t)0x0801B000) /* Base @ of Page 54, 2 Kbytes  */
#define ADDR_FLASH_PAGE_55    ((uint32_t)0x0801B800) /* Base @ of Page 55, 2 Kbytes */
#define ADDR_FLASH_PAGE_56    ((uint32_t)0x0801C000) /* Base @ of Page 56, 2 Kbytes */
#define ADDR_FLASH_PAGE_57    ((uint32_t)0x0801C800) /* Base @ of Page 57, 2 Kbytes */
#define ADDR_FLASH_PAGE_58    ((uint32_t)0x0801D000) /* Base @ of Page 58, 2 Kbytes */
#define ADDR_FLASH_PAGE_59    ((uint32_t)0x0801D800) /* Base @ of Page 59, 2 Kbytes */
#define ADDR_FLASH_PAGE_60    ((uint32_t)0x0801E000) /* Base @ of Page 60, 2 Kbytes */
#define ADDR_FLASH_PAGE_61    ((uint32_t)0x0801E800) /* Base @ of Page 61, 2 Kbytes */
#define ADDR_FLASH_PAGE_62    ((uint32_t)0x0801F000) /* Base @ of Page 62, 2 Kbytes */
#define ADDR_FLASH_PAGE_63    ((uint32_t)0x0801F800) /* Base @ of Page 63, 2 Kbytes */
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_63 + FLASH_PAGE_SIZE   /* End @ of user Flash area */

#define GENERIC_DATA                  (1 << 0)            // Generic data updating flag
#define SPECIAL_DATA                  (1 << 1)            // Manufacturing data updating flag
#define USER_LED_DATA                 (1 << 2)            // Generic data updating flag for Custom effect LED matrix data
#define CRC_DATA                      (1 << 3)
#define USER_CHANGED                  (1 << 0)            // Generic data update with no delay
#define SW_CHANGED                    (1 << 1)            // Generic data update with longer delay
#define FACTORY_CHANGED               (1 << 2)            // Manufacturing data update
#define LED_CUSTOM_CHANGED            (1 << 3)            // LED Custom matrix data changed.
#define BUFFERING_TIME_USER           0                   // Amount of time to wait before update (ms)
#define BUFFERING_TIME_SW             103                   // Amount of time to wait before update (ms)

#define NORMAL_MODE                   0x00                // Device mode normal definition
#define DRIVER_MODE                   0x01                // Device mode bootloader definition
#define CLOCK_MODE                    0x02                // Device mode test definition
#define BOOTLOADER_MODE               0x03                // Device mode driver definition
#define TEST_MODE                     0x10                // Device mode test definition
#define DOWNLODAR_MODE                0x05                //
#define RF_TEST_MODE									0x08								// RF test mode

#define CRC16_START                   0x0000              // EEPROM, 0x0000-0x0008 for crc16 data of all saved setting 
#define MANUFACTURING_SATRT           0xFC00              // EEPROM, 0x0008-0x0039, first 56 bytes for manufacturing data, SN...
#define USER_SETTING_START            0xFC80              // EEPROM, 0x0040-0x01ff, for user setting data

#define NUMBER_OF_LEDS                (1)
#define MAX_LED_NUM         (144)                         // One chip support 144 led max


#define NUMBER_OF_ENDPOINT                (4)
#define NUMBER_OF_REPORTID                (2)
//#define SHOWMODE
//#define INDIVUAL_FN
//#define  EXTERNALCLOCK
#define KEYS87


//#define ADC_0_25VCC       0x3FF0                          // 0xFFC0 * 0.25 = 0x3FF0
//#define ADC_0_50VCC       0x7FE0                          // 0xFFC0 * 0.50 = 0x7FE0
//#define ADC_0_75VCC       0xBFD0                          // 0xFFC0 * 0.75 = 0xBFD0
//#define ADC_RANGE         0x1FF8                          // 0xFFC0 * 0.25 /2 = 0x1FF8
//[ definition of the scroll mode 
#define volumeMode        0x00                            // US keyborad layout
#define backlitMode       0x01                            // US keyborad layout
#define inputMode         0x02                            // EU keyborad layout
#define singleColorMode   0x03                            // JP keyborad layout
//#define KBLayout_KR       0x04                            // KR keyborad layout 
//#define KBLayout_BZ       0x05                            // BZ keyborad layout

//[ RTC define
#define BACKUP_COUNT RTC_BKP_NUMBER

/* Defines related to Clock configuration */
/* Uncomment to enable the adaquate Clock Source */
#define RTC_CLOCK_SOURCE_LSE
/*#define RTC_CLOCK_SOURCE_LSI*/

#ifdef RTC_CLOCK_SOURCE_LSI
#define RTC_ASYNCH_PREDIV    0x7F
#define RTC_SYNCH_PREDIV     0x0130
#endif

#ifdef RTC_CLOCK_SOURCE_LSE
#define RTC_ASYNCH_PREDIV  0x7F
#define RTC_SYNCH_PREDIV   0x00FF
#endif

//]

/* Exported variables ------------------------------------------------------- */
void USB_checkStatus(void);
//extern CRC_HandleTypeDef hcrc;
//extern I2C_HandleTypeDef hi2c2;
//extern IWDG_HandleTypeDef hiwdg;
//extern TIM_HandleTypeDef htim2;
//extern TIM_HandleTypeDef htim6;
//extern TIM_HandleTypeDef htim7;
//extern RTC_HandleTypeDef hrtc;
//extern WWDG_HandleTypeDef hwwdg;
//extern uint8_t aTxBuffer[];
//extern USBD_HandleTypeDef hUsbDeviceFS;
extern uint32_t remotewakeupon;// __IO uint32_t remotewakeupon;
/* Exported functions ------------------------------------------------------- */
void initializeVariables(void);
void MX_GPIO_Init(void);
void MX_CRC_Init(void);
void MX_I2C2_Init(void);
void MX_TIM2_Init(void);
void MX_RTC_Init(void);
void MX_PVD_Init(void);
#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


