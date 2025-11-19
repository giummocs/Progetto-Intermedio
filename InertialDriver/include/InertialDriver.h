#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "Lettura.h"
#include "MyVector.h"
//opzione rigida definisco una costante globale che rappresenta la dimensione massima del buffer
//constexpr int BUFFER_DIM = 5;

class InertialDriver{
    public:

	//costante public accessibile dall'esterno in sola lettura, utile per visualizzare la dimensione del buffer
    const int BUFFER_DIM;

	InertialDriver();
    //opzione flessibile lascio all'utente la scelta della dimensione del buffer
    //costruttore con un argomento
    InertialDriver(int buff_sz);

    //inserimento di una misura
    void push_back(Lettura v[]);

    //rimozione di una misura
    //void poiche' stampa in output l'array piu' vecchio
    Lettura[] pop_front();

    //svuota senza restituire nulla il buffer
    void clear_buffer();

    //restituisce la lettura di indice i della misura piu' recente
    Lettura get_reading(int i);

    //overloading dell'operatore << che stampa in output ultima misura salvata
   std::ostream& operator<<(std::ostream& out, const InertialDriver& t);
   
private:
    MyVector<Lettura[]> v;

	//funzione membro per gestire l'incremento del puntatore
	void increment_pointer();

	//funzione membro per gestire il decremento del puntatore
	void decrement_pointer();
}

#include "IntertialDriver.cpp"
#endif






