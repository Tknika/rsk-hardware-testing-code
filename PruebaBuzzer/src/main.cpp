#include <Arduino.h>

// Pin donde está conectado el buzzer
#define BUZZER_PIN 32

// Canal PWM para el buzzer
#define BUZZER_CHANNEL 0

// Estructura para definir notas
struct Note {
  unsigned int frequency; // Frecuencia de la nota (Hz)
  unsigned int duration;  // Duración de la nota (ms)
};

// Definición de las melodías
Note melody1[] = {
    {523, 300}, {587, 300}, {659, 300}, {698, 300}, {0, 300}}; // Do, Re, Mi, Fa

Note melody2[] = {
    {784, 300}, {880, 300}, {988, 300}, {1047, 300}, {0, 300}}; // Sol, La, Si, Do (octava alta)

// Función para reproducir una nota
void playNote(unsigned int frequency, unsigned int duration) {
  if (frequency == 0) {
    ledcWriteTone(BUZZER_CHANNEL, 0); // Silencio
  } else {
    ledcWriteTone(BUZZER_CHANNEL, frequency);
  }
  delay(duration);
}

// Función para reproducir una melodía
void playMelody(Note *melody, size_t length) {
  for (size_t i = 0; i < length; i++) {
    playNote(melody[i].frequency, melody[i].duration);
  }
}

void setup() {
  // Configuración del buzzer
  ledcSetup(BUZZER_CHANNEL, 2000, 10); // Canal, frecuencia inicial (2 kHz), resolución de 10 bits
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);

  // Reproducir melodías
  playMelody(melody1, sizeof(melody1) / sizeof(Note));
  delay(500); // Pausa entre melodías
  playMelody(melody2, sizeof(melody2) / sizeof(Note));

  // Detener el buzzer
  ledcWriteTone(BUZZER_CHANNEL, 0);
}

void loop() {
  // No se necesita nada en el loop para este ejemplo
}
