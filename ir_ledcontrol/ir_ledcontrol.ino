/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    
  }

  if (results.value == 0x8C22657B)  // change zero to your IR remote button number
     {
      
           digitalWrite(8, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
  else if (results.value == 0x51E43D1B)  // change zero to your IR remote button number
     {
      
           digitalWrite(8, HIGH);
           delay(100);      // keeps the transistion smooth
            
            
            digitalWrite(8, LOW);
            delay(100);
            
          }
 
  delay(100);
}
