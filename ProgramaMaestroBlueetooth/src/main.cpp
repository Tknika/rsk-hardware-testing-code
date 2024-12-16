#include <Arduino.h>
#include "BluetoothSerial.h"
 
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
const char *pin = "1234"; // Cambiar el PIN por el que tenga designado el esclavo
String slaveName = "RSK04"; // Cambiar el nombre por el nombre de dispositivo esclavo.
String myName = "ESP32-Master";  //Nombre que va a tener el dispositivo Maestro

void setup() {
  bool connected;
  Serial.begin(115200);
  delay(1000);
  SerialBT.begin(myName, true);
  Serial.printf("The device \"%s\" started in master mode, make sure slave BT device is on!\n", myName.c_str());
  SerialBT.setPin(pin);
  Serial.println("Using PIN");
  // connect(address) is fast (up to 10 secs max), connect(slaveName) is slow (up to 30 secs max) as it needs
  // to resolve slaveName to address first, but it allows to connect to different devices with the same name.
  // Set CoreDebugLevel to Info to view devices Bluetooth address and device names
  connected = SerialBT.connect(slaveName);
  Serial.printf("Connecting to slave BT device named \"%s\"\n", slaveName.c_str());
  if(connected) {
    Serial.println("Connected Successfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
    }
  }
  // Disconnect() may take up to 10 secs max
  if (SerialBT.disconnect()) {
    Serial.println("Disconnected Successfully!");
  }
  // This would reconnect to the slaveName(will use address, if resolved) or address used with connect(slaveName/address).
  SerialBT.connect();
  if(connected) {
    Serial.println("Reconnected Successfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to reconnect. Make sure remote device is available and in range, then restart app.");
    }
  } 
}

void loop() {
  // Este pequeño código lo que hace es hacer sonar la melodia 1 en el robot
  SerialBT.println("play 1");
  delay(1000);
}

