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

#include "PSDIR.h"

#define FPSD 0x40
#define BPSD 0x38

uint8_t I2C0_ReadFlag;
uint8_t I2C0_Tx_Data0[10];
uint8_t I2C0_Rx_Data0[10];
uint8_t I2C0_DataLen0;
uint8_t I2C0_RxLen0;
uint8_t I2C0_ContinueLen;
uint8_t I2C0_I2ccnt=0;
volatile uint8_t I2C0_EndFlag0 = 0;
volatile uint8_t I2C0_ErrorFlag = 0;
uint8_t  I2C0_Addr1[3] = {0};
uint8_t  I2C0_DataLen1;
uint8_t  I2C0_Slave_Buff1[32] = {0};
uint16_t I2C0_Slave_Buff_Addr1;
uint8_t PSD_Addr;
uint32_t IR=64,IR_12,IR_f=0xFFF,cnt,cnf=0,FB=0;
typedef void (*I2C0_FUNC)(uint32_t u32Status,uint8_t PSD_Addr);
static volatile I2C0_FUNC s_I2C0HandlerFn = NULL;

void PSDIR_init(void)
{
	  uint8_t i,data[2],PSD[2]={FPSD,BPSD};
		/* Enable I2C0 module clock */
    CLK_EnableModuleClock(I2C0_MODULE);
	
    /* Open I2C module and set bus clock */
    I2C_Open(I2C0, 100000);

    /* Enable I2C interrupt */
    I2C_EnableInt(I2C0);
    NVIC_EnableIRQ(I2C0_IRQn);
	
		/* Set I2C PA multi-function pins */
    SYS->GPD_MFPL &= ~(SYS_GPD_MFPL_PD4MFP_Msk | SYS_GPD_MFPL_PD5MFP_Msk);
    SYS->GPD_MFPL |= (SYS_GPD_MFPL_PD4MFP_I2C0_SDA | SYS_GPD_MFPL_PD5MFP_I2C0_SCL);

		data[0]=0x06;
		I2C0_writeBytes(PSD[0], 0xEE, 1, data);
		data[0]=0x06;
		I2C0_writeBytes(PSD[1], 0xEE, 1, data);
		TIMER_Delay(TIMER0, 10000);

		for(i=0;i<2;i++)
		{
				data[0]=0xFF;
				I2C0_writeBytes(PSD[i], 0x2F, 1, data);
				data[0]=0x1F;
				I2C0_writeBytes(PSD[i], 0x1C, 1, data);
				data[0]=0x34;
				data[1]=0x37;
				I2C0_writeBytes(PSD[i], 0x33, 2, data);
		}		
}

void I2C0_WaitEndFlag0(uint16_t timeout)
{
	if(timeout)
		I2C_EnableTimeout(I2C0, (uint8_t) timeout);
	
	while (I2C0_EndFlag0 == 0) {
		if(I2C0_ErrorFlag) {
			break;
		}
	};
	I2C_DisableTimeout(I2C0);
}

int8_t I2C0_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data, uint16_t timeout) 
{
	uint8_t i;
	uint32_t cnt=0;
	
	PSD_Addr=devAddr;
	I2C0_RxLen0 = 0;
	I2C0_DataLen0 = 0;
	I2C0_EndFlag0 = 0;
	I2C0_ReadFlag = 0;
	I2C0_ErrorFlag = 0;
	I2C0_ContinueLen = length;
	I2C0_Tx_Data0[0] = regAddr;
#ifdef M451
	s_I2C0HandlerFn = (I2C0_FUNC)I2C0_Callback_Rx_Continue;
	while(I2C0->CTL & I2C_CTL_STO_Msk)
	{
			cnt++;
			if (cnt>65535)
			{
#if 1
            I2C0_ErrorFlag=1;
						return I2C0_ErrorFlag;
#else
						__disable_irq();
						SYS_UnlockReg();
						SYS_ResetChip();
#endif
			}
	}
	cnt=0;
	I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);

	I2C0_WaitEndFlag0(timeout);
#else		
	DrvI2C_InstallCallback(I2C0, I2CFUNC, I2C0_Callback_Rx_Continue);
	DrvI2C_Ctrl(I2C_PORT, 1, 0, 0, 0);

	I2C0_WaitEndFlag0(timeout);
#endif
	for(i = 0; i<length; i++)
		data[i]=I2C0_Rx_Data0[i];
	
	return I2C0_ErrorFlag;
}

