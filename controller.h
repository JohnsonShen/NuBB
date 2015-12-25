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
 * O     O          __                   ______  __                           *
 *  \   /      /\  / /_      _    __    / /___/ / /_     _                    *
 *   [+]      /  \/ / \\    //__ / /__ / /____ / / \\   //                    *
 *  /   \    / /\  /   \\__// --/ /---/ /----// /   \\_//                     *
 * O     O  /_/  \/     \__/    \_\/ /_/     /_/ ____/_/                      *
 *                                                                            *
 *                                                                            *
 * Multi-Rotor controller firmware for Nuvoton Cortex M4 series               *
 *                                                                            *
 * Written by by T.L. Shen for Nuvoton Technology.                            *
 * tlshen@nuvoton.com/tzulan611126@gmail.com                                  *
 *                                                                            *
 *============================================================================*
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Def.h"
#include "pid.h"
void controllerInit(void);
bool controllerTest(void);

void controllerCorrectAttitudePID(
				float eulerRollActual, float eulerPitchActual, float eulerYawActual,
				float eulerRollDesired, float eulerPitchDesired, float eulerYawDesired,
				float* rollRateDesired, float* pitchRateDesired, float* yawRateDesired);

void controllerCorrectRatePID(
				float rollRateActual, float pitchRateActual, float yawRateActual,
				float rollRateDesired, float pitchRateDesired, float yawRateDesired);

#ifdef ABROBOT
void controllerCorrectSpeedPID(float speedActual,float speedDesired);
#endif
void controllerResetAllPID(void);
void controllerResetYawRatePID(void);
#ifdef ABROBOT
void controllerGetActuatorOutput(int16_t* roll, int16_t* pitch, int16_t* yaw, int16_t* speed);
#else
void controllerGetActuatorOutput(int16_t* roll, int16_t* pitch, int16_t* yaw);
#endif

void controllerSetRollPID(float kp, float ki, float kd);

void controllerSetPitchPID(float kp, float ki, float kd);

void controllerSetYawPID(float kp, float ki, float kd);

void controllerSetRollRatePID(float kp, float ki, float kd);

void controllerSetPitchRatePID(float kp, float ki, float kd);

void controllerSetYawRatePID(float kp, float ki, float kd);

void SetPID(void);

bool LoadFlashPID(void);

void GetRollPID(float* PID);

void GetPitchPID(float* PID);

void GetYawPID(float* PID);

void GetRollRatePID(float* PID);

void GetPitchRatePID(float* PID);

void GetYawRatePID(float* PID);

void GetAltHoldPID(float* PID);

uint32_t GetUnit32(void);

PidObject* GetAltHoldPIDObj(void);

#endif /* CONTROLLER_H_ */
