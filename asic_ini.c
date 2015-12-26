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

#include "asic_ini.h"
#include "Def.h"
#include "Timer_Ctrl.h"
extern uint32_t LED1_R, LED1_G, LED1_B, Blink;
uint32_t ini_Tick,cur_Tick;
uint8_t ini_start=0,asic_ready=1;

void asic_init(void)
{
	SYS->GPD_MFPL = (SYS->GPD_MFPL & (~SYS_GPD_MFPL_PD2MFP_Msk));		//key input
	GPIO_SetMode(PD, BIT2, GPIO_MODE_INPUT);
	GPIO_CLR_INT_FLAG(PD, BIT2);
	GPIO_ENABLE_DEBOUNCE(PD, BIT2);
	GPIO_SET_DEBOUNCE_TIME(GPIO_DBCTL_DBCLKSRC_HCLK,GPIO_DBCTL_DBCLKSEL_32768);
	GPIO_EnableInt(PD, 2, GPIO_INT_FALLING);
	
	SYS->GPD_MFPH = (SYS->GPD_MFPH & (~SYS_GPD_MFPH_PD10MFP_Msk));	//asic power control
	PD10=0;
	GPIO_SetMode(PD, BIT10, GPIO_MODE_OUTPUT);	
}

uint8_t asic_power(uint8_t key)
{
	if (asic_ready==1)
	{
			ini_start=0;
			key=0;
	}
	if ((key==1)&&(ini_start==0))
	{
			ini_Tick=getTickCount();
			cur_Tick=ini_Tick;
			LED1_R=1;
			LED1_G=0;
			LED1_B=0;
			Blink=10;
			PD10=0;
			ini_start=1;
	}
	else if((key==1)&&(ini_start>=1)&&(asic_ready==0))
	{
			if (getTickCount()<ini_Tick)
					ini_Tick=0;
			if (getTickCount()>(cur_Tick+300))
			{
					uint32_t LEDM;
					cur_Tick=getTickCount();
					LEDM=(cur_Tick-ini_Tick)/300;
					if ((LEDM%3)==0)
					{
						LED1_R=1;
						LED1_B=0;	
					}
					else if ((LEDM%3)==1)
					{
						LED1_R=0;
						LED1_G=1;		
					}
					else if ((LEDM%3)==2)
					{
						LED1_G=0;	
						LED1_B=1;
					}
			}
			if (((cur_Tick-ini_Tick)>600000)&&(ini_start==1)&&(asic_ready==0))
			{
					PD10=1;
					TIMER_Delay(TIMER0,500);
					ini_Tick=getTickCount();
					cur_Tick=ini_Tick;
					LED1_R=1;
					LED1_G=0;
					LED1_B=0;
					Blink=10;
					PD10=0;
					ini_start=2;
			}
			else if (((cur_Tick-ini_Tick)>600000)&&(ini_start==2)&&(asic_ready==0))
			{
					PD10=1;
					ini_start=0;
					key=0;
			}
	}
	return key;
}
