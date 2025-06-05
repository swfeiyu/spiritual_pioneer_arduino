#include <Arduino.h>
#include "pitches.h"

#define BUZZER 3

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

void setup(){}

void loop()
{
  for (int thisNote = 0; thisNote < 34; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER);
  }
}
