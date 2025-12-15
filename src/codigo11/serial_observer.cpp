#include <SoftwareSerial.h>
#include "Arduino.h"

// Se leen los datos del Arduino A en el Pin 2 del Arduino C
const byte A_RX_Pin = 2; 
// Se leen los datos del Arduino B en el Pin 4 del Arduino C
const byte B_RX_Pin = 4; 

// Se inicializan los dos puertos de escucha de Arduino C, los puertos de transmision se van a ignorar pero son obligatorios de indicar
SoftwareSerial portA(A_RX_Pin, 3);
SoftwareSerial portB(B_RX_Pin, 5); 

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino C a la escucha...");

  // Habilita la escucha de los puertos
  portA.begin(9600);
  portB.begin(9600);
}

void loop() {
  // Escucha en el puerto A
  portA.listen(); 
  while (portA.available()) {
        String messageA = portA.readStringUntil('\n');
        Serial.print("Mensaje recibido desde A -> ");
        Serial.println(messageA);
  }

  // Escucha en el puerto B
  portB.listen(); 
  while (portB.available()) {
        String messageB = portB.readStringUntil('\n');
        Serial.print("Mensaje recibido desde B -> ");
        Serial.println(messageB);
  }
}
