#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();

  lcd.backlight();
  lcd.print("light value : ");

}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(light);

  delay(1000);

}
