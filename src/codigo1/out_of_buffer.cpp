#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(100);
  // buffer pequeño: 7 chars + '\0'
  char smallBuf[8];                      
  // Copiamos una cadena literal más larga que el buffer -> overflow
  strcpy(smallBuf, "Hola mundo, esto es demasiado largo");
  // comportamiento indefinido
  Serial.println(smallBuf);              
}

void loop() {
  // nada aquí
}