
#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <SN32F240B.h>
#include 	"Mouse_IOSetting.h"

#define button_input ((1 << 7) | (((MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_6) >> MS_KEY_IO_PM_6_N) << 6) | (((MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_5) >> MS_KEY_IO_PM_5_N) << 5) | (((MS_KEY_PM_1->DATA & mskMS_KEY_IO_PM_4) >> MS_KEY_IO_PM_4_N) << 4) | (((MS_KEY_PM_1->DATA & mskMS_KEY_IO_PM_3) >> MS_KEY_IO_PM_3_N) << 3) |\
                      (((MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_2) >> MS_KEY_IO_PM_2_N) << 2) | (((MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_1) >> MS_KEY_IO_PM_1_N) << 1) | (((MS_KEY_PM_0->DATA & mskMS_KEY_IO_PM_0) >> MS_KEY_IO_PM_0_N) << 0))                      
extern void MS_Init(void);	
extern void MS_GpioInit(void);
extern void MS_RamInit(void);
extern void	MS_TimerInit(void);		

#endif //__MOUSE_H__

