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
#ifdef M451
#include "M451Series.h"
#else
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvUART.h"
#include "Driver\DrvUSB.h"
#include "Driver\DrvI2C.h"
#endif
#include "Def.h"
#include "FlashCtrl.h"
#include "NVT_I2C.h"
#include "Timer_Ctrl.h"
#include "I2CDev.h"
#include "retarget.h"
#include "AHRSLib.h"
#include "Sensors.h"
#include "Report.h"
#include "Calibrate.h"
#include "LED.h"
#include "battery.h"
#include "motors.h"
#include "IR.h"
#include "PSDIR.h"
#include "Hall.h"
#include "asic_ini.h"
#ifdef OPTION_RC
#include "RC.h"
#include "RC_ssv.h"
#include "ssv7241.h"
#include "stabilizer.h"
#include "controller.h"
#include "motors.h"
int freq=0;
#endif
#include "MPU6050.h"
#define MAG_INTERVAL 4
#define code_version 0x00010900	//code version: 0.190
extern RF_DATA RxData;
uint32_t COM_LED_R, COM_LED_G, COM_LED_B, COM_Blink,COM2_LED_R, COM2_LED_G, COM2_LED_B, COM2_Blink,COM_LED_EN=0,COM2_LED_EN=0,code_ver,code_update;
extern uint32_t LED1_R, LED1_G, LED1_B;
extern int16_t  motor_enable;
extern int16_t speed[2];
extern uint8_t BatteryPercent,charge,asic_ready,ini_start;
extern uint16_t RxChannel[RC_CHANS];
extern uint16_t* rcValueSSV;
extern uint16_t  camera;
uint8_t au8IR_CODE[4],notify=0,notify_buf[10],keyin=0,spin,spin_cnt,ss=0,sleep=0;

void version_check(void)
{
		int32_t i32TimeOutCnt;
	
		code_ver=read_code_ver(1+7168);
		if (code_ver==0xffffffff)
				write_code_ver(1+7168,code_version);
		code_update=read_code_ver(2+7168);
		if (code_update==0xffffffff)
		{
				write_code_ver(2+7168,0);
		}
		else
		{
				PD10=1; //asic off
				asic_ready=0;
				keyin=1;
				i32TimeOutCnt = __HSI; /* About 5ms */
				while(1)
				{
						if(i32TimeOutCnt-- <= 0)
							break;
				}
		}
		
}
uint32_t WaitDataReady(uint32_t u32DataNum)
{
    int32_t i32TimeOutCnt;

    i32TimeOutCnt = __HSI / 200; /* About 5ms */

    while(u32DataNum > Serial_available())
    {
        if(i32TimeOutCnt-- <= 0)
            return 0;
    }

    return 1;
}
void GPD_IRQHandler(void)
{
    /* To check if PB.2 interrupt occurred */
    if(GPIO_GET_INT_FLAG(PD, BIT14))
    {
        GPIO_DisableInt(PD, 14);
				GPIO_CLR_INT_FLAG(PD, BIT14);				
				notify = 1;
    }
		else if(GPIO_GET_INT_FLAG(PD, BIT2))
    {
				int key_cnt=0;
				uint8_t motor_temp;
				__disable_irq();
				GPIO_CLR_INT_FLAG(PD, BIT2);
				motor_temp=motor_enable;
				if (PD10==1)
						keyin=1;
				while (PD2==0)
				{
						motor_enable=0;
						PB5=0;
 
						TIMER_Delay(TIMER0,100);
						key_cnt++;
						if ((key_cnt/3570)%2==0)
								PA->DOUT = 0x8048|(PA->DOUT&BIT12);	//turn on red led
						else
								PA->DOUT = 0|(PA->DOUT&BIT12);
						if(key_cnt>45000)
								PD10=1;
						if(key_cnt>49000)
						{
								PD10=1;
                Channel_Reset();
								keyin=0;
								asic_ready=0;
                ini_start=0;
                LED1_R=0;
                LED1_G=0;
                LED1_B=0;
								PA->DOUT = 0|(PA->DOUT&BIT12);
								break;						
						}
				}
				if (PD10==0)
				{
						PA->DOUT = 0x8048|(PA->DOUT&BIT12);						
						TIMER_Delay(TIMER0,100000);
						PA->DOUT = 0|(PA->DOUT&BIT12);	
						motor_enable=motor_temp;
						PB5=motor_temp;
    }
				__enable_irq();
    }
		else
    {
        /* Un-expected interrupt. Just clear all PB interrupts */
        PD->INTSRC = PD->INTSRC;
    }
}
void setupSystemClock()
{
#ifdef M451
	SYS_UnlockReg();
	/* Enable HIRC clock */
	CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk | CLK_PWRCTL_LXTEN_Msk);

	/* Waiting for HIRC clock ready */
	CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk | CLK_STATUS_LXTSTB_Msk);

	/* Switch HCLK clock source to HIRC */
	CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

	/* Set core clock as PLL_CLOCK from PLL and SysTick source to HCLK/2*/
	CLK_SetCoreClock(SYSTEM_CLOCK);
	CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);
	SYS_LockReg();
