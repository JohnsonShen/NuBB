#line 1 "ak8975.c"






















 














 
#line 1 "AK8975.h"






















 














 
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







#line 40 "AK8975.h"









#line 68 "AK8975.h"


















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
#line 40 "ak8975.c"
#line 1 "I2CDev.h"
 











 














 
#line 32 "I2CDev.h"
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
#line 41 "ak8975.c"
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
#line 42 "ak8975.c"
static uint8_t devAddr;
static uint8_t buffer[6];
static int16_t hx, hy, hz;


 
void AK8975_address() {
    devAddr = 0x0C;
}



 
_Bool AK8975_testConnection() {
    if (I2C_readByte(devAddr, 0x00, buffer,1) == 1) {
        return (buffer[0] == 0x48);
    }
    return 0;
}

uint8_t AK8975_getDeviceID() {
    I2C_readByte(devAddr, 0x00, buffer,0);
    return buffer[0];
}



uint8_t AK8975_getInfo() {
    I2C_readByte(devAddr, 0x01, buffer,0);
    return buffer[0];
}



_Bool AK8975_getDataReady() {
    I2C_readBit(devAddr, 0x02, 0, buffer,0);
    return buffer[0];
}


void AK8975_getHeading(int16_t *x, int16_t *y, int16_t *z) {
	if(ChronographRead(1)>= 10)
  {
		ChronographSet(1);
		I2C_readBytes(devAddr, 0x03, 6, buffer, 0);
		hx = (((int16_t)buffer[1]) << 8) | buffer[0];
		hy = (((int16_t)buffer[3]) << 8) | buffer[2];
    hz = (((int16_t)buffer[5]) << 8) | buffer[4];
		
    I2C_writeByte(devAddr, 0x0A, 0x1);
    
    
	}
	*x = hx;
  *y = hy;
  *z = hz;
    
}
int16_t AK8975_getHeadingX() {
    I2C_writeByte(devAddr, 0x0A, 0x1);
    DelayMsec(8);
    I2C_readBytes(devAddr, 0x03, 2, buffer,0);
    return (((int16_t)buffer[1]) << 8) | buffer[0];
}
int16_t AK8975_getHeadingY() {
    I2C_writeByte(devAddr, 0x0A, 0x1);
    DelayMsec(8);
    I2C_readBytes(devAddr, 0x05, 2, buffer,0);
    return (((int16_t)buffer[1]) << 8) | buffer[0];
}
int16_t AK8975_getHeadingZ() {
    I2C_writeByte(devAddr, 0x0A, 0x1);
    DelayMsec(8);
    I2C_readBytes(devAddr, 0x07, 2, buffer,0);
    return (((int16_t)buffer[1]) << 8) | buffer[0];
}


_Bool AK8975_getOverflowStatus() {
    I2C_readBit(devAddr, 0x09, 3, buffer,0);
    return buffer[0];
}
_Bool AK8975_getDataError() {
    I2C_readBit(devAddr, 0x09, 2, buffer,0);
    return buffer[0];
}


uint8_t AK8975_getMode() {
    I2C_readBits(devAddr, 0x0A, 3, 4, buffer,0);
    return buffer[0];
}
void AK8975_setMode(uint8_t mode) {
    I2C_writeBits(devAddr, 0x0A, 3, 4, mode);
}
void AK8975_reset() {
    I2C_writeBits(devAddr, 0x0A, 3, 4, 0x0);
}


void AK8975_setSelfTest(_Bool enabled) {
    I2C_writeBit(devAddr, 0x0C, 6, enabled);
}


void AK8975_getAdjustment(int8_t *x, int8_t *y, int8_t *z) {
    I2C_readBytes(devAddr, 0x10, 3, buffer,0);
    *x = buffer[0];
    *y = buffer[1];
    *z = buffer[2];
}
void AK8975_setAdjustment(int8_t x, int8_t y, int8_t z) {
    buffer[0] = x;
    buffer[1] = y;
    buffer[2] = z;
    I2C_writeBytes(devAddr, 0x10, 3, buffer);
}
uint8_t AK8975_getAdjustmentX() {
    I2C_readByte(devAddr, 0x10, buffer,0);
    return buffer[0];
}
void AK8975_setAdjustmentX(uint8_t x) {
    I2C_writeByte(devAddr, 0x10, x);
}
uint8_t AK8975_getAdjustmentY() {
    I2C_readByte(devAddr, 0x11, buffer,0);
    return buffer[0];
}
void AK8975_setAdjustmentY(uint8_t y) {
    I2C_writeByte(devAddr, 0x11, y);
}
uint8_t AK8975_getAdjustmentZ() {
    I2C_readByte(devAddr, 0x12, buffer,0);
    return buffer[0];
}
void AK8975_setAdjustmentZ(uint8_t z) {
    I2C_writeByte(devAddr, 0x12, z);
}
_Bool AK8975_initialize() {
	_Bool connect;
	AK8975_address();
	connect = AK8975_testConnection();
	if(connect)
		AK8975_reset();
	
	return connect;
}
