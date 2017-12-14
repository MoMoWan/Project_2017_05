
#include "Mouse_Sensor.h"
#include "Mouse_Const.h"
#include "Mouse_RamSetting.h"
//#include "..\Driver\SPI0.h"
#include "..\Utility\Utility.h"
#include "main.h"
#include "SPI.h"
#include "avago_api.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/


/*****************************************************************************
* Function			: MS_SensorInit
* Description		: MS_SensorInit
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MS_SensorInit(void)
{
	//Reset Sensor SPI.
//	__SPI0_CLR_SEL0
//	__UT_MAIN_tSRAD
//	__SPI0_SET_SEL0
//	
//#ifdef	PMW3325
//	
//	SPI_W_2BYTE(SENSOR_RESET, SETTING_POWER_UP_RESET);
//	__UT_MAIN_tSWW;	
//	SPI_W_2BYTE(SENSOR_RESOLUTION_3325, SENSOR_RESOLUTION_3000_3325);
//	__UT_MAIN_tSWW;	
//	SPI_W_2BYTE(0x18, 0x39);				//Must Write 0x39 To 0x18
//	UT_MAIN_DelayNms(50);	
//	
//#else			//3360

//	SPI_W_2BYTE(SENSOR_RESET, SETTING_POWER_UP_RESET);	
//	UT_MAIN_DelayNms(50);	
//	
//	__UT_MAIN_tSWW;	
//	SPI_W_2BYTE(SENSOR_CONTROL_3360, DEGREE_0_3360);
//	
//	__UT_MAIN_tSWW;	
//	SPI_W_2BYTE(SENSOR_CONFIG1_3360, SENSOR_CPI_5000_3360);
//	
////	__UT_MAIN_tSWW;	
////	SPI_W_2BYTE(SENSOR_CONFIG2_3360, REST_DISENABLE);
//	
//	__UT_MAIN_tSWW;	
//	SPI_W_2BYTE(SENSOR_CONFIG5_3360, SENSOR_CPI_5000_3360);	
//	
//#endif

//	__UT_MAIN_tSWW;		

	//MS_SensorDPISetting_by_SPI();
//  SN_GPIO0->MODE |= (0x01<<6);	//set P05 is ouput mode
//  SN_GPIO0->BSET |= (0x01<<6);
   sensorPowerUp();                                      // sensor power up
}

/*****************************************************************************
* Function			: MN_SensorState
* Description		: MN_SensorState
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void MN_SensorState(void)
{	
//Burst Read	
#ifdef PMW3325
	
	uint16_t dbDelta_Y;
	
	b_arySPI_Rx_Fifo[0] = SPI_R_BYTE(SENSOR_PRODUCT_ID);
	
	if(b_arySPI_Rx_Fifo[0] != PMW3325_PRODUCT_ID )	
	{
		//If product ID check Fail , system back to Boot mode for init Sensor
		bMN_State = S_MAIN_BOOT_STATE;
		return;
	}
	
	SPI_Burst_Read(SENSOR_BURST_3325);			
	if(b_arySPI_Rx_Fifo[0] & mskSENSOR_MotionStaus)					//if Motion
	{	
		b_aryKB_Mouse[1] = b_arySPI_Rx_Fifo[2];						//X_L
		b_aryKB_Mouse[2] = b_arySPI_Rx_Fifo[3];						//X_H
		
		dbDelta_Y =( (b_arySPI_Rx_Fifo[5]<<8) | b_arySPI_Rx_Fifo[4] );
		dbDelta_Y = (~dbDelta_Y)+1;									//
		
		b_aryKB_Mouse[3] = (dbDelta_Y & 0x0FF);						//Y_L
		b_aryKB_Mouse[4] = ((dbDelta_Y>>8) & 0x0FF);				//Y_H
		
		wKB_SendStatus |= mskKB_SendMouseFlag;						//Send data to Host
	}
	
#else			//PMW3360
	
//	b_arySPI_Rx_Fifo[0] = SPI_R_BYTE(REG_SROM_ID/*SENSOR_PRODUCT_ID*/);
	
	//if(b_arySPI_Rx_Fifo[0] != PMW3360_PRODUCT_ID )
