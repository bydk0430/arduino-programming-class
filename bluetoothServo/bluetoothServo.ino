#include <SoftwareSerial.h>

int blueTx=2;
int blueRx=3;

SoftwareSerial bluetooth(blueTx, blueRx);

#include <Servo.h>

Servo myservo;


void setup() {
  Serial.begin(9600);

  bluetooth.begin(9600);

  myservo.attach(8);
  myservo.write(0);

}

void loop() {

  char val = bluetooth.read();

  if(bluetooth.available()) {
    Serial.write(bluetooth.read());
  }

  if(val == 'l') {
    Serial.println('L');
    for(int i=0;i<100;i++){
      myservo.write(i);
      delay(20);
    }
  } else if (val=='r') {
    Serial.println('R');
    for(int i=100;i>0;i--){
      myservo.write(i);
      delay(20);
    }
  }
  
}
