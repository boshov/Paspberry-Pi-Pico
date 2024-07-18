// Library: https://github.com/ZinggJM/GxEPD2

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_4C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold12pt7b.h>

#include "therm2.h"
#include "celsius2.h"


// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
#include "GxEPD2_display_selection.h"
#include "GxEPD2_display_selection_added.h"

int sensorPin = A2;
int ledPin = 25;     
int adcValue = 0; // variable to store the value coming from the sensor
float voltage = 0;
double tempC = 0.0195;
double voltO = 400;
double tempA;

void printText()
{
  const char Text[] = "TEMPERATURE";
  display.setRotation(3);
  display.setFont(&FreeMonoBold12pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(Text, 0, 0, &tbx, &tby, &tbw, &tbh);
  do
  {
    display.setCursor(120, 30);
    display.print(Text);
  }
  while (display.nextPage());
}

void drawImages()
{
  display.setRotation(3);
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.drawBitmap(5, 0, gImage_therm2, 128, 128, GxEPD_BLACK);
    display.drawBitmap(225, 50, gImage_celsius2, 24, 24, GxEPD_BLACK);
  }
  while (display.nextPage());
}

void setup()
{
  //Serial.begin(115200);
  Serial.println("SYSSTART!");
  display.init(115200); // default 10ms reset pulse, e.g. for bare panels with DESPI-C02w
  delay(1000);
  drawImages();
  printText();
  analogReadResolution(12);
}

void temperature(float temp)
{
  String tempValue = "";
  tempValue = tempValue + temp;
  display.setRotation(3);
  display.setFont(&FreeMonoBold12pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(tempValue, -35, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  uint16_t wh = FreeMonoBold12pt7b.yAdvance;
  uint16_t wy = ((display.height() - wh) / 2);
  display.setPartialWindow(100, wy, 122, wh);
  display.firstPage();
  do
  {
    display.setCursor(x, y);
    display.print(tempValue);
  }
  while (display.nextPage());
}


void loop() {
  adcValue = analogRead(sensorPin);
  voltage = adcValue*(3300/4095.0);
  tempA = (voltage - voltO)/(tempC*1000);

  temperature(tempA);

  Serial.print("ADC Value   = ");
  Serial.println(adcValue);
  Serial.print("Voltage     = ");
  Serial.print(voltage);
  Serial.print(" mV \nTemperature = ");
  Serial.print(tempA);
  Serial.println(" C \n============== ");
  
  delay(3000);
}
