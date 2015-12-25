#line 1 "Sensors.c"














 
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



 

#line 17 "Sensors.c"
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



 

#line 18 "Sensors.c"
#line 1 "MPU6050.h"
























 












 
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"



#line 40 "MPU6050.h"
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



 



#line 43 "MPU6050.h"
#line 1 "Def.h"














 
#line 1 "Config.h"














 
#line 1 "..\\AHRSLib\\include\\AHRSLib.h"














 
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







#line 44 "MPU6050.h"

#line 54 "MPU6050.h"

#line 165 "MPU6050.h"














#line 187 "MPU6050.h"

#line 195 "MPU6050.h"









#line 211 "MPU6050.h"






#line 223 "MPU6050.h"

#line 232 "MPU6050.h"

#line 239 "MPU6050.h"

#line 256 "MPU6050.h"

#line 266 "MPU6050.h"

#line 275 "MPU6050.h"

#line 284 "MPU6050.h"

#line 293 "MPU6050.h"













#line 314 "MPU6050.h"



#line 323 "MPU6050.h"

#line 331 "MPU6050.h"

#line 338 "MPU6050.h"





#line 349 "MPU6050.h"






#line 363 "MPU6050.h"

#line 370 "MPU6050.h"

#line 378 "MPU6050.h"

#line 387 "MPU6050.h"

































void MPU6050_getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);


#line 620 "MPU6050.h"

#line 812 "MPU6050.h"
int16_t MPU6050_getTemperature(void);
_Bool MPU6050_initialize(void);
void MPU6050_getAcceleration(int16_t* x, int16_t* y, int16_t* z);
void MPU6050_getRotation(int16_t* x, int16_t* y, int16_t* z);
_Bool MPU6050_testConnection(void);
#line 23 "Sensors.c"
#line 1 "hmc5883l.h"



















 
#line 24 "hmc5883l.h"
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

#line 24 "Sensors.c"
#line 1 "ak8975.h"






















 














 
#line 40 "ak8975.h"









#line 68 "ak8975.h"


















void AK8975_address(void);
_Bool AK8975_testConnection(void);


uint8_t AK8975_getDeviceID(void);
        

uint8_t AK8975_getInfo(void);
        
_Bool AK8975_getDataReady(void);

void AK8975_getHeading(int16_t *x, int16_t *y, int16_t *z);
int16_t AK8975_getHeadingX(void);
int16_t AK8975_getHeadingY(void);
int16_t AK8975_getHeadingZ(void);
        

_Bool AK8975_getOverflowStatus(void);
_Bool AK8975_getDataError(void);


uint8_t AK8975_getMode(void);
void AK8975_setMode(uint8_t mode);
void AK8975_reset(void);
        

void AK8975_setSelfTest(_Bool enabled);
        
      

void AK8975_getAdjustment(int8_t *x, int8_t *y, int8_t *z);
void AK8975_setAdjustment(int8_t x, int8_t y, int8_t z);
uint8_t AK8975_getAdjustmentX(void);
void AK8975_setAdjustmentX(uint8_t x);
uint8_t AK8975_getAdjustmentY(void);
void AK8975_setAdjustmentY(uint8_t y);
uint8_t AK8975_getAdjustmentZ(void);
void AK8975_setAdjustmentZ(uint8_t z);
_Bool AK8975_initialize(void);
#line 25 "Sensors.c"
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
#line 35 "Sensors.c"
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
#line 36 "Sensors.c"
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
#line 37 "Sensors.c"
#line 1 "AltHold.h"














 
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


#line 19 "AltHold.h"
typedef struct ALT_STATE {
	float altHoldPIDVal;
	float altHoldChange;
	float altHoldTarget;
	float asl;
}ALTHOLD_STATE_T;
_Bool GetAltHoldMode(void);
void stabilizerAltHoldUpdate(int16_t *);
_Bool GetAltHoldMode(void);
void SetAltHoldPIDObj(PidObject* PIDObj);
void SetCalibratingB(uint8_t c);
ALTHOLD_STATE_T* GetAltHoldState(void);
float getAslSpeed(void);
float getAltHoldPIDVal(void);
float getAccFuse(void);
_Bool GetAutoLandMode(void);
_Bool GetNearLand(void);
#line 38 "Sensors.c"

