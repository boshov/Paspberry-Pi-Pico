## RP2040 - Analog sensor - MCP9701A
[MCP9701A](https://store.comet.bg/en/Catalogue/Product/5003942/) family of sensors with Linear Active Thermistor Integrated Circuit
(IC) comprise a family of analog temperature sensors that convert temperature to analog voltage.
The low-cost, low-power sensors feature an accuracy of ±1°C from +20°C to +70°C (MCP9700B), ±2°C from
0°C to +70°C (MCP9700A/9701A) and ±4°C from 0°C to +70°C (MCP9700/9701) while consuming 6 µA (typical) of operating current.
 
## RP2040 - Digital sensor - DHT22
[DHT22](https://store.comet.bg/en/Catalogue/Product/50013/) is basic, ultra low-cost digital temperature and humidity sensor. 
It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin 
(no analog input pins needed). It's fairly simple to use but requires careful timing to grab data.

## RP2040 - Digital sensor - DS18B20
[DS18B20](https://store.comet.bg/en/Catalogue/Product/29267/) provides 9 to 12 bit (configurable) temperature readings which indicate the temperature of the device.
Information is sent to/from the DS18B20 over a 1- Wire interface, 
so that only one wire (and ground) needs to be connected from a central microprocessor to a DS18B20.

### Libraries for DHT22
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor?utm_source=platformio&utm_medium=piohome)
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library?utm_source=platformio&utm_medium=piohome)

### Libraries for DS18B20
- [Onewire](https://github.com/PaulStoffregen/OneWire)
- [Dallas temperature](https://github.com/jmchiappa/DallasTemperature)

## Used Software
- [Visual Studio Code](https://code.visualstudio.com/) version 1.81.0
- [PlatformIO](https://platformio.org/) Core Version 6.1.10
- [Arduino framework](https://docs.platformio.org/en/stable/frameworks/arduino.html) - Allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences.
