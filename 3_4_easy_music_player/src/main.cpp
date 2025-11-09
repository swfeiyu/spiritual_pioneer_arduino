#include <Arduino.h>
#include "pitches.h"

const int BUZZER = 3;
const int BUTTON0 = 7;
const int BUTTON1 = 6;

void button0Interrupt();
void button1Interrupt();

int melody0[] =
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

int noteDurations0[] =
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

int melody1[] =
{
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4,
    NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4,
    NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_C4,
};

int noteDurations1[] =
{
    4, 4, 4, 4,
    4, 4, 8,
    4, 4, 4, 4,
    4, 4, 8,
    4, 4, 4, 4,
    4, 4, 8,
    4, 4, 4, 4,
    4, 4, 8,
    4, 4, 4, 4,
    4, 4, 8,
    4, 4, 4, 4,
    4, 4, 8,
};

int flag = 0;
int thisNote = 0;
int music_choose = 0;

void setup()
{
  pinMode(BUTTON0, INPUT_PULLUP);
  attachInterrupt(BUTTON0, button0Interrupt, FALLING);
  pinMode(BUTTON1, INPUT_PULLUP);
  attachInterrupt(BUTTON1, button1Interrupt, FALLING);
}

void loop()
{
  if(music_choose == 0)
  {
    for(; thisNote < 34 && flag == 1; thisNote++)
    {
      if(music_choose != 0)
        break;
      int noteDuration = 1000 / noteDurations0[thisNote];
      tone(BUZZER, melody0[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZER);
    }
    if(thisNote == 34)
    {
      thisNote = 0;
    }
  }
  else if(music_choose == 1)
  {
    for(; thisNote < 42 && flag == 1; thisNote++)
    {
      if(music_choose != 1)
        break;
      int noteDuration = 1000 / noteDurations1[thisNote];
      tone(BUZZER, melody1[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZER);
    }
    if(thisNote == 42)
    {
      thisNote = 0;
    }
  }
}

void button0Interrupt()
{
  if(flag == 0)
    flag = 1;
  else
    flag = 0;
}

void button1Interrupt()
{
  if(music_choose == 0)
  {
    music_choose = 1;
    thisNote = 0;
  }
  else if(music_choose == 1)
  {
    music_choose = 0;
    thisNote = 0;
  }
}
