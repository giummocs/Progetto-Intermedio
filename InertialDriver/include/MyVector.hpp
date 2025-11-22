#ifndef MyVector_hpp
#define MyVector_hpp

template<typename T>
MyVector<T>::MyVector(){
	//inizializzo le variabili
	size = 0;
	max_size = 0;
	v = new T[max_size];
	
}

template<typename T>
MyVector<T>::MyVector(int max_size){
	//inizializzo le variabili
	size = 0;
	this->max_size = max_size;
	v = new T[max_size];

	//inizializzo tutti i valori chiamando il construtto di default del typename
	std::fill(v, v+max_size, T());
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst){
	//inizializzo le variabili
	size = lst.size();
	max_size = size * 2;
	v = new T[max_size];

	//copio la lista nel nuovo vettore appena creato e inizializzo gli spazi vuoti
	std::copy(lst.begin(), lst.end(), v);
	std::fill(v+size, v+max_size, T());
}

template <typename T>
void MyVector<T>::safe_set(int i, T valore)
{
	//lancio una eccezione se l'indice e' sbagliato
    if(i<0 || i>=size){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
    v[i] = valore;
}

template <typename T>
T& MyVector<T>::safe_get(int i)
{
	//lancio una eccezione se l'indice e' sbagliato
    if(i<0 || i>=size){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
    return v[i];
}

template<typename T>
T& MyVector<T>::operator[] (int i){
	
	return v[i];
}

template<typename T>
const T& MyVector<T>::operator[] (int i) const{
	
	return v[i];
}

template<typename T>
T& MyVector<T>::at(int i){
	//lancio una eccezione se l'indice e' sbagliato
	if(i<0 || i>=size){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
	return v[i];
}

template<typename T>
int MyVector<T>::getSize(){
	return size;
}

template<typename T>
void MyVector<T>::push_back(T valore){
	//se il vettore è pieno aumenta la dimensione
	if (size >= max_size) {
        reserve(max_size * 2);  
    }
	
    v[size] = valore;
    size++;
}

template<typename T>
T& MyVector<T>::pop_back(){
	
	if(size <= 0){
		throw std::out_of_range("Vettore vuoto!");
	}

	//salvo il vecchio valore
	T oldValue = v[size-1];

	//resetto il vecchio valore
	v[size-1] = 0.0;
	
	size--;
	return oldValue;
}

template<typename T>
void MyVector<T>::reserve(int new_capacity) {
	//controllo che la nuova capacità sia maggiore della vecchia
	if (new_capacity <= max_size) { throw std::out_of_range("Valore non valido!"); }
	
    T* newBuffer = new T[new_capacity];
    std::copy(v, v + size, newBuffer);
	std::fill(newBuffer + size, newBuffer + new_capacity, 0.0);

    delete[] v;
    v = newBuffer;
    max_size = new_capacity;
}

template<typename T>
MyVector<T>::~MyVector(){
	
	delete[] v;
}


#endif
