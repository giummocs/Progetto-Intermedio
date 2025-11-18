#ifndef MyVector_h
#define MyVector_h

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class MyVector{
	
	public:
	MyVector(int max_size);
	ee
	MyVector(std::initializer_list<T> lst);
	
	T& operator[] (int i);
	
	const T& operator[] (int i) const;
	
	T& at(int i);
	
	void push_back(T valore);
	
	T pop_back();
	
	void reserve(int newCapacity);
	
	~MyVector();

	private:
	int size, max_size;
	T* v;
};

#include "MyVector.hpp"
#endif
