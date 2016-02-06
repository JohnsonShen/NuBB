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
 * Written by Howard Huang for Nuvoton Technology.                            *
 * chhuang16@nuvoton.com                                                      *
 *                                                                            *
 *============================================================================*
 */
#ifndef PSDIR_H_
#define PSDIR_H_

#include <stdbool.h>
#include "Def.h"


extern void PSDIR_init(void);
int8_t I2C0_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data, uint16_t timeout);
bool I2C0_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data);
void I2C0_Callback_Tx_Continue(uint32_t status,uint8_t Addr);
void I2C0_Callback_Rx_Continue(uint32_t status, uint8_t Addr);
void Get_PSDIR(void);
#endif /* PSDIR_H_ */

