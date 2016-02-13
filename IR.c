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
#include "IR.h"
#include "Timer_Ctrl.h"

#define     Percent             0.04        // 4 % 
#define     MaxValue            0xFFFF

// Leader code range
#define     IR_LDC_MAX          (13460 * (1 + Percent))
#define     IR_LDC_MIN          (13460 * (1 - Percent))
// Repeater code range
#define     IR_RPC_MAX          (11280 * (1 + Percent))
#define     IR_RPC_MIN          (11280 * (1 - Percent))
// Bit = 1 range
#define     IR_BIT_1_MAX        (2236 * (1 + Percent))
#define     IR_BIT_1_MIN        (2236 * (1 - Percent))
// Bit = 0 range
#define     IR_BIT_0_MAX        (1120 * (1 + Percent))
#define     IR_BIT_0_MIN        (1120 * (1 - Percent))

volatile    uint8_t             IR_State = 0;       // IR State
volatile    uint8_t             IR_LDC_Ready = 0;   // LeaDer Code is Ready
volatile    uint8_t             IR_CTC_Ready = 0;   // CusTomer Code is Ready
uint8_t             IR_CODE[13]  =   {0x00, 0x00, 0x00, 0x00};

volatile    uint8_t             IR2_State = 0;       // IR State
volatile    uint8_t             IR2_LDC_Ready = 0;   // LeaDer Code is Ready
volatile    uint8_t             IR2_CTC_Ready = 0;   // CusTomer Code is Ready
uint8_t             IR2_CODE[13]  =   {0x00, 0x00, 0x00, 0x00};
extern uint32_t COM2_LED_R, COM2_LED_G, COM2_LED_B, COM2_Blink,COM2_LED_EN;

