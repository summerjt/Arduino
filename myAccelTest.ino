int xIn, yIn, zIn; //average values from 3 readings
int compValX, compValY, compValZ;
int xPin=A0;
int yPin= A1;
int zPin=A2;
int digiPin=2;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  Serial.println("Starting");
  
}

void loop() {
  if(digitalRead(2)==HIGH){
    Serial.println("Initial");
    setVals(xIn, yIn, zIn);
    delay(200);
  }
  if(xIn>0){
    setVals(compValX, compValY, compValZ);
  }
}

void setVals(int xI, int yI, int zI){
  int x, y, z;
  for(int i=0;i<3; i++){
    x+=analogRead(xPin);
    y+=analogRead(yPin);
    z+=analogRead(zPin);
  }
  x=x/3;
  y=y/3;
  z=z/3;
  Sprint(x, y, z);
  xI=x;
  yI=y;
  zI=z;
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
