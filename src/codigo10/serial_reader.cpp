#include "Arduino.h"

void setup() 
{
    Serial.begin(9600);  
}
 
 
void loop() 
{
    //Solo lee datos si hay algo disponible
    if(Serial.available())
    {
      //Captura el mensaje completo y lo imprime
      String message = Serial.readStringUntil('\n');
      Serial.print("Mensaje recibido en Arduino B -> ");
      Serial.println(message);
    }
    //Hace una espera prudencial
    delay(500);
}
