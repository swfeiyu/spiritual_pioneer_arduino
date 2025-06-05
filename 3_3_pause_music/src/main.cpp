#include <Arduino.h>
#include "pitches.h"

#define BUZZER 3
#define BUTTON0 7

void button0Interrupt();

int melody[]=
    {
        NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4,
        NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4,
        NOTE_E4, NOTE_F4, NOTE_G4,
        NOTE_E4, NOTE_F4, NOTE_G4,
        NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
        NOTE_E4, NOTE_C4,
        NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
        NOTE_E4, NOTE_C4,
        NOTE_D4, NOTE_G3,
        NOTE_C4, 0,
        NOTE_D4, NOTE_G3,
        NOTE_C4, 0
    };

int noteDurations[]=
    {
        2, 2, 2, 2,
        2, 2, 2, 2,
        2, 2, 4,
        2, 2, 4,
        2, 2, 2, 2,
        4, 4,
        2, 2, 2, 2,
        4, 4,
        4, 4,
        4, 4,
        4, 4,
        4, 4
    };

int flag = 0;
int thisNote = 0;

void setup()
{
  pinMode(BUTTON0, INPUT_PULLUP);
  attachInterrupt(BUTTON0, button0Interrupt, FALLING);
}

void loop()
{
  for (; thisNote < 34 && flag == 1; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER);
  }
  if (thisNote == 34)
  {
    thisNote = 0;
  }
}

void button0Interrupt()
{
  if (flag == 0)
    flag = 1;
  else
    flag = 0;
}
