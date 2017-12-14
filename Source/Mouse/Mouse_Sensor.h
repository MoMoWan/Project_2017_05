
#ifndef __MOUSE_SENSOR_H__
#define __MOUSE_SENSOR_H__

#include <SN32F240B.h>	
#include "main.h"	

extern void	MS_SensorInit(void);
extern void MN_SensorState(void);

extern uint8_t SPI_Read_1Byte(uint8_t bRegAddr);
extern void SPI0_Write_2Byte( uint8_t bRegAddr, uint8_t bData);
extern void setResolution(U16 x,U16 y);
#endif //__MOUSE_SENSOR_H__




