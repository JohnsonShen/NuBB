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
#include "retarget.h"
#include "controller.h"
#include "pid.h"
#include "param.h"
#include "FlashCtrl.h"
#include "Timer_Ctrl.h"
#include "Report.h"
//Fancier version
#define TRUNCATE_SINT16(out, in) (out = (in<INT16_MIN)?INT16_MIN:((in>INT16_MAX)?INT16_MAX:in) )

//Better semantic
#define SATURATE_SINT16(in) ( (in<INT16_MIN)?INT16_MIN:((in>INT16_MAX)?INT16_MAX:in) )

PidObject pidRollRate[2];
PidObject pidPitchRate[2];
PidObject pidYawRate[2];
PidObject pidRoll[2];
PidObject pidPitch[2];
PidObject pidYaw[2];
PidObject pidAltHold[2]; // Used for altitute hold mode. I gets reset when the bat status changes
#ifdef ABROBOT
PidObject pidSpeed[2];
#endif

int16_t rollOutput;
int16_t pitchOutput;
int16_t yawOutput;
#ifdef ABROBOT
int16_t speedOutput;
#endif


static bool isInit;

bool LoadFlashPID()
{
	float PID_FIELD[PID_FIELD_SIZE],IMU_UPDATE_DT;
	bool FlashValid;
	FlashValid = GetFlashPID(PID_FIELD);
	IMU_UPDATE_DT = getUpdateDT();
	if(FlashValid) {
		pidInit(&pidRoll[GetAHRSReport()], 0, PID_FIELD[0], PID_FIELD[1], PID_FIELD[2], IMU_UPDATE_DT);
		pidInit(&pidPitch[GetAHRSReport()], 0, PID_FIELD[3], PID_FIELD[4], PID_FIELD[5], IMU_UPDATE_DT);
		pidInit(&pidYaw[GetAHRSReport()], 0, PID_FIELD[6], PID_FIELD[7], PID_FIELD[8], IMU_UPDATE_DT);
		pidInit(&pidRollRate[GetAHRSReport()], 0, PID_FIELD[9], PID_FIELD[10], PID_FIELD[11], IMU_UPDATE_DT);
		pidInit(&pidPitchRate[GetAHRSReport()], 0, PID_FIELD[12], PID_FIELD[13], PID_FIELD[14], IMU_UPDATE_DT);
		pidInit(&pidYawRate[GetAHRSReport()], 0, PID_FIELD[15], PID_FIELD[16], PID_FIELD[17], IMU_UPDATE_DT);
#ifdef ABROBOT
    pidInit(&pidSpeed[GetAHRSReport()], 0, PID_FIELD[18], PID_FIELD[19], PID_FIELD[20], IMU_UPDATE_DT);
#else
		pidInit(&pidAltHold[GetAHRSReport()], 0, PID_FIELD[18], PID_FIELD[19], PID_FIELD[20], ALTHOLD_UPDATE_DT);
#endif
		return true;
	}
	else {
		pidInit(&pidRoll[GetAHRSReport()], 0, PID_ROLL_KP, PID_ROLL_KI, PID_ROLL_KD, IMU_UPDATE_DT);
		pidInit(&pidPitch[GetAHRSReport()], 0, PID_PITCH_KP, PID_PITCH_KI, PID_PITCH_KD, IMU_UPDATE_DT);
		pidInit(&pidYaw[GetAHRSReport()], 0, PID_YAW_KP, PID_YAW_KI, PID_YAW_KD, IMU_UPDATE_DT);
		pidInit(&pidRollRate[GetAHRSReport()], 0, PID_ROLL_RATE_KP, PID_ROLL_RATE_KI, PID_ROLL_RATE_KD, IMU_UPDATE_DT);
		pidInit(&pidPitchRate[GetAHRSReport()], 0, PID_PITCH_RATE_KP, PID_PITCH_RATE_KI, PID_PITCH_RATE_KD, IMU_UPDATE_DT);
		pidInit(&pidYawRate[GetAHRSReport()], 0, PID_YAW_RATE_KP, PID_YAW_RATE_KI, PID_YAW_RATE_KD, IMU_UPDATE_DT);
#ifdef ABROBOT
    pidInit(&pidSpeed[GetAHRSReport()], 0, PID_SPEED_KP, PID_SPEED_KI, PID_SPEED_KD, IMU_UPDATE_DT);
#else
		pidInit(&pidAltHold[GetAHRSReport()], 0, PID_ALTHOLD_KP, PID_ALTHOLD_KI, PID_ALTHOLD_KD, ALTHOLD_UPDATE_DT);
#endif
		return false;
	}
}
void controllerInit()
{

	if(LoadFlashPID()==false)
		printf("Load PID from [DEFAULT]\n");
	else
		printf("Load PID from [FLASH]\n");
#ifdef ABROBOT
	/* TBD for ABROBOT proper LIMIT */
	pidSetIntegralLimit(&pidRollRate[GetAHRSReport()], PID_ROLL_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidPitchRate[GetAHRSReport()], PID_PITCH_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidYawRate[GetAHRSReport()], PID_YAW_RATE_INTEGRATION_LIMIT);

	pidSetIntegralLimitLow(&pidRollRate[GetAHRSReport()], -PID_ROLL_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidPitchRate[GetAHRSReport()], -PID_PITCH_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidYawRate[GetAHRSReport()], -PID_YAW_RATE_INTEGRATION_LIMIT);

	pidSetIntegralLimit(&pidRoll[GetAHRSReport()], PID_ROLL_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidPitch[GetAHRSReport()], PID_PITCH_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidYaw[GetAHRSReport()], PID_YAW_INTEGRATION_LIMIT);
  
	pidSetIntegralLimitLow(&pidRoll[GetAHRSReport()], -PID_ROLL_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidPitch[GetAHRSReport()], -PID_PITCH_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidYaw[GetAHRSReport()], -PID_YAW_INTEGRATION_LIMIT);
#else
	pidSetIntegralLimit(&pidRollRate[GetAHRSReport()], PID_ROLL_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidPitchRate[GetAHRSReport()], PID_PITCH_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidYawRate[GetAHRSReport()], PID_YAW_RATE_INTEGRATION_LIMIT);

	pidSetIntegralLimitLow(&pidRollRate[GetAHRSReport()], -PID_ROLL_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidPitchRate[GetAHRSReport()], -PID_PITCH_RATE_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidYawRate[GetAHRSReport()], -PID_YAW_RATE_INTEGRATION_LIMIT);

	pidSetIntegralLimit(&pidRoll[GetAHRSReport()], PID_ROLL_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidPitch[GetAHRSReport()], PID_PITCH_INTEGRATION_LIMIT);
	pidSetIntegralLimit(&pidYaw[GetAHRSReport()], PID_YAW_INTEGRATION_LIMIT);
  
	pidSetIntegralLimitLow(&pidRoll[GetAHRSReport()], -PID_ROLL_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidPitch[GetAHRSReport()], -PID_PITCH_INTEGRATION_LIMIT);
	pidSetIntegralLimitLow(&pidYaw[GetAHRSReport()], -PID_YAW_INTEGRATION_LIMIT);
#endif
	isInit = true;
}

