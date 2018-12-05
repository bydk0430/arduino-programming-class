int trig_pin=2;
int echo_pin=3;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  long duration = pulseIn(3, HIGH);

   if(duration == 0 ) {
    return;
  }
  long distance = duration/58.2;
  Serial.println(distance);
  delay(50);

 
  tone(8, 1000,20);
  delay(20);
  noTone(8);

  delay(2 *distance);

}
