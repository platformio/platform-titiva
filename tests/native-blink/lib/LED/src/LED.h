/*
  ************************************************************************
  *	LED.h
  *
  *	LED driver for EK-TM4C123GXL
  *		Copyright (c) 2020 Lei Zhang. All right reserved.
  *
  *
  ***********************************************************************
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef __LED_H
#define __LED_H

/* LED Definitions */
typedef enum {
  LED_RED = 0,
  LED_BLUE,
  LED_GREEN,
  LED_NUM /* Number of user LEDs */
} LED_REF;

// call init once before other calls
extern void LED_Init(void);
// call uninit once before stop using
extern void LED_Uninit(void);

extern bool LED_IsOn(LED_REF num);
extern bool LED_IsOff(LED_REF num);

// control individule led without affecting other leds
extern void LED_On(LED_REF num);
extern void LED_Off(LED_REF num);
extern void LED_Toggle(LED_REF num);

#endif
