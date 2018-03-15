#define ledPin 13
#define dotDelay 200

char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",       //A-I
                    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",    //J-R
                    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };         //S-Z

char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};


void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  char ch;
  if (Serial.available() >0)       //oczekiwanie na odebranie znaku
    {
      ch = Serial.read();      //odczyt otrzymanego znaku
      Serial.print(ch);
      Serial.print(": ");
      if(ch >= 'a' && ch <= 'z')
        {
          flashSeq(letters[ch - 'a']);
        }
      else if(ch >= 'A' && ch <= 'Z')
        {
          flashSeq(letters[ch - 'A']);
        }
      else if(ch >= '0' && ch <= '9')
        {
          flashSeq( numbers[ch - '0']);
        }
      else if (ch == ' ')
        {
          delay(dotDelay *4);    //odstęp pomiędzy błyskami
        }
    }
}

void flashSeq(char* seq)   //odczyt sekwencji znaków
{
  int i = 0;
  Serial.println(seq);
  while (seq[i] != NULL)  //leci po znakach z tablicu do znaku null czyli końca łańcucha
    {
      flashDotOrDash(seq[i]);
      i++;
    }
   delay(dotDelay *3);    //odstęp między literami
}

void flashDotOrDash(char dotOrDash)    //funkcja do rozpoznawania kropki i kreski
{
  digitalWrite(ledPin, HIGH);
  if(dotOrDash == '.')
    {
      delay(dotDelay);
    }
   else
    {
      delay(dotDelay *3);
    }
   digitalWrite(ledPin, LOW);
   delay(dotDelay);      //odstęp pomiędzy błyskami
}  


