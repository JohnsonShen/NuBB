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
#ifndef __MOTORS_H__
#define __MOTORS_H__
#include <stdint.h>
/******** Defines ********/
#define MOTORS_PWM_BITS     9
#define MOTORS_PWM_PERIOD   ((1<<MOTORS_PWM_BITS) - 1)
#define MOTORS_PWM_PRESCALE 0
#ifdef ABROBOT
#define IO_MR_CRTL0        PE,BIT12
#define IO_MR_CRTL1        PE,BIT13
#define IO_ML_CRTL0        PD,BIT7
#define IO_ML_CRTL1        PF,BIT2
#endif
// Motors IDs define
#define MOTOR_M1  0
#define MOTOR_M2  1
#define MOTOR_M3  2
#define MOTOR_M4  3
#define MOTOR_M5  4
#define MOTOR_M6  5

#define MOTORS_TEST_RATIO          (uint16_t)(0.5*(1<<16))
#define MOTORS_TEST_ON_TIME_MS     10
#define MOTORS_TEST_DELAY_TIME_MS  50
#define ESC_UPDATE_FREQ            400
#define ESC_FREQ_UPDATE_FREQ_DIV_1000000  0.0004f
#define MOTORS_ESC_DELAY           1500 /*Frame*/
#ifdef ABROBOT
#define MOTOR_NUMBER               6
#define STOP  0
#define CCW   1
#define CW    2
#define BREAK 3
#define R     0
#define L     1
#define M     2
typedef struct {
  uint8_t ctrl;
  uint16_t pwm;
} BLDC_MOTOR_T;
#else
#ifdef HEX6X 
#define MOTOR_NUMBER               6
#else
#define MOTOR_NUMBER               4
#endif
#endif
#define MAX_PULSE_WIDTH            2000 /*pulse width range from 0 to 2000 and 2000 means 2ms*/
#define PWM_GET_CNR(pwm, u32ChannelNum)  (*(__IO uint32_t *) (&((pwm)->PERIOD0) + (u32ChannelNum)))


void motorsInit(void);
void motorsSetRatio(int id, uint16_t ratio);
int motorsGetRatio(int id);
void motorsStart(void);
#ifdef ABROBOT
void ABRobotMotorInit(void);
void SetMotorCal(void);
MotorCal_t* GetMotorCal(void);
#endif
#endif /* __MOTORS_H__ */

