#include <Arduino.h>

const int LED = 25;
const int BUTTON = 7;

void buttonInterrupt();

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(BUTTON, buttonInterrupt, FALLING);
}

void loop()
{
  Serial.println("Hello EXTI");
  delay(500);
}

void buttonInterrupt()
{
  if(digitalRead(LED) == HIGH)
  {
    digitalWrite(LED, LOW);
  }
  else if(digitalRead(LED) == LOW)
  {
    digitalWrite(LED, HIGH);
  }
}
