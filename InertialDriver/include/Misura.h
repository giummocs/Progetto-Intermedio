#ifndef MISURA_H
#define MISURA_H

#include <iostream>
#include "Lettura.h"

//definisco una costante pubblica che indica il numero di sensori
static const int SENSOR = 17;

class Misura{
  
  //costruttore di default
  Misura();
  //
  void replace(Lettura nuova_misura[]);
  //
  const Lettura* get() const;
  //restisce lettura all'indice i
  Lettura at(int i);
  
  Lettura& operator[] (int i);
  
  const Lettura& operator[] (int i) const;

  std::ostream& print() const;

  private:
  Lettura array[SENSOR];
};

std::ostream& operator<<(std::ostream& out, const Misura& t);

#endif
