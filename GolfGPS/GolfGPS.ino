/* Golf GPS
 *  Author: Michael Burmeister
 *  Date: May 15, 2017
 *  Version 1.0
 *  Description: Display Distance to the hole
 *  
 */

#include <Arduino.h>
#include <string.h>
#include "Util.h"
#include "File.h"

void refresh();

Course C1;
GpsValues G1[18];
Tees T1[5];
Holes H1[5][18];

int ObjectPointer = 0;
int Level = -1;
int Base = -1;

int Lvl[6];
int Prv[6];
bool Itr[6];

int Hole;
int Tee;

void setup() {
  delay(5000);
  Serial.begin(11500);
  Serial1.begin(9600);

  Serial.println("Loading Course");
  
  LoadGolf("Course.txt");

  Serial.println("Course Loaded");


  Tee = 0;
  Hole = 2;

  refresh();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void refresh()
{
  float blat, blon;
  float lat, lon;
  int distance;
  
  Nextion.txt("Course", C1.getName());

  Nextion.txt("Tees", T1[Tee].getName());
  Nextion.txt("Hole", H1[Tee][Hole].getHole());
  Nextion.txt("Par", H1[Tee][Hole].getPar());
  Nextion.txt("Yards", H1[Tee][Hole].getYards());
  Nextion.txt("Hcp", H1[Tee][Hole].getHandicap());

  G1[Hole].getCenter(&blat, &blon);

  G1[Hole].getBack(&lat, &lon);
  distance = Gps.getDistance(blat, blon, lat, lon);
  Nextion.val("Back", distance);

  G1[Hole].getFront(&lat, &lon);
  distance = Gps.getDistance(blat, blon, lat, lon);
  Nextion.val("Front", distance);

  G1[Hole].getCenter(&lat, &lon);
  if (lat > 0)
    distance = Gps.getDistance(blat, blon, lat, lon);
  else
    distance = 0;
  Nextion.val("Center", distance);

  G1[Hole].get100(&lat, &lon);
  if (lat > 0)
    distance = Gps.getDistance(blat, blon, lat, lon);
  else
    distance = 0;
  Nextion.val("M100", distance);

  G1[Hole].get150(&lat, &lon);
  if (lat > 0)
    distance = Gps.getDistance(blat, blon, lat, lon);
  else
    distance = 0;
  Nextion.val("M150", distance);

  G1[Hole].get200(&lat, &lon);
  if (lat > 0)
    distance = Gps.getDistance(blat, blon, lat, lon);
  else
    distance = 0;
  Nextion.val("M200", distance);
  
}

