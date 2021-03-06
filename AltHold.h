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
#ifndef _ALTHOLD_H
#define _ALTHOLD_H
#include "pid.h"
typedef struct ALT_STATE {
	float altHoldPIDVal;
	float altHoldChange;
	float altHoldTarget;
	float asl;
}ALTHOLD_STATE_T;
bool GetAltHoldMode(void);
void stabilizerAltHoldUpdate(int16_t *);
bool GetAltHoldMode(void);
void SetAltHoldPIDObj(PidObject* PIDObj);
void SetCalibratingB(uint8_t c);
ALTHOLD_STATE_T* GetAltHoldState(void);
float getAslSpeed(void);
float getAltHoldPIDVal(void);
float getAccFuse(void);
bool GetAutoLandMode(void);
bool GetNearLand(void);
#endif
