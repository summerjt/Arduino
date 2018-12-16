#include <Servo.h>
//Servo myServo;
int val;
//int serv = 3; 

//void setup() {
  //myServo.attach(serv);

//}



void bellz1(){
  myServo.write(0);
  delay(500);
  myServo.write(80);
  delay(1000);
}
void bellz2(){
  myServo.write(0);
  delay(200);
  myServo.write(80);
  delay(200);
}
