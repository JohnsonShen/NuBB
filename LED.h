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
#ifndef _LED_H
#define _LED_H
#define LED_STATE_TOGGLE    0
#define LED_STATE_ON        1
#define LED_STATE_OFF       2

#define LED_ARM             0
#define LED_MAG             1
#define LED_HEAD_FREE       2
#define LED_ALTHOLD         3
#define LED_LOW_BAT         4
#define LED_LOW_RSSI	      5
#define LED_FLY_MODE	      6
#define LED_MATCH_ADDRESS   7

void Laser_init(void);
void LED_Init(void);
void UpdateLED(void);
void led_arm_state(char state);
void led_mag_state(char state);
char GetLedState(void);
#endif
