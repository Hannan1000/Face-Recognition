#include <AFMotor.h>

AF_DCMotor motor1(1); // Motor connected to M1
AF_DCMotor motor2(2); // Motor connected to M2

const int xPin = A0;  // X-axis of the accelerometer
const int yPin = A1;  // Y-axis of the accelerometer
const int zPin = A2;  // Z-axis of the accelerometer

void setup() {
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  int zValue = analogRead(zPin);

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("\tY: ");
  Serial.print(yValue);
  Serial.print("\tZ: ");
  Serial.println(zValue);

  // Adjust these threshold values based on your accelerometer and hand gestures
  if (xValue > 600) {
    // Move the car forward
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  } else if (xValue < 400) {
    // Move the car backward
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  } else {
    // Stop the car
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }

  delay(100);
}
