# Uvod do Arduina

## IDE - vývojové prostředí
- Arduino IDE / Arduino Pro IDE
- Nahrani / kompilace
- Seriova linka
- Priklady
- Knihovny
- Desky
- Program
  - `setup()`
  - `loop()`
- Základní příkazy `setup()`
  - `Serial.begin(9600)`
  - `pinMode(CisloPinu, OUTPUT)`
  - `pinMode(CisloPinu, INPUT_PULLUP)`
- Základní příkazy `loop()`
  - `Serial.print("Text")`
  - `Serial.println("Text s odradkovanim")`
  - `delay(Milisekynd)`
  - `digitalWrite(CisloPinu, HIGH)`
  - `analogWrite(CisloPinu, PWM)` PWM -> [0-255]
  - ``