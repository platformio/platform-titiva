/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */
#include <Arduino.h>

#include "LED.h"

void setup() { LED_Init(); }

extern void delay(uint32_t milliseconds);

void loop() {
  LED_Toggle(LED_GREEN);
  delay(1000);  // waits for a while
}
