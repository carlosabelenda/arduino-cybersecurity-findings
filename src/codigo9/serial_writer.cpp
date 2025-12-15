#include "Arduino.h"

int index = 0;

void setup() 
{
    Serial.begin(9600);  
}
 
 
void loop() 
{
  //Monto el mensaje a enviar en un String
  String message;
  message.concat("Mensaje ");
  message.concat(index);  
  message.concat(" enviado desde Arduino A");
  //Escribo en el puerto serie
  Serial.write(message.c_str(), message.length());
  //Verifico la salida por el monitor serie
  Serial.println(message);
  delay(1000);
  index++;
}

