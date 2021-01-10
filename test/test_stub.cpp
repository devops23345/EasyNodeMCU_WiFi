#include <Arduino.h>
#include "EasyNodeMCU_Wifi.h"
#include <unity.h>

const char* easy_Wifi_SSID = "Doppler2"; //defined in main program
const char* easy_Wifi_Password = "23345chicoryroad"; //defined in main program

void test_wifi_setup(){

  //TEST_ASSERT_TRUE(setup_easy_wifi(easy_Wifi_SSID, easy_Wifi_Password));
  setup_easy_wifi(easy_Wifi_SSID, easy_Wifi_Password);

}

void test_wifi_loop(){

  //TEST_ASSERT_TRUE(loop_easy_wifi());//will handle reconnects
  loop_easy_wifi();
}

void setup() {
  // Start serial comm first as other setups will print to the serial port
  // Begin Serial on 115200
  // Remember to choose the correct Baudrate on the Serial monitor!
  // This is just for debugging purposes
  Serial.begin(115200);
  delay(2);

  UNITY_BEGIN();    // IMPORTANT LINE!
  RUN_TEST(test_wifi_setup);
}

uint8_t i = 0;
uint8_t max_time = 5;

void loop() {
    if (i < max_time)
    {
        RUN_TEST(test_wifi_loop);
        delay(1000);
        i++;
    }
    else if (i == max_time) {
      UNITY_END(); // stop unit testing
    }
}
