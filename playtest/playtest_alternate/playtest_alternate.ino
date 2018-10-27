#include <Adafruit_NeoPixel.h>
int rotation=0;
unsigned long time;
int x, y, z;
int xavg, yavg;
int difX, difY;
Adafruit_NeoPixel stripR = Adafruit_NeoPixel(11, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripL = Adafruit_NeoPixel(11, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripDown = Adafruit_NeoPixel(5, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  stripR.begin();
  stripL.begin();
  stripDown.begin();
  stripR.show();
  stripL.show();
  stripDown.show();
  rainbow(20);
  setValues();
  
}

void loop() {
  Sprint(analogRead(A0)-x, analogRead(A1)-y, analogRead(A2)-z);
  setValues();
  
  
  checkX();
  checkRL();
  
  //delay(20);
  
}
void Sprint(int x, int y, int z){
  Serial.print("x = ");       // prints a label
  Serial.print(x);
  Serial.print(" y = ");       // prints a label
  Serial.print(y);
  Serial.print("  z = ");       // prints a label
  Serial.print(z);
  Serial.println("");
}

void setValues(){
  x= (analogRead(A0)+analogRead(A0)+analogRead(A0))/3;
  y= (analogRead(A1)+analogRead(A1)+analogRead(A1))/3;
  z= (analogRead(A2)+analogRead(A2)+analogRead(A2))/3;
  Sprint(x, y, z);
}
void checkRL(){
  int ydif=y-analogRead(A1);
  if(ydif>3){
    theaterChaseL(stripL.Color(255, 0, 255), 50);
    Serial.println("right");
  }
  else if(ydif<-3){
    theaterChaseR(stripR.Color(255, 0, 255), 50);
    Serial.println("left");
  }
}
void checkX(){
  setValues();
  int xdif=analogRead(A0)-x;
  if(abs(xdif)<5){
    rainbow(10);
    Serial.println("rainbow under 5 x change");
  }else if(abs(xdif)<8){
    colorWipeRL(stripL.Color(0, 0, 255), 20);
    Serial.println("b wipe under 8 x change");
  }else if(abs(xdif)>8){
    colorWipeRL(stripL.Color(0, 0, 0, 255), 20);
    colorWipeDown(stripDown.Color(0, 0, 0, 255), 20);
    Serial.println("over 8 color white wipe all");
  }else if(abs(xdif)>12){
    theaterChaseR(stripR.Color(255, 0, 255), 50);
    theaterChaseL(stripL.Color(255, 0, 255), 50);
  }
  else{
    Serial.println("none");
  }
  
}
void alternateRL(uint32_t c){
  for(uint16_t i=0; i<stripR.numPixels(); i=i+2){
    stripR.setPixelColor(i, c);
    stripL.setPixelColor(i, c);
    delay(5);
  }
  for (uint16_t i=1; i<stripR.numPixels(); i=i+2) {
        stripL.setPixelColor(i, c);        
        stripR.setPixelColor(i, c); 
        delay(5);
      }
  for(uint16_t i=0; i<stripR.numPixels(); i++){
        stripL.setPixelColor(i, 0);        
        stripR.setPixelColor(i, 0);
        delay(5);
  }
  
}
void colorWipeRL(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<stripR.numPixels(); i++) {
    stripR.setPixelColor(i, c);
    stripL.setPixelColor(i, c);
    stripR.show();
    stripL.show();
    delay(wait);
  }
}
void colorWipeL(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<stripL.numPixels(); i++) {
    stripL.setPixelColor(i, c);
    stripL.show();
    delay(wait);
  }
}
void colorWipeDown(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<stripDown.numPixels(); i++) {
    stripDown.setPixelColor(i, c);
    stripDown.show();
    delay(wait);
  }
}
void theaterChaseL(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < stripL.numPixels(); i=i+3) {
        stripL.setPixelColor(i+q, c);    //turn every third pixel on
      }
      stripL.show();

      delay(wait);

      for (uint16_t i=0; i < stripL.numPixels(); i=i+3) {
        stripL.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
void theaterChaseR(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < stripR.numPixels(); i=i+3) {
        stripR.setPixelColor(i+q, c);    //turn every third pixel on
      }
      stripR.show();

      delay(wait);

      for (uint16_t i=0; i < stripR.numPixels(); i=i+3) {
        stripR.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
void rainbow(uint8_t wait) {
  uint16_t i, j;
  
  for(j=0; j<256; j++) {
//    if(digitalRead(2)==HIGH){
//      rpm();
//     }
    for(i=0; i<stripL.numPixels(); i++) {
      stripR.setPixelColor(i, Wheel((i+j) & 255));
      stripL.setPixelColor(i, Wheel((i+j) & 255));
      if(i<4){
        stripDown.setPixelColor(i, Wheel((i+j) & 255));
    }else{
      stripDown.setPixelColor(abs(4-i), Wheel((i+j) & 255));
      }
    }
    stripR.show();
    stripL.show();
    stripDown.show();
    delay(wait);
  }
}


uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return stripR.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return stripR.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return stripR.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