#line 1 "LED.h"














 






#line 30 "LED.h"

void Laser_init(void);
void LED_Init(void);
void UpdateLED(void);
void led_arm_state(char state);
void led_mag_state(char state);
char GetLedState(void);
#line 40 "Sensors.c"
#line 1 "Report.h"














 



#line 35 "Report.h"






extern char report_mode;
extern char report_format;
extern char stream_mode;
void report_sensors(void);
void report_status(void);
void CheckVersion(void);
#line 41 "Sensors.c"
#line 1 "Hall.h"
 










 














 



#line 32 "Hall.h"
#line 33 "Hall.h"
extern void HALL_getSpeed(int16_t* moveSpeed);


#line 42 "Sensors.c"
#line 1 "motors.h"

















 
#line 22 "motors.h"
 
#line 32 "motors.h"

#line 39 "motors.h"

#line 54 "motors.h"
typedef struct {
  uint8_t ctrl;
  uint16_t pwm;
} BLDC_MOTOR_T;
#line 67 "motors.h"


void motorsInit(void);
void motorsSetRatio(int id, uint16_t ratio);
int motorsGetRatio(int id);
void motorsStart(void);

void ABRobotMotorInit(void);
typedef struct  {
  float MotorOffset[2];
  float MotorScale[2];
}MotorCal_t;
void SetMotorCal(void);
MotorCal_t* GetMotorCal(void);



#line 43 "Sensors.c"
SensorInit_T SensorInitState = {0,0,0};
SensorInit_T SensorCalState  = {0,0,0,0};
CAL_FLASH_STATE_T CalFlashState =  {0,0,0,0xff};
Sensor_T Sensor;
float GyroScale[3];
float AccScale[3];
float GyroOffset[3];
float AccOffset[3];
float MagCalMatrix[10];




int BaroDoTick;
int BaroDoState;

