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
#ifndef _RC_SSV_H
#define _RC_SSV_H
void ssv_rc_update(void);
bool RC_SSV_Init(void);
void RC_SSV_Enable(char enable);
void SysTick_SSV(void);
void RC_CheckFlyMode(void);
uint8_t  RC_GetFlyMode(void);
uint16_t readSsvRC(uint8_t chan) ;
bool IsSSVRCConnected(void);
bool IsSSVReceiverConnected(void);
int16_t GetSSVThrust(void);
int16_t GetSSVAltitude(void);
void SetRemoteControl(void);
#endif
