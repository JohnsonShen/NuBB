 /*
* Copyright (C) 2011-2012 Bitcrazy AB
* Adapted to Cortex-M4 Fly Controller by Nuvoton
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, in version 3.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*/
/*============================================================================*
  ___     ___     ___            _                _                           *
  /   \   | _ )   | _ \    ___   | |__     ___    | |_      o O O             *
  | - |   | _ \   |   /   / _ \  | '_ \   / _ \   |  _|    o                  *
  |_|_|   |___/   |_|_\   \___/  |_.__/   \___/   _\__|   TS__[O]             *
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|             *
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'             *
 *                                                                            *
 * Auto Balance Robot controller firmware for Nuvoton Cortex M4 series        *
 *                                                                            *
 * Written by T.L. Shen for Nuvoton Technology.                               *
 * tlshen@nuvoton.com/tzulan611126@gmail.com                                  *
 *                                                                            *
 *============================================================================*
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef M451
#include "M451Series.h"
#else
#include "Driver\DrvGPIO.h"
#include "Driver\DrvI2C.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvUART.h"
#endif
#define M1_VO_A     PB3		//[L]
#define M1_VO_B     PC3
#define M2_VO_A     PB0		//[R]
#define M2_VO_B     PB1

#include "Hall.h"
#include "Def.h"
#include "motors.h"

extern uint8_t R_rl,L_rl,start;
extern int16_t speed[2];
void HALL_init()
{
	/* Enable battery detect circuit (PA3=1)*/
	SYS->GPB_MFPL = (SYS->GPB_MFPL & (~SYS_GPB_MFPL_PB0MFP_Msk) & (~SYS_GPB_MFPL_PB3MFP_Msk));
	GPIO_SetMode(PB, BIT0, GPIO_MODE_INPUT);
	GPIO_SetMode(PB, BIT1, GPIO_MODE_INPUT);
	GPIO_SetMode(PB, BIT3, GPIO_MODE_INPUT);
	GPIO_SetMode(PC, BIT3, GPIO_MODE_INPUT);
	GPIO_CLR_INT_FLAG(PB, BIT0);
	GPIO_CLR_INT_FLAG(PB, BIT3);
//	GPIO_EnableInt(PB, 0, GPIO_INT_RISING);
//	GPIO_EnableInt(PB, 3, GPIO_INT_RISING);
}

void HALL_getSpeed(int16_t* moveSpeed)
{
//  int32_t i32TimeOutCnt;
//	
//	i32TimeOutCnt = 360000; /* About 5ms */
	GPIO_EnableInt(PB, 0, GPIO_INT_RISING);
	GPIO_EnableInt(PB, 3, GPIO_INT_RISING);
//	while(((R_rl==0)||(L_rl==0)) && (i32TimeOutCnt>0)&&(start==1))
//	{
//			if(i32TimeOutCnt-- <= 0)
//			{
//					speed[0]=R_rl?speed[0]:0;
//					speed[1]=L_rl?speed[1]:0;
//			}
//	}
//	R_rl=0;
//	L_rl=0;
	moveSpeed[R] = speed[0]; 	//[R]
  moveSpeed[L] = speed[1];	//[L]
}
