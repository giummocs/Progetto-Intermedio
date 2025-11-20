#include "InertialDriver.h"

InertialDriver::InertialDriver() : BUFFER_DIM(0), v(0) {
	first = 0;
    last = 0;
}
	
InertialDriver::InertialDriver(int buff_sz) : BUFFER_DIM(buff_sz), v(buff_sz) {
    first = 0;
    last = 0;
}


void InertialDriver::push_back(Lettura misura[]){
	if(BUFFER_DIM==0){
		throw std::out_of_range("Il vettore non ha dimensione!");
	}

	//alloca il nuovo spazio per la misura
    Lettura* nuova_misura = new Lettura[SENSOR];

    //copia i 17 elementi dell'array
    for (int i = 0; i < SENSOR; ++i) {
        nuova_misura[i] = misura[i];
    }
    
    //dealloca il vecchio puntatore
    if (v[last] != nullptr) {
        delete[] v[last]; 
    }

    v[last] = nuova_misura;

	last = (last+1) % BUFFER_DIM;
	if(last == first){
		first = (first+1) % BUFFER_DIM;
	}
	
}

Lettura* InertialDriver::pop_front(){
	if(last == first){
		throw std::out_of_range("Il vettore e' vuoto!");
	}

	Lettura* vecchia_misura = v[first]; 
    v[first] = nullptr; 
	
	first = (first+1) % BUFFER_DIM;

	return vecchia_misura;	
	
}

void InertialDriver::clear_buffer(){   
	//first==last significa che il vettore e' vuoto
    while(first != last){
		
         if (v[first] != nullptr) {
            delete[] v[first]; 
            v[first] = nullptr; 
        }
		
		first = (first+1) % BUFFER_DIM;
    }
	first = 0;
	last = 0;
}
    
Lettura InertialDriver::get_reading(int i){   
	if(i < 0 || i >= SENSOR){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
	
	if(first == last){
        throw std::out_of_range("Il vettore e' vuoto!");
    }

	int index_last = (last - 1 + BUFFER_DIM) % BUFFER_DIM;
    return v[index_last][i];
}

std::ostream& InertialDriver::print() const{
	std::ostream& out = std::cout;
	
	if (first == last) {
        out << "Nessuna misura da stampare.\n";
        return out;
    }
	
	int index_last = (last - 1 + BUFFER_DIM) % BUFFER_DIM;
    
    out << "\nUltima Misura Salvata\n";
	for(int i = 0; i < 17; i++)
	{
	    out << "Sensore " << i + 1 << ":\n";
		out << "Yaw_v = " << v[index_last][i].yaw_v << "\n";
		out << "Yaw_a = " << v[index_last][i].yaw_a << "\n";
	    out << "Pitch_v = " << v[index_last][i].pitch_v << "\n";
	    out << "Pitch_a = " << v[index_last][i].pitch_a << "\n";
	    out << "Roll_v = " << v[index_last][i].roll_v << "\n";
	    out << "Roll_a = " << v[index_last][i].roll_a << "\n\n";
	}
    return out;
}

InertialDriver::~InertialDriver(){
	clear_buffer();
}
 
std::ostream& operator<<(std::ostream& out, const InertialDriver& t){

	return t.print();
}

