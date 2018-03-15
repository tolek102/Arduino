
// co 1 s odczytuje stan wejścia D5

#define inputPin 5
#define ledPin 13


void setup() 
{
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(inputPin, HIGH);    //włączenie wewnętrznego rezystora podwyższającego pinu 5
}

void loop() 
{
  int reading = digitalRead(inputPin);  //jesli przycisk wcisnięty to 0, inaczej 1
  digitalWrite(ledPin, !reading);       //! po to aby przyciśnięcie powodowało podanie 1
}
