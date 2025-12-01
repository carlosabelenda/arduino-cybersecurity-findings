#include "Arduino.h"
#include <EEPROM.h>

//Definimos la dirección de inicio para almacenar la password
#define PASSWORD_ADDRESS 0

//Función para leer una cadena desde la EEPROM que retorna un String
String readEEPROM(int addr) {
  String value = "";
  char c;
  for (int i = addr; i < addr + 50; i++) {
    c = EEPROM.read(i);
    if (c == '\0') break;
    value += c;
  }
  return value;
}


void setup() {

  Serial.begin(9600);
  //Indicamos lo siguiente para asegurar que el Serial está listo antes de empezar
  while (!Serial) { ; }  

  //Recuperamos la password almacenada en la EEPROM
  String password = readEEPROM(PASSWORD_ADDRESS);

  //Mostramos la password recuperada o el mensaje de error
  if (password == "") {
    Serial.println("No hay password almacenado en EEPROM");
  } else {
    Serial.print("Password recuperado: ");
    Serial.println(password);

  }
}

void loop() {
  // nada aquí
}