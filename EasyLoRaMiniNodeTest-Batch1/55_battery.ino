void setupBattery()
{
  // https://github.com/G6EJD/ESP32-ADC-Accuracy-Improvement-function/blob/master/ESP32_Read_Voltage_Simple.ino
  // http://community.heltec.cn/t/heltec-wifi-lora-v2-battery-management/147/37
  // https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
  pinMode(BAT_METER, INPUT);
  adcAttachPin(BAT_METER);
  analogSetClockDiv(255); // More accurate ADC
}

float getBatteryADCValue()
{
  return analogRead(BAT_METER);
}

// If UART USB is attached (with or without battery), the voltage is randomly from 4.1-4.4v.
// And the battery is charged with 4.2v.
// else batVolt = 0.001654 * getBatteryADCValue() + 0.442;
float getBatteryVoltage()
{
  float batVolt = 0.001654 * getBatteryADCValue() + 0.442;
  return batVolt;
}

void testBattery()
{
  Serial.println("[BAT] Battery voltage > 4.2v if use UART. Voltage: " + 
    (String) getBatteryVoltage());
}
