// Nastaveni jasu - analogWrite

int led = LED_BUILTIN;  // cislo PWM pinu
int brightness = 0;     // nastaveni jasu
int fadeAmount = 5;     // nastaveni kroku

void setup() {
  // nastaveni digitalniho pinu led jako vystupni
  pinMode(led, OUTPUT);
}


void loop() {
  // nastaveni jasu na pinu led
  analogWrite(led, brightness);

  // zmen cislo pinu o nastaveny krok
  brightness = brightness + fadeAmount;

  // zmen znamenko kroku
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  // cekej 30 milisekund
  delay(30);
}
