/*
This is an arduino code to control custom made home tank feeding/training chamber. It controls a servo for feeding and a peristaltic pump for odor delivery. NT- 23/11/2018
*/ 

int motorPinA = A0; // pin that turns on the pump 1
int motorPinB = A1; // pin that turns on the pump 2
int motorPinC = A2; // pin that turns on the pump 3
int foodPin = 9; // pin for feeder
long watertime = 60 ; // pump ON, in seconds
long odortime = 30 ; // pump ON, in seconds
long waittimeShort =2304 ;//2300; // 40min (normal ITI) - a trial length 
long waittimeLong = 38304 ; //10h40 (length of lights off period)-trial time, in seconds
long waittimeBegin = 900; //in seconds, 15min (how long after you start to run the arduino, the first training happens, optional)
long waittimeEnd = 1404; //in seconds, 25min -trial, if you do have a waittimeBegin, to make sure when the code loops, ITI ends up waittimeShort
int interval =4; // interval between odor delivery and food delivery, in seconds (depends on tubing length and flow rate)
int feedTime = 2; //how long the feeding will happen, in seconds
int ledPin = 13;//LED blink pin 



void setup() {
	pinMode(motorPinA, OUTPUT); 
  pinMode(motorPinB, OUTPUT);
  pinMode(motorPinC, OUTPUT);
  pinMode(foodPin, OUTPUT);// set pin9 to an output for feeding
	pinMode(ledPin, OUTPUT); // set pin 13 to an output to use it to turn on the LED

}

void loop() {
 
  delay(waittimeBegin*1000); // seconds to milliseconds  

   // CS+ Trial #1
   
  digitalWrite(motorPinC, HIGH); // turn on the water pump
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);  
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   // turn the LED on 
  digitalWrite(motorPinC, LOW); // turn off the water pump
	digitalWrite(motorPinA, HIGH); // turn on the pump 
	delay(odortime*1000);        // seconds to milliseconds
	digitalWrite(motorPinA, LOW);  // turn off the pump
  digitalWrite(ledPin, LOW);    // turn the LED off 
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   // turn the LED on 
  digitalWrite(foodPin, HIGH);   // turn the LED on 
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    // turn the LED off 
  digitalWrite(ledPin, LOW);    // turn the LED off 

  delay(waittimeShort*1000); // seconds to milliseconds  
  
  // CS- Trial #1 
  digitalWrite(motorPinC, HIGH); // turn on the water pump
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   // turn the LED on 
  digitalWrite(motorPinC, LOW); // turn off the water pump
  digitalWrite(motorPinB, HIGH); // turn on the pump 
  delay(odortime*1000);        // seconds to milliseconds
  digitalWrite(motorPinB, LOW);  // turn off the pump
  digitalWrite(ledPin, LOW);    // turn the LED off
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);   
  
  // CS- Trial #2 
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000); 

  // CS+ Trial #2
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinA, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinA, LOW);  
  digitalWrite(ledPin, LOW);      
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   
  digitalWrite(foodPin, HIGH);   
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    
  digitalWrite(ledPin, LOW); 

  delay(waittimeShort*1000);

  // CS- Trial #3
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);  

// CS- Trial #4
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);  


  // CS+ Trial #3
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinA, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinA, LOW);  
  digitalWrite(ledPin, LOW);      
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   
  digitalWrite(foodPin, HIGH);   
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    
  digitalWrite(ledPin, LOW); 

  delay(waittimeShort*1000); 

  // CS- Trial #5
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);   


// CS- Trial #6
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000); 


  // CS+ Trial #4
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinA, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinA, LOW);  
  digitalWrite(ledPin, LOW);      
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   
  digitalWrite(foodPin, HIGH);   
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    
  digitalWrite(ledPin, LOW); 

  delay(waittimeShort*1000);  

  // CS- Trial #7
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);;

  delay(waittimeShort*1000);  

  // CS- Trial #8
  digitalWrite(motorPinC, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeLong*1000);  


 // CS+ Trial #5
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinA, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinA, LOW);  
  digitalWrite(ledPin, LOW);      
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   
  digitalWrite(foodPin, HIGH);   
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    
  digitalWrite(ledPin, LOW); 

  delay(waittimeShort*1000);   

  // CS- Trial #9 
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);  

  // CS- Trial #10
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);  


  // CS+ Trial #6
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinA, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinA, LOW);  
  digitalWrite(ledPin, LOW);      
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   
  digitalWrite(foodPin, HIGH);   
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    
  digitalWrite(ledPin, LOW); 

  delay(waittimeShort*1000);  

  // CS- Trial #11
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000);  

  // CS- Trial #12
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);
  
  delay(waittimeShort*1000); 


  // CS+ Trial #7
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);   
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinA, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinA, LOW);  
  digitalWrite(ledPin, LOW);      
  delay(interval*1000);
  digitalWrite(ledPin, HIGH);   
  digitalWrite(foodPin, HIGH);   
  delay(feedTime*1000);
  digitalWrite(foodPin, LOW);    
  digitalWrite(ledPin, LOW);    

  delay(waittimeShort*1000); 

  // CS- Trial #13 
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);    
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);     
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeShort*1000); 
  
   // CS- Trial #14 
  digitalWrite(motorPinC, HIGH); 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(watertime*1000); 
  digitalWrite(ledPin, HIGH);  
  digitalWrite(motorPinC, LOW); 
  digitalWrite(motorPinB, HIGH); 
  delay(odortime*1000);        
  digitalWrite(motorPinB, LOW);  
  digitalWrite(ledPin, LOW);    
  delay(interval*1000);
  delay(feedTime*1000);

  delay(waittimeEnd*1000); 

}
