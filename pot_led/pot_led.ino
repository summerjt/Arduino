void setup() {
  pinMode(4, OUTPUT);
  
}

void loop() {
  int pot = analogRead(A0);
  int color= map(pot, 0, 1023, 0, 255);
  analogWrite(9, color);
  
}
