/*
 * GPS locations for golf course
 * Author Michael Burmeister
 * Date May 15, 2017
 * Version 1.0
 * Description Hold each hole and positions
 * 
 */

 #include <string.h>
 #include "GpsValues.h"
  
 GpsValues::GpsValues()
 {
  N = 0;
  Backa = 0.0f;
  Backo = 0.0f;
  Centera = 0.0f;
  Centero = 0.0f;
  Fronta = 0.0f;
  Fronto = 0.0f;
  N100a = 0.0f;
  N100o = 0.0f;
  N150a = 0.0f;
  N150o = 0.0f;
  N200a = 0.0f;
  N200o = 0.0f;
  O1a = 0.0f;
  O1o = 0.0f;
  O2a = 0.0f;
  O2o = 0.0f;
  O3a = 0.0f;
  O3o = 0.0f;
  setNameNO1("");
  setNameNO2("");
  setNameNO3("");
 }

void GpsValues::setHole(int h)
{
  N = h;
}

int GpsValues::getHole()
{
  return N;
}

void GpsValues::setBack(float lat, float lon)
{
  Backa = lat;
  Backo = lon;
}

void GpsValues::getBack(float *lat, float *lon)
{
  *lat = Backa;
  *lon = Backo;
}

void GpsValues::setCenter(float lat, float lon)
{
  Centera = lat;
  Centero = lon;
}

void GpsValues::getCenter(float *lat, float *lon)
{
  *lat = Centera;
  *lon = Centero;
}

void GpsValues::setFront(float lat, float lon)
{
  Fronta = lat;
  Fronto = lon;
}

void GpsValues::getFront(float *lat, float *lon)
{
  *lat = Fronta;
  *lon = Fronto;
}

void GpsValues::set100(float lat, float lon)
{
  N100a = lat;
  N100o = lon;
}

void GpsValues::get100(float *lat, float *lon)
{
  *lat = N100a;
  *lon = N100o;
}

void GpsValues::set150(float lat, float lon)
{
  N150a = lat;
  N150o = lon;
}

void GpsValues::get150(float *lat, float *lon)
{
  *lat = N150a;
  *lon = N150o;
}

void GpsValues::set200(float lat, float lon)
{
  N200a = lat;
  N200o = lon;
}

void GpsValues::get200(float *lat, float *lon)
{
  *lat = N200a;
  *lon = N200o;
}

void GpsValues::setNameNO1(char *n)
{
  strcpy(NO1, n);
}

void GpsValues::setNO1(float lat, float lon)
{
  O1a = lat;
  O1o = lon;
}

char* GpsValues::getNameNO1()
{
  return NO1;
}

void GpsValues::getNO1(float *lat, float *lon)
{
  *lat = O1a;
  *lon = O1o;
}

void GpsValues::setNameNO2(char *n)
{
  strcpy(NO2, n);
}

void GpsValues::setNO2(float lat, float lon)
{
  O2a = lat;
  O2o = lon;
}

char* GpsValues::getNameNO2()
{
  return NO2;
}

void GpsValues::getN02(float *lat, float *lon)
{
  *lat = O2a;
  *lon = O2o;
}

void GpsValues::setNameNO3(char *n)
{
  strcpy(NO3, n);
}

void GpsValues::setNO3(float lat, float lon)
{
  O3a = lat;
  O3o = lon;
}

char* GpsValues::getNameN03()
{
  return NO3;
}

void GpsValues::getNO3(float *lat, float *lon)
{
  *lat = O3a;
  *lon = O3o;
}

