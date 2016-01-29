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
uint32_t LED1_R, LED1_G, LED1_B, Blink,brea=0,brea_cnt=0,LED_cnt=0;
extern uint32_t BAT_LED_R, BAT_LED_G, BAT_LED_B, BAT_Blink, BAT_LED_EN;
extern uint32_t COM_LED_R, COM_LED_G, COM_LED_B, COM_Blink,COM_LED_EN;
extern uint8_t ini_start;
void TMR1_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER1) == 1)
    {
        uint32_t LED_duty,RLED,BLED,GLED,LED_brea;
        /* Clear Timer1 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER1);
				LED_cnt++;
				LED_duty=LED_cnt%100;
				if ((brea==1)&&((brea_cnt%2)==0))
						LED_brea=100-(LED_cnt/100);
				else if (brea==1)
						LED_brea=LED_cnt/100;
				else
						LED_brea=0;
				LED_brea=LED_brea*LED_brea/100;
				RLED=((int32_t)(LED1_R-LED_duty-LED_brea)>0)?1:0;
				BLED=((int32_t)(LED1_B-LED_duty-LED_brea)>0)?1:0;
				GLED=((int32_t)(LED1_G-LED_duty-LED_brea)>0)?1:0;				
				if (LED_cnt<(Blink*1000))
						PA->DOUT = (RLED<<3)|(RLED<<6)|(RLED<<15)|(GLED<<2)|(GLED<<5)|(GLED<<14)|(BLED<<1)|(BLED<<4)|(BLED<<13);
				else 
						PA->DOUT = 0;
				if (LED_cnt==10000)
				{
						LED_cnt=0;
						brea_cnt++;
				}
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
		GPIO_SetMode(PA,(BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT13|BIT14|BIT15),GPIO_MODE_OUTPUT);
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
		if ((COM_LED_EN==1)&&(ini_start==0))
		{
				LED1_R=COM_LED_R;
				LED1_G=COM_LED_G;
				LED1_B=COM_LED_B;
				Blink=COM_Blink;
				brea=0;
		}
		else if ((BAT_LED_EN==1)&&(ini_start==0))
		{
				LED1_R=BAT_LED_R;
				LED1_G=BAT_LED_G;
				LED1_B=BAT_LED_B;
				Blink=BAT_Blink;
				brea=1;
		}
		else if ((COM_LED_EN==0)&&(BAT_LED_EN==0)&&(ini_start==0))
		{
				LED1_R=0;
				LED1_G=0;
				LED1_B=0;
				Blink=0;
				brea=0;
		}

}
