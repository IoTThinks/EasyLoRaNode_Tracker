// ===================================================
// Put all pin mappings and library here
// ===================================================
#include "driver/adc.h"
// #include <driver/rtc_io.h>

// WiFi
#include <WiFi.h>
#define WIFI_NAME "Easy LoRa"   //  TO CHANGE TO YOUR WIFI
#define WIFI_PWD "EasyLoRa123"  //  TO CHANGE TO YOUR WIFI 
String WiFi_IP="0.0.0.0";

// Serial
#define BAUD_RATE             115200

// LED
#define LED                   22 // Mini - Pull-down resistor

// Button
#define BTN                   39 // Mini - Pull-down resistor

// LoRa
#include <SPI.h>
#include <LoRa.h>

#define LORA_POWER            21 // Low to off, High to on LoRa module

#define LORA_SS               25 // Mini - Must have pull up resistor
#define LORA_SCK              18 // Mini
#define LORA_MOSI             23 // Mini
#define LORA_MISO             19 // Mini
#define LORA_DIO0             26 // Mini
#define LORA_DIO1             35 // Mini
#define LORA_DIO2             34 // Mini
#define LORA_RESET            27 // Mini

#define LORA_FREQ             920E6
#define LORA_SF               9
#define LORA_CR               5
#define LORA_BW               250E3
#define LORA_PREAMBLE_LENGTH  8

// Battery
#define BAT_METER             36 // Mini

// Deepsleep
#define uS_TO_S_FACTOR        1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP         10        /* Time ESP32 will go to sleep (in seconds) */
