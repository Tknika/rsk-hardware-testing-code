/*
Utilizando la librería FastLed generamos un programa que ilumina los 6 Leds
del RobotSoccer kit con colores aleatorios. 
*/

#pragma once

#include <Arduino.h>
#include <stdint.h>
#include <FastLED.h>

// LEDs pin (6 RGB addressable WS2812 LEDs)
#define LEDS 27

//Variable donde almacenaremos el numero aleatorio
long randomNumberR;
long randomNumberG;
long randomNumberB;

CRGB leds[6];

//Función para poner un color por defecto
void leds_default() {
  for (int k = 0; k < 6; k++) {
    leds[k] = CRGB(128, 64, 0);
  }

  FastLED.show();
}

//Funcion para inicializar los leds y poner el color por defecto
void leds_init() {
  FastLED.addLeds<NEOPIXEL, LEDS>(leds, 6);
  leds_default();
}

//Funcion para poner el color que queramos a todos los leds
void leds_set(uint8_t r, uint8_t g, uint8_t b) {
  for (int k = 0; k < 6; k++) {
    leds[k] = CRGB(r, g, b);
  }

  FastLED.show();
}


void setup() {
  //Inicializamos los leds 
  leds_init();
  delay(1000);
}

void loop() {
  //Creamos numeros aleatorios RGB para los leds
  randomNumberR = random(0,255);
  randomNumberG = random(0,255);
  randomNumberB = random(0,255);

  //Enviamos el color aleatorio a los leds durante 2sg
  leds_set(randomNumberR, randomNumberG, randomNumberB);
  delay(2000);

}