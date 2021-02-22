// Jednoduchy jas

int wait = 0;

// nastaveni periferii
void setup() {
  // nastaveni digitalniho pinu LED_BUILTIN jako vystupni
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

// nekonecna smycka
void loop() {

  wait++;
  Serial.println(wait);
  
  digitalWrite(LED_BUILTIN, HIGH);  // rozsvid LED (HIGH zapne digitalni vystup)
  delay(wait);                      // cekej wait vterinu
  digitalWrite(LED_BUILTIN, LOW);   // zhasni LED (LOW vypne digitalni vystup)
  delay(wait);                      // cekej 1 vterinu
}
