int C1=7;
int C2=7;
int C3=13;
int C4=12;
int C5=8;
int R1=11;
int R2=16;
int R3=10;
int R4=14;
int R5=5;
int R6=9;
int R7=6;
int Col[]={C1,C2,C3,C4,C5};
int Row[]={R1,R2,R3,R4,R5,R6,R7};

void setup(){
  pinMode(C1,OUTPUT);
  pinMode(R1,OUTPUT);
  /*
  digitalWrite(C1,HIGH);
  pinMode(C2,OUTPUT);
  digitalWrite(C2,HIGH);
  pinMode(C3,OUTPUT);
  digitalWrite(C3,HIGH);
  pinMode(C4,OUTPUT);
  digitalWrite(C4,HIGH);
  pinMode(C5,OUTPUT);
  digitalWrite(C5,HIGH);
  
  pinMode(R1,OUTPUT);
  digitalWrite(R1,LOW);
  pinMode(R2,OUTPUT);
  digitalWrite(R2,LOW);
  pinMode(R3,OUTPUT);
  digitalWrite(R3,LOW);
  pinMode(R4,OUTPUT);
  digitalWrite(R4,LOW);
  pinMode(R5,OUTPUT);
  digitalWrite(R5,LOW);
  pinMode(R6,OUTPUT);
  digitalWrite(R6,LOW);
  pinMode(R7,OUTPUT);
  digitalWrite(R7,LOW);
  */
}

void loop(){
  digitalWrite(C1,HIGH);
  digitalWrite(R1,LOW);
  delay(500);
  digitalWrite(C1,LOW);
  digitalWrite(R1,HIGH);
/*
  for(int i = 0;i<7;i++){
    digitalWrite(Row[i],LOW);
    for(int j = 0;j<5;j++){
      digitalWrite(Col[j],HIGH);
      delay(500);
      digitalWrite(Col[j],LOW);
      delay(500);
    }
    digitalWrite(Row[i],HIGH);
  }
  */
}
