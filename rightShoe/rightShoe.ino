#include <Adafruit_NeoPixel.h>
int x, y, z; //unchanging 
int xC, yC, zC; //variables for change values
//int xDif, yDif, zDif; //compare values
int wait=20;
//pins
int pinX = A0;
int pinY = A1;
int pinZ= A3;
#define PIN 5

//LED strip lengths
int right = 10;
int left = 20;
int bottom = 25;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  strip.begin();
  strip.show();
  //setVals(x, y, z);
  x=analogRead(pinX);
  y=analogRead(pinY);
  z=analogRead(pinZ);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  
  rainbow(20);
}
void Sprint(int x2, int y2, int z2){
  Serial.print("x = ");       // prints a label
  Serial.print(x2);
  Serial.print(" y = ");       // prints a label
  Serial.print(y2);
  Serial.print("  z = ");       // prints a label
  Serial.print(z2);
  Serial.println("");
}
void setVals(int xI, int yI, int zI){
  int x1, y1, z1;
  for(int i=0;i<3; i++){
    x1+=analogRead(A0);
    y1+=analogRead(A1);
    z1+=analogRead(A2);
  }
  x1=x1/3;
  y1=y1/3;
  z1=z1/3;
  Sprint(x1, y1, z1);
  xI=x1;
  yI=y1;
  zI=z1;
}
void rainbow(uint8_t wait) {
  uint16_t i, j;
  
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
      strip.setPixelColor(i, Wheel((i+j) & 255));
      if(i<4){
        strip.setPixelColor(i, Wheel((i+j) & 255));
    }else{
      strip.setPixelColor(abs(4-i), Wheel((i+j) & 255));
      }
    }
    strip.show();
    delay(wait);
  }
}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



void powerUp(){
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=left; i < bottom; i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));
        //turn every third pixel on
        delay(wait);
      }
      strip.show();

      

      for (uint16_t i=left; i< bottom ; i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
void turnRight(){
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0 ; i < right; i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        
      }
      
      strip.show();

      //delay(60);

      for (uint16_t i=0; i< right ; i=i+3) {
        strip.setPixelColor(i+q, 0);  
        //turn every third pixel off
        //delay(5);
      }
      for(int i=left; i<bottom; i++){
        strip.setPixelColor(i+q, 0); 
      }
      strip.show();
    }
  }
}
//forward try
void turnLeft(){
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=right; i < left+1; i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        delay(10);
      }
      strip.show();

      //delay(60);

      for (uint16_t i=right; i<left+1; i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
        delay(5);
      }
      strip.show();
      
    }
  }
}
void clearAll(){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, 0);
  }
}
int getAverageX(){
  int q=0;
  for( int i=0; i<3; i++){
    q=q+analogRead(pinX);
  }
  q=q/3;
  Serial.print("average: ");
  Serial.println(q);
  return q;
}
int getAverageY(){
  int q=0;
  for( int i=0; i<3; i++){
    q=q+analogRead(pinY);
  }
  q=q/3;
  Serial.print("averageY: ");
  Serial.println(q);
  return q;
}
void loop() {
  Serial.println("change");
  xC= getAverageX();
  yC= getAverageY();
  
 Serial.println(x);
  Serial.println(xC);
  Serial.println(y);
  Serial.println(yC);
  int xDif=xC-x;
  int yDif=yC-y;
  Serial.print("xDif: ");
  Serial.println(xDif);
  Serial.print("yDif: ");
  Serial.println(yDif);
  //wait=100-xDif;
  //turnRight();
//  delay(20);
//  turnLeft();
//  delay(20);
//  powerUp();
  //wait=map(abs(xDif), 100, 600, 200, 20);

  if(analogRead(pinY)-y>100){
    Serial.println("right");
    turnRight();
    
  } else if(analogRead(pinY)-y<-10){
    Serial.println("left");
    turnLeft();
    
  }else {
    if(abs(z-zC)>5){
    powerUp();
  }else if(abs(xDif)>0){
    turnLeft();
    turnRight();
    powerUp();
  }else{
    rainbow(20);
  }
  rainbow(20);
}
}
