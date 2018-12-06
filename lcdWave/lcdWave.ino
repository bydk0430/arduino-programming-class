#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig_pin=2, echo_pin=3;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  lcd.begin();

  lcd.backlight();
}

void loop() {
  lcd.clear();

  lcd.home();
  lcd.print("distance value : ");
  
  lcd.setCursor(0,1);
  lcd.print(getDistance(2, 3));

  delay(1000);
}

int getDistance(int aTrig_pin,int aEcho_pin) {
    digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH);

  long distance = duration/58.2;
  Serial.println(distance);
  delay(50);

  return distance;
}
 
