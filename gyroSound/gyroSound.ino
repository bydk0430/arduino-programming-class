// 자이로 라이브러리
#include <MPU6050_tockn.h>
#include <Wire.h>
//  mpu6050 wire 설정
MPU6050 mpu6050(Wire);
// 사운드 핀 설정
int sound_pin=8;
//  y축 설정
int y_angle=0;

void setup() {
  Serial.begin(9600);
 //  mpu6050 설정
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  //mput6050.setGyroOffsets(x,y,z);

}

void loop() {
  //  mpu6050 설정
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();
  //  y축 = mpu6050의 Y축
  y_angle=mpu6050.getAngleY();
  //  y축이 45보다 크거나 -45보다 작으면 소리울림
  if(y_angle >= 45 || y_angle <= -45) {
    tone(sound_pin, 440, 250);
  }
    delay(200);

}
