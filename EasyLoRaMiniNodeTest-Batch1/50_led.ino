// ====================================
// LED
// ====================================
void setupLEDs() 
{
  // Should be already low
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void testLEDs() 
{ 
  Serial.println("[LED] Check if 1 LED are OFF?");
  digitalWrite(LED, LOW);
  delay(2000);
  Serial.println("[LED] Check if 1 LED are ON?");
  digitalWrite(LED, HIGH);  
}

void LoRaOKLED()
{
  for(int i=0; i<5; i++)
  {
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);
    delay(500);    
  }
}