#else
	uint32_t u32PllCr;
	uint16_t i;
	UNLOCKREG();	
	DrvSYS_SetOscCtrl(E_SYS_OSC22M, 1);
	while (DrvSYS_GetChipClockSourceStatus(E_SYS_OSC22M) != 1);
	DrvSYS_SelectPLLSource(E_SYS_INTERNAL_22M);
	u32PllCr = DrvSYS_GetPLLContent(E_SYS_INTERNAL_22M, SYSTEM_CLOCK);	
	/*Delay for 12M or 22M stable*/
	for (i=0;i<10000;i++);		

	DrvSYS_SetPLLContent(u32PllCr);
	SYSCLK->PLLCON.OE     = 0;
	SYSCLK->PLLCON.PD 	  = 0;

	/*Delay for PLL stable*/
	for (i=0;i<10000;i++);
	/* Change HCLK clock source to be PLL. */
	DrvSYS_SelectHCLKSource(2);
	LOCKREG();	// Lock the protected registers
#endif
}
void setupCommandUART()
{
	/* Enable peripheral clock */
	CLK_EnableModuleClock(UART0_MODULE);
	/* Peripheral clock source */
	CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UARTSEL_HIRC, CLK_CLKDIV0_UART(1));
	/* Set PD multi-function pins for UART0 RXD, TXD */
	SYS->GPD_MFPL = SYS_GPD_MFPL_PD0MFP_UART0_RXD | SYS_GPD_MFPL_PD1MFP_UART0_TXD;
	/* Reset UART module */
	SYS_ResetModule(UART0_RST);
	/* Configure UART0 and set UART0 Baudrate */
	UART_Open(UART0, 115200);
	
	GPIO_SetMode(PD, BIT11, GPIO_MODE_OUTPUT);
	PD11=1;
	GPIO_SetMode(PD, BIT14, GPIO_MODE_INPUT);
	GPIO_CLR_INT_FLAG(PD, BIT14);
	GPIO_EnableInt(PD, 14, GPIO_INT_FALLING);
	NVIC_EnableIRQ(GPD_IRQn);
}

S_RTC_TIME_DATA_T sWriteRTC, sReadRTC;
void setupRTC()
{
		CLK_EnableModuleClock(RTC_MODULE);
	
		/* Open RTC and start counting */
    sWriteRTC.u32Year       = 2015;
    sWriteRTC.u32Month      = 12;
    sWriteRTC.u32Day        = 14;
    sWriteRTC.u32DayOfWeek  = RTC_MONDAY;
    sWriteRTC.u32Hour       = 12;
    sWriteRTC.u32Minute     = 30;
    sWriteRTC.u32Second     = 30;
    sWriteRTC.u32TimeScale  = RTC_CLOCK_24;
    RTC_Open(&sWriteRTC);	
		RTC_32KCalibration(3276800);
		/* Enable RTC tick interrupt, one RTC tick is 1 second */
    RTC_SetTickPeriod(RTC_TICK_1_SEC);
		NVIC_EnableIRQ(RTC_IRQn);
}
void setupUART()
{
#ifdef M451
	setupCommandUART();
#else
	STR_UART_T param;
	DrvGPIO_InitFunction(E_FUNC_UART1);
	DrvSYS_SelectIPClockSource(E_SYS_UART_CLKSRC,3);
	param.u32BaudRate        = UART_BAUD_RATE;
	param.u8cDataBits        = DRVUART_DATABITS_8;
	param.u8cStopBits        = DRVUART_STOPBITS_1;
	param.u8cParity          = DRVUART_PARITY_NONE;
	param.u8cRxTriggerLevel  = DRVUART_FIFO_1BYTES;
	param.u8TimeOut        	 = 0;
	DrvUART_Open(UART_PORT1, &param);
#endif
	printf("Version:%d\n", VERSION_CODE);
}