bool controllerTest()
{
	return isInit;
}

void controllerCorrectRatePID(
				float rollRateActual, float pitchRateActual, float yawRateActual,
				float rollRateDesired, float pitchRateDesired, float yawRateDesired)
{
	float pidOut;
	pidSetDesired(&pidRollRate[nvtGetAHRSID()], rollRateDesired);
	pidSetDt(&pidRollRate[nvtGetAHRSID()],getUpdateDT());
	pidOut = pidUpdate(&pidRollRate[nvtGetAHRSID()], rollRateActual, TRUE);
	TRUNCATE_SINT16(rollOutput, pidOut);
	//printf("%f %f %f %f\n",pidOut,pidRollRate.outP,pidRollRate.outI,pidRollRate.outD);
	pidSetDesired(&pidPitchRate[nvtGetAHRSID()], pitchRateDesired);
	pidSetDt(&pidPitchRate[nvtGetAHRSID()],getUpdateDT());
	pidOut = pidUpdate(&pidPitchRate[nvtGetAHRSID()], pitchRateActual, TRUE);
	TRUNCATE_SINT16(pitchOutput, pidOut);

	//printf("%f %f %f %f\n",pidOut,pidPitchRate.outP,pidPitchRate.outI,pidPitchRate.outD);
	pidSetDesired(&pidYawRate[nvtGetAHRSID()], yawRateDesired);
	pidSetDt(&pidYawRate[nvtGetAHRSID()],getUpdateDT());
	pidOut = pidUpdate(&pidYawRate[nvtGetAHRSID()], yawRateActual, TRUE);
	TRUNCATE_SINT16(yawOutput, pidOut);
}

