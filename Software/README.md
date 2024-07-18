## RP2040 - Analog temperature sensor - MCP9701A
[MCP9701A](https://store.comet.bg/en/Catalogue/Product/5003942/) family of sensors with Linear Active Thermistor Integrated Circuit
(IC) comprise a family of analog temperature sensors that convert temperature to analog voltage.
The low-cost, low-power sensors feature an accuracy of ±1°C from +20°C to +70°C (MCP9700B), ±2°C from
0°C to +70°C (MCP9700A/9701A) and ±4°C from 0°C to +70°C (MCP9700/9701) while consuming 6 µA (typical) of operating current.
 
## RP2040 - Digital temperature and humidity sensor - DHT22
[DHT22](https://store.comet.bg/en/Catalogue/Product/50013/) is basic, ultra low-cost digital temperature and humidity sensor. 
It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin 
(no analog input pins needed). It's fairly simple to use but requires careful timing to grab data.

### Libraries for DHT22
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor?utm_source=platformio&utm_medium=piohome)
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library?utm_source=platformio&utm_medium=piohome)

## RP2040 - Digital temperature sensor - DS18B20
[DS18B20](https://store.comet.bg/en/Catalogue/Product/29267/) provides 9 to 12 bit (configurable) temperature readings which indicate the temperature of the device.
Information is sent to/from the DS18B20 over a 1- Wire interface, 
so that only one wire (and ground) needs to be connected from a central microprocessor to a DS18B20.

### Libraries for DS18B20
- [Onewire](https://github.com/PaulStoffregen/OneWire)
- [Dallas temperature](https://github.com/jmchiappa/DallasTemperature)

## RP2040 - Epaper - GDEY029T94
[GDEY029T94](https://store.comet.bg/en/Catalogue/Product/46503/) is a 2.9 inch SPI e-paper display. This display showcases black and white images indefinitely without power via SPI interface with 296x128 resolution.

### Libraries used for Epaper
- [Adafruit_GFX](https://github.com/adafruit/Adafruit-GFX-Library?utm_source=platformio&utm_medium=piohome)
- [GxEPD2](https://github.com/ZinggJM/GxEPD2)
- [Adafruit BusIO](https://github.com/adafruit/Adafruit_BusIO?utm_source=platformio&utm_medium=piohome)

## RP2040 - OLED - WEA012864D
[WEA012864DLPP3N00003](https://store.comet.bg/download-file.php?id=21559) is an OLED display module made of 128x64 pixels, diagonal size 0.96 inch. This module is built in with SSD1306 IC, it supports I2C (default), SPI interface optional, VCC 3V /5V, I/O level 5V to 3V, with conversion circuit, 1/64 duty cycle. 

### Libraries used for OLED
- SPI - This library is bundled with every Arduino platform
- Wire - This library is bundled with every Arduino platform
- [Adafruit_GFX](https://github.com/adafruit/Adafruit-GFX-Library?utm_source=platformio&utm_medium=piohome)
- [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306?utm_source=platformio&utm_medium=piohome) - 2.5.1
- [Adafruit BusIO](https://github.com/adafruit/Adafruit_BusIO?utm_source=platformio&utm_medium=piohome)

## Used Software
- [Visual Studio Code](https://code.visualstudio.com/) version 1.91.0
- [PlatformIO](https://platformio.org/) Core Version 6.1.15
- [Arduino framework](https://docs.platformio.org/en/stable/frameworks/arduino.html) - Allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences.
