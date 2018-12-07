// LCD 라이브러리
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sound_pin=A0;

void setup() {
  Serial.begin(9600);
  
  lcd.begin();

  lcd.backlight();
  // 화면에 출력할 이모티콘
  lcd.print("(^^)");
}

void loop() {
  int sound_value=analogRead(sound_pin);

  Serial.print("sound value : ");
  Serial.println(sound_value);
  // 사운드값이 1000 이상이면 오른칸으로 이동
  if(sound_value>=1000) {
    lcd.scrollDisplayRight();
  }
  delay(1000);
  // 사운드값이 1000 미만이면 왼칸으로 이동
 if(sound_value<1000) {
    lcd.scrollDisplayLeft();
  }
  delay(1000);


  
}
