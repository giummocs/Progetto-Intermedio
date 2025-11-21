#ifndef InertialDriver_h
#define InertialDriver_h

#include <iostream>
#include "Misura.h"
#include "MyVector.h"

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
    const Lettura* pop_front();

    //svuota senza restituire nulla il buffer
    void clear_buffer();

    //restituisce la lettura di indice i della misura piu' recente
    Lettura get_reading(int i);
    
    std::ostream& print() const;

	~InertialDriver();
   
private:
    MyVector<Lettura*> v;

	//indici che indicano il primo e l'ultimo elemento del vettore circolare
	int first, last;

};

//overloading dell'operatore << che stampa in output ultima misura salvata
std::ostream& operator<<(std::ostream& out, const InertialDriver& t);

#endif

















