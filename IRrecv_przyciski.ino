#include <IRremote.h>
#include <IRremoteInt.h>




int ledPin = 13;
int RECV_PIN = 11;
int flashDelay = 100;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  //attachInterrupt(1, loop, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RECV_PIN), loop, CHANGE);
}

int on = 0;
unsigned long last = millis();

void loop() 
{
  flash();
  if (irrecv.decode(&results))
   { 
     if(results.value == 0xFFA25D)
       {
        if(millis() - last > 100)
        {
            flashDelay = flashDelay + 100;  
        }
        last = millis();
       }    
     
     if(results.value == 0xFFE21D && flashDelay > 0)
       {
        if(millis() - last > 100)
          {
            flashDelay = flashDelay - 100;
          }
        last = millis();
       }    
  
  irrecv.resume(); // Receive the next value
  Serial.println(flashDelay);

   }
}

void flash()
{
  
  digitalWrite(ledPin, HIGH);
  delay(flashDelay);
  digitalWrite(ledPin, LOW);
  delay(flashDelay);
}
