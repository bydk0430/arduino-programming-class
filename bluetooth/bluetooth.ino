//시리얼통신 라이브러리 호출
#include <SoftwareSerial.h> 
 
int blueTx=2;   
int blueRx=3;   
//시리얼 통신을 위한 객체선언
SoftwareSerial mySerial(blueTx, blueRx);  
 
void setup() 
{
  //시리얼모니터
  Serial.begin(9600);   
  //블루투스 시리얼
  mySerial.begin(9600); 
}
void loop()
{
  if (mySerial.available()) {       
    //블루투스측 내용을 시리얼모니터에 출력
    Serial.write(mySerial.read());  
  }
  if (Serial.available()) {       
    //시리얼 모니터 내용을 블루투스 측에 WRITE  
    mySerial.write(Serial.read());  
  }
}
