//po wciśnięciu przycisku zapala isę dioda, po ponownym wciśnięciu wyłącza
//brak likwidacji drgania styków, zamiast tego wprowadzono opóźnienie

#define inputPin 2
#define ledPin 13
int ledValue = LOW;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, LOW);
}

void loop() 
{
  if(digitalRead(inputPin) == HIGH)
  {
    ledValue = !ledValue;
    digitalWrite(ledPin, ledValue);
    delay(200);
  }
}
