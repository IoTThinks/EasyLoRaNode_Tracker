// ====================================
// Serial
// ====================================
void setupSerial() 
{
  Serial.begin(BAUD_RATE);
  Serial.println("=========================================================");
  Serial.println("[SERIAL] MUST CONNECT LIPO BATTERY TO TEST WIFI AND LORA");
  Serial.println("[SERIAL] IF HIT BROWNOUT => TEST FAILED");
  Serial.println("=========================================================");
}

void testSerial()
{
  Serial.println("[Serial] Serial is PASSED.");
}
