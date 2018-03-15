

#include<LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //lcd(RS, E, D4, D5, D6, D7)
int numRows = 2;
int numCols = 16;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(numRows,numCols);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("0123456789012345");
  lcd.setCursor(0, 1);
  lcd.print("0123456789012345");
}

void loop() 
{}
/* if (Serial.available() >0)
  {
    char ch = Serial.read();
    Serial.println(ch);
    if (ch == '#')
    {
      lcd.clear();
    }
    else if (ch == '/')
    {
      lcd.setCursor(0, 1);    //nowy wiersz
    }
    else if (ch == '-')
    {
      lcd.noDisplay();        //wyłącza wyświetlacz
    }
    else if (ch == '+')
    {
      lcd.display();          //włącza wyświetlacz
    }
    else
    {
      lcd.write(ch);
    }
  } 
}
*/
