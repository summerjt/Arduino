//#include <Adafruit_NeoPixel.h>
#include <Servo.h>
       
//Rotary Inputs and Variables
#define INITPIN A11 //white
#define NUMPIN A14 //green
#define onHook A15 //blue
int currentValue = 0; 
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 5;    // the debounce time; increase if the output flickers


//num display commands
#define SEGMENT_ON  HIGH
#define SEGMENT_OFF LOW

//num display pins
int BL = 12; //bottom left
int B = 11; //bottom
int BR = 10; //bottom right
int TR = 9; //top right 
int T = 8; //top 
int TL = 6; //top left
int M = 7; //middle

//LEDS
int str1 = 0;
int str2 = 1;

//int LED = 4; 
int counter; // holds the pulse count for each dial spin
int prevCounter[2]={0, 0};
//prevCounter[0]=0;
//prevCounter[1]=0;
//servo
Servo myServo;
int serv = 53; 

int enablePin = 2;
int motor1Pin = 3;
int motor2Pin = 4;

void setup() {
  Serial.begin(9600);
  // configure the two inputs, and the onboard LED.
  pinMode(INITPIN, INPUT_PULLUP);
  pinMode(NUMPIN, INPUT_PULLUP);
  pinMode(onHook, INPUT_PULLUP);
  pinMode(BL, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(BR, OUTPUT);
  pinMode(TR, OUTPUT);
  pinMode(T, OUTPUT);
  pinMode(TL, OUTPUT);
  pinMode(M, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(str1, OUTPUT);
  pinMode(str2, OUTPUT);
  analogWrite(enablePin, 0);
  //digitalWrite(motor1Pin, HIGH);
  //digitalWrite(motor2Pin, LOW);
  
  lightNumber(20);
  myServo.attach(serv);
  //setupMP3();
  ringTillPickup();
  
}

void loop() {
  
  int initRead = digitalRead (INITPIN); // Is the wheel turning or not?
  static int lastValue = HIGH;  // holds the last read from the pulse pin.

  if (initRead == LOW) {  // If the wheel is turning....
    int newValue = digitalRead (NUMPIN); // check the pulse pin.
    if (newValue != lastValue) { // if it's CHANGED from the last read...
      lastDebounceTime = millis(); // save its clock cycle; we need to check it.
    }
    // If enough time has passed (aka, it's not just a "bounce" from the 
    // analog signal)...
    if ((millis() - lastDebounceTime) > debounceDelay) { 
      // and if the current value is DIFFERENT than the one you just read...
      if (currentValue != newValue) { 
        currentValue = newValue; // make them the same.
        if (newValue == 1) { // If you just set it to a 1...
          counter++; // it just finished a pulse, so add one to the counter.
        }
      }
    }

    lastValue = newValue; // Your new value becomes the old one for comparison.

  } else {
// once the dial returns home and switches the initializing pin OFF,
// you can be sure that there will be no more pulses coming.
// "Counter" is the number dialed. You may now use it for whatever you want.
// This is adjusted for the special case of "0" actually being 10 pulses.
    if (counter > 0) {
      if (counter == 10) {
        Serial.println (0);
        lightNumber(0);
//        for(int i=0; i<3; i++){
//          bellz1();
//        }
      } else if (counter == 1) {
        Serial.println (counter);
        lightNumber(counter);
        
        //digitalWrite(LED, HIGH);

        analogWrite(enablePin, 0);
      } else if (counter == 2) {
        Serial.println (counter);
        lightNumber(counter);
        bellz2();
        //digitalWrite(LED, HIGH);

        analogWrite(enablePin, 0);
        
      } else if (counter == 3) {
        Serial.println (counter);
        lightNumber(counter);
        bellz2();
        bellz1();
        digitalWrite(str1, HIGH);
        digitalWrite(str2, HIGH);


        analogWrite(enablePin, 0);
        
      } else if (counter == 4) {
        Serial.println (counter);
        lightNumber(counter);
        
        //digitalWrite(LED, HIGH);

         motor2();
         
      } else if (counter == 5) {
        Serial.println (counter);
        lightNumber(counter);
        //digitalWrite(LED, HIGH);

        stringLights();
        analogWrite(enablePin, 0);
          
      } else if (counter == 6) {
        Serial.println (counter);
        lightNumber(counter);
        RingNum(6);
        //digitalWrite(LED, HIGH);

        analogWrite(enablePin, 0);
        
      } else if (counter == 7) {
        Serial.println (counter);
        lightNumber(counter);
        motor1();
        //MP3.playTrackNumber(1);
       // digitalWrite(LED, HIGH);

        analogWrite(enablePin, 0);
       
      } else if (counter == 8) {
        Serial.println (counter);
        lightNumber(counter);
        RingNum(8);
        //digitalWrite(LED, HIGH);
        motor1();
        
      } else if (counter == 9) {
        Serial.println (counter);
        lightNumber(counter);
        
        for(int i=0; i<3; i++){
          bellz2();
        }
        analogWrite(enablePin, 0);
        
      } else {
        Serial.println(counter);
        lightNumber(counter);
        analogWrite(enablePin, 0);
      }
    }
// After you're done using it, reset counter so it can start again on the
// next dial.
    prevCounter[0]=prevCounter[1];
    prevCounter[1]=counter;
    counter = 0;
    if((prevCounter[0]==6)&&(prevCounter[1]==9)){
      //sixtyNine();
    }
    //digitalWrite(LED, LOW);
  }  
}
void sixtyNine(){
  for(int i=0; i<6; i++){
    bellz2();
  }
}
void forward(){
  myServo.write(0);
  delay(400);
  myServo.write(100);
  delay(400);
  //reverse();
}
void motorBackwards(){
  digitalWrite(motor1Pin, HIGH);
  digitalWrite(motor2Pin, LOW);
  analogWrite(enablePin, 155);
  delay(1000);
  analogWrite(enablePin, 0);
  
}
void motor1() {
  digitalWrite(motor1Pin, HIGH);
  analogWrite(enablePin, 255);
  delay(100);
  analogWrite(enablePin, 100);
  //delay(100);
  //analogWrite(enablePin, 70);
  delay(4000);
  analogWrite(enablePin, 0);
}
void motor2(){
  analogWrite(enablePin, 255);
  delay(100);
  analogWrite(enablePin, 100);
  //delay(100);
  //danalogWrite(enablePin, 70);
  delay(4000);
  analogWrite(enablePin, 0);
}
void stringLights(){
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(str1, fadeValue);
    analogWrite(str2, fadeValue-10);
    
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(str1, fadeValue);
    analogWrite(str2, fadeValue);
    
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  
}
void RingNum(int selection){
  for(int i=0; i<selection/2; i++){
    forward();
  }
}
