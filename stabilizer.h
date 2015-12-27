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
#ifndef STABILIZER_H_
#define STABILIZER_H_
#include <stdint.h>
void stabilizer(void);
void stabilizerInit(void);
void GetMotorPower(int16_t* MotorPower);
char GetFlip(void);
void ClearFlip(void);
float GetAccWZ(void);
void GetvSpeed(float* speed);
void SetvSpeed(float speed);
float deadband(float value, const float threshold);
uint16_t limitThrust(int32_t value);
float GetactuatorThrust(void);
void HoldHead(void);
void HoldHeadFree(void);
bool getMagMode(void);
bool getHeadFreeMode(void);
bool isArmMinThrottle(void);
bool IsMotorSpin(void);
float getHeadHold(void);
ACTUATOR_T* getActuator(void);
#endif /* STABILIZER_H_ */

