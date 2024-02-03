#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int counter = 0;

void setup() { // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
}

void loop() { // put your main code here, to run repeatedly:
  Serial.println("Please enter a string:");
  lcd.setCursor(0, 1);
  while(Serial.available() == 0) {}
      String string_1 = Serial.readString();
      lcd.clear();
      lcd.print(string_1);


  Serial.println("Please enter another string:");
  lcd.setCursor(0, 1);
  while(Serial.available() == 0) {}
    String string_2 = Serial.readString(); 
    lcd.print(string_2);
}
