#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Signal이 연결된 아두이노의 핀번호
int DHT11PIN = A0;

dht11 DHT11;

void setup() {
  //  시리얼 통신속도 설정
  Serial.begin(9600);

  lcd.begin();
  
  lcd.backlight();
  
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
float t = DHT11.temperature;
float rh = DHT11.humidity;

int discom = (float)(9/5*t)-(0.55*(1-(rh/100)))*(((9/5*t)-26)*32);

 String state;
  if(discom < 68) {
    state = "HEAVEN";
  } else if (discom>=68 && discom<75) {
    state = "FINE";
  } else if ( discom>=75 && discom<80) {
    state = "NOT FINE";
  } else {
    state = "HELL";
  }
  

  lcd.print("Temp : ");
  lcd.print((float)t);
  lcd.print(" C ");

  lcd.print("/ RelF : ");
  lcd.print((float)rh);
  lcd.print(" %");
 
  lcd.print("/ State : ");
  lcd.print(state);
   
  delay(2000);

 

  Serial.print("Temp : ");
  Serial.print(t);
  Serial.print(" C ");

  Serial.print("/ RelF: ");
  Serial.print(rh);
  Serial.print(" %");

  Serial.print("/ State  : ");
  Serial.print(state);
 
  Serial.println();
   
  delay(2000);

}