CAL_FLASH_STATE_T* GetFlashState()
{
	return &CalFlashState;
}
void SetFlashState(CAL_FLASH_STATE_T* State)
{
	CalFlashState.ACC_FLASH = State->ACC_FLASH;
	CalFlashState.GYRO_FLASH = State->GYRO_FLASH;
	CalFlashState.MAG_FLASH = State->MAG_FLASH;
	CalFlashState.MAG_QFACTOR = State->MAG_QFACTOR;
}
void temperatureRead(float *temperatureOut)
{


	*temperatureOut = (MPU6050_getTemperature()-512)/340+34;
	*temperatureOut = *temperatureOut*25/20;


}





 
void SensorInitACC()
{
	float Cal[6];
	_Bool FlashValid;
	
	if(!SensorInitState.ACC_Done) {

		SensorInitState.ACC_Done = MPU6050_initialize();
		SensorInitState.GYRO_Done = SensorInitState.ACC_Done;

	}
	if(SensorInitState.ACC_Done) {
		printf("ACC connect - [OK]\n");
		FlashValid = GetFlashCal((1<<0), Cal);
		if(FlashValid) {
			CalFlashState.ACC_FLASH = 1;
			AccOffset[0] = Cal[0];
			AccOffset[1] = Cal[1];
			AccOffset[2] = Cal[2];
			AccScale[0]  = Cal[3];
			AccScale[1]  = Cal[4];
			AccScale[2]  = Cal[5];
			printf("ACC calibration from - [FLASH]\n");
			
		}
		else {
			AccOffset[0] = 0;
			AccOffset[1] = 0;
			AccOffset[2] = 0;
			AccScale[0] = (float)((2 * 8) / 65536.0);
			AccScale[1] = (float)((2 * 8) / 65536.0);
			AccScale[2] = (float)((2 * 8) / 65536.0);
			printf("ACC calibration from - [DEFAULT]\n");
		}
	printf("Offset: %f  %f  %f\n", AccOffset[0], AccOffset[1], AccOffset[2]);
	printf("Scale: %f  %f  %f\n", AccScale[0], AccScale[1], AccScale[2]);
	nvtSetAccScale(AccScale);
	nvtSetAccOffset(AccOffset);
		nvtSetAccG_PER_LSB((float)((2 * 8) / 65536.0));
}
	else
		printf("ACC connect - [FAIL]\n");
}
void SensorInitGYRO()
{
	float Cal[6];
	_Bool FlashValid;
	if(!SensorInitState.GYRO_Done) {

		SensorInitState.GYRO_Done = MPU6050_initialize();
		SensorInitState.ACC_Done = SensorInitState.GYRO_Done;

	}

	if(SensorInitState.GYRO_Done) {
		printf("GYRO connect - [OK]\n");
		FlashValid = GetFlashCal((1<<1), Cal);
		
		if(FlashValid) {
			CalFlashState.GYRO_FLASH = 1;
			GyroOffset[0] = Cal[0];
			GyroOffset[1] = Cal[1];
			GyroOffset[2] = Cal[2];
			GyroScale[0]  = Cal[3]*(float)((2 * 2000.0) / 65536.0);
			GyroScale[1]  = Cal[4]*(float)((2 * 2000.0) / 65536.0);
			GyroScale[2]  = Cal[5]*(float)((2 * 2000.0) / 65536.0);
			printf("GYRO calibration from [FLASH]\n");
			
		}
		else {
			GyroOffset[0] = 0;
			GyroOffset[1] = 0;
			GyroOffset[2] = 0;
			GyroScale[0] = (float)((2 * 2000.0) / 65536.0);
			GyroScale[1] = (float)((2 * 2000.0) / 65536.0);
			GyroScale[2] = (float)((2 * 2000.0) / 65536.0);
			printf("GYRO calibration from - [DEFAULT]\n");
		}
		printf("Offset: %f  %f  %f\n", GyroOffset[0], GyroOffset[1], GyroOffset[2]);
		printf("Scale: %f  %f  %f\n", GyroScale[0], GyroScale[1], GyroScale[2]);
		nvtSetGyroScale(GyroScale);
		nvtSetGyroOffset(GyroOffset);
		nvtSetGYRODegPLSB((float)((2 * 2000.0) / 65536.0));
	}
	else
		printf("GYRO connect - [FAIL]\n");
}
void SensorInitMAG()
{
	float Cal[10 + 1];
	_Bool FlashValid;
	int i;
	
	if(!SensorInitState.MAG_Done) {
#line 187 "Sensors.c"
	}
	
	if(SensorInitState.MAG_Done) {
		if (report_format == 0) 
		printf("MAG connect - [OK]\n");
		FlashValid = GetFlashCal((1<<2), Cal);
		
		if(FlashValid) {
			CalFlashState.MAG_FLASH = 1;
			for(i=0;i<10;i++)
				MagCalMatrix[i] = Cal[i];
			CalFlashState.MAG_QFACTOR = Cal[i];
			if (report_format == 0) 
			printf("MAG calibration from - [FLASH], Q:%d\n",CalFlashState.MAG_QFACTOR);
		}
		else {
			








 
			for(i=0;i<10;i++)
				MagCalMatrix[i] = 0;





			MagCalMatrix[3] = (1/660.0);
			MagCalMatrix[4] = (1/660.0);
			MagCalMatrix[5] = (1/660.0);

			if (report_format == 0) 
			printf("MAG calibration from - [DEFAULT], Q:%d\n",CalFlashState.MAG_QFACTOR);
		}
		if (report_format == 0) {
		printf("M[0][1][2]: %f %f %f\n", MagCalMatrix[0], MagCalMatrix[1], MagCalMatrix[2]);
		printf("M[3][4][5]: %f %f %f\n", MagCalMatrix[3], MagCalMatrix[4], MagCalMatrix[5]);
		printf("M[6][7][8]: %f %f %f\n", MagCalMatrix[6], MagCalMatrix[7], MagCalMatrix[8]);
		printf("M[9]: %f\n", MagCalMatrix[9]);
		}
		nvtSetMagCalMatrix(MagCalMatrix);
		nvtSetMagGaussPLSB((1/660.0));
	}
	else {
		if (report_format == 0)
		printf("MAG connect - [FAIL]\n");
}
}
void SensorInitBARO()
{
#line 295 "Sensors.c"
}
void SensorsInit()
{

	SensorInitACC();


	SensorInitGYRO();
#line 310 "Sensors.c"
}

 
void SensorReadACC()
{

	int16_t rawACC[3];

	MPU6050_getAcceleration(&rawACC[0],&rawACC[1], &rawACC[2]);

	{Sensor . rawACC[0] = -rawACC[0]; Sensor . rawACC[1] = -rawACC[1]; Sensor . rawACC[2] = rawACC[2];};

}

