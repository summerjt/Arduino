const int switchPin = 2;    // switch input
const int motor1Pin = 3;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 9;    // H-bridge enable pin

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
}

void loop() {
  int enablePinVal=digitalRead(switchPin);
  if(enablePinVal==HIGH){
    digitalWrite(motor1Pin, LOW);
    analogWrite(motor2Pin, 104);
  }else{
    analogWrite(motor1Pin, 104);
    digitalWrite(motor2Pin, LOW);
  }

}
