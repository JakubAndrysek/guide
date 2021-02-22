// Potenciometr

#include "ALKS.h"

int wait = 1500;
int longWait = 4000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(POT1); // cteni potenciometru [vraci 0-1023]
  int m = map(val, 0, 1023, 0, 100); // prepocita cislo na procenta
  Serial.println("Procento otoceni: " + String(m)); // vypise text + cislo prevede na text a vypise

  delay(100);
}