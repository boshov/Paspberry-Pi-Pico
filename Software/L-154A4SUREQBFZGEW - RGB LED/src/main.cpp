#include <Arduino.h>

void setup() {
  pinMode(16,OUTPUT); // green
  pinMode(14,OUTPUT); // blue
  pinMode(15,OUTPUT); // red
  pinMode(25,OUTPUT);
}

void loop() {
  digitalWrite(25, HIGH);

  //GREEN
  digitalWrite(16, LOW); // led on
  delay(1000);
  digitalWrite(16, HIGH); // led off
  delay(1000);

  //BLUE
  digitalWrite(14, LOW); // led on
  delay(1000);
  digitalWrite(14, HIGH); // led off
  delay(1000);

  //RED
  digitalWrite(15, LOW); // led on
  delay(1000);
  digitalWrite(15, HIGH); // led off
  delay(1000);
}

