//vypis do seriove linky

#include "ALKS.h"

void zhasni()
{
  digitalWrite(L_RGB_R, LOW);
  digitalWrite(L_RGB_G, LOW);
  digitalWrite(L_RGB_B, LOW);
}


void cervena(bool s = true)
{
  digitalWrite(L_RGB_R, s);
}

void zelena(bool s = true)
{
  digitalWrite(L_RGB_G, s);
}

void modra(bool s = true)
{
  digitalWrite(L_RGB_B, s);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(L_RGB_R, red_light_value);
  analogWrite(L_RGB_G, green_light_value);
  analogWrite(L_RGB_B, blue_light_value);
}

void ledJas()
{
  for(int i = 0; i<255; i++)
  {
    RGB_color(i, 0, 0);
    delay(10);
  }
}

void poleLed()
{
  int led[] = {0, 0, 0};
  RGB_color(led[0], led[1], led[2]);
}

void poleLedJas()
{
  int led[] = {0, 0, 0};

  for(; led[0]<255; led[0]++)
  {
    RGB_color(led[0], led[1], led[2]);
    delay(10);
  }

  delay(500);  
}

void poleLedProlinani()
{
  int led[] = {0, 0, 0};

  for(int i = 0; i<3; i++)
  {
    for(led[i] = 0 ; led[i]<255; led[i]++)
    {
      RGB_color(led[0], led[1], led[2]);
      delay(10);
    }
    
    delay(1000);
    zhasni();
    delay(1000);
  }   
}

void setup() {
  pinMode(L_RGB_R, OUTPUT);
  pinMode(L_RGB_G, OUTPUT);
  pinMode(L_RGB_B, OUTPUT);
}

void loop() {

  cervena();
  delay(1000);

  zelena();
  delay(1000);

  modra();
  delay(5000);

  zhasni();
  delay(5000);

  // RGB_color(255, 0, 127);

}