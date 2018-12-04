// 아날로그 신호등
// 레드 pin ~11, 옐로 pin ~10, 그린 pin ~9
int r=11,y=10, g=9;

void setup() {
  // 레드
  pinMode(r,OUTPUT);
  // 옐로
  pinMode(y,OUTPUT);
  // 그린
  pinMode(g,OUTPUT);
}

void loop() {
  // 불빛 점차적 (0-255까지) 증가
  for(int i=0;i<=255;i++) {
     analogWrite(r, i);
     delay(10);
  }
  // 불빛 점차적 (255-0까지) 감소
    for(int i=255;i>=0;i--) {
     analogWrite(r, i);
     delay(10);
  }
   for(int i=0;i<=255;i++) {
     analogWrite(y, i);
     delay(10);
  }
    for(int i=255;i>=0;i--) {
     analogWrite(y, i);
     delay(10);
  }
   for(int i=0;i<=255;i++) {
     analogWrite(g, i);                                             
     delay(10);
  }
    for(int i=255;i>=0;i--) {
     analogWrite(g, i);
     delay(10);
  }

}
