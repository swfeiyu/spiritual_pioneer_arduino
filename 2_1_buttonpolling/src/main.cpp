#include <Arduino.h>

const int LED = 25;
const int BUTTON = 7;

int flag = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  if(digitalRead(BUTTON) == LOW)
  {
    delay(60);
    if(digitalRead(BUTTON) == LOW && flag == 0)
    {
      if(digitalRead(LED) == HIGH)
      {
        digitalWrite(LED, LOW);
        flag = 1;
      }
      else if(digitalRead(LED) == LOW)
      {
        digitalWrite(LED, HIGH);
        flag = 1;
      }
    }
  }
  if(digitalRead(BUTTON) == HIGH)
  {
    flag = 0;
  }
}
