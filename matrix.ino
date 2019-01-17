int C1=12;
int C2=4;
int C3=10;
int C4=9;
int C5=5;
int R1=8;
int R2=13;
int R3=7;
int R4=11;
int R5=2;
int R6=6;
int R7=3;

int C[]={C1,C2,C3,C4,C5};
int R[]={R1,R2,R3,R4,R5,R6,R7};
void setup() {
  pinMode(C1,OUTPUT);
  digitalWrite(C1,LOW);
  pinMode(C2,OUTPUT);
  digitalWrite(C2,LOW);
  pinMode(C3,OUTPUT);
  digitalWrite(C3,LOW);
  pinMode(C4,OUTPUT);
  digitalWrite(C4,LOW);
  pinMode(C5,OUTPUT);
  digitalWrite(C5,LOW);
  
  pinMode(R1,OUTPUT);
  digitalWrite(R1,HIGH);
  pinMode(R2,OUTPUT);
  digitalWrite(R2,HIGH);
  pinMode(R3,OUTPUT);
  digitalWrite(R3,HIGH);
  pinMode(R4,OUTPUT);
  digitalWrite(R4,HIGH);
  pinMode(R5,OUTPUT);
  digitalWrite(R5,HIGH);
  pinMode(R6,OUTPUT);
  digitalWrite(R6,HIGH);
  pinMode(R7,OUTPUT);
  digitalWrite(R7,HIGH);

}

void loop() {
  for(int i=0;i<7;i++){
    digitalWrite(R[i],LOW);
    for(int j=0;j<5;j++){
      digitalWrite(C[j],HIGH);
      delay(100);
      digitalWrite(C[j],LOW);
    }
    digitalWrite(R[i],HIGH);
  }
  /*
  digitalWrite(C1,HIGH);
  digitalWrite(R1,LOW);
  delay(500);
  digitalWrite(R1,HIGH);
  digitalWrite(C1,LOW);
  delay(500);
  */
}
