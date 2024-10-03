/* Galvo Mirror Scanning Test
 * 
 * 
 * Produces different wave forms for the intended purpose 
 * of test-driving a pair of 3 mm galvo scanning mirrors. 
 *  
 * This is not a clean and nicely commented script.
 * 
 * Arduino generates voltages using PWM. Please average 
 * the generated signal using an in-series RC circuit 
 * (10kO, 10uF) and amplify output current using an op-amp.
 * 
 * Recording channels: pre-amp, post-amp.
 * 
 * 
 * 
 * Tommaso Caudullo
 * 20 Feb 2019
 * 
 */



const int ledPin = 3;
const int measPin = A0;
const int measPin1 = A1;
const int timer = 2;

const int clamp = 100; // adjust to determine amplitude [ 0 - 255 ]

#define SINUSOID 0
#define STEPS 1
#define SAWTOOTH 2

const int shape = 0; // select wave shape ID

const int maxOUTval = 255 - clamp;
const int minOUTval = 0;

const int maxINval = 5000; // determines digital output resolution
const int minINval = 0;

const float scaling = 0.001 * 1.5; // temporal compression, indicates frequency
                                   // if sinusoidal, second term is Hz

float t = 0.0;

//int ledState = LOW;

float inVal;
int outVal;
int measVal = 0;
int measVal1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(measPin, INPUT);
  pinMode(measPin1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  if (ledState == HIGH){
//    ledState = LOW;
//  } else {
//    ledState = HIGH;
//  }

  t = scaling * millis();

// ----------------------------------------------- //

  switch (shape) {
    case 0:  // sinusoid
      inVal = 2500 * ( sin(t * 3.14 ) + 1 );
      break;
    
    case 1:     // steps
      if (floor(t)/2 == floor(floor(t)/2)) {
        inVal = maxINval;
      } else {
        inVal = minINval;
      }
      break;
  
    case 2:  // sawtooth
      if (floor(t)/2 == floor(floor(t)/2)) {
        inVal = minINval + (t - floor(t)) * (maxINval - minINval);
      } else {
        inVal = minINval;
      }
      break;
  }
  
// ----------------------------------------------- //

  outVal = map(inVal, minINval, maxINval, minOUTval, maxOUTval);
  
  analogWrite(ledPin, outVal);

  measVal = analogRead(measPin);
  measVal1 = analogRead(measPin1);
  
  Serial.print("Time: ");
  Serial.print(t);
  Serial.print(" Input: ");
  Serial.print(inVal);
  Serial.print(" Output: ");
  Serial.print(outVal);
  Serial.print(" Measured (pre-amp): ");
  Serial.print(measVal);
  Serial.print(" Measured (post-amp): ");
  Serial.println(measVal1);

  delay(timer);

  //analogWrite(ledPin, 1000);
  //delay(timer);
}
