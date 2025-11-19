#ifndef MyVector_h
#define MyVector_h

#include <stdexcept>
#include <initializer_list>

template<typename T>
class MyVector{
	
	public:
	MyVector(int max_size);
	
	MyVector(std::initializer_list<T> lst);
	
	T& operator[] (int i);

	void safe_set(int i, T valore);
    
    T safe_get(int i);
	
	const T& operator[] (int i) const;
	
	T& at(int i);
	
	void push_back(T valore);
	
	T pop_back();
	
	void reserve(int newCapacity);
	
	~MyVector();

	private:

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
