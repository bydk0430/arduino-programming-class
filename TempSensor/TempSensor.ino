#include <dht11.h>
// Signal이 연결된 아두이노의 핀번호
int DHT11PIN = A0;

dht11 DHT11;

void setup() {
  //  시리얼 통신속도 설정
  Serial.begin(9600);

}

void loop() {
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Temp : ");
  Serial.print((float)DHT11.temperature);
  Serial.print(" C ");

  Serial.print("/ RelF: ");
  Serial.print((float)DHT11.humidity);
  Serial.print(" %");
 
  Serial.println();
   
  delay(1000);

}
