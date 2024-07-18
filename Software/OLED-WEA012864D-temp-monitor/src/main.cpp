#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "therm3.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int sensorPin = A2;
int ledPin = 25;     
int adcValue = 0; 
float voltage = 0;
double tempC = 0.0195;
double voltO = 400;
double tempA;

void setup() {
  Serial.begin(115200);
  delay(3000);

  Serial.println("SYSSTART");

  delay(2000);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  analogReadResolution(12);

  display.clearDisplay();
}

void loop() {
  adcValue = analogRead(sensorPin);

  voltage = adcValue*(3300/4095.0);
  tempA = (voltage - voltO)/(tempC*1000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(45, 10);
  display.println("TEMPERATURE");

  display.setTextSize(2);
  display.setCursor(42, 40);
  display.print(tempA);

  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

  display.drawBitmap(0, 0, gImage_therm3, 64, 64, 1);
  display.display(); 

  Serial.print("ADC Value   = ");
  Serial.println(adcValue);
  Serial.print("Voltage     = ");
  Serial.print(voltage);
  Serial.print(" mV \nTemperature = ");
  Serial.print(tempA);
  Serial.println(" C \n============== ");
  
  delay(3000);
}