bool I2C0_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data) 
{
	uint8_t i;
	uint32_t cnt=0;
	
	PSD_Addr=devAddr;
	I2C0_Tx_Data0[0]=regAddr;
	
	for(i=0;i<length;i++)
		I2C0_Tx_Data0[1+i]=data[i];
	
	I2C0_DataLen0 = 0;
	I2C0_EndFlag0 = 0;
	I2C0_ErrorFlag = 0;
	I2C0_ContinueLen=length+1;
	s_I2C0HandlerFn = (I2C0_FUNC)I2C0_Callback_Tx_Continue;
	while(I2C0->CTL & I2C_CTL_STO_Msk)
	{
			cnt++;
			if (cnt>65535)
			{
#if 1
						I2C0_ErrorFlag=1;
						return I2C0_ErrorFlag;
#else
						__disable_irq();
						SYS_UnlockReg();
						SYS_ResetChip();
#endif
			}
	}
	cnt=0;
	I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);
	I2C0_WaitEndFlag0(1);	
	return I2C0_ErrorFlag;
}

void I2C0_IRQHandler(void)
{
	uint32_t u32Status;

	u32Status = I2C_GET_STATUS(I2C0);
	
	if(I2C_GET_TIMEOUT_FLAG(I2C0)) {
	I2C0_ErrorFlag = 1;
	I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
	/* Clear I2C0 Timeout Flag */
	I2C_ClearTimeoutFlag(I2C0);
	}
	else {
		switch (u32Status) {	
			case 0x38:{/* Arbitration loss */
				I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI); 
				I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);
				//printf("I2C Arbitration loss\n");
				break;
			}
			case 0x00:	/* Bus error */
			case 0x30:
			case 0xF8:
			case 0x48: {
				I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
				//I2C_SET_CONTROL_REG(I2C_PORT, I2C_CTL_SI);
				I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);
				//printf("I2C bus error\n");
				break;
			}
			default: {
				if(s_I2C0HandlerFn != NULL)
					s_I2C0HandlerFn(u32Status,PSD_Addr);
			}
}
	}
}

void I2C0_Callback_Tx_Continue(uint32_t status,uint8_t Addr)
{
    if (status == 0x08)                     /* START has been transmitted */
    {
#ifdef M451
      I2C_SET_DATA(I2C0, Addr << 1);    /* Write SLA+W to Register I2CDAT */
      I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
      DrvI2C_WriteData(I2C0, Device_W_Addr<<1);
      DrvI2C_Ctrl(I2C_PORT, 0, 0, 1, 0);
#endif
    }   
    else if (status == 0x18)                /* SLA+W has been transmitted and ACK has been received */
    {
#ifdef M451
      I2C_SET_DATA(I2C0, I2C0_Tx_Data0[I2C0_DataLen0++]);
      I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
      DrvI2C_WriteData(I2C0, Tx_Data0[DataLen0++]);
      DrvI2C_Ctrl(I2C_PORT, 0, 0, 1, 0);
#endif
    }
    else if (status == 0x20)                /* SLA+W has been transmitted and NACK has been received */
    {
#ifdef M451
			I2C0_I2ccnt++;
			if(I2C0_I2ccnt==10)
			{
					I2C0_ErrorFlag = 1;
					I2C0_EndFlag0 = 1;
					I2C0_I2ccnt=0;
					I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
			}
			else
				I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_STO_SI);
#else    
      DrvI2C_Ctrl(I2C0, 1, 1, 1, 0);
#endif
    }   
    else if (status == 0x28)                /* DATA has been transmitted and ACK has been received */
    {
        if (I2C0_DataLen0 != I2C0_ContinueLen)
        {
#ifdef M451
          I2C_SET_DATA(I2C0, I2C0_Tx_Data0[I2C0_DataLen0++]);
          I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
          DrvI2C_WriteData(I2C0, I2C0_Tx_Data0[I2C0_DataLen0++]);
          DrvI2C_Ctrl(I2C0, 0, 0, 1, 0);
#endif
        }
        else
        {
#ifdef M451
          I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
#else
          DrvI2C_Ctrl(I2C_PORT, 0, 1, 1, 0);        
#endif
          I2C0_EndFlag0 = 1;
        }       
    }
    else
    {
					I2C0_I2ccnt++;
					if(I2C0_I2ccnt==10)
					{
							I2C0_ErrorFlag = 1;
							I2C0_EndFlag0 = 1;
							I2C0_I2ccnt=0;
							I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
					}
					else
						I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_STO_SI);
//        DEBUG_PRINT("Status 0x%x is NOT processed\n", status);
    }       
}

