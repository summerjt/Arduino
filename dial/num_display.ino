void lightNumber(int counter) {

#define SEGMENT_ON  HIGH
#define SEGMENT_OFF LOW

//  int segA = 9; //top right
//int segB = 7; //middle
//int segC = 10; //bottom right
//int segD = 11; //bottom
//int segE = 8; //top 
//int segF = 6; //top left
//int segG = 12; //bottom left

  if(counter==0){
    digitalWrite(BL, SEGMENT_ON);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_OFF);
  }
  else if(counter==1){
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_OFF);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_OFF);
    digitalWrite(TL, SEGMENT_OFF);
    digitalWrite(M, SEGMENT_OFF);
  }
  else if(counter==2){
    digitalWrite(BL, SEGMENT_ON);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_OFF);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_OFF);
    digitalWrite(M, SEGMENT_ON);
    }
  else if(counter==3){
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_OFF);
    digitalWrite(M, SEGMENT_ON);
   }
  else if(counter==4){
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_OFF);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_OFF);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_ON);
    }
  else if(counter==5){
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_OFF);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_ON);
    }
  else if(counter==6){
    digitalWrite(BL, SEGMENT_ON);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_OFF);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_ON);
    }
  else if(counter==7){
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_OFF);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_OFF);
    
    }
  else if(counter==8){
    digitalWrite(BL, SEGMENT_ON);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_ON);
    }
  else if(counter==9){
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_ON);
    digitalWrite(BR, SEGMENT_ON);
    digitalWrite(TR, SEGMENT_ON);
    digitalWrite(T, SEGMENT_ON);
    digitalWrite(TL, SEGMENT_ON);
    digitalWrite(M, SEGMENT_ON);
    }
  else {
    digitalWrite(BL, SEGMENT_OFF);
    digitalWrite(B, SEGMENT_OFF);
    digitalWrite(BR, SEGMENT_OFF);
    digitalWrite(TR, SEGMENT_OFF);
    digitalWrite(T, SEGMENT_OFF);
    digitalWrite(TL, SEGMENT_OFF);
    digitalWrite(M, SEGMENT_OFF);
  }
}
