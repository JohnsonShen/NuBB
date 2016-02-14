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
#include "M451Series.h"
#include "gpio.h"
#include "Def.h"
#include "RC.h"
#include "AHRSLib.h"
#include "controller.h"
#include "motors.h"
#include "pid.h"
#include "math.h"
#include "sensors.h"
#include "AltHold.h"
#include "Timer_Ctrl.h"
#include "stabilizer.h"
#include "Report.h"
#include "RC.h"
#ifdef ABROBOT
#define ROLL_DEG_MAX  70
#define PITCH_DEG_MAX 65
#else
#define ROLL_DEG_MAX  60
#define PITCH_DEG_MAX 60
#endif
#define YAW_DEG_MAX   80
#define THRUST_MAX    90
#define COS_30        0.866f
#define COS_60        0.5f
#ifdef ABROBOT
#define ACTUATOR_DEAD_ZONE 0
#endif
#define YAW_SPEED 200
#define FLIP_COUNTER 100
static float gyro[3]; // Gyro axis data in deg/s
static float eulerRollActual;
static float eulerPitchActual;
static float eulerYawActual;
static float eulerRollDesired;
static float eulerPitchDesired;
static float eulerYawDesired;
static float rollRateDesired;
static float pitchRateDesired;
static float yawRateDesired;
#ifdef ABROBOT
static float speedDesired;
#endif
static float vSpeed       = 0.0f; // Vertical speed (world frame) integrated from vertical acceleration
static float accWZ        = 0.0f;
static float headHold     = 0.0f;
static float headFreeHold = 0.0f;
static bool magMode = false;
static bool headFreeMode = false;
static bool wspeedMode = false;
int16_t  motor_enable=0;
uint16_t  camera=1512;
ACTUATOR_T Actuator;

uint32_t motorPowerM[MOTOR_NUMBER];
#ifdef ABROBOT
BLDC_MOTOR_T BLDC_MOTOR[MOTOR_NUMBER];
#endif
extern int flip_count;
char flip = 0;
ACTUATOR_T* getActuator()
{
  return &Actuator;
}
void HoldHead(void)
{
	headHold = eulerYawActual;
}
float getHeadHold() 
{
  return headHold;
}
void HoldHeadFree(void)
{
	headFreeHold = eulerYawActual;
}
bool getMagMode()
{
	return magMode;
}
bool getHeadFreeMode()
{
	return headFreeMode;
}
void stabilizerInit(void)
{
	controllerInit();

#if STACK_BARO
	SetAltHoldPIDObj(GetAltHoldPIDObj());
#endif
	rollRateDesired = 0;
	pitchRateDesired = 0;
	yawRateDesired = 0;
}
int flip_count=0;
void DetectFlip()
{
	if(eulerRollActual>ROLL_DEG_MAX)
		flip_count++;
	else if(eulerRollActual<-ROLL_DEG_MAX)
		flip_count++;
	
	if(eulerPitchActual>PITCH_DEG_MAX)
		flip_count++;
	else if(eulerPitchActual<-PITCH_DEG_MAX)
		flip_count++;
  
  if(flip_count>FLIP_COUNTER)
    flip = 1;
    
  //if((GetFrameCount()%40)==0)
  //  printf("flip,R,P:%d,%f,%f\n", flip,eulerRollActual,eulerPitchActual);
}
float GetAccWZ()
{
	return accWZ;
}
char GetFlip()
{
	return flip;
}
void ClearFlip()
{
	flip = 0;
  flip_count=0;
}

