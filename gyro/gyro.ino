// 자이로 라이브러리
#include <MPU6050_tockn.h>
#include <Wire.h>
//  mpu6050 wire 설정
MPU6050 mpu6050(Wire);

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
    
  
}
