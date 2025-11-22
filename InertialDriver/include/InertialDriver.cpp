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
	//controllo se il vettore ha una dimensione valida
	if(BUFFER_DIM==0){
		throw std::out_of_range("Il vettore non ha dimensione!");
	}

	//inserisce la nuova misura nell'ultimo elemento del buffer
    v[last].replace(nuova_misura);

	//incremento last, poi se necessario incremento anche first 
	//(così facendo al prossimo push verrà sovrascritto l'elemento piu vecchio del buffer)
	last = (last+1) % BUFFER_DIM;
	if(last == first){
		first = (first+1) % BUFFER_DIM;
	}
	
}

const Lettura* InertialDriver::pop_front(){
	//first==last significa che il buffer è vuoto
	if(last == first){
		throw std::out_of_range("Il vettore e' vuoto!");
	}

	//salvo l'indice first
	int old_first = first;

	//incremento l'indice
	first = (first+1) % BUFFER_DIM;

	return v[old_first].get();
	//non "resetto" i valori della misura perchè l'array viene passato tramite puntatore e "punta" agli stessi valori di v[old_first]
}

void InertialDriver::clear_buffer(){   
	//first==last significa che il vettore e' vuoto
    while(first != last){

		//resetto l'oggetto usando il costruttore
        v[first] = Misura();
		
		first = (first+1) % BUFFER_DIM;
    }
	//rinizio il conteggio da 0
	first = 0;
	last = 0;
}
    
Lettura InertialDriver::get_reading(int i){   
	//buffer vuoto
	if(first == last){
        throw std::out_of_range("Il vettore e' vuoto!");
    }

	//last contiene l'indice del prossimo elemento libero, quindi 
	//per avere l'ultimo elemento inserito nel buffer devo prendere l'indice precedente a last
	int last_added = (last - 1 + BUFFER_DIM) % BUFFER_DIM;

	//ritorno la lettura i dell'ultima misura
    return v[last_added].at(i);
}

std::ostream& InertialDriver::print() const{
	//creo l'oggetto ostream che dovrà essere ritornato
	std::ostream& out = std::cout;

	//buffer vuoto
	if (first == last) {
        out << "Nessuna misura da stampare.\n";
        return out;
    }

	//indice dell'ultima misura inserita
	int last_added = (last - 1 + BUFFER_DIM) % BUFFER_DIM;
    
    out << "\nUltima Misura Salvata\n";
	out << v[last_added];
    return out;
}

InertialDriver::~InertialDriver(){
	clear_buffer();
	delete[] v;
}
 
std::ostream& operator<<(std::ostream& out, const InertialDriver& t){

	return t.print();
}

