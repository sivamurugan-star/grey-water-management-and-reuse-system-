#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int turbidityPin = A0;
int levelPin = A1;
int relayPin = 2;

void setup()
{
    pinMode(relayPin, OUTPUT);
    lcd.begin(16, 2);
}

void loop()
{
    int turbidity = analogRead(turbidityPin);
    int level = analogRead(levelPin);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tur:");
    lcd.print(turbidity);

    lcd.setCursor(0,1);
    lcd.print("Lvl:");
    lcd.print(level);

    if(turbidity < 500 && level > 300)
    {
        digitalWrite(relayPin, HIGH);
    }
    else
    {
        digitalWrite(relayPin, LOW);
    }

    delay(1000);
}
