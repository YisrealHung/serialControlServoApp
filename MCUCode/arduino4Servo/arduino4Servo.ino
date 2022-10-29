#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

String text;

void setup() {
  Serial.begin(115200);
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
}

void loop() {
  while (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte != '\n') {
      text += inByte;
    }
    else {
      String servoNumber = text.substring(0, 2);
      int servoValue = (text.substring(3, 6)).toInt();

      if (servoNumber == "s1") {
        servo1.write(servoValue);
      }
      else if (servoNumber == "s2") {
        servo2.write(servoValue);
      }
      else if (servoNumber == "s3") {
        servo3.write(servoValue);
      }
      else if (servoNumber == "s4") {
        servo4.write(servoValue);
      }
      text = "";
      break;
    }
  }
  delay(15);
}
