
 
void ringTillPickup(){
  //
  while(digitalRead(onHook)==HIGH){
    myServo.write(0);
    delay(400);
    myServo.write(100);
    delay(400);
    //Serial.print(digitalRead(onHook));
    //Serial.println(i);
  }
  if(digitalRead(onHook)==LOW){
    digitalWrite(20, HIGH);
    digitalWrite(22, HIGH);
    
  }
  digitalWrite(20, LOW);
  digitalWrite(22, LOW);
  //setupMP3();
  //MP3.playTrackNumber(1);
  Serial.println("ring Over");
}
