/*
 * Golf Course Data
 * Author Michael Burmeister
 * Date May 15, 2017
 * Version 1.0
 * Description Hold Golf Course Data
 * 
 */

#ifndef _COURSE_H_
#define _COURSE_H_

class Course
{
  private:
  char N[30];
  char C[30];
  char S[30];
  char Cy[5];
  char P[10];

  public:
  Course();
  Course(char*, char*, char*, char*, char*);
  void setName(char*);
  char* getName(void);
  void setCity(char*);
  char* getCity(void);
  void setState(char*);
  char* getState(void);
  void setCountry(char*);
  char* getCountry(void);
  void setPhone(char*);
  char* getPhone(void);
};

#endif
