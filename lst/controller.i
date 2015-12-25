#line 1 "controller.c"
 










 














 
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



 

#line 29 "controller.c"
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
 
 
 




 
 



 













  


 








#line 46 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


  
  typedef unsigned int size_t;










    



    typedef unsigned short wchar_t;  
#line 75 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { __int64 quot, rem; } lldiv_t;
    


#line 96 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
   



 

   




 
#line 115 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) __int64 atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) __int64 strtoll(const char * __restrict  ,
                               char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned __int64 strtoull(const char * __restrict  ,
                                         char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 415 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 503 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 532 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __pure int abs(int  );
   



 

extern __declspec(__nothrow) __pure div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __pure long int labs(long int  );
   



 




extern __declspec(__nothrow) __pure ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __pure __int64 llabs(__int64  );
   



 




extern __declspec(__nothrow) __pure lldiv_t lldiv(__int64  , __int64  );
   











 
#line 613 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"



 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __pure __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 



 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 867 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


 

#line 30 "controller.c"
#line 1 "retarget.h"














 


void Serial_write(char* id, int num);
void SendChar(int ch);
char Serial_read(void);
char GetChar(void);
int Serial_available(void);
int gpsnumbers(void);
int GPS_available(void);
char GPS_read(void);
void GPS_write(char* id, int num, int delay);


#line 31 "controller.c"
#line 1 "controller.h"
 










 














 
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







#line 31 "controller.h"
#line 1 "pid.h"
 










 














 



#line 32 "pid.h"
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


#line 32 "controller.h"
void controllerInit(void);
_Bool controllerTest(void);

void controllerCorrectAttitudePID(
				float eulerRollActual, float eulerPitchActual, float eulerYawActual,
				float eulerRollDesired, float eulerPitchDesired, float eulerYawDesired,
				float* rollRateDesired, float* pitchRateDesired, float* yawRateDesired);

void controllerCorrectRatePID(
				float rollRateActual, float pitchRateActual, float yawRateActual,
				float rollRateDesired, float pitchRateDesired, float yawRateDesired);


void controllerCorrectSpeedPID(float speedActual,float speedDesired);

void controllerResetAllPID(void);
void controllerResetYawRatePID(void);

void controllerGetActuatorOutput(int16_t* roll, int16_t* pitch, int16_t* yaw, int16_t* speed);




void controllerSetRollPID(float kp, float ki, float kd);

void controllerSetPitchPID(float kp, float ki, float kd);

void controllerSetYawPID(float kp, float ki, float kd);

void controllerSetRollRatePID(float kp, float ki, float kd);

void controllerSetPitchRatePID(float kp, float ki, float kd);

void controllerSetYawRatePID(float kp, float ki, float kd);

void SetPID(void);

_Bool LoadFlashPID(void);

void GetRollPID(float* PID);

void GetPitchPID(float* PID);

void GetYawPID(float* PID);

void GetRollRatePID(float* PID);

void GetPitchRatePID(float* PID);

void GetYawRatePID(float* PID);

void GetAltHoldPID(float* PID);

uint32_t GetUnit32(void);

PidObject* GetAltHoldPIDObj(void);

#line 32 "controller.c"
#line 33 "controller.c"
#line 1 "param.h"














 
#line 19 "param.h"
 
void paramInit(void);
_Bool paramTest(void);

 
struct param_s {
  uint8_t type;
  char * name;
  void * address;
};
























#line 59 "param.h"



 

















#line 34 "controller.c"
#line 1 "FlashCtrl.h"














 
#line 19 "FlashCtrl.h"


#line 29 "FlashCtrl.h"


#line 38 "FlashCtrl.h"





void FlashInit(void);
void UpdateBoardVersion(_Bool);
uint32_t GetBoardVersion(void);
void UpdateFlashCal(int8_t sensorType, _Bool erase);
_Bool GetFlashCal(int8_t sensorType, float* Cal);
void UpdateFlashPID(_Bool erase);
_Bool GetFlashPID(float* PID_FIELD);
void UpdateFlashRxAddress(void);
_Bool GetFlashRxAddress(uint8_t* RX_ADDRESS_FIELD);
void TestFloat(void);
float GetFloatCounter(void);
int32_t float2dw(float f);
float dw2float(int32_t dw);
void FlashControl(void);
#line 35 "controller.c"
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
#line 36 "controller.c"






PidObject pidRollRate;
PidObject pidPitchRate;
PidObject pidYawRate;
PidObject pidRoll;
PidObject pidPitch;
PidObject pidYaw;
PidObject pidAltHold; 

PidObject pidSpeed;


int16_t rollOutput;
int16_t pitchOutput;
int16_t yawOutput;

int16_t speedOutput;



static _Bool isInit;

_Bool LoadFlashPID()
{
	float PID_FIELD[(9 + 9 + 3)],IMU_UPDATE_DT;
	_Bool FlashValid;
	FlashValid = GetFlashPID(PID_FIELD);
	IMU_UPDATE_DT = getUpdateDT();
	if(FlashValid) {
		pidInit(&pidRoll, 0, PID_FIELD[0], PID_FIELD[1], PID_FIELD[2], IMU_UPDATE_DT);
		pidInit(&pidPitch, 0, PID_FIELD[3], PID_FIELD[4], PID_FIELD[5], IMU_UPDATE_DT);
		pidInit(&pidYaw, 0, PID_FIELD[6], PID_FIELD[7], PID_FIELD[8], IMU_UPDATE_DT);
		pidInit(&pidRollRate, 0, PID_FIELD[9], PID_FIELD[10], PID_FIELD[11], IMU_UPDATE_DT);
		pidInit(&pidPitchRate, 0, PID_FIELD[12], PID_FIELD[13], PID_FIELD[14], IMU_UPDATE_DT);
		pidInit(&pidYawRate, 0, PID_FIELD[15], PID_FIELD[16], PID_FIELD[17], IMU_UPDATE_DT);

    pidInit(&pidSpeed, 0, PID_FIELD[18], PID_FIELD[19], PID_FIELD[20], IMU_UPDATE_DT);



		return 1;
	}
	else {
		pidInit(&pidRoll, 0, 39.8f, 5.6f, 0, IMU_UPDATE_DT);
		pidInit(&pidPitch, 0, 39.8f, 5.6f, 0, IMU_UPDATE_DT);
		pidInit(&pidYaw, 0, 0.54f, 0.04f, 0.7f, IMU_UPDATE_DT);
		pidInit(&pidRollRate, 0, 5.8f, 0.1f, 1.0f, IMU_UPDATE_DT);
		pidInit(&pidPitchRate, 0, 5.8f, 0.1f, 1.0f, IMU_UPDATE_DT);
		pidInit(&pidYawRate, 0, 0.54f, 0.04f, 0.7f, IMU_UPDATE_DT);

    pidInit(&pidSpeed, 0, 1, 1, 1, IMU_UPDATE_DT);



		return 0;
	}
}
void controllerInit()
{
	if(isInit)
		return;

	if(LoadFlashPID()==0)
		printf("Load PID from [DEFAULT]\n");
	else
		printf("Load PID from [FLASH]\n");

	 
	pidSetIntegralLimit(&pidRollRate, 100.0);
	pidSetIntegralLimit(&pidPitchRate, 100.0);
	pidSetIntegralLimit(&pidYawRate, 500.0);

	pidSetIntegralLimitLow(&pidRollRate, -100.0);
	pidSetIntegralLimitLow(&pidPitchRate, -100.0);
	pidSetIntegralLimitLow(&pidYawRate, -500.0);

	pidSetIntegralLimit(&pidRoll, 20.0);
	pidSetIntegralLimit(&pidPitch, 20.0);
	pidSetIntegralLimit(&pidYaw, 360.0);
  
	pidSetIntegralLimitLow(&pidRoll, -20.0);
	pidSetIntegralLimitLow(&pidPitch, -20.0);
	pidSetIntegralLimitLow(&pidYaw, -360.0);
#line 141 "controller.c"
	isInit = 1;
}

_Bool controllerTest()
{
	return isInit;
}

void controllerCorrectRatePID(
				float rollRateActual, float pitchRateActual, float yawRateActual,
				float rollRateDesired, float pitchRateDesired, float yawRateDesired)
{
	float pidOut;
	pidSetDesired(&pidRollRate, rollRateDesired);
	pidSetDt(&pidRollRate,getUpdateDT());
	pidOut = pidUpdate(&pidRollRate, rollRateActual, 1);
	(rollOutput = (pidOut< -32768)?-32768:((pidOut>32767)?32767:pidOut) );
	
	pidSetDesired(&pidPitchRate, pitchRateDesired);
	pidSetDt(&pidPitchRate,getUpdateDT());
	pidOut = pidUpdate(&pidPitchRate, pitchRateActual, 1);
	(pitchOutput = (pidOut< -32768)?-32768:((pidOut>32767)?32767:pidOut) );

	
	pidSetDesired(&pidYawRate, yawRateDesired);
	pidSetDt(&pidYawRate,getUpdateDT());
	pidOut = pidUpdate(&pidYawRate, yawRateActual, 1);
	(yawOutput = (pidOut< -32768)?-32768:((pidOut>32767)?32767:pidOut) );
}

void controllerCorrectAttitudePID(
				float eulerRollActual, float eulerPitchActual, float eulerYawActual,
				float eulerRollDesired, float eulerPitchDesired, float eulerYawDesired,
				float* rollRateDesired, float* pitchRateDesired, float* yawRateDesired)
{
	float yawError;
	pidSetDesired(&pidRoll, eulerRollDesired);
	pidSetDt(&pidRoll,getUpdateDT());
	*rollRateDesired = pidUpdate(&pidRoll, eulerRollActual, 1);

	
	pidSetDesired(&pidPitch, eulerPitchDesired);
	pidSetDt(&pidPitch,getUpdateDT());
	*pitchRateDesired = pidUpdate(&pidPitch, eulerPitchActual, 1);

	
	yawError = eulerYawDesired - eulerYawActual;
	if (yawError > 180.0f)
		yawError -= 360.0f;
	else if (yawError < -180.0f)
		yawError += 360.0f;
	
	pidSetError(&pidYaw, yawError);
	pidSetDt(&pidYaw,getUpdateDT());
	*yawRateDesired = pidUpdate(&pidYaw, eulerYawActual, 0);
}

void controllerCorrectSpeedPID(
				float speedActual,
				float speedDesired)
{ 
  float pidOut;
	pidSetDesired(&pidSpeed, speedDesired);
	pidSetDt(&pidSpeed,getUpdateDT());
	pidOut = pidUpdate(&pidSpeed, speedActual, 1);
	(speedOutput = (pidOut< -32768)?-32768:((pidOut>32767)?32767:pidOut) );
}

void controllerResetAllPID(void)
{
	pidReset(&pidRoll);
	pidReset(&pidPitch);
	pidReset(&pidYaw);
	pidReset(&pidRollRate);
	pidReset(&pidPitchRate);
	pidReset(&pidYawRate);

  pidReset(&pidSpeed);

}
void controllerResetYawRatePID(void)
{
  pidReset(&pidYawRate);
}
void controllerSetRollPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidRoll, kp, pidRoll.ki, pidRoll.kd);
	if(ki>=0)
		pidSetPID(&pidRoll, pidRoll.kp, ki, pidRoll.kd);
	if(kd>=0)
		pidSetPID(&pidRoll, pidRoll.kp, pidRoll.ki, kd);
}

void controllerSetPitchPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidPitch, kp, pidPitch.ki, pidPitch.kd);
	if(ki>=0)
		pidSetPID(&pidPitch, pidPitch.kp, ki, pidPitch.kd);
	if(kd>=0)
		pidSetPID(&pidPitch, pidPitch.kp, pidPitch.ki, kd);
}
void controllerSetYawPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidYaw, kp, pidYaw.ki, pidYaw.kd);
	if(ki>=0)
		pidSetPID(&pidYaw, pidYaw.kp, ki, pidYaw.kd);
	if(kd>=0)
		pidSetPID(&pidYaw, pidYaw.kp, pidYaw.ki, kd);
}
void controllerSetRollRatePID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidRollRate, kp, pidRollRate.ki, pidRollRate.kd);
	if(ki>=0)
		pidSetPID(&pidRollRate, pidRollRate.kp, ki, pidRollRate.kd);
	if(kd>=0)
		pidSetPID(&pidRollRate, pidRollRate.kp, pidRollRate.ki, kd);
}
void controllerSetPitchRatePID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidPitchRate, kp, pidPitchRate.ki, pidPitchRate.kd);
	if(ki>=0)
		pidSetPID(&pidPitchRate, pidPitchRate.kp, ki, pidPitchRate.kd);
	if(kd>=0)
		pidSetPID(&pidPitchRate, pidPitchRate.kp, pidPitchRate.ki, kd);
}
void controllerSetYawRatePID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidYawRate, kp, pidYawRate.ki, pidYawRate.kd);
	if(ki>=0)
		pidSetPID(&pidYawRate, pidYawRate.kp, ki, pidYawRate.kd);
	if(kd>=0)
		pidSetPID(&pidYawRate, pidYawRate.kp, pidYawRate.ki, kd);
}
void controllerSetAltHoldPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidAltHold, kp, pidAltHold.ki, pidAltHold.kd);
	if(ki>=0)
		pidSetPID(&pidAltHold, pidAltHold.kp, ki, pidAltHold.kd);
	if(kd>=0)
		pidSetPID(&pidAltHold, pidAltHold.kp, pidAltHold.ki, kd);
}

