//시리얼통신 라이브러리 호출
#include <SoftwareSerial.h> 
 
int blueTx=2;   
int blueRx=3;   
//시리얼 통신을 위한 객체선언
SoftwareSerial bluetooth(blueTx, blueRx);  

// LCD 라이브러리
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

 
void setup() 
{
  //시리얼모니터
  Serial.begin(9600);   
  //블루투스 시리얼
  bluetooth.begin(9600); 

  lcd.begin();

  lcd.backlight();
  // 화면에 출력할 이모티콘
  lcd.print("(^^)");
}
void loop()
{

  char val = bluetooth.read();
  if (bluetooth.available()) {       
    //블루투스측 내용을 시리얼모니터에 출력
    Serial.write(bluetooth.read());  
  }
  if (Serial.available()) {       
    //시리얼 모니터 내용을 블루투스 측에 WRITE  
    bluetooth.write(Serial.read());  
  }

  if(val == 'l') {
    lcd.scrollDisplayLeft();
    delay(20);
  
  } else if (val=='r') {
    lcd.scrollDisplayRight();
     delay(20);
  }
}
