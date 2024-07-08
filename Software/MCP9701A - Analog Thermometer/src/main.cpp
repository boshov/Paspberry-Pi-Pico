#include <Arduino.h>

int sensorPin = A2;
int ledPin = 25;     
int adcValue = 0; // variable to store the value coming from the sensor
float voltage = 0;
double tempC = 0.0195;
double voltO = 400;
double tempA;
int count = 0;
double totalValue = 0;
double avrValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  delay(500);
  analogReadResolution(12);

}

void loop() {
  // read the value from the sensor:
  for(count=0; count<10; count++)
  {
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);
    // stop the program for <sensorValue> milliseconds:
    delay(50);
    // turn the ledPin off:
    digitalWrite(ledPin, LOW);
    delay(50);

    adcValue = analogRead(sensorPin);
    totalValue += adcValue;
  }

  avrValue = totalValue/10;
  totalValue=0;

  voltage = avrValue*(3300/4095.0);         //voltage output from sensor

  tempA = (voltage - voltO)/(tempC*1000);   //temperature

  Serial.print("ADC Value   = ");
  Serial.println(avrValue);
  Serial.print("Voltage     = ");
  Serial.print(voltage);
  Serial.print(" mV \nTemperature = ");
  Serial.print(tempA);
  Serial.println(" C \n============== ");

  delay(1000);
}