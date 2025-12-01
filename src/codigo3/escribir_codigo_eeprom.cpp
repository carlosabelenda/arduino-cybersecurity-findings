#include "Arduino.h"
#include <EEPROM.h>

//Definimos la dirección de inicio para almacenar la password
#define PASSWORD_ADDRESS 0

//Función para escribir una cadena en la EEPROM en la dirección especificada
void writeEEPROM(int addr, String data) {
 // Forzamos un tipo de dato a Address y nos aseguramos de no exceder el tamaño de la EEPROM
  if ((size_t)addr + data.length() + 1 > EEPROM.length()) {
    Serial.println("No hay espacio suficiente en EEPROM");
    return;
  }

  //Byte a byte escribimos la cadena en la EEPROM
  for (size_t i = 0; i < data.length(); i++) {
    EEPROM.write(addr + i, data[i]);
  }
  EEPROM.write(addr + data.length(), '\0');
}

void setup() {
  Serial.begin(9600);

  //Llamamos a la función de escritura para guardar la password en la EEPROM
  writeEEPROM(PASSWORD_ADDRESS, "mi_password");

  Serial.println("EEPROM escrita con éxito");
}

void loop() {
  // nada aquí
}