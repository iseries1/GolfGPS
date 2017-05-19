/*
 * Author Michael Burmeister
 * Date May 16, 2017
 * Version 1.0
 * Description Hold Hole data for Golf Course
 * 
 */

 #include <Arduino.h>
 #include <string.h>

 #include "Holes.h"

 Holes::Holes()
 {
  N=0;
  Y=0;
  H=0;
  P=0;
 }

 void Holes::setHole(int n)
 {
  N = n;
 }

 int Holes::getHole()
 {
  return N;
 }

 void Holes::setYards(int y)
 {
  Y = y;
 }

 int Holes::getYards()
 {
  return Y;
 }

 void Holes::setHandicap(int h)
 {
  H = h;
 }

 int Holes::getHandicap()
 {
  return H;
 }

 void Holes::setPar(int p)
 {
  P = p;
 }

 int Holes::getPar()
 {
  return P;
 }

