#define A 2
#define B 3
#define C 4
#define D 5
#define NUMBER_OF_STEPS_PER_REV 512

void setup(){
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
}

void write(int a,int b,int c,int d){
digitalWrite(A,a);
digitalWrite(B,b);
digitalWrite(C,c);
digitalWrite(D,d);
}

void onestepFW(int s){
write(1,0,0,0);
delay(s);
write(1,1,0,0);
delay(s);
write(0,1,0,0);
delay(s);
write(0,1,1,0);
delay(s);
write(0,0,1,0);
delay(s);
write(0,0,1,1);
delay(s);
write(0,0,0,1);
delay(s);
write(1,0,0,1);
delay(s);
}

void onestepRV(int s){
write(1,0,0,1);
delay(s);
write(0,0,0,1);
delay(s);
write(0,0,1,1);
delay(s);
write(0,0,1,0);
delay(s);
write(0,1,1,0);
delay(s);
write(0,1,0,0);
delay(s);
write(1,1,0,0);
delay(s);
write(1,0,0,0);
delay(s);
}

void runMotorRV(int nsteps){
  int i;
  i=0;
  while(i<nsteps){
  onestepFW(1);
  i++;
  }
}

void runMotorFW(int nsteps){
  int i;
  i=0;
  while(i<nsteps){
  onestepRV(1);
  i++;
  }
}

void feedonce(){
  int nsteps = floor(NUMBER_OF_STEPS_PER_REV/8);

  runMotorFW(nsteps);
  delay(100);
  runMotorRV(nsteps);
}

void loop(){
  const unsigned long SECOND = 1000;
  const unsigned long HOUR = 3600*SECOND;
  const unsigned long DAY = 24*HOUR;
  
  delay(5*SECOND); // 5 sec
  feedonce();

  delay(3*DAY);
}