void controllerSetSpeedPID(float kp, float ki, float kd)
{
	if(kp>=0)
		pidSetPID(&pidSpeed, kp, pidSpeed.ki, pidSpeed.kd);
	if(ki>=0)
		pidSetPID(&pidSpeed, pidSpeed.kp, ki, pidSpeed.kd);
	if(kd>=0)
		pidSetPID(&pidSpeed, pidSpeed.kp, pidSpeed.ki, kd);
}


void controllerGetActuatorOutput(int16_t* roll, int16_t* pitch, int16_t* yaw,int16_t* speed)
{
	*roll = rollOutput;
	*pitch = pitchOutput;
	*yaw = yawOutput;
  *speed = speedOutput;
}
#line 316 "controller.c"
void GetRollPID(float* PID)
{
	PID[0] = pidRoll.kp;
	PID[1] = pidRoll.ki;
	PID[2] = pidRoll.kd;
}
void GetPitchPID(float* PID)
{
	PID[0] = pidPitch.kp;
	PID[1] = pidPitch.ki;
	PID[2] = pidPitch.kd;
}
void GetYawPID(float* PID)
{
	PID[0] = pidYaw.kp;
	PID[1] = pidYaw.ki;
	PID[2] = pidYaw.kd;
}
void GetRollRatePID(float* PID)
{
	PID[0] = pidRollRate.kp;
	PID[1] = pidRollRate.ki;
	PID[2] = pidRollRate.kd;
}
void GetPitchRatePID(float* PID)
{
	PID[0] = pidPitchRate.kp;
	PID[1] = pidPitchRate.ki;
	PID[2] = pidPitchRate.kd;
}
void GetYawRatePID(float* PID)
{
	PID[0] = pidYawRate.kp;
	PID[1] = pidYawRate.ki;
	PID[2] = pidYawRate.kd;
}
void GetAltHoldPID(float* PID)
{
	PID[0] = pidAltHold.kp;
	PID[1] = pidAltHold.ki;
	PID[2] = pidAltHold.kd;
}

