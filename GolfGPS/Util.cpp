/*
 * Author Michael Burmeister
 * Date May 18, 2017
 * Version 1.0
 * Description Uitility functions
 */

#include <Arduino.h>
#include <math.h>
#include "Util.h"


GpsCalc::GpsCalc()
{
  
}

float GpsCalc::getDistance(float flat, float flon, float tlat, float tlon)
{

  float dlat = tlat - flat;
  float dlon = tlon - flon;

  dlat = M_PI * dlat / 360;
  dlon = M_PI * dlon / 360;

  float flatr = M_PI * flat / 180;
  float tlatr = M_PI * tlat / 180;

  float i = sin(dlat) * sin(dlat) + cos(flatr) * cos(tlatr) * sin(dlon) * sin(dlon);
  float j = asin(sqrt(i)) * 2;
  j = j * Yards;
  return j;
}

GpsCalc Gps;

NextionClass::NextionClass()
{
  
}

void NextionClass::txt(char *f, char *v)
{
  strcpy(Format, f);
  strcat(Format, ".txt=\"%s\"");
  sprintf(Buffer, Format, v);
  cmd(Buffer);
}

void NextionClass::txt(char *f, int v)
{
  strcpy(Format, f);
  strcat(Format, ".txt=\"%d\"");
  sprintf(Buffer, Format, v);
  cmd(Buffer);
}

void NextionClass::val(char *f, int v)
{
  strcpy(Format, f);
  strcat(Format, ".val=%d");
  sprintf(Buffer, Format, v);
  cmd(Buffer);
}

void NextionClass::cmd(char *c)
{
  Serial1.print(c);
  Serial1.write(0xff);Serial1.write(0xff);Serial1.write(0xff);
  if (Serial1.available() > 0)
  {
    Serial.println(c);
    while (Serial1.available() >0)
    {
      char c = Serial1.read();
      Serial.print(c, HEX);
    }
    Serial.println();
  }
}

NextionClass Nextion;

