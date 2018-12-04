// 디지털 신호등
// 레드 pin 13, 옐로 pin 12, 그린 pin 8
int r=13, y=12, g=8;

void setup() {
  // 레드
  pinMode(r,OUTPUT);
  // 옐로
  pinMode(y,OUTPUT);
  // 그린
  pinMode(g,OUTPUT);
}

void loop() {
  // 레드 LED 온 - 오프
  digitalWrite(r,HIGH);
  delay(100);
  digitalWrite(r,LOW);
  delay(100);

  // 옐로 LED 온 - 오프
  digitalWrite(y,HIGH);
  delay(100);
  digitalWrite(y,LOW);
  delay(100);

  // 그린 LED 온 - 오프
  digitalWrite(g,HIGH);
  delay(100);
  digitalWrite(g,LOW);
  delay(100);
}
