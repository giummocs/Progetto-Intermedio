#ifndef InertialDriver_h
#define InertialDriver_h

#include <iostream>
#include "Misura.h"
#include "MyVector.h"

class InertialDriver{
    public:
	//costante public accessibile dall'esterno in sola lettura, utile per visualizzare la dimensione del buffer
    const int BUFFER_DIM;

	//costruttore deafult che imposta un buffer di dimensione 0
	InertialDriver();

    //lascio all'utente la scelta della dimensione del buffer
    InertialDriver(int buff_sz);

    //inserimento di una misura
    void push_back(Lettura v[]);

    //rimuove la prima misura inserita e ne ritorna il valore
	//il valore di ritorno è un puntatore a un array stile C
    const Lettura* pop_front();

    //svuota il buffer
    void clear_buffer();

    //restituisce la lettura di indice i della misura piu' recente
    Lettura get_reading(int i);

	//funzione utile per l'overload di <<
    std::ostream& print() const;

	//distruttore
	~InertialDriver();
   
private:
	//buffer
    MyVector<Misura> v;

	//indici che indicano il primo e l'ultimo elemento del buffer circolare
	int first, last;

};

//overloading dell'operatore << che stampa in output ultima misura salvata
std::ostream& operator<<(std::ostream& out, const InertialDriver& t);

#endif



















