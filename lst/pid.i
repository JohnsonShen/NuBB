#line 1 "pid.c"
 










 














 
#line 1 "pid.h"
 










 














 



#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"



#line 32 "pid.h"
#line 1 "Def.h"














 
#line 1 "Config.h"














 
#line 1 "..\\AHRSLib\\include\\AHRSLib.h"














 
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
 
 





 










#line 26 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 197 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     







     










     











#line 261 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"



 



#line 19 "..\\AHRSLib\\include\\AHRSLib.h"




#line 31 "..\\AHRSLib\\include\\AHRSLib.h"









#line 46 "..\\AHRSLib\\include\\AHRSLib.h"

#line 60 "..\\AHRSLib\\include\\AHRSLib.h"
void nvtGetEulerRPY(float*);
 
void nvtGetQuaternion(float*);
void nvtGetNormAttitude(float*);
void nvtGetNormACC(float*);
void nvtGetMAGHeading(float*);
void nvtGetEulerNormMAG(float*);
void nvtGetNormMAG(float*);
void nvtGetGYRODegree(float*);
void nvtGetVelocity(float* Velocity);
void nvtGetMove(float* Move);
void nvtSetMove(float* Move);
void nvtResetMove(void);

void nvtGetCalibratedGYRO(float*);
void nvtGetCalibratedACC(float*);
void nvtGetCalibratedMAG(float*);

void nvtAHRSInit(void);
void nvtUpdateAHRS(uint8_t UPDATE);
void nvtMillisecondTick(void);
void nvt100usecondTick(void);
void nvtInputSensorRawACC(int16_t *raw);
void nvtInputSensorRawGYRO(int16_t *raw);
void nvtInputSensorRawMAG(int16_t *raw);
void nvtInputSensorRawBARO(int16_t *raw);
void nvtInputSensorRaw9D(int16_t *RawACC, int16_t *RawGYRO, int16_t *RawMAG);

void nvtGetAccZWithoutGravity(float *ZWithoutGravity, float *AccZMag);
void nvtGetAccOffset(float*);
void nvtGetAccScale(float*);
void nvtGetGyroOffset(float* );
void nvtGetGyroScale(float*);
void nvtGetMagCalMatrix(float*);
void nvtSetAccOffset(float* AccMean);
void nvtSetAccScale(float* AccScale);
void nvtSetGyroOffset(float* GyroMean);
void nvtSetGyroScale(float* GyroScale);
void nvtSetGYRODegPLSB(float DPLSB);
void nvtSetAccG_PER_LSB(float G_PER_LSB);
void nvtSetMagCalMatrix(float* MagCalMatrix);

void nvtGetSensorRawACC(int16_t *raw);
void nvtGetSensorRawGYRO(int16_t *raw);
void nvtGetSensorRawMAG(int16_t *raw);
void nvtGetSensorRawBARO(uint16_t *raw);
void nvtGetSensorRaw9D(int16_t *RawACC, int16_t *RawGYRO, int16_t *RawMAG);


void nvtCalACCInit(void);
signed char nvtCalACCBufferFill(int8_t Dir);

signed char nvtGyroScaleCalibrate(int8_t axis);
signed char nvtGyroCenterCalibrate(void);
signed char nvtGyroIsSteady(void);
void nvtCalGyroInit(char axis);

signed char nvtCalMAGBufferFill(void);
void nvtCalMAGInit(void);
void nvtSetMagGaussPLSB(float);
uint8_t nvtGetMagCalQFactor(void);
void nvtSmoothSensorRawData(unsigned char enable, char sensor);



#line 19 "Config.h"



#line 28 "Config.h"
 
 
 






#line 19 "Def.h"
#line 20 "Def.h"
#line 35 "Def.h"

#line 56 "Def.h"
 
 
 

 
 
 

#line 112 "Def.h"
 
 
 

#line 132 "Def.h"

#line 145 "Def.h"







#line 33 "pid.h"
#line 134 "pid.h"

#line 163 "pid.h"






