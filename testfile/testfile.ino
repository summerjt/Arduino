int redPin1 = 9;
int greenPin1 = 11;
int bluePin1 = 10;
int redPin2 = 6;
int greenPin2 = 5;
int bluePin2 = 3;

int r = 0;
int g = 0;
int b = 0;

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
  Serial.begin(9600);
}

void loop() {
    
    int switchpin2 = digitalRead(2);
    int switchpin4 = digitalRead(4);
    if(switchpin2 == 1){
      Serial.println(" 2 go");
    }
    if(switchpin4 == 1){
      Serial.println(" 4 go");
    }
    if(switchpin2 == 0){
      Serial.println(" 2 not ");
    }
    if(switchpin4 == 0){
      Serial.println("4 no ");
    }
   
}
