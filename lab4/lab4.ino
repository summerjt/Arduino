
void setup() {
  Serial.begin(9600);
  delay(10);
}

void loop() {
  int pot1=analogRead(A0);
  int pot2=analogRead(A1);
  int mapPot1=map(pot1, 0, 669, 0, 255); //I found that the max values for my pots were 669
  int mapPot2=map(pot2, 0, 669, 0, 255);
  Serial.print(mapPot1);
  Serial.print(",");
  Serial.println(mapPot2);
}

