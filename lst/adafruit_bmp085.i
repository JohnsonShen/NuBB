#line 1 "Adafruit_BMP085.c"
















 














 
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"




 





 












 








 






#line 48 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"

#line 62 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"

   




 















 
#line 93 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"











 





extern __softfp unsigned __ARM_dcmp4(double  , double  );
extern __softfp unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __softfp int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __softfp int __ARM_fpclassify(double  );
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
__inline __declspec(__nothrow) __softfp int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
__inline __declspec(__nothrow) __softfp int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
__inline __declspec(__nothrow) __softfp int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

__inline __declspec(__nothrow) __softfp int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
__inline __declspec(__nothrow) __softfp int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     








#line 211 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"



   
  typedef float float_t;
  typedef double double_t;







extern const int math_errhandling;



extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __pure double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __pure double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    __inline double _sqrt(double __x) { return sqrt(__x); }


    __inline float _sqrtf(float __x) { return __sqrtf(__x); }



    



 

extern __declspec(__nothrow) __pure double ceil(double  );
    
    
extern __declspec(__nothrow) __pure double fabs(double  );
    
    

extern __declspec(__nothrow) __pure double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
__inline __declspec(__nothrow) __pure double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
__inline __declspec(__nothrow) __pure float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 445 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __pure double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __pure float _fabsf(float);  
__inline __declspec(__nothrow) __pure float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __pure float ceilf(float  );
extern __declspec(__nothrow) __pure float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );



#line 825 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"





#line 980 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"











#line 1182 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"



 

#line 34 "Adafruit_BMP085.c"
#line 1 "Adafruit_BMP085.h"
















 














 
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
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"



#line 20 "Def.h"
#line 35 "Def.h"

#line 56 "Def.h"
 
 
 

 
 
 

#line 112 "Def.h"
 
 
 

#line 132 "Def.h"

#line 145 "Def.h"







#line 36 "Adafruit_BMP085.h"




#line 55 "Adafruit_BMP085.h"








_Bool begin(uint8_t mode );  
float readTemperature(int32_t UT);
int32_t readPressure(void);
int32_t readSealevelPressure(float altitude_meters );
float readAltitude(float sealevelPressure , float pressure); 
uint16_t readRawTemperature(void);
uint32_t readRawPressure(void);
void TriggerRawTemperature(void);
void TriggerRawPressure(void);
  
int32_t computeB5(int32_t UT);
uint8_t read8(uint8_t addr, uint16_t timeout);
uint16_t read16(uint8_t addr);
void write8(uint8_t addr, uint8_t data);
#line 35 "Adafruit_BMP085.c"
#line 1 "I2Cdev.h"
 











 














 
#line 32 "I2Cdev.h"
void I2C_Init(void);
int8_t I2C_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data, uint16_t timeout);
int8_t I2C_readByte(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t timeout);
int8_t I2C_readBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data, uint16_t timeout);
int8_t I2C_readBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data, uint16_t timeout);
int8_t I2C_readWords(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint16_t *data, uint16_t timeout);
_Bool I2C_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data);
_Bool I2C_writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data);
_Bool I2C_writeBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data);
_Bool I2C_writeBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data);
_Bool I2C_writeWord(uint8_t devAddr, uint8_t regAddr, uint16_t data);
#line 36 "Adafruit_BMP085.c"
#line 1 "Timer_Ctrl.h"














 
#line 19 "Timer_Ctrl.h"
#line 25 "Timer_Ctrl.h"


void ChronographSet(char Chron);
void ChronographStart(char Chron);
int32_t ChronographRead(char Chron);
int getTickCount(void);
void SetTickSSVRC(uint8_t tick);
void DelayLoop(unsigned short delay);
void DelayUsec(unsigned int usec);
void DelayMsec(unsigned short msec);
void setup_system_tick(uint32_t sampleRate);
void IncFrameCount(int inc);
uint32_t GetFrameCount(void);
uint32_t micros(void);
uint32_t millis(void);
void TIMER_Init(void);
void TIMER_Enable(char enable);
float getUpdateDT(void);
#line 37 "Adafruit_BMP085.c"
#line 1 "Sensors.h"














 
#line 19 "Sensors.h"

#line 27 "Sensors.h"

typedef struct {
	int16_t rawACC[3];
	int16_t rawGYRO[3];
	int16_t rawMAG[3];
	int16_t rawBARO[2];



	float Altitude;

  int16_t moveSpeed[2];

}Sensor_T;

typedef struct {
	_Bool ACC_Done;
	_Bool GYRO_Done;
	_Bool MAG_Done;
	_Bool BARO_Done;
	uint8_t BARO_BRAND;
	int32_t BARO_BasePressure;
}SensorInit_T;
typedef struct {
	_Bool ACC_FLASH;
	_Bool GYRO_FLASH;
	_Bool MAG_FLASH;
	uint8_t MAG_QFACTOR;
}CAL_FLASH_STATE_T;
#line 77 "Sensors.h"

#line 101 "Sensors.h"
void SensorsRead(char,char);
void SensorsDynamicCalibrate(char SensorType);
void temperatureRead(float *temperatureOut);
void SensorsInit(void);
char GetSensorInitState(void);
char GetSensorCalState(void);
void SetFlashState(CAL_FLASH_STATE_T* State);
void SensorInitMAG(void);
CAL_FLASH_STATE_T* GetFlashState(void);
#line 117 "Sensors.h"
int16_t GetMoveSpeed(void);
int16_t GetMoveSpeedL(void);
int16_t GetMoveSpeedR(void);
#line 38 "Adafruit_BMP085.c"
