#ifndef MISURA_H
#define MISURA_H

#include "Lettura.h"
class Misura{
  //definisco una costante pubblica che indica il numero di sensori
  static const int SENSOR= 17;
  //costruttore di default
  Misura();
  //costruttore di copia
  Misura(const Misura& m);
  //
  void replace(Lettura nuova_misura[]);
  //distruttore
  ~Misura();
  
  Lettura& operator[] (int i);
  
  Misura& operator= (const Misura& m);

  private:
  Lettura array[SENSOR];
}

#endif
