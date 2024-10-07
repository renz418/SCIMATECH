#include <Servo.h>

Servo servoX;  // Create servo object for X-axis
Servo servoY;  // Create servo object for Y-axis

// Joystick input pins
const int joyX = A0;  // Joystick X-axis
const int joyY = A1;  // Joystick Y-axis

void setup() {
  servoX.attach(9);  // Attach the X-axis servo to pin 9
  servoY.attach(11); // Attach the Y-axis servo to pin 10

  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Read joystick values
  int xValue = analogRead(joyX); // Read the X-axis value
  int yValue = analogRead(joyY); // Read the Y-axis value

  // Map joystick values (0-1023) to servo angles (0-180)
  int servoXAngle = map(xValue, 0, 1023, 0, 180);
  int servoYAngle = map(yValue, 0, 1023, 0, 180);

  // Set servo positions
  servoX.write(servoXAngle);
  servoY.write(servoYAngle);

  // Debugging output
  Serial.print("X: ");
  Serial.print(servoXAngle);
  Serial.print(" | Y: ");
  Serial.println(servoYAngle);

  delay(15); // Wait for the servos to reach the position
}