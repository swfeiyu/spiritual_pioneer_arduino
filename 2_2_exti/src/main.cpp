#include <Arduino.h>

#define BUTTON 7

void buttonInterrupt();

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(BUTTON, buttonInterrupt, FALLING);
}

void loop() {}

void buttonInterrupt()
{
  Serial.println("Hello EXTI");
}
