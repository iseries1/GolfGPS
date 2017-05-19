/*
 * Author Michael Burmeister
 * Date May 16, 2017
 * Version 1.0
 * Description Do file IO and load classes
 * 
 */

 #include <Arduino.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <SD.h>
 #include "File.h"
 


 void LoadGolf(char *f)
 {
  char Object[512];
  char C;
  bool Start;
  bool Val;
  int i = 0;

  File fp;
  
  if (!SD.begin(10))
  {
    delay(5000);
    Serial.println("SD Not working");
    return;
  }

  if (!SD.exists(f))
  {
    Serial.println("File Not Found");
    return;
  }

  
  fp = SD.open(f);

  Start = false;
  Val = false;
  Tee = 0;
  Hole = 0;
  
  memset(Object, 0, sizeof(Object));
  C = fp.read();
  while (C != 0xff)
  {
    if (C == '{')
    {
      Level++;
      Hole++;
      if (Base == 4)
        Tee++;
      Val = false;
    }

    if (C == '[')
    {
      Itr[Base] = true;
      if (Base == 4)
        Tee = -1;
      Hole = -1;
    }

    if (C == ']')
    {
      Itr[Base] = false;
      if (Lvl[Base] >= Level)
        Base = Prv[Base];
    }

    if (C == ':')
      Val = true;

    if (C == '\"')
    {
      if (Start)
      {
        if (Val)
        {
          doValue(Object);
          Val = false;
        }
        else
          doObject(Object);
        Start = false;
      }
      else
      {
        Start = true;
        memset(Object, 0, sizeof(Object));
        i = 0;
        C = 0;
      }
    }

    if (C == '}')
    {
      Level--;
      if (Lvl[Base] >= Level)
        if (!Itr[Base])
          Base = Prv[Base];
    }

    if (Start)
    {
      if (C > 0)
        Object[i++] = C;
    }

    C = fp.read();
  }
  fp.close();
 }
 
void doObject(char *o)
{
  int i;

  for (i = 0; i < 18; i++)
    if (strcmp(o, Obj[i]) == 0)
      ObjectPointer = i;
  if (ObjectPointer < 6)
  {
    i = Base;
    Base = ObjectPointer;
    Lvl[Base] = Level;
    Prv[Base] = i;
  }
  ObjectPointer = ObjectPointer - 5;
}

void doValue(char *v)
{
  int i;

  switch (ObjectPointer)
  {
    case 1: C1.setCity(v); //C
      break;
    case 2: C1.setCountry(v); //Cy
      break;
    case 3: //N
      if (Base == 5)
        H1[Tee][Hole].setHole(atoi(v));
      if (Base == 4)
        T1[Tee].setName(v);
      if (Base == 2)
        G1[Hole].setHole(atoi(v));
      if (Base == 0)
        C1.setName(v);
      break;
    case 4: extractGps(v); //V
      break;
    case 5: //P
      if (Base == 0)
        C1.setPhone(v);
      if (Base == 5)
        H1[Tee][Hole].setPar(atoi(v));
      break;
    case 6: C1.setState(v); //S
      break;
    case 7: H1[Tee][Hole].setHandicap(atoi(v)); //H
      break;
    case 8: H1[Tee][Hole].setYards(atoi(v)); //Y
      break;
    case 9: T1[Tee].setMr(v); //Mr
      break;
    case 10: T1[Tee].setWr(v); //Wr
      break;
    case 11: T1[Tee].setMs(v); //Ms
      break;
    case 12: T1[Tee].setWs(v); //Ws
      break;
    default:
      break;
  }
}

void extractGps(char *v)
{
  int i, j;
  char b[20];
  float Lat, Lon;

  i = 0;
  extractLatLon(v, &Lat, &Lon);
  G1[Hole].setBack(Lat, Lon);
  i = i + 28;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].setCenter(Lat, Lon);
  i = i + 28;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].setFront(Lat, Lon);
  i = i + 28;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].set100(Lat, Lon);
  i = i + 28;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].set150(Lat, Lon);
  i = i + 28;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].set200(Lat, Lon);
  i = 336;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].setNO1(Lat, Lon);
  i = i + 28;
  memcpy(b, &v[i], 2);
  b[2] = 0;
  j = atoi(b);
  i = i + 2;
  if (j > 0)
  {
    memcpy(b, &v[i], j);
    G1[Hole].setNameNO1(b);
  }
  i = i + j;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].setNO2(Lat, Lon);
  i = i + 28;
  memcpy(b, &v[i], 2);
  b[2] = 0;
  j = atoi(b);
  i = i + 2;
  if (j > 0)
  {
    memcpy(b, &v[i], j);
    G1[Hole].setNameNO2(b);
  }
  i = i + j;
  extractLatLon(&v[i], &Lat, &Lon);
  G1[Hole].setNO3(Lat, Lon);
  i = i + 28;
  memcpy(b, &v[i], 2);
  b[2] = 0;
  j = atoi(b);
  i = i + 2;
  if (j > 0)
  {
    memcpy(b, &v[i], j);
    G1[Hole].setNameNO3(b);
  }
}

void extractLatLon(char *p, float *lat, float *lon)
{
  char b[8];
  float Lat, Lon, Mins;

  memcpy(b, &p[10], 2);
  b[2] = 0;
  Lat = atof(b);
  memcpy(b, &p[12], 2);
  b[2] = '.';
  memcpy(&b[3], &p[14], 4);
  b[7] = 0;
  Mins = atof(b);
  Lat = Lat + Mins / 60;
  memcpy(b, &p[20], 2);
  b[2] = 0;
  Lon = atof(b);
  memcpy(b, &p[22], 2);
  b[2] = '.';
  memcpy(&b[3], &p[24], 4);
  b[7] = 0;
  Mins = atof(b);
  Lon = Lon + Mins / 60;
  if (p[8] == '2')
    Lat = -Lat;
  if (p[18] == '4')
    Lon = -Lon;
  *lat = Lat;
  *lon = Lon;
}
 
