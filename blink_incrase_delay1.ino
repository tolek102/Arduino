
int ledPin = 13;
int delayPeroid = 100;
int count = 0;
int delayIncrase = 100;

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
  delayPeroid = delayPeroid + delayIncrase;  //incrase delay time
  count ++;
  if(count == 9)          //delay incrasing to 1000 and decrasing to 100 
    {
      count = 0;
      delayIncrase = -delayIncrase;
    }
}