//    if(b_arySPI_Rx_Fifo[0] != PMW3389_PRODUCT_ID )	
//	{
		//If product ID check Fail , system back to Boot mode for init Sensor
//		bMN_State = S_MAIN_BOOT_STATE;
//		return;
//	}
//  __UT_MAIN_tSRW
  checkSROM();
	__UT_MAIN_tSRW
	//SPI_W_2BYTE(SENSOR_MOTION_STATUS,0x0FF);						//Write any data to Clear MOTION
  SPI_W_2BYTE(SENSOR_BURST_3360,0x0FF);						//Write any data to Clear MOTION
	__UT_MAIN_tSWR
	
	SPI_Burst_Read(SENSOR_BURST_3360);			
	if(b_arySPI_Rx_Fifo[0] & mskSENSOR_MotionStaus)					//if Motion
	{	
		b_aryKB_Mouse[1] = b_arySPI_Rx_Fifo[2];
		b_aryKB_Mouse[2] = b_arySPI_Rx_Fifo[3];
		b_aryKB_Mouse[3] = b_arySPI_Rx_Fifo[4];
		b_aryKB_Mouse[4] = b_arySPI_Rx_Fifo[5];
		
		wKB_SendStatus |= mskKB_SendMouseFlag;
	}

#endif

////Normal Read
//#ifdef PMW3325
//	b_arySPI_Rx_Fifo[0] = SPI_R_BYTE(SENSOR_MOTION_STATUS);
//	
//	if(b_arySPI_Rx_Fifo[0] & mskSENSOR_MotionStaus)
//	{
////		__UT_MAIN_tSRR
//		b_arySPI_Rx_Fifo[2] = SPI_R_BYTE(SENSOR_DELTA_X_L);	
////		__UT_MAIN_tSRR
//		b_arySPI_Rx_Fifo[3] = SPI_R_BYTE(SENSOR_DELTA_X_H);	
////		__UT_MAIN_tSRR		
//		b_arySPI_Rx_Fifo[4] = SPI_R_BYTE(SENSOR_DELTA_Y_L);		
////		__UT_MAIN_tSRR
//		b_arySPI_Rx_Fifo[5] = SPI_R_BYTE(SENSOR_DELTA_Y_H);
//		
//		b_aryKB_Mouse[1] = b_arySPI_Rx_Fifo[2];
//		b_aryKB_Mouse[2] = b_arySPI_Rx_Fifo[3];
//		b_aryKB_Mouse[3] = b_arySPI_Rx_Fifo[4];
//		b_aryKB_Mouse[4] = b_arySPI_Rx_Fifo[5];
//		
//		wKB_SendStatus |= mskKB_SendMouseFlag;
//		
////		b_arySPI_Rx_Fifo[4] = SPI_R_BYTE(SENSOR_SQUAL);	
////		b_arySPI_Rx_Fifo[5] = SPI_R_BYTE(SENSOR_PIX_SUM); 			
////		b_arySPI_Rx_Fifo[6] = SPI_R_BYTE(SENSOR_PIX_MAX);
//	}
//#else			//PMW3360
//	//Should write any value to SENSOR_MOTION_STATUS first
//	SPI_W_2BYTE(SENSOR_MOTION_STATUS,0x0FF);		
//	__UT_MAIN_tSWR
//	b_arySPI_Rx_Fifo[0] = SPI_R_BYTE(SENSOR_MOTION_STATUS);
//	
//	if(b_arySPI_Rx_Fifo[0] & mskSENSOR_MotionStaus)
//	{
////		__UT_MAIN_tSRR
//		b_arySPI_Rx_Fifo[2] = SPI_R_BYTE(SENSOR_DELTA_X_L);	
////		__UT_MAIN_tSRR
//		b_arySPI_Rx_Fifo[3] = SPI_R_BYTE(SENSOR_DELTA_X_H);	
////		__UT_MAIN_tSRR		
//		b_arySPI_Rx_Fifo[4] = SPI_R_BYTE(SENSOR_DELTA_Y_L);		
////		__UT_MAIN_tSRR
//		b_arySPI_Rx_Fifo[5] = SPI_R_BYTE(SENSOR_DELTA_Y_H);
//		
//		b_aryKB_Mouse[1] = b_arySPI_Rx_Fifo[2];
//		b_aryKB_Mouse[2] = b_arySPI_Rx_Fifo[3];
//		b_aryKB_Mouse[3] = b_arySPI_Rx_Fifo[4];
//		b_aryKB_Mouse[4] = b_arySPI_Rx_Fifo[5];
//		
//		wKB_SendStatus |= mskKB_SendMouseFlag;
//	}
//#endif
	
	bMN_State = S_MAIN_IDLE_STATE;	
	
}

