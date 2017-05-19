/*
 * Author Michael Burmeister
 * Date May 16, 2017
 * Version 1.0
 * Description Holds Hole data for Golf Course
 * 
 */

 #ifndef _HOLES_H
 #define _HOLES_H

class Holes
{
  private:
  int N;
  int Y;
  int H;
  int P;

  public:
  Holes();
  void setHole(int);
  int getHole(void);
  void setYards(int);
  int getYards(void);
  void setHandicap(int);
  int getHandicap(void);
  void setPar(int);
  int getPar(void);
};

 #endif
