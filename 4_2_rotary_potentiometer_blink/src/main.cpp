#include <Arduino.h>

#include <Arduino.h>

const int LED = 1;
const int ROTARY_POTENTIOMETER = 26;

int DELAY_TIME = 0;
int i = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(ROTARY_POTENTIOMETER, INPUT);

  digitalWrite(LED, LOW);
}

void loop()
{
  int rotaryPotentiometervalue = analogRead(ROTARY_POTENTIOMETER);

  Serial.println(rotaryPotentiometervalue);

  if(rotaryPotentiometervalue < 20)
  {
    digitalWrite(LED, HIGH);
    DELAY_TIME = 0;
    int i = 0;
  }
  else if(rotaryPotentiometervalue >= 20 && rotaryPotentiometervalue < 1024)
  {
    DELAY_TIME = 100 * (rotaryPotentiometervalue / 20 - 1);
    i++;
    if(i >= DELAY_TIME)
    {
      if(digitalRead(LED) == HIGH)
      {
        digitalWrite(LED, LOW);
      }
      else if(digitalRead(LED) == LOW)
      {
        digitalWrite(LED, HIGH);
      }
      i = 0;
    }
    delay(1);
  }
}
