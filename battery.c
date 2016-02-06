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
#define BAT_FULL 	12.5f
#define BAT_LOW		10.8f
#define BAT_TH		15
#ifdef M451
#include "M451Series.h"
#else
#include "DrvGPIO.h"
#endif
#include "battery.h"
#include "Def.h"
#include "Report.h"
#include "Timer_Ctrl.h"

#ifdef M451
#define IO_STATE_BAT	PB, BIT2
#define IO_BAT        PB2
#define USB_CS				PB13
#define Dis_charge_pin		PB14
#define USB_boost					PA12
#else
#endif  

/*---------------------------------------------------------------------------------------------------------*/
/* Define global variables and constants                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
volatile uint32_t g_u32AdcIntFlag;
static uint16_t  AdcData = 0,BAT_TEMP2,BAT_PR,TEMP1,ADP_IN,USB_IN,BAT_PR_M,ID_ADC,USB_CC1_ADC, Band,Band_cnt=0,bat_cnt=0,Dis_charge=1;
uint8_t BatteryPercent=2,charge,full=0,low_bat=0,Vref_err;
uint32_t g_u32RTCTickINT=0,R_value,L_value;
uint8_t R_cnt=1,L_cnt=1,R_rl=3,L_rl=3,start=0;
int16_t speed[2]={0,0};
uint32_t BAT_LED_R, BAT_LED_G, BAT_LED_B, BAT_Blink, BAT_Brea, BAT_LED_EN=0;
extern int16_t  motor_enable;
/*---------------------------------------------------------------------------------------------------------*/
/* EADC interrupt handler                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void ADC00_IRQHandler(void)
{
	g_u32AdcIntFlag++;
	PE7=1;
	EADC_CLR_INT_FLAG(EADC, 0x1);      /* Clear the A/D ADINT0 interrupt flag */
}
void RTC_IRQHandler(void)
{
    /* To check if RTC tick interrupt occurred */
    if(RTC_GET_TICK_INT_FLAG() == 1)
    {
        /* Clear RTC tick interrupt flag */
        RTC_CLEAR_TICK_INT_FLAG();        
				if (USB_CS == 1)
						g_u32RTCTickINT++;
				else
						g_u32RTCTickINT = g_u32RTCTickINT+4;
				if (g_u32RTCTickINT>43200)
				{
							BAT_LED_R=0;
							BAT_LED_G=0;
							BAT_LED_B=0;
							BAT_Blink=0;
							BAT_Brea=0;
							low_bat=0;
							BAT_LED_EN=0;
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
						Dis_charge=1;
							charge=1;
							PD11=0;
				}
    }
}
void GPB_IRQHandler(void)
{
    /* To check if PB.2 interrupt occurred */
    if(GPIO_GET_INT_FLAG(PB, BIT15))
    {
//				if (BatteryPercent==0)
//						full=1;
				Dis_charge = 1;
				BAT_LED_R=0;
				BAT_LED_G=100;
				BAT_LED_B=0;
				BAT_Blink=10;
				BAT_Brea=0;
				low_bat=0;
				BAT_LED_EN=1;
				charge=1;
				PD11=0;
				report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
        GPIO_CLR_INT_FLAG(PB, BIT15);
    }
		else if(GPIO_GET_INT_FLAG(PB, BIT14))
    {
        GPIO_CLR_INT_FLAG(PB, BIT14);
				if (Dis_charge_pin==0)
				{
						/* Enable RTC NVIC */
						RTC_CLEAR_TICK_INT_FLAG();
						RTC_EnableInt(RTC_INTEN_TICKIEN_Msk);
				}	
				else if (Dis_charge_pin==1)
				{
						RTC_DisableInt(RTC_INTEN_TICKIEN_Msk);
						g_u32RTCTickINT=0;
				}
    }
		else if(GPIO_GET_INT_FLAG(PB, BIT0))
		{
				if (TIMER3->CNT>0xC00000)
				{
						TIMER3->CTL |= TIMER_CTL_RSTCNT_Msk;
						TIMER3->CTL |= TIMER_CTL_CNTEN_Msk;
				}		
				if (L_cnt==1)
				{
						L_value=TIMER3->CNT;						
				}
				else if(L_cnt==2)
				{
						speed[0]=(277778/(TIMER3->CNT-L_value));
            if (PB1==0)
                speed[0]=-speed[0];
						L_cnt=0;
						GPIO_DisableInt(PB, 0);
				}					
				L_cnt++;
				GPIO_CLR_INT_FLAG(PB, BIT0);
		}
		else if(GPIO_GET_INT_FLAG(PB, BIT3))
		{
				if (TIMER3->CNT>0xC00000)
				{
						TIMER3->CTL |= TIMER_CTL_RSTCNT_Msk;
						TIMER3->CTL |= TIMER_CTL_CNTEN_Msk;
				}		
				if (R_cnt==1)
				{
						R_value=TIMER3->CNT;						
				}
				else if(R_cnt==2)
				{
						speed[1]=(277778/(TIMER3->CNT-R_value));
            if (PC3==1)
                speed[1]=-speed[1];
						R_cnt=0;
						GPIO_DisableInt(PB, 3);
				}					
				R_cnt++;
				GPIO_CLR_INT_FLAG(PB, BIT3);
		}
    else
    {
        /* Un-expected interrupt. Just clear all PB interrupts */
        PB->INTSRC = PB->INTSRC;
    }
}
void Battery_Init(void)
{
#ifdef M451
	SYS_UnlockReg();
	/* Enable EADC module clock */
	CLK_EnableModuleClock(EADC_MODULE);	
	/* EADC clock source is 72MHz, set divider to 8, ADC clock is 72/8 MHz */
	CLK_SetModuleClock(EADC_MODULE, 0, CLK_CLKDIV0_EADC(8));
	SYS->VREFCTL = 0;
	
	SYS_LockReg();	
	/* Configure the GPB0 - GPB3 ADC analog input pins.  */
	SYS->GPB_MFPL = (SYS->GPB_MFPL & (~SYS_GPB_MFPL_PB4MFP_Msk) & (~SYS_GPB_MFPL_PB6MFP_Msk) & (~SYS_GPB_MFPL_PB7MFP_Msk));
	SYS->GPB_MFPL |= (SYS_GPB_MFPL_PB4MFP_EADC_CH4 | SYS_GPB_MFPL_PB6MFP_EADC_CH14 | SYS_GPB_MFPL_PB7MFP_EADC_CH15);
	
	SYS->GPB_MFPH = (SYS->GPB_MFPH & (~SYS_GPB_MFPH_PB8MFP_Msk) & (~SYS_GPB_MFPH_PB9MFP_Msk) & (~SYS_GPB_MFPH_PB10MFP_Msk)  
	& (~SYS_GPB_MFPH_PB11MFP_Msk) & (~SYS_GPB_MFPH_PB12MFP_Msk));
	SYS->GPB_MFPH |= (SYS_GPB_MFPH_PB8MFP_EADC_CH5 | SYS_GPB_MFPH_PB9MFP_EADC_CH6  | SYS_GPB_MFPH_PB10MFP_EADC_CH7
	| SYS_GPB_MFPH_PB11MFP_EADC_CH8 | SYS_GPB_MFPH_PB12MFP_EADC_CH9);
	
	GPIO_DISABLE_DIGITAL_PATH(PB, (BIT4|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12));
	
	/* Set the ADC internal sampling time, input mode as single-end and enable the A/D converter */
	EADC_Open(EADC, EADC_CTL_DIFFEN_SINGLE_END);
	EADC_SetInternalSampleTime(EADC, 6);

	/* Configure the sample module 0 for analog input channel 2 and software trigger source.*/
	EADC_ConfigSampleModule(EADC, 0, EADC_SOFTWARE_TRIGGER, 5);
	EADC_ConfigSampleModule(EADC, 1, EADC_SOFTWARE_TRIGGER, 6);
	EADC_ConfigSampleModule(EADC, 2, EADC_SOFTWARE_TRIGGER, 7);
	EADC_ConfigSampleModule(EADC, 3, EADC_SOFTWARE_TRIGGER, 8);
	EADC_ConfigSampleModule(EADC, 4, EADC_SOFTWARE_TRIGGER, 9);
	EADC_ConfigSampleModule(EADC, 5, EADC_SOFTWARE_TRIGGER, 4);
	EADC_ConfigSampleModule(EADC, 6, EADC_SOFTWARE_TRIGGER, 14);
	EADC_ConfigSampleModule(EADC, 7, EADC_SOFTWARE_TRIGGER, 15);
	EADC_ConfigSampleModule(EADC, 8, EADC_SOFTWARE_TRIGGER, 16);
	
	/* Clear the A/D ADINT0 interrupt flag for safe */
	EADC_CLR_INT_FLAG(EADC, 0x1);

	/* Enable the sample module 0 interrupt.  */
	EADC_ENABLE_INT(EADC, 0x1);//Enable sample module A/D ADINT0 interrupt.
	EADC_ENABLE_SAMPLE_MODULE_INT(EADC, 0, (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8));//Enable sample module 0 interrupt.
	NVIC_EnableIRQ(ADC00_IRQn);
	
	/* Reset the ADC interrupt indicator and trigger sample module 0 to start A/D conversion */
	g_u32AdcIntFlag = 0;
	
	/* Enable battery detect circuit (PA3=1)*/
	SYS->GPB_MFPH = (SYS->GPB_MFPH & (~SYS_GPB_MFPH_PB13MFP_Msk) & (~SYS_GPB_MFPH_PB14MFP_Msk) & (~SYS_GPB_MFPH_PB15MFP_Msk));
	SYS->GPA_MFPH = (SYS->GPA_MFPH & (~SYS_GPA_MFPH_PA12MFP_Msk));
	PA12=0;		//USB boost enable 
	PB13=1;
	PB14=0;
	GPIO_SetMode(PA, BIT12, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT13, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT14, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT15, GPIO_MODE_INPUT);
	GPIO_CLR_INT_FLAG(PB, BIT15);
	GPIO_CLR_INT_FLAG(PB, BIT14);
	GPIO_EnableInt(PB, 15, GPIO_INT_RISING);
	GPIO_EnableInt(PB, 14, GPIO_INT_BOTH_EDGE);
	NVIC_EnableIRQ(GPB_IRQn);
#else
	/* TBD.. */
#endif	
}
bool CheckLowBattery()
{
	if(GetBattery()<BAT_TH)
		return true;
	else
		return false;
}
void led_level(void)
{
		if (((Dis_charge_pin == 1)&&(Dis_charge == 1))&&(PD10==0))
		{
				if (BatteryPercent>=4)
				{
							BAT_LED_R=100;
							BAT_LED_G=0;
							BAT_LED_B=0;
							BAT_Blink=2;
							BAT_Brea=0;
							BAT_LED_EN=1;
							low_bat=1;
				}
				else if (BatteryPercent==3)
				{
							BAT_LED_R=100;
							BAT_LED_G=0;
							BAT_LED_B=0;
							BAT_Blink=10;
							BAT_Brea=0;
							BAT_LED_EN=1;
							low_bat=0;
				}
				else if ((BatteryPercent<3)&&(BatteryPercent>=1))
				{
							BAT_LED_R=100;
							BAT_LED_G=100;
							BAT_LED_B=0;
							BAT_Blink=10;
							BAT_Brea=0;
							BAT_LED_EN=1;
							low_bat=0;
				}	
				else
				{
							BAT_LED_R=0;
							BAT_LED_G=100;
							BAT_LED_B=0;
							BAT_Blink=10;
							BAT_Brea=0;
							BAT_LED_EN=1;
							low_bat=0;
				}
		}
		else if (((Dis_charge_pin == 1)&&(Dis_charge == 1))&&(PD10==1))
		{
							BAT_LED_R=0;
							BAT_LED_G=0;
							BAT_LED_B=0;
							BAT_Blink=0;
							BAT_Brea=0;
							BAT_LED_EN=0;
							low_bat=0;
		}
}
void UpdateBattery()
{
	if(Dis_charge_pin != Dis_charge)
			bat_cnt++;
	else if ((Dis_charge_pin == Dis_charge)&& (bat_cnt>1000))
			bat_cnt++;
	if (bat_cnt==1000)
	{
//			GPIO_CLR_INT_FLAG(PB, BIT15);
//			NVIC_ClearPendingIRQ(GPB_IRQn);
			GPIO_DisableInt(PB, 15);
			Dis_charge_pin = Dis_charge;
			if (Dis_charge_pin==0)
			{
					motor_enable=0;
					PB5=0;
			}
			bat_cnt++;	
	}
	else if(bat_cnt==2500)
	{
			if (PB15==1)
					Dis_charge=1;
			GPIO_EnableInt(PB, 15, GPIO_INT_RISING);
			bat_cnt=0;
	}
	if(g_u32AdcIntFlag!=0)
	{
			if(g_u32AdcIntFlag==1)
			{
					BAT_TEMP2 = EADC_GET_CONV_DATA(EADC, 0);
					g_u32AdcIntFlag++;
					PE7=0;
					EADC_START_CONV(EADC, BIT1);
			}
			else if(g_u32AdcIntFlag==3)
			{
					BAT_PR = EADC_GET_CONV_DATA(EADC, 1);
					if(AdcData==0)
						AdcData=BAT_PR;
					else if ((AdcData - BAT_PR) < 0x200)
						AdcData=(AdcData+BAT_PR)/2;
//					printf("ADC: %d\n",AdcData);
					if ((AdcData>=1921)&& ((BatteryPercent!=1)||(Dis_charge_pin==0)))//&& (BatteryPercent!=0))
					{
							BatteryPercent=0;//100 percent
//							full=1;
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
//							led_level();
							PD11=0;
//							printf("Level:100\n");
					}
					else if ((AdcData<1950)&& (AdcData>=1921))
					{
							full=0;
					}
					else if ((AdcData<1911)&&(AdcData>=1849)&& ((BatteryPercent<1)||(Dis_charge_pin==0))&& (BatteryPercent!=1))
					{					
							BatteryPercent=1;//75 percent
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
//							led_level();
							PD11=0;
//						printf("Level:75\n");
					}	
					else if ((AdcData<1839)&&(AdcData>=1778)&& ((BatteryPercent<2)||(Dis_charge_pin==0))&& (BatteryPercent!=2))
					{
							BatteryPercent=2;//50 percent
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
//							led_level();
							PD11=0;
//						printf("Level:50\n");
					}
					else if ((AdcData<1768)&&(AdcData>=1706)&& ((BatteryPercent<3)||(Dis_charge_pin==0))&& (BatteryPercent!=3))
					{	
							BatteryPercent=3;//25 percent
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
//							led_level();
							PD11=0;
//						printf("Level:25\n");
					}	
					else if ((AdcData<1696)&&(AdcData>=1634)&& ((BatteryPercent<4)||(Dis_charge_pin==0))&& (BatteryPercent!=4))
					{
							BatteryPercent=4;//10 percent
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
//							led_level();
							PD11=0;
//						printf("Level:0\n");
					}
					else if ((AdcData<1624)&& ((BatteryPercent<5)||(Dis_charge_pin==0))&& (BatteryPercent!=5))
					{
							BatteryPercent=5;//off
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
//							led_level();
							PD11=0;
//						printf("Level:off\n");
					}
					led_level();
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT2);
			}
			else if(g_u32AdcIntFlag==5)
			{
					TEMP1 = EADC_GET_CONV_DATA(EADC, 2);
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT3);
			}
			else if(g_u32AdcIntFlag==7)
			{
					ADP_IN = EADC_GET_CONV_DATA(EADC, 3);
					if ((ADP_IN>0x5B7) && (ADP_IN<0x7BC) && (Dis_charge ==1)&&(full==0) )//&& (USB_CC1_ADC>0x45B) && (USB_CC1_ADC<0x688))
					{
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
							USB_CS = 0;
							USB_boost=0;
							Dis_charge = 0;
							BAT_LED_R=100;
							BAT_LED_G=0;
							BAT_LED_B=0;
							BAT_Blink=10;
							BAT_Brea=1;
							low_bat=0;
							BAT_LED_EN=1;
							charge=2;
							PD11=0;
					}
					else if ((USB_IN>0x649) && (ADP_IN>0x5B7) && (Dis_charge_pin ==0)&&(USB_CS==1))
					{
							USB_CS = 0;
							USB_boost=1;
					}
					else if ((USB_IN>0x649) && (ADP_IN<0x5B7) && (Dis_charge_pin ==0)&&(USB_CS==0))
					{
							USB_CS = 1;
							USB_boost=1;
					}
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT4);
			}
			else if(g_u32AdcIntFlag==9)
			{	
					USB_IN = EADC_GET_CONV_DATA(EADC, 4);
					if ((((USB_IN>0x649) && (USB_IN<0x880) && (ADP_IN<0x5B7))||(Vref_err==1)) && (Dis_charge ==1)&&(full==0))
					{
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
							USB_CS = 1;
							USB_boost=1;
							Dis_charge = 0;
							BAT_LED_R=100;
							BAT_LED_G=0;
							BAT_LED_B=0;
							BAT_Blink=10;
							BAT_Brea=1;
							low_bat=0;
							BAT_LED_EN=1;
							charge=2;
							PD11=0;
					}
					else if ((USB_IN<0x649) && (ADP_IN<0x5B7) && (Dis_charge_pin ==0))
					{
							report_ASIC(0x6A,0x04,0x01,0x01,charge,BatteryPercent,0,0,0,0);
							Dis_charge = 1;
							USB_CS = 1;
							USB_boost=0;
							led_level();
							charge=0;
							PD11=0;
					}
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT5);
			}
			else if(g_u32AdcIntFlag==11)
			{
					BAT_PR_M = EADC_GET_CONV_DATA(EADC, 5);
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT6);
			}
			else if(g_u32AdcIntFlag==13)
			{
					ID_ADC = EADC_GET_CONV_DATA(EADC, 6);
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT7);
			}
			else if(g_u32AdcIntFlag==15)
			{
					USB_CC1_ADC = EADC_GET_CONV_DATA(EADC, 7);					
					g_u32AdcIntFlag++;
					EADC_START_CONV(EADC, BIT8);
			}
			else if(g_u32AdcIntFlag==17)
			{
					Band = EADC_GET_CONV_DATA(EADC, 8);
//					if ((Band<0xC62)||(Band<0xC62))
//							Band_cnt++;
//					else
//							Band_cnt=0;
//					if(Band_cnt>100)
//					{
//							Vref_err=1;
//							BAT_LED_R=100;
//							BAT_LED_G=100;
//							BAT_LED_B=100;
//							BAT_Blink=10;
//							BAT_Brea=1;
//							low_bat=0;
//							BAT_LED_EN=1;
//					}
					g_u32AdcIntFlag=0;
			}
	}
	else
	{
			if (getTickCount()>1000)
			EADC_START_CONV(EADC, BIT0);
	}
}
uint16_t GetBattery()
{
	uint16_t CurrentBattery;
	CurrentBattery = AdcData;
//	CurrentBattery = ((AdcData-2700)*100/(3240-2700));
//	BatteryPercent = BatteryPercent*0.95f + CurrentBattery*0.05f;
//	//BatteryPercent = CurrentBattery;
//	if(BatteryPercent<0)
//		BatteryPercent = 0;
//	else if(BatteryPercent>100)
//		BatteryPercent = 100;
		
	return CurrentBattery;
}
