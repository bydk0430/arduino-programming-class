#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig_pin=2, echo_pin=3;
int btn1=12,btn2=13;
int light = A0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.home();
  if(digitalRead(btn1) == HIGH) {
    lcd.print("Distance : ");
    lcd.setCursor(0,1);
    lcd.print(getDistance(2,3));
  } else if (digitalRead(btn2) == HIGH) {
    lcd.print("Light : ");
    lcd.setCursor(0,1);
    lcd.print(getLight(A0));
  } else {
    lcd.print("select button");
  }

  delay(1000);
}
int getLight(int aLight_pin) {
  return analogRead(aLight_pin);
}

int getDistance(int aTrig_pin, int aEcho_pin) {
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH); 
  long distance = duration / 58.2;
  Serial.println(distance);
  delay(100);

  return distance;
}
