/*
  ************************************************************************
  *	LED.c
  *
  *	LED driver for EK-TM4C123GXL implementation
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
#include "LEDpriv.h"

static const uint32_t LED_ALL = RED_LED_PIN | BLUE_LED_PIN | GREEN_LED_PIN;
static const uint32_t led_mask[] = {RED_LED_PIN, BLUE_LED_PIN, GREEN_LED_PIN};

/*----------------------------------------------------------------------------
  initialize LED Pins (GPIOF.2)
 *----------------------------------------------------------------------------*/
void LED_Init(void) { /* Enable clock and init GPIO outputs */
  /* enable clock for GPIO F   */
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  /* wait for the GPIOA module to be ready. */
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {
  }

  /* GPIOF.2 is output        */
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_ALL);
}

void LED_Uninit(void) { SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOF); }

bool LED_IsOn(LED_REF num) {
  return GPIOPinRead(GPIO_PORTF_BASE, led_mask[num]) & led_mask[num];
}
bool LED_IsOff(LED_REF num) { return !LED_IsOn(num); }
/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void LED_On(LED_REF num) {
  GPIOPinWrite(GPIO_PORTF_BASE, led_mask[num], led_mask[num]);
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void LED_Off(LED_REF num) { GPIOPinWrite(GPIO_PORTF_BASE, led_mask[num], 0); }

/*----------------------------------------------------------------------------
  Function that toggles requested LED
 *----------------------------------------------------------------------------*/
void LED_Toggle(LED_REF num) {
  // GPIO_PORTF_DATA_R ^= led_mask[num];
  HWREG(GPIO_PORTF_BASE + (GPIO_O_DATA + (led_mask[num] << 2))) ^=
      led_mask[num];
  // HWREGBITW(GPIO_PORTF_BASE, led_mask[num] >> 2) ^= led_mask[num];
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/
// void LED_Out(unsigned int value) {
//   int i;

//   for (i = 0; i < LED_NUM; i++) {
//     if (value & (1 << i)) {
//       LED_On(i);
//     } else {
//       LED_Off(i);
//     }
//   }
// }
