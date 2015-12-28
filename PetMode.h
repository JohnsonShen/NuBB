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
#ifndef _PETMODE_H
#define _PETMODE_H
#include "Def.h"
typedef struct {
  int16_t rc_roll;
  int16_t rc_pitch;
  int16_t rc_yaw;
  int16_t rc_aux1;
  int16_t rc_thrust;
} PET_CTRL_T;
#define STOP   0
#define START  1
#define TURN   2
#define FWBW   3
#define PET_PITCH 300
#define PET_YAW 200
#define PET_RTURN   200
#define PET_LTURN   100
#define PET_NOTURN  128
#define FWBW_TIME   250
#define FWBW_COUNT  2
#define FW_TURNR PetControl.rc_pitch = PET_PITCH;PetControl.rc_aux1 = PET_RTURN;
#define FW_TURNL PetControl.rc_pitch = PET_PITCH;PetControl.rc_aux1 = PET_LTURN;
#define FW_ONLY  PetControl.rc_pitch = PET_PITCH;PetControl.rc_aux1 = PET_NOTURN;
#define BW_ONLY  PetControl.rc_pitch = -PET_PITCH;PetControl.rc_aux1 = PET_NOTURN;
#define STEADY   PetControl.rc_pitch = 0;PetControl.rc_aux1 = PET_NOTURN; 
bool getPetMode(void);
void PetModeControl(void);
PET_CTRL_T* getPetControl(void);
#endif
