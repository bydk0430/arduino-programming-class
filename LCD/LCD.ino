#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();

  lcd.noBacklight();
  lcd.print("Hello, world!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