void I2C0_Callback_Rx_Continue(uint32_t status, uint8_t Addr)
{
    if (status == 0x08)                     /* START has been transmitted and prepare SLA+W */
    {
#ifdef M451
        I2C_SET_DATA(I2C0, Addr << 1|I2C0_ReadFlag);    /* Write SLA+W to Register I2CDAT */
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
        DrvI2C_WriteData(I2C0, Addr<<1|ReadFlag);
        DrvI2C_Ctrl(I2C0, 0, 0, 1, 0);
#endif
    }   
    else if (status == 0x18)                /* SLA+W has been transmitted and ACK has been received */
    {
#ifdef M451
      I2C_SET_DATA(I2C0, I2C0_Tx_Data0[I2C0_DataLen0++]);
      I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
      DrvI2C_WriteData(I2C0, I2C0_Tx_Data0[I2C0_DataLen0++]);
      DrvI2C_Ctrl(I2C_PORT, 0, 0, 1, 0);
#endif
    }
    else if (status == 0x20)                /* SLA+W has been transmitted and NACK has been received */
    {
#ifdef M451
			I2C0_I2ccnt++;
			if(I2C0_I2ccnt==10)
			{
					I2C0_ErrorFlag = 1;
					I2C0_EndFlag0 = 1;
					I2C0_I2ccnt = 0;
					I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
			}
			else
				I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_STO_SI);
#else
      DrvI2C_Ctrl(I2C0, 0, 1, 1, 0);
#endif
    }
    else if (status == 0x28)                /* DATA has been transmitted and ACK has been received */
    {
#ifdef M451
      I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_SI);
#else
      DrvI2C_Ctrl(I2C0, 1, 0, 1, 0);
#endif
    }
    else if (status == 0x10)                /* Repeat START has been transmitted and prepare SLA+R */
    {
#ifdef M451
      I2C_SET_DATA(I2C0, ((Addr << 1) | 0x01));   /* Write SLA+R to Register I2CDAT */
      I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
      DrvI2C_WriteData(I2C0, Addr<<1 | 0x01);
      DrvI2C_Ctrl(I2C_PORT, 0, 0, 1, 0);
#endif
    }
    else if (status == 0x40)                /* SLA+R has been transmitted and ACK has been received */
    {
#ifdef M451
      if(I2C0_ContinueLen>1)
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI_AA);
      else 
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
#else
      if(I2C0_ContinueLen>1)
        DrvI2C_Ctrl(I2C0, 0, 0, 1, 1);
      else 
        DrvI2C_Ctrl(I2C0, 0, 0, 1, 0);
#endif
    }       
    else if (status == 0x58)                /* DATA has been received and NACK has been returned */
    {
#ifdef M451
      I2C0_Rx_Data0[I2C0_RxLen0++] = (unsigned char) I2C_GET_DATA(I2C0);  
      I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
      I2C0_EndFlag0 = 1;
#else
      I2C0_Rx_Data0[I2C0_RxLen0++] = DrvI2C_ReadData(I2C0);
      DrvI2C_Ctrl(I2C0, 0, 1, 1, 0);
      I2C0_EndFlag0 = 1;
#endif
    }
    else if (status == 0x50)                /* DATA has been received and ACK has been returned */
    {
#ifdef M451
      I2C0_Rx_Data0[I2C0_RxLen0++] = (unsigned char) I2C_GET_DATA(I2C0);  
      if(I2C0_RxLen0<(I2C0_ContinueLen-1))
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI_AA);
      else {
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
      }
#else
      I2C0_Rx_Data0[I2C0_RxLen0++] = DrvI2C_ReadData(I2C0);
      if(I2C0_RxLen0<(I2C0_ContinueLen-1))
        DrvI2C_Ctrl(I2C0, 0, 0, 1, 1);
      else
        DrvI2C_Ctrl(I2C0, 0, 0, 1, 0);
#endif
    }
    else
    {
				I2C0_I2ccnt++;
				if(I2C0_I2ccnt==10)
				{
						I2C0_ErrorFlag = 1;
						I2C0_EndFlag0 = 1;
						I2C0_I2ccnt = 0;
						I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
				}
				else
					I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_STO_SI);
//        DEBUG_PRINT("Status 0x%x is NOT processed\n", status);
    }           
}

void Get_PSDIR(void)
{
		uint8_t i,data[2];
		for(i=0;i<10;i++)
		{
				if(FB==0)
						I2C0_readBytes(FPSD, 0x5E, 2, data,1);
				else
						I2C0_readBytes(BPSD, 0x5E, 2, data,1);
				IR_12=(data[0]<<4)|(data[1]&0x0F);				

				cnt++;
				if (IR_12!=0xFFF)
						IR_f=(IR_f+IR_12);
				else
						cnf++;
				if ((cnt%1000)==0)
				{
						IR=IR_f/(1000-cnf)/64;
						if (cnf>500)
								IR=64;
						IR_f=0;
						cnf=0;
						FB^=1;
//						printf("%d: %d\n",FB,IR);
				}
		}
}

