# Easy LoRa Node - Tracker
A wearable LoRa node with battery with deepsleep less than 15uA.

# 1. Specifications
## 1.1 Overview
![Easy LoRa Tracker - Overview](https://user-images.githubusercontent.com/29994971/104403543-516f5d00-558b-11eb-9928-45658bd5ce4e.jpg)

## 1.2 Components
![Easy LoRa Tracker - Components](https://user-images.githubusercontent.com/29994971/104405468-98f7e800-558f-11eb-816b-1ce77bce26a2.jpg)

# 2. Usage guides
## 2.1 Pin mapping
LED
* LED                   22 // LOW is off, HIGH is on.

Button
* BTN                   39 // Pressed is HIGH. Keep LOW.

LoRa
* LORA_POWER            21 // LOW to off, HIGH to power on LoRa module
* LORA_SS               25 // Have pull up resistor
* LORA_SCK              18
* LORA_MOSI             23
* LORA_MISO             19
* LORA_DIO0             26
* LORA_DIO1             35
* LORA_DIO2             34
* LORA_RESET            27

Battery
* BAT_METER             36 // To measure battery voltage

## 2.2 Upload sketch

## 2.3 LoRa

## 2.4 Battery

## 2.5 GPIOs

## 2.6 Assemble everything