void setup()
{
	setupSystemClock();
	setup_system_tick(SYSTEM_TICK_FREQ);
	GPIO_SetMode(PD,BIT6, GPIO_MODE_OUTPUT);
	PD6=1;
	GPIO_SetMode(PF,BIT3, GPIO_MODE_OUTPUT);
	PF3=0;
	GPIO_SetMode(PE,BIT7, GPIO_MODE_OUTPUT);
	PE7=1;
	setupUART();
//	GetChar();
	setupRTC();
	IR_init();
	Laser_init();
	asic_init();
#ifdef GPS
	setupGPS();
#endif
	I2C_Init();
	FlashInit();
	version_check();	
	UpdateBoardVersion(false);
#ifdef OPTION_RC
	RC_Init();
	if(IsSSVConnected())
		Battery_Init();
	TIMER_Init();
	LED_Init();
  motorsInit();
	PSDIR_init();
#endif
#ifdef ABROBOT
  ABRobotMotorInit();
#endif
	nvtAHRSInit();
  nvtSetAHRSID(1);
  SetAHRSReport(1);
  MPU6050_set_addr(1);
  stabilizerInit();
	SensorsInit();
  nvtSetAHRSID(0);
  SetAHRSReport(0);
  MPU6050_set_addr(0);
	SensorsInit();
  stabilizerInit();
	ChronographSet(ChronMain);
}
void CommandProcess()
{
	if ((notify==1)&&(PD11==0))
	{
		UART_Write(DEBUG_PORT,notify_buf,(notify_buf[1]+2));
		notify=0;
		PD11=1;
		GPIO_EnableInt(PD, 14, GPIO_INT_FALLING);
	}
#ifdef DEGREE
#else
#ifdef WSPEED_DEGREE
#else
	if ((spin==0)&&(spin_cnt==0))
	{
			rcValueSSV[AUX1_CH] 	= 128;
	}
  spin_cnt--;
#endif
#endif
	// Read incoming control messages
	if (Serial_available() >= 2)
	{
		char start=Serial_read();
		if (start == '@') {// Start of new control message
			int command = Serial_read(); // Commands
			if (command == 'h') {//Hook AHRS Stack Device
				// Read ID
				char id[2];
				id[0] = GetChar();
				id[1] = GetChar();
				// Reply with synch message
				printf("@HOOK");
				Serial_write(id, 2);
			}
			else if (command == 'v') {//Check Version
				CheckVersion();
			}
			else if (command == 'c') {// A 'c'calibration command
				SensorCalibration();
			}
			else if (command == 'b') {// 'b'lock erase flash
				FlashControl();
			}
			else if (command == 'p') {// Set 'p'id command
				SetPID();
			}
			else if (command == 'm') {// Set report 'm'ode
				char mode = GetChar();
				if (mode == 'e') {// Report AHRS by 'e'uler angle
					report_mode = REPORT_AHRS_EULER;
				}
				else if (mode == 'q') {// Report // Report AHRS by 'q'quaternion
					report_mode = REPORT_AHRS_QUATERNION;
				}
				else if (mode == 'r') {// Report sensor 'r'aw data
					report_mode = REPORT_SENSORS_RAW;
				}
				else if (mode == 'c') {// Report sensor 'c'alibrated data
					report_mode = REPORT_SENSORS_CALIBRATED;
				}
				else if (mode == 'm') {// Report 'm'otor power distribution
					report_mode = REPORT_MOTOR_POWER;
				}
				else if (mode == 'v') {// Report 'v'elocity
					report_mode = REPORT_VELOCITY;
				}
				else if (mode == 's') {// Report 's'tatus
					report_status();
				}
				else if (mode == 'p') {// Report controller 'p'id
					char type = GetChar();
					if (type == 'p') // 'p'id
						report_mode = REPORT_PID;
					else if (type == 'r') //'r'ate pid
						report_mode = REPORT_RATE_PID;
					else if (type == 'a') //'a'ltitude hold pid
#ifdef ABROBOT
						report_mode = REPORT_HALLSPEED_PID;
#else          
						report_mode = REPORT_ALTHOLD_PID;
#endif
				}
			}
			else if (command == 'f') {// Set report 'f'ormat
				char format = GetChar();
				if (format == 'b') {// Report 'b'inary format
					report_format = REPORT_FORMAT_BINARY;
				}
				else if (format == 't') {// Report 't'ext format
					report_format = REPORT_FORMAT_TEXT;
				}
			}
			else if (command == 's') {// 's'tream output control
				char mode = GetChar();
				if (mode == 's') {// 's'tart stream
					stream_mode = STREAM_START;
				}
				else if (mode == 'p') {// 'p'ause stream
					stream_mode = STREAM_PAUSE;
				}
				else if (mode == 't') {// 't'oggle stream
					if(stream_mode==STREAM_START)
						stream_mode = STREAM_PAUSE;
					else
						stream_mode = STREAM_START;
				}
#ifdef ABROBOT
        else if (mode=='m') {// 'm'otor
					SetMotorCal();
				}
        else if (mode=='r') {// 'r'emote
					SetRemoteControl();
				}
        else if (mode=='a') {// 'a'hrs
					SetReportAHRS();
				}
#endif
			}
		}
		else if(start == 0x1A){ 
				char buf[10],i;
				int length = Serial_read();
				if(WaitDataReady(length)==1)
				{
						for(i=0;i<length;i++)
								buf[i] = Serial_read();
						if((buf[0] == 0x01)&&(buf[1] == 00)){ 
								RxData.BUF[0] = buf[2];
								RxData.BUF[1] = buf[3];
								RxData.BUF[2] = buf[4];
								RxData.BUF[3] = buf[5];
								RxData.BUF[4] = buf[6];
								RxData.num=5;
						}
						else if((buf[0] == 0x02)&&(buf[1] == 00)){
										rcValueSSV[AUX1_CH] = buf[2];
//										spin=buf[3];
//                    if(spin==0)
//                        spin_cnt=80;
						}						
						else if((buf[0] == 0x07)&&(buf[1] == 00)){
										if (buf[2]==1)
												ss=getTickCount();
										else if(buf[2]==0)
										{
												ss=0;
												rcValueSSV[AUX1_CH]=128;
										}
						}
						else if((buf[0] == 0x04)&&(buf[1] == 00)){
								DEBUG_PORT->DAT = ((GetBattery()>>8) & 0xFF);
								DEBUG_PORT->DAT = (GetBattery() & 0xFF);
						}
						else if((buf[0] == 0x05)&&(buf[1] == 00)){								
								if ((buf[2]==1)&&(PB14==1))
								{
										motor_enable=1;
										PB5=1;	//enable motor power
								}
								else if ((buf[2]==0)&&(PB14==1))
								{
                  motor_enable=0;
									PB5=0;
                  Channel_Reset();
								}
						}
						else if((buf[0] == 0x06)&&(buf[1] == 00)){								
								RTC_SetDate((2000+buf[2]), buf[3], buf[4], buf[5]);
                RTC_SetTime(buf[6], buf[7], buf[8], RTC_CLOCK_24, RTC_AM);
						}
//						UART_Write(DEBUG_PORT,buf,length);
				}
				else
				{
						while(Serial_available()!=0)
								buf[0] = Serial_read();
//						UART_Write(DEBUG_PORT,buf,Serial_available());
				}
		}
		else if(start == 0x7A){ 
				char buf[10],i;
				int length = Serial_read();
				if(WaitDataReady(length)==1)
				{
						for(i=0;i<length;i++)
								buf[i] = Serial_read();
						if((buf[0] == 0x01)&&(buf[1] == 00)){ 
								au8IR_CODE[0] = buf[2];
								au8IR_CODE[1] = buf[3];
								au8IR_CODE[2] = buf[4];
								au8IR_CODE[3] = buf[5];
								SendIR(au8IR_CODE);
						}
//						UART_Write(DEBUG_PORT,buf,length);
				}
				else
				{
						while(Serial_available()!=0)
								buf[0] = Serial_read();
//						UART_Write(DEBUG_PORT,buf,Serial_available());
				}
		}
		else if(start == 0x3A){ 
				uint8_t buf[10],i;
				int length = Serial_read();
				if(WaitDataReady(length)==1)
				{
						for(i=0;i<length;i++)
								buf[i] = Serial_read();
						if((buf[0] == 0x01)&&(buf[1] == 00)){ 
								__disable_irq();
								SYS_UnlockReg();
								SYS_ResetChip();
						}
						else if((buf[0] == 0x01)&&(buf[1] == 01)){ 
								buf[0]=0x3A;
								buf[1]=6;
								buf[2]=0x01;
								buf[3]=0x01;
								buf[4]=((code_ver>>24)&0xFF);
								buf[5]=((code_ver>>16)&0xFF);
								buf[6]=((code_ver>>8)&0xFF);
								buf[7]=(code_ver&0xFF);
								UART_Write(DEBUG_PORT,buf,8);
						}
						else if((buf[0] == 0x01)&&(buf[1] == 02)){ 
								asic_ready=1;
						}
						else if((buf[0] == 0x01)&&(buf[1] == 03)){ 
								sleep=buf[2];
						}
//						UART_Write(DEBUG_PORT,buf,length);
				}
				else
				{
						while(Serial_available()!=0)
								buf[0] = Serial_read();
//						UART_Write(DEBUG_PORT,buf,Serial_available());
				}
		}
		else if(start == 0x5A){ 
				char buf[10],i;
				int length = Serial_read();
				if(WaitDataReady(length)==1)
				{
						for(i=0;i<length;i++)
								buf[i] = Serial_read();
						if((buf[0] == 0x01)&&(buf[1] == 00)){ 
								PC10=buf[2];
						}
						else if((buf[0] == 0x01)&&(buf[1] == 01)){
								COM_LED_R=buf[2];
								COM_LED_G=buf[3];
								COM_LED_B=buf[4];
								COM_Blink=buf[5];
								COM_LED_EN=1;
								if ((buf[2]==0)&&(buf[3]==0)&&(buf[4]==0))
										COM_LED_EN=0;
						}
						else if((buf[0] == 0x01)&&(buf[1] == 02)){
								COM2_LED_R=buf[2];
								COM2_LED_G=buf[3];
								COM2_LED_B=buf[4];
								COM2_Blink=buf[5];
								COM2_LED_EN=1;
								if ((buf[2]==0)&&(buf[3]==0)&&(buf[4]==0))
										COM2_LED_EN=0;
						}
//						UART_Write(DEBUG_PORT,buf,length);
				}
				else
				{
						while(Serial_available()!=0)
								buf[0] = Serial_read();
//						UART_Write(DEBUG_PORT,buf,Serial_available());
				}
		}
		else if(start == 0x6A){ 
				uint8_t buf[10],i;
				int length = Serial_read();
				if(WaitDataReady(length)==1)
				{
						for(i=0;i<length;i++)
								buf[i] = Serial_read();
						if((buf[0] == 0x01)&&(buf[1] == 01)){ 
								buf[0]=0x6A;
								buf[1]=4;
								buf[2]=0x01;
								buf[3]=0x01;
								buf[4]=charge;
								buf[5]=BatteryPercent;
								UART_Write(DEBUG_PORT,buf,6);
						}
				}
				else
				{
						while(Serial_available()!=0)
								buf[0] = Serial_read();
//						UART_Write(DEBUG_PORT,buf,Serial_available());
				}
		}
		else { 
			if (report_format == REPORT_FORMAT_TEXT) {
				__NOP();
//			printf("Unknown command.\n");
			}
		} // Skip character
	}
}

