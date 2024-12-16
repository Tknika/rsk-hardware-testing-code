#include <Arduino.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hola..");
  delay(1000);
}

