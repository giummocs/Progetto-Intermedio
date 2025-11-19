#ifndef MyVector_h
#define MyVector_h

#include <stdexcept>
#include <initializer_list>

template<typename T>
class MyVector{
	
	public:
	//costruttore di default
	MyVector();

	//costruttore che imposta il vettore a lunghezza max_size
	MyVector(int max_size);

	//costruttore che accetta una lista gia inizializzata come parametro
	MyVector(std::initializer_list<T> lst);

	//overloading dell'operatore []
	T& operator[] (int i);
	const T& operator[] (int i) const;
	
	//set di un valore del vettore
	void safe_set(int i, T valore);

	//get di un valore del vettore
    T safe_get(int i);

	//prende un valore del vettore e lo ritorna per riferimento
	T& at(int i);

	//inserisce un nuovo elemento, aumentando la dimensione del vettore se necessario
	void push_back(T valore);

	//inserisce un nuovo elemento, gestendolo con una politica circolare
	void push_back_circolare(T valore);

	//preleva e rimuove l'ultimo elemento del vettore
	T pop_back();

	//preleva e rimuove il primo elemento della coda, gestendolo con una politica circolare
	T pop_front();

	//distruttore
	~MyVector();


	private:

	//funzione membro per la gestione del vettore nel caso sia pieno
	void reserve(int newCapacity);

	//numero di elementi riempiti del vettore
	int size;

	//dimensione fisica del vettore
	int max_size;

	//puntatore all'elemento piu vecchio (primo inserito) del vettore circolare
	int pointer_first;

	//puntatore all'elemento piu nuovo (ultimo inserito) del vettore circolare
	int pointer_last;

	//vettore
	T* v;
};

#include "MyVector.hpp"
#endif
