#include <Arduino.h>
#include <unity.h>

#include "LED.c"
#include "LEDpriv.h"

// void setUp(void) {
//   LED_Off(LED_RED);
//   LED_Off(LED_BLUE);
//   LED_Off(LED_GREEN);
// }

// void tearDown(void) {

// }

void test_LED_Init(void) {
  LED_Init();
  TEST_ASSERT_TRUE(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
}

void test_LED_Uninit(void) {
  LED_Uninit();
  TEST_ASSERT_FALSE(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
}

void test_LED_On(void) {
  LED_Off(LED_RED);
  LED_Off(LED_BLUE);
  LED_Off(LED_GREEN);

  LED_On(LED_RED);
  TEST_ASSERT_TRUE(LED_IsOn(LED_RED));
  TEST_ASSERT_TRUE(LED_IsOff(LED_BLUE));
  TEST_ASSERT_TRUE(LED_IsOff(LED_GREEN));
}

void test_LED_Off(void) {
  LED_On(LED_RED);
  LED_On(LED_BLUE);
  LED_On(LED_GREEN);

  LED_Off(LED_RED);
  TEST_ASSERT_TRUE(LED_IsOff(LED_RED));
  TEST_ASSERT_TRUE(LED_IsOn(LED_BLUE));
  TEST_ASSERT_TRUE(LED_IsOn(LED_GREEN));
}

void test_LED_Toggle(void) {
  bool before_toogle = LED_IsOn(LED_GREEN);
  LED_Toggle(LED_GREEN);
  bool after_toogle = LED_IsOn(LED_GREEN);
  TEST_ASSERT_TRUE(before_toogle == !after_toogle);
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN();  // IMPORTANT LINE!

  RUN_TEST(test_LED_Init);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
  if (i < max_blinks) {
    RUN_TEST(test_LED_On);
    // delay(500);
    RUN_TEST(test_LED_Off);
    // delay(500);
    RUN_TEST(test_LED_Toggle);
    // delay(500);
    i++;
  } else if (i == max_blinks) {
    RUN_TEST(test_LED_Uninit);

    UNITY_END();  // stop unit testing
  }
}