void controllerCorrectAttitudePID(
				float eulerRollActual, float eulerPitchActual, float eulerYawActual,
				float eulerRollDesired, float eulerPitchDesired, float eulerYawDesired,
				float* rollRateDesired, float* pitchRateDesired, float* yawRateDesired)
{
	float yawError;
	pidSetDesired(&pidRoll[nvtGetAHRSID()], eulerRollDesired);
	pidSetDt(&pidRoll[nvtGetAHRSID()],getUpdateDT());
	*rollRateDesired = pidUpdate(&pidRoll[nvtGetAHRSID()], eulerRollActual, TRUE);

	// Update PID for pitch axis
	pidSetDesired(&pidPitch[nvtGetAHRSID()], eulerPitchDesired);
	pidSetDt(&pidPitch[nvtGetAHRSID()],getUpdateDT());
	*pitchRateDesired = pidUpdate(&pidPitch[nvtGetAHRSID()], eulerPitchActual, TRUE);

	// Update PID for yaw axis
	yawError = eulerYawDesired - eulerYawActual;
	if (yawError > 180.0f)
		yawError -= 360.0f;
	else if (yawError < -180.0f)
		yawError += 360.0f;
	
	pidSetError(&pidYaw[nvtGetAHRSID()], yawError);
	pidSetDt(&pidYaw[nvtGetAHRSID()],getUpdateDT());
	*yawRateDesired = pidUpdate(&pidYaw[nvtGetAHRSID()], eulerYawActual, FALSE);
}
#ifdef ABROBOT
void controllerCorrectSpeedPID(
				float speedActual,
				float speedDesired)
{ 
  float pidOut;
	pidSetDesired(&pidSpeed[nvtGetAHRSID()], speedDesired);
	pidSetDt(&pidSpeed[nvtGetAHRSID()],getUpdateDT());
	pidOut = pidUpdate(&pidSpeed[nvtGetAHRSID()], speedActual, TRUE);
	TRUNCATE_SINT16(speedOutput, pidOut);
}
#endif
void controllerResetAllPID(void)
{
	pidReset(&pidRoll[nvtGetAHRSID()]);
	pidReset(&pidPitch[nvtGetAHRSID()]);
	pidReset(&pidYaw[nvtGetAHRSID()]);
	pidReset(&pidRollRate[nvtGetAHRSID()]);
	pidReset(&pidPitchRate[nvtGetAHRSID()]);
	pidReset(&pidYawRate[nvtGetAHRSID()]);
#ifdef ABROBOT
  pidReset(&pidSpeed[nvtGetAHRSID()]);
#endif
}
void controllerResetYawRatePID(void)
{
  pidReset(&pidYawRate[nvtGetAHRSID()]);
}
void controllerSetRollPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidRoll[GetAHRSReport()], kp, pidRoll[GetAHRSReport()].ki, pidRoll[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidRoll[GetAHRSReport()], pidRoll[GetAHRSReport()].kp, ki, pidRoll[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidRoll[GetAHRSReport()], pidRoll[GetAHRSReport()].kp, pidRoll[GetAHRSReport()].ki, kd);
}

void controllerSetPitchPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidPitch[GetAHRSReport()], kp, pidPitch[GetAHRSReport()].ki, pidPitch[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidPitch[GetAHRSReport()], pidPitch[GetAHRSReport()].kp, ki, pidPitch[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidPitch[GetAHRSReport()], pidPitch[GetAHRSReport()].kp, pidPitch[GetAHRSReport()].ki, kd);
}
void controllerSetYawPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidYaw[GetAHRSReport()], kp, pidYaw[GetAHRSReport()].ki, pidYaw[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidYaw[GetAHRSReport()], pidYaw[GetAHRSReport()].kp, ki, pidYaw[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidYaw[GetAHRSReport()], pidYaw[GetAHRSReport()].kp, pidYaw[GetAHRSReport()].ki, kd);
}
void controllerSetRollRatePID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidRollRate[GetAHRSReport()], kp, pidRollRate[GetAHRSReport()].ki, pidRollRate[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidRollRate[GetAHRSReport()], pidRollRate[GetAHRSReport()].kp, ki, pidRollRate[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidRollRate[GetAHRSReport()], pidRollRate[GetAHRSReport()].kp, pidRollRate[GetAHRSReport()].ki, kd);
}
void controllerSetPitchRatePID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidPitchRate[GetAHRSReport()], kp, pidPitchRate[GetAHRSReport()].ki, pidPitchRate[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidPitchRate[GetAHRSReport()], pidPitchRate[GetAHRSReport()].kp, ki, pidPitchRate[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidPitchRate[GetAHRSReport()], pidPitchRate[GetAHRSReport()].kp, pidPitchRate[GetAHRSReport()].ki, kd);
}
void controllerSetYawRatePID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidYawRate[GetAHRSReport()], kp, pidYawRate[GetAHRSReport()].ki, pidYawRate[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidYawRate[GetAHRSReport()], pidYawRate[GetAHRSReport()].kp, ki, pidYawRate[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidYawRate[GetAHRSReport()], pidYawRate[GetAHRSReport()].kp, pidYawRate[GetAHRSReport()].ki, kd);
}
void controllerSetAltHoldPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidAltHold[GetAHRSReport()], kp, pidAltHold[GetAHRSReport()].ki, pidAltHold[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidAltHold[GetAHRSReport()], pidAltHold[GetAHRSReport()].kp, ki, pidAltHold[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidAltHold[GetAHRSReport()], pidAltHold[GetAHRSReport()].kp, pidAltHold[GetAHRSReport()].ki, kd);
}
#ifdef ABROBOT
void controllerSetSpeedPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidSpeed[GetAHRSReport()], kp, pidSpeed[GetAHRSReport()].ki, pidSpeed[GetAHRSReport()].kd);
	if(ki>=0)
		pidSetPID(&pidSpeed[GetAHRSReport()], pidSpeed[GetAHRSReport()].kp, ki, pidSpeed[GetAHRSReport()].kd);
	if(kd>=0)
		pidSetPID(&pidSpeed[GetAHRSReport()], pidSpeed[GetAHRSReport()].kp, pidSpeed[GetAHRSReport()].ki, kd);
}
#endif
#ifdef ABROBOT
void controllerGetActuatorOutput(int16_t* roll, int16_t* pitch, int16_t* yaw,int16_t* speed)
{
	*roll = rollOutput;
	*pitch = pitchOutput;
	*yaw = yawOutput;
  *speed = speedOutput;
}
#else
void controllerGetActuatorOutput(int16_t* roll, int16_t* pitch, int16_t* yaw)
{
	*roll = rollOutput;
	*pitch = pitchOutput;
	*yaw = yawOutput;
}
#endif
void GetRollPID(float* PID)
{
	PID[0] = pidRoll[GetAHRSReport()].kp;
	PID[1] = pidRoll[GetAHRSReport()].ki;
	PID[2] = pidRoll[GetAHRSReport()].kd;
}
void GetPitchPID(float* PID)
{
	PID[0] = pidPitch[GetAHRSReport()].kp;
	PID[1] = pidPitch[GetAHRSReport()].ki;
	PID[2] = pidPitch[GetAHRSReport()].kd;
}
void GetYawPID(float* PID)
{
	PID[0] = pidYaw[GetAHRSReport()].kp;
	PID[1] = pidYaw[GetAHRSReport()].ki;
	PID[2] = pidYaw[GetAHRSReport()].kd;
}
void GetRollRatePID(float* PID)
{
	PID[0] = pidRollRate[GetAHRSReport()].kp;
	PID[1] = pidRollRate[GetAHRSReport()].ki;
	PID[2] = pidRollRate[GetAHRSReport()].kd;
}
void GetPitchRatePID(float* PID)
{
	PID[0] = pidPitchRate[GetAHRSReport()].kp;
	PID[1] = pidPitchRate[GetAHRSReport()].ki;
	PID[2] = pidPitchRate[GetAHRSReport()].kd;
}
void GetYawRatePID(float* PID)
{
	PID[0] = pidYawRate[GetAHRSReport()].kp;
	PID[1] = pidYawRate[GetAHRSReport()].ki;
	PID[2] = pidYawRate[GetAHRSReport()].kd;
}
void GetAltHoldPID(float* PID)
{
	PID[0] = pidAltHold[GetAHRSReport()].kp;
	PID[1] = pidAltHold[GetAHRSReport()].ki;
	PID[2] = pidAltHold[GetAHRSReport()].kd;
}
#ifdef ABROBOT
void GetSpeedPID(float* PID)
{
	PID[0] = pidSpeed[GetAHRSReport()].kp;
	PID[1] = pidSpeed[GetAHRSReport()].ki;
	PID[2] = pidSpeed[GetAHRSReport()].kd;
}
#endif
uint32_t GetUnit32()
{
  char value_s[4];
  uint32_t X;//Jtest
  value_s[0] = GetChar();
  value_s[1] = GetChar();
  value_s[2] = GetChar();
  value_s[3] = GetChar();
  X = atoi(value_s);
  return X;
}
int GetPIDValue()
{
	char value_s[3];
	
	value_s[0] = GetChar();
	value_s[1] = GetChar();
	value_s[2] = GetChar();
	
	return atoi(value_s);
}
float GetPIDfloat()
{
	char value_s[4];
	
	value_s[0] = GetChar();
	value_s[1] = GetChar();
	value_s[2] = GetChar();
	value_s[3] = GetChar();
	
	return atof(value_s);
}
PidObject* GetAltHoldPIDObj()
{
	return &pidAltHold[GetAHRSReport()];
}
#ifdef ABROBOT
PidObject* GetSpeedPIDObj()
{
	return &pidSpeed[GetAHRSReport()];
}
#endif
void SetPID()
{
	char type = GetChar();
	//int value;
	char rpy, pid;
	float valuef;
	if(type=='p') { //PID
		rpy = GetChar();
		if(rpy=='r') { //Roll
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p')
				controllerSetRollPID(valuef, -1, -1);
			else if(pid=='i') 
				controllerSetRollPID(-1, valuef, -1);
			else if(pid=='d') 
				controllerSetRollPID(-1, -1, valuef);
		}
		else if(rpy=='p') { //Pitch
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetPitchPID(valuef, -1, -1);
			else if(pid=='i') 
				controllerSetPitchPID(-1, valuef, -1);
			else if(pid=='d') 
				controllerSetPitchPID(-1, -1, valuef);
		}
		else if(rpy=='y') { //Yaw
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetYawPID(valuef, -1, -1);
			else if(pid=='i') 
				controllerSetYawPID(-1, valuef, -1);
			else if(pid=='d') 
				controllerSetYawPID(-1, -1, valuef);
		}
	}
	else if(type=='r') { //Rate PID
		rpy = GetChar();
		if(rpy=='r') { //Roll
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetRollRatePID((float)valuef, -1, -1);
			else if(pid=='i') 
				controllerSetRollRatePID(-1, (float)valuef, -1);
			else if(pid=='d') 
				controllerSetRollRatePID(-1, -1, (float)valuef);
		}
		else if(rpy=='p') { //Pitch
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetPitchRatePID((float)valuef, -1, -1);
			else if(pid=='i') 
				controllerSetPitchRatePID(-1, (float)valuef, -1);
			else if(pid=='d') 
				controllerSetPitchRatePID(-1, -1, (float)valuef);
		}
		else if(rpy=='y') { //Yaw
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetYawRatePID((float)valuef, -1, -1);
			else if(pid=='i') 
				controllerSetYawRatePID(-1, (float)valuef, -1);
			else if(pid=='d') 
				controllerSetYawRatePID(-1, -1, (float)valuef);
		}
	}
#ifdef ABROBOT
  else if(type=='a') { //Altitide Hold PID
		pid = GetChar();
		valuef = GetPIDfloat();
		if(pid=='p') 
			controllerSetSpeedPID((float)valuef, -1, -1);
		else if(pid=='i') 
			controllerSetSpeedPID(-1, (float)valuef, -1);
		else if(pid=='d') 
			controllerSetSpeedPID(-1, -1, (float)valuef);
	}
#else
	else if(type=='a') { //Altitide Hold PID
		pid = GetChar();
		valuef = GetPIDfloat();
		if(pid=='p') 
			controllerSetAltHoldPID((float)valuef, -1, -1);
		else if(pid=='i') 
			controllerSetAltHoldPID(-1, (float)valuef, -1);
		else if(pid=='d') 
			controllerSetAltHoldPID(-1, -1, (float)valuef);
	}
#endif
	else if(type=='s') { //'s'tore flash PID
		UpdateFlashPID(false);
	}
	else if(type=='l') { //'l'oad flash PID
		LoadFlashPID();
	}
}

