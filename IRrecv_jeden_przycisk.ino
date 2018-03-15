

#include <IRremote.h>

int ledPin = 13;
int RECV_PIN = 11;


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  //irrecv.blink13(true);
}

int on = 0;
unsigned long last = millis();

void loop() 
{

  if (irrecv.decode(&results))
   { 
     if(results.value == 0xFFA25D) //jeśli wciśnięty CH-
       {
        if(millis() - last > 100)
          {
            on = !on;
            digitalWrite(ledPin, on ? HIGH:LOW); 
          }
        last = millis();
        
        
       }    
    irrecv.resume(); // Receive the next value 
   }
}

