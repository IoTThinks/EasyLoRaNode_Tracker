void setupWiFi()
{
   // delete old config
   WiFi.disconnect(true);
   delay(1000);
   
   WiFi.onEvent(WiFiEvent);

   // Reduce TX Power
   // https://github.com/espressif/arduino-esp32/issues/2792
   // https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFiGeneric.h#L52
   // https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/wifi.html#esp32-wi-fi-station-general-scenario
   // https://blog.voneicken.com/projects/low-power-wifi-intro/
   // WiFi.setTxPower(WIFI_POWER_MINUS_1dBm); // Worked. To reduce brownout power
   
   // Set false for better ping latency
   // WiFi.setSleep(false);
}

void WiFiEvent(WiFiEvent_t event)
{  
  switch(event) {
    case SYSTEM_EVENT_STA_GOT_IP:      
      Serial.print("[WiFi] IP address: ");
      Serial.print(WiFi.localIP());
      Serial.println(". WiFi is PASSED.");
      WiFi_IP = WiFi.localIP().toString();
      // WiFi.mode(WIFI_OFF); // Still brownout
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      // Serial.println("[WiFi] WiFi lost connection.  Attempting to reconnect...");
      WiFi.reconnect();
      break;
    case SYSTEM_EVENT_STA_START:
      // Serial.println("[WiFi] WiFi station start");
      break;
    case SYSTEM_EVENT_STA_CONNECTED:
      // Serial.println("[WiFi] WiFi station connected to AP");
      break;
    case SYSTEM_EVENT_AP_START:
      // Serial.println("[WiFi] WiFi AP start");
      break;
    default:      
      // Serial.printf("[WiFi] Unhandled WiFi Event %d\n", event);       
      break;
  }
}

 void testWiFi()
 {
   Serial.println("[WiFi] Testing WiFi...");
  
   // delete old config
   WiFi.disconnect(true);
   delay(1000);
   
   WiFi.begin(WIFI_NAME, WIFI_PWD);
   delay(5000); // To wait for DHCP IP
   Serial.println("[WiFi] If you can see this, WiFi is PASSED.");
 }
