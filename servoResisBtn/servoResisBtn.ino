#include <Servo.h>

Servo myservo;

int btn = 12;

void setup() {
  myservo.attach(9);
  pinMode(12,INPUT);
}

void loop() {
  if(digitalRead(btn)==HIGH) {
  int val = analogRead(A0);
  int rad = map(val, 0, 1023, 0, 120);
  myservo.write(rad);
  delay(15);
  }
  
}
