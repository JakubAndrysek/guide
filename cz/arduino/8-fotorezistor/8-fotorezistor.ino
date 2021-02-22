#include "ALKS.h"

//nastaveni periferii
void setup() {
  Serial.begin(9600);
}

//nekonecna smycka
void loop() {
  int val = analogRead(PHOTO);
  int m = map(val, 0, 1023, 0, 255);
  Serial.println(m);
  int val = analogRead(PHOTO); // cteni fotorezistoru [vraci 0-1023]
  int m = map(val, 0, 1023, 0, 100); // prepocita cislo na procenta
  Serial.println("Procento svitivosti: " + String(m)); // vypise text + cislo prevede na text a vypise  

  delay(100);
}