void commanderGetRPY()
{
	int16_t rcData[RC_CHANS], rc_roll, rc_pitch, rc_yaw, rc_aux1;
  static int16_t yaw_last;
  
	getRC(rcData);
	rc_roll = (rcData[ROLL_CH] - RC_ROLL_MID);
	rc_pitch = -(rcData[THR_CH] - RC_PITCH_MID); //(rcData[PITCH_CH] - RC_PITCH_MID);
	rc_yaw = (rcData[YAW_CH] - RC_YAW_MID);
	rc_aux1 = rcData[AUX1_CH];
  //if((GetFrameCount()%500)<=1)
  //  printf("rc_pitch0:%d",rc_pitch);
  if((rc_roll!=0)||((rc_aux1!=128)&&(rc_aux1!=255))) {
    MotorArm();
  }
#ifdef ABROBOT
  //if((rc_pitch==0)&&(rc_roll==0)&&(rc_aux1==128))
  //  controllerResetAllPID();
#ifdef  DEGREE
    if(rc_aux1==255)
      rc_yaw = 0;
    else
      rc_yaw = -(rc_aux1 - 128)*15;

#else
#ifdef WSPEED
    rc_yaw = rc_roll;
  //if((GetFrameCount()%500)==0)
  //    printf("rc_yaw,rcData[YAW_CH],:%d %d\n",rc_yaw, rcData[YAW_CH]);
#else
#ifdef WSPEED_DEGREE
    if(rc_roll) {
      rc_yaw = rc_roll*5;
      wspeedMode = true;
    }
    else {
      if(rc_aux1==255)
        rc_yaw = 0;
      else
        rc_yaw = -(rc_aux1 - 128)*15;
      wspeedMode = false;
    }
#else
  if(rc_aux1==128)
    rc_yaw = 0;
  else if(rc_aux1>128)
    rc_yaw = YAW_SPEED*YawSpeedFactor;
  else
    rc_yaw = -YAW_SPEED*YawSpeedFactor;
#endif
#endif
#endif
  
  //rc_roll =0;
	if(nvtGetAHRSID()==0)
    rc_pitch = 0;
  else {
    //rc_pitch-=20;
  }
	
  if(!magMode)
    HoldHead();

  magMode = true;
  headFreeMode = false;
#else
	if(rc_aux2<RC_ONE_THIRD) {
		magMode = false;
		headFreeMode = false;
	} else if(rc_aux2>RC_TWO_THIRD) {
		if(!headFreeMode)
			HoldHeadFree();
		headFreeMode = true;
	}
	else {
		if(!magMode)
			HoldHead();
		
		magMode = true;
		headFreeMode = false;
	}
#endif
	if(headFreeMode) { //to optimize
		float radDiff = (headFreeHold - eulerYawActual) * 0.0174533f; // where PI/180 ~= 0.0174533
		float cosDiff = cos(radDiff);
		float sinDiff = sin(radDiff);
		int16_t rcCommand_PITCH = rc_pitch*cosDiff + rc_roll*sinDiff;
		
		rc_roll =  rc_roll*cosDiff - rc_pitch*sinDiff; 
		rc_pitch = rcCommand_PITCH;
		//if((GetFrameCount()%18)==0)
		//printf("YA:%f,HF:%f,Diff:%f\n",eulerYawActual,headFreeHold,radDiff);
	}
#if 0
	if (fabs(rc_yaw)<RC_YAW_DEAD_BAND) {
		if(magMode&&(!headFreeMode)) {
			int16_t dif = eulerYawActual - headHold;
			
			if(dif<-180)
				dif = dif + 360;
			else if(dif>180)
				dif = dif - 360;
			eulerYawDesired = dif;
		}
		else 
			eulerYawDesired = 0;
	} 
	else {
		if(magMode)
			HoldHead();
		
		if(rc_yaw>0)
			eulerYawDesired = (rc_yaw*YAW_DEG_MAX/(RC_YAW_MAX-RC_YAW_MID));
		else
			eulerYawDesired = -(rc_yaw*YAW_DEG_MAX/(RC_YAW_MIN-RC_YAW_MID));
	}
#else
#ifdef DEGREE
  	if ((rc_aux1==255)||(rc_yaw==0)) {
		if(magMode&&(!headFreeMode)) {
			int16_t dif = eulerYawActual - headHold;
      
      if((yaw_last!=0)&&(rc_aux1==255)) {
        HoldHead();
        yaw_last = 0;
      }
			
			/*if(dif<-180)
				dif = dif + 360;
			else if(dif>180)
				dif = dif - 360;
			eulerYawDesired = dif;*/
      eulerYawDesired = headHold;
		}
		else 
			eulerYawDesired = 0;
      
	} 
	else {
		eulerYawDesired = headHold + rc_yaw;
    if(eulerYawDesired>360)
      eulerYawDesired-=360;
    else if(eulerYawDesired<0)
      eulerYawDesired+=360;
	}
  yaw_last = rc_yaw;
  //if((GetFrameCount()%500)==0)
  //    printf("headHoldrc_yaw,Desire,Actual:%f %d %f %f\n",headHold,rc_yaw, eulerYawDesired, eulerYawActual);
#else

#ifdef WSPEED
  if (fabs(rc_yaw)==0) {
		eulerYawDesired = 0;
	} 
	else {
		eulerYawDesired = rc_yaw;
	}
  //if((GetFrameCount()%500)==0)
  //    printf("headHoldrc_yaw,Desire,Actual:%f %d %f %f\n",headHold,rc_yaw, eulerYawDesired, eulerYawActual);
#else
#ifdef WSPEED_DEGREE
  if(checkArm()==false) {
    HoldHead();
    yaw_last = 0;
  }
  if(rc_roll) {
    if (fabs(rc_yaw)==0) {
      eulerYawDesired = 0;
    } 
    else {
      eulerYawDesired = rc_yaw;
    }
  }
  else {
    if ((rc_aux1==255)||(rc_yaw==0)) {
      if(magMode&&(!headFreeMode)) {
        if((yaw_last!=0)&&(rc_aux1==255)) {
          HoldHead();
          yaw_last = 0;
        }
        eulerYawDesired = headHold;
      }
      else 
        eulerYawDesired = 0;
    } 
    else {
		eulerYawDesired = headHold + rc_yaw;
      if(eulerYawDesired>360)
        eulerYawDesired-=360;
      else if(eulerYawDesired<0)
        eulerYawDesired+=360;
    }
    yaw_last = rc_yaw;
  }
#else  
  if(fabs(rc_yaw)<3) {
			
	} 
	else {


		if(magMode)
			HoldHead();
		if(rc_yaw>0)
			eulerYawDesired+=(((float)rc_yaw/100.0f*YAW_DEG_MAX/(RC_YAW_MAX-RC_YAW_MID)));
		else
			eulerYawDesired+=(-((float)rc_yaw/100.0f*YAW_DEG_MAX/(RC_YAW_MIN-RC_YAW_MID)));
    
    if(eulerYawDesired<-180)
				eulerYawDesired = eulerYawDesired + 360;
			else if(eulerYawDesired>180)
				eulerYawDesired = eulerYawDesired - 360;
}
#endif
#endif   
#endif
#endif
	if(rc_roll>RC_ROLL_DEAD_BAND)
		eulerRollDesired = (rc_roll*ROLL_DEG_MAX/(RC_ROLL_MAX-RC_ROLL_MID));
	else if(rc_roll<-RC_ROLL_DEAD_BAND)
		eulerRollDesired = -(rc_roll*ROLL_DEG_MAX/(RC_ROLL_MIN-RC_ROLL_MID));
	else
    eulerRollDesired = 0;
	
  if(nvtGetAHRSID()==0) {
    if(rc_pitch>RC_PITCH_DEAD_BAND)
      eulerPitchDesired = (rc_pitch*PITCH_DEG_MAX/(RC_PITCH_MAX-RC_PITCH_MID));
    else if(rc_pitch<-RC_PITCH_DEAD_BAND)
      eulerPitchDesired = -(rc_pitch*PITCH_DEG_MAX/(RC_PITCH_MIN-RC_PITCH_MID));
    else
      eulerPitchDesired = 0;
  }
  else 
    eulerPitchDesired = rc_pitch;
  
  //if((GetFrameCount()%500)<=1)
  //  printf("eulerPitchDesired,rc_pitch:%f %d\n",eulerPitchDesired,rc_pitch);
    
}
void commanderGetThrust()
{
	int16_t rcData[RC_CHANS];
#ifndef ABROBOT
	char arm_min_thr = RC_THR_ARM - RC_THR_MIN;
#endif
	getRC(rcData);
	//rc_thrust = GetRCThrust();
#ifdef ABROBOT
  Actuator.actuatorThrust = (rcData[PITCH_CH] - RC_PITCH_MID);
  if(Actuator.actuatorThrust!=0) {
    //if((GetFrameCount()%500)==0)
    //  printf("actuatorThrust,motor_enable:%d,%d\n",Actuator.actuatorThrust,motor_enable);
    MotorArm();
  }
  speedDesired = Actuator.actuatorThrust/6;
  
#else
	if(checkArm()) {
		if(rc_thrust<arm_min_thr) {
#if STACK_BARO
			if(!GetAutoLandMode()) {
			rc_thrust = arm_min_thr;
			eulerYawDesired = 0;
			controllerResetAllPID();
		}
#else
			rc_thrust = arm_min_thr;
			eulerYawDesired = 0;
			controllerResetAllPID();
#endif
		}
	}
	else
		rc_thrust = 0;
	
	if(rc_thrust<=0)
		actuatorThrust = 0;
	else
		actuatorThrust = rc_thrust;
#endif
}
bool isArmMinThrottle()
{
	if((int)Actuator.actuatorThrust<=(RC_THR_ARM - RC_THR_MIN))
		return true;
	else
		return false;
}
float GetactuatorThrust()
{
	return Actuator.actuatorThrust;
}
	
