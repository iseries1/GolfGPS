/*
 * Author Michael Burmeister
 * Date May 18, 2017
 * Version 1.0
 * Description Load Golf Course Data
 * 
 */

 #ifndef _FILE_H
 #define _FILE_H

 #include "Course.h"
 #include "GpsValues.h"
 #include "Tees.h"
 #include "Holes.h"

void doObject(char*);
void doValue(char*);
void extractGps(char*);
void extractLatLon(char*, float*, float*);
void LoadGolf(char*);

const char Obj[18][10] = { "Course", "Gps", "GpsValue", "Tees", "Tee", "H1", "C", "Cy", "N", "V", "P", "S", "H", "Y", "Mr", "Wr", "Ms", "Ws" };
extern int ObjectPointer;
extern int Level;
extern int Base;

extern Course C1;
extern GpsValues G1[18];
extern Tees T1[5];
extern Holes H1[5][18];

extern int Lvl[6];
extern int Prv[6];
extern bool Itr[6];

extern int Hole;
extern int Tee;

#endif
