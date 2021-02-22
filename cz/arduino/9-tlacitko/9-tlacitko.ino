#include "ALKS.h"

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT_PULLUP); // nastaveni pinu pro tlacitko jako vstupni (se seftwarovym pullupem)
}

void loop() {
  int val = !digitalRead(SW1); // cteni stavy tlacitka (diky pullupu je stav invertovany)
  Serial.println("Stav talcitka: " + String(val));

  delay(100);
}