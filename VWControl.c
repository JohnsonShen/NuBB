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
#include "Def.h"
#include "Report.h"
#include "Sensors.h"
#include "VWControl.h"
#define RPM_MAX 140
#define RPM_MIN 0
#define MIN_FACTOR 0.1f;
float GetFactorFromVelocity()
{
  int16_t FusionSpeed;/*cm/sec*/
  float WFactor;
  FusionSpeed = GetFusionSpeed();
  WFactor = fabs((RPM_MAX - fabs(FusionSpeed)))/RPM_MAX + MIN_FACTOR;
  //printf("%d %f\n",FusionSpeed,WFactor);
  return WFactor;
}
