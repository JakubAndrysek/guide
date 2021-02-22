// Semafor

#include "ALKS.h"

int wait = 1500;
int longWait = 4000;

void setup() {
  // nastaveni digitalniho pinu jako vystupni
  pinMode(L_R, OUTPUT);
  pinMode(L_Y, OUTPUT);
  pinMode(L_G, OUTPUT);
}

void loop() {

  digitalWrite(L_R, HIGH);
  delay(wait);

  digitalWrite(L_Y, HIGH);
  delay(wait);
  
  digitalWrite(L_R, LOW);
  digitalWrite(L_Y, LOW);
  digitalWrite(L_G, HIGH);
  delay(longWait);

  digitalWrite(L_G, LOW);
  delay(wait);

  digitalWrite(L_Y, HIGH);
  delay(wait);
  
  digitalWrite(L_Y, LOW);
  delay(longWait);  


}