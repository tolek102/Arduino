

#include <IRremote.h>

int ledPin = 13;
int rel_1 = 5;
int rel_2 = 6;
int RECV_PIN = 3;


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  
  pinMode(ledPin, OUTPUT);
  pinMode(rel_1, OUTPUT);
  pinMode(rel_2, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
}

int on1 = 0;
int on2 = 0;
unsigned long last = millis();

void loop() 
{

  if (irrecv.decode(&results))
   { 
     if(results.value == 0xFFA25D) //jeśli wciśnięty CH-
       {
        if(millis() - last > 100)
          {
            on1 = !on1;
            digitalWrite(rel_1, on1 ? HIGH:LOW); 
          }
        last = millis();     
       }    
       
       if(results.value == 0xFFE21D) //jeśli wciśnięty CH-
       {
        if(millis() - last > 100)
          {
            on2 = !on2;
            digitalWrite(rel_2, on2 ? HIGH:LOW); 
          }
        last = millis();     
       }    
    irrecv.resume(); // Receive the next value 
   }
}

