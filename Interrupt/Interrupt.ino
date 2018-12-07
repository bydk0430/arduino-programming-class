int btn1=2;
int btn2=3;

volatile int count1=0;
volatile int count2=1;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  attachInterrupt(0, btn1ISR, FALLING);
 // attachInterrupt(1, btn2ISR, LOW);
  
}

void loop() {
  delay(1000);
}

void btn1ISR() {
  count1 += 1;
  Serial.print("count1 : ");
  Serial.println(count1);
}

void btn2ISR() {
  count2 += 1;
  Serial.print("count2 : ");
  Serial.println(count2);
}