void setResolution(U16 x,U16 y)
/*++

Function Description:
  This function sets sensor resolution. The Sensor handles settings 800 cpi and 
  1800 cpi. The lowest setting of 400 cpi is achieved mathematically by dividing
  800 cpi displacement values by two.
 
Arguments:
  NONE

Returns: 
  NONE

--*/
{
//	 dpiCurrent.x = x;
//   dpiCurrent.y = y;
	
//[ for PWM3389 Sensor  
  // must first high then low, Jolie 20160824
  SPI_W_2BYTE(REG_RESOLUTION_H, (y/50)>> 8); 
	SPI_W_2BYTE(REG_RESOLUTION_L, (U8)(y/50));
  
  SPI_W_2BYTE(REG_CONFIG5_H,(x/50)>> 8);
	SPI_W_2BYTE(REG_CONFIG5_L,(U8)(x/50));

//]  
//  requestNtfEvent(NTF_DPI, 0);

//  mouseEvent = 0;                                         // Clear mouse event make the write there are no motion data
//  xCount = yCount = 0;                                    // The motion data will infulence the  x y
}

//IO¿ÚÄ£ÄâSPI£¬ÔÝÎ´ÓÃ
/*****************************************************************************
* Function			: SPI0_Write_2Byte
* Description		: SPI0_Write_2Byte
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void SPI0_Write_2Byte( uint8_t bRegAddr, uint8_t bData)
{
	uint8_t i;
	uint16_t Data;
	
	Data = ( 0x8000 | (bRegAddr<<8) | bData );
	
	__SPI0_CLR_SEL
	__SPI0_SDIO_OUTPUTMODE
	UT_MAIN_DelayNx1us(1);
	
	for(i=0;i<16;i++)
	{
		__SPI0_CLR_SCK
		
		if(Data&0x8000)
			__SPI0_SET_SDIO
		else
			__SPI0_CLR_SDIO
		
		Data<<=1;
		
		UT_MAIN_DelayNx1us(1);
		__SPI0_SET_SCK
		UT_MAIN_DelayNx1us(1);
		
	}
	
	UT_MAIN_DelayNx1us(1);
	__SPI0_SDIO_INPUTMODE
	__SPI0_SET_SEL
	
}

/*****************************************************************************
* Function			: SPI_Read_1Byte
* Description		: SPI_Read_1Byte
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
uint8_t SPI_Read_1Byte(uint8_t bRegAddr)
{
	uint8_t i,RegAddr,Data;
	
	RegAddr = (READ_BIT|bRegAddr);
	__SPI0_SDIO_OUTPUTMODE
	__SPI0_CLR_SEL
	
	UT_MAIN_DelayNx1us(1);
	
	for(i=0;i<8;i++)
	{
		__SPI0_CLR_SCK

		if(RegAddr&0x80)
			__SPI0_SET_SDIO
		else
			__SPI0_CLR_SDIO
		RegAddr<<=1;
		
		UT_MAIN_DelayNx1us(1);
		__SPI0_SET_SCK
		UT_MAIN_DelayNx1us(1);
	}
	
	__UT_MAIN_tSRAD
	
	//read data
	__SPI0_SDIO_INPUTMODE
	UT_MAIN_DelayNx5us(2);
	
	for(i=0;i<8;i++)
	{
		__SPI0_CLR_SCK
		UT_MAIN_DelayNx1us(1);
		__SPI0_SET_SCK
		
		Data<<=1;
		if(__SPI0_SDIO_DATA)
			Data |= 0x01;
		
		UT_MAIN_DelayNx1us(1);
	}
	
	UT_MAIN_DelayNx1us(1);
	
	__SPI0_SET_SEL
	
	return Data;
}









