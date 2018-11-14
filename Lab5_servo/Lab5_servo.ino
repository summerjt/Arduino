#include <Servo.h>
Servo myServo;
int pot=A0;
int val;
int serv = 3; 

void setup() {
  myServo.attach(serv);

}

void loop() {
  val=analogRead(pot);
  val=map(val, 0, 1023, 0, 180);
  myServo.write(val);
  delay(15);

}