void IrDa_NEC_Rx(uint32_t u32Time)
{
    if(IR_State == 0)
    {
        IR_LDC_Ready = 0;           // Clear LeaDer Code Ready
        IR_CTC_Ready = 0;           // Clear CusTomer Code Ready
        IR_State++;
    }
    // Leader or Repeater code
    else if(IR_State == 1)
    {
        // Leader code
        if((u32Time >= IR_LDC_MIN) && (u32Time <= IR_LDC_MAX))
        {
            IR_LDC_Ready = 1;       // Set LeaDer Code Ready
            IR_State++;
        }
        else
        {
            IR_State = 1;
            IR_LDC_Ready = 0;           // Clear LeaDer Code Ready
            IR_CTC_Ready = 0;           // Clear CusTomer Code Ready
        }
    }
    // Customer code 0
    else if((IR_State >= 2 && IR_State < 10) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[0] = IR_CODE[0] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[0] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX)) // 2.25ms = 1
            IR_CODE[0] |= 0x80;
        else
            IR_State = 0;
    }
    // Customer code 1
    else if((IR_State >= 10 && IR_State < 18) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[1] = IR_CODE[1] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[1] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX)) // 2.25ms = 1
            IR_CODE[1] |= 0x80;
        else
            IR_State = 0;
    }
    // Data
    else if((IR_State >= 18 && IR_State < 26) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[2] = IR_CODE[2] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[2] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[2] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 26 && IR_State < 34) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[3] = IR_CODE[3] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[3] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[3] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 34 && IR_State < 42) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[4] = IR_CODE[4] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[4] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[4] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 42 && IR_State < 50) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[5] = IR_CODE[5] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[5] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[5] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 50 && IR_State < 58) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[6] = IR_CODE[6] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[6] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[6] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 58 && IR_State < 66) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[7] = IR_CODE[7] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[7] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[7] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 66 && IR_State < 74) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[8] = IR_CODE[8] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[8] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[8] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 74 && IR_State < 82) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[9] = IR_CODE[9] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[9] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[9] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 82 && IR_State < 90) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[10] = IR_CODE[10] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[10] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[10] |= 0x80;
        else
            IR_State = 0;

    }
		else if((IR_State >= 90 && IR_State < 98) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[11] = IR_CODE[11] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR_CODE[11] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[11] |= 0x80;
        else
            IR_State = 0;

    }
    // Data bar
    else if((IR_State >= 98 && IR_State < 106) && (IR_LDC_Ready == 1))
    {
        IR_State++;
        IR_CODE[12] = IR_CODE[12] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))      // 1.12ms = 0
            IR_CODE[12] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR_CODE[12] |= 0x80;
        else
            IR_State = 0;

        if(IR_State == 106)
        {
            IR_LDC_Ready = 0;   // Clear LeaDer Code Ready
//                printf("IR: ID=%02x,  %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
//												, IR_CODE[0], IR_CODE[1], IR_CODE[2], IR_CODE[3], IR_CODE[4], IR_CODE[5], IR_CODE[6]
//												, IR_CODE[7], IR_CODE[8], IR_CODE[9], IR_CODE[10], IR_CODE[11], IR_CODE[12]);
            IR_State = 0;
        }
    }
}
void IrDa_NEC_Rx2(uint32_t u32Time)
{
    if(IR2_State == 0)
    {
        IR2_LDC_Ready = 0;           // Clear LeaDer Code Ready
        IR2_CTC_Ready = 0;           // Clear CusTomer Code Ready
        IR2_State++;
    }
    // Leader or Repeater code
    else if(IR2_State == 1)
    {
        // Leader code
        if((u32Time >= IR_LDC_MIN) && (u32Time <= IR_LDC_MAX))
        {
            IR2_LDC_Ready = 1;       // Set LeaDer Code Ready
            IR2_State++;
        }
        else
        {
            IR2_State = 1;
            IR2_LDC_Ready = 0;           // Clear LeaDer Code Ready
            IR2_CTC_Ready = 0;           // Clear CusTomer Code Ready
        }
    }
    // Customer code 0
    else if((IR2_State >= 2 && IR2_State < 10) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[0] = IR2_CODE[0] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[0] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX)) // 2.25ms = 1
            IR2_CODE[0] |= 0x80;
        else
            IR2_State = 0;
    }
    // Customer code 1
    else if((IR2_State >= 10 && IR2_State < 18) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[1] = IR2_CODE[1] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[1] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX)) // 2.25ms = 1
            IR2_CODE[1] |= 0x80;
        else
            IR2_State = 0;
    }
    // Data
    else if((IR2_State >= 18 && IR2_State < 26) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[2] = IR2_CODE[2] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[2] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[2] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 26 && IR2_State < 34) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[3] = IR2_CODE[3] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[3] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[3] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 34 && IR2_State < 42) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[4] = IR2_CODE[4] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[4] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[4] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 42 && IR2_State < 50) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[5] = IR2_CODE[5] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[5] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[5] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 50 && IR2_State < 58) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[6] = IR2_CODE[6] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[6] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[6] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 58 && IR2_State < 66) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[7] = IR2_CODE[7] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[7] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[7] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 66 && IR2_State < 74) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[8] = IR2_CODE[8] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[8] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[8] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 74 && IR2_State < 82) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[9] = IR2_CODE[9] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[9] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[9] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 82 && IR2_State < 90) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[10] = IR2_CODE[10] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[10] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[10] |= 0x80;
        else
            IR2_State = 0;

    }
		else if((IR2_State >= 90 && IR2_State < 98) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[11] = IR2_CODE[11] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))          // 1.12ms = 0
            IR2_CODE[11] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[11] |= 0x80;
        else
            IR2_State = 0;

    }
    // Data bar
    else if((IR2_State >= 98 && IR2_State < 106) && (IR2_LDC_Ready == 1))
    {
        IR2_State++;
        IR2_CODE[12] = IR2_CODE[12] >> 1;
        if((u32Time >= IR_BIT_0_MIN) && (u32Time <= IR_BIT_0_MAX))      // 1.12ms = 0
            IR2_CODE[12] &= 0x7f;
        else if((u32Time >= IR_BIT_1_MIN) && (u32Time <= IR_BIT_1_MAX))     // 2.25ms = 1
            IR2_CODE[12] |= 0x80;
        else
            IR2_State = 0;

        if(IR2_State == 106)
        {
            IR2_LDC_Ready = 0;   // Clear LeaDer Code Ready
//                printf("IR: ID=%02x,  %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
//												, IR_CODE[0], IR_CODE[1], IR_CODE[2], IR_CODE[3], IR_CODE[4], IR_CODE[5], IR_CODE[6]
//												, IR_CODE[7], IR_CODE[8], IR_CODE[9], IR_CODE[10], IR_CODE[11], IR_CODE[12]);
            IR2_State = 0;
        }
    }
}

void PWM1P1_IRQHandler(void)
{
    uint32_t TDR1_tmp,TDR2_tmp;
		if(PWM_GetCaptureIntFlag(PWM1, 2) ==3)
		{	
				TDR1_tmp = MaxValue - PWM_GET_CAPTURE_FALLING_DATA(PWM1, 2);
				PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_FALLING_LATCH);
				IrDa_NEC_Rx(TDR1_tmp);
		}
		if(PWM_GetCaptureIntFlag(PWM1, 3) ==3)
		{	
				TDR2_tmp = MaxValue - PWM_GET_CAPTURE_FALLING_DATA(PWM1, 3);
				PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_FALLING_LATCH);
				IrDa_NEC_Rx2(TDR2_tmp);
		}
}

