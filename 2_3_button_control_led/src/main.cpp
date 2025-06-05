#include <Arduino.h>

#define LED 25
#define BUTTON0 7
#define BUTTON1 6

void button0Interrupt();
void button1Interrupt();

int DELAY_TIME = 500;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);

  attachInterrupt(BUTTON0, button0Interrupt, FALLING);
  attachInterrupt(BUTTON1, button1Interrupt, FALLING);

  digitalWrite(LED, LOW);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED, LOW);
  delay(DELAY_TIME);
}

void button0Interrupt()
{
  if (DELAY_TIME < 10000)
  {
    DELAY_TIME += 500;
  }
  else
  {
    DELAY_TIME = 10000;
  }
}

void button1Interrupt()
{
  if (DELAY_TIME > 500)
  {
    DELAY_TIME -= 500;
  }
  else
  {
    DELAY_TIME = 500;
  }
}