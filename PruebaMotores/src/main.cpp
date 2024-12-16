/*
Programa para probar motores del RobotSoccerKit
Este programa está cofigurado para los pines del Motor 1
Cambiando el valor de los pines podemos probar cualquiera de los encoders

MOTOR1_PWM1 13
MOTOR1_PWM2 14

MOTOR2_PWM1 17
MOTOR2_PWM2 18

MOTOR3_PWM1 22
MOTOR3_PWM2 23

*/

#include <Arduino.h>

#define MOTOR_PWM1 13  //Sustituir el valor por el Pin1 del motor que se quiera probar
#define MOTOR_PWM2 14  //Sustituir el valor por el Pin2 del motor que se quiera probar

void motor_girar (bool pin1, bool pin2){
   digitalWrite(MOTOR_PWM1, pin1);
   digitalWrite(MOTOR_PWM2, pin2);
}

void setup() {
  // Ajustes par el programa.
  Serial.begin(115200);
  delay(200);
  pinMode(MOTOR_PWM1, OUTPUT);
  pinMode(MOTOR_PWM2, OUTPUT);
}

void loop() {
  // Los motore giran en función de como son las salidas de los pines 0-1 en un sentido 1-0 en sentido contrario
  // 0 - 0 o 1 - 1 harán que los motores se detengan.
  motor_girar(true, false);
  delay(1000);
  motor_girar(false, false);
  delay(1000);
  motor_girar(false, true);
  delay(1000);
  motor_girar(false, false);
  delay(1000);
  }