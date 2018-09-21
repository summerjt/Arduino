int redPin1 = 9;
int greenPin1 = 11;
int bluePin1 = 10;
int redPin2 = 6;
int greenPin2 = 5;
int bluePin2 = 3;


int r = 0;
int g = 0;
int b = 0;

void setColor(int red, int green, int blue) {
  while ( r != red || g != green || b != blue ) {
    if ( r < red ) r += 1;
    if ( r > red ) r -= 1;

    if ( g < green ) g += 1;
    if ( g > green ) g -= 1;

    if ( b < blue ) b += 1;
    if ( b > blue ) b -= 1;

    _setColor();
    delay(10);
  }
}
void compColor(int red, int green, int blue) {
  while ( r != red || g != green || b != blue ) {
    if ( r < red ) r += 1;
    if ( r > red ) r -= 1;

    if ( g < green ) g += 1;
    if ( g > green ) g -= 1;

    if ( b < blue ) b += 1;
    if ( b > blue ) b -= 1;

    _compColor();
    delay(10);
  }
}

void _compColor(){
  analogWrite(redPin1, r);
  analogWrite(greenPin1, g);
  analogWrite(bluePin1, b);
  analogWrite(redPin2, (255-r));
  analogWrite(greenPin2, (255-g));
  analogWrite(bluePin2, (255-b));
}
void _setColor() {
  analogWrite(redPin1, r);
  analogWrite(greenPin1, g);
  analogWrite(bluePin1, b);
  analogWrite(redPin2, r);
  analogWrite(greenPin2, g);
  analogWrite(bluePin2, b); 
}

void setup() {
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  int buttonVal1 = digitalRead(2);
  int buttonVal2 = digitalRead(4);
  if(buttonVal1 == 0){
    setColor(200, 200, 200);
  }
  if(digitalRead(4)== 1){
    setColor(255, 0, 0);    // red
    setColor(0, 255, 0);    // green
    setColor(0, 0, 255);    // blue
    setColor(255, 255, 0);  // yellow
    setColor(80, 0, 80);    // purple
    setColor(0, 255, 255);  // aqua
  }
  else if(digitalRead(2)==1){
    compColor(255, 0, 0);    // red
    compColor(0, 255, 0);    // green
    compColor(0, 0, 255);    // blue
    compColor(255, 255, 0);  // yellow
    compColor(80, 0, 80);    // purple
    compColor(0, 255, 255);  // aqua
  }
  else if((digitalRead(2) == 0)&&(digitalRead(4)==0)){
    analogWrite(redPin1, 255);
    analogWrite(greenPin1, 255);
    analogWrite(bluePin1, 255);
    analogWrite(redPin2, 255);
    analogWrite(greenPin2, 255);
    analogWrite(bluePin2, 255);
  }
//  if(buttonVal1 == 1)
//  {
//    setColor(255, 0, 0);    // red
//    setColor(0, 255, 0);    // green
//    setColor(0, 0, 255);    // blue
//    setColor(255, 255, 0);  // yellow
//    setColor(80, 0, 80);    // purple
//    setColor(0, 255, 255);  // aqua
//  }
//  else{
//    compColor(255, 0, 0);    // red
//    compColor(0, 255, 0);    // green
//    compColor(0, 0, 255);    // blue
//    compColor(255, 255, 0);  // yellow
//    compColor(80, 0, 80);    // purple
//    compColor(0, 255, 255);  // aqua
//    
//  }
  
}
