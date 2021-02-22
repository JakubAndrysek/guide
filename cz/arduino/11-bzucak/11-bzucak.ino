// bzucak

#include "ALKS.h"

void setup() {
  pinMode(PIEZO2, OUTPUT); // piezo pin je vystupni
  pinMode(SW1, INPUT_PULLUP); // pin pro tlacitko je vstupni s pullupem
}

//nekonecna smycka
void loop() {

  if(!digitalRead(SW1))
  {
    digitalWrite(PIEZO2, HIGH); // zapni bzucak
  }
  else
  {
    digitalWrite(PIEZO2, LOW); // vypni bzucak
  }

}