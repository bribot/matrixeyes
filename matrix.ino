//PIN Configuration
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
//PIN Array
int C[]={C1,C2,C3,C4,C5};
int R[]={R1,R2,R3,R4,R5,R6,R7};
//Size
int My=5;
int Mx=7;
//Buffer memory
int memX=0,memY=0;
boolean mem[7][5];

//////////////////////////////////////////////
boolean eyes[7][5]={
{1,1,1,1,1},
{1,0,0,0,1},
{1,1,1,1,1},
{0,0,0,0,0},
{1,1,1,1,1},
{1,0,0,0,1},
{1,1,1,1,1}
};

boolean closedEyes[7][5]={
{0,0,1,0,0},
{0,0,1,0,0},
{0,0,1,0,0},
{0,0,0,0,0},
{0,0,1,0,0},
{0,0,1,0,0},
{0,0,1,0,0}
};

///////////////////////////////////////////////

void setup() {
  
  cli();//stop interrupts
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 1300;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
  
  pinMode(C1,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(C3,OUTPUT);
  pinMode(C4,OUTPUT);
  pinMode(C5,OUTPUT);
  
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(R5,OUTPUT);
  pinMode(R6,OUTPUT);
  pinMode(R7,OUTPUT);
  initMatrix();

}

void loop() {
  openAnim(100);
  delay(500);
  closeAnim(100);
  delay(500);
  setImg(eyes);
  delay(500);
}

void clearM(){
  for(int i=0;i<My;i++)
    for(int j=0;j<Mx;j++)
      mem[j][i]=0;
}

void fullM(){
  for(int i=0;i<My;i++)
    for(int j=0;j<Mx;j++)
      mem[j][i]=1;
}

void initAnim(){
  int t=100;
  boolean istate[7][5];
  boolean fstate[7][5];
  for(int i=0;i<Mx;i++){
    for(int j=0;j<My;j++){
      istate[i][j]=mem[i][j];
      fstate[i][j]=eyes[i][j];
    }
  }
  openAnim(t);
  
  for(int i=0;i<Mx;i++){
    for(int j=0;j<My;j++){
      mem[i][j]=fstate[i][j];
      delay(100);

    }
  }
}

void setImg(boolean fstate[][]){
 for(int i=0;i<Mx;i++){
    for(int j=0;j<My;j++){
      mem[i][j]=fstate[i][j];
      delay(100);

    }
  } 
}

void openAnim(int t){
  fullM();
  for(int i=0;i<3;i++){
   line(0,2+i,6,2+i,0);
   line(0,2-i,6,2-i,0);
   delay(t);
  }
}

void closeAnim(int t){
  for(int i=2;i>=0;i--){
   line(0,2+i,6,2+i,1);
   line(0,2-i,6,2-i,1);
   delay(t);
   
  }
}

void line(int x1,int y1,int x2, int y2,boolean s){
  
  mem[x1][y1]=s;
  mem[x2][y2]=s;
  int xt=x1,yt=y1;
  while(yt!=y2 || xt!=x2){
   if(xt!=x2)
     xt++;
   if(yt!=y2)
     yt++;
   mem[xt][yt]=s;
  }
}

void test(float t){
  for(int i=0;i<My;i++){
    for(int j=0;j<Mx;j++){
      dot(j,i,1);
      delay(t);
      dot(j,i,0);
      delay(t);
    }
  }
}
/*
void sweep_OLD(){
  for(int i=0;i<7;i++){
    for(int j=0;j<5;j++){
      dot(j,i,mem[i][j]);
      delay(1);
      dot(j,i,0);
      delay(0.1);
    }
  }
}*/

void dot(int x,int y,boolean s){
  digitalWrite(C[y],s);
  digitalWrite(R[x],!s);
}

void initMatrix(){
  for(int i=0;i<Mx;i++){
    digitalWrite(C[i],LOW);
  }
  for(int i=0;i<My;i++){
    digitalWrite(R[i],HIGH);
  }
}

void sweep(){
  dot(memX,memY,0);
  memX++;
  if(memX>Mx-1){
    memX=0;
    memY++;
    if(memY>My-1)
      memY=0;
  }
  dot(memX,memY,mem[memX][memY]);
}

ISR(TIMER1_COMPA_vect){
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
  sweep();
}

