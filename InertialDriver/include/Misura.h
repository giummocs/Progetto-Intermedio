#ifndef MISURA_H
#define MISURA_H

#include "Lettura.h"

class Misura{
  //definisco una costante pubblica che indica il numero di sensori
  static const int SENSOR= 17;
  //costruttore di default
  Misura();
  //
  void replace(Lettura nuova_misura[]);
  //
  Lettura[] get();
  //restisce lettura all'indice i
  Lettura at(int i);
  //distruttore
  ~Misura();
  
  Lettura& operator[] (int i);
  
  const Lettura& operator[] (int i) const;

  std::ostream& Misura::print() const;

  private:
  Lettura array[SENSOR];
};

std::ostream& operator<<(std::ostream& out, const Misura& t);

#endif
