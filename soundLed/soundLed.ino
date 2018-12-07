// 사운드 감지 센서 설정
int sound_pin=A0;
// LED, 그린,옐로,레드 설정
int g=11,y=12, r=13;

int count=0;

void setup() {
  Serial.begin(9600);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);

}

void loop() {
  int sound_value=analogRead(A0);
  int light_value=map(sound_value,0,1023,0,255);

  Serial.print("sound value : ");
  Serial.println(sound_value);

  Serial.print("light value : ");
  Serial.println(light_value);

  // 사운드값 1000 넘으면 count
  if( sound_value > 1000) {
    count++;
  }
  //  카운트 5 미만 그린
  if(count<5) {
    analogWrite(g,light_value);

    delay(200);
    //  카운트 5 이상 10 미만 옐로
  } else if(count>=5 && count<10) {
    analogWrite(y,light_value);

    delay(200);
    //  카운트 10이상 20 미만 레드
  }else if(count>=10 && count<20) {
    analogWrite(r,light_value);

    delay(200);
    //  카운트 20 이상 그린,옐로,레드
  } else {
    analogWrite(g,light_value);
    analogWrite(y,light_value);
    analogWrite(r,light_value);

    delay(200);
  }
  // 카운트 횟수 표시
  Serial.print("count : ");
  Serial.println(count);

  delay(200);
}
