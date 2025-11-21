#ifndef MISURA_H
#define MISURA_H

#include "Lettura.h"
class Misura{
  //definisco una costante pubblica che indica il numero di sensori
  const SENSOR= 17;
  //construttore di default
  Misura();
  //
  void replace(Lettura nuova_misura[]);
  //distruttore
  ~Misura();
  




  private:
  Lettura array[SENSOR];
}

#endif
