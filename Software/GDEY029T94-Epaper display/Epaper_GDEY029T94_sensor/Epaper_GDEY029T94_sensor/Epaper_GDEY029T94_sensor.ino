// Library: https://github.com/ZinggJM/GxEPD2

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_4C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold9pt7b.h>


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
double tempP = 100;
int hyster = 1;

void setup()
{
  pinMode(25, OUTPUT);
  Serial.begin(115200);
  Serial.println("SYSSTART!");
  display.init(115200);
  analogReadResolution(12);
}

void printtext(float temperature){
  
  String tempValue = "";
  tempValue = tempValue + temperature;

  display.setRotation(3);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(tempValue, 0, 0, &tbx, &tby, &tbw, &tbh);
  //center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    //PRINTING TEXT
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(tempValue);
  }
  while (display.nextPage());
}

void loop() {

  adcValue = analogRead(sensorPin);
  voltage = adcValue*(3300/4095.0);         //voltage output from sensor
  tempA = (voltage - voltO)/(tempC*1000);

  if(abs(tempP - tempA) >= hyster){
    printtext(tempA);
  } 
  tempP = tempA;
  Serial.println(tempA);

  delay(3000);
}