uint16_t limitThrust(int32_t value)
{
	if(value > UINT16_MAX) {
		value = UINT16_MAX;
	}
	else if(value < 0) {
		value = 0;
	}

	return (uint16_t)value;
}
#ifdef ABROBOT
static void distributePower(bool On)
{
  int16_t actuatorMotor[2];
  MotorCal_t* MotorCal;

	nvtActuatorFusionFilter(&Actuator);
  MotorCal = GetMotorCal();
	nvtSetMotorSmooth(MotorCal);
	nvtGetActuatorSmooth(actuatorMotor);
  /* ROBOT tilt forward
     Right Motor CCW for balance
  */
  if(actuatorMotor[R]>ACTUATOR_DEAD_ZONE) { 
    BLDC_MOTOR[R].ctrl = CW;
    BLDC_MOTOR[R].pwm = actuatorMotor[R];
    motorPowerM[R] = BLDC_MOTOR[R].pwm;
  } 
  /* ROBOT tilt backward
     Right Motor CW for balance
  */
  else if(actuatorMotor[R]<-ACTUATOR_DEAD_ZONE) { 
    actuatorMotor[R] = -actuatorMotor[R];
    BLDC_MOTOR[R].ctrl = CCW;
    BLDC_MOTOR[R].pwm = actuatorMotor[R];
    motorPowerM[R] = -BLDC_MOTOR[R].pwm;
  } 
  /* Balance in Dead Zone */
  else {
    BLDC_MOTOR[R].ctrl = STOP;
    BLDC_MOTOR[R].pwm = 0;
    motorPowerM[R] = 0;
  }
   /* ROBOT tilt forward
     Left Motor CW for balance
  */
  if(actuatorMotor[L]>ACTUATOR_DEAD_ZONE) { 
    BLDC_MOTOR[L].ctrl = CW;
    BLDC_MOTOR[L].pwm = actuatorMotor[L];
    motorPowerM[L] = BLDC_MOTOR[L].pwm;
  } 
  /* ROBOT tilt backward
     Left Motor CCW for balance
  */
  else if(actuatorMotor[L]<-ACTUATOR_DEAD_ZONE) { 
    actuatorMotor[L] = -actuatorMotor[L];
    BLDC_MOTOR[L].ctrl = CCW;
    BLDC_MOTOR[L].pwm = actuatorMotor[L];
    motorPowerM[L] = -BLDC_MOTOR[L].pwm;
  } 
  /* Balance in Dead Zone */
  else {
    BLDC_MOTOR[L].ctrl = STOP;
    BLDC_MOTOR[L].pwm = 0;
    motorPowerM[L] = 0;
  }
  switch(BLDC_MOTOR[R].ctrl)
  {
    case STOP:
      PE13 = 0;
      PE12 = 0;
    break;
    case CCW:
      PE13 = 0;
      PE12 = 1;
    break;
  case CW:
      PE13 = 1;
      PE12 = 0;
    break;
  default:
    PE13 = 1;
    PE12 = 1;
  }
  
  switch(BLDC_MOTOR[L].ctrl)
  {
    case STOP:
      PD7 = 0;
      PF2 = 0;
    break;
    case CCW:
      PD7 = 0;
      PF2 = 1;
    break;
    case CW:
      PD7 = 1;
      PF2 = 0;
    break;
    default:
      PD7 = 1;
      PF2 = 1;
  }
	if(On) {  
  motorsSetRatio(MOTOR_M1, BLDC_MOTOR[R].pwm);
  motorsSetRatio(MOTOR_M2, BLDC_MOTOR[L].pwm);
}
	else {
	motorsSetRatio(MOTOR_M1, 0);
  motorsSetRatio(MOTOR_M2, 0);
	}
}
static void distributeTiltPower(bool On)
{
  int16_t actuatorMotor[3];
	actuatorMotor[C] = Actuator.actuatorPitch;
	
	  /* ROBOT tilt forward
     Right Motor CCW for balance
  */
  if(actuatorMotor[C]>ACTUATOR_DEAD_ZONE) { 
    BLDC_MOTOR[C].ctrl = CW;
    BLDC_MOTOR[C].pwm = actuatorMotor[C];
    motorPowerM[C] = BLDC_MOTOR[C].pwm;
  } 
  /* ROBOT tilt backward
     Right Motor CW for balance
  */
  else if(actuatorMotor[C]<-ACTUATOR_DEAD_ZONE) { 
    actuatorMotor[C] = -actuatorMotor[C];
    BLDC_MOTOR[C].ctrl = CCW;
    BLDC_MOTOR[C].pwm = actuatorMotor[C];
    motorPowerM[C] = -BLDC_MOTOR[C].pwm;
  } 
  /* Balance in Dead Zone */
  else {
    BLDC_MOTOR[C].ctrl = STOP;
    BLDC_MOTOR[C].pwm = 0;
    motorPowerM[C] = 0;
  }
	  switch(BLDC_MOTOR[C].ctrl)
  {
    case STOP:
      PC5 = 0;
      PC7 = 0;
    break;
    case CCW:
      PC5 = 0;
      PC7 = PD8;
    break;
    case CW:
      PC5 = PD15;
      PC7 = 0;
    break;
    default:
      PC5 = 1;
      PC7 = 1;
  }

	if(On)
    motorsSetRatio(MOTOR_M3, BLDC_MOTOR[C].pwm);
  else
    motorsSetRatio(MOTOR_M3, 0);
}
#else
static void distributePower(int16_t thrust, int16_t roll,
                            int16_t pitch, int16_t yaw)
{
#ifdef HEX6X 
	motorPowerM[0] = limitThrust(thrust - COS_60*roll - COS_30*pitch + yaw);//PIDMIX(-1/2,-7/8,+1); //FRONT_R
	motorPowerM[1] = limitThrust(thrust - roll - yaw);//PIDMIX(-1  ,+0  ,-1); //RIGHT
	motorPowerM[2] = limitThrust(thrust - COS_60*roll + COS_30*pitch + yaw);//PIDMIX(-1/2,+7/8,+1); //REAR_R
	motorPowerM[3] = limitThrust(thrust + COS_60*roll + COS_30*pitch - yaw);//PIDMIX(+1/2,+7/8,-1); //REAR_L
	motorPowerM[4] = limitThrust(thrust + roll + yaw);//PIDMIX(+1  ,+0  ,+1); //LEFT
	motorPowerM[5] = limitThrust(thrust + COS_60*roll - COS_30*pitch - yaw);//PIDMIX(+1/2,-7/8,-1); //FRONT_L
#else
	motorPowerM[0] = limitThrust(thrust - roll - pitch + yaw);
	motorPowerM[1] = limitThrust(thrust - roll + pitch - yaw);
	motorPowerM[2] =  limitThrust(thrust + roll + pitch + yaw);
	motorPowerM[3] =  limitThrust(thrust + roll - pitch - yaw);
#endif

	//printf("%d  %d  %d  %d\n", motorPowerM1>>6, motorPowerM2>>6, motorPowerM3>>6, motorPowerM4>>6);
#ifdef BLDC
	motorPowerM[0] = (motorPowerM[0]) + RC_THR_MIN;
	motorPowerM[1] = (motorPowerM[1]) + RC_THR_MIN;
	motorPowerM[2] = (motorPowerM[2]) + RC_THR_MIN;
	motorPowerM[3] = (motorPowerM[3]) + RC_THR_MIN;
#ifdef HEX6X 
	motorPowerM[4] = (motorPowerM[4]) + RC_THR_MIN;
	motorPowerM[5] = (motorPowerM[5]) + RC_THR_MIN;
#endif
#else
	motorPowerM[0] = (motorPowerM[0])*5+0;
	motorPowerM[1] = (motorPowerM[1])*5+0;
	motorPowerM[2] = (motorPowerM[2])*5+0;
	motorPowerM[3] = (motorPowerM[3])*5+0;
#endif
	//printf("%d  %d  %d  %d\n", motorPowerM1, motorPowerM2, motorPowerM3, motorPowerM4);
	motorsSetRatio(MOTOR_M1, motorPowerM[0]);
	motorsSetRatio(MOTOR_M2, motorPowerM[1]);
	motorsSetRatio(MOTOR_M3, motorPowerM[2]);
	motorsSetRatio(MOTOR_M4, motorPowerM[3]);
#ifdef HEX6X 
	motorsSetRatio(MOTOR_M5, motorPowerM[4]);
	motorsSetRatio(MOTOR_M6, motorPowerM[5]);
#endif
}
#endif
void GetMotorPower(int16_t* MotorPower)
{
  if(GetAHRSReport()==0) {
    MotorPower[0] = (uint16_t)motorPowerM[0];
    MotorPower[1] = (uint16_t)motorPowerM[1];
    MotorPower[2] = BLDC_MOTOR[R].ctrl;
    MotorPower[3] = BLDC_MOTOR[L].ctrl;
  }
  else {
    MotorPower[0] = (uint16_t)motorPowerM[2];
    MotorPower[1] = 0;
    MotorPower[2] = BLDC_MOTOR[C].ctrl;
    MotorPower[3] = 0;
  }

}
bool IsMotorSpin() 
{
	uint8_t i;
	for(i=0; i<MOTOR_NUMBER; i++) {
		if((uint16_t)motorPowerM[i]<MOTOR_START_SPIN)
			return false;
	}
	return true;
}
void GetvSpeed(float* speed)
{
	*speed = vSpeed;
}

