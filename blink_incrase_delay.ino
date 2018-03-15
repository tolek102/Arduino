
int ledPin = 13;
int delayPeroid = 100;


void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);        //start serial port
}

void loop() 
{
  Serial.print(delayPeroid);    //send delayPeroid value to serial port
  Serial.print("\n");           //enter
  digitalWrite(ledPin, HIGH);   //led on
  delay(delayPeroid);
  digitalWrite(ledPin, LOW);    //led off
  delay(delayPeroid);
  delayPeroid = delayPeroid + 100;  //incrase delay time
  
  if(delayPeroid > 1000)          //if delay over 1000, set delay to 100
    {
      delayPeroid = 100;
    }
}
