/*----------------------------------------------------------------------------
 * Name:    LED.h
 * Purpose: low level LED definitions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2013 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#ifndef __LED_H
#define __LED_H

/* LED Definitions */
typedef enum {
  LED_RED = 0,
  LED_BLUE,
  LED_GREEN,
  LED_NUM /* Number of user LEDs */
} LED_REF;

// call init once before others
extern void LED_Init(void);
// call uninit once before stop using
extern void LED_Uninit(void);

// control individule led without affecting other leds
extern bool LED_IsOn(LED_REF num);
extern bool LED_IsOff(LED_REF num);

extern void LED_On(LED_REF num);
extern void LED_Off(LED_REF num);
extern void LED_Toggle(LED_REF num);

#endif
