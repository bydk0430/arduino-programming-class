// 버튼 디지털 신호등
// 레드 pin 13, 옐로 pin 12, 그린 pin 8
int r=13, y=12,g=8;
// 레드버튼 pin 7, 옐로버튼 pin 4, 그린버튼 pin 2
int r_btn=7,y_btn=4,g_btn=2;

void setup() {
  // LED 설정
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
  // 버튼 설정
  pinMode(r_btn,INPUT);
  pinMode(y_btn,INPUT);
  pinMode(g_btn,INPUT);
}

void loop() {
  // 버튼
  r_btn = digitalRead(7);
  y_btn = digitalRead(4);
  g_btn = digitalRead(2);

  delay(100);
  
  // 버튼에 따른 LED 반응
  if(r_btn == HIGH) {
    digitalWrite(r, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
  }
  
  if(y_btn == HIGH) {
    digitalWrite(r, LOW);
    digitalWrite(y, HIGH);
    digitalWrite(g, LOW);
  }
  
  if(g_btn == HIGH) {
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);
  }
}