typedef struct
{
  float desired;     
  float error;        
  float prevError;    
  float integ;        
  float deriv;        
  float kp;           
  float ki;           
  float kd;           
  float outP;         
  float outI;         
  float outD;         
  float iLimit;       
  float iLimitLow;    
  float dt;           
} PidObject;









 
void pidInit(PidObject* pid, const float desired, const float kp,
             const float ki, const float kd, const float dt);






 
void pidSetIntegralLimit(PidObject* pid, const float limit);

void pidSetIntegralLimitLow(PidObject* pid, const float limit);





 
void pidReset(PidObject* pid);









 
float pidUpdate(PidObject* pid, const float measured, const _Bool updateError);






 
void pidSetDesired(PidObject* pid, const float desired);




 
float pidGetDesired(PidObject* pid);




 
_Bool pidIsActive(PidObject* pid);






 
void pidSetError(PidObject* pid, const float error);






 
void pidSetKp(PidObject* pid, const float kp);






 
void pidSetKi(PidObject* pid, const float ki);






 
void pidSetKd(PidObject* pid, const float kd);






 
void pidSetDt(PidObject* pid, const float dt);

void pidSetPID(PidObject* pid, float kp, float ki, float kd);
float constrain(float value, const float minVal, const float maxVal);


#line 29 "pid.c"
#line 30 "pid.c"

void pidInit(PidObject* pid, const float desired, const float kp,
             const float ki, const float kd, const float dt)
{
  pid->error     = 0;
  pid->prevError = 0;
  pid->integ     = 0;
  pid->deriv     = 0;
  pid->desired = desired;
  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
  pid->iLimit    = 5000.0;
  pid->iLimitLow = -5000.0;
  pid->dt        = dt;
}

float pidUpdate(PidObject* pid, const float measured, const _Bool updateError)
{
    float output;

    if (updateError)
    {
        pid->error = pid->desired - measured;
    }

    pid->integ += pid->error * pid->dt;
    if (pid->integ > pid->iLimit)
    {
        pid->integ = pid->iLimit;
    }
    else if (pid->integ < pid->iLimitLow)
    {
        pid->integ = pid->iLimitLow;
    }

    pid->deriv = (pid->error - pid->prevError) / pid->dt/50;

    pid->outP = pid->kp * pid->error;
    pid->outI = pid->ki * pid->integ;
    pid->outD = pid->kd * pid->deriv;

    output = pid->outP + pid->outI + pid->outD;

    pid->prevError = pid->error;

    return output;
}

void pidSetIntegralLimit(PidObject* pid, const float limit) {
    pid->iLimit = limit;
}


void pidSetIntegralLimitLow(PidObject* pid, const float limitLow) {
    pid->iLimitLow = limitLow;
}

void pidReset(PidObject* pid)
{
  
  
  pid->integ     = 0;
  pid->deriv     = 0;
}

void pidSetPID(PidObject* pid, float kp, float ki, float kd)
{
  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
}

void pidSetError(PidObject* pid, const float error)
{
  pid->error = error;
}

void pidSetDesired(PidObject* pid, const float desired)
{
  pid->desired = desired;
}

float pidGetDesired(PidObject* pid)
{
  return pid->desired;
}

_Bool pidIsActive(PidObject* pid)
{
  _Bool isActive = 1;

  if (pid->kp < 0.0001f && pid->ki < 0.0001f && pid->kd < 0.0001f)
  {
    isActive = 0;
  }

  return isActive;
}

void pidSetKp(PidObject* pid, const float kp)
{
  pid->kp = kp;
}

void pidSetKi(PidObject* pid, const float ki)
{
  pid->ki = ki;
}

void pidSetKd(PidObject* pid, const float kd)
{
  pid->kd = kd;
}
void pidSetDt(PidObject* pid, const float dt) {
    pid->dt = dt;
}
float constrain(float value, const float minVal, const float maxVal)
{
  return ((maxVal) < (((minVal) > (value) ? (minVal) : (value))) ? (maxVal) : (((minVal) > (value) ? (minVal) : (value))));
}

