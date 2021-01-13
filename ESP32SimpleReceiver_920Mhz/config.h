// ===================================================
// Put all pin mappings and library here
// ===================================================
// Serial
#define BAUD_RATE 115200 //9600

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
#define LORA_SF               9 // 7 is the fastest. 12 is is farthest
#define LORA_CR               5
#define LORA_BW               250E3 // 62.5E3 // 41.7E3 //31.25E3 // 41.7E3 //125E3
#define LORA_PREAMBLE_LENGTH  8
#define LORA_LNA_GAIN         6 // 0-6: 0 to disable. 6 is max gain

// #define PA_OUTPUT_RFO_PIN      0
// #define PA_OUTPUT_PA_BOOST_PIN 1
