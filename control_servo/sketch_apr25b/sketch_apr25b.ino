/*
  Auto-Feed larvae like a boss.

  (Values are tuned for the dynamic range of the small black servo.)

  Tommaso Caudullo
  17.04.2019
*/


#include <Servo.h>
Servo myServo;

static int pinAO = 3;
static int pinAI = A0;
static int tot_iterations = 1;
static long oneDay = 86400000;
static int downPos = 145;
static int upPos = 30;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(3);
  Serial.begin(9600);
  
  myServo.write(upPos);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  
  if (sensorValue > 1000) { // deliver
    for (int iteration = 1; iteration < tot_iterations+1; iteration++) {
    
      myServo.write(downPos);
      delay(1000);
    
      myServo.write(upPos);
      delay(1000);
    }  
  } else if (sensorValue < 20) { // load
    if (myServo.read() < downPos-25) {
      myServo.write(downPos);
      delay(1000);
    }
  } else if (sensorValue>500 & myServo.read() > downPos-25){
    myServo.write(upPos);
    delay(1000);
  }
}
