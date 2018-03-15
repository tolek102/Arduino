/* Wyjscie odbiornika podpięte do pinu RECV_PIN
  po wcisnieciu przycisku CH- zwieksza sie opoznienie migania(dioda miga wolniej)
  a po przycisku CH+ zwieksza*/

#include <IRremote.h>

int ledPin = 13;
int RECV_PIN = 3;

int ledState = HIGH;
long prevMill = 0;
long flashDelay = 200;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  //attachInterrupt(digitalPinToInterrupt(RECV_PIN), loop, CHANGE);
}

void loop() 
{
  unsigned long curMill = millis();  //przypisanie aktualnego czasu trwania programu do zmiennej curMill
  if (irrecv.decode(&results))
   { 
     if(results.value == 0xFFA25D)
       {
        flashDelay = flashDelay + 100;  
       }    
     if(results.value == 0xFFE21D && flashDelay > 0)
       {
        flashDelay = flashDelay - 100;          
       }     
     irrecv.resume(); // Receive the next value
     Serial.println(flashDelay);
   }
   
   if(curMill - prevMill > flashDelay) // miganie diodą na timerze o interwale flashDelay
    {
     prevMill = curMill;   
    if (ledState == LOW)
     ledState = HIGH;
    else
     ledState = LOW;
    }
   digitalWrite(ledPin, ledState);   
}

