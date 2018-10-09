void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
}

void loop() {
  int photo = analogRead(A1);
  int pot = analogRead(A0);
  int red= map(photo, 0, 1023, 0, 255);
  int blue= map(pot, 0, 1023, 0, 255);
  analogWrite(9, red);
  analogWrite(10, blue);
  
}
