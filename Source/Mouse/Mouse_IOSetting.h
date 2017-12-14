
#ifndef __MOUSE_IOSETTING_H__
#define __MOUSE_IOSETTING_H__
#include <SN32F240B.h>
#include "Mouse_Const.h"

//MS Key IO Define  P215 P20 P21 P25 P211
#define MS_KEY_PM_0 			SN_GPIO2
	#define mskMS_KEY_IO_PM_0 			(BIT_1)
	#define mskMS_KEY_IO_PM_1			  (BIT_15)
	#define mskMS_KEY_IO_PM_2 			(BIT_0)
//	#define mskMS_KEY_IO_PM_3 			(BIT_8)
//	#define mskMS_KEY_IO_PM_4 			(BIT_7)
	#define mskMS_KEY_IO_PM_5 			(BIT_5)  
	#define mskMS_KEY_IO_PM_6 			(BIT_11)
//	#define mskMS_KEY_IO_PM_7 			(BIT_9)
//MS Key IO Define  P01 P00
#define MS_KEY_PM_1 			SN_GPIO0
	#define mskMS_KEY_IO_PM_3 			(BIT_0)
	#define mskMS_KEY_IO_PM_4 			(BIT_1)


#define MS_KEY_IO_PM_0_N 			1
#define MS_KEY_IO_PM_1_N 			15
#define MS_KEY_IO_PM_2_N 			0
#define MS_KEY_IO_PM_3_N 			0
#define MS_KEY_IO_PM_4_N 			1
#define MS_KEY_IO_PM_5_N 			5
#define MS_KEY_IO_PM_6_N 			11
//#define MS_KEY_IO_PM_7_N 			11

//WHEEL IO Define P23¡¢P24
#define MS_WHEEL_PM_0 			SN_GPIO2
	#define mskMS_WHEEL_IO_PM_A 		BIT_3
	#define mskMS_WHEEL_IO_PM_B 		BIT_4
	#define MS_WHEEL_IO_PM_A_N 				3
	#define MS_WHEEL_IO_PM_B_N 				4

//WHEEL IO Pullup Enable 	
#define	__MS_WHEEL_IO_A_SETPUR			MS_WHEEL_PM_0->CFG &= ~MS_WHEEL_IO_SETPUR_A_MASK;
#define	__MS_WHEEL_IO_B_SETPUR			MS_WHEEL_PM_0->CFG &= ~MS_WHEEL_IO_SETPUR_B_MASK;

//WHEEL IO Pullup DisEnable 
#define	__MS_WHEEL_IO_A_CLRPUR			MS_WHEEL_PM_0->CFG &= ~MS_WHEEL_IO_SETPUR_A_MASK; MS_WHEEL_PM_0->CFG |= MS_WHEEL_IO_CLRPUR_A_MASK;
#define	__MS_WHEEL_IO_B_CLRPUR			MS_WHEEL_PM_0->CFG &= ~MS_WHEEL_IO_SETPUR_B_MASK; MS_WHEEL_PM_0->CFG |= MS_WHEEL_IO_CLRPUR_B_MASK;

//WHEEL IO Set Input Mode
#define	__MS_WHEEL_IO_A_INPUTM			MS_WHEEL_PM_0->MODE &= ~mskMS_WHEEL_IO_PM_A;
#define	__MS_WHEEL_IO_B_INPUTM			MS_WHEEL_PM_0->MODE &= ~mskMS_WHEEL_IO_PM_B;

//WHEEL IO Set Output Mode
#define	__MS_WHEEL_IO_A_OUTPUTM			MS_WHEEL_PM_0->MODE |= mskMS_WHEEL_IO_PM_A;
#define	__MS_WHEEL_IO_B_OUTPUTM			MS_WHEEL_PM_0->MODE |= mskMS_WHEEL_IO_PM_B;

