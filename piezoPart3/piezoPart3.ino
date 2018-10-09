int light=A0;
int piezo=9;
void setup() {
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop() {
  int lightVal=analogRead(light);
  Serial.println(lightVal);
  int freq = map(lightVal, 40, 800, 1000, 2000);
  tone(piezo, freq);
}
