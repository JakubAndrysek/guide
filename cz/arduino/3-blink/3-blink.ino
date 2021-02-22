// Blikej LEDkou

// nastaveni periferii
void setup() {
  // nastaveni digitalniho pinu LED_BUILTIN jako vystupni
  pinMode(LED_BUILTIN, OUTPUT);
}

// nekonecna smycka
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // rozsvid LED (HIGH zapne digitalni vystup)
  delay(1000);                       // cekej 1 vterinu
  digitalWrite(LED_BUILTIN, LOW);    // zhasni LED (LOW vypne digitalni vystup)
  delay(1000);                       // cekej 1 vterinu
}