void SetvSpeed(float speed)
{
	vSpeed = speed;
}

// Deadzone
float deadband(float value, const float threshold)
{
	if (fabs(value) < threshold) {
		value = 0;
	}
	else if (value > 0) {
		value -= threshold;
	}
	else if (value < 0) {
		value += threshold;
	}
	return value;
}

void stabilizer()
{
	float Euler[3],Ve[3];
#ifdef ABROBOT
#ifdef STACK_HALL
  int16_t FusionSpeed;/*cm/sec*/
#endif
  FusionSpeed = GetFusionSpeed();
  /*if((moveSpeedAvg>-15)&&(moveSpeedAvg<15)) {
    controllerResetYawRatePID();
		//HoldHead();
  }*/
#endif
#if STACK_BARO	
	bool altHold =  GetAltHoldMode();
#endif	
	nvtGetEulerRPY(Euler);
#ifdef ABROBOT
  eulerRollActual = Euler[0];
#ifdef DEGREE
  if(Euler[2]<0) {
    eulerYawActual = Euler[2] + 360;
  }
  else
    eulerYawActual = Euler[2];
#else
  eulerYawActual = Euler[2];
#endif
#else
	eulerRollActual = Euler[0];
  eulerYawActual = Euler[2];
#endif
	eulerPitchActual = Euler[1];
	DetectFlip();
  eulerRollActual= 0;
	
	commanderGetRPY();
	
	nvtGetVelocity(Ve);
	accWZ = Ve[2];
	
	if(checkArm())
		vSpeed=accWZ;
	else
		vSpeed = 0;
	
	//printf("%f  %f  %f \n", eulerRollActual, eulerPitchActual, eulerYawActual);
  /*if(nvtGetAHRSID()==1) {
    if((GetFrameCount()%50)>=1)
      printf("%f  %f  %f \n", eulerRollDesired, eulerPitchDesired, eulerYawDesired);
  }*/
	controllerCorrectAttitudePID(eulerRollActual, eulerPitchActual, eulerYawActual,
				eulerRollDesired, eulerPitchDesired, eulerYawDesired,\
				&rollRateDesired, &pitchRateDesired, &yawRateDesired);
	
#if STACK_BARO
	if(GetSensorInitState()&SENSOR_BARO) {
		if(GetFrameCount()%(int)(1.0f/ALTHOLD_UPDATE_FREQ/getUpdateDT())==0) {
		stabilizerAltHoldUpdate(&actuatorThrust);
		}
		if(!altHold)
			commanderGetThrust();
	}
	else
#endif
	commanderGetThrust();
	
#ifdef WSPEED
	yawRateDesired = -eulerYawDesired;
#else
#ifdef WSPEED_DEGREE
  if(wspeedMode) {
    yawRateDesired = -eulerYawDesired;
  }
#endif
#endif
  /*if(nvtGetAHRSID()==1) {
    if((GetFrameCount()%50)>=1)
      printf("%f  %f  %f \n", rollRateDesired, pitchRateDesired, yawRateDesired);
  }*/
	nvtGetCalibratedGYRO(gyro);
	controllerCorrectRatePID(gyro[0], gyro[1], gyro[2],
				rollRateDesired, pitchRateDesired, yawRateDesired);
  
  controllerCorrectSpeedPID((float)FusionSpeed,speedDesired);
#ifdef ABROBOT
  
  controllerGetActuatorOutput(&Actuator.actuatorRoll, &Actuator.actuatorPitch, &Actuator.actuatorYaw, &Actuator.actuatorSpeed);
  if(nvtGetAHRSID()==1) {
    Actuator.actuatorThrust = 0;
    Actuator.actuatorRoll = 0;
    Actuator.actuatorYaw = 0;
    Actuator.actuatorSpeed = 0;
  }
#else
	controllerGetActuatorOutput(&Actuator.actuatorRoll, &Actuator.actuatorPitch, &Actuator.actuatorYaw);
#endif
  /*if(nvtGetAHRSID()==1) {
    if((GetFrameCount()%40)==1)
      printf("P0:%d ", Actuator.actuatorPitch);
  }*/
	//printf("actuatorThrust:%d",actuatorThrust);

#ifdef ABROBOT
  if((GetSensorCalState()&(1<<GYRO))&&checkArm()) {
    if(nvtGetAHRSID()==0) {
      distributePower(true);
    }
    else
      distributeTiltPower(true);
  }
  else {
    controllerResetAllPID();
    if(nvtGetAHRSID()==0)
      distributePower(false);
    else
      distributeTiltPower(false);
  }
  /*if(nvtGetAHRSID()==1) {
    if((GetFrameCount()%40)==1)
      printf("P1:%d \n", Actuator.actuatorPitch);
  }*/
  /**if((GetFrameCount()%18)==0)
    //printf("Th,Roll,Pitch,Yaw, Speed:%d,%d,%d,%d, %d \n",Actutaor.actuatorThrust,Actutaor.actuatorRoll, Actutaor.actuatorPitch, -Actutaor.actuatorYaw, Actutaor.actuatorSpeed);
    printf("Yaw, Head, Speed:%d,%f,%d\n",Actutaor.actuatorYaw, Actutaor.headHold, Actutaor.actuatorSpeed);*/
#else
  if(GetFrameCount()>(MOTORS_ESC_DELAY*2)) {
    if (actuatorThrust > 0)
        distributePower(true);
    else {
      distributePower(false);
    }
    //printf("Th,Roll,Pitch,Yaw:%d,%d,%d,%d  ",actuatorThrust,actuatorRoll, actuatorPitch, -actuatorYaw);
  }
#endif
}
