
void setup() {
 Serial.begin(9600);
}

void loop() {
  //  A0 읽어오기
  int a = analogRead(A0);
  Serial.println(a);
}
