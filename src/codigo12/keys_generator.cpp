#include "Arduino.h"
#include <uECC.h>

uint8_t message[] = "Mensaje a cifrar y descifrar para Arduino UNO";
uint8_t signature[64];


//Función de impresión
void printHex(const uint8_t *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (data[i] < 16) Serial.print("0");
        Serial.print(data[i], HEX);
    }
    Serial.println();
}

// Función de generación de números aleatorios
int rng_function(uint8_t *dest, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        dest[i] = analogRead(A0) & 0xFF; // ruido analógico
        delay(1);                        // da tiempo a cambiar la lectura
    }
    return 1;

}
// ---------------------------------------------------

void setup() {
    Serial.begin(9600);
    delay(1000);

    const struct uECC_Curve_t *curve = uECC_secp160r1();

    //Proceso donde se genera una semilla aleatoria
    randomSeed(analogRead(0));  
    uECC_set_rng(&rng_function); 

    uint8_t privateKey[20];
    uint8_t publicKey[40];

    Serial.println("Generando claves...");

    if (!uECC_make_key(publicKey, privateKey, curve)) {
        Serial.println("ERROR: No se pudieron generar las claves!");
        return;
    }

    Serial.println("Clave privada:");
    printHex(privateKey, sizeof(privateKey));

    Serial.println("Clave pública:");
    printHex(publicKey, sizeof(publicKey));


    //Salida ejemplo
    //Clave privada:00D6D6D8DBDEE2E3E3E5E5E5E5E4E2DFDEDCDADA
    //Clave pública:FBC2217CF9683F5535B4C2F35043A86990719930C15A10D84BC2FA11A3BAC4CC7CC88A8D9E5382F7
    Serial.println("\nFirmando mensaje de prueba...");
    if (!uECC_sign(privateKey, message, sizeof(message), signature, curve)) {
      Serial.println("ERROR al firmar!");
      return;
    }

  Serial.println("Firma generada:");
  printHex(signature, sizeof(signature));

  Serial.println("\nVerificando firma...");
  int verified = uECC_verify(publicKey, message, sizeof(message), signature, curve);

  if (verified) {
    Serial.println("FIRMA VERFICADA");
  } else {
    Serial.println("ERROR EN LA VERIFICACIÓN DE FIRMA");
  }

}

void loop() {}
