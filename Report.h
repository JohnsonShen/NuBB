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
#ifndef _REPORT_H
#define _REPORT_H

#define REPORT_AHRS_EULER         1 
#define REPORT_AHRS_QUATERNION    2 
#define REPORT_SENSORS_CALIBRATED 3 
#define REPORT_SENSORS_RAW        4 
#define REPORT_MOTOR_POWER        5 
#define REPORT_PID                6
#define REPORT_RATE_PID           7
#define REPORT_VELOCITY           8
#define REPORT_RC_STATUS          9
#define REPORT_ALTHOLD_PID       10
#define REPORT_ALTHOLD_STATUS    11
#define REPORT_MODE_STATUS       12
#define REPORT_FLASH_STATUS      13
#define REPORT_GPS_STATUS        14
#define REPORT_HALL_STATUS       15
#define REPORT_ACTUATOR_STATUS   16
#define REPORT_HALLSPEED_PID     17

#define REPORT_FORMAT_TEXT        0 
#define REPORT_FORMAT_BINARY      1 

#define STREAM_START              1
#define STREAM_PAUSE              0
extern char report_mode;
extern char report_format;
extern char stream_mode;
extern uint8_t notify_buf[10];
void report_ASIC(uint8_t buf0,uint8_t buf1,uint8_t buf2,uint8_t buf3,uint8_t buf4,
									uint8_t buf5,uint8_t buf6,uint8_t buf7,uint8_t buf8,uint8_t buf9);
void report_sensors(void);
void report_status(void);
void CheckVersion(void);
#endif
