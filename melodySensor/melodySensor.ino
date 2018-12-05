void setup() {
  Serial.begin(9600);

}

void loop() {
  int light = analogRead(A0);
  int hertz = map(light, 0, 1023, 31, 4978);
  tone(8, hertz, 100);
  delay(100);
  noTone(8);
  Serial.println(light);
  Serial.println(hertz);
  delay(200);

}
