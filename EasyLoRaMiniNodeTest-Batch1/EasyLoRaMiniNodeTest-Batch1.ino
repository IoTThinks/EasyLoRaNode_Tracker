// Version Ai-Thinker 915Mhz + LoRa switch
// 40 boards
#include "EasyLoRa.h"
#include "soc/rtc_cntl_reg.h" // Temporarily disable brownout detector

void setup() 
{  
  // Temporarily disable brownout detector. Seems working well
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  
  setupSerial();
  setupLEDs();
  setupWiFi();
  setupLoRa();  
  setupSleep();
  setupBattery();
  setupButton();
}

void loop() 
{ 
  Serial.println("======= BEGIN TEST ========");
  testSerial();
  testLEDs();

  // Test LoRa Power Switch to on and off many times
  // Should be on after test
  testLoRaPower();

  // For other LoRa mesages
  // Should be already on after testLoRaPower
  // powerOnLoRa();
  // startLoRa();
  
  // Do not attach the usb uart when testing battery voltage 
  // Battery voltage is larger than 4.2v if use UART
  // WiFi.mode(WIFI_OFF);
  testLoRaSendBatMeter();

  // Test button
  testButton();
  
  // CHANGE WIFI_NAME AND WIFI_PWD IN EASYLORA.H!!!
  // Test WiFi and send IP via LoRa
  testWiFi();
  // WiFi.mode(WIFI_OFF);
  testLoRaSendIP();
  Serial.println("======= END TEST ========");  
  
  // To go to deepsleep
  testSleep();
}
