const int trigPin = 9;
const int echoPin = 10;
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

long duration;
int distance;
double i = 0;
double a = millis();
double c;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();

  Serial.begin(9600);

  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
}

void loop()
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  lcd.print("Distance");
  Serial.println("Hello");

  if(distance>0 & distance<=30)
  {
    if(digitalRead(8) == LOW)
    {
      lcd.clear();
      a = millis();
      while(digitalRead(9) == HIGH)
      {
        c = millis();
        i = (c - a) / 1000;
        lcd.print(i);
        lcd.setCursor(7,0);
        lcd.print("Sec's");
        lcd.setCursor(0,0);
        Serial.println(c);
        Serial.println(a);
        Serial.println(i);
        Serial.println("......");
        delay(100);
      }
    }
  }
 else if(distance>30)
 {
   while(digitalRead(8) == HIGH)
   {
     lcd.setCursor(0,0);
     lcd.print(i);
     lcd.setCursor(11,0);
     lcd.print("");
     lcd.setCursor(0,0);
     delay(100);
   }
 }
}
