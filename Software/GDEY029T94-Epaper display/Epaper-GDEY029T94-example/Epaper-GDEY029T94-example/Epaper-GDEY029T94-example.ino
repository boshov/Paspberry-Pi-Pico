// Library: https://github.com/ZinggJM/GxEPD2

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_4C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include "ytlogo1.h"

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
#include "GxEPD2_display_selection.h"
#include "GxEPD2_display_selection_added.h"

void setup()
{
  pinMode(25, OUTPUT);
  Serial.begin(115200);
  delay(5000);
  Serial.println("SYSSTART!");
  display.init(115200); // default 10ms reset pulse, e.g. for bare panels with DESPI-C02w
}

//PRINTING TEXT

const char Text[] = "MIHAIL BOSHOV";

void printtext()
{
  display.setRotation(3);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(Text, 0, 0, &tbx, &tby, &tbw, &tbh);
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
    display.print(Text);
    
    //DRAWING AN IMAGE
    //display.fillScreen(GxEPD_BLACK);
    //display.drawBitmap(70, 3, gImage_ytlogo1, 152, 121, GxEPD_WHITE);
  }
  while (display.nextPage());

  digitalWrite(25,HIGH);
  delay(500);
  digitalWrite(25,LOW);
  delay(500);

}

void loop() {
  printtext();
  delay(5000);
}
