/*
 Figproxy Flashlight Test
Demonstrates the arduino recieving data from Figma prototype using the Figproxy utility

Created by Dave Vondle at IDEO 2024 - Modified by Cathal Moran
*/


int led = 9; // set pin 9 as the LED 


void setup() {
  // set LED to output 
  pinMode(led, OUTPUT); 


  // start serial port at 19200 bps:
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  ///////////////////////////////Look for messages from Figma and set LED//////////////////////////
  // if we get a valid byte
  if (Serial.available() > 0) {  
    // get incoming byte:
    char incomingByte = Serial.read();
    //in Figma the Toggle on sends "a",  Toggle off sends "b"
    if(incomingByte=='a'){
      digitalWrite(led, HIGH);
    }else if(incomingByte=='b'){
      digitalWrite(led, LOW);
    }
  }
 
  }
