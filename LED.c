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
#ifdef M451
#include "M451Series.h"
#else
#include "DrvGPIO.h"
#endif
#include "LED.h"
#include "Def.h"
#include "stabilizer.h"
#include "Sensors.h"
#include "Battery.h"
#include "AltHold.h"
#include "ssv7241.h"
#include "RC_ssv.h"
//#ifdef M451
//#if (BOARD_CODE == 200)
//#define IO_STATE_ARM        PB, BIT0	//PA, BIT0
//#define IO_ARM              PB0				//PA0
//#define IO_STATE_HEAD_MODE  PB, BIT8	//PA, BIT1
//#define IO_MAG              PB8
//#elseif (BOARD_CODE ==145)
//#else
//#define IO_STATE_ARM        PA, BIT0
//#define IO_ARM              PA0
//#define IO_STATE_HEAD_MODE  PA, BIT1
//#define IO_MAG              PA1
//#endif
//#define IO_STATE_HFREE_MODE PA, BIT2
//#define IO_HFREE_MODE       PA2
//#else
//#define IO_STATE_ARM        E_GPB, 8
//#endif  
static char ledState = 0;
uint32_t LED1_R, LED1_G, LED1_B, Blink,LED_cnt=0;
void TMR1_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER1) == 1)
    {
        /* Clear Timer1 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER1);
				LED_cnt++;
				if (LED_cnt<(Blink*100))
						PA->DOUT = (LED1_R<<3)|(LED1_R<<6)|(LED1_G<<2)|(LED1_G<<5)|(LED1_B<<1)|(LED1_B<<4);
				else 
						PA->DOUT = 0;
				if (LED_cnt==1000)
						LED_cnt=0;
    }
}

void Laser_init(void)
{
		GPIO_SetMode(PC,BIT10,GPIO_MODE_OUTPUT);
		PC10=0;
}
char GetLedState()
{
	return ledState;
}
void LED_Init(void)
{
		GPIO_SetMode(PA,(BIT1|BIT2|BIT3|BIT4|BIT5|BIT6),GPIO_MODE_OUTPUT);
		PA->DOUT = 0;
		/* Start Time1 counting */
		TIMER_Start(TIMER1);		
//#ifdef M451
//	GPIO_SetMode(IO_STATE_ARM, GPIO_MODE_OUTPUT);
//	GPIO_SetMode(IO_STATE_HEAD_MODE, GPIO_MODE_OUTPUT);
//	GPIO_SetMode(IO_STATE_HFREE_MODE, GPIO_MODE_OUTPUT);
//	IO_ARM = 1;
//	IO_MAG = 1;
//	IO_HFREE_MODE = 1;
//#else
//	DrvGPIO_Open(IO_STATE_ARM, E_IO_OUTPUT);
//	DrvGPIO_SetBit(IO_STATE_ARM);
//#endif	
}

void led_arm_state(char state)
{
//	if(state==LED_STATE_TOGGLE)
//		ledState=ledState^(1<<LED_ARM);	
//	else if(state==LED_STATE_ON)
//		ledState|=(1<<LED_ARM);
//	else if(state==LED_STATE_OFF)
//		ledState&=~(1<<LED_ARM);	
}
void led_mag_state(char state)
{
//	if(state==LED_STATE_TOGGLE)
//		ledState=ledState^(1<<LED_MAG);	
//	else if(state==LED_STATE_ON)
//		ledState|=(1<<LED_MAG);
//	else if(state==LED_STATE_OFF)
//		ledState&=~(1<<LED_MAG);	
}

void UpdateLED()
{
//	if((GetSensorCalState()&(1<<MAG))) {
//		if(getMagMode())
//			ledState|=(1<<LED_MAG);
//		else 
//			ledState&=~(1<<LED_MAG);
//	}
//	
//	if(getHeadFreeMode())
//		ledState|=(1<<LED_HEAD_FREE);
//	else
//		ledState&=~(1<<LED_HEAD_FREE);
//#if STACK_BARO
//	if(GetAltHoldMode())
//		ledState|=(1<<LED_ALTHOLD);
//	else
//#endif
//		ledState&=~(1<<LED_ALTHOLD);
//	
//	if(CheckLowBattery())
//		ledState|=(1<<LED_LOW_BAT);
//	else
//		ledState&=~(1<<LED_LOW_BAT);
//	
//	if(CheckLowRSSI())
//		ledState|=(1<<LED_LOW_RSSI);
//	else
//		ledState&=~(1<<LED_LOW_RSSI);
//	
//	if(RC_GetFlyMode())
//		ledState|=(1<<LED_FLY_MODE);
//	else
//		ledState&=~(1<<LED_FLY_MODE);

//	if((ledState&(1<<LED_ARM))==0)
//#ifdef M451
//		IO_ARM = 1;
//#else
//		DrvGPIO_SetBit(IO_STATE_ARM);
//#endif
//	else
//#ifdef M451
//		IO_ARM = 0;
//#else
//		DrvGPIO_ClrBit(IO_STATE_ARM);
//#endif
//	
//#ifdef M451
//	if((ledState&(1<<LED_MAG))==0)
//		IO_MAG = 1;
//	else
//		IO_MAG = 0;
//#endif
//	
//#ifdef M451
//	if((ledState&(1<<LED_HEAD_FREE))==0)
//		IO_HFREE_MODE = 1;
//	else
//		IO_HFREE_MODE = 0;
//#endif
}
