
#ifndef __MOUSE_KEY_H__
#define __MOUSE_KEY_H__

#include "SN32F240B.h"

extern void MN_KeyScanState(void);

void	MS_ScanState(void);
void 	MS_CheckMatrixState(void);	
void 	KB_CheckDebounce(uint8_t bCurrentColNum, uint8_t bKeyMap_Data);	
void	KB_ConvertUsbUsage(uint8_t bCRIndex, uint8_t bKeyEvent);
void    MS_BufferUsbKey(uint16_t wKeycode, uint8_t bKeyEvent);

void	MS_NFireState(void);

#endif //__MOUSE_KEY_H__

