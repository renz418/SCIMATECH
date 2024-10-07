 #include <Servo.h>

const int joystickXPin = A0;
const int servo1Pin = 9;             

Servo servo1; 


void setup() {
  servo1.attach(servo1Pin);

  Serial.begin(2000);
}

void loop() {

  // Read the joystick values
 int joystickXValue = analogRead(joystickXPin);

 int servo1Position = map(joystickXValue, 0, 1023, 0, 120);

 servo1.write(servo1Position);

  Serial.print(" , X-axis: ");
  Serial.print(servo1Position);
}
  