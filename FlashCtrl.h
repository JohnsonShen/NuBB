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
#ifndef _FLASH_CTRL_H
#define _FLASH_CTRL_H
#include "Def.h"
#define BOARD_CODE_BASE 12
//Calibration Section
#define CAL_BASE0	16
#define FIELD_VALID_SIZE 1
#define QUALITY_FACTOR_SIZE 1
#define FIELD_VALID      0x77
#define FIELD_INVALID    0x88
#define CAL_BASE_GYRO0	 CAL_BASE0
#define CAL_BASE_ACC0	(CAL_BASE_GYRO0 + GYRO_CAL_DATA_SIZE + FIELD_VALID_SIZE)
#define CAL_BASE_MAG0	(CAL_BASE_ACC0 + ACC_CAL_DATA_SIZE + FIELD_VALID_SIZE)

//PID Section
#define PID_SIZE 3
#define ALT_PID_SIZE 1
#define PPID_DATA_SIZE 9
#define RPID_DATA_SIZE 9
#define APID_DATA_SIZE 3
#define PID_FIELD_SIZE 		(PPID_DATA_SIZE + RPID_DATA_SIZE + APID_DATA_SIZE)
#define PID_BASE0 (CAL_BASE_MAG0 + MAG_CAL_DATA_SIZE + FIELD_VALID_SIZE + QUALITY_FACTOR_SIZE)

//SSVRC Section
#define RX_ADDRESS_SIZE 2
#define RX_ADDRESS_BASE (PID_BASE0 + PID_FIELD_SIZE + FIELD_VALID_SIZE)

#define CAL_BASE1	(RX_ADDRESS_BASE+RX_ADDRESS_SIZE)
#define CAL_BASE_GYRO1 CAL_BASE1
#define CAL_BASE_ACC1	(CAL_BASE_GYRO1 + GYRO_CAL_DATA_SIZE + FIELD_VALID_SIZE)
#define CAL_BASE_MAG1	(CAL_BASE_ACC1 + ACC_CAL_DATA_SIZE + FIELD_VALID_SIZE)
#define PID_BASE1 (CAL_BASE_MAG1 + MAG_CAL_DATA_SIZE + FIELD_VALID_SIZE + QUALITY_FACTOR_SIZE)

uint32_t read_code_ver(uint32_t u32add);
void write_code_ver(uint32_t u32add,uint32_t u32data);
void FlashInit(void);
void UpdateBoardVersion(bool);
uint32_t GetBoardVersion(void);
void UpdateFlashCal(int8_t sensorType, bool erase);
bool GetFlashCal(int8_t sensorType, float* Cal);
void UpdateFlashPID(bool erase);
bool GetFlashPID(float* PID_FIELD);
void UpdateFlashRxAddress(void);
bool GetFlashRxAddress(uint8_t* RX_ADDRESS_FIELD);
void TestFloat(void);
float GetFloatCounter(void);
int32_t float2dw(float f);
float dw2float(int32_t dw);
void FlashControl(void);
#endif
