int pinin=2;
int pinout1=4;
int pinout2=7;
int pinout3=8;
int pinout4=12;
int pinout5=13;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinin,INPUT);
  pinMode(pinout1, OUTPUT);
  pinMode(pinout2,OUTPUT);
  pinMode(pinout3, OUTPUT);
  pinMode(pinout4, OUTPUT);
  pinMode(pinout5, OUTPUT);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  int v=0;
 
  while(v<5){
    digitalWrite(pinout1, LOW);
    digitalWrite(pinout2,LOW);
    digitalWrite(pinout3,LOW);
    digitalWrite(pinout4,LOW);
    digitalWrite(pinout5,LOW);
    digitalWrite(pinout1, HIGH);
    digitalWrite(pinout2,HIGH);
    digitalWrite(pinout3,HIGH);
    digitalWrite(pinout4,HIGH);
    digitalWrite(pinout5,HIGH);
    digitalWrite(pinout1, LOW);
    digitalWrite(pinout2,LOW);
    digitalWrite(pinout3,LOW);
    digitalWrite(pinout4,LOW);
    digitalWrite(pinout5,LOW);
    int buttonVal = digitalRead(pinin);
    if(buttonVal == 1){
      digitalWrite(pinout1, HIGH);
      if(buttonVal == 0){
        digitalWrite(pinout2, HIGH);
        if(buttonVal == 1){
          digitalWrite(pinout3, HIGH);
          if(digitalRead(pinin) == 1){
            digitalWrite(pinout4, HIGH);
            if(digitalRead(pinin) == 1){
              digitalWrite(pinout5, HIGH);
            }
          }
        }
      }
    }
    if(buttonVal == 0){
      digitalWrite(pinout1, LOW);
      if(buttonVal == 0){
        digitalWrite(pinout2, LOW);
        if(buttonVal == 0){
          digitalWrite(pinout3, LOW);
          if(buttonVal == 0){
            digitalWrite(pinout4, LOW);
            if(buttonVal == 0){
              digitalWrite(pinout5, LOW);
            }
          }
        }
      }
    }
  }
}
