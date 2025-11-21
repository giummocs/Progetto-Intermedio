#include "InertialDriver.h"

InertialDriver::InertialDriver() : BUFFER_DIM(0), v(0) {
	first = 0;
    last = 0;
}
	
InertialDriver::InertialDriver(int buff_sz) : BUFFER_DIM(buff_sz), v(buff_sz) {
    first = 0;
    last = 0;
}


void InertialDriver::push_back(Lettura nuova_misura[]){
	if(BUFFER_DIM==0){
		throw std::out_of_range("Il vettore non ha dimensione!");
	}


    v[last].replace(nuova_misura);

	last = (last+1) % BUFFER_DIM;
	if(last == first){
		first = (first+1) % BUFFER_DIM;
	}
	
}

const Lettura* InertialDriver::pop_front(){
	if(last == first){
		throw std::out_of_range("Il vettore e' vuoto!");
	}

	//non resetto i valori della misura perchè l'array viene passato tramite puntatore e "punta" agli stessi valori di v[old_first]
	int old_first = first;
	
	first = (first+1) % BUFFER_DIM;

	return v[old_first].get();
	
}

void InertialDriver::clear_buffer(){   
	//first==last significa che il vettore e' vuoto
    while(first != last){

		//resetto l'oggetto usando il costruttore
        v[first] = Misura();
		
		first = (first+1) % BUFFER_DIM;
    }
	first = 0;
	last = 0;
}
    
Lettura InertialDriver::get_reading(int i){   
	
	if(first == last){
        throw std::out_of_range("Il vettore e' vuoto!");
    }

	int index_last = (last - 1 + BUFFER_DIM) % BUFFER_DIM;
    return v[index_last].at(i);
}

std::ostream& InertialDriver::print() const{
	std::ostream& out = std::cout;
	
	if (first == last) {
        out << "Nessuna misura da stampare.\n";
        return out;
    }
	
	int index_last = (last - 1 + BUFFER_DIM) % BUFFER_DIM;
    
    out << "\nUltima Misura Salvata\n";
	out << v[index_last];
    return out;
}

InertialDriver::~InertialDriver(){
	clear_buffer();
}
 
std::ostream& operator<<(std::ostream& out, const InertialDriver& t){

	return t.print();
}

