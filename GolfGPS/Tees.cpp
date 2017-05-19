/*
 * Author Michael Burmeister
 * Date May 16, 2017
 * Version 1.0
 * Description Hold Golf Course Tee positions
 * 
 */

 #include <Arduino.h>
 #include <string.h>
 #include "Tees.h"


 Tees::Tees()
 {
  setName("");
  setMr("");
  setWr("");
  setMs("");
  setWs("");
 }

 void Tees::setName(char *n)
 {
  strcpy(N, n);
 }

 char* Tees::getName()
 {
  return N;
 }

 void Tees::setMr(char *r)
 {
  strcpy(Mr, r);
 }

 char* Tees::getMr()
 {
  return Mr;
 }

 void Tees::setWr(char *r)
 {
  strcpy(Wr, r);
 }

 char* Tees::getWr()
 {
  return Wr;
 }

 void Tees::setMs(char *s)
 {
  strcpy(Ms, s);
 }

 char* Tees::getMs()
 {
  return Ms;
 }

 void Tees::setWs(char *s)
 {
  strcpy(Ws, s);
 }

 char* Tees::getWs()
 {
  return Ws;
 }

