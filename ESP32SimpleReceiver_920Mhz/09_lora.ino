// ====================================
// Lora
// https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md
// ====================================
// Setup Lora
void setupLoRa() {
  Serial.println("[LoRa] Setting up LoRa");
  
  // Power on LoRa
  powerOnLoRa();
  
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
  LoRa.setPins(LORA_SS, LORA_RESET, LORA_DIO0);
  
  while (!LoRa.begin(LORA_FREQ)) {
    Serial.println("[LoRa] Starting LoRa failed!");
    delay(1000);
  }

  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setCodingRate4(LORA_CR); //4/5
  LoRa.setSignalBandwidth(LORA_BW);
  LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);
  LoRa.enableCrc();
  LoRa.setGain(LORA_LNA_GAIN);

  Serial.println("[LoRa] LoRa OK!");

   // register the receive callback
  LoRa.onReceive(onReceive);

  // put the radio into receive mode
  LoRa.receive();
}

void powerOnLoRa()
{
  Serial.println("[LoRa] Power on LoRa");
  pinMode(LORA_POWER, OUTPUT);
  digitalWrite(LORA_POWER, HIGH);
}

void powerOffLoRa()
{
  Serial.println("[LoRa] Power off LoRa");
  digitalWrite(LORA_POWER, LOW);
  // pinMode(LORA_POWER, INPUT);
}

void onReceive(int packetSize) {
  // received a packet
  Serial.print("Received packet '");

  // read packet
  for (int i = 0; i < packetSize; i++) {
    Serial.print((char)LoRa.read());
  }

  // print RSSI of packet
  Serial.print("' with RSSI = ");
  Serial.print(LoRa.packetRssi());

  // print SNR of packet
  Serial.print(", SNR = ");
  Serial.println(LoRa.packetSnr());
}