//WHEEL IO Set Output Low
#define	__MS_WHEEL_IO_A_OUTPUTL			MS_WHEEL_PM_0->DATA &=~ mskMS_WHEEL_IO_PM_A;
#define	__MS_WHEEL_IO_B_OUTPUTL			MS_WHEEL_PM_0->DATA &=~ mskMS_WHEEL_IO_PM_B;

//WHEEL IO Set Output High
#define	__MS_WHEEL_IO_A_OUTPUTH			MS_WHEEL_PM_0->DATA |= mskMS_WHEEL_IO_PM_A;
#define	__MS_WHEEL_IO_B_OUTPUTH			MS_WHEEL_PM_0->DATA |= mskMS_WHEEL_IO_PM_B;


//========================================================//
//** Enable Pull-UP mask 								  //
//========================================================//
#define MS_KEY_IO_SETPUR_0_MASK 		(0x03U<<(MS_KEY_IO_PM_0_N*2))
#define MS_KEY_IO_SETPUR_1_MASK 		(0x03U<<(MS_KEY_IO_PM_1_N*2))
#define MS_KEY_IO_SETPUR_2_MASK 		(0x03U<<(MS_KEY_IO_PM_2_N*2))
#define MS_KEY_IO_SETPUR_3_MASK 		(0x03U<<(MS_KEY_IO_PM_3_N*2))
#define MS_KEY_IO_SETPUR_4_MASK 		(0x03U<<(MS_KEY_IO_PM_4_N*2))
#define MS_KEY_IO_SETPUR_5_MASK 		(0x03U<<(MS_KEY_IO_PM_5_N*2))
#define MS_KEY_IO_SETPUR_6_MASK 		(0x03U<<(MS_KEY_IO_PM_6_N*2))


//========================================================//
//** Disable Schmitt Trigger mask 						  //
//========================================================//
#define MS_KEY_IO_CLRSCH_0_MASK 		(0x03U<<(MS_KEY_IO_PM_0_N*2))
#define MS_KEY_IO_CLRSCH_1_MASK 		(0x03U<<(MS_KEY_IO_PM_1_N*2))
#define MS_KEY_IO_CLRSCH_2_MASK 		(0x03U<<(MS_KEY_IO_PM_2_N*2))
#define MS_KEY_IO_CLRSCH_3_MASK 		(0x03U<<(MS_KEY_IO_PM_3_N*2))
#define MS_KEY_IO_CLRSCH_4_MASK 		(0x03U<<(MS_KEY_IO_PM_4_N*2))
#define MS_KEY_IO_CLRSCH_5_MASK 		(0x03U<<(MS_KEY_IO_PM_5_N*2))
#define MS_KEY_IO_CLRSCH_6_MASK 		(0x03U<<(MS_KEY_IO_PM_6_N*2))


//----------------------------------------------------------------//
//**		Pull up setting 										//
//			00b: pull up 											//
//			01b: Reserved											//
//			10b: Inactive (no pull-down/pull-up resistor enabled).	//
//			11b: Inactive (Schmitt trigger Disabled).				//
//----------------------------------------------------------------//	
#define	__MS_KEY_IO_0_SETPUR	MS_KEY_PM_0->CFG &= ~MS_KEY_IO_SETPUR_0_MASK;
#define	__MS_KEY_IO_1_SETPUR	MS_KEY_PM_0->CFG &= ~MS_KEY_IO_SETPUR_1_MASK;
#define	__MS_KEY_IO_2_SETPUR	MS_KEY_PM_0->CFG &= ~MS_KEY_IO_SETPUR_2_MASK;
#define	__MS_KEY_IO_3_SETPUR	MS_KEY_PM_1->CFG &= ~MS_KEY_IO_SETPUR_3_MASK;
#define	__MS_KEY_IO_4_SETPUR	MS_KEY_PM_1->CFG &= ~MS_KEY_IO_SETPUR_4_MASK;
#define	__MS_KEY_IO_5_SETPUR	MS_KEY_PM_0->CFG &= ~MS_KEY_IO_SETPUR_5_MASK;
#define	__MS_KEY_IO_6_SETPUR	MS_KEY_PM_0->CFG &= ~MS_KEY_IO_SETPUR_6_MASK;


