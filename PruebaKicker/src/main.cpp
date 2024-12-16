/*
Prueba simple para hacer que el Kicker chute 2 veces

Se ha utilizado la función que se utiliza en el Software de RobotSoccer

*/
#include <Arduino.h>

#define KICK_PIN 33

// Maxima duración en microsegundos
#define KICK_MAX_DURATION 20000

static unsigned long kick_end = 0;
static bool kicking = false;
static bool pruebaAcabada = false;
int ciclo;

//Inicializar el pin del kicker
void kicker_init() { pinMode(KICK_PIN, OUTPUT); }

//función para hacer Kick
void kicker_kick(float power) {
  if (!kicking) {
    if (power < 0)
      power = 0;
    if (power > 1)
      power = 1;
    kicking = true;
    kick_end = micros() + KICK_MAX_DURATION * power;
    digitalWrite(KICK_PIN, HIGH);
  }
}


void setup() {
  Serial.begin(115200);
  ciclo = 0;
  kicker_init();
  digitalWrite(KICK_PIN, LOW);
  delay(1000);
  Serial.println("Prueba Kicker");
}

void loop() {
  for (ciclo; ciclo <= 2 ; ciclo++){
    if (kicking && micros() > kick_end) {
      kicking = false;
      digitalWrite(KICK_PIN, LOW);
    }else{
      kicker_kick(1.0);
    }
    delay(2000);
  }
  if (ciclo == 2 && !pruebaAcabada){
    Serial.println("Prueba Acabada");
    pruebaAcabada = true;
  }
}

