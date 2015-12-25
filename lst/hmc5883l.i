#line 1 "hmc5883l.c"



















 
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
 
 
 





 






 













#line 38 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"


  
  typedef unsigned int size_t;    








 
 

 
  typedef struct __va_list __va_list;





   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 129 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 948 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"



 

#line 22 "hmc5883l.c"
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
 
 
 






#line 23 "hmc5883l.c"
#line 1 "hmc5883l.h"



















 
#line 24 "hmc5883l.h"
#line 1 "Def.h"














 
#line 19 "Def.h"
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"



#line 20 "Def.h"
#line 35 "Def.h"

#line 56 "Def.h"
 
 
 

 
 
 

#line 112 "Def.h"
 
 
 

#line 132 "Def.h"

#line 145 "Def.h"







#line 25 "hmc5883l.h"



#line 41 "hmc5883l.h"

#line 48 "hmc5883l.h"






#line 61 "hmc5883l.h"








#line 77 "hmc5883l.h"











#line 108 "hmc5883l.h"

_Bool hmc5883lInit(void);
_Bool hmc5883lTestConnection(void);
_Bool hmc5883lSelfTest(void);
_Bool hmc5883lEvaluateSelfTest(int16_t min, int16_t max, int16_t value, char* string);


uint8_t hmc5883lGetSampleAveraging(void);
void hmc5883lSetSampleAveraging(uint8_t averaging);
uint8_t hmc5883lGetDataRate(void);
void hmc5883lSetDataRate(uint8_t rate);
uint8_t hmc5883lGetMeasurementBias(void);
void hmc5883lSetMeasurementBias(uint8_t bias);


uint8_t hmc5883lGetGain(void);
void hmc5883lSetGain(uint8_t gain);


uint8_t hmc5883lGetMode(void);
void hmc5883lSetMode(uint8_t mode);


void hmc5883lGetHeading(int16_t *x, int16_t *y, int16_t *z);
int16_t hmc5883lGetHeadingX(void);
int16_t hmc5883lGetHeadingY(void);
int16_t hmc5883lGetHeadingZ(void);


_Bool hmc5883lGetLockStatus(void);
_Bool hmc5883lGetReadyStatus(void);


uint8_t hmc5883lGetIDA(void);
uint8_t hmc5883lGetIDB(void);
uint8_t hmc5883lGetIDC(void);


void hmc5883lGetRatioFactor(float *x, float *y, float *z);

