// ====================================
// Lora
// https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md
// ====================================
// TODO: Tests for DIO0, DIO1 and DIO2
// Setup Lora
void setupLoRa() 
{
  // To avoid random LoRa issue at startup
  pinMode(LORA_SS, OUTPUT);
  digitalWrite(LORA_SS, HIGH);

  // Setup SPI and LoRa GPIOs
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);  
  LoRa.setPins(LORA_SS, LORA_RESET, LORA_DIO0);

  // Set Power GPIO mode
  pinMode(LORA_POWER, OUTPUT);
}

void powerOnLoRa()
{
  // Serial.println("[LoRa] Power on LoRa");
  digitalWrite(LORA_POWER, HIGH);
}

void powerOffLoRa()
{
  // Serial.println("[LoRa] Power off LoRa");
  LoRa.end();
  digitalWrite(LORA_POWER, LOW);
}

void testLoRaPower()
{
  Serial.print("[LoRa] Testing LoRa Power switch: ");
  for(int i=0; i<2; i++)
  {
    testLoRaWithPowerOff();
    delay(200);
    testLoRaWithPowerOn();
    delay(200);    
  }
  Serial.println(". Done.");
}

bool startLoRa() 
{
  if (!LoRa.begin(LORA_FREQ)) 
  {
    // Serial.println("[LoRa] LoRa is started FAILED!!!");
    // delay(1000);
    return false;
  }
  else 
  {
    // Signal LoRa OK
    LoRaOKLED();
    
    LoRa.setSpreadingFactor(LORA_SF);
    LoRa.setCodingRate4(LORA_CR); //4/5
    LoRa.setSignalBandwidth(LORA_BW);
    LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);  
    // Serial.println("[LoRa] LoRa is started OK.");

    return true;
  }
}

void testLoRa()
{
  powerOnLoRa();
  bool isLoRaOK = startLoRa();
  if(isLoRaOK)
  {
    Serial.println("[LoRa] Power on LoRa OK. LoRa PASSED!");
  }
  else
  {
    Serial.println("[LoRa] Power on LoRa FAILED!");
  }
}

void testLoRaWithPowerOn()
{
  powerOnLoRa();
  bool isLoRaOK = startLoRa();
  delay(500);

  if(!isLoRaOK) 
  { 
    Serial.print("[on FAILED]");
  }
  else
  {
    Serial.print("[on ok]");
  }
}

void testLoRaWithPowerOff()
{
  powerOffLoRa();
  bool isLoRaOK = startLoRa();
  delay(500);
  if(isLoRaOK) 
  { 
    Serial.print("[off FAILED]");
  }
  else
  {
    Serial.print("[off ok]");
  }
}

// Assume LoRa is on and OK
void testLoRaSendBatMeter()
{
  // Send battery voltage via LoRa
  String batVolt = (String)getBatteryVoltage();
  sendLoRaMessage("BatV:" + batVolt);
}

// Assume LoRa is on and OK
void testLoRaSendIP()
{
  // Send IP via LoRa
  sendLoRaMessage("IP:" + WiFi_IP);
}

void sendLoRaMessage(String outgoing) {
  Serial.println("[LoRa]=> Sending LoRa packet: " + outgoing);
  LoRa.beginPacket();                   // start packet
  /*
  msgCount++;                           // increment message ID
  LoRa.write(destination);              // add destination address
  LoRa.write(localAddress);             // add sender address
  LoRa.write(msgCount);                 // add message ID
  LoRa.write(outgoing.length());        // add payload length
  */
  LoRa.print(outgoing);                 // add payload
  LoRa.endPacket();                     // finish packet and send it  
}
