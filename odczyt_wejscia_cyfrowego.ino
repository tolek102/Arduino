
// co 1 s odczytuje stan wejścia D5

#define inputPin 5


void setup() 
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int reading = digitalRead(inputPin);
  Serial.println(reading);
  delay(1000);
}