#line 24 "hmc5883l.c"
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
#line 25 "hmc5883l.c"
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
#line 26 "hmc5883l.c"
static uint8_t devAddr;
static uint8_t buffer[6];
static uint8_t mode;
static float magCal[3];




 
void hmc5883lGetRatioFactor(float *x, float *y, float *z)
{
  *x = magCal[0];
  *y = magCal[1];
  *z = magCal[2];
}







 
_Bool hmc5883lInit(void)
{
	_Bool connect;

  
  devAddr = 0x1E;

  connect = hmc5883lTestConnection();
  
  if(!connect)
    return 0;

  hmc5883lSetMode(0x01);
  
  I2C_writeByte(devAddr, 0x00,
      (0x03 << (6 - 2 + 1)) |
      (0x04 << (4 - 3 + 1)) |
      (0x00 << (1 - 2 + 1)));

  
  hmc5883lSetGain(0x03);

  return 1;
}




 
_Bool hmc5883lTestConnection()
{
  if (I2C_readBytes(devAddr, 0x0A, 3, buffer,1))
  {
    return (buffer[0] == 'H' && buffer[1] == '4' && buffer[2] == '3');
  }

  return 0;
}



 
_Bool hmc5883lSelfTest()
{
  _Bool testStatus = 1;
  int16_t mxp, myp, mzp;  
  int16_t mxn, myn, mzn;  
  struct
  {
    uint8_t configA;
    uint8_t configB;
    uint8_t mode;
  } regSave;

  
  if (I2C_readBytes(devAddr, 0x00, sizeof(regSave), (uint8_t *)&regSave,0) == 0)
  {
    
    return 0;
  }

  
  hmc5883lSetGain(0x03);

  
  I2C_writeByte(devAddr, 0x00,
      (0x00 << (6 - 2 + 1)) |
      (0x04 << (4 - 3 + 1)) |
      (0x01 << (1 - 2 + 1)));

   
  hmc5883lSetMode(0x01);
  DelayMsec(250);
  hmc5883lGetHeading(&mxp, &myp, &mzp);
  magCal[0] = 1.16f/mxp;
  magCal[1] = 1.16f/myp;
  magCal[2] = 1.08f/mzp;

  
  I2C_writeByte(devAddr, 0x00,
      (0x00 << (6 - 2 + 1)) |
      (0x04 << (4 - 3 + 1)) |
      (0x02 << (1 - 2 + 1)));

   
  hmc5883lSetMode(0x01);
  DelayMsec(250);
  hmc5883lGetHeading(&mxn, &myn, &mzn);

  if (hmc5883lEvaluateSelfTest((int32_t)((int32_t)(1.16f * 660) - ((int32_t)(1.16f * 660) * 0.2f)), (int32_t)((int32_t)(1.16f * 660) + ((int32_t)(1.16f * 660) * 0.2f)), mxp, "pos X") &&
      hmc5883lEvaluateSelfTest((int32_t)((int32_t)(1.16f * 660) - ((int32_t)(1.16f * 660) * 0.2f)), (int32_t)((int32_t)(1.16f * 660) + ((int32_t)(1.16f * 660) * 0.2f)), myp, "pos Y") &&
      hmc5883lEvaluateSelfTest((int32_t)((int32_t)(1.08f * 660) - ((int32_t)(1.08f * 660) * 0.2f)), (int32_t)((int32_t)(1.08f * 660) + ((int32_t)(1.08f * 660) * 0.2f)), mzp, "pos Z") &&
      hmc5883lEvaluateSelfTest(-(int32_t)((int32_t)(1.16f * 660) + ((int32_t)(1.16f * 660) * 0.2f)), -(int32_t)((int32_t)(1.16f * 660) - ((int32_t)(1.16f * 660) * 0.2f)), mxn, "neg X") &&
      hmc5883lEvaluateSelfTest(-(int32_t)((int32_t)(1.16f * 660) + ((int32_t)(1.16f * 660) * 0.2f)), -(int32_t)((int32_t)(1.16f * 660) - ((int32_t)(1.16f * 660) * 0.2f)), myn, "neg Y") &&
      hmc5883lEvaluateSelfTest(-(int32_t)((int32_t)(1.08f * 660) + ((int32_t)(1.08f * 660) * 0.2f)), -(int32_t)((int32_t)(1.08f * 660) - ((int32_t)(1.08f * 660) * 0.2f)), mzn, "neg Z"))
  {
    printf("HMC5883L Self test [OK].\n");
    printf("Ratio Factor:%f, %f, %f\n",1.0f/magCal[0],1.0f/magCal[1],1.0f/magCal[2]);
  }
  else
  {
    testStatus = 0;
  }

  
  if (I2C_writeBytes(devAddr, 0x00, sizeof(regSave), (uint8_t *)&regSave) == 0)
  {
    
    return 0;
  }

  return testStatus;
}







 
_Bool hmc5883lEvaluateSelfTest(int16_t min, int16_t max, int16_t value, char* string)
{
  if (value < min || value > max)
  {
    printf("Self test %s [FAIL]. low: %d, high: %d, measured: %d\n",
                string, min, max, value);
    return 0;
  }
  return 1;
}









 
uint8_t hmc5883lGetSampleAveraging()
{
  I2C_readBits(devAddr, 0x00, 6, 2, buffer,0);
  return buffer[0];
}





 
void hmc5883lSetSampleAveraging(uint8_t averaging)
{
  I2C_writeBits(devAddr, 0x00, 6, 2, averaging);
}






















 
uint8_t hmc5883lGetDataRate()
{
  I2C_readBits(devAddr, 0x00, 4, 3, buffer,0);
  return buffer[0];
}







 
void hmc5883lSetDataRate(uint8_t rate)
{
  I2C_writeBits(devAddr, 0x00, 4, 3, rate);
}






 
uint8_t hmc5883lGetMeasurementBias()
{
  I2C_readBits(devAddr, 0x00, 1, 2, buffer,0);
  return buffer[0];
}






 
void hmc5883lSetMeasurementBias(uint8_t bias)
{
  I2C_writeBits(devAddr, 0x00, 1, 2, bias);
}

























 
uint8_t hmc5883lGetGain()
{
  I2C_readBits(devAddr, 0x01, 7, 3, buffer,0);
  return buffer[0];
}






 
void hmc5883lSetGain(uint8_t gain)
{
  
  
  
  I2C_writeByte(devAddr, 0x01, gain << (7 - 3 + 1));
}
























 
uint8_t hmc5883lGetMode()
{
  I2C_readBits(devAddr, 0x02, 1, 2, buffer,0);
  return buffer[0];
}









 
void hmc5883lSetMode(uint8_t newMode)
{
  
  
  
  I2C_writeByte(devAddr, 0x02, mode << (1 - 2 + 1));
  mode = newMode;
}













 
void hmc5883lGetHeading(int16_t *x, int16_t *y, int16_t *z)
{
  I2C_readBytes(devAddr, 0x03, 6, buffer,0);
  if (mode == 0x01) I2C_writeByte(devAddr, 0x02, 0x01 << (1 - 2 + 1));
  *x = (((int16_t)buffer[0]) << 8) | buffer[1];
  *y = (((int16_t)buffer[4]) << 8) | buffer[5];
  *z = (((int16_t)buffer[2]) << 8) | buffer[3];
}



 
int16_t hmc5883lGetHeadingX()
{
  
  
  I2C_readBytes(devAddr, 0x03, 6, buffer,0);
  if (mode == 0x01) I2C_writeBytes(devAddr, 0x02, 0x01 << (1 - 2 + 1),0);
  return (((int16_t)buffer[0]) << 8) | buffer[1];
}



 
int16_t hmc5883lGetHeadingY()
{
  
  
  I2C_readBytes(devAddr, 0x03, 6, buffer,0);
  if (mode == 0x01) I2C_writeByte(devAddr, 0x02, 0x01 << (1 - 2 + 1));
  return (((int16_t)buffer[4]) << 8) | buffer[5];
}



 
int16_t hmc5883lGetHeadingZ()
{
  
  
  I2C_readBytes(devAddr, 0x03, 6, buffer,0);
  if (mode == 0x01) I2C_writeByte(devAddr, 0x02, 0x01 << (1 - 2 + 1));
  return (((int16_t)buffer[2]) << 8) | buffer[3];
}













 
_Bool hmc5883lGetLockStatus()
{
  I2C_readBit(devAddr, 0x09, 1, buffer,0);
  return buffer[0];
}









 
_Bool hmc5883lGetReadyStatus()
{
  I2C_readBit(devAddr, 0x09, 0, buffer,0);
  return buffer[0];
}





 
uint8_t hmc5883lGetIDA()
{
  I2C_readByte(devAddr, 0x0A, buffer,0);
  return buffer[0];
}


 
uint8_t hmc5883lGetIDB()
{
  I2C_readByte(devAddr, 0x0B, buffer,0);
  return buffer[0];
}


 
uint8_t hmc5883lGetIDC()
{
  I2C_readByte(devAddr, 0x0C, buffer,0);
  return buffer[0];
}
