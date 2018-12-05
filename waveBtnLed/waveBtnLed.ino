// 센서 설정
int trig_pin=2;
int echo_pin=3;
// LED 설정
int r=11,g=12,y=13;
// 버튼 설정
int btn=8;


void setup() {
 Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);

  pinMode(btn, INPUT);

}

void loop() {
  
  btn = digitalRead(8);
  // 센서 거리 측정
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  long duration = pulseIn(3, HIGH);
  long distance = duration/58.2;
  Serial.println(distance);

  // 버튼 on 경우, 길이에 의한 LED 점등
  if(btn == HIGH) {

      if(distance>=5 && distance<10) {
      digitalWrite(r, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      }
      else if(distance<5) {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(y, LOW);
        
      } else  {
      digitalWrite(r ,LOW);
      digitalWrite(g, LOW);
      digitalWrite(y, HIGH);
    }
    
  }
  
}
