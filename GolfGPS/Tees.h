/*
 * Author Michael Burmeister
 * Date May 16, 2017
 * Version 1.0
 * Description Hold Golf Course Tee Positions
 * 
 */

 #ifndef _TEES_H
 #define _TEES_H


class Tees
{
  private:
  char N[15];
  char Mr[5];
  char Wr[5];
  char Ms[5];
  char Ws[5];

  public:
  Tees();
  void setName(char*);
  char* getName(void);
  void setMr(char*);
  char* getMr(void);
  void setWr(char*);
  char* getWr(void);
  void setMs(char*);
  char* getMs(void);
  void setWs(char*);
  char* getWs(void);
  
};

 #endif
