/* Golf Course Data
 *  Author: Michael Burmeister
 *  Date: May 15, 2017
 *  Version 1.0
 *  Description: Hold Golf Course Info
 *  
 */

#include <string.h>
#include "Course.h"

Course::Course()
{
  strcpy(N, "");
  strcpy(C, "");
  strcpy(S, "");
  strcpy(Cy, "");
  strcpy(P, "");
}

Course::Course(char *n, char *c, char *s, char *cy, char *p)
{
  setName(n);
  setCity(c);
  setState(s);
  setCountry(cy);
  setPhone(p);
}

void Course::setName(char *n)
{
  strcpy(N, n);
}

char* Course::getName()
{
  return N;
}

void Course::setCity(char *c)
{
  strcpy(C, c);
}

char* Course::getCity()
{
  return C;
}

void Course::setState(char *s)
{
  strcpy(S, s);
}

char* Course::getState()
{
  return S;
}

void Course::setCountry(char *c)
{
  strcpy(Cy, c);
}

char* Course::getCountry()
{
  return Cy;
}

void Course::setPhone(char *p)
{
  strcpy(P, p);
}

char* Course::getPhone()
{
  return P;
}
