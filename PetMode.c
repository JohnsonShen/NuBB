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
#include "math.h"
#include "M451Series.h"
#include "battery.h"
#include "Def.h"
#include "Report.h"
#include "Timer_Ctrl.h"
#include "PetMode.h"
PET_CTRL_T PetControl;
bool bePetMode=false;
uint8_t PetModeState = STOP;
float eulerYawActual,eulerYawStart,eulerYawDiff;
uint16_t fwbwTime, fwbwCount;
bool getPetMode()
{
  return bePetMode;
}
PET_CTRL_T* getPetControl(void)
{
  return &PetControl;
}
void PetModeStop()
{
}
void PetModeStart()
{
  eulerYawStart = eulerYawActual;
  PetModeState = TURN;
}
void PetModeTurn()
{
  eulerYawDiff = (eulerYawActual - eulerYawStart);
  if(fabs(eulerYawDiff)>80) {
    STEADY
    PetModeState = FWBW;
  }
  else {
    FW_TURNR
  }
}
void PetModeFwBw()
{

}
void PetModeControl() 
{
  float Euler[3];
  nvtGetEulerRPY(Euler);
  eulerYawActual = Euler[2];
  if(PetModeState==STOP) {
  }
  else if(PetModeState==START) {
    PetModeStart();
  }
  else if(PetModeState==TURN) {
    PetModeTurn();
  }
  else if(PetModeState==FWBW) {
    PetModeFwBw();
  }
}
