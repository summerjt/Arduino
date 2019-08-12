/*  Soil Mositure Basic Example
    This sketch was written by SparkFun Electronics
    Joel Bartlett 
    August 31, 2015

    Basic skecth to print out soil moisture values to the Serial Monitor 

    Released under the MIT License(http://opensource.org/licenses/MIT)
*/

int val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 
int soilPower = 7;//Variable for Soil moisture Power

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

//Cone pins

//int cone1 = 3;
//int cone2= 5;


void setup() 
{
  Serial.begin(9600);   // open serial over USB

  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
//  analogWrite(cone1, HIGH);
//  analogWrite(cone1, HIGH);
}

void loop() 
{
Serial.print("Soil Moisture = ");    
//get soil moisture value from the function below and print it
Serial.println(readSoil());
int color=map(val, 0, 880, 0, 6);
if(color==0){
  setColor(255, 0, 0);  //red
}else if(color==1){
 setColor(175, 255, 0); //orange?
}
else if(color==2){
  setColor(255, 255, 0);  // yellow
}
else if(color==3){
  setColor(255, 255, 0); //green
}
else if(color==4){
  setColor(0, 255, 255);  // aqua
}
else if(color==5){
  setColor(0, 0, 255);  // blue
}
else if(color==6){
  setColor(80, 0, 80);  // purple
}
//This 1 second timefrme is used so you can test the sensor and see it change in real-time.
//For in-plant applications, you will want to take readings much less frequently.
delay(1000);//take a reading every second
}
//This is a function used to get the soil moisture content
int readSoil()
{

    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
