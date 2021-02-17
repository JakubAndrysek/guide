// Vypis do seriove linky

//nastaveni periferii
void setup() {
  // nastaveni komunikacni rychlosti na 9600 bitu za sekundu
  Serial.begin(9600);
}


//nekonecna smycka
void loop() 
{
  Serial.println("Ahoj svete"); //vypis "Ahoj svete"
  delay(1000);                  //cekej 1 vterinu
}