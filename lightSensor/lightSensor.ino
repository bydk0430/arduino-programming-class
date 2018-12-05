void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int light = analogRead(A0);
  //(기준값,원래최소값,원래최대값,목표최소값,목표최대값)
  int ledLight = map(light, 0, 516, 255,0);
  analogWrite(9, ledLight);

}