void SensorReadGYRO()
{

	int16_t rawGYRO[3];

	MPU6050_getRotation(&rawGYRO[0],&rawGYRO[1], &rawGYRO[2]);

	{Sensor . rawGYRO[0] = -rawGYRO[0]; Sensor . rawGYRO[1] = -rawGYRO[1]; Sensor . rawGYRO[2] = rawGYRO[2];};
	

}

void SensorReadMAG()
{
	int16_t rawMAG[3];
#line 345 "Sensors.c"
	{Sensor . rawMAG[0] = rawMAG[0]; Sensor . rawMAG[1] = rawMAG[1]; Sensor . rawMAG[2] = rawMAG[2];};
	
}
#line 373 "Sensors.c"
_Bool SensorReadBARO()
{
#line 429 "Sensors.c"
	return 0;

}

void SensorReadSpeed()
{

	int16_t moveSpeed[2]; 
	HALL_getSpeed(moveSpeed);
  Sensor.moveSpeed[0] = moveSpeed[0];
  Sensor.moveSpeed[1] = moveSpeed[1];

}

void SensorsRead(char SensorType, char interval)
{
#line 452 "Sensors.c"
	if(SensorType&(1<<0)&&SensorInitState.ACC_Done) {
		SensorReadACC();
		nvtInputSensorRawACC(&Sensor.rawACC[0]);
	}
#line 472 "Sensors.c"
	if(SensorType&(1<<1)&&SensorInitState.GYRO_Done) {
		SensorReadGYRO();
		nvtInputSensorRawGYRO(&Sensor.rawGYRO[0]);
	}


	if(SensorType&(1<<4)) {
		SensorReadSpeed();
	}

  
}

void SensorsDynamicCalibrate(char SensorType)
{

	if(SensorType&(1<<0)&&SensorInitState.ACC_Done) {
		 
	}


	if(SensorType&(1<<1)&&SensorInitState.GYRO_Done) {
		if(!SensorCalState.GYRO_Done) {
			if(nvtGyroCenterCalibrate()!=1)
				led_arm_state(0);
			else {
				float GyroMean[3];
				
				SensorCalState.GYRO_Done = 1;
				led_arm_state(2);
				nvtGetGyroOffset(GyroMean);
			}
		}
	}
#line 524 "Sensors.c"
}

char GetSensorInitState()
{
	char InitState = 0;
	
	InitState = ((SensorInitState.ACC_Done<<0))|((SensorInitState.GYRO_Done<<1))|((SensorInitState.MAG_Done<<2)|((SensorInitState.BARO_Done<<3)));
	return InitState;
}

char GetSensorCalState()
{
	char CalState = 0;
	CalState = ((SensorCalState.ACC_Done<<0))|((SensorCalState.GYRO_Done<<1))|((SensorCalState.MAG_Done<<2)|((SensorCalState.BARO_Done<<3)));
	return CalState;
}

int32_t GetBaroBasePressure()
{



	return 0;

}
float GetBaroAltitude()
{



	return 0;

}

#line 569 "Sensors.c"
int16_t GetMoveSpeed()
{
	return (Sensor.moveSpeed[1]+Sensor.moveSpeed[0])/2;
}
int16_t GetMoveSpeedL()
{
	return Sensor.moveSpeed[1];
}
int16_t GetMoveSpeedR()
{
	return Sensor.moveSpeed[0];
}
