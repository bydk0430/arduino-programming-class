#include <SoftwareSerial.h>

// 2번 TX, 3번 RX
SoftwareSerial bluetooth(2, 3); 

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);

  // LED OUTPUT
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
}

void loop()
{
  char val = bluetooth.read();

  if (bluetooth.available())
  {
    Serial.write(bluetooth.read());
  }

  if(val == 'a')
  {
    digitalWrite(7,HIGH);
  }

  if(val == 'b')
  {
    digitalWrite(8, HIGH);
  }

  else if(val == 'c')
  {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  
}
