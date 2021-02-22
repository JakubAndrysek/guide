// Pokrocilejsi vypis do seriove linky

// nastaveni periferii
void setup() {
  // nastaveni komunikacni rychlosti na 9600 bitu za sekundu
  Serial.begin(9600);
}


// nekonecna smycka
void loop() 
{
  Serial.println("Vypis s odradkovanim");
  Serial.print("Vypis normalne");

  int cislo = 5;
  Serial.println(cislo);

  String text = "Tohle je muj string";
  Serial.println(text);

  String k = "Ahoj";
  String l = "svete";

  Serial.println(k + "-" + l);

  Serial.print("\n\n\n\n");
  
  delay(10000);
}