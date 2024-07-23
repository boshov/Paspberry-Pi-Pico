
#include <SPI.h>
#include <MFRC522.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define RST_PIN         22          // Configurable, see typical pin layout above
#define SS_PIN          17          // Configurable, see typical pin layout above

byte readCard[4];
String MasterTag = "89DCF1C0";	// REPLACE this Tag ID with your Tag ID!!!
String tagID = "";

// Create instances
MFRC522 mfrc522(SS_PIN, RST_PIN);

int blueLED = 13; 
int redLED = 14;
int greenLED = 15;

void setup() 
{
  SPI.begin(); // SPI bus
  mfrc522.PCD_Init(); // MFRC522

  Serial.begin(115200);

  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, HIGH);

  delay(3000);
  Serial.println("SYSSTART");

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay(); 
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(8, 20);
  display.print(" WELCOME!");
  display.display();

}

//Read new tag if available
boolean getID() {
  // Getting ready for Reading PICCs
  if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
  return false;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
  return false;
  }
  tagID = "";
  for ( uint8_t i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
  //readCard[i] = mfrc522.uid.uidByte[i];
  tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading
  return true;
}

void loop() {
  //Wait until new tag is available
  while (getID()) 
  {
    
    if (tagID == MasterTag) 
    {
      
      Serial.println(" Access Granted!");

      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(20, 15);
      display.print(" Access \n  Granted!");
      display.display();

      digitalWrite(blueLED, HIGH);
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);

      delay(1000);

      display.clearDisplay(); 
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(23, 21);
      display.print(" ENTER!");
      display.display();
      // You can write any code here like opening doors, switching on a relay, lighting up an LED, or anything else you can think of.
    }
    else
    {
      Serial.println(" Access Denied!");

      display.clearDisplay(); 
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(18, 15);
      display.print(" Access \n  Denied!");
      display.display();

      digitalWrite(blueLED, HIGH);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);      

      delay(1000);

      display.clearDisplay(); 
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(8, 20);
      display.print("CHECK TAG!");
      display.display();
    }
    
    Serial.println(tagID);

    delay(1000);

    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);

    display.clearDisplay(); 
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(8, 20);
    display.print(" WELCOME!");
    display.display();
  }
}


