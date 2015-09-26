//main arduino entry points for rover bot

#include "drive_state.h"

int debug = 0;


void setup()
{
  SystemSetup();
  DriveSetup();
  PingSetup();
  StateSetup();
}

void loop()
{
  StateLoop();
  RangeGet();
}


void SystemSetup()
{
  if(debug == 1)
  {
    Serial.begin(9600);
  }
}

void Log(char message[])
{
  if(debug == 1)
  {
    Serial.println(message);
  }
}

//Debug Serial Output
void DebugSetup()
{
  if(debug == 1)
  {
    Serial.begin (9600);
  }
}