// Main Control loop
void loop()
{
	static uint32_t nextTick = 0;
	while(getTickCount()<nextTick);
	nextTick = getTickCount()+TICK_FRAME_PERIOD;
//	RTC_GetDateAndTime(&sReadRTC);
	CommandProcess();
	keyin=asic_power(keyin);
#ifdef GPS
  GPSCommandProcess();
#endif
	SensorsRead(SENSOR_ACC|SENSOR_GYRO|SENSOR_MAG|SENSOR_BARO,1);
#ifdef ABROBOT
 SensorsRead(SENSOR_HALL,1);
#endif
#ifdef OPTION_RC
	if(IsSSVConnected()) {
	ssv_rc_update();
	if(getTickCount()%1000)
		UpdateBattery();
	}
	if(ChronographRead(ChronRC)>= OUTPUT_RC_INTERVAL) {
    if((GetFrameCount()%2)==0) {
      SensorsDynamicCalibrate(SENSOR_GYRO|SENSOR_MAG);
      ChronographSet(ChronRC);
      computeRC();
      armDetect();
    }
	}
#endif
	if(getMagMode()||!(GetSensorCalState()&(1<<MAG)))
		nvtUpdateAHRS(SENSOR_ACC|SENSOR_GYRO|SENSOR_MAG|SENSOR_HALL);
	else
		nvtUpdateAHRS(SENSOR_ACC|SENSOR_GYRO|SENSOR_HALL);

	if((GetFrameCount()%40)==0) {
    if(GetAHRSReport()==0)
      report_sensors();
  }
  else if((GetFrameCount()%40)==1) {
    if(GetAHRSReport()==1)
      report_sensors();
  }
	
	
#ifdef OPTION_RC
	if(GetFrameCount()==MOTORS_ESC_DELAY)
		motorsStart();
  //if((GetFrameCount()%2)==1)
	//	Get_PSDIR();
    stabilizer();
	if((GetFrameCount()%10)==0)
	{
		sleep_mode(sleep);
		UpdateLED();
//		GetFusionSpeed();
	}
#endif
  IncFrameCount(1);
}

/*-----------------------------------------------------------------------------------*/
/*  Fly Controller Main Function                                                     */
/*-----------------------------------------------------------------------------------*/
int32_t main (void)
{
	setup();
//		motor_enable=1;
//	PB5=1;	//enable motor power
	while(true) loop();
}




