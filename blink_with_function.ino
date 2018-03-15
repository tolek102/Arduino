
int ledPin = 13;
int ledPin2 = 12;
int delayPeroid = 100;
int delayIncrase = 100;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);        //start serial port
}

void loop() 
{

    for(int i = 0; i < 9; i++)          //delay incrasing to 1000 and decrasing to 100 
    {
      Serial.print(delayPeroid);    //send delayPeroid value to serial port
      Serial.print("\n");           //enter
      flash();
      delayPeroid = delayPeroid + delayIncrase;  //incrase delay time
    }
    
    delayIncrase = -delayIncrase;
    
}

void flash()
{
  digitalWrite(ledPin, HIGH);   //led on
  digitalWrite(ledPin2, LOW);
  delay(delayPeroid);
  digitalWrite(ledPin, LOW);    //led off
  digitalWrite(ledPin2, HIGH);
  delay(delayPeroid);
  
}