#define     NEC_LDC_MARK        16      // 16 x 560us = 8960us =   9ms
#define     NEC_LDC_SPACE       8       //  8 x 560us = 4480us = 4.5ms
#define     NEC_BIT_MARK        1       // 560us
#define     NEC_ONE_SPACE       3       //  3 x 560us = 1680us = 1690us
#define     NEC_ZERO_SPACE      1       // 560us
#define     NEC_BYTES           4


//*******************************
// Mark
//
// Pulse = 1/3 duty @38KHz frequency
//*******************************
void Mark(uint8_t N)
{
    /* Switch to PWM output waveform */
    PWM_EnableOutput(PWM1, PWM_CH_0_MASK);
    TIMER_Delay(TIMER0, 560 * N);
    PWM_DisableOutput(PWM1, PWM_CH_0_MASK);

}
void SPACE(uint8_t N)
{
    TIMER_Delay(TIMER0, 560 * N);
}
//*******************************
// Send NEC IR Format
//
// PC15 (PWM1_CH3)
//*******************************
void SendIR(uint8_t* data)
{
    uint8_t nbyte;
    uint8_t nbit;

    /* Send out Leader code */
    Mark(NEC_LDC_MARK);
    SPACE(NEC_LDC_SPACE);

    /* Send out Customer code and Data code */
    for(nbyte = 0; nbyte < NEC_BYTES; nbyte++)
    {
        for(nbit = 0; nbit < 8; nbit++)
        {
            Mark(NEC_BIT_MARK);
            if(data[nbyte] & (1 << nbit))       // LSB first
                SPACE(NEC_ONE_SPACE);
            else
                SPACE(NEC_ZERO_SPACE);
        }
    }
    /* Send out Stop bit */
    Mark(NEC_BIT_MARK);
}


void IR_init(void)
{
    /* Set PC multi-function pins for PWM1 Channel 0 and 2 */
    SYS->GPC_MFPH = SYS->GPC_MFPH & (~SYS_GPC_MFPH_PC9MFP_Msk) & (~SYS_GPC_MFPH_PC11MFP_Msk) & (~SYS_GPC_MFPH_PC12MFP_Msk);
    SYS->GPC_MFPH |= (SYS_GPC_MFPH_PC9MFP_PWM1_CH0|SYS_GPC_MFPH_PC11MFP_PWM1_CH2|SYS_GPC_MFPH_PC12MFP_PWM1_CH3);


    /* Enable PWM module clock */
    CLK_EnableModuleClock(PWM1_MODULE);

    /* Select PWM module clock source */
    CLK_SetModuleClock(PWM1_MODULE, CLK_CLKSEL2_PWM1SEL_PCLK1, 0);

    /* Reset PWM1 channel 0~5 */
    SYS_ResetModule(PWM1_RST);

    /* set PWM1 channel 0 output configuration */
    PWM_ConfigOutputChannel(PWM1, 0, 38000, 30);

    /* Enable Timer for PWM1 channel 4 */
    PWM_Start(PWM1, PWM_CH_0_MASK);


    /* set PWM1 channel 3 capture configuration */
    PWM_ConfigCaptureChannel(PWM1, 2, 1000, 0);
		PWM_ConfigCaptureChannel(PWM1, 3, 1000, 0);

    /* Enable capture falling edge interrupt for PWM1 channel 3 */
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_FALLING_LATCH);
		PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_FALLING_LATCH);

    /* Enable PWM1 NVIC interrupt */
    NVIC_EnableIRQ(PWM1P1_IRQn);

    /* Enable Timer for PWM1 channel 3 */
    PWM_Start(PWM1, PWM_CH_2_MASK);
		PWM_Start(PWM1, PWM_CH_3_MASK);

    /*Enable Input Schmitt Trigger*/
    PC->SMTEN |= GPIO_SMTEN_SMTEN11_Msk;
		PC->SMTEN |= GPIO_SMTEN_SMTEN12_Msk;

    /* Enable Capture Function for PWM1 channel 3 */
    PWM_EnableCapture(PWM1, PWM_CH_2_MASK);
		PWM_EnableCapture(PWM1, PWM_CH_3_MASK);

    /* Enable falling capture reload */
    PWM1->CAPCTL |= PWM_CAPCTL_FCRLDEN2_Msk;
		PWM1->CAPCTL |= PWM_CAPCTL_FCRLDEN3_Msk;

}
