
#ifndef MyVector_hpp
#define MyVector_hpp

template <typename T>
void MyVector<T>::safe_set(int i, T valore)
{
    if(i<0 || i >= vSize)
    {
        throw std::out_of_range("Indice sbagliato");
    }
    v[i] = valore;
}

template <typename T>
T MyVector<T>::safe_get(int i)
{
    if(i<0 || i>=vSize)
    {
        throw std::out_of_range("Indice sbagliato");
    }
    return v[i];
}

template<typename T>
MyVector<T>::MyVector(int max_size){
	
	size = 0;
	this->max_size = max_size;
	v = new T[max_size];
	
	for(int i=0;i<max_size;i++){
		v[i] = 0.0;
	}
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst){
	
	size = lst.size();
	max_size = size * 2;
	v = new T[max_size];
	std::copy(lst.begin(), lst.end(), v);
	std::fill(v+size, v+max_size, 0.0);
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
	
	if(i<0 || i>=size){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
	return v[i];
}

template<typename T>
void MyVector<T>::push_back(T valore){
	
	if (size >= max_size) {
           reserve(max_size * 2);  
       }
       v[size] = valore;
       size++;
}

template<typename T>
T MyVector<T>::pop_back(){
	
	if(size > 0){
		T oldValue = v[size-1];
		v[size-1] = 0.0;
		size--;
		return oldValue;
	}
	else{ throw std::out_of_range("Vettore vuoto!");}

}

template<typename T>
void MyVector<T>::reserve(int newCapacity) {
	
	if (newCapacity <= max_size) return;
	
    T* newBuffer = new T[newCapacity];
    std::copy(v, v + size, newBuffer);
	std::fill(newBuffer + size, newBuffer + newCapacity, 0.0);

    delete[] v;
    v = newBuffer;
    max_size = newCapacity;
}

template<typename T>
MyVector<T>::~MyVector(){
	
	delete[] v;
}





#endif