//----------------------------------------------------------------//
//**		Input setting 											//
//			00b: pull up 											//
//			01b: Reserved											//
//			10b: Inactive (no pull-down/pull-up resistor enabled).	//
//			11b: Inactive (Schmitt trigger Disabled).				//
//----------------------------------------------------------------//	
#define	__MS_KEY_IO_0_INPUTM	MS_KEY_PM_0->MODE &= ~mskMS_KEY_IO_PM_0;
#define	__MS_KEY_IO_1_INPUTM	MS_KEY_PM_0->MODE &= ~mskMS_KEY_IO_PM_1;
#define	__MS_KEY_IO_2_INPUTM	MS_KEY_PM_0->MODE &= ~mskMS_KEY_IO_PM_2;
#define	__MS_KEY_IO_3_INPUTM	MS_KEY_PM_1->MODE &= ~mskMS_KEY_IO_PM_3;
#define	__MS_KEY_IO_4_INPUTM	MS_KEY_PM_1->MODE &= ~mskMS_KEY_IO_PM_4;
#define	__MS_KEY_IO_5_INPUTM	MS_KEY_PM_0->MODE &= ~mskMS_KEY_IO_PM_5;
#define	__MS_KEY_IO_6_INPUTM	MS_KEY_PM_0->MODE &= ~mskMS_KEY_IO_PM_6;


//----------------------------------------------------------------//
//**		Disable Schmitt trigger setting 						//
//			00b: pull up 											//
//			01b: Reserved									    	//
//			10b: Inactive (no pull-down/pull-up resistor enabled).	//
//			11b: Inactive (Schmitt trigger Disabled).				//
//----------------------------------------------------------------//	
#define	__MS_KEY_IO_0_CLRSCH	MS_KEY_PM_0->CFG |= MS_KEY_IO_CLRSCH_0_MASK;
#define	__MS_KEY_IO_1_CLRSCH	MS_KEY_PM_0->CFG |= MS_KEY_IO_CLRSCH_1_MASK;
#define	__MS_KEY_IO_2_CLRSCH	MS_KEY_PM_0->CFG |= MS_KEY_IO_CLRSCH_2_MASK;
#define	__MS_KEY_IO_3_CLRSCH	MS_KEY_PM_1->CFG |= MS_KEY_IO_CLRSCH_3_MASK;
#define	__MS_KEY_IO_4_CLRSCH	MS_KEY_PM_1->CFG |= MS_KEY_IO_CLRSCH_4_MASK;
#define	__MS_KEY_IO_5_CLRSCH	MS_KEY_PM_0->CFG |= MS_KEY_IO_CLRSCH_5_MASK;
#define	__MS_KEY_IO_6_CLRSCH	MS_KEY_PM_0->CFG |= MS_KEY_IO_CLRSCH_6_MASK;



//========================================================//
//** Enable Wheel Pull-UP mask 							  //
//========================================================//
#define MS_WHEEL_IO_SETPUR_A_MASK (0x03U<<(MS_WHEEL_IO_PM_A_N*2))
#define MS_WHEEL_IO_SETPUR_B_MASK (0x03U<<(MS_WHEEL_IO_PM_B_N*2))

//========================================================//
//** Disable Wheel Pull-UP mask 						  //
//========================================================//
#define MS_WHEEL_IO_CLRPUR_A_MASK (0x02U<<(MS_WHEEL_IO_PM_A_N*2))
#define MS_WHEEL_IO_CLRPUR_B_MASK (0x02U<<(MS_WHEEL_IO_PM_B_N*2))



#endif //__MOUSE_IOSETTING_H__


