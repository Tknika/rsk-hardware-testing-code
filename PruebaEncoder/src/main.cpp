/*
Programa para probar los pines de los encoders del RobotSoccerKit
Este programa está cofigurado para los pines del encoder del Motor 1
Cambiando el valor de los pines podemos probar cualquiera de los encoders

PIN MOTOR1_ENC1 25
PIN MOTOR1_ENC2 26

PIN MOTOR2_ENC1 19
PIN MOTOR2_ENC2 21

PIN MOTOR3_ENC1 4
PIN MOTOR3_ENC2 16

*/

#include <Arduino.h>

#define MOTOR_ENC1 25  //Sustituir el valor por el Pin1 del encoder del motor que se quiera probar
#define MOTOR_ENC2 26  //Sustituir el valor por el Pin2 del encoder del motor que se quiera probar

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  pinMode(MOTOR_ENC1, INPUT_PULLUP);
  pinMode(MOTOR_ENC2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool enc1 = digitalRead(MOTOR_ENC1);
  bool enc2 = digitalRead(MOTOR_ENC2);
  Serial.print("Encoder C1: ");
  Serial.println(enc1);
  Serial.print("Encoder C2: ");
  Serial.println(enc2);
  delay(500);
}

