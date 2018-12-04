// 테스트 LED 온 - 오프
// LED pin 13
int led = 13;

void setup() {
  //  LED
  pinMode(led, OUTPUT);

}

void loop() {
  // LED 온
  digitalWrite(led,HIGH);

  delay(100);
  // LED 오프
  digitalWrite(led, LOW);

  delay(10000);
}
