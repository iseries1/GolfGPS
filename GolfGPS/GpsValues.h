/*
 * GPS value for golf course
 * Author Michael Burmeister
 * Date May 15, 2017
 * Version 1.0
 * Description Holds GPS position of each hold
 * 
 */

#ifndef _GPSVALUES_H_
#define _GPSVALUES_H_

class GpsValues
{
  private:
  int N;
  float Backo, Backa;
  float Centero, Centera;
  float Fronto, Fronta;
  float N100o, N100a;
  float N150o, N150a;
  float N200o, N200a;
  char NO1[15];
  float O1o, O1a;
  char NO2[15];
  float O2o, O2a;
  char NO3[15];
  float O3o, O3a;

  public:
  GpsValues();
  void setHole(int);
  int getHole(void);
  void setBack(float, float);
  void getBack(float*, float*);
  void setCenter(float, float);
  void getCenter(float*, float*);
  void setFront(float, float);
  void getFront(float*, float*);
  void set100(float, float);
  void get100(float*, float*);
  void set150(float, float);
  void get150(float*, float*);
  void set200(float, float);
  void get200(float*, float*);
  void setNameNO1(char*);
  void setNO1(float, float);
  char* getNameNO1(void);
  void getNO1(float*, float*);
  void setNameNO2(char*);
  void setNO2(float, float);
  char* getNameNO2(void);
  void getN02(float*, float*);
  void setNameNO3(char*);
  void setNO3(float, float);
  char* getNameN03(void);
  void getNO3(float*, float*);
};

#endif
