/*
  Auto-Feed larvae like a boss.

  (Values are tuned for the dynamic range of the small black servo.)

  Tommaso Caudullo
  17.04.2019
*/


#include <Servo.h>
Servo myServo;

static int pinAO = 3;
static int tot_iterations = 8;
static long oneDay = 86400000;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(3);
  Serial.begin(9600);
  
  myServo.write(30);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int iteration = 1; iteration < tot_iterations+1; iteration++) {
    //shake
    for (int i = 1; i < 30; i++) {
      myServo.write(50);
      delay(100);
    
      myServo.write(30);
      delay(100);
    }
  
    myServo.write(145);
    delay(3000);

    //shake
    for (int i = 1; i < 15; i++) {
      myServo.write(85);
      delay(400);
    
      myServo.write(145);
      delay(400);
    }

    //shake
    for (int i = 1; i < 15; i++) {
      myServo.write(125);
      delay(100);
    
      myServo.write(145);
      delay(100);
    }
  
    myServo.write(30);
    delay(1000);
  }

  Serial.println(oneDay);
  
  delay(oneDay);
}
