#ifndef Misura_h
#define Misura_h

#include <iostream>
#include "Lettura.h"

//definisco una costante pubblica che indica il numero di sensori
static const int SENSOR = 17;

class Misura{
  public:
  //costruttore di default
  Misura();

  //costruttore che copia da un puntatore Lettura*
  Misura(const Lettura* letture);

  //copia ogni valore della nuova misura nell'array
  void replace(Lettura nuova_misura[]);

  //ritorna l'intero array tramite puntatore
  const Lettura* get() const;

  //restitusce la lettura all'indice i
  Lettura at(int i);

  Lettura& operator[] (int i);
  
  const Lettura& operator[] (int i) const;

  //compone l'oggetto ostream con i valori da stampare
  std::ostream& print() const;

  private:
  Lettura array[SENSOR];
};

//overload dell'operatore <<
std::ostream& operator<<(std::ostream& out, const Misura& t);

#endif