void GetSpeedPID(float* PID)
{
	PID[0] = pidSpeed.kp;
	PID[1] = pidSpeed.ki;
	PID[2] = pidSpeed.kd;
}

uint32_t GetUnit32()
{
  char value_s[4];
  value_s[0] = GetChar();
  value_s[1] = GetChar();
  value_s[2] = GetChar();
  value_s[3] = GetChar();
  return atoi(value_s);
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
	return &pidAltHold;
}

PidObject* GetSpeedPIDObj()
{
	return &pidSpeed;
}

void SetPID()
{
	char type = GetChar();
	
	char rpy, pid;
	float valuef;
	if(type=='p') { 
		rpy = GetChar();
		if(rpy=='r') { 
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p')
				controllerSetRollPID(valuef, -1, -1);
			else if(pid=='i') 
				controllerSetRollPID(-1, valuef, -1);
			else if(pid=='d') 
				controllerSetRollPID(-1, -1, valuef);
		}
		else if(rpy=='p') { 
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetPitchPID(valuef, -1, -1);
			else if(pid=='i') 
				controllerSetPitchPID(-1, valuef, -1);
			else if(pid=='d') 
				controllerSetPitchPID(-1, -1, valuef);
		}
		else if(rpy=='y') { 
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
	else if(type=='r') { 
		rpy = GetChar();
		if(rpy=='r') { 
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetRollRatePID((float)valuef, -1, -1);
			else if(pid=='i') 
				controllerSetRollRatePID(-1, (float)valuef, -1);
			else if(pid=='d') 
				controllerSetRollRatePID(-1, -1, (float)valuef);
		}
		else if(rpy=='p') { 
			pid = GetChar();
			valuef = GetPIDfloat();
			if(pid=='p') 
				controllerSetPitchRatePID((float)valuef, -1, -1);
			else if(pid=='i') 
				controllerSetPitchRatePID(-1, (float)valuef, -1);
			else if(pid=='d') 
				controllerSetPitchRatePID(-1, -1, (float)valuef);
		}
		else if(rpy=='y') { 
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

  else if(type=='a') { 
		pid = GetChar();
		valuef = GetPIDfloat();
		if(pid=='p') 
			controllerSetSpeedPID((float)valuef, -1, -1);
		else if(pid=='i') 
			controllerSetSpeedPID(-1, (float)valuef, -1);
		else if(pid=='d') 
			controllerSetSpeedPID(-1, -1, (float)valuef);
	}
#line 501 "controller.c"
	else if(type=='s') { 
		UpdateFlashPID(0);
	}
	else if(type=='l') { 
		LoadFlashPID();
	}
}

