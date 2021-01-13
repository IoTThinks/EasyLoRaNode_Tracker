void setupSleep()
{  
  // Serial.println("Configured all RTC Peripherals to be powered down in sleep");
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
}

void testSleep()
{    
  Serial.print("[SLEEP] Going to deepsleep in second(s): ");
  Serial.println(TIME_TO_SLEEP);
  Serial.println("[SLEEP] To check for battery current, must below 15uA!");
  delay(1000);  
  Serial.end(); // To avoid printing rubbish at the end
  LoRa.end();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  // To power off LoRa
  // LORA_POWER may go LOW when deepsleep automatically
  // and turn off LoRa
  powerOffLoRa();

  // To turn off ADC
  adc_power_off(); // adc_power_on();
  
  delay(1000);

  // To go to deepsleep
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}
