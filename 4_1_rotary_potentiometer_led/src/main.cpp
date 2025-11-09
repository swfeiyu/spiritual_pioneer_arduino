#include <Arduino.h>

const int LED = 1;
const int ROTARY_POTENTIOMETER = 26;

void setup()
{
  Serial.begin(9600);
  pinMode(ROTARY_POTENTIOMETER, INPUT);
}

void loop()
{
  int rotaryPotentiometervalue = analogRead(ROTARY_POTENTIOMETER);

  Serial.println(rotaryPotentiometervalue);
  analogWrite(LED, rotaryPotentiometervalue);
}
