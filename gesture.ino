#include <Wire.h>
#include <MPU6050.h>



MPU6050 mpu;


void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected!");
  } else {
    Serial.println("MPU6050 connection failed.");
    while (1);  // Stop if MPU not connected
  }

 
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Adjust these thresholds based on your testing
  if (ax > 7000) {
    // Tilt Left
    Serial.println("Left turn gesture detected!");
    digitalWrite(6, LOW);
    delay(500);
  digitalWrite(6, HIGH);
      delay(500);

  }
  else if (ax < -7000) {
    // Tilt Right
    Serial.println("Right turn gesture detected!");
    digitalWrite(7, LOW);
    delay(500);
  digitalWrite(7, HIGH);
      delay(500);
  }
  else {
    // No gesture
   
  }

  delay(200);
}